#include<iostream>
#include"ezwin.h"
#include"bitmap.h"
#include"assert.h"
#include<cstdio>
    Position  pw=Position(1,1);
    SimpleWindow sizewindow("Input Height & Width ",15.0,25.0,pw);
    BitMap header(sizewindow);
    BitMap htbutton(sizewindow);
    BitMap stdb(sizewindow);
    BitMap pro(sizewindow);
    BitMap ad(sizewindow);
     BitMap stdo(sizewindow);
    BitMap proo(sizewindow);
    BitMap ado(sizewindow);
    BitMap difc(sizewindow);
    BitMap wdbutton(sizewindow);
    BitMap enter(sizewindow);
    BitMap numw[11];
    BitMap numh[11];
    BitMap btnbluh[11];
    BitMap btnbluw[11];
int status,dif=-1;
Position p;int m1=1,n1=1;
using namespace std;
int mouseclick(const Position &mousepos)
    { int i,j;
    	
      if(enter.IsInside(mousepos))
       {
       		FILE *size;
       		size=fopen("GridSize","w");
       		if (m1==0) m1=7;
       		if (n1==0) n1=7;
       		fprintf(size,"%2d %2d %2d",m1,n1,dif);
       		sizewindow.Close();
       		return 1;
       	}
       	if(stdb.IsInside(mousepos))
       	{	
       		if(dif==0)
       		{	stdo.Erase();
       			stdb.Draw();
       		}
       		else if(dif==1)
       		{	ado.Erase();
       			ad.Draw();
       		}
       		else if(dif==2)
       		{	proo.Erase();
       			pro.Draw();
       		}
       		stdb.Erase();
       		dif=0;
       		stdo.Draw();
       	}
          if(ad.IsInside(mousepos))
       	{	
       		if(dif==0)
       		{	stdo.Erase();
       			stdb.Draw();
       		}
       		else if(dif==1)
       		{	ado.Erase();
       			ad.Draw();
       		}
       		else if(dif==2)
       		{	proo.Erase();
       			pro.Draw();
       		}
       		ad.Erase();
       		dif=1;
       		ado.Draw();
       	}
           if(pro.IsInside(mousepos))
       	{	
       		if(dif==0)
       		{	stdo.Erase();
       			stdb.Draw();
       		}
       		else if(dif==1)
       		{	ado.Erase();
       			ad.Draw();
       		}
       		else if(dif==2)
       		{	proo.Erase();
       			pro.Draw();
       		}
       		pro.Erase();
       		dif=2;
       		proo.Draw();
       	}
          for(i=3;i<=10;i++)
          {
             if(numh[i].IsInside(mousepos))
              {	      btnbluh[m1].Erase();
              		numh[m1].Draw();
                   p=numh[i].GetPosition();
                   btnbluh[i].SetPosition(p);
                   btnbluh[i].Draw();
                      status =0;
                      m1=i;
                      return 1;
                      
                }
         }
         for(i=3;i<=10;i++)
          {
             if(numw[i].IsInside(mousepos))
              {		btnbluw[n1].Erase();
              		numw[n1].Draw();		
                   p=numw[i].GetPosition();
                   btnbluw[i].SetPosition(p);
                   btnbluw[i].Draw();
                   
                    status =0;
                      n1=i;
                      return 1;
                }
         }
           
        
}
                                  
int ApiMain(){
 int i,j;   
    sizewindow.Open();
    m1=n1=status=0;
     for( i=3;i<=10;i++)
   {
    	btnbluh[i].SetWindow(sizewindow);
    	
    	btnbluw[i].SetWindow(sizewindow);
    	numh[i].SetWindow(sizewindow);
    	numw[i].SetWindow(sizewindow);
   } 
   stdb.Load("standard.xpm");
   stdo.Load("stdo.xpm");
   ad.Load("advanced.xpm");
   ado.Load("ado.xpm");
   pro.Load("pro.xpm");
   proo.Load("proo.xpm");
   difc.Load("difficulty.xpm");
   
    htbutton.Load("height.xpm");
    wdbutton.Load("width.xpm");    
    numw[3].Load("w3.xpm");
    numw[4].Load("w4.xpm");
    numw[5].Load("w5.xpm");
    numw[6].Load("w6.xpm");
    numw[7].Load("w7.xpm");
    numw[8].Load("w8.xpm");
    numw[9].Load("w9.xpm");
    numw[10].Load("w10.xpm");

    numh[3].Load("w3.xpm");
    numh[4].Load("w4.xpm");
    numh[5].Load("w5.xpm");
    numh[6].Load("w6.xpm");
    numh[7].Load("w7.xpm");
    numh[8].Load("w8.xpm");
    numh[9].Load("w9.xpm");
    numh[10].Load("w10.xpm");
    
    btnbluh[3].Load("b3.xpm");
    btnbluh[4].Load("b4.xpm");
    btnbluh[5].Load("b5.xpm");
    btnbluh[6].Load("b6.xpm");
    btnbluh[7].Load("b7.xpm");
    btnbluh[8].Load("b8.xpm");
    btnbluh[9].Load("b9.xpm");
    btnbluh[10].Load("b10.xpm");
    
     
    btnbluw[3].Load("b3.xpm");
    btnbluw[4].Load("b4.xpm");
    btnbluw[5].Load("b5.xpm");
    btnbluw[6].Load("b6.xpm");
    btnbluw[7].Load("b7.xpm");
    btnbluw[8].Load("b8.xpm");
    btnbluw[9].Load("b9.xpm");
    btnbluw[10].Load("b10.xpm");
   
   
 	float ystd,ydif;
    Position pnumh,pe,pnumw,pht,pwd,pdif;
    pht=pw+Position(1,3);
    htbutton.SetPosition(pht);
    float htx=htbutton.GetWidth();
    float hty=htbutton.GetHeight();
    float wdx=wdbutton.GetWidth();
    float wdy=wdbutton.GetHeight();
    float numx=numh[5].GetWidth();
    float numy=numh[5].GetHeight();
    ystd=stdb.GetHeight();
    ydif=difc.GetHeight();
    enter.Load("enter.xpm");
    
    
   
   pnumh=pw+Position(pht.GetXDistance()+0.5,pht.GetYDistance()-1);
    for( i=3;i<=10;i++)
    {
    	numh[i].SetPosition(pnumh);
    	pnumh=pnumh+Position(0,numy+0.2);
    }
    pwd=pw+Position(3,0);
    pnumw=pw+Position(hty-1,htx+0.2);
    
    wdbutton.SetPosition(pwd);
    for( i=3;i<=10;i++)
    {
    	numw[i].SetPosition(pnumw);
    	pnumw=pnumw+Position(numy+0.2,0);
    }
    float shift;
    shift=(difc.GetWidth()-stdb.GetWidth())/2;
    pe=Position(pwd.GetXDistance()+2.5*hty,pht.GetYDistance()+2 *hty);
 	enter.SetPosition(pe);
	pdif=numw[10].GetPosition()+Position(numx+1,0); 	
	difc.SetPosition(pdif);
	pdif=pdif+Position(shift,ydif+0.6);
	stdb.SetPosition(pdif);
	stdo.SetPosition(pdif);
	pdif=pdif+Position(0,ystd+0.6);
	ad.SetPosition(pdif);
	ado.SetPosition(pdif);
	pdif=pdif+Position(0,ystd+0.6);
	pro.SetPosition(pdif);
	proo.SetPosition(pdif);
	
	difc.Draw();
	stdb.Draw();
	
	ad.Draw();
		
	pro.Draw();
	
enter.Draw();
    wdbutton.Draw();
    htbutton.Draw();
    for(j=1;j<=10;j++)
    {
    	numh[j].Draw();
    	numw[j].Draw();
    }
    	
	sizewindow.SetMouseClickCallback(mouseclick);
}
     
             
