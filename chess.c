#include<stdio.h>
char chess[8][8];
char next[8][8];
int check(short y,short x,short xt,short yt,char input){
    int c=0;
    int n=0;
    for (int i = x+xt,j=y+yt; i >-1 && j >-1 && j<8 && i<8; i+=xt,j+=yt){
        n++;
        if(chess[j][i]==input)  return 0;
        if(chess[j][i]!=input&&chess[j][i]!='0')    c=1;
        if(chess[j][i]=='0'){
            if(c==1){
                return n;
            }
            return 0;
        }
    }
}
void dnext(char input,short i,short j){
    if(input=='1'){
        if(next[j][i]!='b'){
            next[j][i]='w';
        }else{
            next[j][i]='a';
        }
        }else{
            if(next[j][i]!='w'){
                next[j][i]='b';
            }else{
                next[j][i]='a';
            }
    }
}
void printInput(char input){
    int d=0;
    input=(input=='1') ?'w':'b';
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(next[i][j]==input||next[i][j]=='a'){
                if(d==1){
                    printf(",");
                }else
                    d=1;
                printf("(%d,%d)",i,j);
            }
        }
    }
    printf("\n");
}
int main(){    
    int x,y;
    char haha;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; ){
            scanf("%c",&chess[i][j]);
            next[i][j]=chess[i][j];
            if (chess[i][j]=='\n'||chess[i][j]==' ')
            {
                continue;
            }
            j++;
        }
    }
    printf("input ");
    scanf("%1d%c%1d",&x,&haha,&y);
    char input=chess[x][y];
    if (input=='0'){
        return 0;
    }
    for (short i = -1; i < 2; i++){
        for (short j = -1; j < 2; j++){
            int temp=check(x,y,i,j,input);
            if(temp){
                dnext(input,x+temp*j,y+temp*i);
            }
        }
    }
    printInput(input);
    for (int k = 0; k < 8; k++){
        for (int m = 0; m < 8; m++){
            if(chess[k][m]=='0') continue;
            for (short i = -1; i < 2; i++){
                for (short j = -1; j < 2; j++){                    
                    int temp=check(k,m,i,j,chess[k][m]);
                    if(temp){
                        dnext(chess[k][m],k+temp*j,m+temp*i);
                    }
                }
            }
        }
    }
    printf("The white flag can be lowered:\n");
    printInput('1');
    printf("The black flag can be lowered:\n");
    printInput('2');
}
