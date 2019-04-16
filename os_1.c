#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include<conio.h>
#include<windows.h>

int n=0,option=-1;

void gotoxy(long x, long y)
      {
           COORD pos = {x, y};
           SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
      }
/////////////////////////////////////

struct Process
{
	int P_ID,arivl_tym,burst_tym,completion_tym,waiting_tym,turnaround_tym,flag;
};

////////////////////////
average(struct Process P[n])
{
	int i;
	float totWt=0,totTt=0,avgWt,avgTt;
	for(i=0;i<n;i++)
	{
		totWt+=P[i].waiting_tym;
		totTt+=P[i].turnaround_tym;
	}
	avgWt=totWt/n;
	avgTt=totTt/n;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2 );
		gotoxy(71,2*n+12);
		printf("%c     %.2f ",179,avgWt);
		gotoxy(86,2*n+12);
		printf("%c    %.2f",179,avgTt);
}


///////////////////////////////////////////////////////////////////////////////////////

void frame()
{

	int i;

	for(i=0;i<91;i++)
	{
		gotoxy(11+i,3);
		printf("=");
		gotoxy(11+i,6);
		printf("_");
		gotoxy(11+i,2*n+7);
		printf("%c",175);
		if(i<30)
		{
		gotoxy(71+i,2*n+8);
		printf("=");
		gotoxy(71,2*n+9);
		printf("%c   Average    %c",179,179);
		gotoxy(71,2*n+10);
		printf("%c     W.T      %c",179,179);
		gotoxy(89,2*n+9);
		printf("Average    %c",179,179);
		gotoxy(89,2*n+10);
		printf("  T.T      %c",179,179);
		gotoxy(71+i,2*n+11);
		printf("%c",175);
		gotoxy(71+i,2*n+13);
		printf("%c",175);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2 );
		gotoxy(71,2*n+12);
		printf("%c       .      %c",179,179);
		gotoxy(89,2*n+12);
		printf("    .      %c",179);

	    }
	}
	////////////////
	gotoxy(15,4);
    printf("Process    %c",179);
    gotoxy(15,5);
    printf("  ID       %c",179);
    gotoxy(30,4);
    printf("arivl    %c",179);
    gotoxy(30,5);
    printf(" tym      %c",179);
    gotoxy(45,4);
    printf("Burst      %c",179);
    gotoxy(45,5);
    printf("tym       %c",179);
    gotoxy(60,4);
    printf("Completion %c",179);
    gotoxy(60,5);
    printf("   tym    %c",179);
    gotoxy(75,4);
    printf("Waiting    %c",179);
    gotoxy(75,5);
    printf(" tym      %c",179);
    gotoxy(89,4);
    printf("TurnAround %c",179);
    gotoxy(89,5);
    printf("   tym    %c",179);
	////////////////
    for(i=0;i<n*2+4;i++)
	{
		gotoxy(11,i+4);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2 );
		//printf("%c",179);
		printf("%c",179);
		printf("%c",222);

		gotoxy(100,i+4);
		printf("%c",222);
		printf("%c",179);
		//printf("||");
	}
}
/////////////////////////////////////////////////////////////////////////////
void display(struct Process P[n])
{
	//frame();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2 );
	int i,l=0,b=0;
	//n=7;
	for(i=0;i<n;i++)
    {
    l+=2;
	  //gotoxy(12,5+i);
	gotoxy(15,6+l);
	if(P[i].P_ID==-1)
    printf("   %c       %c",249,179);
    else
    {
    printf("           %c",179);
    gotoxy(15,6+l);
    printf("   P%d",P[i].P_ID);
    }