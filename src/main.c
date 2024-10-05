
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Downloaded Libraries
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "level.h"


/*
hauteur max possible --> 64*11= 704
largeur max possible --> 64*21= 1344

le mieux serait du 10x18

*/


//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lSDL2
//-mwindow ( pour enlever le cmd )

int WorldMap();
int GameOver();
bool MouseColision(int pos_mouse[],SDL_Rect rect);
int TropicalResortLevel();
void Init_keys();
void Init_level_elements();
int ScreenResult();





SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
bool keys[]={false, false, false, false, false, false, false, false, false};//up,down,left,right,cleft,cright,space,escape,return
int mouse_pos[2] = {0, 0};
int temp=0;
int sx;
int sy;
int souris_pos[2]={0,0};
int selectcursor=0;
int tempenter=0;
int tempcursor[2]={0,0};
SDL_Color colorwhite={255,255,255,255};
bool jumpair=false;
bool pjumpside=false;
int vspeed=0,vspeedy=0;
int vspeedsol=0,vspeedsoly=0;
bool wallr=false,walll=false;
int countlife[3]={0,0,3};
int countring[3]={0,0,0};
int counttimer[6]={0,0,0,0,0,0};
bool gameover=false,isdead=false;
int startposx[3]={0,0,0};
int startposy[3]={448,448,448};
SDL_Rect rectsrun;
int deplacementx=0;
int deplacementy=0;
bool ispaused=false;
bool paused=false;
bool locked[8]={false,true,true,true,true,true,true,true};
int AreaMapIndex=0;
int ActIndex=0;
int checkpoint[]={0,0,0,0};
bool newact=false;
bool ActLocked[7][3]={{false,true,true},
                {false,true,true},
                {false,true,true},
                {false,true,true},
                {false,true,true},
                {false,true,true},
                {false,true,true} };

SDL_Rect PosAct[]={{0,0,0,0}};



#include "menu.h"
#include "WorldMap.h"
#include "TropicalResort.h"
#include "SonicElement.h"
#include "Element.h"
#include "ObjectElement.h"

int AreaMap();
int Pause(SDL_Renderer *renderer,bool enter,bool up,bool down);
bool Collision(SDL_Rect rect1,SDL_Rect rect2,direction way);
SDL_Rect camera={0,0,WINDOWS_WIDTH,WINDOWS_HEIGHT};



int main(int argc, char *argv[]){


    int SDL_Init_Value = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    if (SDL_Init_Value == -1)
        exit(EXIT_FAILURE);

    if (Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0) {
        exit(EXIT_FAILURE);
    }
    TTF_Init();

    window = SDL_CreateWindow("SONIC COLORS 2D",//nom provisoire
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, // position centered (x, y)
                              WINDOWS_WIDTH, WINDOWS_HEIGHT, // 16/9
                              SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_MOUSE_FOCUS);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer){printf("oof" );}




    SDL_Surface *icon = NULL;
    icon = IMG_Load("bin/res/img/Icon/SonicColors2D_icon.jpg");
    SDL_SetWindowIcon(window, icon);
    SDL_FreeSurface(icon);



    //TropicalResortLevel();
    main_menu();
    //worldmap();
    //AreaMap();

    Mix_CloseAudio();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

int WorldMap(){
    //renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);




    SDL_Rect rectworld;
    SDL_Texture *tworld=SDL_LoadImage(renderer,"bin/res/img/worldmapbis.png",tworld);
    SDL_QueryTexture(tworld, NULL, NULL, &rectworld.w, &rectworld.h);
    rectworld.y=0;
    rectworld.x=(WINDOWS_WIDTH/2)-(rectworld.w/2);
    SDL_SetWindowSize(window,rectworld.w,rectworld.h);
    SDL_SetWindowPosition(window,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    Load_Cursor();
    Mix_Music* WorldMapSound=Mix_LoadMUS("bin/res/audio/Ost/WorldMap.mp3");
    Mix_PlayMusic(WorldMapSound, -1);
    Load_bg_worldmap();
    Mix_Chunk *Worldmapcursor = Mix_LoadWAV("bin/res/audio/sound/system/SYS_Wmap_Set.wav");
    Mix_Chunk *decide = Mix_LoadWAV("bin/res/audio/sound/system/SYS_Worldmap_Decide.wav");
    Mix_Chunk *unlockplanetsound=Mix_LoadWAV("bin/res/audio/sound/system/SYS_Worldmap_Ng.wav");
    if (!Worldmapcursor){printf("%s\n",Mix_GetError() );}
    if (!decide){printf("%s\n",Mix_GetError() );}

    int count[7]={0,0,0,0,0,0,0};
    Init_keys();
    tcadena=SDL_LoadImage(renderer,"bin/res/img/cadenas.png",tcadena);
    SDL_QueryTexture(tcadena,NULL,NULL,&rectcadena.w,&rectcadena.h);
    selectcursor=0;
    bool launchingg=true;
    while (launchingg) {
        SDL_GetMouseState(&sx, &sy);
        cursormouse.y=sy-(cursormouse.h/2);
        cursormouse.x=sx-(cursormouse.w/2);
        Event_keys(launchingg);
        SDL_RenderCopy(renderer, tworld, NULL, &rectworld);

        Load_cadena();
        if (tempstars+50<SDL_GetTicks()){
            if (indexstars==0){
                chargestars=1;
            }else if(indexstars==5){
                chargestars=-1;
            }
            indexstars+=1*chargestars;
            tempstars=SDL_GetTicks();
        }

        for(int i=0;i<=5;i++){
            pixelstars[indexstars].x=Posstars[i][0];
            pixelstars[indexstars].y=Posstars[i][1];
            SDL_RenderCopy(renderer,tpixelstars[indexstars],NULL,&pixelstars[indexstars]);
        }


        if (keys[KESCAPE]){
            SDL_RenderClear(renderer);
            main_menu();
            break;
        }

        SDL_RenderCopy(renderer,tborderworld,NULL,&borderworld);
        for(int i=0;i<2;i++){
            wispemplacement.x=Poswispemplacement[i][0];
            wispemplacement.y=Poswispemplacement[i][1];
            SDL_RenderCopy(renderer,twispemplacement,NULL,&wispemplacement);
        }
        for (int i=0;i<8;i++){

            souris_pos[0]=sx;
            souris_pos[1]=sy;
            if (!locked[i] && MouseColision(souris_pos,planet_list[i]) && count[i] < 1){
                Mix_PlayChannel(1,Worldmapcursor, 0);
                count[i]=1;
            }

            if (!MouseColision(souris_pos,planet_list[i]) && count[i] > 0){

                count[i]=0;
            }
            if (MouseColision(souris_pos,planet_list[i])){
                SDL_RenderCopy(renderer,ttitlelevel[i],NULL,&titlelevel[i]);
                int index,index2;
                switch (i) {
                    case 1:
                        index=BURST;
                        index2=ROCKET;
                        break;
                    case 2:
                        index=HOVER;
                        index2=CUBE;
                        break;
                    case 3:
                        index=DRILL;
                        index2=SPIKE;
                        break;
                    case 4:
                        index=LASER;
                        index2=DRILL;
                        break;
                    case 5:
                        index=VOID;
                        index2=FRENZY;
                        break;


                }
                if (i<6&&i!=0){
                    wispindex[index].x=280+(wispemplacement.w/2)-(wispindex[index].w/2);
                    wispindex[index].y=10+(wispemplacement.h/2)-(wispindex[index].h/2);
                    SDL_RenderCopy(renderer,twispindex[index],NULL,&wispindex[index]);
                    wispindex[index2].x=320+(wispemplacement.w/2)-(wispindex[index2].w/2);
                    wispindex[index2].y=10+(wispemplacement.h/2)-(wispindex[index2].h/2);
                    SDL_RenderCopy(renderer,twispindex[index2],NULL,&wispindex[index2]);

                }


            }
            if (locked[i] && MouseColision(souris_pos,planet_list[i]) && keys[CLEFT]&& count[i] < 1){
                Mix_PlayChannel(1,unlockplanetsound, 0);
                count[i]=1;
            }
            if (!locked[i] && MouseColision(souris_pos,planet_list[i]) && keys[CLEFT]){
                Mix_FreeMusic(WorldMapSound);
                Mix_PlayChannel(1,decide, 0);
                SDL_RenderClear(renderer);
                AreaMapIndex=i;
                AreaMap();
                break;

            }
        }


        SDL_RenderCopy(renderer,tcursormouse,NULL,&cursormouse);
        SDL_RenderPresent(renderer);
    }
    SDL_RenderClear(renderer);

    return 0;

}

int AreaMap(){


    Load_AreaElement();
    SDL_SetWindowSize(window, Areafond[AreaMapIndex].w,Areafond[AreaMapIndex].h);
    SDL_SetWindowPosition(window,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    Mix_Chunk *decideb=Mix_LoadWAV("bin/res/audio/sound/system/SYS_Wmap_Decide.wav");
    Mix_Chunk *unlockactsound=Mix_LoadWAV("bin/res/audio/sound/system/SYS_Amap_Act_Unlock.wav");
    if (!decideb){printf("%s\n",Mix_GetError() );}

    Mix_PlayMusic(Areasound, -1);


    selectcursor=0;
    bool launching = true;
    Init_keys();
    if (ActLocked[AreaMapIndex][ActIndex+1]==false && newact){
        Mix_PlayChannel(2,unlockactsound,0);
        newact=false;
    }
    while (launching) {


        Event_keys(launching);


        if(tempaAreaAnim+250<SDL_GetTicks()){
            if(indexAreaAnim==3){
                indexAreaAnim=1;
            }else{
                indexAreaAnim++;
            }
            tempaAreaAnim=SDL_GetTicks();
        }
        if(tempSonicHead+150<SDL_GetTicks()){
            if(PosSonicHead==0){
                multi=1;
            }else if(PosSonicHead==8){
                multi=-1;
            }
            PosSonicHead+=1*multi;
            tempSonicHead=SDL_GetTicks();
        }


        SDL_RenderCopy(renderer, tAreafond[AreaMapIndex], NULL, &Areafond[AreaMapIndex]);
        Event_cursor(2);
        for(int i=0;i<=3;i++){
            if(i<3){
                if (!ActLocked[AreaMapIndex][i]) {
                    levelArea[indexAreaAnim].x=PosArea[AreaMapIndex][i].x;
                    levelArea[indexAreaAnim].y=PosArea[AreaMapIndex][i].y;
                    SDL_RenderCopy(renderer, tlevelArea[indexAreaAnim],NULL,&levelArea[indexAreaAnim]);

                }else{
                    levelArea[0].x=PosArea[AreaMapIndex][i].x;
                    levelArea[0].y=PosArea[AreaMapIndex][i].y;

                }
                SDL_RenderCopy(renderer, tlevelArea[0],NULL,&levelArea[0]);
            }
            if(selectcursor==i){
                SonicArea.x=PosArea[AreaMapIndex][i].x;
                SonicArea.y=PosArea[AreaMapIndex][i].y-20+PosSonicHead;
                SDL_RenderCopy(renderer, tSonicArea,NULL,&SonicArea);
            }
            if(selectcursor==i&&keys[KRETURN]&&!ActLocked[AreaMapIndex][i]){
                ActIndex=i;
                Mix_PlayChannel(1,decideb,0);
                SDL_RenderClear(renderer);
                TropicalResortLevel();
                break;
            }

        }


        if(keys[KESCAPE]){
            SDL_RenderClear(renderer);
            WorldMap();
            break;

        }



        SDL_RenderPresent(renderer);
    }

    SDL_RenderClear(renderer);

    return 0;
}

int TropicalResortLevel(){
    SDL_SetWindowSize(window, WINDOWS_WIDTH,WINDOWS_HEIGHT);
    SDL_SetWindowPosition(window,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    int deltatemp=SDL_GetTicks();

    selectcursor=0;
    rectsrun=sonic_runr[0];
    rectsrun.x=0;
    rectsrun.y=WINDOWS_HEIGHT-192;

    deplacementx=rectsrun.x;
    deplacementy=rectsrun.y;
    //Ca part dans un Init_Sonic()

    Load_TropicalResortElement();
    Load_SonicElement();
    Load_PauseElement();
    Load_GameOverElement();
    Load_SonicScore();
    Load_ObjectElement();
    Init_keys();
    Init_level_elements();


    int tempidle=0;
    int tempoidle=0;
    int tempsr=0;
    int tempsd=0;
    int tempsrun=0;
    int charge;
    bool jumpside=false;
    int countspeed=15;
    const int countjump=8;
    bool isjumping=false;
    bool isfallen=false;
    bool jump=false;
    bool groundl=false,groundr=false,ground=false;
    int iground=0;
    int ifall=0;
    int countjumpside=0;
    int chargefall=0;
    int delta=0;
    int countdelta=0;
    int tempground[]={0,0};
    int ijump=1;
    int tempjump[]={0,0};
    int tempjumpside=0;
    int vplacement=0,countplacement=0;
    SDL_Rect last_rect=rectsrun;
    int firstposy=rectsrun.y;
    int temptimer=0;
    int posysol=0;
    int indexrect=0;
    SDL_Rect last_bgrect={0,0,0,0};

    TropicalResortRect[0].y=0;
    TropicalResortRect[1].y=313;
    TropicalResortRect[2].y=313-TropicalResortRect[2].h;
    int coefmulti=3;
    for(int i=0;i<25;i++){
        sonic_runr[i].w*=coefmulti;
        sonic_runr[i].h*=coefmulti;
        if (i<6){
            sonic_idle_rect[i].w*=coefmulti;
            sonic_idle_rect[i].h*=coefmulti;
        }
        if (i<6){
            sonic_down[i].w*=coefmulti;
            sonic_down[i].h*=coefmulti;
        }

    }

    sonicjump.w*=coefmulti;
    sonicjump.h*=coefmulti;
    rectsfall.w*=coefmulti;
    rectsfall.h*=coefmulti;
    rectsair.w*=coefmulti;
    rectsair.h*=coefmulti;


    for(int i=3;i<sizeof(TropicalResortRect)/sizeof(TropicalResortRect[0]);i++){
        TropicalResortRect[i].w=SIZE_BLOC*2;
        TropicalResortRect[i].h=SIZE_BLOC*2;
    }
    bool finished=false;
    int countwall[2]={0,0};
    printf("deltatemp=%d\n", SDL_GetTicks()-deltatemp);
    Mix_PlayMusic(Tropisound,-1);
    while (!finished) {


        Event_keys(finished);


        if (deplacementx>=WINDOWS_WIDTH/2){ // 576=9*64
            vspeedsol=-((WINDOWS_WIDTH/2)-deplacementx);

            countplacement++;
        }else{
            vplacement=0;
            vspeedsol=0;
            countplacement=0;
        }

        /*
        if((deplacementy/SIZE_BLOC)>NUMBER_COLONE+1){

            isdead=true;
        }else{
            isdead=false;
        }
        */

        if(rectsrun.x<0){
            walll=true;
        }


        if(isdead){
            rectsrun.x=startposx[0];
            deplacementx=startposx[0];
            deplacementy=startposy[0];
            if(countlife[2]>0){
                countlife[2]--;
            }else if(countlife[2]==0&&countlife[1]>0){
                countlife[2]=9;
                countlife[1]--;
            }else if(countlife[2]==0&&countlife[1]==0&&countlife[0]>0){
                countlife[1]=9;
                countlife[2]=9;
                countlife[0]--;
            }

            for(int i=0;i<3;i++){
                countring[i]=0;
            }
        }
        if(countlife[2]==0&&countlife[1]==0&&countlife[0]==0){
           gameover=true;
       }else{
           gameover=false;
       }
        if(gameover){
            for(int i=0;i<3;i++){
                if(i==2){
                    countlife[i]=3;
                }else{
                    countlife[i]=0;
                }
            }
        }

        if (!ispaused){
            if (temptimer+10<SDL_GetTicks()){

                if (counttimer[5]>9){
                    counttimer[4]++;
                    counttimer[5]=0;
                }else{
                    counttimer[5]++;
                }

                if (counttimer[4]>9){
                    counttimer[3]++;
                    counttimer[4]=0;
                }

                if (counttimer[3]>9){
                    counttimer[2]++;
                    counttimer[3]=0;
                }

                if (counttimer[2]==6){
                    counttimer[1]++;
                    counttimer[2]=0;
                }

                if (counttimer[1]>9){
                    counttimer[0]++;
                    counttimer[1]=0;
                }

                temptimer=SDL_GetTicks();
            }
        }




        int countg=0;
        countwall[0]=0;
        countwall[1]=0;
        vspeedsoly=firstposy-deplacementy;
        SDL_RenderCopy(renderer, TropicalResortTexture[0], NULL, &TropicalResortRect[0]);

        for(int i=0;i<NUMBER_COLONE;i++){
            TropicalResortRect[2].x=0+(i*TropicalResortRect[2].w)-(vspeedsol/10);
            SDL_RenderCopy(renderer, TropicalResortTexture[2], NULL, &TropicalResortRect[2]);
            TropicalResortRect[1].x=0+(i*TropicalResortRect[1].w)-(vspeedsol/6);
            SDL_RenderCopy(renderer, TropicalResortTexture[1], NULL, &TropicalResortRect[1]);
            for(int j=0;j<NUMBER_LINE;j++){
                indexrect=0;

                switch (LevelList[AreaMapIndex][ActIndex][i][j]) {

                    case 1:
                        indexrect=SOL4;
                        break;
                    case 2:
                        indexrect=SOL2;
                        break;
                    case 3:
                        indexrect=SOL3;
                        break;

                    case 28:
                        indexrect=SOL28;
                        break;
                    case 29:
                        indexrect=SOL29;
                        break;
                    case 30:
                        indexrect=SOL30;
                        break;

                    default:
                        break;
                }

                if (indexrect>=3){
                    TropicalResortRect[indexrect].x=j*TropicalResortRect[indexrect].w-vspeedsol;
                    TropicalResortRect[indexrect].y=i*TropicalResortRect[indexrect].h+vspeedsoly;
                    SDL_RenderCopy(renderer, TropicalResortTexture[indexrect], NULL, &TropicalResortRect[indexrect]);
                    SDL_RenderDrawRect(renderer,&TropicalResortRect[indexrect]);
                    if (Collision(last_rect,TropicalResortRect[indexrect],TOP)) {
                        //deplacementy=((TropicalResortRect[index].y+TropicalResortRect[index].h)-vspeedsoly)+last_rect.h;
                        deplacementy=(SIZE_BLOC*(deplacementy/SIZE_BLOC))+1;
                        isjumping=false;
                    }
                    if(Collision(last_rect,TropicalResortRect[indexrect],BOTTOM)){
                        ground=true;
                        deplacementy=(SIZE_BLOC*(deplacementy/SIZE_BLOC));
                        countg=1;
                    }

                    if(Collision(last_rect,TropicalResortRect[indexrect],RIGHT)){
                        countwall[0]=1;
                        last_bgrect=TropicalResortRect[indexrect];
                        //deplacementx=(TropicalResortRect[index].x+vspeedsol)-last_rect.w;
                    }
                    if(Collision(last_rect,TropicalResortRect[indexrect],LEFT)){
                        countwall[1]=1;
                    }


                }

            }
        }
        if(countg<1){
            ground=false;
        }

        if(countwall[1]==1){
            walll=true;
        }else{
            walll=false;
        }

        if(countwall[0]==1){
            wallr=true;
        }else{
            wallr=false;
        }


        if(tempring+50<SDL_GetTicks()){
            if (indexring[0]==8){
                multi=-1;
                chargering*=-1;
            }else if(indexring[0]==0){
                chargering*=-1;
                multi=1;
            }
            indexring[0]+=1*multi;
            tempring=SDL_GetTicks();
        }

        if(tempgring+90<SDL_GetTicks()){
            if (indexring[1]==4){
                multig=-1;
                chargegring*=-1;
            }else if(indexring[1]==0){
                chargegring*=-1;
                multig=1;

            }
            indexring[1]+=1*multig;
            tempgring=SDL_GetTicks();
        }

        gring[indexring[1]].x=Posgring[0][0]-vspeedsol;
        gring[indexring[1]].y=Posgring[0][1]-gring[indexring[1]].h+vspeedsoly;
        SDL_RenderDrawRect(renderer,&gring[indexring[1]]);


        if(Collision(last_rect,gring[indexring[1]],ALL_DIRECTION)){
            SDL_RenderClear(renderer);
            Mix_FreeMusic(Tropisound);
            Mix_PlayChannel(3,stageclearsound,0);
            for(int i=0;i<6;i++){
                timerecord[i]=counttimer[i];
                if (i<3){
                    scorering[i]=countring[i];
                }
            }

            ScreenResult();
            break;

        }






        if(chargegring>0){
            SDL_RenderCopy(renderer,tgring[indexring[1]],NULL,&gring[indexring[1]]);
        }else{
            SDL_RenderCopyEx(renderer,tgring[indexring[1]],NULL,&gring[indexring[1]],0,NULL,SDL_FLIP_HORIZONTAL);
        }


        /*
        for(ringposition=0;ringposition<Nring;ringposition++){

        if (!touched[ringposition]){
            ring[indexring[0]].x=Posring[ringposition][0]-vspeedsol;
            ring[indexring[0]].y=Posring[ringposition][1]-ring[indexring[0]].h+vspeedsoly;

            if (Colision(last_rect,ring[indexring[0]],ALL_DIRECTION)){
                Mix_PlayChannel(0,ringsound,0);
                touched[ringposition]=true;
                countring[2]++;
                if (countring[2]>9){
                    countring[1]++;
                    countring[2]=0;
                }if (countring[1]>9){
                    countring[0]++;
                    countring[1]=0;
                }
            }
            if(chargering>0){
                SDL_RenderCopy(renderer,tring[indexring[0]],NULL,&ring[indexring[0]]);
            }else{
                SDL_RenderCopyEx(renderer,tring[indexring[0]],NULL,&ring[indexring[0]],0,NULL,SDL_FLIP_HORIZONTAL);
            }
        }


        }
        */
        /*
        ring[indexring[0]].x=Posring[4][0]-vspeedsol;
        ring[indexring[0]].y=510-ring[indexring[0]].h+vspeedsoly;
        SDL_RenderCopy(renderer,tring[indexring[0]],NULL,&ring[indexring[0]]);
        if(Collision(last_rect,ring[indexring[0]],ALL_DIRECTION)){
            printf("colision \n");
        }else{
            printf("rien\n" );
        }
        */
        if(!paused){
            if (keys[KLEFT] ){
                charge=-1;
            }
            else if (keys[KRIGHT]){
                charge=1;
            }
        }


        if (keys[KLEFT] && !isdown ){
            if (!ispaused){
                if (tempsrun>=countspeed){
                    tempsrun=8;
                }
                if (tempsd+150<SDL_GetTicks() && tempsrun<countspeed){
                    tempsrun++;
                    tempsd=SDL_GetTicks();
                }

                if(!walll){

                    if (tempsrun<=8){
                        vspeed=-1;
                    }else if (tempsrun>8 && tempsrun<15){
                        vspeed=-2;
                    }else{
                        vspeed=-3;
                    }
                    if (rectsrun.x<(WINDOWS_WIDTH/2-100)){

                        rectsrun.x+=vspeed;
                        deplacementx=rectsrun.x;
                    }else{
                        deplacementx+=vspeed;
                    }

                }else{
                    vspeed=0;

                }
                sonic_runr[tempsrun].x=rectsrun.x;
                sonic_runr[tempsrun].y=rectsrun.y-sonic_runr[tempsrun].h;sonic_runr[tempsrun].x=rectsrun.x;
                sonic_runr[tempsrun].y=rectsrun.y-sonic_runr[tempsrun].h;

                countdelta=0;
            }


            last_rect=sonic_runr[tempsrun];
            if (!isjumping&&ground&&!isfallen) {
                SDL_RenderCopyEx(renderer, sonic_runt[tempsrun], NULL, &sonic_runr[tempsrun], 0, NULL, SDL_FLIP_HORIZONTAL);
            }

        } else if (keys[KRIGHT] && !isdown ){
            if (!ispaused){
                if (tempsrun>=countspeed){
                    tempsrun=8;
                }
                if (tempsr+150<SDL_GetTicks() && tempsrun<countspeed){
                    tempsrun++;
                    tempsr=SDL_GetTicks();
                }

                if(!wallr){
                    if (tempsrun<=8){
                        vspeed=1;
                    }else if (tempsrun>8 && tempsrun<15){
                        vspeed=2;
                    }else{
                        vspeed=3;
                    }
                    if (rectsrun.x<(WINDOWS_WIDTH/2+100)){
                        rectsrun.x+=vspeed;
                        deplacementx=rectsrun.x;
                    }else{
                        deplacementx+=vspeed;
                        TropicalResortRect[0].x-=0.5;
                    }
                    sonic_runr[tempsrun].x=rectsrun.x;
                    sonic_runr[tempsrun].y=rectsrun.y-sonic_runr[tempsrun].h;
                }else{
                    vspeed=0;



                }


                countdelta=0;
            }


            last_rect=sonic_runr[tempsrun];

            if ((!isjumping&&ground&&!isfallen)){
                SDL_RenderCopy(renderer,sonic_runt[tempsrun],NULL,&sonic_runr[tempsrun]);
            }

        }


        if (charge>0){
            flip=SDL_FLIP_NONE;
            if(wallr){
                sonic_runr[tempsrun].x=last_bgrect.x-sonic_runr[tempsrun].w;
                sonic_runr[tempsrun].y=rectsrun.y-sonic_runr[tempsrun].h;
            }
        }else{
            flip=SDL_FLIP_HORIZONTAL;
        }

        if(keys[KDOWN]&&(isjumping||isfallen)&&!isdown){
            sdown=true;
        }else{
            sdown=false;
        }


        if (!keys[KLEFT] && !keys[KRIGHT] && countdelta<1){
            delta=SDL_GetTicks();
            countdelta=1;
        }

        if (!keys[KLEFT] && !keys[KRIGHT] && delta+50<SDL_GetTicks() && countdelta>0){
            tempsrun=0;
            tempsr=0;
            tempsd=0;
            countspeed=15;
            vspeed=0;

        }

        if(!ispaused){
            if(keys[KSPACE] && !isjumping && !isfallen && ground  ){
                Mix_PlayChannel(4,sjumpsound, 0);
                jump=true;
            }else{
                jump=false;
            }
        }

        /*
        if (keys[KSPACE] &&!jumpside && !jumpair && isjumping && !isfallen && ijump>5 &&!isdown){
            jumpside=true;
        }else{
            jumpside=false;
        }
        */




        /*
        Pour le jump je lui fais prendre une valeur par defaut et lui fait appliqué un coef multiplicateur
        */

        if (jump || isjumping || jumpair && !isdown){

            if (ijump<countjump && !jumpside){
                if(!ispaused){

                    if (tempjump[0]+50<SDL_GetTicks()){
                        vspeedy=-(pow(ijump,2));
                        //rectsrun.y+=vspeedy;
                        deplacementy+=vspeedy;
                        ijump++;
                        tempjump[0]=SDL_GetTicks();
                    }

                }


                sonicjump.y=rectsrun.y-sonicjump.h;
                sonicjump.x=rectsrun.x;
                last_rect=sonicjump;
                if (charge>0){
                    anglesonicjump+=10;
                }else{
                    anglesonicjump-=10;
                }


                SDL_RenderCopyEx(renderer,tsonicjump,NULL,&sonicjump,anglesonicjump,NULL,flip);
                chargefall=-1;
                isjumping=true;
            }
            else if (jumpside || jumpair){
                isjumping=false;
                if(countjumpside==8){
                    jumpair=false;
                }else{
                    jumpair=true;
                }
                if (tempjumpside+30<SDL_GetTicks() && countjumpside<=8){
                    countjumpside++;
                    tempjumpside=SDL_GetTicks();
                    if (charge>0){
                        deplacementx+=25;
                    }else{
                        deplacementx-=25;
                    }

                }

                rectsair.x=rectsrun.x;
                rectsair.y=rectsrun.y-rectsair.h;
                last_rect=rectsair;
                if (charge>0){
                    SDL_RenderCopy(renderer,tsair,NULL,&rectsair);
                }else{
                    SDL_RenderCopyEx(renderer,tsair,NULL,&rectsair,0,NULL,SDL_FLIP_HORIZONTAL);
                }
                jumpside=false;

                chargefall=1;
            }
            else if (ijump>=countjump || !jumpair ){
                isjumping=false;
                jumpside=false;
                ijump=1;
                chargefall=-1;
                tempjump[0]=0;
                tempjump[1]=0;
                countjumpside=0;
                tempjumpside=0;
                vspeedy=0;
            }


        }else{
            jumpside=false;
            ijump=1;
            tempjump[0]=0;
            tempjump[1]=0;
            countjumpside=0;
            tempjumpside=0;
            vspeedy=0;
        }


        if(sdown||isdown && !ground){

            if(tempdown[0]+50<SDL_GetTicks()){
                deplacementy+=40;
                tempdown[0]=SDL_GetTicks();
            }

            if(tempdown[1]+100<SDL_GetTicks()){
                indexdown++;
                if(indexdown>=sizeof(sonic_down)/sizeof(sonic_down[0])){
                    indexdown=2;
                }
                tempdown[1]=SDL_GetTicks();
            }
            if(wallr){
            sonic_down[indexdown].x=last_bgrect.x-sonic_down[indexdown].w;
            sonic_down[indexdown].y=rectsrun.y-sonic_down[indexdown].h;
            }else{
                sonic_down[indexdown].x=rectsrun.x;
                sonic_down[indexdown].y=rectsrun.y-sonic_down[indexdown].h;
            }

            last_rect=sonic_down[indexdown];
            SDL_RenderCopyEx(renderer,tsonic_down[indexdown],NULL,&sonic_down[indexdown],0,NULL,flip);

            isdown=true;
        }else{
            isdown=false;
            indexdown=0;
        }


        if(!ground && !isjumping &&!isdown){//&& !jumpair

            if(!ispaused){


                if(ifall>=1){
                    ifall=0;
                }
                if (iground>=8){
                    iground=8;
                }
                if (tempground[0]+50<SDL_GetTicks()){
                    vspeedy=pow(iground,2);
                    //rectsrun.y+=vspeedy;
                    deplacementy+=vspeedy;
                    iground++;
                    tempground[0]=SDL_GetTicks();
                }
                if (tempground[1]+200<SDL_GetTicks()){
                    ifall++;
                    tempground[1]=SDL_GetTicks();
                }



            }




            if(!jumpair){
                if (chargefall<0){
                    if (charge>0){
                        anglesonicjump+=10;
                    }else{
                        anglesonicjump-=10;
                    }
                    sonicjump.y=rectsrun.y-sonicjump.h;
                    sonicjump.x=rectsrun.x;
                    SDL_RenderCopyEx(renderer,tsonicjump,NULL,&sonicjump,anglesonicjump,NULL,flip);
                    last_rect=sonicjump;
                }else{
                    rectsfall.x=rectsrun.x;
                    rectsfall.y=rectsrun.y-rectsfall.h;
                    SDL_RenderCopyEx(renderer,tsfall,NULL,&rectsfall,0,NULL,flip);
                    last_rect=rectsfall;
                }

            }

            isfallen=true;
        }else {
            isfallen=false;
            iground=0;
            ifall=0;
            tempground[0]=0;
            tempground[1]=0;
            vspeedy=0;
            chargefall=1;
        }

        for(int z=0;z<6;z++){
            if(wallr){
                sonic_idle_rect[z].x=last_bgrect.x-sonic_idle_rect[z].w;
                sonic_idle_rect[z].y=rectsrun.y-sonic_idle_rect[z].h;
            }else{
                sonic_idle_rect[z].x=rectsrun.x;
                sonic_idle_rect[z].y=rectsrun.y-sonic_idle_rect[z].h;
            }


        }


        if(!keys[KLEFT] && !keys[KRIGHT] && !isjumping && ground){
            if(!ispaused){
                chargefall=1;

                if (tempidle>=5){
                    tempidle=0;
                }

                if (tempoidle+150<SDL_GetTicks()){
                    tempidle++;
                    tempoidle=SDL_GetTicks();
                }
            }

            last_rect=sonic_idle_rect[tempidle];
            SDL_RenderCopyEx(renderer, sonic_idle_texture[tempidle], NULL, &sonic_idle_rect[tempidle], 0, NULL, flip);

        }
        SDL_RenderDrawRect(renderer,&last_rect);
        if (keys[KESCAPE] && !ispaused){
            Mix_PlayChannel(3,pausedsound, 0);
            paused=true;
        }else{
            paused=false;
        }
        if(ispaused){
            Mix_PauseMusic();
        }else{
            Mix_ResumeMusic();
        }
        if(paused||ispaused){

            if(Pause(renderer,keys[KRETURN],keys[KUP],keys[KDOWN])==4){
                ispaused=false;
            }else{
                ispaused=true;

            }
            if(Pause(renderer,keys[KRETURN],keys[KUP],keys[KDOWN])==5){
                ispaused=false;
                TropicalResortLevel();
                break;
            }

            if(Pause(renderer,keys[KRETURN],keys[KUP],keys[KDOWN])==6){
                break;
            }

        }

        SDL_RenderCopy(renderer, sonic_score,NULL,&rectsoniccore);

        for(int i=0;i<=5;i++){
            indexnumber=counttimer[i];
            if(indexnumber!=10){
                list_number[indexnumber].x=pos[i];
                list_number[indexnumber].y=90;
                SDL_RenderCopy(renderer,tlist_number[indexnumber],NULL,&list_number[indexnumber]);
            }

            if (i<3){
                indexnumber=countring[i];
                list_number[indexnumber].x=pos3[i];
                list_number[indexnumber].y=55;
                SDL_RenderCopy(renderer,tlist_number[indexnumber],NULL,&list_number[indexnumber]);
                indexnumber=countlife[i];
                list_number[indexnumber].x=pos3[i];
                list_number[indexnumber].y=15;
                SDL_RenderCopy(renderer,tlist_number[indexnumber],NULL,&list_number[indexnumber]);

            }

        }
        SDL_RenderCopy(renderer,deuxpoint,NULL,&rectdeuxpoint);
        SDL_RenderCopy(renderer,point,NULL,&rectpoint);
        SDL_RenderPresent(renderer);
        waitTick(60);
    }


    return 0;
}

int GameOver(){

    return 0;
}


int LevelAct(){

    return 0;
}



int Pause(SDL_Renderer *renderer,bool enter,bool up,bool down){


    SDL_RenderCopy(renderer, pausefond, NULL, &rectPausefond);
    SDL_RenderCopy(renderer, pause, NULL, &rectPause);
    SDL_RenderCopy(renderer, texit, NULL, &rectexit);
    SDL_RenderCopy(renderer, ttcontinue, NULL, &recttcontinue);
    SDL_RenderCopy(renderer, trestart, NULL, &rectrestart);


    if(selectcursor<0){
        selectcursor=2;
    }else if(selectcursor>2){
        selectcursor=0;
    }
    if(tempcursor[0]+150<SDL_GetTicks() && up){
        Mix_PlayChannel(2,pausecursorsound, 0);
        selectcursor--;
        tempcursor[0]=SDL_GetTicks();
    }
    if(tempcursor[1]+150<SDL_GetTicks() && down){
        Mix_PlayChannel(2,pausecursorsound, 0);
        selectcursor++;
        tempcursor[1]=SDL_GetTicks();
    }

    switch(selectcursor){
        case 0:
            posselect=recttcontinue;
            break;
        case 1:
            posselect=rectrestart;
            break;
        case 2:
            posselect=rectexit;
            break;

    }
    rectselectpause.y=posselect.y;
    rectselectpause.x=posselect.x-40;
    SDL_RenderCopy(renderer, selectpause, NULL, &rectselectpause);
    rectselectpause.x=(posselect.x+posselect.w)+10;
    SDL_RenderCopyEx(renderer, selectpause, NULL, &rectselectpause,0,NULL,SDL_FLIP_HORIZONTAL);

    if (selectcursor==0 && enter){
        return 4;
    }else if (selectcursor==1 && enter){
        return 5;
    }else if (selectcursor==2 && enter){
        SDL_RenderClear(renderer);
        ispaused=false;
        WorldMap();
        return 6;
    }
    return 0;
}

int ScreenResult(){
    Load_ScreenResultElement();
    Init_keys();
    bool notpressed=true;
    bool isplaying=false;
    while (notpressed) {
        Event_keys(notpressed);
        if(Mix_Playing(3)==0 && !isplaying){
            Mix_PlayMusic(resultscreensound,-1);
            isplaying=true;
        }
        SDL_RenderCopy(renderer,tfondresult[0],NULL,&fondresult[0]);
        for(int i=0;i<4;i++){
            hud.x=PosHud[i][0];
            hud.y=PosHud[i][1];
            SDL_RenderCopy(renderer,thud,NULL,&hud);
        }
        for(int i=0;i<6;i++){

            indexnumber=timerecord[i];
            if(indexnumber!=10){
                list_number[indexnumber].x=Postimerecord[i];
                list_number[indexnumber].y=160;
                SDL_RenderCopy(renderer,tlist_number[indexnumber],NULL,&list_number[indexnumber]);
            }
            indexnumber=scorerecord[i];
            numberscore[indexnumber].x=Posscore[i];
            numberscore[indexnumber].y=200;
            SDL_RenderCopy(renderer,tnumberscore[indexnumber],NULL,&numberscore[indexnumber]);

            if (i<3){
                indexnumber=scorering[i];
                list_number[indexnumber].x=Posscorering[i];
                list_number[indexnumber].y=310;
                SDL_RenderCopy(renderer,tlist_number[indexnumber],NULL,&list_number[indexnumber]);
            }
            if (i<2){
                SDL_RenderCopy(renderer,tborderline[i],NULL,&borderline[i]);
            }

        }
        SDL_RenderCopy(renderer,trank[0],NULL,&rank[0]);
        SDL_RenderCopy(renderer,tresulttext,NULL,&resulttext);
        SDL_RenderCopy(renderer,tscoretext,NULL,&scoretext);
        SDL_RenderCopy(renderer,tranktext,NULL,&ranktext);

        SDL_RenderCopy(renderer,tringicon,NULL,&ringicon);
        SDL_RenderCopy(renderer,ttimericon,NULL,&timericon);
        SDL_RenderCopy(renderer,point,NULL,&rectpoint);
        SDL_RenderCopy(renderer,deuxpoint,NULL,&rectdeuxpoint);

        if (keys[KRETURN]){
            SDL_RenderClear(renderer);
            Mix_FreeMusic(resultscreensound);
            Mix_FreeChunk(stageclearsound);
            ActLocked[AreaMapIndex][ActIndex+1]=false;
            newact=true;
            AreaMap();
            break;
        }

        SDL_RenderPresent(renderer);
    }

    return 0;
}



bool MouseColision(int pos_mouse[],SDL_Rect rect){
    if (pos_mouse[0]>rect.x && pos_mouse[0]< (rect.x+rect.w) && pos_mouse[1]>rect.y && pos_mouse[1]<(rect.y+rect.h)){
        return true;
    }else{
        return false;
    }
}



bool Collision(SDL_Rect rect1,SDL_Rect rect2,direction way){
    if (way==RIGHT){
        /*
        if ((rect1.x+rect1.w)>=rect2.x && (rect1.x+rect1.w)<=(rect2.x+rect2.w)  && ( (rect1.y>=rect2.y&&(rect1.y+rect1.h)<=(rect2.y+rect2.h))||((rect2.y>=rect1.y)&&(rect2.y+rect2.h)<=(rect1.y+rect1.h))|| ( (rect2.y<=rect1.y&&(rect2.y+rect2.h>=rect1.y&&rect2.y+rect2.h<=rect1.y+rect1.h)) ||(rect2.y+rect2.h>=rect1.y+rect1.h&&(rect2.y>=rect1.y&&rect2.y<=rect1.y+rect1.h)) )  ) ){
            return true;
        }else{
            return false;
        }
        */
        if ( (rect1.x+rect1.w)>=rect2.x && (rect1.x+rect1.w)<=(rect2.x+rect2.w)  &&  (rect1.y>rect2.y&&(rect1.y+rect1.h)<=(rect2.y+rect2.h)) ){
            return true;
        }else{
            return false;
        }

    }else if(way==LEFT){
        if (rect1.x<=(rect2.x+rect2.w) &&rect1.x>=rect2.x && ( (rect1.y>rect2.y&&(rect1.y+rect1.h)<=(rect2.y+rect2.h))||((rect2.y>rect1.y)&&(rect2.y+rect2.h)<(rect1.y+rect1.h))|| ( (rect2.y<rect1.y&&(rect2.y+rect2.h>rect1.y&&rect2.y+rect2.h<rect1.y+rect1.h)) ||(rect2.y+rect2.h>rect1.y+rect1.h&&(rect2.y>rect1.y&&rect2.y<rect1.y+rect1.h)) )  ) ) {
            return true;
        }else{
            return false;
        }
    }else if(way==TOP){
        if ((rect1.y<=(rect2.y+rect2.h)) && (rect1.y>=rect2.y)   && ( (((rect1.x+rect1.w)>rect2.x&&(rect1.x+rect1.w)<(rect2.x+rect2.w)) || ((rect1.x<(rect2.x+rect2.w))&&(rect1.x>rect2.x))) ||  ((rect2.x>rect1.x)&&((rect2.x+rect2.w)<(rect1.x+rect1.w))) )  ) {
            return true;
        }else{
            return false;
        }
    }
    else if(way==BOTTOM){
        if (((rect1.y+rect1.h)>=rect2.y) && ((rect1.y+rect1.h)<=(rect2.y+rect2.h))    &&  ( (((rect1.x+rect1.w)>rect2.x&&(rect1.x+rect1.w)<(rect2.x+rect2.w)) || ((rect1.x<(rect2.x+rect2.w))&&(rect1.x>rect2.x))) ||  ((rect2.x>rect1.x)&&((rect2.x+rect2.w)<(rect1.x+rect1.w))) )  ) {
            return true;
        }else{
            return false;
        }
    }
    else if(way==ALL_DIRECTION){

        if ( ((rect1.x+rect1.w)>=rect2.x) && (rect1.x<=(rect2.x+rect2.w)) && ((rect1.y) <= (rect2.y+rect2.h)) && ((rect1.y+rect1.h) >= rect2.y)  ) {
            return true;
        }else{
            return false;
        }
    }

}


void Init_keys(){
    for(int i=0;i<sizeof(keys)/sizeof(keys[0]);i++){
        keys[i]=false;
    }
}

void Init_level_elements(){
    for(int i=0;i<Nring;i++){
        touched[i]=false;
        if(i<6){
            counttimer[i]=0;
            countring[i]=0;
        }
    }
    rectsrun.x=0;
    rectdeuxpoint.x=87;
    rectdeuxpoint.y=90;
    rectpoint.x=118;
    rectpoint.y=95;

    // boost,checkpoint a rajouter
}
