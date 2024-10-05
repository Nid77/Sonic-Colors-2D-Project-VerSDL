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
const char *levelArea_path[4]={"assets/images/ElementSprite/locklevelact.png",
                            "assets/images/ElementSprite/levelact1.png",
                            "assets/images/ElementSprite/levelact2.png",
                            "assets/images/ElementSprite/levelact3.png"};
//C:/Users/THOMSON/Desktop/Save/Sonic/Project_sonic/assets/images/ElementSprite/

SDL_Rect Areafond[7]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
SDL_Texture *tAreafond[7]={NULL,NULL,NULL,NULL,NULL,NULL,NULL};

const char *Areafond_path[7]={"assets/images//TropicalResort/TropicalResortMap.png",
                            "assets/images/SweetMountain/SweetMountainMap.png",
                            "assets/images/StarlightCarnival/StarlightCarnivalMap.png",
                            "assets/images/PlanetWisp/PlanetWispMap.png",
                            "assets/images/AquariumPrak/AquariumPrakMap.png",
                            "assets/images/AsteoridCoaster/AsteoridCoasterMap.png",
                            "assets/images/Terminalvelocity/TerminalvelocityMap.png"
                            };
const char *Areasound_path[7]={"assets/sounds/Ost/TropicalResort/AreaTropicalResort.mp3",
                            "assets/sounds/Ost/SweetMountain/AreaSweetMountain.mp3",
                            "assets/sounds/Ost/StarlightCarnival/AreaStarlightCarnival.mp3",
                            "assets/sounds/Ost/PlanetWisp/AreaPlanetWisp.mp3",
                            "assets/sounds/Ost/AquariumPrak/AreaAquariumPrak.mp3",
                            "assets/sounds/Ost/AsteoridCoaster/AreaAsteoridCoaster.mp3",
                            "assets/sounds/Ost/Terminalvelocity/AreaTerminalvelocity.mp3"
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
    tSonicArea=SDL_LoadImage(renderer,"assets/images/ElementSprite/SonicHead.png",tSonicArea);
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

    pausedsound=Mix_LoadWAV("assets/sounds/sound/system/SYS_Actstg_Pausedecide.wav");

    pause=SDL_LoadImage(renderer,"assets/images/UI_PAUSE/pause.png",pause);
    SDL_QueryTexture(pause,NULL,NULL,&rectPause.w,&rectPause.h);


    pausefond=SDL_LoadImage(renderer,"assets/images/UI_PAUSE/pausefond.png",pausefond);
    SDL_QueryTexture(pausefond,NULL,NULL,&rectPausefond.w,&rectPausefond.h);

    selectpause=SDL_LoadImage(renderer,"assets/images/UI_PAUSE/selectpause.png",selectpause);
    SDL_QueryTexture(selectpause,NULL,NULL,&rectselectpause.w,&rectselectpause.h);
    TTF_Font *font=TTF_OpenFont("assets/fonts/NiseSegaSonic.ttf",30);
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



    pausecursorsound=Mix_LoadWAV("assets/sounds/sound/system/SYS_Actstg_Pausecursor.wav");

}
/*----------------------------------------------------------------------------------------------------------------------------------------------*/

SDL_Rect list_number[]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
SDL_Texture *tlist_number[]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
const char *list_number_path[]={"assets/images/UI/0.png","assets/images/UI/1.png","assets/images/UI/2.png","assets/images/UI/3.png","assets/images/UI/4.png",
                                "assets/images/UI/5.png","assets/images/UI/6.png","assets/images/UI/7.png","assets/images/UI/8.png","assets/images/UI/9.png",};

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


    sonic_score=SDL_LoadImage(renderer,"assets/images/UI/sonic_scoreboard.png",sonic_score);
    SDL_QueryTexture(sonic_score,NULL,NULL,&rectsoniccore.w,&rectsoniccore.h);
    deuxpoint=SDL_LoadImage(renderer,"assets/images/UI/deuxpoint.png",deuxpoint);
    SDL_QueryTexture(deuxpoint,NULL,NULL,&rectdeuxpoint.w,&rectdeuxpoint.h);
    point=SDL_LoadImage(renderer,"assets/images/UI/point.png",point);
    SDL_QueryTexture(point,NULL,NULL,&rectpoint.w,&rectpoint.h);



}
/*----------------------------------------------------------------------------------------------------------------------------------------------*/

SDL_Texture *gameovertext=NULL;
SDL_Rect rectgameovertext={0,0,0,0};

int Load_GameOverElement(){
    gameovertext=SDL_LoadImage(renderer,"assets/images/UI/gameovertext.png",gameovertext);
    SDL_QueryTexture(point,NULL,NULL,&rectgameovertext.w,&rectgameovertext.h);
}


/*----------------------------------------------------------------------------------------------------------------------------------------------*/

SDL_Texture *tfondresult[7]={NULL,NULL,NULL,NULL,NULL,NULL,NULL};
SDL_Rect fondresult[7]={{0,80,0,0},{0,20,0,0},{0,20,0,0},{0,20,0,0},{0,20,0,0},{0,20,0,0},{0,20,0,0}};

const char *fondresult_path[7]={"assets/images//TropicalResort/ResultTropicalResort.png",
                            "assets/images/SweetMountain/ResultSweetMountain.png",
                            "assets/images/StarlightCarnival/ResultStarlightCarnival.png",
                            "assets/images/PlanetWisp/ResultPlanetWisp.png",
                            "assets/images/AquariumPrak/ResultAquariumPrak.png",
                            "assets/images/AsteoridCoaster/AsteoridCoaster.png",
                            "assets/images/Terminalvelocity/ResultTerminalvelocity.png"
                        };

SDL_Texture *trank[5]={NULL,NULL,NULL,NULL,NULL};
SDL_Rect rank[5]={{WINDOWS_WIDTH/2+100,400,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

const char *rank_path[5]={"assets/images/UI_ENDLEVEL/s.png",
                        "assets/images/UI_ENDLEVEL/a.png",
                        "assets/images/UI_ENDLEVEL/b.png",
                        "assets/images/UI_ENDLEVEL/c.png",
                        "assets/images/UI_ENDLEVEL/d.png"
                        };

SDL_Rect numberscore[9]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
SDL_Texture *tnumberscore[9]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};

const char *numberscore_path[9]={"assets/images/UI_ENDLEVEL/0r.png",
                                "assets/images/UI_ENDLEVEL/1r.png",
                                "assets/images/UI_ENDLEVEL/2r.png",
                                "assets/images/UI_ENDLEVEL/3r.png",
                                "assets/images/UI_ENDLEVEL/4r.png",
                                "assets/images/UI_ENDLEVEL/5r.png",
                                "assets/images/UI_ENDLEVEL/6r.png",
                                "assets/images/UI_ENDLEVEL/7r.png",
                                "assets/images/UI_ENDLEVEL/9r.png"
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
const char *borderline_path[2]={"assets/images/UI_ENDLEVEL/borderline.png",
                                "assets/images/UI_ENDLEVEL/borderline2.png"};
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
    tranktext=SDL_LoadImage(renderer,"assets/images/UI/ranktext.png",tranktext);
    SDL_QueryTexture(tranktext,NULL,NULL,&ranktext.w,&ranktext.h);
    tscoretext=SDL_LoadImage(renderer,"assets/images/UI/scoretext.png",tscoretext);
    SDL_QueryTexture(tscoretext,NULL,NULL,&scoretext.w,&scoretext.h);
    tresulttext=SDL_LoadImage(renderer,"assets/images/UI/resulttext.png",tresulttext);
    SDL_QueryTexture(tresulttext,NULL,NULL,&resulttext.w,&resulttext.h);
    thud=SDL_LoadImage(renderer,"assets/images/UI/hud.png",thud);
    SDL_QueryTexture(thud,NULL,NULL,&hud.w,&hud.h);
    tsonicicon=SDL_LoadImage(renderer,"assets/images/UI/sonicicon.png",tsonicicon);
    SDL_QueryTexture(tsonicicon,NULL,NULL,&sonicicon.w,&sonicicon.h);
    ttimericon=SDL_LoadImage(renderer,"assets/images/UI/timericon.png",ttimericon);
    SDL_QueryTexture(ttimericon,NULL,NULL,&timericon.w,&timericon.h);
    tringicon=SDL_LoadImage(renderer,"assets/images/UI/ringicon.png",tringicon);
    SDL_QueryTexture(tringicon,NULL,NULL,&ringicon.w,&ringicon.h);
    /*
    tpointbleu=SDL_LoadImage(renderer,"assets/images/pointbleu.png",tpointbleu);
    SDL_QueryTexture(tpointbleu,NULL,NULL,&pointbleu.w,&pointbleu.h);
    tdeuxpointbleu=SDL_LoadImage(renderer,"assets/images/deuxpointbleu.png",tdeuxpointbleu);
    SDL_QueryTexture(tdeuxpointbleu,NULL,NULL,&deuxpointbleu.w,&deuxpointbleu.h);
    */
    rectdeuxpoint.x=282;
    rectdeuxpoint.y=160;
    rectpoint.x=310;
    rectpoint.y=165;
    resultscreensound=Mix_LoadMUS("assets/sounds/Ost/ResultScreen.mp3");
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
    tcursormouse=SDL_LoadImage(renderer,"assets/images/UI_MENU/cursormouse.png",tcursormouse);
    SDL_QueryTexture(tcursormouse,NULL,NULL,&cursormouse.w,&cursormouse.h);
}


/*----------------------------------------------------------------------------------------------------------------------------------------------*/
