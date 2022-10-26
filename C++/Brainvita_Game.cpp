/* Brainvita - Game in C++ (Project) */

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <time.h>
#include <bios.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define ESC 27
#define YES 1
#define NO 0
int x=320,y=100,marble=32,marble_color=12;
void *p;
size_t area;
//	Matrix of board
int board[7][7]=
{
	{-1,-1,1,1,1,-1,-1},
	{-1,-1,1,1,1,-1,-1},
	{ 1, 1,1,1,1, 1, 1},
	{ 1, 1,1,1,1, 1, 1},
	{ 1, 1,1,1,1, 1, 1},
	{-1,-1,1,1,1,-1,-1},
	{-1,-1,1,1,1,-1,-1}
};

//------------------------------------------------------------------------
//				Function Prototypes
//------------------------------------------------------------------------

void Marble(int x,int y,int c);
void G();
int check();
int GetXY(int X,int Y);
int GetBoard(int X,int Y);
void SetBoard(int X,int Y,int element);
void Blink(int x,int y,int c);
void DrawBoard();
int MakeMove(int X,int Y);
void Init();
int finish();
void win(char *text,int sx,int sy,int ex,int ey,int ck);
void winp(int sx,int sy,int ex,int ey,int state);
void Menu();
void LCD(int left,int top,int NUM);
void Lcd(int x,int y,int n);
void Intro();
void Drawborder(int x,int y);
void Background();
int load_game ();
int save_game();

//------------------------------------------------------------------------
//				Main Function
//------------------------------------------------------------------------

void main()
{
   int i;
   G();
   Intro();
   Background();
   DrawBoard();
   Marble(320,220,0);
   board[3][3]=0;
   Init();
   setcolor(0);
   for(i=0;i<=220;i++)
   {
   rectangle(0+i,0+i,640-i,480-i);
   delay(10);
   }
   for(i=0;i<=220;i++)
   {
   rectangle(100+i,100,540-i,380);
   delay(8);
   }
   closegraph();
   getch();
}
void Marble(int x,int y,int c)
{
   setfillstyle(1,c);
   setcolor(c);
   fillellipse(x,y,8,8);
   if(c!=0)
   {
   if(c==15){setcolor(7);setfillstyle(1,7);}
   else {setfillstyle(1,15);setcolor(15);}
   fillellipse(x+3,y-2,1,2);
   }
}
void mydelay(float secs)
{
	clock_t start, end;
	start = clock();
	do
	{
		end = clock();
		if(kbhit()) break;
	}while(((end - start)/CLK_TCK)<secs);
}
void Intro()
{
   int i;
   char pattern[8] ={0xfe,0xbc,0xda,0xe4,0xe2,0xc0,0x88,0x00};
   setfillpattern(pattern,1);
   bar(0,0,640,480);
   settextstyle(1,0,5);
   setcolor(10);
   getch();
   setcolor(0);
   for(i=0;i<=320;i++)
   {
   rectangle(0+i,0,640-i,480);
   delay(5);
   }
  //   win("BRAINVITA",1,1,638,478,1);
}
void Drawborder(int x,int y)
{
   setwritemode(COPY_PUT);
   setcolor(0);
   line(x+60,y-20,x+180,y-20);//       __
   line(x+60,y+60,x+60,y-20);//      |
   line(x-40,y+60,x+60,y+60);//   __
   line(x-40,y+60,x-40,y+180);// |
   setcolor(15);
   line(x-40,y+180,x+60,y+180);// __
   setcolor(0);
   line(x+60,y+180,x+60,y+280);//   |
   setcolor(15);
   line(x+180,y-20,x+180,y+60);//        |
   setcolor(0);
   line(x+180,y+60,x+290,y+60);//         __
   setcolor(15);
   line(x+290,y+60,x+290,y+180);//          |
   line(x+180,y+180,x+290,y+180);//       __
   line(x+180,y+180,x+180,y+280);//      |
   line(x+180,y+280,x+60,y+280);//    __
   setwritemode(XOR_PUT);
}

void Background()
{
   int i;
   setfillstyle(1,3);
   bar(0,0,640,480);
   for(i=0;i<=15;i++)
   {
   setcolor(i);
   rectangle(0+i,0+i,640-i,480-i);
   }
  win("BRAINVITA",145,45,505,400,1);
//  winp(159,79,491,381,1);
  win("Keys",24,45,135,290,1);
  win("Help !",510,45,625,250,1);
  setfillstyle(1,0);
  bar(35,75,125,280);
  bar(520,75,618,240);
  winp(35,75,125,280,1);
  winp(520,75,618,240,1);
  setcolor(14);
  settextstyle(2,0,4);
  outtextxy(42,80,"Keys used");
  setcolor(15);
  outtextxy(42,100,"+ or- : color");
  outtextxy(47,120,"³  : Up");
  outtextxy(47,140,"³  : Down");
  outtextxy(42,160,"<- : Left");
  outtextxy(42,180,"-> : Right");
  outtextxy(42,200,"Enter : Pick");
  outtextxy(42,220,"S : save game");
  outtextxy(42,240,"L : load game");
  outtextxy(42,260,"Esc : Exit");
  line(47,120,50,123);
  line(47,120,43,123);
  line(47,140,50,143);
  line(47,140,43,143);
  outtextxy(523,80,"Use Arrow Keys");
  outtextxy(523,100,"to move around");
  outtextxy(523,120,"then press enter");
  outtextxy(523,140,"to select any");
  outtextxy(523,160,"marble,then jump");
  outtextxy(523,180,"over another to");
  outtextxy(523,200,"remove it.");
  win("",190,410,480,460,0);
  setfillstyle(1,0);
  bar(200,420,470,450);
  settextstyle(1,0,3);
  setcolor(10);
  outtextxy(220,420,"Marbles :");
}

//------------------------------------------------------------------------
//			Draw The Whole Board on Screen
//------------------------------------------------------------------------

void DrawBoard()
{
   int i,j,x=200,y=100;
   x=200;y=100;
   setfillstyle(1,1);
   bar(x-40,y-20,x+290,y+280);
   setfillstyle(1,7);
   bar(x-41,y-21,x+60,y+60);
   bar(x+180,y-21,x+290,y+60);
   bar(x-41,y+180,x+60,y+290);
   bar(x+180,y+180,x+290,y+290);
   Drawborder(x,y);
   Drawborder(x+1,y+1);
   setfillstyle(1,12);
   setcolor(11);
   for(i=0;i<7;i++)
   {
	for(j=0;j<7;j++)
	{
	    if(board[j][i]!=-1)
	    {
	     if(board[j][i]==1)
	     Marble(x,y,marble_color);
	     if(board[j][i]==0)
	     Marble(x,y,0);
	    }
	    x+=40;
	}
	x=200;
	y+=40;
   }
   settextstyle(1,0,3);
}

//------------------------------------------------------------------------
//				Switch Into Graphics mode
//------------------------------------------------------------------------

void G()
{
   int gdriver = DETECT, gmode, errorcode;
/*
   // for stand alone
   registerfarbgidriver(EGAVGA_driver_far);
   registerfarbgifont(sansserif_font_far);
   registerfarbgifont(small_font_far);
   registerfarbgifont(gothic_font_far);
   registerfarbgifont(triplex_font_far);
    */
   initgraph(&gdriver, &gmode, "");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s
", grapherrormsg(errorcode));
      exit(1);
   }
   area=imagesize(150,70,240,180);
   p=malloc(area);
   if(p==NULL)
   {closegraph();exit(1);}
}

//------------------------------------------------------------------------
//			Check the board if any move is possible
//------------------------------------------------------------------------

int check() // a know bug is there
{
   int i,j,flag;
   flag=0;
   for(i=0;i<7;i++)
   {
    for(j=0;j<7;j++)
    if(board[j][i]!=-1)
    {
	if(board[j][i]==1)
	{
		if(board[j+1][i]==1)
		{
			  if(board[j+2][i]==0)
			  flag++;

		}
		if(board[j-1][i]==1)
		{
			  if(board[j-2][i]==0)
			  flag++;

		}
		if(board[j][i+1]==1)
		{
			  if(board[j][i+2]==0)
			  flag++;

		}
		if(board[j][i-1]==1)
		{
			  if(board[j][i-2]==0)
			  flag++;

		}

	}
    }
   }
   //count marble
   marble=0;
   for(i=0;i<7;i++)
   {
    for(j=0;j<7;j++)
    if(board[j][i]==1)
    marble++;
   }
   return flag;
}

//------------------------------------------------------------------------
//      Give the current x,y position on board & find is it valid or not
//------------------------------------------------------------------------

int GetXY(int X,int Y)
{
   int i,j,x=200,y=100,flag=0;
   for(i=0;i<7;i++)
   {
	for(j=0;j<7;j++)
	{
	    if(board[j][i]!=-1)
	    {
	     if(x==X && y==Y)
	     flag=1;
	    }
	    x+=40;
	}
	x=200;
	y+=40;
   }
   return flag;
}

//------------------------------------------------------------------------
//		check current position is filled or not
//------------------------------------------------------------------------

int GetBoard(int X,int Y)
{
   int i,j,x=200,y=100,f=-1;
   for(i=0;i<7;i++)
   {
	for(j=0;j<7;j++)
	{
	    if(board[j][i]!=-1)
	    {
	     if(x==X && y==Y)
	     f=board[j][i];
	    }
	    x+=40;
	}
	x=200;
	y+=40;
   }
   return f;
}

//------------------------------------------------------------------------
//	Sets the board to 1 or 0 ,represents filled & empty respectively
//------------------------------------------------------------------------

void SetBoard(int X,int Y,int element)
{
   int i,j,x=200,y=100;
   for(i=0;i<7;i++)
   {
	for(j=0;j<7;j++)
	{
	    if(board[j][i]!=-1)
	    {
	     if(x==X && y==Y)
	     board[j][i]=element;
	    }
	    x+=40;
	}
	x=200;
	y+=40;
   }
}

//------------------------------------------------------------------------
//			Blinks the cursor or square
//------------------------------------------------------------------------

void Blink(int x,int y,int c)
{
 int i;
 setcolor(c);
 do
 {
	rectangle(x-10,y-10,x+10,y+10);
	rectangle(x-11,y-11,x+11,y+11);
	mydelay(0.5);
	rectangle(x-10,y-10,x+10,y+10);
	rectangle(x-11,y-11,x+11,y+11);
	mydelay(0.5);
 }while(!kbhit());
}

//------------------------------------------------------------------------
//		 When ENTER pressed check for conditions & perform task
//------------------------------------------------------------------------

int MakeMove(int X,int Y)
{
 int flag,key;
 flag=NO;
 if(marble_color==11)
 Marble(X,Y,9);
 else Marble(X,Y,11);
 key = bioskey(0);
 if(key==0x4800)//up
 {
	if(GetBoard(X,Y-80)==0 && GetBoard(X,Y-40)==1)
	{
		  Marble(X,Y,0);
		  SetBoard(X,Y,0);
		  Y-=40;
		  Marble(X,Y,0);
		  SetBoard(X,Y,0);
		  Y-=40;
		  SetBoard(X,Y,1);
		  y=Y;
		  flag=YES;
	}
 }
 if(key==0x5000)//down
 {
	if(GetBoard(X,Y+80)==0 && GetBoard(X,Y+40)==1)
	{
		  Marble(X,Y,0);
		  SetBoard(X,Y,0);
		  Y+=40;
		  Marble(X,Y,0);
		  SetBoard(X,Y,0);
		  Y+=40;
		  SetBoard(X,Y,1);
		  y=Y;
		  flag=YES;
	}
 }
 if(key==0x4b00)//left
 {
	if(GetBoard(X-80,Y)==0 && GetBoard(X-40,Y)==1)
	{
		  Marble(X,Y,0);
		  SetBoard(X,Y,0);
		  X-=40;
		  Marble(X,Y,0);
		  SetBoard(X,Y,0);
		  X-=40;
		  SetBoard(X,Y,1);
		  x=X;
		  flag=YES;
	}
 }
 if(key==0x4d00)//right
 {
	if(GetBoard(X+80,Y)==0 && GetBoard(X+40,Y)==1)
	{
		  Marble(X,Y,0);
		  SetBoard(X,Y,0);
		  X+=40;
		  Marble(X,Y,0);
		  SetBoard(X,Y,0);
		  X+=40;
		  SetBoard(X,Y,1);
		  x=X;
		  flag=YES;
	}
  }
  if(kbhit()) getch();
  setcolor(11);
  if(flag==YES)
  {
	Marble(X,Y,marble_color);
  }
  else//invalid key
  {
	Marble(X,Y,marble_color);
	sound(800);
	delay(100);
	nosound();
  }
  return flag;
}

//------------------------------------------------------------------------
//		Handles All the funtions & Perform desired move
//------------------------------------------------------------------------

void Init()
{
   int i,j,e=1;
   char ch;
   setwritemode(XOR_PUT);
   setcolor(15);
   while(e)
   {
    setfillstyle(1,11);
    Lcd(360,425,marble);
    Blink(x,y,11);
    ch=getch();
    Lcd(360,425,marble);
    if(ch==ESC) e=0;
    if(GetXY(x,y)==1)
    {
	switch(ch)
	{
		case    UP :if(GetXY(x,y-40)==1)
				if(y>100) y-=40;break;
		case  DOWN :if(GetXY(x,y+40)==1)
				if(y<340) y+=40;break;
		case  LEFT :if(GetXY(x-40,y)==1)
				if(x>200) x-=40;break;
		case RIGHT :if(GetXY(x+40,y)==1)
				if(x<440) x+=40;break;
		case ENTER :if(GetBoard(x,y)==1)
			    {
			     MakeMove(x,y);
			    }
			    break;
		case ESC   :e=0;break;
		case '+': marble_color++;
			 if(marble_color>15) marble_color=2;
			 DrawBoard();
			 break;
		case '-':marble_color--;
			 if(marble_color<2) marble_color=15;
			 DrawBoard();
			 break;
		case 's':case 'S':save_game();break;
		case 'l':case 'L':load_game();break;
	}//switch
    }//if
   if(check()==0) e=finish();
   }//while
   setwritemode(COPY_PUT);
}

//------------------------------------------------------------------------
//			Display Final Screen
//------------------------------------------------------------------------

int finish()
{
    int i,j,f;
    char opt=0;
    setwritemode(COPY_PUT);
    f=0;
    for(i=0;i<7;i++)
    {
    for(j=0;j<7;j++)
    if(board[j][i]==1)
    f++;
    }
    Lcd(360,425,marble);
//    f-=1;
    win("Done !",220,155,425,240,1);
    setcolor(0);
    settextstyle(1,0,1);
    switch(f)
    {
	case 1:outtextxy(230,180,"You Are Intelligent !");break;
	case 2:outtextxy(255,180,"    Wonderful !");break;
	case 3:outtextxy(255,180,"  Good Job !");break;
	case 4:outtextxy(255,180,"  Can be better !");break;
	case 5:outtextxy(230,180," You Need Practice !");break;
	case 6:outtextxy(230,180,"   Very Poor !");break;
	case 7:outtextxy(230,180," Very Very Poor !");break;
	default:outtextxy(255,180," Try Again !");break;
    }
//    gotoxy(1,1);printf("%d",f);
    getch();
    win("Exit ?",220,155,425,240,1);
    settextstyle(1,0,1);
    setcolor(1);
    outtextxy(240,180,"Play Again [y/n] :");
    opt=getch();
    setfillstyle(1,3);
    bar(17,402,624,464);
    if(opt=='y' || opt=='Y')
    {
     for(i=0;i<7;i++)
     {
	for(j=0;j<7;j++)
	if(board[j][i]!=-1) board[j][i]=1;
     }
     Marble(320,220,0);
     board[3][3]=0;
     marble=32;
     Background();
     DrawBoard();
     f=1;
    }
    else f=0;
    setwritemode(XOR_PUT);
    return f;
}
void win(char *text,int sx,int sy,int ex,int ey,int ck)
{
   setfillstyle(1,7);
   bar(sx,sy,ex,ey);
   setfillstyle(1,7);
   setcolor(15);
   line(sx,sy,sx,ey);
   line(sx,sy,ex,sy);
   line(sx,sy,sx,ey);
   line(sx,sy,ex,sy);
   setcolor(0);
   line(ex,sy,ex,ey);
   line(ex,sy,ex,ey);
   line(sx,ey,ex,ey);
   line(sx,ey,ex,ey);
   if(ck==1)
   {
   settextstyle(0,0,0);
   setfillstyle(1,1);
   bar(sx+2,sy+2,ex-2,sy+17);
   setcolor(15);
   outtextxy(sx+4,sy+4,text);
   //for x
   setfillstyle(1,7);
   bar(ex-15,sy+4,ex-4,sy+15);
   setcolor(15);
   line(ex-15,sy+4,ex-4,sy+4);
   line(ex-15,sy+4,ex-15,sy+15);
   setcolor(0);
   line(ex-15,sy+15,ex-4,sy+15);
   line(ex-4,sy+4,ex-4,sy+15);
   setcolor(1);
   outtextxy(ex-13,sy+5,"x");
   setfillstyle(1,7);
   }
}
void winp(int sx,int sy,int ex,int ey,int state)
{
   if(state==1)
   {
   setcolor(0);
   line(sx,sy,sx,ey);
   line(sx,sy,ex,sy);
   line(sx,sy,sx,ey);
   line(sx,sy,ex,sy);
   setcolor(15);
   line(ex,sy,ex,ey);
   line(ex,sy,ex,ey);
   line(sx,ey,ex,ey);
   line(sx,ey,ex,ey);
  }
  else
  {
   setcolor(15);
   line(sx,sy,sx,ey);
   line(sx,sy,ex,sy);
   line(sx,sy,sx,ey);
   line(sx,sy,ex,sy);
   setcolor(0);
   line(ex,sy,ex,ey);
   line(ex,sy,ex,ey);
   line(sx,ey,ex,ey);
   line(sx,ey,ex,ey);
  }
}
void mybar(int sx,int sy,int ex,int ey)
{
 int i;
// setcolor(14);
 for(i=sy;i<=ey;i++)
 line(sx,i,ex,i);
}
void Menu()
{
 setcolor(0);
 settextstyle(2,0,4);
 getimage(161,80,240,180,p);
 win(" ",161,80,240,180,0);
 outtextxy(170,88,"New Game");
 outtextxy(170,105,"Exit");
 setwritemode(XOR_PUT);
 mybar(170,88,220,100);
 getch();
 mybar(170,88,220,100);
 mybar(170,105,220,117);
 getch();
 mybar(170,105,220,117);
 setwritemode(COPY_PUT);
 getch();
 putimage(161,80,p,COPY_PUT);
}
void Lcd(int x,int y,int n)
{
 int a,b;
 if(n<10)
 {
 LCD(x,y,0);
 LCD(x+15,y,n);
 }
 else if(n<100)
 {
  a=n/10;b=n%10;
  LCD(x,y,a);
  LCD(x+15,y,b);
 }
}
void LCD(int left,int top,int NUM)
{
   int i;
//   int right=100, bottom=100;
   setcolor(10);

   switch(NUM)
   {
   case 1:
	  line(left+11,top+2,left+11,top+9);	//  |
	  line(left+11,top+11,left+11,top+18);	//  |
	  break;
   case 2:
	   line(left,top,left+10,top);		//--
	   line(left+11,top+2,left+11,top+9);	//  |
	   line(left+1,top+10,left+9,top+10);	//--
	   line(left-1,top+11,left-1,top+18);	//|
	   line(left,top+20,left+10,top+20);	//--
	   break;
   case 3:
	   line(left,top,left+10,top);		//--
	   line(left+11,top+2,left+11,top+9);	//  |
	   line(left+1,top+10,left+9,top+10);	//--
	   line(left+11,top+11,left+11,top+18);	//  |
	   line(left,top+20,left+10,top+20);	//--
	   break;
   case 4:
	   line(left-1,top+2,left-1,top+9);	//|
	   line(left+11,top+2,left+11,top+9);	//  |
	   line(left+1,top+10,left+9,top+10);	//--
	   line(left+11,top+11,left+11,top+18);	//  |
	   break;
   case 5:
	   line(left,top,left+10,top);		//--
	   line(left-1,top+2,left-1,top+9);	//|
	   line(left+1,top+10,left+9,top+10);	//--
	   line(left+11,top+11,left+11,top+18);	//  |
	   line(left,top+20,left+10,top+20);	//--
	   break;
   case 6:
	   line(left,top,left+10,top);		//--
	   line(left-1,top+2,left-1,top+9);	//|
	   line(left+1,top+10,left+9,top+10);	//--
	   line(left-1,top+11,left-1,top+18);	//|
	   line(left+11,top+11,left+11,top+18);	//  |
	   line(left,top+20,left+10,top+20);	//--
	   break;
   case 7:
	   line(left,top,left+10,top);		//--
	   line(left-1,top+2,left-1,top+9);	//|
	   line(left+11,top+2,left+11,top+9);	//  |
	   line(left+11,top+11,left+11,top+18);	//  |
	   break;
   case 8:
	   line(left,top,left+10,top);		//--
	   line(left-1,top+2,left-1,top+9);	//|
	   line(left+11,top+2,left+11,top+9);	//  |
	   line(left+1,top+10,left+9,top+10);	//--
	   line(left-1,top+11,left-1,top+18);	//|
	   line(left+11,top+11,left+11,top+18);	//  |
	   line(left,top+20,left+10,top+20);	//--
	   break;
   case 9:
	   line(left,top,left+10,top);		//--
	   line(left-1,top+2,left-1,top+9);	//|
	   line(left+11,top+2,left+11,top+9);	//  |
	   line(left+1,top+10,left+9,top+10);	//--
	   line(left+11,top+11,left+11,top+18);	//  |
	   line(left,top+20,left+10,top+20);	//--
	   break;
   case 0:
	   line(left,top,left+10,top);		//--
	   line(left-1,top+2,left-1,top+9);	//|
	   line(left+11,top+2,left+11,top+9);	//  |
	   line(left-1,top+11,left-1,top+18);	//|
	   line(left+11,top+11,left+11,top+18);	//  |
	   line(left,top+20,left+10,top+20);	//--
	   break;
   }
}
int load_game()
{
	FILE *fp ;
	char *name;
	gotoxy(20,2);printf("File name: ");
	scanf("%s",name);
	if ( ( fp = fopen ( name, "rb" ) ) == NULL )
	{
	  setfillstyle(1,3);
	  bar(20,17,400,40);
	  gotoxy(20,2);
	  printf("  Unable to Load Game");
	  getch();
	  setfillstyle(1,3);
	  bar(20,17,400,40);
	  return 0;
	}
	fread(board,sizeof(board),1,fp);
	fclose ( fp ) ;
	setfillstyle(1,3);
	bar(20,17,400,40);
	DrawBoard();
	return 1;
}
int save_game()
{
	char *fname;
	FILE *fp ;
	gotoxy(20,2);printf("File name: ");
	scanf("%s",fname);
	if ( ( fp = fopen ( fname, "wb" ) ) == NULL ) return 0;
	fwrite(board, sizeof ( board ), 1, fp);
	fclose(fp) ;
	setfillstyle(1,3);
	bar(20,17,400,40);
	return 1;
}
