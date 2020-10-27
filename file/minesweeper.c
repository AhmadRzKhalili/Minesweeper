#include <stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>

void cls();
void bomb(int bmb[][2],int number[][30]);
void num(char ground[][30],int bmb[][2],int number[][30]);
void choose(int a,int b,int number[][30],char ground[][30],int bmb[][2]);
void flagger(int a,int b,char ground[][30]);
void unflagger(int a,int b,char ground[][30]);

int main()
{
    char cmd[3],ground[14][30];
    int bmb[40][2],number[14][30]={0},bmbg[14][30]={0};
    int x,y;
    for(int i=0;i<14;i++)
    {
        for(int j=0;j<30;j++)
            ground[i][j]='#';
    }
    for(int i=0;i<14;i++)
    {
        for(int j=0;j<30;j++)           
            printf("%c ", ground [i][j]);           
        printf("\n");           
    }
    bomb(bmb,number);
    num(ground,bmb,number);
    while(1){
    fgets(cmd, sizeof(cmd)*3, stdin);
    if(cmd[0]=='e'&&cmd[1]=='x'&&cmd[2]=='t')
        break;
    else
    if(cmd[0]=='c'&&cmd[1]=='h'&&cmd[2]=='o'){
        scanf("%d",&x);
        scanf("%d",&y);
        choose(x,y,number,ground,bmb);
        for(int i=0;i<14;i++)
        {
            for(int j=0;j<30;j++)           
                if(ground[i][j]=='*')
                    break;           
        }
    }
    else
    if(cmd[0]=='f'&&cmd[1]=='l'&&cmd[2]=='a'){
        scanf("%d",&x);
        scanf("%d",&y);
        flagger(x,y,ground);
    }
    else  
    if(cmd[0]=='u'&&cmd[1]=='f'&&cmd[2]=='l'){
        scanf("%d",&x);
        scanf("%d",&y);
        unflagger(x,y,ground);
    }
    }
    return 0;
}

void num(char ground[][30],int bmb[][2],int number[][30])
{
    int x,y;
    for(int i=0;i<40;i++)
    {
        x=bmb[i][0];
        y=bmb[i][1];
        for(int j=x-1;j<=x+1;j++)
        {
            for(int k=y-1;k<=y+1;k++)
            {
                if(j==x&&k==y)
                    continue;
                else
                    number[j][k]++;
            }
        }
    }
}

void cls(){
    system("cls");
}

void bomb(int bmb[][2],int number[][30])
{
    srand(time(0));
    int x,y;
    for(int i=0;i<40;i++)
    {
        x=1+rand()%13;
        y=1+rand()%39;
        if(number[x-1][y-1]==-1&&number[x-1][y]==-1&&number[x-1][y+1]==-1&&number[x][y-1]==-1&&number[x][y+1]==-1&&number[x+1][y-1]==-1&&number[x+1][y]==-1&&number[x+1][y+1]==-1)
        {
            i--;
            continue;
        }
        number[x][y]=-1;
        bmb[i][0]=x;
        bmb[i][1]=y;
    }
}

void choose(int a,int b,int number[][30],char ground[][30],int bmb[][2])
{
    int x,y,temp=0,p,q,w;
    p=a;
    q=b;
    if(number[a][b]==-1)
    {
    
        for(int i=0;i<40;i++)
        {
            x=bmb[i][0];
            y=bmb[i][1];
            ground[x][y]='*';
        }
        cls();
        for(int i=0;i<14;i++)
        {
            for(int j=0;j<30;j++)           
                printf("%c ", ground [i][j]);           
            printf("\n");           
        }
    }
    else
    if(number[a][b]==0)
    {
        for(int i=a-1;i<=a+1;i++)
        {
            for(int j=b-1;j<=b+1;j++)
            {
                if(number[i][j]!=-1)
                    temp+=number[i][j];
            }
        }
    }
    if(temp==0)
    {
        q=b+3;
        choose(p,q,number,ground,bmb);
        q=b-3;
        choose(p,q,number,ground,bmb);
        q=b;
        p=a-3;
        choose(p,q,number,ground,bmb);
        p=a+3;
        choose(p,q,number,ground,bmb);
    }
    else{
        for(int i=a-1;i<=a+1;i++)
        {
            for(int j=b-1;j<=b+1;j++)
            {
                if(number[i][j]!=0)
                    ground[i][j]=number[i][j]+48;
                if(number[i][j]==0)
                    ground[i][j]=' ';
                if(number[i][j]==-1)
                    ground[i][j]='#';
            }
        }
        cls();
    }
    for(int i=0;i<14;i++)
    {
        for(int j=0;j<30;j++)           
            printf("%c ", ground [i][j]);           
        printf("\n");           
    }
}

void flagger(int a,int b,char ground[][30])
{
    if(ground[a-1][b]='#'){
        ground[a][b]='P';
        cls();
        for(int i=0;i<14;i++)
        {
            for(int j=0;j<30;j++)           
                printf("%c ", ground [i][j]);           
            printf("\n");           
        }
    }
}

void unflagger(int a,int b,char ground[][30])
{
    if(ground[a][b]='P'){
        ground[a][b]='#';
        cls();
        for(int i=0;i<14;i++)
        {
            for(int j=0;j<30;j++)           
                printf("%c ", ground [i][j]);           
            printf("\n");           
        }
    }
}