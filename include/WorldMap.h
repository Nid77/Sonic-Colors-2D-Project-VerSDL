

//SDL_Rect planet_list[7]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

int Load_cadena();

#define BURST 0
#define LASER 1
#define DRILL 2
#define ROCKET 3
#define VOID 4
#define HOVER 5
#define SPIKE 6
#define FRENZY 7
#define CUBE 8
/*

SDL_Rect SweetMountain;
SweetMountain.x=32;
SweetMountain.y=288;
SweetMountain.w=207;
SweetMountain.h=187;
SDL_Rect TropicalResort;
TropicalResort.x=439;
TropicalResort.y=238;
TropicalResort.w=192;
TropicalResort.h=146;
SDL_Rect AquariumPark;
AquariumPark.x=886;
AquariumPark.y=187;
AquariumPark.w=256;
AquariumPark.h=190;
SDL_Rect StarlightCarnival;
StarlightCarnival.x=191;
StarlightCarnival.y=51;
StarlightCarnival.w=226;
StarlightCarnival.h=153;
SDL_Rect TerminalVelocity;
TerminalVelocity.x=378;
TerminalVelocity.y=436;
TerminalVelocity.w=148;
TerminalVelocity.h=87;
SDL_Rect PlanetWisp;
PlanetWisp.x=529;
PlanetWisp.y=17;
PlanetWisp.w=220;
PlanetWisp.h=171;
SDL_Rect AsteoridCoaster;
AsteoridCoaster.x=730;
AsteoridCoaster.y=456;
AsteoridCoaster.w=215;
AsteoridCoaster.h=182;
*/

/*
SDL_Color bleu={255,0,0,255};
SDL_SetRenderDrawColor(renderer, bleu.r, bleu.g, bleu.b, bleu.a);
SDL_RenderDrawRect(renderer,&AsteoridCoaster);
SDL_RenderDrawRect(renderer,&TropicalResort);
SDL_RenderDrawRect(renderer,&PlanetWisp);
SDL_RenderDrawRect(renderer,&AquariumPark);
SDL_RenderDrawRect(renderer,&StarlightCarnival);
SDL_RenderDrawRect(renderer,&TerminalVelocity);
SDL_RenderDrawRect(renderer,&SweetMountain);
*/



//SDL_Rect planet_list[8]={{439,238,192,146},{32,288,207,187},{886,187,256,190},{191,51,226,153},{529,17,220,171},{730,456,215,182},{378,436,148,87},{861,64,168,128}};

SDL_Rect planet_list[8]={{439,238,192,146},{32,288,207,187},{191,51,226,153},{529,17,220,171},{886,187,256,190},{730,456,215,182},{378,436,148,87},{861,64,168,128}};

//planet_list[7]={TropicalResort,SweetMountain,AquariumPark,StarlightCarnival,PlanetWisp,AsteoridCoaster,TerminalVelocity};

SDL_Rect rectcadena;
SDL_Texture *tcadena=NULL;
SDL_Rect pixelstars[6]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
SDL_Texture *tpixelstars[6]={NULL,NULL,NULL,NULL,NULL,NULL};
int indexstars=0;
int tempstars=0;
int chargestars=0;
int Posstars[6][2]={{94,200},{286,240},{322,416},{872,382},{762,200},{598,490}};
const char *stars_path[6]={"assets/images/UI_MENU/stars1.png",
                        "assets/images/UI_MENU/stars2.png",
                        "assets/images/UI_MENU/stars3.png",
                        "assets/images/UI_MENU/stars4.png",
                        "assets/images/UI_MENU/stars5.png",
                        "assets/images/UI_MENU/stars6.png"};
SDL_Texture *tborderworld=NULL;
SDL_Rect borderworld={0,20,0,0};
SDL_Texture *twispemplacement=NULL;
SDL_Rect wispemplacement={0,20,0,0};

int Poswispemplacement[2][2]={{280,10},{320,10}};
SDL_Rect wispindex[10]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
SDL_Texture *twispindex[10]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
const char *wispindex_path[10]={"assets/images/UI_MENU/indexburst.png",
                                "assets/images/UI_MENU/indexlaser.png",
                                "assets/images/UI_MENU/indexdrill.png",
                                "assets/images/UI_MENU/indexrocket.png",
                                "assets/images/UI_MENU/indexvoid.png",
                                "assets/images/UI_MENU/indexhover.png",
                                "assets/images/UI_MENU/indexspike.png",
                                "assets/images/UI_MENU/indexfrenzy.png",
                                "assets/images/UI_MENU/indexcube.png",
                                "assets/images/UI_MENU/indexghost.png"
                                };


SDL_Rect titlelevel[8]={{0,10,0,0},{0,10,0,0},{0,10,0,0},{0,10,0,0},{0,10,0,0},{0,10,0,0},{0,10,0,0},{0,20,0,0}};
SDL_Texture *ttitlelevel[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
const char *titlelevel_path[8]={"assets/images/TropicalResort/TropicalResortText.png",
                            "assets/images/SweetMountain/SweetMountainText.png",
                            "assets/images/StarlightCarnival/StarlightCarnivalText.png",
                            "assets/images/PlanetWisp/PlanetWispText.png",
                            "assets/images/AquariumPark/AquariumParkText.png",
                            "assets/images/AsteroidCoaster/AsteroidCoasterText.png",
                            "assets/images/TerminalVelocity/TerminalVelocityText.png",
                            "assets/images/GameLand/GameLandText.png"
                            };


int Load_cadena(){
    for(int i=0;i<8;i++){
        if(locked[i]){
            rectcadena.x=planet_list[i].x+(planet_list[i].w/2)-(rectcadena.h/2);
            rectcadena.y=planet_list[i].y+(planet_list[i].h/2)-(rectcadena.h/2);
            SDL_RenderCopy(renderer,tcadena,NULL,&rectcadena);
        }
    }
}

int Load_bg_worldmap(){

    tborderworld=SDL_LoadImage(renderer,"assets/images/UI_MENU/borderlineworld.png",tborderworld);
    SDL_QueryTexture(tborderworld,NULL,NULL,&borderworld.w,&borderworld.h);
    twispemplacement=SDL_LoadImage(renderer,"assets/images/UI_MENU/wispemplacement.png",twispemplacement);
    SDL_QueryTexture(twispemplacement,NULL,NULL,&wispemplacement.w,&wispemplacement.h);
    //borderworld.w+=20;
    //borderworld.h+=20;
    for(int i=0;i<10;i++){
        if(i<8){
            ttitlelevel[i]=SDL_LoadImage(renderer,titlelevel_path[i],ttitlelevel[i]);
            SDL_QueryTexture(ttitlelevel[i], NULL, NULL, &titlelevel[i].w, &titlelevel[i].h);
        }
        if(i<9){
            twispindex[i]=SDL_LoadImage(renderer,wispindex_path[i],twispindex[i]);
            SDL_QueryTexture(twispindex[i], NULL, NULL, &wispindex[i].w, &wispindex[i].h);
        }


        if (i<6){
            tpixelstars[i]=SDL_LoadImage(renderer,stars_path[i],tpixelstars[i]);
            SDL_QueryTexture(tpixelstars[i], NULL, NULL, &pixelstars[i].w, &pixelstars[i].h);
            pixelstars[i].w=25;
            pixelstars[i].h=25;
        }

    }

}
