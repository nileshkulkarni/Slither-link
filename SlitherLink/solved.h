void Loop::InputHor (int i, int j) {
    HorLine[i][j]=statusH[i+1][j];
    if (HorLine[i][j]==0) {
        VertCer[i][j]++;
        VertCer[i][j-1]++;
        GridCer[i][j]++;
        GridCer[i+1][j]++;
    }
    
    else if (HorLine[i][j]==-1) {
        VertImp[i][j]++;
        VertImp[i][j-1]++;
        GridImp[i][j]++;
        GridImp[i+1][j]++;
    }
}

void Loop::InputVer (int i, int j) {
    VerLine[i][j]=statusV[i][j+1];
    if (VerLine[i][j]==0) {
        VertCer[i][j]++;
        VertCer[i-1][j]++;
        GridCer[i][j]++;
        GridCer[i][j+1]++;
    }
    
    else if (VerLine[i][j]==-1) {
        VertImp[i][j]++;
        VertImp[i-1][j]++;
        GridImp[i][j]++;
        GridImp[i][j+1]++;
    }
}

int Loop::Solved() {
    // 0:solved; -1:empty; 1: Not a loop at all; 2:Cells not surrounded by correct no. of lines; 3:Multiple loops.
     int i, j, totLine=0, nLine=1, bi, bj, dir;
     //    -2
     // -1   1  (for direction)
     //    2
     
     for (i=0; i<=HorSize; i++) for (j=0; j<=VerSize; j++) if (VertCer[i][j]!=2 && VertCer[i][j]!=0) return(1);
     for (i=1; i<=HorSize; i++) for (j=1; j<=VerSize; j++) if (GridVal[i][j]!=-1 && GridCer[i][j]!=GridVal[i][j]) return(2);
     
     for (i=0; i<=HorSize; i++) for (j=1; j<=VerSize; j++) if (HorLine[i][j]==0) {totLine++; bi=i; bj=j;}
     for (i=1; i<=HorSize; i++) for (j=0; j<=VerSize; j++) if (VerLine[i][j]==0) {totLine++;}
     
     for (i=bi,j=bj,dir=-1 ; i!=bi||j!=bj-1 ; nLine++) {
         if (HorLine[i][j+1]==0 && dir!=1) {dir=-1; j++;}
         else if (HorLine[i][j]==0 && dir!=-1) {dir=1; j--;}
         else if (VerLine[i+1][j]==0 && dir!=2) {dir=-2; i++;} 
         else if (VerLine[i][j]==0 && dir!=-2) {dir=2; i--;}
     }
         
     if (nLine==totLine) return(0);
     else return(3);
}
