//Code Written by Lakshmanan on July 08, 2015

#include<stdio.h>
#include<conio.h>
#include<time.h>

char a[3][3],w,r='f';

void grid(){
    int i;
    printf("\n\n");
    printf("     1   2   3\n\n");
    for(i=0;i<3;i++){
       printf("%d    %c | %c | %c \n",i+1,a[i][0],a[i][1],a[i][2]);
       if(i<2)
          printf("    ---+---+---\n");
    }
}

void rep(){
    int x,y;
    time_t t;
    srand((unsigned) time(&t));
    x=rand()%3;
    y=rand()%3;
    if(a[x][y]==' ')
      a[x][y]='O';
    else
      rep();
}

void input(){
    int x,y;
    printf("Enter Coordinates \nX: ");
    scanf("%d",&x);
    printf("Y: ");
    scanf("%d",&y);
    if(a[x-1][y-1]==' ')
         a[x-1][y-1]='X';
    else{
         grid();
         printf("Invalid Coordinates, Try again");
         input();
     }
}

void check(){
  int i;
  for(i=1;i<4;i++){
     if(a[i][1]==a[i][2]&&a[i][1]==a[i][3]&&(a[i][1]=='X'||a[i][1]=='O')){
         w=a[i][1];
         r='t';
         break;
     }
     else if(a[1][i]==a[2][i]&&a[2][i]==a[3][i]&&(a[1][i]=='X'||a[1][i]=='O')){
         w=a[1][i];
         r='t';
         break;
     }
  }
  if(r=='f'){
      if(a[1][1]==a[2][2]&&a[2][2]==a[3][3]&&(a[1][1]=='X'||a[1][1]=='O')){
         r='t';
         w=a[2][2];
      }
  }

  if(r=='f'){
     if(a[1][3]==a[2][2]&&a[2][2]==a[3][1]&&(a[1][3]=='X'||a[1][3]=='O')){
        r='t';
        w=a[2][2];
     }
  }
}

void result(){
    printf("\nGame Over\nplayer %c has won",w);
}

void main(){
  int i,j;
  for(i=0;i<3;i++)
     for(j=0;j<3;j++)
        a[i][j]=' ';
  grid();
  do{
     input();
     check();
     rep();
     check();
     grid();
   }while(r=='f');
  result();
  getch();
}
