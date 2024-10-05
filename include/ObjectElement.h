


SDL_Texture *tring[9]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
SDL_Rect ring[9]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

const char *ring_path[9]={"bin/res/img/ObjectSprite/r1.png",
                        "bin/res/img/ObjectSprite/r2.png",
                        "bin/res/img/ObjectSprite/r3.png",
                        "bin/res/img/ObjectSprite/r4.png",
                        "bin/res/img/ObjectSprite/r5.png",
                        "bin/res/img/ObjectSprite/r6.png",
                        "bin/res/img/ObjectSprite/r7.png",
                        "bin/res/img/ObjectSprite/r8.png",
                        "bin/res/img/ObjectSprite/r9.png"};


int Posring[10][2]={{50,448},{60,448},{80,448},{90,448},{120,448},{150,448},{300,448},{350,448},{400,448},{450,448}};


int tempring=0;
int chargering=1;
int indexring[3]={0,0,0};

SDL_Texture *tgring[6]={NULL,NULL,NULL,NULL,NULL,NULL};
SDL_Rect gring[6]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

const char *gring_path[6]={"bin/res/img/ObjectSprite/gr1.png",
                        "bin/res/img/ObjectSprite/gr2.png",
                        "bin/res/img/ObjectSprite/gr3.png",
                        "bin/res/img/ObjectSprite/gr4.png",
                        "bin/res/img/ObjectSprite/gr5.png",
                        "bin/res/img/ObjectSprite/gr6.png"};

const char *bgring_path[6]={"bin/res/img/ObjectSprite/bgr1.png",
                        "bin/res/img/ObjectSprite/bgr2.png",
                        "bin/res/img/ObjectSprite/bgr3.png",
                        "bin/res/img/ObjectSprite/bgr4.png",
                        "bin/res/img/ObjectSprite/bgr5.png",
                        "bin/res/img/ObjectSprite/bgr5.png"};


int Posgring[7][2]={{300,490},{6390,448},{6390,448},{6390,448},{6390,448},{6390,448},{6390,448}};

int tempgring=0;
int chargegring=1;
int multig=1;
int Nring=sizeof(Posring)/sizeof(Posring[0]);
Mix_Chunk *ringsound=NULL;

bool touched[10]={false,false,false,false,false,false,false,false,false,false};

int Load_ObjectElement(){
    ringsound=Mix_LoadWAV("bin/res/audio/sound/common/SE_Ring_Mix.wav");
    for(int i=0;i<9;i++){
        tring[i]=SDL_LoadImage(renderer,ring_path[i],tring[i]);
        SDL_QueryTexture(tring[i],NULL,NULL,&ring[i].w,&ring[i].h);
        if (i<6){
            tgring[i]=SDL_LoadImage(renderer,bgring_path[i],tgring[i]);
            SDL_QueryTexture(tgring[i],NULL,NULL,&gring[i].w,&gring[i].h);
        }
    }
}
