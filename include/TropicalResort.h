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

const char *TropicalResortpath[]={"assets/images/TropicalResort/Tropifond.png",
                        "assets/images/TropicalResort/Tropifond2.png",
                        "assets/images/TropicalResort/Tropifond3.png",
                        "assets/images/TropicalResort/colorsrz11/2.png",
                        "assets/images/TropicalResort/colorsrz11/3.png",
                        "assets/images/TropicalResort/colorsrz11/4.png",
                        "assets/images/TropicalResort/colorsrz11/28.png",
                        "assets/images/TropicalResort/colorsrz11/29.png",
                        "assets/images/TropicalResort/colorsrz11/30.png" };

Mix_Music *Ost=NULL;

const char *Ost_path[7][3]={{"assets/sounds/Ost/TropicalResort/TropicalResortAct1.mp3","assets/sounds/Ost/TropicalResort/TropicalResortAct2.mp3","assets/sounds/Ost/TropicalResort/TropicalResortAct3.mp3"},
                            {"assets/sounds/Ost/SweetMountain/SweetMountainAct1.mp3","assets/sounds/Ost/SweetMountain/SweetMountainAct2.mp3","assets/sounds/Ost/SweetMountain/SweetMountainAct3.mp3"},
                            {"assets/sounds/Ost/StarlightCarnival/StarlightCarnival1.mp3","assets/sounds/Ost/StarlightCarnival/StarlightCarnivalAct2.mp3","assets/sounds/Ost/StarlightCarnival/StarlightCarnivalAct3.mp3"},
                            {"assets/sounds/Ost/PlanetWisp/PlanetWispAct1.mp3","assets/sounds/Ost/PlanetWisp/PlanetWispAct2.mp3","assets/sounds/Ost/PlanetWisp/PlanetWispAct3.mp3"},
                            {"assets/sounds/Ost/AquariumPrak/AquariumPrakAct1.mp3","assets/sounds/Ost/AquariumPrak/AquariumPrakAct2.mp3","assets/sounds/Ost/AquariumPrak/AquariumPrakAct3.mp3"},
                            {"assets/sounds/Ost/AsteoridCoaster/AsteoridCoasterAct1.mp3","assets/sounds/Ost/AsteoridCoaster/AsteoridCoasterAct2.mp3","assets/sounds/Ost/AsteoridCoaster/AsteoridCoasterAct3.mp3"},
                            {"assets/sounds/Ost/Terminalvelocity/TerminalvelocityAct1.mp3","assets/sounds/Ost/Terminalvelocity/TerminalvelocityAct2.mp3","assets/sounds/Ost/Terminalvelocity/TerminalvelocityAct3.mp3"}
                        };

Mix_Music *Tropisound=NULL;
Mix_Chunk *stageclearsound=NULL;
int Load_TropicalResortElement(){
    stageclearsound=Mix_LoadWAV("assets/sounds/Ost/StageClear.wav");
    Tropisound=Mix_LoadMUS(Ost_path[AreaMapIndex][ActIndex]);
    if (!Tropisound){printf("%s\n",Mix_GetError() );}
    for(int i=0;i<sizeof(TropicalResortpath)/sizeof(TropicalResortpath[0]);i++){
        TropicalResortTexture[i]=SDL_LoadImage(renderer,TropicalResortpath[i],TropicalResortTexture[i]);
        SDL_QueryTexture(TropicalResortTexture[i],NULL,NULL,&TropicalResortRect[i].w,&TropicalResortRect[i].h);
    }
}
