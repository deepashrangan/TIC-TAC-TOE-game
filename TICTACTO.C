#include<stdio.h>
#include<bios.h>
#include<conio.h>
#include<dos.h>
#define rl 218
#define ml 191
#define hl 196
#define vl 179
#define tt 194
#define cross 197
#define rt 195
#define lt 180
#define ll 192
#define revt 193
#define bl 217
#define bs 8
#define space 32
#define width 7
#define height 3
#define dim 3
#define safe 1
#define unsafe 0
#define row 10
int tic[row]={-1,-1,-2,-3,-4,-5,-6,-7,-8,-9};
#define left 19200
#define right 19712
#define up 18432
#define down 20480
#define esc 283
#define P 6480
int main()
{
char name1[100]="DEEPASH",name2[100]="RANGAN";
 int count=0,key,bcol=27,brow=12,i=0,index,iu,count1=0;
clrscr();



printf(" \t\t\t WELCOME TO WORLD OF TIC TAC TOE\n\n\n");
//bcol=bcol+(2*8);
brow=brow+8;
printf("  ENTER PLAYER NAME1 : %s ",name1);
//scanf("%s",&name1);
printf("\n  ENTER PLAYER NAME1 : %s",name2);
//scanf("%s",&name2);

// gotoxy(bcol,brow);
 //printf("1");
//printf("%s\n",name1);
//printf("%s",name2);
  putdappa();



 gotoxy(bcol,brow);
// printf("1");
 do{
// putdappa();
while(bioskey(1)==0);

key=bioskey(0);
gotoxy(59,6);
printf("                    ");
gotoxy(59,6);
if(count%2==0){

printf("%s Turn(1)",name1);
}
else{
printf("%s Turn(0)",name2);

}
///delline();
gotoxy(bcol,brow);

switch(key)
case left:
{
bcol=bcol-8;
//i++;
//if(i==3)
//i=0;
// gotoxy(bcol,brow);
 // printf("1");
 if(bcol<27)
 bcol=43;
  gotoxy(bcol,brow);
  //printf("1");
break;

 case right:
bcol=bcol+8;
if(bcol>43)
bcol=27;
gotoxy(bcol,brow);
//printf("0");
break;
 case up:
 brow=brow-4;
 if(brow<12)
 brow=20;
gotoxy(bcol,brow);
//printf("0");
break;
 case down:
 brow=brow+4;
 if(brow>20)
 brow=12;
gotoxy(bcol,brow);
//printf("1");
 break;

case P:
	if(bcol==27&&brow==12)
	index=1;
	else if(bcol==27&&brow==16)
	index=4;
	else if(bcol==27&&brow==20)
	index=7;
	else if(bcol==43&&brow==20)
	index=9;
	else if(bcol==43&&brow==16)
	index=6;
	else if(bcol==43&&brow==12)
	index=3;
	else if(bcol==35&&brow==20)
	index=8;
	else if(bcol==35&&brow==16)
	index=5;
	else if(bcol==35&&brow==12)
	index=2;
	  count++;
	  iu=bcol;
if(issafe(index)==1)
	{
	if(count%2==1)
       {	printf("1");
	tic[index]=1;
       //	print();
	if( amiwin()==1)
     {
     gotoxy(59,9);
     printf("\n\n\n    \t\t\t %s won the game",name1);
      gotoxy(bcol,brow);
     count1++;
      }
       //	printf("\n\n\n ind=%d to=%d ",index,tic[index]);
	//bcol=bcol+8;
       //	if(bcol>43)
	//bcol=27;
	//gotoxy(bcol,brow);
       //	break;
	}
	else
	{printf("0");
       tic[index]=0;
      // print();
       //	printf("\n\n\n ind=%d to=%d ",index,tic[index]);

       if( amiwin()==1)

       {
       gotoxy(59,9);
	printf("\n\n\n\t\t\t  %s won the game",name2);
	  gotoxy(bcol,brow);
	  count1++;
	}

       //	bcol=bcol+8;
	      //	if(bcol>43)
       //	bcol=27;
	 //gotoxy(bcol,brow);
	 //break;
	 }  if(count==9&&count1==0)
	 { gotoxy(59,9);
	 printf("GAME DRAW");
	 gotoxy(bcol,brow);
   }
  /*

       if( amiwin()==1)
       {
	if(count%2==0)
	printf("\n\n\n%s won the game",name2);
	else
	printf("\n\n\n%s won the game",name1);

	}    */

       //	break;
	}
	else
	{
	sound(200);
	gotoxy(59,9);
	printf("\n\n\n not a valid move");
	gotoxy(bcol,brow);
	delay(500);
	count--;
	nosound();
	}

      }
  }while(key!=esc&&count1!=1);
	 //if(count==9)
       //	 printf("\n\n\nGAME IS DRAW");
	 getch();
	 return 0;

}


int issafe(int index)
{
      if(tic[index]<0)
      return 1;
      else
      return -1;

}





int  putdappa()
{
 int bcol=23,brow=10,i,j,k,o,p,m ;
// clrscr();
textcolor(RED+BLINK);
//delay(500);
gotoxy(2,5);
cprintf("\n\n\n                             TIC TAC TOE    ");
   textcolor(YELLOW);
 gotoxy(bcol,brow);
 cprintf("%c",rl);
for(j=1;j<=dim;j++){
 for(i=1;i<=width;i++)
 {
 cprintf("%c",hl);
  }cprintf("%c",tt);
  }
  cprintf("%c%c",bs,ml);
  //endof1stline
 for(m=1;m<=dim;m++)
 { for(i=1;i<=height;i++){
  brow=brow+1;
  gotoxy(bcol,brow);

  cprintf("%c",vl);
    for(o=1;o<=dim;o++){
    for(k=1;k<=width;k++)

   // textbackground(WHITE);
    cprintf("%c",space);
    cprintf("%c",vl);
		      } }

 brow=brow+1;
  gotoxy(bcol,brow);
  if(m!=dim)
  cprintf("%c",rt);
  else
  {cprintf("%c",ll);
  }
  for(p=1;p<=dim;p++)
 { for(j=1;j<=width;j++)
  {cprintf("%c",hl);

  }
   if(m!=dim)
 { cprintf("%c",cross);
  }
  else
  {cprintf("%c",revt);
  }



   }
  if(m!=dim)
  cprintf("%c%c",bs,lt);
  else
  cprintf("%c%c",bs,bl);
  }
     brow=brow-12;
    // printf("\n\n\n%d %d",bcol,brow);
 // gotoxy(bcol,brow);
 // printf("1");
    return 0;
}

int amiwin()
{
 if(tic[1]==tic[5]&&tic[1]==tic[9]&&tic[5]==tic[9])
 return 1;
 else if(tic[3]==tic[5]&&tic[5]==tic[7]&&tic[3]==tic[7])
 return 1;
 else if(tic[7]==tic[8]&&tic[8]==tic[9]&&tic[7]==tic[9])
 return 1;
 else if(tic[1]==tic[2]&&tic[1]==tic[3]&&tic[2]==tic[3])
 return 1;
 else if(tic[4]==tic[5]&&tic[4]==tic[6]&&tic[5]==tic[6])
 return 1;
else if(tic[1]==tic[4]&&tic[4]==tic[7]&&tic[1]==tic[7])
 return 1;
else if(tic[2]==tic[5]&&tic[5]==tic[8]&&tic[2]==tic[8])
 return 1;
else if(tic[3]==tic[6]&&tic[6]==tic[9]&&tic[3]==tic[9])
 return 1;
 else
 return 0;

}


int print()
{
printf("\n\n\n\n%d %d %d %d %d %d %d %d %d",tic[1],tic[2],tic[3],tic[4],tic[5],tic[6],tic[7],tic[8],tic[9]);
   return 0;
}