   //-----------------------------------------------------------------//

			       /* SNAKE GAME */

   //---------------------------------------------------------------------//

#include<fstream.h>
#include<conio.h>
#include<graphics.h>
#include<iostream.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<iomanip.h>

int lin=0,line_thick=0,dot=0,line_col=1,home_chk=0,home=0,chk_def_ch=0,ckibar=0,food_col=10,gametime=300,ext=0,pause=0,pscore=0,wrong=0,rdm=0,ckbar=0,br_col=7,sn_col=15,bk_col=0,dif=0,final_score=0,fail=0,cheat=0,speed=70,game_time=0,tim=0,sctime=0,tm=0,run=0,p1=0,q1=0,r1=0,s1=0,size=0,hin,end=0,maxx,maxy,sz=0,ckbarx1[300],ckbarx2[300],ckbary2[300],ckbary1[300],p=0,a=0,level=2,b=0,c=0,d=0,z=0,checkfood=0,x,y,food=1,k=0,sizear=19,i,x1,y1,x2,y2,ar[1000];
char check,str[10],str1[10],str_aux[10],str_time[50]="TIME : ",str_time1[50]="TIME : ",strtm3[50],cheat1[30]="wor",cheat2[30]="iam",cheat3[30]="belowthishell",cheat4[30]="bedecent";

class snake
{
  int z;
  public :
  void score();
  void insert();
  void checkmotion();
  void checkend();
  void setscreen();
  void makebars();
  void motionr();
  void motiont();
  void motionl();
  void makesnake();
  void motiond();
  void makelines();
  void level_clear();
  void calc_time();
  void check_win();
  void beautify();
  void game_save();
  void load();
  void count();
  void fac();
  void help();
}s;

//-----------------------------------------------------//

  int sa_score,p_level,l_level,t_fail,t_cheat;
  char play_name[50],form[50];

 //----------------------------------------------------//

void snake ::game_save()
  {
    sa_score=0;
    p_level=0;
    l_level=0;
    t_fail=0;
    t_cheat=0;
    //form=" AUTOSAVE COMPLETE ";
    sa_score=final_score;
    p_level=level;
    l_level=10-level;
    t_fail=fail;
    t_cheat=cheat;
    fstream f;
    /*f.open("SAVE FILES");
    f<<sa_score<<" ";
    f<< p_level<<" ";
    f<<t_fail<<" ";
    f<<t_cheat<<" ";   */
    f.open("SAVE FILES ",ios::in);
    f.write((char *) &this,(sizeof (snake)));
    f.close();
    //outtextxy(getmaxx/2-30,250,form);
  }

//----------------------------------------------------//

void rndom()
{
 //time_t th;
 long f;
 //f=(unsigned)th.gettime();
 time_t t;
 srand((unsigned) time(&t));
 srand(f);
}

//------------------------------------------------------//

void snake::setscreen()
{
  while(maxx%15!=0||maxy%15!=0)
  {
   if(maxx%15!=0)
    maxx=maxx-1;
   if(maxy%15!=0)
    maxy=maxy-1;
  }
  maxy=maxy-15;
}

//---------------------------------------------------------//

void checkpos()
{
  if(food==1)
    {  l:k=rand()%50;
       p=rand()%50;
       i=10;
       food_col=food_col;
      if((15+k*p*15)>=maxx||15+k*p*15>=maxy)
      goto l;
      if((15+k*p*15)<=0)
      goto l;
      if((15+k*p*15)==a||(15+k*p*15)==b||(30+k*p*15)==c||(30+k*p*15)==d)
      goto l;
      a=k*p*15+15;
      b=k*p*15+15;
      c=k*p*15+30;
      d=k*p*15+30;
      for(k=0;k<sizear;k++)
      {
       if(k%2==0)
       if(ar[k]==a||ar[k]==c)
       if(ar[k+1]==b||ar[k+1]==d)
       if(ar[k+2]==c||ar[k+2]==a)
       if(ar[k+3]==d||ar[k+3]==b)
       goto l;
      }
      for(k=0;k<=size;k++)
      {
	if(ckbarx1[k]==a||ckbarx1[k]==c||ckbary1[k]==b||ckbary1[k]==d)
	if(ckbary1[k+1]==b||ckbary1[k+1]==d||ckbarx2[k+1]==a||ckbarx2[k+1]==c)
	if(ckbarx2[k+2]==a||ckbarx2[k+2]==c||ckbary1[k+2]==b||ckbary1[k+2]==d)
	if(ckbary2[k+3]==b||ckbary2[k+3]==d||ckbarx2[k+3]==a||ckbarx2[k+3]==c)
	goto l;
      }
      setfillstyle(SOLID_FILL,food_col);
      //bar(15+k*p*15,15+p*k*15,30+k*p*15,30+p*k*15);
      if(home)
      bar3d(a,b,c,d,5,1);
      else
      bar(a,b,c,d);
      /*a=k*p*15+15;
      b=k*p*15+15;
      c=k*p*15+30;
      d=k*p*15+30;*/
      food=0;
    }
    if(ar[sizear-4]==a&&ar[sizear-3]==b&&ar[sizear-2]==c&&ar[sizear-1]==d)
    {
      food=1;
      checkfood=1;
      setfillstyle(SOLID_FILL,sn_col);
      if(home)
      bar3d(a,b,c,d,5,1);
      else
      bar(a,b,c,d);
      run=run+10;
      final_score=final_score+10;
      if(chk_def_ch)
      ckibar=1;
      if(!chk_def_ch)
      ckibar=0;
      //final_score=run;
    }
    setfillstyle(SOLID_FILL,0);
    if(home)
      bar3d(ar[0],ar[1],ar[2],ar[3],5,9);
    else
    {
      bar(ar[0],ar[1],ar[2],ar[3]);
      /*setcolor(bk_col);
      setlinestyle(SOLID_LINE,3,3);
      line(ar[0],ar[1],ar[2],ar[1]);
      line(ar[0],ar[3],ar[2],ar[3]);
      line(ar[0],ar[1],ar[0],ar[3]);
      line(ar[2],ar[1],ar[2],ar[1]);*/
    }
  }

//----------------------------------------------------//

void snake::score()
{
  setcolor(1);
  settextstyle(8,HORIZ_DIR,3);
  outtextxy(5,getmaxy()-30,"SCORE : ");
  itoa(run, str, 10);
  //strcpy(str1,str);
  //setcolor(2);
  if((strcmpi(str1,str))==0)
  outtextxy(100,getmaxy()-30,str);
  else
  {
    setcolor(2);
    outtextxy(100,getmaxy()-30,str1);
    setcolor(1);
    outtextxy(100,getmaxy()-30,str);
  }
  strcpy(str1,str);
  /*gotoxy(5,getmaxy()-5);
  cout<<run;*/
}

//-------------------------------------------------------------//

void snake::calc_time()
{
  tim=tim+speed;
  if(tim>=1000)
  {
    setfillstyle(SOLID_FILL,2);
    bar(0,maxy+2,maxx,getmaxy());
    setcolor(15);
    //setlinestyle(SOLID_FILL,1,1);
    line(0,maxy+2,maxx,maxy+2);
    line(0,getmaxy(),maxx,getmaxy());
    line(0,maxy+2,0,getmaxy());
    line(maxx,maxy+2,maxx,getmaxy());
    setcolor(2);
    outtextxy(getmaxx()-150,getmaxy()-30,strtm3);
    itoa(game_time,str_aux,10);
    strcat(str_time,str_aux);
    //strcat(strtm3,str_time);
    setcolor(1);
    outtextxy(getmaxx()-150,getmaxy()-30,str_time);
    strcpy(strtm3,str_time);
    tim=0;
    game_time++;
    strcpy(str_time,str_time1);
  }
}

//--------------------------------------------//


void snake::check_win()
{
  char str_sh[15]="LEVEL : ",str_ax[10],str1[30]="! ! CONGRATULATIONS ! !",str_l[30]="LEVEL CLEARED",str_l1[30]="LEVEL : ";
  int l;
  level++;
  l=level;
  cleardevice();
  beautify();
  itoa(level,str_ax,10);
  //strcat(str_l,str_ax);
  setcolor(15);
  strcat(str_sh,str_ax);
  settextstyle(1,HORIZ_DIR,2);
  outtextxy(200,getmaxy()/2-70,str1);
  outtextxy(220,getmaxy()/2-30,str_l);
  delay(1000);
  cleardevice();
  beautify();
  settextstyle(10,HORIZ_DIR,2);
  outtextxy(200,getmaxy()/2-70,str_sh);
  /*char dj=0;
  while(dj!=13&&dj!=27)
  {
   dj=getch();
  }
  if(dj==27)
  goto start_game; */
  settextstyle(1,HORIZ_DIR,2);
  delay(2000);
  cleardevice();
  count();
  delay(500);
}

//--------------------------------------------------//

void snake::count()
{
   char st1[2]="1",st2[2]="2",st3[3]="3",str_l2[20]=" ARE YOU READY ? ";
   int iz=0;
    setcolor(15);
    settextstyle(8,HORIZ_DIR,3);
    outtextxy(150,getmaxy()/2-30,str_l2);
    outtextxy(250+iz*30,getmaxy()/2-5,st1);
    delay(500);
    iz++;
    outtextxy(250+iz*30,getmaxy()/2-5,st2);
    delay(500);
    iz++;
    outtextxy(250+iz*30,getmaxy()/2-5,st3);
    delay(500);
    cleardevice();
}

//-----------------------------------------------//

void snake::beautify()
{
  setfillstyle(SOLID_FILL,4);
  bar(0,0,getmaxx(),20);
  bar(0,20,20,getmaxy());
  bar(20,getmaxy()-20,getmaxx(),getmaxy());
  bar(getmaxx()-20,20,getmaxx(),getmaxy()-20);
  setfillstyle(SOLID_FILL,8);
  bar(25,25,getmaxx()-25,30);
  bar(25,25,30,getmaxy()-25);
  bar(25,getmaxy()-25,getmaxx()-25,getmaxy()-30);
  bar(getmaxx()-30,25,getmaxx()-25,getmaxy()-25);
}

//---------------------------------------------------//

void grow()
{
   sizear=sizear+4;
      for(k=sizear;k>=0;k--)
      {
	if(k>=4)
	ar[k]=ar[k-4];
	else if(k%2==0)
	ar[k]=ar[k]-15;
	else
	ar[k]=ar[k];
      }
}

//------------------------------------------------------//

void snake::makelines()
{
  setcolor(br_col);
  setlinestyle(SOLID_LINE,1,1);
  line(0,0,maxx,0);
  line(0,maxy,maxx,maxy);
  line(0,0,0,maxy);
  line(maxx,0,maxx,maxy);
}
void snake::insert()
{
  ckbarx1[size]=p1;
  ckbary1[size]=q1;
  ckbarx2[size]=r1;
  ckbary2[size]=s1;
  size=size+1;
}

//----------------------------------------------------//

void rdm_col()
{
  if(br_col==100)
  {
    br_col=rand()%15;
    if(br_col!=bk_col)
      setfillstyle(SOLID_FILL,br_col);
  }
}
void snake:: makebars()
{
  int setbars=0;
  size=0;
  if(br_col!=100)
    setfillstyle(SOLID_FILL,br_col);
  if(level==2)
  {
    for(hin=60;hin<maxx-60;hin=hin+15)
    {
      rdm_col();
      bar(hin,195,hin+15,210);
      p1=hin;
      q1=195;
      r1=hin+15;
      s1=210;
      ckbarx1[size]=hin-15;
      ckbary1[size]=195;
      ckbarx1[size]=hin+15;
      ckbary1[size]=195+15;
      size++;
      insert();
    }
  }
  if(level==3)
  {
    for(hin=0;hin<255;hin=hin+15)
    {
    rdm_col();
    setbars++;
    if(setbars!=1)
    {
      bar(hin,maxy-165,hin+15,maxy-150);
      p1=hin;
      q1=maxy-165;
      r1=hin+15;
      s1=maxy-150;
      ckbarx1[size]=hin-15;
      ckbary1[size]=q1;
      ckbarx1[size]=hin;
      ckbary1[size]=s1;
      size++;
      insert();
    }
    }
    setbars=0;
    for(hin=maxx;hin>=maxx-240;hin=hin-15)
    {
     rdm_col();
     setbars++;
     if(setbars!=1)
     {
      bar(hin,165,hin-15,180);
      p1=hin;
      q1=165;
      r1=hin-15;
      s1=180;
      insert();
     }
    }
    size++;
    ckbarx1[size]=r1+15;
    ckbary1[size]=q1;
    ckbarx1[size]=r1+30;
    ckbary1[size]=s1;
  }
  if(level==4)
  {
     for(hin=15;hin<255;hin=hin+15)
    {
      rdm_col();
      bar(hin,maxy-165,hin+15,maxy-150);
      p1=hin;
      q1=maxy-165;
      r1=hin+15;
      s1=maxy-150;
      ckbarx1[size]=p1-15;
      ckbary1[size]=q1;
      ckbarx1[size]=r1-15;
      ckbary1[size]=s1;
      size++;
      insert();
    }
    for(hin=maxx;hin>=maxx-240;hin=hin-15)
    {
     rdm_col();
     setbars++;
     if(setbars!=1)
     {
      bar(hin,164,hin-15,180);
      p1=hin;
      q1=165;
      r1=hin-15;
      s1=180;
      insert();
     }
    }
  for(hin=0;hin<=150;hin=hin+15)
  {
  rdm_col();
   bar(180,hin,180-15,hin+15);
    p1=180;
    q1=hin;
    r1=180-15;
    s1=hin+15;
    insert();
   }
   setbars=0;
   for(hin=maxy;hin>=maxy-165;hin=hin-15)
   {
      rdm_col();
   setbars++;
    if(setbars!=1)
    {
     bar(maxx-180,hin,maxx-180-15,hin+15);
     p1=maxx-180;
     q1=hin;
     r1=maxx-180-15;
     s1=hin+15;
     insert();
     }
   }
   }
   if(level==5)
   {
    size=0;
    for(hin=105;hin<=maxx-135;hin=hin+15)
    {
      rdm_col();
     bar(hin,105,hin+15,120);
     p1=hin;
     q1=105;
     r1=hin+15;
     s1=120;
     insert();
    }
    /*setfillstyle(SOLID_FILL,9);
    bar(105,150,120,165);*/
    setfillstyle(SOLID_FILL,br_col);
    for(hin=105;hin<=maxy-105;hin=hin+15)
    {
      rdm_col();
     bar(105,hin,120,hin+15);
     p1=105;
     q1=hin;
     r1=120;
     s1=hin+15;
     insert();
    }
    bar(135,maxy-105,150,maxy-90);
    for(hin=150;hin<=maxx-105;hin=hin+15)
    {
      rdm_col();
     bar(hin,maxy-105,hin+15,maxy-90);
     p1=hin;
     q1=maxy-105;
     r1=hin;
     s1=maxy-90;
     insert();
    }
    for(hin=maxy-105;hin>=105;hin=hin-15)
    {
      rdm_col();
     bar(maxx-105,hin,maxx-90,hin+15);
     p1=maxx-105;
     q1=hin;
     r1=maxx-90;
     s1=hin+15;
     insert();
    }
   }
   if(level==6)
   {
    size=0;
    setbars=0;
    for(hin=45;hin<maxx-60;hin=hin+15)
    {
      rdm_col();
     setbars++;
     if(setbars!=1)
     {
     bar(hin,105,hin+15,120);
     p1=hin;
     q1=105;
     r1=hin+15;
     s1=120;
     ckbarx1[size]=p1-15;
     ckbary1[size]=q1;
     ckbarx1[size]=r1-15;
     ckbary1[size]=s1;
     size++;
     insert();
     }
    }
    /*setfillstyle(SOLID_FILL,0);
    bar(ckbarx1[0],ckbary1[0],ckbarx2[0],ckbary2[0]);
    setfillstyle(SOLID_FILL,7);*/
    for(hin=60;hin<maxx-60;hin=hin+15)
    {
     rdm_col();
     bar(hin,maxy-105,hin+15,maxy-120);
     p1=hin;
     q1=maxy-105;
     r1=hin+15;
     s1=maxy-120;
     insert();
    }
    for(hin=105;hin>=45;hin=hin-15)
    {
     rdm_col();
     bar(105,hin,120,hin+15);
     p1=105;
     q1=hin;
     r1=120;
     s1=hin+15;
     insert();
    }
    for(hin=105;hin>=45;hin=hin-15)
    {
     rdm_col();
     bar(maxx-105,hin,maxx-120,hin+15);
     p1=maxx-105;
     q1=hin;
     r1=maxx-120;
     s1=hin+15;
     insert();
    }
    for(hin=maxy-105;hin<=maxy-45;hin=hin+15)
    {
    rdm_col();
     bar(105,hin,120,hin+15);
     p1=105;
     q1=hin;
     r1=120;
     s1=hin+15;
     insert();
    }
    for(hin=maxy-105;hin<=maxy-45;hin=hin+15)
    {
      rdm_col();
     bar(maxx-105,hin,maxx-120,hin+15);
     p1=maxx-105;
     q1=hin;
     r1=maxx-120;
     s1=hin+15;
     insert();
    }
   }
   if(level==7)
   {
    size=0;
    setbars=0;
    for(hin=45;hin<maxx-60;hin=hin+15)
    {
    rdm_col();
     setbars++;
     if(setbars!=1)
     {
     bar(hin,105,hin+15,120);
     p1=hin;
     q1=105;
     r1=hin+15;
     s1=120;
     insert();
     }
    }
    /*setfillstyle(SOLID_FILL,0);
    bar(ckbarx1[0],ckbary1[0],ckbarx2[0],ckbary2[0]);
    setfillstyle(SOLID_FILL,7);*/
    for(hin=60;hin<maxx-60;hin=hin+15)
    {
    rdm_col();
     bar(hin,maxy-105,hin+15,maxy-120);
     p1=hin;
     q1=maxy-105;
     r1=hin+15;
     s1=maxy-120;
     insert();
    }
    for(hin=105;hin>=15;hin=hin-15)
    {
     rdm_col();
     bar(60,hin,75,hin+15);
     p1=60;
     q1=hin;
     r1=75;
     s1=hin+15;
     insert();
    }
    for(hin=105;hin>=15;hin=hin-15)
    {
    rdm_col();
     bar(maxx-60,hin,maxx-75,hin+15);
     p1=maxx-60;
     q1=hin;
     r1=maxx-75;
     s1=hin+15;
     insert();
    }
    for(hin=maxy-105;hin<=maxy-30;hin=hin+15)
    {
     rdm_col();
     bar(60,hin,75,hin+15);
     p1=60;
     q1=hin;
     r1=75;
     s1=hin+15;
     insert();
    }
    for(hin=maxy-105;hin<=maxy-30;hin=hin+15)
    {
    rdm_col();
     bar(maxx-60,hin,maxx-75,hin+15);
     p1=maxx-60;
     q1=hin;
     r1=maxx-75;
     s1=hin+15;
     insert();
    }
   }
  if(level==8)
  {
    size=0;
    setbars=0;
    for(hin=45;hin<maxx-60;hin=hin+15)
    {
     rdm_col();
     setbars++;
     if(setbars!=1)
     {
     bar(hin,60,hin+15,75);
     p1=hin;
     q1=60;
     r1=hin+15;
     s1=75;
     insert();
     }
    }
    setbars=0;
    for(hin=60;hin<maxy-75;hin=hin+15)
    {
     rdm_col();
     setbars++;
     if(setbars!=1)
     {
     bar(60,hin,75,hin+15);
     p1=60;
     q1=hin;
     r1=75;
     s1=hin+15;
     insert();
     }
    }
    setbars=0;
     for(hin=60;hin<maxy-75;hin=hin+15)
     {
      rdm_col();
      setbars++;
      if(setbars!=1)
      {
      bar(maxx-60,hin,maxx-75,hin+15);
      p1=maxx-60;
      q1=hin;
      r1=maxx-75;
      s1=hin+15;
      insert();
      }
     }
     setbars=0;
    for(hin=45;hin<maxx-105;hin=hin+15)
    {
    rdm_col();
     setbars++;
     if(setbars!=1)
     {
     bar(hin,maxy-60,hin+15,maxy-75);
     p1=hin;
     q1=maxy-60;
     r1=hin+15;
     s1=maxy-75;
     insert();
     }
    }
     setbars=0;
    for(hin=15;hin<150;hin=hin+15)
    {
    rdm_col();
     setbars++;
     if(setbars!=1)
     {
     bar(hin,30,hin+15,45);
     p1=hin;
     q1=30;
     r1=hin+15;
     s1=45;
     insert();
     }
    }
    setbars=0;
    setbars=0;
    for(hin=15;hin<150;hin=hin+15)
    {
     rdm_col();
     setbars++;
     if(setbars!=1)
     {
     bar(30,hin,45,hin+15);
     p1=30;
     q1=hin;
     r1=45;
     s1=hin+15;
     insert();
     }
    }
    setbars=0;
    for(hin=maxx-30;hin>maxx-175;hin=hin-15)
    {
    rdm_col();
     setbars++;
     if(setbars!=1)
     {
     bar(hin,30,hin+15,45);
     p1=hin;
     q1=30;
     r1=hin+15;
     s1=45;
     insert();
     }
    }
     setbars=0;
    for(hin=maxy-30;hin>maxy-175;hin=hin-15)
    {
     rdm_col();
     setbars++;
     if(setbars!=1)
     {
     bar(30,hin,45,hin+15);
     p1=30;
     q1=hin;
     r1=45;
     s1=hin+15;
     insert();
     }
    }
     setbars=0;
     for(hin=15;hin<150;hin=hin+15)
     {
      rdm_col();
      setbars++;
      if(setbars!=1)
      {
      bar(hin,maxy-30,hin+15,maxy-45);
      p1=hin;
      q1=maxy-30;
      r1=hin+15;
      s1=maxy-45;
      insert();
      }
     }
     setbars=0;
     for(hin=15;hin<150;hin=hin+15)
     {
     rdm_col();
      setbars++;
      if(setbars!=1)
      {
      bar(maxx-30,hin,maxx-45,hin+15);
      p1=maxx-30;
      q1=hin;
      r1=maxx-45;
      s1=hin+15;
      insert();
      }
     }
     setbars=0;
     for(hin=maxx-30;hin>maxx-175;hin=hin-15)
     {
     rdm_col();
      setbars++;
      if(setbars!=1)
      {
      bar(hin,maxy-30,hin+15,maxy-45);
      p1=hin;
      q1=maxy-30;
      r1=hin+15;
      s1=maxy-45;
      insert();
     }
    }
     for(hin=maxy-30;hin>maxy-175;hin=hin-15)
     {
     rdm_col();
      setbars++;
      if(setbars!=1)
      {
      bar(maxx-30,hin,maxx-45,hin-15);
      p1=maxx-30;
      q1=hin;
      r1=maxx-45;
      s1=hin-15;
      insert();
     }
    }
   }
   if(level==9)
  {
    size=0;
    setbars=0;
    for(hin=15;hin<maxx-15;hin=hin+15)
    {
      rdm_col();
      bar(hin,maxy-165,hin+15,maxy-150);
      p1=hin;
      q1=maxy-165;
      r1=hin+15;
      s1=maxy-150;
      ckbarx1[size]=p1-15;
      ckbary1[size]=q1;
      ckbarx1[size]=r1-15;
      ckbary1[size]=s1;
      size++;
      insert();
    }
    /*setfillstyle(SOLID_FILL,0);
    bar(0,maxy-165,15,maxy-150); */
    setfillstyle(SOLID_FILL,br_col);
    setbars=0;
    for(hin=maxx;hin>=30;hin=hin-15)
    {
     setbars++;
     if(setbars!=1)
     {
      bar(hin,164,hin-15,180);
      p1=hin;
      q1=165;
      r1=hin-15;
      s1=180;
      insert();
     }
    }
  for(hin=0;hin<=150;hin=hin+15)
  {
   rdm_col();
   bar(180,hin,180-15,hin+15);
    p1=180;
    q1=hin;
    r1=180-15;
    s1=hin+15;
    insert();
   }
   setbars=0;
   for(hin=maxy;hin>=maxy-165;hin=hin-15)
   {
   rdm_col();
   setbars++;
    if(setbars!=1)
    {
     bar(maxx-180,hin,maxx-180-15,hin+15);
     p1=maxx-180;
     q1=hin;
     r1=maxx-180-15;
     s1=hin+15;
     insert();
     }
   }
   }
   if(level==10)
   {
    size=0;
    setbars=0;
   }
   if(level==10)
   {
     for(hin=15;hin<maxx-45;hin=hin+15)
     {
       rdm_col();
       setbars++;
       if(setbars!=1)
       {
	 bar(hin,165,hin+15,180);
	 p1=hin;
	 q1=150;
	 r1=hin+15;
	 s1=165;
	insert();
       }
     }
     setbars=0;
     for(hin=15;hin<maxx-45;hin=hin+15)
     {
       rdm_col();
       setbars++;
       if(setbars==1)
       {
	setfillstyle(SOLID_FILL,0);
	bar(hin,maxy-150,hin+15,maxy-165);
	setfillstyle(SOLID_FILL,br_col);
       }
       if(setbars!=1)
       {
	 bar(hin,maxy-165,hin+15,maxy-180);
	 p1=hin;
	 q1=maxy-165;
	 r1=hin+15;
	 s1=maxy-180;
	insert();
       }
     }
     for(hin=60;hin<maxx-75;hin=hin+15)
     {
       rdm_col();
       setbars++;
       if(setbars==1)
       {
	setfillstyle(SOLID_FILL,0);
	bar(hin,maxy-75,hin+15,maxy-90);
	setfillstyle(SOLID_FILL,br_col);
       }
       if(setbars!=1)
       {
	 bar(hin,maxy-75,hin+15,maxy-90);
	 p1=hin;
	 q1=maxy-75;
	 r1=hin+15;
	 s1=maxy-90;
	insert();
       }
     }
     for(hin=60;hin<maxx-75;hin=hin+15)
     {
       rdm_col();
       setbars++;
       if(setbars==1)
       {
	setfillstyle(SOLID_FILL,0);
	bar(hin,75,hin+15,90);
	setfillstyle(SOLID_FILL,7);
       }
       if(setbars!=1)
       {
	 bar(hin,75,hin+15,90);
	 p1=hin;
	 q1=75;
	 r1=hin+15;
	 s1=90;
	insert();
       }
     }
    for(hin=15;hin<=165;hin=hin+15)
    {
      rdm_col();
      setbars++;
      if(setbars!=1)
      {
	bar(maxx-45,hin,maxx-60,hin+15);
	p1=maxx-45;
	q1=hin;
	r1=maxx-60;
	s1=hin+15;
	insert();
      }
    }
    for(hin=maxy-30;hin>=maxy-165;hin=hin-15)
    {
      rdm_col();
      setbars++;
      if(setbars!=1)
      {
	bar(30,hin,45,hin+15);
	p1=30;
	q1=hin;
	r1=45;
	s1=hin+15;
	insert();
      }
    }
    for(hin=15;hin<=165;hin=hin+15)
    {
      rdm_col();
      setbars++;
      if(setbars!=1)
      {
	bar(30,hin,45,hin+15);
	p1=30;
	q1=hin;
	r1=45;
	s1=hin+15;
	insert();
      }
    }
    for(hin=maxy-30;hin>=maxy-165;hin=hin-15)
    {
      rdm_col();
      setbars++;
      if(setbars!=1)
      {
	bar(maxx-45,hin,maxx-60,hin+15);
	p1=maxx-45;
	q1=hin;
	r1=maxx-60;
	s1=hin+15;
	insert();
      }
    }
   }
   if(level>10)
   {
     level=0;
   }
}

//----------------------------------------//

void snake::checkend()
{
  if(!ckibar)
  {
  for(i=0;i<=size;i++)
  {
   if(i!=0)
   if(ckbarx1[i]==ar[sizear-2]||ckbarx1[i]==ar[sizear-4])
   if(ckbary1[i]==ar[sizear-1]||ckbary1[i]==ar[sizear-3])
   if(ckbarx2[i]==ar[sizear-2]||ckbarx2[i]==ar[sizear-4])
   if(ckbary2[i]==ar[sizear-1]||ckbary2[i]==ar[sizear-3])
   end=1;
  }
  }
  gametime=300;
  if(game_time>=gametime)
  {
    if(run<500)
    end=1;
  }
}

//---------------------------------------------//

void snake::makesnake()
{
  i=0;
  y1=180;
  setfillstyle(SOLID_FILL,sn_col);
  for(x1=150;x1<=300;x1=x1+15)
  {
  x2=x1+15;
  y2=y1+15;
    bar(x1,y1,x2,y2);
    ar[i]=x1;
    i++;
    ar[i]=y1;
    i++;
    ar[i]=x2;
    i++;
    ar[i]=y2;
    i++;
  }
  sizear=i;
}

//-------------------------------------------------------------//

void snake::motionr()    //function of right motion
{  int prr=0;
   while(1)
   {
    if(ar[sizear-2]>maxx)
    {
      end=1;
      break;
    }
    checkpos();
    checkend();
    if(prr)
     {
      if(kbhit())
      break;
     }
    for(k=0;k<=sizear;k++)
    {
    if(k<sizear-4)
    ar[k]=ar[k+4];
    else if(k%2==0)
    ar[k]=ar[k]+15;
    else
    ar[k]=ar[k];
    }
    if(checkfood==1)
    grow();
     for(k=0;k<=sizear-4;k++)
     {
       if(k%2==0&&k%4!=0)
       {
       if(ar[sizear-1]==ar[k+1]&&ar[sizear-2]==ar[k])
       /*if(ar[sizear-2]==ar[k]||ar[sizear-2]==ar[k+2])
       if(ar[sizear-1]=ar[k+1]||ar[sizear-1]==ar[k+3])
       if(ar[sizear-4]==ar[k]||ar[sizear-4]==ar[k+2])
       if(ar[sizear-3]=ar[k+1]||ar[sizear-3]==ar[k+3])*/
       {
	 end=1;
	 break;
       }
       }
     }
     if(rdm)
     {
      sn_col=rand()%15;
      if(sn_col==bk_col)
      sn_col=12;
     }
     setfillstyle(SOLID_FILL,sn_col);
     bar(ar[0]+15,ar[1],ar[2],ar[3]);
    setfillstyle(SOLID_FILL,sn_col);
    if(home)
    bar3d(ar[sizear-4],ar[sizear-3],ar[sizear-2],ar[sizear-1],5,1);
    else
    {
      bar(ar[sizear-4],ar[sizear-3],ar[sizear-2],ar[sizear-1]);
      setcolor(line_col);
      if(lin%2==0)
      {
      if(line_thick%2==0)
      {
      setlinestyle(SOLID_LINE,3,3);
      line(ar[sizear-4],ar[sizear-3]+1,ar[sizear-2]-1,ar[sizear-3]+1);
      line(ar[sizear-4],ar[sizear-1]-1,ar[sizear-2]-1,ar[sizear-1]-1);
      line(ar[sizear-4]+15-1,ar[sizear-3],ar[sizear-4]+15-1,ar[sizear-1]);
      line(ar[sizear-4],ar[sizear-3]+1,ar[sizear-4],ar[sizear-1]-1);
      }
      else
      {
      setlinestyle(SOLID_LINE,3,1);
      line(ar[sizear-4],ar[sizear-3],ar[sizear-2],ar[sizear-3]);
      line(ar[sizear-4],ar[sizear-1],ar[sizear-2],ar[sizear-1]);
      line(ar[sizear-4],ar[sizear-3],ar[sizear-4],ar[sizear-1]);
      line(ar[sizear-4]-15,ar[sizear-3],ar[sizear-4]-15,ar[sizear-1]);
      }
      }
      if(dot%2==0)
      {
	setfillstyle(SOLID_FILL,0);
	bar(ar[sizear-4]-0.5,ar[sizear-3],ar[sizear-4]+0.5,ar[sizear-3]+1);
	bar(ar[sizear-4]-0.5,ar[sizear-1],ar[sizear-4]+0.5,ar[sizear-1]-1);
	bar(ar[sizear-4]+14.5,ar[sizear-3],ar[sizear-4]+15.5,ar[sizear-3]+1);
	bar(ar[sizear-4]+14.5,ar[sizear-1],ar[sizear-4]+15.5,ar[sizear-1]-1);
      }
    }
    /*if(line_thick%2==0)
    {
      setfillstyle(SOLID_FILL,0);
      bar(ar[0]-1,ar[1]-1,ar[2]+1,ar[3]+1);
    } */
    checkfood=0;
     if(end)
     break;
     /*if(game_time>=300)
     break; */
     makebars();
     makelines();
     score();
     calc_time();
     fac();
     setbkcolor(bk_col);
     prr++;
    delay(speed);
  }
  prr=0;
}

//-----------------------------------------------------//

void snake::motionl()
{
   int prl=0;
   while(1)
   {
    if(ar[sizear-2]<0)
    {
      end=1;
      break;
    }
    checkpos();
    checkend();
    if(prl)
     {
      if(kbhit())
      break;
     }
    for(k=0;k<=sizear;k++)
    {
    if(k<sizear-4)
    ar[k]=ar[k+4];
    else if(k%2==0)
    ar[k]=ar[k]-15;
    else
    ar[k]=ar[k];
    }
    if(checkfood==1)
    grow();
    for(k=0;k<=sizear-4;k++)
     {
       if(k%2==0&&k%4!=0)
       {
       if(ar[sizear-1]==ar[k+1]&&ar[sizear-2]==ar[k])
       /*if(ar[sizear-2]==ar[k]||ar[sizear-2]==ar[k+2])
       if(ar[sizear-1]=ar[k+1]||ar[sizear-1]==ar[k+3])
       if(ar[sizear-4]==ar[k]||ar[sizear-4]==ar[k+2])
       if(ar[sizear-3]=ar[k+1]||ar[sizear-3]==ar[k+3]) */
	{
	 end=1;
	 break;
       }
       }
     }
     if(rdm)
     {
      sn_col=rand()%15;
      if(sn_col==bk_col)
      sn_col=12;
     }
    setfillstyle(SOLID_FILL,sn_col);
    if(home)
    bar3d(ar[sizear-4],ar[sizear-3],ar[sizear-2],ar[sizear-1],5,1);
    else
    {
      bar(ar[sizear-4],ar[sizear-3],ar[sizear-2],ar[sizear-1]);
      setcolor(line_col);
      if(lin%2==0)
      {
      if(line_thick%2==0)
      {
      setlinestyle(SOLID_LINE,3,3);
      line(ar[sizear-4],ar[sizear-3]+1,ar[sizear-2]-1,ar[sizear-3]+1);
      line(ar[sizear-4],ar[sizear-1]-1,ar[sizear-2]-1,ar[sizear-1]-1);
      line(ar[sizear-4]+1,ar[sizear-3]+1,ar[sizear-4]+1,ar[sizear-1]-1);
      line(ar[sizear-4]+15,ar[sizear-3],ar[sizear-4]+15,ar[sizear-1]);
      }
      else
      {
      setlinestyle(SOLID_LINE,3,1);
      line(ar[sizear-4],ar[sizear-3],ar[sizear-2],ar[sizear-3]);
      line(ar[sizear-4],ar[sizear-1],ar[sizear-2],ar[sizear-1]);
      line(ar[sizear-4],ar[sizear-3],ar[sizear-4],ar[sizear-1]);
      line(ar[sizear-4]+15,ar[sizear-3],ar[sizear-4]+15,ar[sizear-1]);
      }
      }
      if(dot%2==0)
      {
	setfillstyle(SOLID_FILL,0);
	bar(ar[sizear-4]+0.5+15,ar[sizear-3],ar[sizear-4]-0.5+15,ar[sizear-3]+1);
	bar(ar[sizear-4]+0.5+15,ar[sizear-1],ar[sizear-4]-0.5+15,ar[sizear-1]-1);
	bar(ar[sizear-4]-14.5+15,ar[sizear-3],ar[sizear-4]-15.5+15,ar[sizear-3]+1);
	bar(ar[sizear-4]-14.5+15,ar[sizear-1],ar[sizear-4]-15.5+15,ar[sizear-1]-1);
      }
    }
    /*if(line_thick%2==0)
    {
      setfillstyle(SOLID_FILL,0);
      bar(ar[0]+1,ar[1]-1,ar[2]+1,ar[3]+1);
    }   */
    checkfood=0;
     if(end)
     break;
     /*if(game_time>=300)
     break; */
     makebars();
     makelines();
     score();
     calc_time();
     fac();
     setbkcolor(bk_col);
     prl++;
     delay(speed);
  }
  prl=0;
}
void snake::motiond()
{
  int prd=0;
  while(1)
  {
    if(ar[sizear-1]>maxy)
    {
      end=1;
      break;
    }
    checkpos();
    checkend();
    if(prd)
     {
      if(kbhit())
      break;
     }
    for(k=0;k<=sizear;k++)
    {
    if(k<sizear-4)
    ar[k]=ar[k+4];
    else if(k%2!=0)
    ar[k]=ar[k]+15;
    else
    ar[k]=ar[k];
    }
    if(checkfood==1)
    grow();
    for(k=0;k<=sizear-4;k++)
     {
       if(k%2==0&&k%4!=0)
       {
       if(ar[sizear-1]==ar[k+1]&&ar[sizear-2]==ar[k])
       {
	 end=1;
	 break;
       }
       }
     }
     if(rdm)
     {
      sn_col=rand()%15;
      if(sn_col==bk_col)
      sn_col=12;
     }
    setfillstyle(SOLID_FILL,sn_col);
    if(home)
    bar3d(ar[sizear-4],ar[sizear-3],ar[sizear-2],ar[sizear-1],5,1);
    else
    {
      bar(ar[sizear-4],ar[sizear-3],ar[sizear-2],ar[sizear-1]);
      setcolor(line_col);
      if(lin%2==0)
      {
      if(line_thick%2==0)
      {
	setlinestyle(SOLID_LINE,3,3);
	line(ar[sizear-4],ar[sizear-3]+1,ar[sizear-4]+15,ar[sizear-3]+1);
	line(ar[sizear-4],ar[sizear-1]-1,ar[sizear-4]+15,ar[sizear-1]-1);
	line(ar[sizear-4]+1,ar[sizear-3]+1,ar[sizear-4]+1,ar[sizear-1]-1);
	line(ar[sizear-2]-1,ar[sizear-3]+1,ar[sizear-2]-1,ar[sizear-1]-1);
      }
      else
      {
      setlinestyle(SOLID_LINE,3,1);
      line(ar[sizear-4],ar[sizear-3],ar[sizear-2],ar[sizear-3]);
      line(ar[sizear-4],ar[sizear-1],ar[sizear-2],ar[sizear-1]);
      line(ar[sizear-4],ar[sizear-3],ar[sizear-4],ar[sizear-1]);
      line(ar[sizear-2],ar[sizear-3],ar[sizear-2],ar[sizear-1]);
      }
      }
      if(dot%2==0)
      {
	setfillstyle(SOLID_FILL,0);
	bar(ar[sizear-4]+14,ar[sizear-3]-0.5,ar[sizear-4]+15,ar[sizear-3]+0.5);
	bar(ar[sizear-4]+14,ar[sizear-1]-1,ar[sizear-4]+15,ar[sizear-1]);
	bar(ar[sizear-4],ar[sizear-3]-0.5,ar[sizear-4]+1,ar[sizear-3]+0.5);
	bar(ar[sizear-4],ar[sizear-1]-1,ar[sizear-4]+1,ar[sizear-1]);
      }
    }
    /*if(line_thick%2==0)
    {
      setfillstyle(SOLID_FILL,0);
      bar(ar[0]-1,ar[1]-1,ar[2]+1,ar[3]+1);
    }*/
    checkfood=0;
     if(end)
     break;
     /*if(game_time>=300)
     break;*/
     makebars();
     makelines();
     score();
     calc_time();
     fac();
     setbkcolor(bk_col);
     prd++;
    delay(speed);
   }
   prd=0;
}
void snake::motiont()  //motion in top
{
    int prt=0;
    while(1)
    {
    if(ar[sizear-1]<0)
    {
      end=1;
      break;
    }
    checkpos();
    checkend();
    if(prt)
     {
      if(kbhit())
      break;
     }
    for(k=0;k<=sizear;k++)
    {
    if(k<sizear-4)
    ar[k]=ar[k+4];
    else if(k%2!=0)
    ar[k]=ar[k]-15;
    else
    ar[k]=ar[k];
    }
    if(checkfood==1)
    grow();
     for(k=0;k<=sizear-4;k++)
     {
       if(k%2==0&&k%4!=0)
       {
       if(ar[sizear-1]==ar[k+1]&&ar[sizear-2]==ar[k])
       /*if(ar[sizear-2]==ar[k]||ar[sizear-2]==ar[k+2])
       if(ar[sizear-1]=ar[k+1]||ar[sizear-1]==ar[k+3])
       if(ar[sizear-4]==ar[k]||ar[sizear-4]==ar[k+2])
       if(ar[sizear-3]=ar[k+1]||ar[sizear-3]==ar[k+3])*/
       {
	 end=1;
	 break;
       }
       }
     }
     if(rdm)
     {
      sn_col=rand()%15;
      if(sn_col==bk_col)
      sn_col=12;
     }
    setfillstyle(SOLID_FILL,sn_col);
    if(home)
      bar3d(ar[sizear-4],ar[sizear-3],ar[sizear-2],ar[sizear-1],5,1);
    else
    {
      bar(ar[sizear-4],ar[sizear-3],ar[sizear-2],ar[sizear-1]);
      setcolor(line_col);
      if(lin%2==0)
      {
      if(line_thick%2==0)
      {
	setlinestyle(SOLID_LINE,3,3);
	line(ar[sizear-4],ar[sizear-3]+1,ar[sizear-4]+15,ar[sizear-3]+1);
	line(ar[sizear-4],ar[sizear-1]-1,ar[sizear-4]+15,ar[sizear-1]-1);
	line(ar[sizear-4]+1,ar[sizear-3],ar[sizear-4]+1,ar[sizear-1]+1);
	line(ar[sizear-2]-1,ar[sizear-3],ar[sizear-2]-1,ar[sizear-1]+1);
      }
      else
      {
      setlinestyle(SOLID_LINE,3,1);
      line(ar[sizear-4],ar[sizear-3],ar[sizear-2],ar[sizear-3]);
      line(ar[sizear-4],ar[sizear-1],ar[sizear-2],ar[sizear-1]);
      line(ar[sizear-4],ar[sizear-3],ar[sizear-4],ar[sizear-1]);
      line(ar[sizear-2],ar[sizear-3],ar[sizear-2],ar[sizear-1]);
      }
      }
      if(dot%2==0)
      {
	setfillstyle(SOLID_FILL,0);
	bar(ar[sizear-4]+14,ar[sizear-3]+0.5,ar[sizear-4]+15,ar[sizear-3]-0.5);
	bar(ar[sizear-4]+14,ar[sizear-1]+1,ar[sizear-4]+15,ar[sizear-1]);
	bar(ar[sizear-4],ar[sizear-3]+0.5,ar[sizear-4]+1,ar[sizear-3]-0.5);
	bar(ar[sizear-4],ar[sizear-1]+1,ar[sizear-4]+1,ar[sizear-1]);
      }
    }
    /*if(line_thick%2==0)
    {
      setfillstyle(SOLID_FILL,0);
      bar(ar[0]-1,ar[1],ar[2]+1,ar[3]+1);
    } */
    checkfood=0;
     if(end)
     break;
     /*if(game_time>=300)
     break;             */
     makebars();
     makelines();
     score();
     calc_time();
     fac();
     setbkcolor(bk_col);
     prt++;
    delay(speed);
  }
  prt=0;
}
void snake::checkmotion()
{
  if(check=='l')
  {
    s.motionl();
    check='l';
  }
   else if(check=='r')
      {
	s.motionr();
	check='r';
      }
   else if(check=='t')
   {
     s.motiont();
     check='t';
   }
   else if(check=='d')
   {
     s.motiond();
     check='d';
   }
  s.makelines();
  s.makebars();
}
void stats()
{
  char stat_scr[5]="     ",stat_lev[5]="     ",stat_ch[5]="     ",stat_fl[5]="    ",stat_lef[5]="     ",stat_reset[10]="      ";
  snake temp;
  temp.beautify();
  settextstyle(4,HORIZ_DIR,5);
  setcolor(4);
  outtextxy(225,75,"STATS");
  settextstyle(1,HORIZ_DIR,2);
  setcolor(15);
  outtextxy(70,140,"LEVELS CLEARED :");
  itoa(level-1,stat_lev,10);
  outtextxy(getmaxx()-150,140,stat_lev);
  outtextxy(70,140+30,"YOUR SCORE :");
  itoa(final_score,stat_scr,10);
  outtextxy(getmaxx()-150,140+30,stat_scr);
  outtextxy(70,140+2*30,"LEVELS LEFT :");
  itoa(11-level,stat_lef,10);
  outtextxy(getmaxx()-150,140+2*30,stat_lef);
  outtextxy(70,140+3*30,"TIMES FAILED :");
  itoa(fail,stat_fl,10);
  outtextxy(getmaxx()-150,140+3*30,stat_fl);
  outtextxy(70,140+4*30,"TIMES CHEATED :");
  itoa(cheat,stat_ch,10);
  outtextxy(getmaxx()-150,140+4*30,stat_ch);
  final_score=0;
  strcpy(stat_lev,stat_reset);
  strcpy(stat_scr,stat_reset);
  strcpy(stat_lef,stat_reset);
  strcpy(stat_ch,stat_reset);
  strcpy(stat_fl,stat_reset);
  char bk;
  while(bk!=27&&bk!=13)
  {
   bk=getch();
  }
}
void snake::load()
{
  ifstream f;
  char info[10],dg;
  snake ty;
  ty.beautify();
  settextstyle(4,HORIZ_DIR,5);
  setcolor(12);
  outtextxy(170,75," SAVED LEVELS");
  /*setcolor(15);
  outtextxy(220,70,"SAVED LEVELS"); */
  settextstyle(1,HORIZ_DIR,2);
  f.open("SAVE FILES");
  if(!f)
  {
   cleardevice();
   ty.beautify();
   setcolor(15);
   settextstyle(4,HORIZ_DIR,2);
   outtextxy(220,70,"!! SORRY !! NO SAVED FILES AVAILABLE");
   delay(1000);
   return;
   exit(0);
  }
  i=0;
  f.getline(info,9,' ');				  //f<<sa_score<<" ";
  while(!f.eof())
  {							  //f<< p_level<<" ";
   i++;
   if(i==2)
   {
   }
  }
  f.open("SAVE FILES",ios::in);
  f.read((char *)&f,(sizeof (snake)));
  f.read((char*)&s,(sizeof (snake)));
  /*for(int lev=1;lev<this->level;lev++)
  {
   setcolor(15);
   //outextxy
  } */
  while(dg!=13&&dg!=27)
  {
   dg=getch();
  }
}
void control()
{
  snake rt;
  cont : rt.beautify();
  settextstyle(4,HORIZ_DIR,5);
  setcolor(12);
  outtextxy(90,70,"SETTINGS & CONTROLS");
  setcolor(15);
  settextstyle(1,HORIZ_DIR,2);
  outtextxy(150,150,"DIFFICULTY LEVEL");
  outtextxy(150,180,"BACKGROUD COLOUR");
  outtextxy(150,210,"SNAKE COLOUR");
  outtextxy(150,240,"CHANGE THEME");
  //outtextxy(150,270,"");
  char sd;
  while(sd!=27)
  {
    sd=getch();
    if(sd==49)
    {
      cleardevice();
      rt.beautify();
      setcolor(15);
      outtextxy(180,125,"DIFFICULTY LEVEL");
      outtextxy(185,165,"1 -> EASY");
      outtextxy(185,205,"2 -> MEDIUM");
      outtextxy(185,250,"3 -> HARD");
      outtextxy(185,295,"4 -> ULTRA HARD");
      char choice;
      choice=0;
      while(choice!=27)
      {
	cont_dif : choice=getch();
	if(choice==49)
	  dif=0;
	if(choice==50)
	  dif=1;
	if(choice==51)
	  dif=2;
	if(choice==52)
	  dif=4;
	if(choice==27)
	{
	  cleardevice();
	  goto cont;
	}
      }
     }
     if(sd==50)
     {
       cleardevice();
       rt.beautify();
       setcolor(15);
       outtextxy(150,125,"AVAIBLE BACKGROUD COLOURS");
       outtextxy(185,165,"1 -> Light Grey");
       outtextxy(185,205,"2 -> Yellow");
       outtextxy(185,245,"3 -> Light Blue");
       outtextxy(185,285,"4 -> Light Red");
       outtextxy(185,315,"5 -> Light Magenta");
       char choice;
       choice=0;
       while(choice!=27)
       {
	 cont_bkcol : choice=getch();
	 if(choice==49)
	   bk_col=7;
	 if(choice==50)
	   bk_col=14;
	 if(choice==51)
	   bk_col=9;
	 if(choice==52)
	   bk_col=12;
	 if(choice==53)
	   bk_col=13;
	 if(choice==27)
	 {
	   cleardevice();
	   goto cont;
	 }
       }
     }
       if(sd==51)
       {
	 cleardevice();
	 rt.beautify();
	 setcolor(15);
	 outtextxy(150,125,"AVAILABLE SNAKE COLOURS");
	 outtextxy(185,165,"1 -> Light Cyan");
	 outtextxy(185,205,"2 -> L ight Green");
	 outtextxy(185,245,"3 -> Light Blue");
	 outtextxy(185,285,"4 -> Light Red");
	 outtextxy(185,325,"5 -> Light Green");
	 outtextxy(185,365,"6 -> Random");
	 char choice;
	 choice=0;
	 while(choice!=27)
	 {
	   //choice=getch();
	   cont_bcol: choice=getch();
	   if(choice==49)
	     {sn_col=11;
	      rdm=0;
	     }
	   if(choice==50)
	     {
	      sn_col=10;
	      rdm=0;
	     }
	   if(choice==51)
	     {
	      sn_col=9;
	      rdm=0;
	     }
	   if(choice==52)
	     {
	      sn_col=12;
	      rdm=0;
	     }
	   if(choice==53)
	     {
	      sn_col=10;
	      rdm=0;
	     }
	   if(choice==54)
	     rdm=1;
	   if(choice==27)
	   {
	     cleardevice();
	     goto cont;
	   }
	 }
       }
       if(sd==52)
       {
	  cleardevice();
	  rt.beautify();
	  setcolor(15);
	  outtextxy((getmaxx()-textwidth("AVAILABLE THEMES"))/2,125,"AVAILABLE THEMES");
	  outtextxy((getmaxx()-textwidth("5-> THEME 5"))/2,165,"1-> THEME 1");
	  outtextxy((getmaxx()-textwidth("5-> THEME 5"))/2,205,"2-> THEME 2");
	  outtextxy((getmaxx()-textwidth("5-> THEME 5"))/2,250,"3-> THEME 3");
	  outtextxy((getmaxx()-textwidth("5-> THEME 5"))/2,295,"4-> THEME 4");
	  outtextxy((getmaxx()-textwidth("5-> THEME 5"))/2,340,"5-> THEME 5");
	  char choice;
	  choice=0;
	  while(choice!=27)
	  {
	    cont_th : choice=getch();
	    if(choice==49)
	      br_col=11;
	    if(choice==50)
	      br_col=3;
	    if(choice==51)
	      br_col=14;
	    if(choice==52)
	      br_col=12;
	    if(choice==53)
	      br_col=100;
	    if(choice==27)
	    {
	      cleardevice();
	      goto cont;
	    }
	  }
	}
    }
}


int check_exit(char sed);

void check_pause()
{
  if(pause)
  {
     pause=0;
     setcolor(1);
     settextstyle(8,HORIZ_DIR,2);
     outtextxy(getmaxx()/2-30,getmaxy()-30,"GAME PAUSED");
     char sed=0;
     while(sed!=32)
     {
      sed=getch();
     }
     setcolor(2);
     outtextxy(getmaxx()/2-30,getmaxy()-30,"GAME PAUSED");
  }
}

//-----------------------------------------------------//

void chek(int pos)
{
      setcolor(8);
      settextstyle(7,HORIZ_DIR,3);
      if(pos==1)
       outtextxy((getmaxx()-textwidth("Start game"))/2,180,"Start Game");
      if(pos==2)
       outtextxy((getmaxx()-textwidth("Stats"))/2,220,"Stats");
      if(pos==3)
       outtextxy((getmaxx()-textwidth("Controls & settings"))/2,260,"Controls & Settings");
      if(pos==4)
       outtextxy((getmaxx()-textwidth("Help"))/2,300,"Help");
      if(pos==5)
       outtextxy((getmaxx()-textwidth("Quit"))/2,340,"Quit");
}

//-------------------------------------------------------//

void chekr(int pos)
{
      setcolor(15);
      settextstyle(7,HORIZ_DIR,3);
      if(pos==1)
       outtextxy((getmaxx()-textwidth("Start game"))/2,180,"Start Game");
      if(pos==2)
       outtextxy((getmaxx()-textwidth("Stats"))/2,220,"Stats");
      if(pos==3)
       outtextxy((getmaxx()-textwidth("Controls & settings"))/2,260,"Controls & Settings");
      if(pos==4)
       outtextxy((getmaxx()-textwidth("Help"))/2,300,"Help");
      if(pos==5)
       outtextxy((getmaxx()-textwidth("Quit"))/2,340,"Quit");
}

//-------------------------------------------------------------//

void chek();

//------------------------------------------------------------//
int amp=0,kmp=0;
void snake:: fac()   //PROVIDES HELP & HELLISH OBJECTS TO PLAYER DURING COURSE OF GAME
{
  //static int amp=0,kmp=0;
  if(game_time>150&&game_time<180)
  {
    chk_def_ch=1;
    kmp++;
    if(kmp)
    food_col=9;
    else
    food_col=10;
  }
  else if(game_time>180)
  {
    chk_def_ch=0;
    kmp=0;
    food_col=10;
  }                 //100 130 160
  if(game_time>200)
  {
    amp++;
    if(amp==1)
    speed=speed-10;
    if(amp)
    food_col=4;
    else
    food_col=10;
  }
}

//-----------------------------------------------------------//

void snake::help()
{
  cleardevice();
  beautify();
  settextstyle(4,HORIZ_DIR,5);
  setcolor(12);
  outtextxy((getmaxx()-textwidth("Help"))/2,70,"HELP");
  setcolor(15);
  settextstyle(4,HORIZ_DIR,2);
  outtextxy(70,150,"Time Limit : 300 seconds");
  delay(2);
  outtextxy(70,180,"Minimum points you have to collect : 500");
  delay(2);
  outtextxy(70,210,"Total levels : 10");
  delay(2);
  outtextxy(70,240,"Shortcut to change snake's color : c");
  delay(2);
  outtextxy(70,270,"Shortcut to change background color : b");
  delay(2);
  outtextxy(70,300,"Shortcut to change snake's line color : l,thickness : t");
  delay(2);
  outtextxy(70,330,"Shortcut to toggle snake's line : y");
  delay(2);
  outtextxy(70,360,"Shortcut to toggle snake's dots : u");
  char yt;
  yt=getch();
  while(yt!=13&&y!=27)
  {
   yt=getch();
  }
}

//-----------------------------------------------------------//

void front()
{
  settextstyle(7,HORIZ_DIR,2);
  settextstyle(4,HORIZ_DIR,7);
  setcolor(12);
  outtextxy(90,70,"SNAKE GAME");
  settextstyle(7,HORIZ_DIR,3);
  setcolor(15);
  outtextxy((getmaxx()-textwidth("Start game"))/2,180,"Start Game");
  setcolor(8);
  outtextxy((getmaxx()-textwidth("Stats"))/2,220,"Stats");
  outtextxy((getmaxx()-textwidth("Controls & settings"))/2,260,"Controls & Settings");
  outtextxy((getmaxx()-textwidth("Help"))/2,300,"Help");
  outtextxy((getmaxx()-textwidth("Quit"))/2,340,"Quit");
}

int pwd1[15],pwd2[15];

void button()
{
  /*setfillstyle(SOLID_FILL,2);
  bar(200,400,250,470);
  bar(350,400,400,470);  */
}
void accept()
{
  snake sn;
  sn.beautify();
  int pd=0,a=0,b=0,pd_chk[9]={1,2,3,6,9,8,7,4,1},pwd_ck[9];
  int rv_a,rv_b;
  pwd_ck[pd]=0;
  char choice,chc;
  circle(pwd2[0],pwd1[0],10);
  setlinestyle(SOLID_LINE,1,3);
  while(choice!=13)
  {
    choice=getch();
    if(choice==0)
    {
      chc=getch();
      if(chc==72)
      {
	if(b-1>=0)
	{
	  setcolor(0);
	  circle(pwd2[a],pwd1[b],10);
	  setcolor(15);
	  rv_b=pwd1[b];
	  rv_a=pwd2[a];
	  b=b-1;
	  setlinestyle(SOLID_LINE,1,1);
	  circle(pwd2[a],pwd1[b],10);
	  setlinestyle(SOLID_LINE,1,3);
	  setcolor(7);
	  line(rv_a,rv_b,pwd2[a],pwd1[b]);
	  setcolor(15);
	}
      }
      if(chc==80)
      {
	if(b+1<3)
	{
	  setcolor(0);
	  circle(pwd2[a],pwd1[b],10);
	  setcolor(15);
	  rv_b=pwd1[b];
	  rv_a=pwd2[a];
	  b=b+1;
	  setlinestyle(SOLID_LINE,1,1);
	  circle(pwd2[a],pwd1[b],10);
	  setlinestyle(SOLID_LINE,1,3);
	  setcolor(7);
	  line(rv_a,rv_b,pwd2[a],pwd1[b]);
	  setcolor(15);
	}
      }
      if(chc==75)
      {
	if(a-1>=0)
	{
	  setcolor(0);
	  circle(pwd2[a],pwd1[b],10);
	  setcolor(15);
	  rv_b=pwd1[b];
	  rv_a=pwd2[a];
	  a=a-1;
	  setlinestyle(SOLID_LINE,1,1);
	  circle(pwd2[a],pwd1[b],10);
	  setlinestyle(SOLID_LINE,1,3);
	  setcolor(7);
	  line(rv_a,rv_b,pwd2[a],pwd1[b]);
	  setcolor(15);
	}
      }
      if(chc==77)
      {
	if(a+1<3)
	{
	  setcolor(0);
	  circle(pwd2[a],pwd1[b],10);
	  setcolor(15);
	  rv_b=pwd1[b];
	  rv_a=pwd2[a];
	  a=a+1;
	  setlinestyle(SOLID_LINE,1,1);
	  circle(pwd2[a],pwd1[b],10);
	  setcolor(7);
	  setlinestyle(SOLID_LINE,1,3);
	  line(rv_a,rv_b,pwd2[a],pwd1[b]);
	  setcolor(15);
	}
      }
    }
  }
  for(int cp=60;cp<getmaxx()-60;cp=cp+1)
  {
    setfillstyle(SOLID_FILL,9);
    bar(cp,getmaxy()-105,cp+5,getmaxy()-95);
    delay(5);
  }
}

void password()
{
  int ip=0,kp=0;
  settextstyle(4,HORIZ_DIR,7);
  setcolor(12);
  button();
   setfillstyle(SOLID_FILL,9);
  outtextxy(90,70,"SNAKE GAME");
  for(static int ps=0;ps<3;ps++)
  {
    setcolor(15);
    pwd1[kp]=200+ps*50;
    for(int ps2=0;ps2<3;ps2++)
    {
      circle(250+50*ps,200+ps2*50,5);
      floodfill(250+50*ps,200+ps2*50,15);
      pwd2[ip]=250+50*ps2;
      ip++;
    }
    kp++;
  }
  accept();
  getch();
  cleardevice();
}
void main()
{
  clrscr();
  char d,c,pk,endchoice;
  int p=0,pos=1,gd=DETECT,gm,color=0,cr=0,ab=0,ckcheat=1;
  initgraph(& gd,&gm,"");
  maxx=getmaxx();
  maxy=getmaxy();
  rndom();
  level=4;
  password();
  start_game:
  maxx=getmaxx();
  maxy=getmaxy();
  front();
  s.beautify();
  while(!kbhit())
  {
  settextstyle(4,HORIZ_DIR,7);
  if(color%2==0)
  setcolor(12);
  else
  setcolor(8);
  outtextxy(90,70,"SNAKE GAME");
  delay(500);
  color++;
  }
  settextstyle(4,HORIZ_DIR,7);
  setcolor(12);
  outtextxy(90,70,"SNAKE GAME");
  //move_choice();
  while(pk!=13)
  {
  settextstyle(7,HORIZ_DIR,2);
  pk=getch();
  if(pk==0)
  {
    pk=getch();
    if(pk==72)
    {
    if(pos!=1)
    {
      chek(pos);
      pos--;
      chekr(pos);
    }
    else
    {
      chek(pos);
      pos=5;
      //pos--;
      chekr(pos);
    }
    }
    if(pk==80)
    {
    if(pos!=5)
    {
      chek(pos);
      pos++;
      chekr(pos);
    }
    else
    {
      chek(pos);
      pos=1;
      //pos++;
      chekr(pos);
    }
    }
  }
  /*if(pk=='i')
  exit(0);*/
  p=pos+48;
  }
  pk=1;
  pos=1;

  for(i=0;i<getmaxx();i=i+15)
  {

   setfillstyle(SOLID_FILL,0);
   for(int j=0;j<getmaxy();j=j+15)
   {
     bar(i,j,i+15,j+15);
     delay(0.6);
   }
  }

  //game_time=0;
  cleardevice();
  if(p==53)
  exit(0);
  if(p==50)
  {
   stats();
   cleardevice();
   goto start_game;
  }
  if(p==52)
  {
    //s.load();
    s.help();
    cleardevice();
    goto start_game;
  }
  if(p==51)
  {
    control();
    cleardevice();
    goto start_game;
  }
  if(p==49)
  {
  s.count();
  start:
  s.makesnake();
  s.setscreen();
  s.makebars();
  s.makelines();
  s.motionr();
  check='r';
  if(level<10)
  speed=100-5*dif-3*level;
  else
  speed=50-5*dif-5*level;
  rdm=1;
  line_col=15;
  while(1)
  {
   //game_time=0;
   //delay(5000);
   setbkcolor(bk_col);
   if(end)
     break;
    c=getch();
    if(c!='0')
    s.checkmotion();
    if(c=='t'||c=='T')
    line_thick++;
    if(c=='y'||c=='Y')
    lin++;
    if(c=='u'||c=='U')
    dot++;
    if(c=='l')
    {
      line_col++;
      if(line_col>15)
      line_col=0;
    }
    if(c==27)
    {
     char sed=0;
     ext=1;
     sed=check_exit(sed);
     if(sed==13)
     {
      cleardevice();
      final_score=pscore;
      food=1;
      game_time=0;
      goto start_game;
     }
    }
    else if(c=='c')
    {
      rdm=0;
      int scol[15]={0,1,2,3,4,5,6,7,8,10,11,12,13,14,15};
      if(scol[cr]!=bk_col)
      sn_col=scol[cr];
      if(cr==5)
      rdm=1;
      s.checkmotion();
      cr++;
      if(cr==15)
      cr=0;
    }
    if(c=='b')
    {
      int bcol[15]={0,1,2,3,4,5,6,7,8,10,11,12,13,14,15};
      if(sn_col!=bcol[ab])
      bk_col=bcol[ab];
      s.checkmotion();
      ab++;
      if(ab==15)
      ab=0;
    }
    if(c==cheat1[0])
    {
      for(i=1;cheat1[i]!='\0';i++)
      {
      s.checkmotion();
      c=getch();
      if(cheat1[i]==c||cheat1[i]==c+32||cheat1[i]==c-32)
      {
       //c=getch();
       ckcheat=1; cout<<"sj  "<<ckcheat;
      }
      else
      {          //cout<<"dhjgfxdngvfXHCFDS";
	s.checkmotion();
       ckcheat=0;
       break;
      }
      }
      if(ckcheat)
      {        cout<<"shdfS";
	s.checkmotion();
	cheat++;
	speed=speed+20;
	ckcheat=0;
      }
    }
    if(c==cheat2[0])
    {
      for(i=1;cheat2[i]!='\0';i++)
      {
       s.checkmotion();
       c=getch();
      if(cheat2[i]==c||cheat2[i]==c+32||cheat2[i]==c-32)
      {          //cout<<"hg";
	s.checkmotion();
	c=getch();
	ckcheat=1;
      }
      else
      {
       cout<<"cv";
       s.checkmotion();
       ckcheat=0;
       break;
      }
      }
      if(ckcheat)
      {
	s.checkmotion();
	cheat++;
	speed=speed-5;
	ckcheat=0;
      }
    }
    if(c==cheat3[0])
    {
      for(i=1;cheat3[i]!='\0';i++)
      {
      s.checkmotion();
      c=getch();
      if(cheat3[i]==c||cheat3[i]==c+32||cheat3[i]==c-32)
      {
	s.checkmotion();
	c=getch();
	ckcheat=0;
      }
      else
      {
       s.checkmotion();
       ckcheat=1;
       break;
      }
      }
      if(!ckcheat)
      {
	s.checkmotion();
	cheat++;
	ckibar=1;
	ckcheat=0;
      }
    }
    if(c==cheat4[0])
    {
      for(i=0;cheat4[i]=='\0';i++)
      {
      s.checkmotion();
      if(cheat4[i]==c)
      {
	c=getch();
	ckcheat=0;
      }
      else
      {
       ckcheat=1;
       break;
      }
      }
      if(!ckcheat)
      {
	s.checkmotion();
	cheat++;
	wrong=1;
	ckcheat=1;
      }
    }
    if(c==32)
    {
     pause=1;
     check_pause();
     /*setcolor(15);
     settextstyle(8,HORIZ_DIR,2);
     outtextxy(getmaxx()/2-30,getmaxy()-30,"GAME PAUSED");
     char sed=0;
     while(sed!=32)
     {
      sed=getch();
     }
     setcolor(0);
     outtextxy(getmaxx()/2-30,getmaxy()-30,"GAME PAUSED");  */
    }
    if(c==0)
    {
    if(end)
    {
     delay(1000);
     break;
    }
    d=getch();
    if(d==32)
    {
     setcolor(15);
     settextstyle(8,HORIZ_DIR,2);
     outtextxy(getmaxx()/2-30,getmaxy()-30,"GAME PAUSED");
     char sed=0;
     while(sed!=32)
     {
      sed=getch();
     }
     setcolor(0);
     outtextxy(getmaxx()/2-60,getmaxy()-30,"GAME PAUSED");
    }
    else if(d==82)
    {
      pause=1;
      check_pause();
    }
    else if(d==77)     //motion in right
    {
      if(end)
      {
	delay(1000);
	break;
      }
      else if(check!='l')
      {
	s.motionr();
	check='r';
      }
      else if(check=='l')
      {
	s.motionl();
	check='l';
      }
      else if(pause)
      {
	pause=1;
	check_pause();
      }
      s.makelines();
      s.makebars();
    }
   else if(d==75)      //motion in left
   {
      if(end)
      {
	delay(1000);
	break;
      }
      if(check!='r')
      {
	s.motionl();
	check='l';
      }
      else if(check=='r')
      {
	s.motionr();
	check='r';
      }
      s.makelines();
      s.makebars();
   }
   else if(d==80)      //motion in down
   {
     if(end)
     {
	delay(1000);
	break;
      }
      if(check!='t')
      {
	s.motiond();
	check='d';
      }
      else if(check=='t')
      {
	s.motiont();
	check='t';
      }
      s.makelines();
      s.makebars();
   }
   else if(d==72)      //motion in top
   {
      if(end)
      {
	delay(1000);
	break;
      }
      if(check!='d')
      {
	s.motiont();
	check='t';
      }
      else if(check=='d')
      {
	s.motiond();
	check='d';
      }
      s.makelines();
      s.makebars();
      //final_score=final_score+run;
   }

   if(d==71)
   {
     s.checkmotion();
     if(home_chk%2==0)
       home=1;
     else
       home=0;
     home_chk++;
   }
   if(game_time>=gametime)
   {
    if(run>=500)
    {
     setbkcolor(0);
     ckbar=0;
     food=1;
     size=0;
     chk_def_ch=0;
     food_col=10;
     amp=0;
     kmp=0;
     pscore=pscore+run;
     run=0;
     end=0;
     maxx=getmaxx();
     maxy=getmaxy();
     speed=70-5*dif-2*level;
     game_time=0;
     s.check_win();
     delay(1000);
     cleardevice();
     s.game_save();
     goto start;
    }
    else
    { cout<<"daf";
    end=1;
    }
   }
   if(end)
   {
     setcolor(0);
     delay(1000);
     break;
   }
   s.makelines();
   s.makebars();
   }
  }
  bk_col=0;
  setbkcolor(bk_col);
  maxx=getmaxx();
  maxy=getmaxy();
  cleardevice();
  if(end==1)
  {
  final_score=pscore;
  food=1;
  size=0;
  run=0;
  end=0;
  fail++;
  chk_def_ch=0;
  food_col=10;
  amp=0;
  kmp=0;
  maxx=getmaxx();
  maxy=getmaxy();
  game_time=0;
  setcolor(15);
  settextstyle(8,HORIZ_DIR,3);
  s.beautify();
  outtextxy(200,100,"!! GAME OVER !!");
  if(wrong)
  outtextxy(200,100,"!! FUCKED UP !!");
  delay(1000);
  cleardevice();
  s.beautify();
  outtextxy(200,100,"Want To Retry");
  outtextxy(210,150,"1. Yes");
  outtextxy(210,200,"2. No");
  do
  {
    endchoice=getch();
  }while(endchoice!=49&&endchoice!=50);
  cleardevice();
  if(endchoice==49)
  goto start;
  else
  goto start_game;
  }
  }
  getch();
}


int  check_exit(char sed)
{
  if(ext)
  {
     ext=0;
     setcolor(15);
     settextstyle(8,HORIZ_DIR,2);
     outtextxy(getmaxx()/2-110,getmaxy()-30,"DO WANT TO EXIT ?");
     while(sed!=13&&sed!=27)
     {
      sed=getch();
     }
     if(sed==27)
     {
      setcolor(0);
      outtextxy(getmaxx()/2-110,getmaxy()-30,"DO WANT TO EXIT ?");
     }
   }
   return sed;
}