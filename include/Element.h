int Load_PauseElement();
int Load_ScreenResultElement();


/*----------------------------------------------------------------------------------------------------------------------------------------------*/

SDL_Rect PosArea[7][3]={{{208,352},{311,320},{279,259}},{{0,0},{0,0},{0,0}},
                        {{0,0},{0,0},{0,0}},{{0,0},{0,0},{0,0}},
                        {{0,0},{0,0},{0,0}},{{0,0},{0,0},{0,0}},
                        {{0,0},{0,0},{0,0}}};
int indexAreaAnim=1;
int tempaAreaAnim=0;
SDL_Rect levelArea[4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
SDL_Texture *tlevelArea[4]={NULL,NULL,NULL,NULL};
const char *levelArea_path[4]={"bin/res/img/ObjectSprite/locklevelact.png",
                            "bin/res/img/ObjectSprite/levelact1.png",
                            "bin/res/img/ObjectSprite/levelact2.png",
                            "bin/res/img/ObjectSprite/levelact3.png"};
//C:/Users/THOMSON/Desktop/Save/Sonic/Project_sonic/bin/res/img/ObjectSprite/

SDL_Rect Areafond[7]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
SDL_Texture *tAreafond[7]={NULL,NULL,NULL,NULL,NULL,NULL,NULL};

const char *Areafond_path[7]={"bin/res/img//TropicalResort/TropicalResortMap.png",
                            "bin/res/img/SweetMountain/SweetMountainMap.png",
                            "bin/res/img/StarlightCarnival/StarlightCarnivalMap.png",
                            "bin/res/img/PlanetWisp/PlanetWispMap.png",
                            "bin/res/img/AquariumPrak/AquariumPrakMap.png",
                            "bin/res/img/AsteoridCoaster/AsteoridCoasterMap.png",
                            "bin/res/img/Terminalvelocity/TerminalvelocityMap.png"
                            };
const char *Areasound_path[7]={"bin/res/audio/Ost/TropicalResort/AreaTropicalResort.mp3",
                            "bin/res/audio/Ost/SweetMountain/AreaSweetMountain.mp3",
                            "bin/res/audio/Ost/StarlightCarnival/AreaStarlightCarnival.mp3",
                            "bin/res/audio/Ost/PlanetWisp/AreaPlanetWisp.mp3",
                            "bin/res/audio/Ost/AquariumPrak/AreaAquariumPrak.mp3",
                            "bin/res/audio/Ost/AsteoridCoaster/AreaAsteoridCoaster.mp3",
                            "bin/res/audio/Ost/Terminalvelocity/AreaTerminalvelocity.mp3"
                            };


Mix_Music *Areasound=NULL;
SDL_Rect SonicArea;
SDL_Texture*tSonicArea=NULL;
int PosSonicHead=0;
int tempSonicHead=0;
int multi=1;
int Load_AreaElement(){

    tAreafond[AreaMapIndex]=SDL_LoadImage(renderer,Areafond_path[AreaMapIndex],tAreafond[AreaMapIndex]);
    SDL_QueryTexture(tAreafond[AreaMapIndex], NULL, NULL, &Areafond[AreaMapIndex].w, &Areafond[AreaMapIndex].h);
    Areasound=Mix_LoadMUS(Areasound_path[AreaMapIndex]);
    if (!Areasound){printf("%s\n",Mix_GetError() );}
    tSonicArea=SDL_LoadImage(renderer,"bin/res/img/ObjectSprite/SonicHead.png",tSonicArea);
    SDL_QueryTexture(tSonicArea,NULL,NULL,&SonicArea.w,&SonicArea.h);
    for(int i=0;i<4;i++){
        tlevelArea[i]=SDL_LoadImage(renderer,levelArea_path[i],tlevelArea[i]);
        SDL_QueryTexture(tlevelArea[i],NULL,NULL,&levelArea[i].w,&levelArea[i].h);
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------------*/
SDL_Texture *pause=NULL;
SDL_Rect rectPause;
SDL_Texture *pausefond=NULL;
SDL_Rect rectPausefond;
SDL_Color colorexit={255,255,255};
SDL_Color colorcontinue={255,255,255};
SDL_Color colorrestart={255,255,255};
SDL_Texture *selectpause=NULL;
SDL_Rect rectselectpause;
SDL_Texture *ttcontinue=NULL;
SDL_Rect recttcontinue;
SDL_Texture *texit=NULL;
SDL_Rect rectexit;
SDL_Texture *trestart=NULL;
SDL_Rect rectrestart;
SDL_Rect posselect;
Mix_Chunk *pausecursorsound=NULL;
Mix_Chunk *pausedsound=NULL;


int Load_PauseElement(){

    pausedsound=Mix_LoadWAV("bin/res/audio/sound/system/SYS_Actstg_Pausedecide.wav");

    pause=SDL_LoadImage(renderer,"bin/res/img/pause.png",pause);
    SDL_QueryTexture(pause,NULL,NULL,&rectPause.w,&rectPause.h);


    pausefond=SDL_LoadImage(renderer,"bin/res/img/pausefond.png",pausefond);
    SDL_QueryTexture(pausefond,NULL,NULL,&rectPausefond.w,&rectPausefond.h);

    selectpause=SDL_LoadImage(renderer,"bin/res/img/selectpause.png",selectpause);
    SDL_QueryTexture(selectpause,NULL,NULL,&rectselectpause.w,&rectselectpause.h);
    TTF_Font *font=TTF_OpenFont("bin/res/font/NiseSegaSonic.ttf",30);
    if (!font){ printf("%s\n",TTF_GetError() );}



    ttcontinue=SDL_LoadText("CONTINUE",renderer ,font,  colorcontinue);
    SDL_QueryTexture(ttcontinue,NULL,NULL,&recttcontinue.w,&recttcontinue.h);

    texit=SDL_LoadText("EXIT",renderer ,font,  colorexit);
    SDL_QueryTexture(texit,NULL,NULL,&rectexit.w,&rectexit.h);

    trestart=SDL_LoadText("RESTART",renderer ,font,  colorrestart);
    SDL_QueryTexture(trestart,NULL,NULL,&rectrestart.w,&rectrestart.h);

    rectPause.x=(WINDOWS_WIDTH/2)-(rectPause.w/2);
    rectPause.y=(WINDOWS_HEIGHT/2)-rectPause.h;
    rectPausefond.x=(WINDOWS_WIDTH/2)-(rectPausefond.w/2);
    rectPausefond.y=rectPause.y-50;
    recttcontinue.x=(WINDOWS_WIDTH/2)-(recttcontinue.w/2);
    recttcontinue.y=rectPause.y+rectPause.h+10;
    rectrestart.x=(WINDOWS_WIDTH/2)-(rectrestart.w/2);
    rectrestart.y=recttcontinue.y+recttcontinue.h+10;
    rectexit.x=(WINDOWS_WIDTH/2)-(rectexit.w/2);
    rectexit.y=rectrestart.y+rectrestart.h+10;



    pausecursorsound=Mix_LoadWAV("bin/res/audio/sound/system/SYS_Actstg_Pausecursor.wav");

}
/*----------------------------------------------------------------------------------------------------------------------------------------------*/

SDL_Rect list_number[]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
SDL_Texture *tlist_number[]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
const char *list_number_path[]={"bin/res/img/0.png","bin/res/img/1.png","bin/res/img/2.png","bin/res/img/3.png","bin/res/img/4.png",
                                "bin/res/img/5.png","bin/res/img/6.png","bin/res/img/7.png","bin/res/img/8.png","bin/res/img/9.png",};

SDL_Rect rectsoniccore={0,0,0,0};
SDL_Rect rectdeuxpoint={87,90,0,0};
SDL_Rect rectpoint={118,95,0,0};
SDL_Texture *sonic_score=NULL;
SDL_Texture *deuxpoint=NULL;
SDL_Texture *point=NULL;
int indexnumber=0;
int pos[]={65,75,95,105,125,135};
int pos3[]={65,75,85};
int Load_SonicScore(){
    for(int i=0;i<10;i++){
        tlist_number[i]=SDL_LoadImage(renderer,list_number_path[i],tlist_number[i]);
        SDL_QueryTexture(tlist_number[i],NULL,NULL,&list_number[i].w,&list_number[i].h);
    }


    sonic_score=SDL_LoadImage(renderer,"bin/res/img/sonic_scoreboard.png",sonic_score);
    SDL_QueryTexture(sonic_score,NULL,NULL,&rectsoniccore.w,&rectsoniccore.h);
    deuxpoint=SDL_LoadImage(renderer,"bin/res/img/deuxpoint.png",deuxpoint);
    SDL_QueryTexture(deuxpoint,NULL,NULL,&rectdeuxpoint.w,&rectdeuxpoint.h);
    point=SDL_LoadImage(renderer,"bin/res/img/point.png",point);
    SDL_QueryTexture(point,NULL,NULL,&rectpoint.w,&rectpoint.h);



}
/*----------------------------------------------------------------------------------------------------------------------------------------------*/

SDL_Texture *gameovertext=NULL;
SDL_Rect rectgameovertext={0,0,0,0};

int Load_GameOverElement(){
    gameovertext=SDL_LoadImage(renderer,"bin/res/img/gameovertext.png",gameovertext);
    SDL_QueryTexture(point,NULL,NULL,&rectgameovertext.w,&rectgameovertext.h);
}


/*----------------------------------------------------------------------------------------------------------------------------------------------*/

SDL_Texture *tfondresult[7]={NULL,NULL,NULL,NULL,NULL,NULL,NULL};
SDL_Rect fondresult[7]={{0,80,0,0},{0,20,0,0},{0,20,0,0},{0,20,0,0},{0,20,0,0},{0,20,0,0},{0,20,0,0}};

const char *fondresult_path[7]={"bin/res/img//TropicalResort/ResultTropicalResort.png",
                            "bin/res/img/SweetMountain/ResultSweetMountain.png",
                            "bin/res/img/StarlightCarnival/ResultStarlightCarnival.png",
                            "bin/res/img/PlanetWisp/ResultPlanetWisp.png",
                            "bin/res/img/AquariumPrak/ResultAquariumPrak.png",
                            "bin/res/img/AsteoridCoaster/AsteoridCoaster.png",
                            "bin/res/img/Terminalvelocity/ResultTerminalvelocity.png"
                        };

SDL_Texture *trank[5]={NULL,NULL,NULL,NULL,NULL};
SDL_Rect rank[5]={{WINDOWS_WIDTH/2+100,400,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

const char *rank_path[5]={"bin/res/img/s.png",
                        "bin/res/img/a.png",
                        "bin/res/img/b.png",
                        "bin/res/img/c.png",
                        "bin/res/img/d.png"
                        };

SDL_Rect numberscore[9]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
SDL_Texture *tnumberscore[9]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

const char *numberscore_path[9]={"bin/res/img/0r.png",
                                "bin/res/img/1r.png",
                                "bin/res/img/2r.png",
                                "bin/res/img/3r.png",
                                "bin/res/img/4r.png",
                                "bin/res/img/5r.png",
                                "bin/res/img/6r.png",
                                "bin/res/img/7r.png",
                                "bin/res/img/9r.png"
                                };

Mix_Music *resultscreensound=NULL;


int scorering[3]={0,0,0};
int Posscorering[3]={260,270,280};
int scorerecord[6]={0,0,0,0,0,0};
int Posscore[6]={606,636,666,696,726,756};
int timerecord[6]={0,0,0,0,0,0};
int Postimerecord[6]={260,270,290,300,315,325};
int ringposition=0;
int PosHud[4][2]={{WINDOWS_WIDTH/2,150},{WINDOWS_WIDTH/2,350},{200,150},{200,300}};

SDL_Texture *tranktext=NULL;
SDL_Texture *tscoretext=NULL;
SDL_Texture *tresulttext=NULL;
SDL_Texture *thud=NULL;
SDL_Texture *tsonicicon=NULL;
SDL_Texture *tringicon=NULL;
SDL_Texture *ttimericon=NULL;
//SDL_Texture *tpointbleu=NULL;
//SDL_Texture *tdeuxpointbleu=NULL;

SDL_Rect borderline[2]={{0,560,0,0},{0,60,0,0}};
SDL_Texture *tborderline[2]={NULL,NULL};
const char *borderline_path[2]={"bin/res/img/borderline.png",
                                "bin/res/img/borderline2.png"};
SDL_Rect ranktext={WINDOWS_WIDTH/2,340};
SDL_Rect scoretext={WINDOWS_WIDTH/2,140};
SDL_Rect resulttext={50,30};
SDL_Rect sonicicon;
//SDL_Rect pointbleu={410,160};
//SDL_Rect deuxpointbleu={280,160};
SDL_Rect ringicon={210,280};
SDL_Rect timericon={210,130};
SDL_Rect hud;


int Load_ScreenResultElement(){
    tranktext=SDL_LoadImage(renderer,"bin/res/img/ranktext.png",tranktext);
    SDL_QueryTexture(tranktext,NULL,NULL,&ranktext.w,&ranktext.h);
    tscoretext=SDL_LoadImage(renderer,"bin/res/img/scoretext.png",tscoretext);
    SDL_QueryTexture(tscoretext,NULL,NULL,&scoretext.w,&scoretext.h);
    tresulttext=SDL_LoadImage(renderer,"bin/res/img/resulttext.png",tresulttext);
    SDL_QueryTexture(tresulttext,NULL,NULL,&resulttext.w,&resulttext.h);
    thud=SDL_LoadImage(renderer,"bin/res/img/hud.png",thud);
    SDL_QueryTexture(thud,NULL,NULL,&hud.w,&hud.h);
    tsonicicon=SDL_LoadImage(renderer,"bin/res/img/sonicicon.png",tsonicicon);
    SDL_QueryTexture(tsonicicon,NULL,NULL,&sonicicon.w,&sonicicon.h);
    ttimericon=SDL_LoadImage(renderer,"bin/res/img/timericon.png",ttimericon);
    SDL_QueryTexture(ttimericon,NULL,NULL,&timericon.w,&timericon.h);
    tringicon=SDL_LoadImage(renderer,"bin/res/img/ringicon.png",tringicon);
    SDL_QueryTexture(tringicon,NULL,NULL,&ringicon.w,&ringicon.h);
    /*
    tpointbleu=SDL_LoadImage(renderer,"bin/res/img/pointbleu.png",tpointbleu);
    SDL_QueryTexture(tpointbleu,NULL,NULL,&pointbleu.w,&pointbleu.h);
    tdeuxpointbleu=SDL_LoadImage(renderer,"bin/res/img/deuxpointbleu.png",tdeuxpointbleu);
    SDL_QueryTexture(tdeuxpointbleu,NULL,NULL,&deuxpointbleu.w,&deuxpointbleu.h);
    */
    rectdeuxpoint.x=282;
    rectdeuxpoint.y=160;
    rectpoint.x=310;
    rectpoint.y=165;
    resultscreensound=Mix_LoadMUS("bin/res/audio/Ost/ResultScreen.mp3");
    tfondresult[AreaMapIndex]=SDL_LoadImage(renderer,fondresult_path[AreaMapIndex],tfondresult[AreaMapIndex]);
    SDL_QueryTexture(tfondresult[AreaMapIndex],NULL,NULL,&fondresult[AreaMapIndex].w,&fondresult[AreaMapIndex].h);
    for(int i=0;i<9;i++){
        tnumberscore[i]=SDL_LoadImage(renderer,numberscore_path[i],tnumberscore[i]);
        SDL_QueryTexture(tnumberscore[i],NULL,NULL,&numberscore[i].w,&numberscore[i].h);
        if (i<5){
            trank[i]=SDL_LoadImage(renderer,rank_path[i],trank[i]);
            SDL_QueryTexture(trank[i],NULL,NULL,&rank[i].w,&rank[i].h);
        }
        if (i<2){
            tborderline[i]=SDL_LoadImage(renderer,borderline_path[i],tborderline[i]);
            SDL_QueryTexture(tborderline[i],NULL,NULL,&borderline[i].w,&borderline[i].h);
        }
        /*
        if (i<7){
            tfondresult[i]=SDL_LoadImage(renderer,fondresult_path[i],tfondresult[i]);
            SDL_QueryTexture(tfondresult[i],NULL,NULL,&fondresult[i].w,&fondresult[i].h);
        }
        */
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------------*/

SDL_Texture *tcursormouse=NULL;
SDL_Rect cursormouse;
int Load_Cursor(){
    tcursormouse=SDL_LoadImage(renderer,"bin/res/img/cursormouse.png",tcursormouse);
    SDL_QueryTexture(tcursormouse,NULL,NULL,&cursormouse.w,&cursormouse.h);
}


/*----------------------------------------------------------------------------------------------------------------------------------------------*/
