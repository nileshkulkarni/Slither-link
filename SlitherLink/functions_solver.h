void Queue(int type, int i, int j, int k) {
     if (!Queued[type][i][j][k]) {
        typeQueue[nQueued]=type;
        iQueue[nQueued]=i;
        jQueue[nQueued]=j;
        kQueue[nQueued]=k;
        Queued[type][i][j][k]=true;
        nQueued++;
     }
}     

int dirH(int k) {
    if (k==1) return 1;
    else if (k==3) return (-1);
    else return 0;
}

int dirV(int k) {
    if (k==0) return (-1);
    else if (k==2) return 1;
    else return 0;
}

int hadd(int k) {
    if (k==0 || k==3) return 0;
    else return 1;
}

int vadd(int k) {
    if (k==0 || k==1) return 0;
    else return 1;
}

void Loop::Clear() {
     int i,j,k;
     for (i=0; i<17; i++) for (j=0; j<17; j++){
                                              HorLine[i][j] = VerLine[i][j] = -1;
                                              GridVal[i][j] = -1;
                                              VertImp[i][j] = GridImp[i][j] = 4;
                                              VertCer[i][j] = GridCer[i][j] = 0;
                                              GridReg[i][j] = -1;
                                              Coupled[i][j] = -1;
                                              LoopNumber[i][j]=0;
                                              for (k=0; k<4; k++) Max1[i][j][k] = Min1[i][j][k] = false;
                                              }
     empty=true; cons=true;
     maxSegNum=0;
}

Loop::Loop (void) {Clear();}

void Loop::HorDark (int i, int j) {
     int u;
     if (HorLine[i][j]==1) if (cons) {
        if (empty) empty=false;
        VertCer[i][j]++;
        VertCer[i][j-1]++;
        GridCer[i][j]++;
        GridCer[i+1][j]++;

        HorLine[i][j]=0;
        
        if (GridCer[i][j]==GridVal[i][j]) NumLeft--;
        if (GridCer[i+1][j]==GridVal[i+1][j]) NumLeft--;
        
        if (VertCer[i][j]==3 || VertCer[i][j-1]==3) cons=false;
        else if (GridVal[i][j]!=-1) {if (GridCer[i][j]>GridVal[i][j]) cons=false;}
        else if (GridVal[i+1][j]!=-1) {if (GridCer[i+1][j]>GridVal[i+1][j]) cons=false;}
        
        if (VertCer[i][j-1]==1) {
           if (VertCer[i][j]==1) {
              maxSegNum++;
              LoopNumber[i][j]=LoopNumber[i][j-1]=maxSegNum;
           }
        
           else Convert(i,j-1,1);
        }
     
        else if (LoopNumber[i][j]==LoopNumber[i][j-1]) {if (Solved()!=0) cons=false;}
        else Convert (i,j,3);
        
        for (u=0; u<2; u++) {
            if (VertCer[i][j-u]==2) {
               HorCross(i,j+1-u);
               HorCross(i,j-u);
               VerCross(i+1,j-u);
               VerCross(i,j-u);
            }
            
            else if (VertImp[i][j-u]==2) {
                 HorDark(i,j+1-u);
                 HorDark(i,j-u);
                 VerDark(i+1,j-u);
                 VerDark(i,j-u);
            }
            
            if (GridCer[i+u][j]==GridVal[i+u][j]) {
               HorCross(i+u-1,j);
               HorCross(i+u,j);
               VerCross(i+u,j-1);
               VerCross(i+u,j);
            }
            
            if (diffic>0) {
               if (GridReg[i+u][j]==0 && GridReg[i+1-u][j]!=0) SetReg(i+u,j,-GridReg[i+1-u][j]);
               if (Coupled[i][j-u]!=-1) sVerDark(i+Coupled[i][j-u]*(1-2*u)+u, j-u);
            }
        }
        
        if (diffic>0) {
           if (GridCer[i][j]==GridVal[i][j]-1) if (HorLine[i-1][j]==1) {
              if (VerLine[i][j-1]==1) Queue(2,i-1,j-1,2);
              if (VerLine[i][j]==1) Queue(2,i-1,j,3);
           }
           
           if (GridCer[i+1][j]==GridVal[i+1][j]-1) if (HorLine[i+1][j]==1) {
              if (VerLine[i+1][j-1]==1) Queue(2,i+1,j-1,1);
              if (VerLine[i+1][j]==1) Queue(2,i+1,j,0);
           }
           
           for (u=0;u<4;u++) {
               if (Max1[i][j-hadd(u)][u]) sVerCross(i+vadd(u),j-hadd(u));
               if (VerLine[i+vadd(u)][j-hadd(u)]==-1) {
                  Queue(1,i, j-hadd(u), (u+2)%4);
                  Queue(2,i, j-hadd(u), (u+2)%4);
               }
           }
        }
     }
}

void Loop::VerDark (int i, int j) {
     int u;
     if (VerLine[i][j]==1) if (cons){
        if (empty) empty=false;
        VertCer[i][j]++;
        VertCer[i-1][j]++;
        GridCer[i][j]++;
        GridCer[i][j+1]++;
        
        VerLine[i][j]=0;
        
        if (GridCer[i][j]==GridVal[i][j]) NumLeft--;
        if (GridCer[i][j+1]==GridVal[i][j+1]) NumLeft--;
        
        if (VertCer[i][j]==3 || VertCer[i-1][j]==3) cons=false;
        else if (GridVal[i][j]!=-1) {if (GridCer[i][j]>GridVal[i][j]) cons=false;}
        else if (GridVal[i][j+1]!=-1) {if (GridCer[i][j+1]>GridVal[i][j+1]) cons=false;}
        
        if (VertCer[i-1][j]==1) {
           if (VertCer[i][j]==1) {
              maxSegNum++;
              LoopNumber[i][j]=LoopNumber[i-1][j]=maxSegNum;
           }
        
           else Convert(i-1,j,2);
        }
     
        else if (LoopNumber[i][j]==LoopNumber[i-1][j]) {if (Solved()!=0) cons=false;}
        else Convert (i,j,0);
        
        for (u=0; u<2; u++) {
            if (VertCer[i-u][j]==2) {
               VerCross(i+1-u,j);
               VerCross(i-u,j);
               HorCross(i-u,j+1);
               HorCross(i-u,j);
            }
            
            else if (VertImp[i-u][j]==2) {
                 VerDark(i+1-u,j);
                 VerDark(i-u,j);
                 HorDark(i-u,j+1);
                 HorDark(i-u,j);
            }
            
            if (GridCer[i][j+u]==GridVal[i][j+u]) {
               VerCross(i,j+u-1);
               VerCross(i,j+u);
               HorCross(i-1,j+u);
               HorCross(i,j+u);
            }
            
            if (diffic>0) {
               if (GridReg[i][j+u]==0 && GridReg[i][j+1-u]!=0) SetReg(i,j+u,-GridReg[i][j+1-u]);
               if (Coupled[i-u][j]!=-1) sHorDark(i-u, j+Coupled[i-u][j]*(1-2*u)+u);
            }
        }
        
        if (diffic>0) {
           if (GridCer[i][j]==GridVal[i][j]-1) if (VerLine[i][j-1]==1) {
              if (HorLine[i-1][j]==1) Queue(2,i-1,j-1,2);
              if (HorLine[i][j]==1) Queue(2,i,j-1,1);
           }
           
           if (GridCer[i][j+1]==GridVal[i][j+1]-1) if (VerLine[i][j+1]==1)  {
              if (HorLine[i-1][j+1]==1) Queue(2,i-1,j+1,3);
              if (HorLine[i][j+1]==1) Queue(2,i,j+1,0);
           }
           
           for (u=0;u<4;u++) {
               if (Max1[i-vadd(u)][j][u]) sHorCross(i-vadd(u),j+hadd(u));
               if (HorLine[i-vadd(u)][j+hadd(u)]==-1) {
                  Queue(1,i-vadd(u), j, (u+2)%4);
                  Queue(2,i-vadd(u), j, (u+2)%4);
               }
           }
        }
     }
}

void Loop::HorCross (int i, int j) {
     int u;
     if (HorLine[i][j]==1) if (cons) {
        VertImp[i][j]++;
        VertImp[i][j-1]++;
        GridImp[i][j]++;
        GridImp[i+1][j]++;
        
        HorLine[i][j]=-1;
        if (GridImp[i][j]>4-GridVal[i][j] || GridImp[i+1][j]>4-GridVal[i+1][j]) cons=false;
        
        for (u=0; u<2; u++) {
            if (GridImp[i+u][j]==4-GridVal[i+u][j]) {
               HorDark(i+u-1,j);
               HorDark(i+u,j);
               VerDark(i+u,j-1);
               VerDark(i+u,j);
            }
            
            if (diffic>0) {
               if (GridReg[i+u][j]==0 && GridReg[i+1-u][j]!=0) SetReg(i+u, j, GridReg[i+1-u][j]);
               if (Coupled[i][j-u]!=-1) sVerCross(i+Coupled[i][j-u]*(1-2*u)+u, j-u);
            }
            
            if (VertImp[i][j-u]==3) {
               HorCross(i,j+1-u);
               HorCross(i,j-u);
               VerCross(i+1,j-u);
               VerCross(i,j-u);
            }
            
            else if (VertImp[i][j-u]==2) {
                 if (VertCer[i][j-u]==1) {
                    HorDark(i,j+1-u);
                    HorDark(i,j-u);
                    VerDark(i+1,j-u);
                    VerDark(i,j-u);
                 }
                 
                 else if (diffic>0) if (VertCer[i][j-u]==0) {
                      if (VerLine[i][j-u]==-1) Queue(0,i,j-u,u);
                      if (VerLine[i+1][j-u]==-1) Queue(0,i,j-u,1-u);
                 }
            }
        }
        
        if (diffic>0) {
           if (GridVal[i][j]!=-1) if (GridImp[i][j]==3-GridVal[i][j]) if (HorLine[i-1][j]==1) {
              if (VerLine[i][j-1]==1) Queue(1,i-1,j-1,2);
              if (VerLine[i][j]==1) Queue(1,i-1,j,3);
           }
           
           if (GridVal[i+1][j]!=-1) if (GridImp[i+1][j]==3-GridVal[i+1][j]) if (HorLine[i+1][j]==1) {
              if (VerLine[i+1][j-1]==1) Queue(1,i+1,j-1,1);
              if (VerLine[i+1][j]==1) Queue(1,i+1,j,0);
           }
           
           for (u=0;u<4;u++) {
               if (Min1[i][j-hadd(u)][u]) sVerDark(i+vadd(u),j-hadd(u));
               if (VerLine[i+vadd(u)][j-hadd(u)]==0) {
                  Queue(1,i, j-hadd(u), (u+2)%4);
                  Queue(2,i, j-hadd(u), (u+2)%4);
               }
           }
        }
     }
}

void Loop::VerCross (int i, int j) {
     int u;
     if (VerLine[i][j]==1) if (cons) {
        VertImp[i][j]++;
        VertImp[i-1][j]++;
        GridImp[i][j]++;
        GridImp[i][j+1]++;
        
        VerLine[i][j]=-1;
        if (GridImp[i][j]>4-GridVal[i][j] || GridImp[i][j+1]>4-GridVal[i][j+1]) cons=false;
        
        for (u=0; u<2; u++) {
            if (GridImp[i][j+u]==4-GridVal[i][j+u]) {
               VerDark(i,j+u-1);
               VerDark(i,j+u);
               HorDark(i-1,j+u);
               HorDark(i,j+u);
            }
            
            if (diffic>0){
               if (GridReg[i][j+u]==0 && GridReg[i][j+1-u]!=0) SetReg(i,j+u,GridReg[i][j+1-u]);
               if (Coupled[i-u][j]!=-1) sHorCross(i-u, j+Coupled[i-u][j]*(1-2*u)+u);
            }
            
            if (VertImp[i-u][j]==3) {
               VerCross(i+1-u,j);
               VerCross(i-u,j);
               HorCross(i-u,j+1);
               HorCross(i-u,j);
            }
            
            else if (VertImp[i-u][j]==2) {
                 if (VertCer[i-u][j]==1) {
                    VerDark(i+1-u,j);
                    VerDark(i-u,j);
                    HorDark(i-u,j+1);
                    HorDark(i-u,j);
                 }
                 
                 else if (diffic>0) if (VertCer[i-u][j]==0) {
                      if (HorLine[i-u][j]==-1) Queue(0,i-u,j,u);
                      if (HorLine[i-u][j+1]==-1) Queue(0,i-u,j,1-u);
                 }
            }
        }
        
        if (diffic>0) {
           if (GridVal[i][j]!=-1) if (GridImp[i][j]==3-GridVal[i][j]) if (VerLine[i][j-1]==1) {
              if (HorLine[i-1][j]==1) Queue(1,i-1,j-1,2);
              if (HorLine[i][j]==1) Queue(1,i,j-1,1);
           }
           
           if (GridVal[i][j+1]!=-1) if (GridImp[i][j+1]==3-GridVal[i][j+1]) if (VerLine[i][j+1]==1) {
              if (HorLine[i-1][j+1]==1) Queue(1,i-1,j+1,3);
              if (HorLine[i][j+1]==1) Queue(1,i,j+1,0);
           }
           
           for (u=0;u<4;u++) {
               if (Min1[i-vadd(u)][j][u]) sHorDark(i-vadd(u),j+hadd(u));
               if (HorLine[i-vadd(u)][j+hadd(u)]==0) {
                  Queue(1,i-vadd(u), j, (u+2)%4);
                  Queue(2,i-vadd(u), j, (u+2)%4);
               }
           }
        }
     }
}

void Loop::HorGrey (int i, int j) {
     if (HorLine[i][j]==0) {
        VertCer[i][j]--;
        VertCer[i][j-1]--;
        GridCer[i][j]--;
        GridCer[i+1][j]--;
     }

     else if (HorLine[i][j]==-1){
        VertImp[i][j]--;
        VertImp[i][j-1]--;
        GridImp[i][j]--;
        GridImp[i+1][j]--;
     }
        
     HorLine[i][j]=1;
}

void Loop::VerGrey (int i, int j) {
     if (VerLine[i][j]==0) {
        VertCer[i][j]--;
        VertCer[i-1][j]--;
        GridCer[i][j]--;
        GridCer[i][j+1]--;
     }
     
     if (VerLine[i][j]==-1){
        VertImp[i][j]--;
        VertImp[i-1][j]--;
        GridImp[i][j]--;
        GridImp[i][j+1]--;
     }
        
     VerLine[i][j]=1;
}
     
void Loop::SetSize () {
     int i,j;
     for (i=0; i<=HorSize; i++) for (j=1; j<=VerSize; j++) HorGrey(i,j);
     for (i=1; i<=HorSize; i++) for (j=0; j<=VerSize; j++) VerGrey(i,j);
     for (i=1; i<=HorSize; i++) for (j=1; j<=VerSize; j++) GridReg[i][j]=0;
}
 
void Loop::Couple (int i, int j, int v) {
     if (cons) if (VertCer[i][j]+VertImp[i][j]!=4) {
        if (Coupled[i][j]==-1) {
           Coupled[i][j]=v;
           
           if (HorLine[i][j]==0) sVerDark(i+v,j);
           else if (HorLine[i][j+1]==0) sVerDark(i+1-v,j);
           else if (VerLine[i+v][j]==0) sHorDark(i,j);
           else if (VerLine[i+1-v][j]==0) sHorDark(i,j+1);
           
           if (HorLine[i][j]==-1) sVerCross(i+v,j);
           if (HorLine[i][j+1]==-1) sVerCross(i+1-v,j);
           if (VerLine[i+v][j]==-1) sHorCross(i,j);
           if (VerLine[i+1-v][j]==-1) sHorCross(i,j+1);
           
           if (Max1[i][j][v]) {sHorCross(i,j+hadd(v)); sVerCross(i+vadd(v),j);}
           if (Min1[i][j][v]) {sHorDark(i,j+hadd(v)); sVerDark(i+vadd(v),j);}
           if (Max1[i][j][v+2]) {sHorCross(i,j+hadd(v+2)); sVerCross(i+vadd(v+2),j);}
           if (Min1[i][j][v+2]) {sHorDark(i,j+hadd(v+2)); sVerDark(i+vadd(v+2),j);}
           
           if (GridVal[i][j+v]==2) {
              Couple (i-1, j+2*v-1, v);
              SetMax(i-1+v, j+v, 3-v); SetMin(i-1+v, j+v, 3-v);
           }
           
           if (GridVal[i+1][j+1-v]==2) {
              Couple (i+1, j-2*v+1, v);
              SetMax(i+v, j-v+1, 3-v); SetMin(i+v, j-v+1, 3-v);
           }
           
           SetMax(i,j,1-v);
           SetMax(i,j,3-v);
        }
        
        else if (Coupled[i][j]==1-v) {
             sHorCross(i, j);
             sVerCross(i, j);
             sHorCross(i, j+1);
             sVerCross(i+1, j);
        }
     }
}

void Loop::SetMin(int i, int j, int k) {
     if (HorLine[i][j+hadd(k)]!=0 && VerLine[i+vadd(k)][j]!=0) if (cons) {
        if (!Min1[i][j][k]) {
           Min1[i][j][k]=true;
           
           if (HorLine[i][j+hadd(k)]==-1) sVerDark(i+vadd(k),j);
           if (VerLine[i+vadd(k)][j]==-1) sHorDark(i,j+hadd(k));
           
           SetMax(i,j,(k+2)%4);
           if (Coupled[i][j]==k%2) {sHorDark(i,j+hadd(k)); sVerDark(i+vadd(k),j);}
           
           if (GridVal[i+vadd(k)][j+hadd(k)]==1) {sHorCross(i+2*vadd(k)-1, j+hadd(k)); sVerCross(i+vadd(k), j+2*hadd(k)-1);}
           else if (GridVal[i+vadd(k)][j+hadd(k)]==2) SetMax(i+2*vadd(k)-1, j+2*hadd(k)-1, (k+2)%4);
           
           if (Max1[i][j][k]) SetMin(i,j,(k+2)%4);
        }
     }
}
     
void Loop::SetMax(int i, int j, int k) {
     if (HorLine[i][j+hadd(k)]!=-1 && VerLine[i+vadd(k)][j]!=-1) if (cons) {
        if (!Max1[i][j][k]) {
           Max1[i][j][k]=true;

           if (HorLine[i][j+hadd(k)]==0) sVerCross(i+vadd(k),j);
           if (VerLine[i+vadd(k)][j]==0) sHorCross(i,j+hadd(k));
           
           if (Coupled[i][j]==k%2) {sHorCross(i,j+hadd(k)); sVerCross(i+vadd(k),j);}
           
           if (GridVal[i+vadd(k)][j+hadd(k)]==3) {sHorDark(i+2*vadd(k)-1, j+hadd(k)); sVerDark(i+vadd(k), j+2*hadd(k)-1);}
           else if (GridVal[i+vadd(k)][j+hadd(k)]==2) SetMin(i+2*vadd(k)-1, j+2*hadd(k)-1, (k+2)%4);
           
           if (Min1[i][j][k]) SetMin(i,j,(k+2)%4);
        }
     }
}

void Loop::sHorDark(int i, int j) {
     HorDark(i,j);
     if (HorLine[i][j]==-1) cons=false;
}

void Loop::sVerDark(int i, int j) {
     VerDark(i,j);
     if (VerLine[i][j]==-1) cons=false;
}

void Loop::sHorCross(int i, int j) {
    HorCross(i,j);
     if (HorLine[i][j]==0) cons=false;
}

void Loop::sVerCross(int i, int j) {
     VerCross(i,j);
     if (VerLine[i][j]==0) cons=false;
}

void Loop::SetReg (int i, int j, int k) {
     int u;
     if (cons) {
        GridReg[i][j]=k;
        
        for (u=0; u<2; u++) {
            if (GridReg[i - 2*u + 1][j]!=0) {
               if (GridReg[i - 2*u + 1][j]==k) HorCross(i-u,j);
               else HorDark(i-u,j);
            }
            
            else if (HorLine[i-u][j]!=1) SetReg (i-2*u+1, j, -k * (2*HorLine[i-u][j]+1));
            if (GridReg[i][j - 2*u + 1]!=0) {
               if (GridReg[i][j - 2*u + 1]==k) VerCross(i,j-u);
               else VerDark(i,j-u);
            }
            
            else if (VerLine[i][j-u]!=1) SetReg (i, j-2*u+1, -k * (2*VerLine[i][j-u]+1));
        }
     }
}

void Loop::Convert (int i, int j, int dir) {
     int newdir=-1, k;
     
     if (cons) {
        if (LoopNumber[i][j]!=0) {
            if (VerLine[i][j]==0) if (dir!=0) newdir=2;
            if (HorLine[i][j+1]==0) if (dir!=1) newdir=3;
            if (VerLine[i+1][j]==0) if (dir!=2) newdir=0;
            if (HorLine[i][j]==0) if (dir!=3) newdir=1;
        }
        
        LoopNumber[i][j]=LoopNumber[i+dirV(dir)][j+dirH(dir)];
        
        if (newdir==-1) {
           if (NumLeft!=0) {
              for (k=0; k<4; k++) if (VertCer[i+dirV(k)][j+dirH(k)]==1) if (LoopNumber[i+dirV(k)][j+dirH(k)]==LoopNumber[i][j]) newdir=k;
              
              if (newdir!=-1) {
                 k=0;
                 if (GridCer[i+vadd(newdir)][j+hadd(newdir)]==GridVal[i+vadd(newdir)][j+hadd(newdir)]-1) k++;
                 if (GridCer[i+hadd(newdir)][j+1-vadd(newdir)]==GridVal[i+hadd(newdir)][j+1-vadd(newdir)]-1) k++;
                 if (NumLeft!=k) {
                      if (newdir==0) VerCross(i,j);
                      if (newdir==1) HorCross(i,j+1);
                      if (newdir==2) VerCross(i+1,j);
                      if (newdir==3) HorCross(i,j);
                 }
                 
                 else if (NumLeft==2) {
                    if (newdir==0) VerDark(i,j);
                    if (newdir==1) HorDark(i,j+1);
                    if (newdir==2) VerDark(i+1,j);
                    if (newdir==3) HorDark(i,j);
                 }
              }
           }
        }
        
        else Convert (i-dirV(newdir), j-dirH(newdir), newdir);
     }
}

void Guess(Loop TempLoop, int i, int j) {
     TempLoop.HorDark(i,j);
     TempLoop.TwoLineSet();
     TempLoop.GuessSolve();
}
