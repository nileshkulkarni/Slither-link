void Loop::Solve() {
     int i, j, k;
     NumLeft=0;
     for (i=1;i<=HorSize;i++) for (j=1;j<=VerSize;j++) if (GridVal[i][j]>0) NumLeft++;
     diffic=0; solns=0;
     
     for (i=1; i<=HorSize; i++) for (j=1; j<=VerSize; j++){
         if (GridVal[i][j]==0) {
            HorCross(i-1,j);
            VerCross(i,j);
            HorCross(i,j);
            VerCross(i,j-1);
         }
     }
     
     if (diff>0 && cons && Solved()!=0) {
        diffic=diff;
        for (i=1; i<=HorSize; i++) {
            if (VerLine[i][0]!=1) if (GridReg[i][1]!=2*VerLine[i][0]+1) SetReg(i, 1, 2*VerLine[i][0]+1);
            if (VerLine[i][VerSize]!=1) if (GridReg[i][VerSize]!=2*VerLine[i][VerSize]+1) SetReg(i, VerSize, 2*VerLine[i][VerSize]+1);
        }
        
        for (j=1; j<=VerSize; j++) {
            if (HorLine[0][j]!=1) if (GridReg[1][j]!=2*HorLine[0][j]+1) SetReg(1,j,2*HorLine[0][j]+1);
            if (HorLine[HorSize][j]!=1) if (GridReg[HorSize][j]!=2*HorLine[HorSize][j]+1) SetReg(HorSize,j,2*HorLine[HorSize][j]+1);
        }
        
        //Coupling
        for (i=0; i<=HorSize; i++) {
            for (j=0; j<=VerSize; j++) {
                if (VertCer[i][j]!=2) if (VertImp[i][j]!=4) {
                   for (k=0; k<4; k++) if (HorLine[i][j+hadd(k)]==-1 && VerLine[i+vadd(k)][j]==-1) Couple(i, j, k%2);
                }
            }
        }
        
        //Setting Min1 and Max1
        for (i=1; i<=HorSize; i++) {
            for (j=1; j<=VerSize; j++) {
               if (GridCer[i][j]==GridVal[i][j]-1) {
                  if (HorLine[i-1][j]==1) {
                     if (VerLine[i][j-1]==1) SetMax(i-1,j-1,2);
                     if (VerLine[i][j]==1) SetMax(i-1,j,3);
                  }
                  
                  if (HorLine[i][j]==1) {
                     if (VerLine[i][j-1]==1) SetMax(i,j-1,1);
                     if (VerLine[i][j]==1) SetMax(i,j,0);
                  }
               }
               
               if (GridImp[i][j]==3-GridVal[i][j]) {
                  if (HorLine[i-1][j]==1) {
                     if (VerLine[i][j-1]==1) SetMin(i-1,j-1,2);
                     if (VerLine[i][j]==1) SetMin(i-1,j,3);
                  }
                  
                  if (HorLine[i][j]==1) {
                     if (VerLine[i][j-1]==1) SetMin(i,j-1,1);
                     if (VerLine[i][j]==1) SetMin(i,j,0);
                  }
               }
            }
        }
     }
     
     if (diffic==2) GuessSolve();
     
     else if (Solved()==0) {
        solns++;
        for (i=1; i<17; i++) for (j=1; j<17; j++) {hLines[i][j]=HorLine[i-1][j]; vLines[i][j]=VerLine[i][j-1];}
     }
}

void Loop::GuessSolve() {
     int i, j, bi, bj;
     while (cons && Solved()!=0) {
           bi=-1;
           for (i=0; i<=HorSize; i++) for (j=1; j<=VerSize; j++) if (HorLine[i][j]==1) {bi=i; bj=j;}
           if (bi==-1) break;
           Guess (*this, bi, bj);
           if (solns>1) break;
           sHorCross(bi,bj);
     }
     
     if (Solved()==0) {
        solns++;
        for (i=1; i<17; i++) for (j=1; j<17; j++) {hLines[i][j]=HorLine[i-1][j]; vLines[i][j]=VerLine[i][j-1];}
     }
}     
