#include<iostream>
#include "ezwin.h"
#include "bitmap.h"
#include<cstdio>
#include <cstring>
#include <ctime>
int VerifyStatus(int a);
int play();
int verifyButton();
int newpuzz();
int mainMenu();
int solution();
int resetButton();
int ApiMain();
bool cheated=false;
int solns=0, level=0, diff=2, change;
int Num[16][16], hLines[17][17], vLines[17][17];
int HorSize,VerSize;
	int statusH[17][17];
	int statusV[17][17];
int time1;

#include "Playinterface_debug.h"
#include "loop_class.h"

Loop MainLoop;
#include "functions_play.h"
#include "solved.h"
#include "generate.h"
#include "solve_play.h"

int resetButton()
{
		for(int i=0;i<17;i++)
		{
			for(int j=0;j<17;j++)
			{
			statusH[i][j]=1;
			statusV[i][j]=1;
			}			
		}
		DisplayGridInitial();
		
			return 1;
}

int solution()//can't solve implementation
{	
	int i, j;
	cheated=true;
	MainLoop.Clear();
	MainLoop.SetSize();
	for(i=1;i<=HorSize;i++)
	{
		for(j=1;j<=VerSize;j++)
		{
			MainLoop.GridVal[i][j]=Num[i][j];
		}
	}
	MainLoop.Solve();
	GridDisplay.StopTimer();
	DisplayGridSolution();
	
	return 1;
}	
int verifyButton()//check's user solution
{	int i ,j, a;
	if (cheated) {
		Position Center=GridDisplay.GetCenter();
		Position ul=Center+Position(-1,-1);
		Position lr=Center+Position(-1,-1);
		GridDisplay.Message("You have already clicked the \"Can't Solve\" button.");
		return 1;
	}
	
	MainLoop.Clear();
	MainLoop.SetSize();
	for(i=1;i<=HorSize;i++)
	{
		for( j=1;j<=VerSize;j++)
		{
			MainLoop.GridVal[i][j]=Num[i][j];
		}
	}
	
	for (i=0; i<=HorSize; i++) for (j=1; j<=VerSize; j++) MainLoop.InputHor(i, j);
	for (i=1; i<=HorSize; i++) for (j=0; j<=VerSize; j++) MainLoop.InputVer(i, j);
	
	Position Center=GridDisplay.GetCenter();
	
	Position ul=Center+Position(-1,-1);
	
	Position lr=Center+Position(-1,-1);
	
	a=MainLoop.Solved();
	if(a==0)
	GridDisplay.Message("Congratulations!!!! Your Solution is Correct :) :)");
	else if(a==1)
	GridDisplay.Message("Sorry wrong solution loop has loose ends or  intersections :(");
	else if(a==2)
	GridDisplay.Message("Sorry wrong solution there are unsatisfied numbers :( or oversatisfied o.O");
	else 
	GridDisplay.Message("Sorry wrong solution it contains multiple loops :P");
	
	return 1;
}
	
int newpuzz()
{		cheated=false;
		GridDisplay.StopTimer();
		resetButton();
		Generate();
		number_reset();
		renderNumbers();
		DisplayGridInitial();
		time1=0;
		GridDisplay.StartTimer(1000);
		return 1;
}	
int mainMenu()
{
		GridDisplay.Close();
}



int play()
{
	// AcceptHW();
	
	AssignValuesPlay();
	
	setpositionPlay();
	resetButton();
	Generate();
	
	renderNumbers();
	 DisplayGridInitial();
	 
	displayclock();
	 time1=0;
	 
	
	return 1;		
}

int ApiMain()
{	srand(time(NULL));
	FILE *size;
	size=fopen("GridSize","r");
	fscanf(size,"%2d %2d %2d", &HorSize, &VerSize, &diff);
	GridDisplay.Open();
	play();
	GridDisplay.SetTimerCallback(timerdisplay);
	GridDisplay.StartTimer(1000);
	GridDisplay.SetMouseClickCallback(MouseClickEventPlay);
}


	
		
	


		

