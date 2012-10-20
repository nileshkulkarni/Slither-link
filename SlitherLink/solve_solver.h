void Loop::Solve() {
     int i, j;
     NumLeft=0; nQueued=0; solns=0;
     for (i=1;i<=HorSize;i++) for (j=1;j<=VerSize;j++) if (GridVal[i][j]>0) NumLeft++;
     diffic=0;
     
     for (i=0; i<=HorSize+1; i++) {
     	for (j=0; j<=VerSize+1; j++) printf("%3d",GridVal[i][j]);
     	cout<<endl;
     }
     
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
     }
     
     if (diffic>0 && Solved()!=0) TwoLineSet();
     if (diffic==2) GuessSolve();
     
     else if (Solved()==0) {
        solns++;
        for (i=1; i<17; i++) for (j=1; j<17; j++) {hLines[i][j]=HorLine[i-1][j]; vLines[i][j]=VerLine[i][j-1];}
     }
}

void Loop::TwoLineSet() {
     int i, j, k, type;
     while (nQueued!=0) {
           type=typeQueue[nQueued-1]; i=iQueue[nQueued-1]; j=jQueue[nQueued-1]; k=kQueue[nQueued-1];
           if (type==0) Couple (i,j,k);
           else if (type==1) SetMin (i,j,k);
           else SetMax (i,j,k);
           Queued[type][i][j][k]=false;
           nQueued--;
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
           TwoLineSet();
     }
     
     if (Solved()==0) {
        solns++;
        for (i=1; i<17; i++) for (j=1; j<17; j++) {hLines[i][j]=HorLine[i-1][j]; vLines[i][j]=VerLine[i][j-1];}
     }
}     
