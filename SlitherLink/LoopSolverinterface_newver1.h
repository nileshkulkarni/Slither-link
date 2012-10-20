
Position pW(1,1);

SimpleWindow loopsolverDisplay("Slither Link ",20,20,pW);

	BitMap greyH[17][17];
	BitMap blueH[17][17];
	BitMap crossH[17][17];
	int statusH[17][17];

	BitMap greyV[17][17];
	BitMap blueV[17][17];
	BitMap crossV[17][17];
	int statusV[17][17];
	
	BitMap enter;
	BitMap zero;
	BitMap eraser;
	BitMap one;
	BitMap two;
	BitMap three;
	BitMap blueblank;
	BitMap object_num[17][17];
	
	BitMap nextpuzzle(loopsolverDisplay);
	BitMap MainMenu(loopsolverDisplay);
	int clickstatus;
	 int i_assign=0,j_assign=0;
	Position pacc;
	Position p;
	int Num[17][17];
	float xbv;
	float xbh;
	float ybv;
	float ybh;
	float yc;
	float xc;					
 BitMap circ(loopsolverDisplay);
 int HorSize,VerSize;
 //m=height
 //n=width
/******************************************************************************/
 int AssignValuesloop() //This function is always executted at the start of the program to initialize objects
{	
	circ.Load("circle.xpm");
	for(int k=1;k<17;k++)
	{
		for(int l=1;l<17;l++)
		{
			greyH[k][l].SetWindow(loopsolverDisplay);
			blueH[k][l].SetWindow(loopsolverDisplay);
			crossH[k][l].SetWindow(loopsolverDisplay);
			greyV[k][l].SetWindow(loopsolverDisplay);
			blueV[k][l].SetWindow(loopsolverDisplay);
			crossV[k][l].SetWindow(loopsolverDisplay);
			object_num[k][l].SetWindow(loopsolverDisplay);
		}
	}
	//height=height+1;
	//width++;
	 enter.SetWindow(loopsolverDisplay);
	 zero.SetWindow(loopsolverDisplay);
	 eraser.SetWindow(loopsolverDisplay);
	 one.SetWindow(loopsolverDisplay);
	 two.SetWindow(loopsolverDisplay);
	 three.SetWindow(loopsolverDisplay);
	 blueblank.SetWindow(loopsolverDisplay);
	for(int i=1;i<=HorSize+1;i++)
	{
		for(int j=1;j<=VerSize+1;j++)
		{	if(j<VerSize+1)
			{
				greyH[i][j].Load("greyhor.xpm");
				blueH[i][j].Load("bluehor.xpm");
				crossH[i][j].Load("crosshor.xpm");
				
			}
			if(i<HorSize+1)
			{
				greyV[i][j].Load("greyver.xpm");
				blueV[i][j].Load("bluever.xpm");
				crossV[i][j].Load("crossver.xpm");
			}
		}
	
	
	}
	blueblank.Load("blue.xpm");
	one.Load("one.xpm");
	zero.Load("zero.xpm");
	two.Load("two.xpm");
	three.Load("three.xpm");
	eraser.Load("eraser.xpm");
	enter.Load("getsoln.xpm");
	nextpuzzle.Load("newpuzzle.xpm");
	MainMenu.Load("mainmenu.xpm");
	return 1;
}

/******************************************************************************/ 
void setpositionloop()//This function must be executed imediately after the assign value function 
{	//m1++;
	//n1++;
	p=pW+Position(1,1);
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
		for(int j=1;j<=(VerSize+1);j++)
		{	p1=p1+Position(xc+0.1,0);
			p3=p1+Position(0,ybh+0.1);
			if(j<VerSize+1)
			{
			blueH[i][j].SetPosition(p1);
			greyH[i][j].SetPosition(p1);
			crossH[i][j].SetPosition(p1);
			
			object_num[i][j].SetPosition(p3);
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
		p=p+Position(0,yc+0.1+ybv+0.1);
		
		p2=p2+Position(-(xbv+0.1+xbh+0.1)*(VerSize+1),yc+0.2+ybv);
	}
	
	
}
/******************************************************************************/


Position numpos;
float Breakdis=3;
int displayProblemAcceptor()//displays the problem acceptor screen.
{	float one_sizex=one.GetWidth();
	float one_sizey=one.GetHeight();
	float enter_sizey=enter.GetHeight();
	numpos=Position(blueH[1][VerSize].GetXPosition()+xbh+0.2+Breakdis,blueH[1][VerSize].GetYPosition());
	object_num[1][2].Load("one.xpm");
	object_num[1][2].Draw();	
	for(int i=1;i<=HorSize+1;i++)
	{
		for(int j=1;j<=VerSize+1;j++)
		{	if(j<VerSize+1)
		{	
			object_num[i][j].Load("blank.xpm");
			Position p10=blueH[i][j].GetPosition()+Position(0,ybh+0.1);
			object_num[i][j].SetPosition(p10);
			object_num[i][j].Draw();
		}
		}
	}
	zero.SetPosition(numpos);
	numpos=numpos+Position(0,one_sizey+0.2);
	one.SetPosition(numpos);
	numpos=numpos+Position(0,one_sizey+0.2);
	two.SetPosition(numpos);
	numpos=numpos+Position(0,one_sizey+0.2);
	three.SetPosition(numpos);
	numpos=numpos+Position(0,one_sizey+0.2);
	eraser.SetPosition(numpos);
	numpos=numpos+Position(0,enter_sizey+0.2);
	enter.SetPosition(numpos);
	numpos=numpos+Position(0,enter_sizey+0.2);
	nextpuzzle.SetPosition(numpos);
	numpos=numpos+Position(0,enter_sizey+0.2);
	MainMenu.SetPosition(numpos);
	zero.Draw();
	one.Draw();
	two.Draw();
	three.Draw();
	eraser.Draw();
	enter.Draw();
	nextpuzzle.Draw();
	MainMenu.Draw();
	return 1;
}
/*******************************************************************************/
int MouseAcceptor(const Position &MousePosition)//action on mouseclicks
{   

	   
        if(enter.IsInside(MousePosition))
	 {	clickstatus=1;
 	 	solutionloop();
 		return 1;

 	 }
 	 if(nextpuzzle.IsInside(MousePosition))
       	{	clickstatus=1;
  		nextpuzz();
 		return 1;

 	}
 	if(MainMenu.IsInside(MousePosition))
	 {	clickstatus=1;
		Mainmenu();
 		return 1;

 	}        

    
    if(clickstatus==1)
    {
    for(int i=1;i<HorSize+1;i++)
    {
    	for(int j=1;j<VerSize+1;j++)
    	{
		 
			if(object_num[i][j].IsInside(MousePosition))
			{		
				p=object_num[i][j].GetPosition();
				blueblank.SetPosition(p);
				blueblank.Draw();
				i_assign=i;
				j_assign=j;
				clickstatus=2;
				return 1;	
			}
			
		}
    	 }
	}
    	else if(clickstatus==2)
    	{	
    		if(zero.IsInside(MousePosition))
		{	blueblank.Erase();
			object_num[i_assign][j_assign].Load("zero.xpm");
			
			Position p10=blueH[i_assign][j_assign].GetPosition()+Position(0,ybh+0.1);
			object_num[i_assign][j_assign].SetPosition(p10);
			object_num[i_assign][j_assign].Draw();
			Num[i_assign][j_assign]=0;
			clickstatus=1;
			return 1;

		}
		if(one.IsInside(MousePosition))
		 {	blueblank.Erase();
			object_num[i_assign][j_assign].Load("one.xpm");
			Position p10=blueH[i_assign][j_assign].GetPosition()+Position(0,ybh+0.1);
			object_num[i_assign][j_assign].SetPosition(p10);
			object_num[i_assign][j_assign].Draw();
			Num[i_assign][j_assign]=1;
			clickstatus=1;
			return 1;

                 }    
		if(two.IsInside(MousePosition))
		 {	blueblank.Erase();
		 	object_num[i_assign][j_assign].Load("two.xpm");
		 	Position p10=blueH[i_assign][j_assign].GetPosition()+Position(0,ybh+0.1);
			object_num[i_assign][j_assign].SetPosition(p10);
			object_num[i_assign][j_assign].Draw();
			Num[i_assign][j_assign]=2;
			clickstatus=1;
			return 1;

                 }                    
                 if(three.IsInside(MousePosition))
		 {	blueblank.Erase();
		 	object_num[i_assign][j_assign].Load("three.xpm");
		 	Position p10=blueH[i_assign][j_assign].GetPosition()+Position(0,ybh+0.1);
			object_num[i_assign][j_assign].SetPosition(p10);
		 	object_num[i_assign][j_assign].Draw();
		 	Num[i_assign][j_assign]=3;
			clickstatus=1;
			return 1;

                 }                                        
                 if(eraser.IsInside(MousePosition))
		 {	blueblank.Erase();
			object_num[i_assign][j_assign].Load("blank.xpm");
		 	Position p10=blueH[i_assign][j_assign].GetPosition()+Position(0,ybh+0.1);
			object_num[i_assign][j_assign].SetPosition(p10);
		 	object_num[i_assign][j_assign].Draw();
			Num[i_assign][j_assign]=-1;
			clickstatus=1;
			return 1;
                 }
              }
return 1;
}

int DisplayGridInitial()//displays grey grid .
{
	//m=m+1;
	//n=n+1;
	for(int i=1;i<=HorSize+1;i++)
	{
		for(int j=1;j<=(VerSize+1);j++)
		{
			if(j<VerSize+1)
			greyH[i][j].Draw();
			if(i<HorSize+1)
			greyV[i][j].Draw();
		}			
	}
	return 1;
}	
/*******************************************************************************/
int DisplayGridSolution()//displays gridsolution
{
	//m=m+1;
	//n=n+1;
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


