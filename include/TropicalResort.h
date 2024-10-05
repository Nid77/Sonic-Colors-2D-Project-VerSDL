int Load_TropicalResortDecor();
int Load_AreaElement();

SDL_Texture *TropicalResortTexture[]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
SDL_Rect TropicalResortRect[]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
#define FOND_TROPICALRESORT 0
#define SOL2 3
#define SOL3 4
#define SOL4 5
#define SOL28 6
#define SOL29 7
#define SOL30 8

const char *TropicalResortpath[]={"bin/res/img/TropicalResort/Tropifond.png",
                        "bin/res/img/TropicalResort/Tropifond2.png",
                        "bin/res/img/TropicalResort/Tropifond3.png",
                        "bin/res/img/TropicalResort/colorsrz11/2.png",
                        "bin/res/img/TropicalResort/colorsrz11/3.png",
                        "bin/res/img/TropicalResort/colorsrz11/4.png",
                        "bin/res/img/TropicalResort/colorsrz11/28.png",
                        "bin/res/img/TropicalResort/colorsrz11/29.png",
                        "bin/res/img/TropicalResort/colorsrz11/30.png" };

Mix_Music *Ost=NULL;

const char *Ost_path[7][3]={{"bin/res/audio/Ost/TropicalResort/TropicalResortAct1.mp3","bin/res/audio/Ost/TropicalResort/TropicalResortAct2.mp3","bin/res/audio/Ost/TropicalResort/TropicalResortAct3.mp3"},
                            {"bin/res/audio/Ost/SweetMountain/SweetMountainAct1.mp3","bin/res/audio/Ost/SweetMountain/SweetMountainAct2.mp3","bin/res/audio/Ost/SweetMountain/SweetMountainAct3.mp3"},
                            {"bin/res/audio/Ost/StarlightCarnival/StarlightCarnival1.mp3","bin/res/audio/Ost/StarlightCarnival/StarlightCarnivalAct2.mp3","bin/res/audio/Ost/StarlightCarnival/StarlightCarnivalAct3.mp3"},
                            {"bin/res/audio/Ost/PlanetWisp/PlanetWispAct1.mp3","bin/res/audio/Ost/PlanetWisp/PlanetWispAct2.mp3","bin/res/audio/Ost/PlanetWisp/PlanetWispAct3.mp3"},
                            {"bin/res/audio/Ost/AquariumPrak/AquariumPrakAct1.mp3","bin/res/audio/Ost/AquariumPrak/AquariumPrakAct2.mp3","bin/res/audio/Ost/AquariumPrak/AquariumPrakAct3.mp3"},
                            {"bin/res/audio/Ost/AsteoridCoaster/AsteoridCoasterAct1.mp3","bin/res/audio/Ost/AsteoridCoaster/AsteoridCoasterAct2.mp3","bin/res/audio/Ost/AsteoridCoaster/AsteoridCoasterAct3.mp3"},
                            {"bin/res/audio/Ost/Terminalvelocity/TerminalvelocityAct1.mp3","bin/res/audio/Ost/Terminalvelocity/TerminalvelocityAct2.mp3","bin/res/audio/Ost/Terminalvelocity/TerminalvelocityAct3.mp3"}
                        };

Mix_Music *Tropisound=NULL;
Mix_Chunk *stageclearsound=NULL;
int Load_TropicalResortElement(){
    stageclearsound=Mix_LoadWAV("bin/res/audio/Ost/StageClear.wav");
    Tropisound=Mix_LoadMUS(Ost_path[AreaMapIndex][ActIndex]);
    if (!Tropisound){printf("%s\n",Mix_GetError() );}
    for(int i=0;i<sizeof(TropicalResortpath)/sizeof(TropicalResortpath[0]);i++){
        TropicalResortTexture[i]=SDL_LoadImage(renderer,TropicalResortpath[i],TropicalResortTexture[i]);
        SDL_QueryTexture(TropicalResortTexture[i],NULL,NULL,&TropicalResortRect[i].w,&TropicalResortRect[i].h);
    }
}
