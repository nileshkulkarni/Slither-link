int loopSolver();
void Mainmenu();
int solutionloop();
int nextpuzz();

#include<iostream>
#include "ezwin.h"
#include "bitmap.h"
#include<cstdio>
using namespace std;
#include "loop_class.h"

Loop MainLoop;
int solns=0, level=0, diff=2, nQueued=0;
int hLines[17][17], vLines[17][17], iQueue[1000], jQueue[1000], kQueue[1000], typeQueue[1000];
bool Queued[3][16][16][4];
#include"LoopSolverinterface_newver1.h"
#include "functions_solver_debug.h"
#include "solved.h"
#include "solve_solver.h"
int ApiEnd()
{
	loopsolverDisplay.Close();
}
int loopSolver()
{
	//AcceptHW();
	AssignValuesloop();
	setpositionloop();
	DisplayGridInitial();
	displayProblemAcceptor();	
	return 1;
		
}
int nextpuzz()
{
	DisplayGridInitial();
	for(int i=1;i<=HorSize+1;i++)
	{
		for(int j=1;j<=VerSize+1;j++)
		{
			statusH[i][j]=1;
			statusV[i][j]=1;
			Num[i][j]=-1;
			if(j<VerSize+1)
			{
			object_num[i][j].Load("blank.xpm");
			Position p10=blueH[i][j].GetPosition()+Position(0,ybh+0.1);
			object_num[i][j].SetPosition(p10);
			object_num[i][j].Draw();	
			}		
		}
	}
	return 1;
}
void Mainmenu()
{
	loopsolverDisplay.Close();
}
int solutionloop()
{	int i, j;
	 MainLoop.Clear();
	
	MainLoop.SetSize();
	for (i=1; i<=HorSize; i++) for (j=1; j<=VerSize; j++) MainLoop.GridVal[i][j]=Num[i][j];
	MainLoop.Solve();

	Position Center=loopsolverDisplay.GetCenter();
	Position ul=Center+Position(-1,-1);
	Position lr=Center+Position(-1,-1);
	
	if(solns==0) loopsolverDisplay.Message("Please recheck the question. It is inconsistent");
	else {
		if(solns==1) loopsolverDisplay.Message("Unique Solution");
		else loopsolverDisplay.Message("The given question has multiple solutions, one of which is displayed.");
		DisplayGridSolution();
	}		
	
	return 1;
}

int ApiMain()
{	
	int i, j;
	FILE *size;
	size=fopen("GridSize","r");
	fscanf(size,"%2d %2d", &HorSize, &VerSize);
	for (i=1; i<=HorSize; i++) for (j=0; j<=VerSize; j++) Num[i][j]=-1;
	loopsolverDisplay.Open();
	loopSolver();
	clickstatus=1;
	loopsolverDisplay.SetMouseClickCallback(MouseAcceptor);
}

