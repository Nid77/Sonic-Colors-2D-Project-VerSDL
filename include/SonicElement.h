int Load_SonicSrpite();
const char *sonic_imagepath[]={"bin/res/img/SonicSprite/SonicColorsSrpite/s1.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s2.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s3.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s4.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s5.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s6.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s7.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s8.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s9.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s10.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s11.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s12.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s13.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s14.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s15.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s16.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s17.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s18.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s19.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s20.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s21.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s22.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s23.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s24.png",
                            "bin/res/img/SonicSprite/SonicColorsSrpite/s25.png"};




SDL_Rect sonic_runr[]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
                    {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};


SDL_Texture *sonic_runt[]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

SDL_Texture *sonic_idle_texture[]={NULL,NULL,NULL,NULL,NULL,NULL};
SDL_Rect sonic_idle_rect[]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

const char *sonic_idle_path[]={"bin/res/img/SonicSprite/s_idle1.png",
                            "bin/res/img/SonicSprite/s_idle2.png",
                            "bin/res/img/SonicSprite/s_idle3.png",
                            "bin/res/img/SonicSprite/s_idle4.png",
                            "bin/res/img/SonicSprite/s_idle5.png",
                            "bin/res/img/SonicSprite/s_idle6.png"};

SDL_Rect sonicjump;
SDL_Rect rectsair;
SDL_Rect rectsfall;
SDL_Texture *tsonicjump=NULL;
SDL_Texture *tsair=NULL;
SDL_Texture *tsfall=NULL;
Mix_Chunk *sjumpsound=NULL;
int anglesonicjump=0;
SDL_RendererFlip fliphorizon=SDL_FLIP_HORIZONTAL;
SDL_RendererFlip noflip=SDL_FLIP_NONE;
SDL_RendererFlip flip=SDL_FLIP_HORIZONTAL;
bool isdown=false;
SDL_Rect sonic_down[5]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
SDL_Texture *tsonic_down[]={NULL,NULL,NULL,NULL,NULL};
const char *sonic_down_path[5]={"bin/res/img/SonicSprite/SonicColorsSrpite/sdown1.png","bin/res/img/SonicSprite/SonicColorsSrpite/sdown2.png",
                                "bin/res/img/SonicSprite/SonicColorsSrpite/sdown3.png","bin/res/img/SonicSprite/SonicColorsSrpite/sdown4.png",
                                "bin/res/img/SonicSprite/SonicColorsSrpite/sdown5.png"};

int indexdown=0;
int tempdown[2]={0,0};
bool sdown=false;

int Load_SonicElement(){
    sjumpsound=Mix_LoadWAV("bin/res/audio/sound/player_sonic/sn_jump.wav");
    tsonicjump=SDL_LoadImage(renderer,"bin/res/img/SonicSprite/SonicColorsSrpite/j1.png",tsonicjump);
    SDL_QueryTexture(tsonicjump,NULL,NULL,&sonicjump.w,&sonicjump.h);
    sonicjump.y=rectsrun.y;
    sonicjump.x=rectsrun.x;
    tsair=SDL_LoadImage(renderer,"bin/res/img/SonicSprite/SonicColorsSrpite/sair.png",tsair);
    SDL_QueryTexture(tsair,NULL,NULL,&rectsair.w,&rectsair.h);
    tsfall=SDL_LoadImage(renderer,"bin/res/img/SonicSprite/SonicColorsSrpite/sfall.png",tsfall);
    SDL_QueryTexture(tsfall,NULL,NULL,&rectsfall.w,&rectsfall.h);
    for(int i=0;i<24;i++){
        sonic_runt[i]=SDL_LoadImage(renderer,sonic_imagepath[i],sonic_runt[i]);
        SDL_QueryTexture(sonic_runt[i],NULL,NULL,&sonic_runr[i].w,&sonic_runr[i].h);
    }
    for(int i=0;i<6;i++){
        sonic_idle_texture[i]=SDL_LoadImage(renderer,sonic_idle_path[i],sonic_idle_texture[i]);
        SDL_QueryTexture(sonic_idle_texture[i],NULL,NULL,&sonic_idle_rect[i].w,&sonic_idle_rect[i].h);

        if (i<5){
            tsonic_down[i]=SDL_LoadImage(renderer,sonic_down_path[i],tsonic_down[i]);
            SDL_QueryTexture(tsonic_down[i],NULL,NULL,&sonic_down[i].w,&sonic_down[i].h);
        }

    }
}
