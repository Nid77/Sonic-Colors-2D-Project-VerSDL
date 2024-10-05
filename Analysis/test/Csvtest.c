#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAXCHAR 100000
int list[10][100];
int Load_CSV(char *filepath);
//gcc src/Csvtest.c -o bin/prog -I include -L lib -lmingw32

int main(){


    Load_CSV("TropicalResortAct1.csv");
    printf("%d\n",list[9][0] );

    return 0;
}

int Load_CSV(char *filepath){
    FILE *fp = NULL;
    fp=fopen(filepath,"r");
    char row[MAXCHAR];
    char *token;
    int count=0,countr=0;
    char newnumber[6];
    for(int i=0;i<5;i++){
        newnumber[i]=' ';
    }
    int n_row=0,n_column=0;

    while (!feof(fp))
    {
    token = strtok(row, "\n");
    fgets(row, MAXCHAR, fp);
    printf("Numero de ligne : %d,[%s]\n",n_column,row );
    count=0;
    countr=0;
    for(int i=0;i<5;i++){
        newnumber[i]=' ';
    }
    while (count <strlen(row)) {

        if ((char)row[count]==','){
            list[n_column][countr]=atoi(newnumber);
            for (size_t i = 0; i < 5; i++) {
                newnumber[i]=' ';
            }
            countr++;
        }else{

            for (size_t i = 0; i < 5; i++) {
                if(newnumber[i]==' '){
                    newnumber[i]=(char)row[count];
                    break;
                }
            }
        }
        count++;
    }
    n_column++;
    }
    fclose(fp);
    return 0;
}
