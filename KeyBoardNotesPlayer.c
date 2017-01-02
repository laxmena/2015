
#include<stdio.h>
#include<conio.h>
#include<dos.h>

char z;
FILE* fp;

int C=261.626,c=277.183,D=293.665,d=311.127,E=329.628,F=349.228,f=369.994,G=391.995,g=415.305,A=440,a=466.164,B=493.883;

void space(){
	delay(200);
	z=fgetc(fp);
	if(z==' ')
	   space();
}

void s(int x){
	nosound();
	delay(20);
	sound(x);
	delay(10);
}

void main(){
	char musi[20];
	clrscr();
	printf("Enter The music file name to play");
	scanf("%s",&musi);
	fp=fopen(musi,"r+");
	while((z=fgetc(fp))!=EOF){
		if(z==' '){
		  space();
		}
		else if(z=='~'){
		  delay(400);
		}
		else if(z=='\n'){
		  delay(100);
		  nosound();
		  delay(300);
		}
		switch(z){
			case 'C':s(C);break;
			case 'c':s(c);break;
			case 'D':s(D);break;
			case 'd':s(d);break;
			case 'E':s(E);break;
			case 'F':s(F);break;
			case 'f':s(f);break;
			case 'G':s(G);break;
			case 'g':s(g);break;
			case 'A':s(A);break;
			case 'a':s(a);break;
			case 'B':s(B);break;
			case 'p':nosound();delay(20);break;       }
		}
		nosound();
		fclose(fp);
		getch();
	}


