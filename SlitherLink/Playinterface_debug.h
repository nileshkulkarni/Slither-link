Position pW(0.5,0.5);
SimpleWindow GridDisplay("Slither Link ",20,20,pW);

	BitMap greyH[17][17];
	BitMap blueH[17][17];
	BitMap crossH[17][17];

	BitMap greyV[17][17];
	BitMap blueV[17][17];
	BitMap crossV[17][17];
	
	BitMap button1[17][17];
	BitMap button2[17][17];
	BitMap button3[17][17];
	BitMap button0[17][17];
	
	BitMap blank[17][17];
	
	BitMap VButton(GridDisplay);
	BitMap NewpuzzleButton(GridDisplay);
	BitMap ResetButton(GridDisplay);
	BitMap MMenuButton(GridDisplay);
	BitMap SolutionButton(GridDisplay);
	
	float xbh;
	float ybh;
	float ybv;
	float xbv;
	float yc;
	float xc;
	
	float clkh;
	float clkw;
	Position p;
	Position pTime;
	Position pclock;				
	 BitMap circ(GridDisplay);
/******************************************************************************/

float Breakdis=2;
void displayclock()
{
	float xverify, yverify;	
	BitMap clock(GridDisplay);
	clock.Load("clock.xpm");
	clkh=clock.GetHeight();
	clkw=clock.GetWidth();
	pclock=Position(blueH[1][VerSize].GetXPosition()+xbh+0.2+Breakdis,blueH[1][VerSize].GetYPosition()-ybv);
	clock.SetPosition(pclock);
	clock.Draw();
	VButton.Load("verify.xpm");
	
	xverify=VButton.GetWidth();
	yverify=VButton.GetHeight();
	ResetButton.Load("reset.xpm");
	
	SolutionButton.Load("showsoln.xpm");
	
	NewpuzzleButton.Load("newpuzzle.xpm");
	
	MMenuButton.Load("mainmenu.xpm");
	
	Position pb=pclock+Position(0,clkw+1.5);
	VButton.SetPosition(pb);
	pb=pb+Position(0,yverify+0.5);
	ResetButton.SetPosition(pb);
	pb=pb+Position(0,yverify+0.5);
	SolutionButton.SetPosition(pb);
	pb=pb+Position(0,yverify+0.5);
	NewpuzzleButton.SetPosition(pb);
	pb=pb+Position(0,yverify+0.5);
	
	MMenuButton.SetPosition(pb);

	VButton.Draw();	
	ResetButton.Draw();	
	SolutionButton.Draw();
	NewpuzzleButton.Draw();
	MMenuButton.Draw();

}
int timerdisplay()
{ 
	time1++;
	char s[30];
	int min=0;
	int sec=0;
	min=time1/60;
	sec=time1%60;
	sprintf(s,"%2d min %2d seconds",min,sec);
	Position up= pclock+Position(clkh,clkw-0.5);
	Position lp= pclock+Position(clkh+2,clkw+0.5);	
	GridDisplay.RenderText(up,lp,s,Black);
	return 1;
}
/******************************************************************************/
int AssignValuesPlay() 
{	
	circ.Load("circle.xpm");
	for(int k=0;k<17;k++)
	{
		for(int l=0;l<17;l++)
		{
			greyH[k][l].SetWindow(GridDisplay);
			blueH[k][l].SetWindow(GridDisplay);
			crossH[k][l].SetWindow(GridDisplay);
			greyV[k][l].SetWindow(GridDisplay);
			blueV[k][l].SetWindow(GridDisplay);
			crossV[k][l].SetWindow(GridDisplay);
			button0[k][l].SetWindow(GridDisplay);
			button1[k][l].SetWindow(GridDisplay);
			button2[k][l].SetWindow(GridDisplay);
			button3[k][l].SetWindow(GridDisplay);
			blank[k][l].SetWindow(GridDisplay);
			
		}
	}
	//height=height+1;
	//width++;
	for(int i=1;i<=HorSize+1;i++)
	{
		for(int j=1;j<=VerSize+1;j++)
		{	if(j<VerSize+1)
			{
				greyH[i][j].Load("greyhor.xpm");
				
				blueH[i][j].Load("bluehor.xpm");
				
				crossH[i][j].Load("crosshor.xpm");
				
				button0[i][j].Load("zero.xpm");
				
				button1[i][j].Load("one.xpm");
				
				button2[i][j].Load("two.xpm");

				button3[i][j].Load("three.xpm");

				blank[i][j].Load("blank");

			}
			if(i<HorSize+1)
			{
				greyV[i][j].Load("greyver.xpm");
				
				blueV[i][j].Load("bluever.xpm");

				crossV[i][j].Load("crossver.xpm");

			}
		}
	
	}
	
	return 1;
}
/******************************************************************************/
int number_reset()
{
	for(int i=1;i<=HorSize;i++)
	{
		for(int j=1;j<=VerSize;j++)
		{ 
			button0[i][j].Erase();
			button1[i][j].Erase();
			button2[i][j].Erase();
			button3[i][j].Erase();
//			blank[i][j].Erase();		
		}
	}
	return 1;
}
	
int renderNumbers()
{	
	for(int i=1;i<=HorSize;i++)
	{
		for(int j=1;j<=VerSize;j++)
		{
			if(Num[i][j]==0)
			{
				button0[i][j].Draw();
				
			}
			if(Num[i][j]==1)
			{
				button1[i][j].Draw();
				
			}
			if(Num[i][j]==2)
			{
				button2[i][j].Draw();
				
			}
			if(Num[i][j]==3)
			{
				button3[i][j].Draw();
				
			}
/*			if(Num[i][j]==-1)
			{
				blank[i][j].Draw();
				
			}
*/			
		}
	}
	return 1;
}

/******************************************************************************/ 
void setpositionPlay()
{	p=pW+Position(0.5,0.5);
		ybh=blueH[1][1].GetHeight();
	      xbh=blueH[1][1].GetWidth();
	      ybv=blueV[1][1].GetHeight();
		 xbv=blueV[1][1].GetWidth();
	      yc =circ.GetHeight();
	      xc =circ.GetWidth();
	Position p3;
	Position p1;
	Position p2=p+Position(0,yc+0.1);
	for(int i=1;i<=HorSize+1;i++)
	{
		circ.SetPosition(p);
		circ.Draw();
		p1=p;
		for(int j=1;j<=VerSize+1;j++)
		{	p1=p1+Position(xc+0.1,0);
			p3=p1+Position(0,ybh+0.1);
			if(j<VerSize+1)
			{
			blueH[i][j].SetPosition(p1);
			greyH[i][j].SetPosition(p1);
			crossH[i][j].SetPosition(p1);
			
			button1[i][j].SetPosition(p3);
			button2[i][j].SetPosition(p3);
			button3[i][j].SetPosition(p3);
			button0[i][j].SetPosition(p3);
			blank[i][j].SetPosition(p3);
			}
			if(i<HorSize+1)
			{
			blueV[i][j].SetPosition(p2);
			greyV[i][j].SetPosition(p2);
			crossV[i][j].SetPosition(p2);
			}
			p2=p2+Position(xbv+0.1+xbh+0.1,0);
			p1=p1+Position(xbh+0.1,0);
			
			if(j<VerSize+1)
			{
			circ.SetPosition(p1);
			circ.Draw();
			}
		}
		p=p+Position(0,yc+0.1+xbh+0.1);
		
		p2=p2+Position(-(xbv+0.1+xbh+0.1)*(VerSize+1),yc+0.2+xbh);
	}
}
/*******************************************************************************/
int MouseClickEventPlay(const Position &MousePosition)
{
	for(int i=1;i<=HorSize+1;i++)
	{	
		for(int j=1;j<=VerSize+1;j++)
		{	
			if(j<VerSize+1)
			{
			if(blueH[i][j].IsInside(MousePosition) ||greyH[i][j].IsInside(MousePosition) ||crossH[i][j].IsInside(MousePosition))
			{
				if (statusH[i][j]==0)
				{	
					blueH[i][j].Erase();
					statusH[i][j]=-1;
					crossH[i][j].Draw();
					
				}
				else if (statusH[i][j]==-1)
				{	
					crossH[i][j].Erase();
					statusH[i][j]=1;
					greyH[i][j].Draw();
				}
				else
				{
					greyH[i][j].Erase();
					statusH[i][j]=0;
					blueH[i][j].Draw();
				}
			}
			}
			if(i<HorSize+1)
			{
			if(blueV[i][j].IsInside(MousePosition) ||greyV[i][j].IsInside(MousePosition) ||crossV[i][j].IsInside(MousePosition))
			{
				if (statusV[i][j]==0)
				{	
					blueV[i][j].Erase();
					statusV[i][j]=-1;
					crossV[i][j].Draw();
					
				}
				else if (statusV[i][j]==-1)
				{	
					crossV[i][j].Erase();
					statusV[i][j]=1;
					greyV[i][j].Draw();
				}
				else
				{
					greyV[i][j].Erase();
					statusV[i][j]=0;
					blueV[i][j].Draw();
				}
			}
			}
		}
 	}
 	if(VButton.IsInside(MousePosition))
 	{
 		verifyButton();
 	}
 	if(NewpuzzleButton.IsInside(MousePosition))
 	{	
 		newpuzz();
 	}
 	if(ResetButton.IsInside(MousePosition))
 	{
 		resetButton();
 	}
 	if(MMenuButton.IsInside(MousePosition))
 	{
 		mainMenu();
 	}
 	if(SolutionButton.IsInside(MousePosition))
 	{
 		solution();
 		
 	}
 	return 1;	
 }
 	
 

 
int DisplayGridInitial()
{
	
	
	for(int i=1;i<=HorSize+1;i++)
	{
		for(int j=1;j<=(VerSize+1);j++)
		{
			if(j<VerSize+1)
			{
				blueH[i][j].Draw();
				crossH[i][j].Draw();
				greyH[i][j].Draw();
				
			}
			if(i<HorSize+1)
			{
				blueV[i][j].Draw();
				crossV[i][j].Draw();
				greyV[i][j].Draw();
			}
		}			
	}
	return 1;
}	

/******************************************************************************/
int DisplayGridSolution()//displays gridsolution
{
	for(int i=1;i<=HorSize+1;i++)
	{
		for(int j=1;j<=(VerSize+1);j++)
		{
			if(j<VerSize+1)
			{
			if(hLines[i][j]==0)
			{
			blueH[i][j].Draw();
			}
			else
			{
			crossH[i][j].Erase();
			greyH[i][j].Erase();
			blueH[i][j].Erase();			
			}
			}
			if(i<HorSize+1)
			{
			if(vLines[i][j]==0)
			{
			blueV[i][j].Draw();
			}
			else
			{
			crossV[i][j].Erase();
			greyV[i][j].Erase();
			blueV[i][j].Erase();
			}
			}
		}			
	}
	return 1;
}	




