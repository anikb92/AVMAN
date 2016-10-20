#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void boundaryfill(int x,int y,int fcolour,int bcolour)
{
 if(getpixel(x,y)!=bcolour && getpixel(x,y)!=fcolour)
 {

  putpixel(x,y,fcolour);
  boundaryfill(x+1,y,fcolour,bcolour);
  boundaryfill(x,y+1,fcolour,bcolour);
  boundaryfill(x-1,y,fcolour,bcolour);
  boundaryfill(x,y-1,fcolour,bcolour);
 }
}



void drawmaze() {

 int i, j;

 setcolor(GREEN);

 rectangle(100,100,400,400);

 for(i=150;i<=350;i+=100)
 {
  line(100,i,200,i);
  line(250,i,350,i);
 }

 for(i=200;i<=300;i+=100)
 {
  line(150,i,250,i);
  line(300,i,400,i);
 }

 for(i=175,j=125;i<=375,j<=325;i+=100,j+=100)
 {
  line(200,i,200,j);
  line(350,i,350,j);
 }

 for(i=225,j=175;i<=325,j<=275;i+=100,j+=100)
 {
  line(150,i,150,j);
  line(300,i,300,j);
 }
}

void main()
{clrscr();
 int gd,gm,i,j;
 int key_RIGHT;
 detectgraph(&gd,&gm);
 initgraph(&gd,&gm,"c:\\turboc3\\bgi");

drawmaze();

 setcolor(YELLOW);
 fillellipse(125,200,5,5);
 boundaryfill(125,200,YELLOW,YELLOW);

 setcolor(YELLOW);
 fillellipse(225,250,5,5);
 boundaryfill(225,250,YELLOW,YELLOW);

 int x = 125, y = 125;

 setcolor(RED);
 fillellipse(x,y,5,5);
 boundaryfill(x,y,RED,RED);

 while(x != 395 || y != 395) {
	key_RIGHT = (int) getch();
	key_RIGHT = (int) getch();
	switch(key_RIGHT) {
		case 77:
			if(getpixel(x+5, y) == GREEN)
				break;

			setcolor(BLACK);
			boundaryfill(x, y, BLACK, BLACK);
			x += 5;
			setcolor(RED);
			fillellipse(x, y, 5, 5);
			boundaryfill(x, y, RED, RED);

			if(getpixel(x+10,y)==YELLOW){
			   setcolor(BLACK);
			   fillellipse(x+10,y,5,5);
			   boundaryfill(x+10,y,BLACK,BLACK);
			  }

			break;

		case 75:
			if(getpixel(x - 5, y) == GREEN)
			break;

			setcolor(BLACK);
			boundaryfill(x, y, BLACK, BLACK);
			x -= 5;
			setcolor(RED);
			fillellipse(x, y, 5, 5);
			boundaryfill(x, y, RED, RED);

			if(getpixel(x-10,y)==YELLOW){
			   setcolor(BLACK);
			   fillellipse(x-10,y,5,5);
			   boundaryfill(x-10,y,BLACK,BLACK);
			  }
			break;
		case 80:
			if(getpixel(x, y + 5) == GREEN)
			break;
			setcolor(BLACK);
			boundaryfill(x, y, BLACK, BLACK);
			y += 5;
			setcolor(RED);
			fillellipse(x, y, 5, 5);
			boundaryfill(x, y, RED, RED);

			if(getpixel(x,y+5)==YELLOW){
			   setcolor(BLACK);
			   fillellipse(x,y+5,5,5);
			   boundaryfill(x,y+5,BLACK,BLACK);
			  }
			break;
		case 72:
			if(getpixel(x, y - 5) == GREEN)
			break;
			setcolor(BLACK);
			boundaryfill(x, y, BLACK, BLACK);
			y -= 5;
			setcolor(RED);
			fillellipse(x, y, 5, 5);
			boundaryfill(x, y, RED, RED);

			if(getpixel(x,y-5)==YELLOW){
			   setcolor(BLACK);
			   fillellipse(x,y-5,5,5);
			   boundaryfill(x,y-5,BLACK,BLACK);
			  }
			break;
		case (int) 'd':
		case (int) 'D':
			x = 400;
			y = 400;

	}
	drawmaze();
 }

}