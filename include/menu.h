

#define WINDOWS_HEIGHT 640
#define WINDOWS_WIDTH 1152


#define KUP 0
#define KDOWN 1
#define KLEFT 2
#define KRIGHT 3
#define CLEFT 4
#define CRIGHT 5
#define KSPACE 6
#define KRETURN 7
#define KESCAPE 8


//using namespace std;

int waitTick(int limitfps);
SDL_Texture *SDL_LoadImage(SDL_Renderer* renderer,const char *imagepath,SDL_Texture *texture);
SDL_Texture *SDL_LoadText(const char *text,SDL_Renderer * renderer ,TTF_Font *font, SDL_Color color);
int SDL_LoadImageBis(SDL_Renderer* renderer,const char *imagepath,SDL_Texture *texture,SDL_Rect *rect);
void Event_keys(bool finished);
int Event_cursor(int max);

typedef enum direction {
    RIGHT,
    LEFT,
    TOP,
    BOTTOM,
    ALL_DIRECTION,
    BOTTOMR,
    BOTTOML,
    TOPR,
    TOPL
} direction;
/*
typedef enum PATH {
    IMG,
    FONT,
    OBJECT,
    SONICSRPITE,
    WISP,
    ICON,
    OST,
    SOUND_EFFECT,
    WISP_SOUND
} PATH;
*/


int main_menu() {


    SDL_Texture *tfond=SDL_LoadImage(renderer,"assets/images/UI_MENU/mainmenu.png",tfond);
    SDL_Rect rectfond={0,0,0,0};
    SDL_QueryTexture(tfond, NULL, NULL, &rectfond.w, &rectfond.h);

    SDL_Texture *tlogo=SDL_LoadImage(renderer,"assets/images/UI_MAINMENU/logo.png",tlogo);
    SDL_Rect rectlogo;
    SDL_QueryTexture(tlogo, NULL, NULL, &rectlogo.w, &rectlogo.h);
    rectlogo.w*=0.6;
    rectlogo.h*=0.6;
    rectlogo.y=WINDOWS_HEIGHT/4-rectlogo.h;
    rectlogo.x=(WINDOWS_WIDTH/2)-(rectlogo.w/2);


    const char *text="PRESS ENTER";

    TTF_Font *font=TTF_OpenFont("assets/fonts/Syntha.ttf", 40);
    TTF_Font *font2=TTF_OpenFont("assets/fonts/NiseSegaSonic.ttf",30);
    if (!font){ printf("%s\n",TTF_GetError() );}
    if (!font2){ printf("%s\n",TTF_GetError() );}

    SDL_Color color2={255,127,0,255};
    SDL_Surface * surface = TTF_RenderText_Solid(font2, text , colorwhite);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Texture *tfangametext=SDL_LoadImage(renderer,"assets/images/UI_MAINMENU/fangametext.png",tfangametext);


    SDL_Rect fangametext;
    SDL_Rect dstrect;
    SDL_QueryTexture(texture, NULL, NULL, &dstrect.w, &dstrect.h);
    SDL_QueryTexture(tfangametext, NULL, NULL, &fangametext.w, &fangametext.h);
    dstrect.x=WINDOWS_WIDTH/2-(dstrect.w/2);
    dstrect.y=WINDOWS_HEIGHT - 50;
    fangametext.w*=2;
    fangametext.h*=2;
    fangametext.x=(rectlogo.x+(rectlogo.w/2))-(fangametext.w/2);
    fangametext.y=(rectlogo.y+rectlogo.h)+10;
    SDL_SetTextureAlphaMod(texture, colorwhite.a);


    SDL_Rect list_sonicfront[6]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    SDL_Texture *tlist_sonicfront[6]={NULL,NULL,NULL,NULL,NULL,NULL};
    const char *sonicfront_path[6]={"assets/images/SonicSprite/SonicColorsSrpite/s_intro1.png",
                                    "assets/images/SonicSprite/SonicColorsSrpite/s_intro2.png",
                                    "assets/images/SonicSprite/SonicColorsSrpite/s_intro3.png",
                                    "assets/images/SonicSprite/SonicColorsSrpite/s_intro4.png",
                                    "assets/images/SonicSprite/SonicColorsSrpite/s_intro5.png",
                                    "assets/images/SonicSprite/SonicColorsSrpite/s_intro6.png"};




    for(int i=0;i<6;i++){
        tlist_sonicfront[i]=SDL_LoadImage(renderer,sonicfront_path[i],tlist_sonicfront[i]);
        SDL_QueryTexture(tlist_sonicfront[i],NULL,NULL,&list_sonicfront[i].w,&list_sonicfront[i].h);
        list_sonicfront[i].x=WINDOWS_WIDTH/2-(list_sonicfront[i].w/2);;
        list_sonicfront[i].y=(WINDOWS_HEIGHT*3)/4-list_sonicfront[i].h;;
    }



    SDL_Rect list_wisp[6][4]={{{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
                            {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
                            {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
                            {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
                            {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}},
                            {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}};
    SDL_Texture *tlist_wisp[6][4]={{NULL,NULL,NULL,NULL},
                            {NULL,NULL,NULL,NULL},
                            {NULL,NULL,NULL,NULL},
                            {NULL,NULL,NULL,NULL},
                            {NULL,NULL,NULL,NULL},
                            {NULL,NULL,NULL,NULL}};


    const char *list_wispath[6][4]={"assets/images/WispsSprite/wispintro/yacker.png","assets/images/WispsSprite/wispintro/yacker2.png","assets/images/WispsSprite/wispintro/yacker.png","assets/images/WispsSprite/wispintro/yacker.png",
                                "assets/images/WispsSprite/wispintro/burst.png","assets/images/WispsSprite/wispintro/burst2.png","assets/images/WispsSprite/wispintro/burst3.png","assets/images/WispsSprite/wispintro/burst4.png",
                                "assets/images/WispsSprite/wispintro/laser.png","assets/images/WispsSprite/wispintro/laser2.png","assets/images/WispsSprite/wispintro/laser3.png","assets/images/WispsSprite/wispintro/laser4.png",
                                "assets/images/WispsSprite/wispintro/drill.png","assets/images/WispsSprite/wispintro/drill2.png","assets/images/WispsSprite/wispintro/drill3.png","assets/images/WispsSprite/wispintro/drill4.png",
                                "assets/images/WispsSprite/wispintro/rocket.png","assets/images/WispsSprite/wispintro/rocket2.png","assets/images/WispsSprite/wispintro/rocket3.png","assets/images/WispsSprite/wispintro/rocket4.png",
                                "assets/images/WispsSprite/wispintro/void.png","assets/images/WispsSprite/wispintro/void2.png","assets/images/WispsSprite/wispintro/void3.png","assets/images/WispsSprite/wispintro/void4.png"};
    for(int i=0;i<6;i++){
        for(int j=0;j<4;j++){
            tlist_wisp[i][j]=SDL_LoadImage(renderer,list_wispath[i][j],tlist_wisp[i][j]);
            SDL_QueryTexture(tlist_wisp[i][j],NULL,NULL,&list_wisp[i][j].w,&list_wisp[i][j].h);

        }
        if(i<4){
            list_wisp[0][i].x=(list_sonicfront[0].x+(list_sonicfront[0].w/2))+100;
            list_wisp[0][i].y=(list_sonicfront[0].y*1.5);

            list_wisp[1][i].x=list_sonicfront[0].x-100;
            list_wisp[1][i].y=(list_sonicfront[0].y*1.5);

            list_wisp[2][i].x=(list_sonicfront[0].x+(list_sonicfront[0].w/2))+200;
            list_wisp[2][i].y=(list_sonicfront[0].y*1.5)-50;

            list_wisp[3][i].x=list_sonicfront[0].x-200;
            list_wisp[3][i].y=(list_sonicfront[0].y*1.5)-50;

            list_wisp[4][i].x=(list_sonicfront[0].x+(list_sonicfront[0].w/2))+300;
            list_wisp[4][i].y=(list_sonicfront[0].y*1.5)-100;

            list_wisp[5][i].x=list_sonicfront[0].x-300;
            list_wisp[5][i].y=(list_sonicfront[0].y*1.5)-100;
        }


    }


    SDL_Texture *newgame=SDL_LoadImage(renderer,"assets/images/UI_MAINMENU/newgame.png",newgame);
    SDL_Texture *tcontinue=SDL_LoadImage(renderer,"assets/images/UI_MAINMENU/continue.png",tcontinue);//
    SDL_Texture *select=SDL_LoadImage(renderer,"assets/images/UI_MAINMENU/select.png",select);

    SDL_Rect rectnewgame;
    SDL_Rect rectcontinue;
    SDL_Rect rectselect;

    SDL_QueryTexture(newgame,NULL,NULL,&rectnewgame.w,&rectnewgame.h);
    SDL_QueryTexture(tcontinue,NULL,NULL,&rectcontinue.w,&rectcontinue.h);
    SDL_QueryTexture(select,NULL,NULL,&rectselect.w,&rectselect.h);

    rectnewgame.x=(WINDOWS_WIDTH/2)-(rectnewgame.w/2);
    rectcontinue.x=(WINDOWS_WIDTH/2)-(rectcontinue.w/2);
    rectselect.x=(WINDOWS_WIDTH/2)-(rectselect.w/2);
    rectnewgame.y=550;
    rectcontinue.y=580;
    rectselect.y=rectnewgame.y;

    int cl=0;
    int alphaf=0;
    int tempf=0;
    int tempsintro[]={0,0};
    int i=0;
    int ibis=0;
    bool menueselect=false,selected=false,entermenu=false;


    Mix_Music* bg_sound=NULL;
    bg_sound = Mix_LoadMUS("assets/sounds/Ost/ThemeofSonicColorsTitle.mp3");
    if (!bg_sound){printf("%s\n",Mix_GetError() );}
    Mix_PlayMusic(bg_sound, -1);
    Mix_VolumeMusic(10);
    bool launching = true;

    while (launching) {

        Event_keys(launching);

        if (keys[KRETURN] && !selected){
            menueselect=true;
            tempenter=SDL_GetTicks();
        }else{
            menueselect=false;
        }


        SDL_RenderCopy(renderer, tfond, NULL, &rectfond);
        SDL_RenderCopy(renderer, tlogo, NULL, &rectlogo);

        if (temp+50<SDL_GetTicks() && cl<255){
            cl+=10;
            temp=SDL_GetTicks();
        }
        if (cl>=255){
            cl=0;
        }
        colorwhite.a=cl;

        SDL_SetTextureAlphaMod(texture, colorwhite.a);
        if(!selected){
            SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        }
        SDL_RenderCopy(renderer, tfangametext, NULL, &fangametext);
        //SDL_RenderCopy(renderer, tnoir, NULL, &rectnoir);


        if (tempsintro[0]+120<SDL_GetTicks()){
            i++;
            tempsintro[0]=SDL_GetTicks();

        }
        if (i>=5){
            i=0;
        }
        if (tempsintro[1]+195<SDL_GetTicks()){
            ibis++;
            tempsintro[1]=SDL_GetTicks();

        }
        if (ibis>=3){
            ibis=0;
        }

        SDL_RenderCopy(renderer,tlist_sonicfront[i],NULL,&list_sonicfront[i]);
        for(int z=0;z<6;z++){
            SDL_RenderCopy(renderer,tlist_wisp[z][ibis],NULL,&list_wisp[z][ibis]);

        }



        if (menueselect || selected){
            if(selectcursor==0){
                rectselect.y=rectnewgame.y;
            }else{
                rectselect.y=rectcontinue.y;
            }
            SDL_RenderCopy(renderer,select,NULL,&rectselect);
            SDL_RenderCopy(renderer,newgame,NULL,&rectnewgame);
            SDL_RenderCopy(renderer,tcontinue,NULL,&rectcontinue);

            Event_cursor(1);

            SDL_PumpEvents();
            SDL_GetMouseState(&sx, &sy);
            souris_pos[0]=sx;
            souris_pos[1]=sy;
            if(MouseColision(souris_pos,rectnewgame)){
                selectcursor=0;
            }else if( MouseColision(souris_pos,rectcontinue)){
                selectcursor=1;
            }

            if(keys[KRETURN]&&tempenter+200<SDL_GetTicks()&&selectcursor==1){
                //launching=false;
                WorldMap();
                break;
            }
            if(keys[KRETURN]&&tempenter+200<SDL_GetTicks()&&selectcursor==0){
                //launching=false;
                WorldMap();
                break;
            }
            if (!keys[KESCAPE]){
                selected=true;
            }else{
                selected=false;
            }


        }
        waitTick(60);
        SDL_RenderPresent(renderer);
    }

    SDL_RenderClear(renderer);
    return 0;
}


SDL_Texture *SDL_LoadText(const char *text,SDL_Renderer * renderer ,TTF_Font *font, SDL_Color color){
  //TTF_Font *fontt=TTF_OpenFont("C:/Users/THOMSON/Desktop/Save/Project_sonic/assets/fonts/NiseSegaSonic.ttf", 25);
  SDL_Surface * surface = TTF_RenderText_Solid(font, text , color);
  SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);

  //SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
  //SDL_SetTextureAlphaMod(texture, color.a);


 //SDL_Rect dstrect = { pos_text[0], pos_text[1], texW, texH };
 //SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    return texture;

}

 SDL_Texture *SDL_LoadImage(SDL_Renderer* renderer,const char *imagepath,SDL_Texture *texture){
     SDL_Surface *image=NULL;
     if (!imagepath){ printf("erreur de chemin pour l'image : %s",imagepath); return 0;}

     image=IMG_Load(imagepath);

     if(!image) {
         printf("IMG_Load: %s\n", IMG_GetError()); return 0;
     }

     texture = SDL_CreateTextureFromSurface(renderer, image);
     SDL_FreeSurface(image);
     if(!texture){printf("erreur de texture");}



     return texture;
 }
int SDL_LoadImageBis(SDL_Renderer* renderer,const char *imagepath,SDL_Texture *texture,SDL_Rect *rect){
     SDL_Surface *image=NULL;
     if (!imagepath){ printf("erreur de chemin pour l'image : %s",imagepath); return 0;}

    image=IMG_Load(imagepath);
    if(!image) {printf("IMG_Load: %s\n", IMG_GetError()); return 0;}

    texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    if(!texture){printf("erreur de texture "); return 0;}

   // printf("%d\n",&rect );
    SDL_QueryTexture(texture, NULL, NULL, &rect->w, &rect->h);
         
     
     
     return 0;
 }


 void Event_keys(bool finished){

     SDL_Event event;

     while (SDL_PollEvent(&event)) {
         switch (event.type) {
             case SDL_MOUSEBUTTONDOWN:
                 if (event.button.button == SDL_BUTTON_LEFT) {
                     keys[CLEFT]=true;
                 }
                 if (event.button.button == SDL_BUTTON_RIGHT) {
                     keys[CRIGHT]=true;
                 }
                 mouse_pos[0] = event.button.x;
                 mouse_pos[1] = event.button.y;
                 break;

                 case SDL_MOUSEBUTTONUP:
                     if (event.button.button == SDL_BUTTON_LEFT) {
                         keys[CLEFT]=false;
                     }
                     if (event.button.button == SDL_BUTTON_RIGHT) {
                         keys[CRIGHT]=false;
                     }
                     break;


             case SDL_KEYDOWN:
                 switch (event.key.keysym.sym) {
                     case SDLK_UP:
                         keys[KUP] = true;
                         break;

                     case SDLK_LEFT:
                         keys[KLEFT] = true;
                         break;

                     case SDLK_DOWN:
                         keys[KDOWN] = true;
                         break;

                     case SDLK_RIGHT:
                         keys[KRIGHT] = true;
                         break;

                     case SDLK_ESCAPE:
                         keys[KESCAPE] = true;
                         break;

                     case SDLK_RETURN:
                         keys[KRETURN] = true;
                         break;

                     case SDLK_SPACE:
                         keys[KSPACE] = true;
                         break;

                     default:
                         break;

                 }
                 break;

             case SDL_KEYUP:
                 switch (event.key.keysym.sym) {
                     case SDLK_UP:
                         keys[KUP] = false;
                         break;

                     case SDLK_LEFT:
                         keys[KLEFT] = false;
                         break;

                     case SDLK_DOWN:
                         keys[KDOWN] = false;
                         break;

                     case SDLK_RIGHT:
                         keys[KRIGHT] = false;
                         break;

                     case SDLK_ESCAPE:
                         keys[KESCAPE] = false;
                         break;

                     case SDLK_RETURN:
                         keys[KRETURN] = false;
                         break;
                     case SDLK_SPACE:
                         keys[KSPACE] = false;
                         break;

                     default:
                         break;

                 }
                 break;


             case SDL_QUIT:
                 finished = !finished;
                 exit(EXIT_FAILURE);
                 break;
             default:
                 break;
         }
     }

 }

int Event_cursor(int max){
    if(selectcursor<0){
        selectcursor=max;
    }else if(selectcursor>max){
        selectcursor=0;
    }
    if(tempcursor[0]+150<SDL_GetTicks() && keys[0]){
        selectcursor++;
        tempcursor[0]=SDL_GetTicks();
    }
    if(tempcursor[1]+150<SDL_GetTicks() && keys[1]){
        selectcursor--;
        tempcursor[1]=SDL_GetTicks();
    }
}

int waitTick(int limitfps){
    int actualtime=SDL_GetTicks();
    if(limitfps-actualtime > 0){
        SDL_Delay(limitfps - actualtime);
    }
}
