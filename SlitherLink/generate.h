void Generate();

void GridGen(int hLine[][17], int vLine[][17]) {
     int bi, bj, r, ntried=0, i, j, num;
     bool tried[17][17];
     Loop SolvingLoop;
          
     for (i=1; i<=HorSize; i++) for (j=1; j<=VerSize; j++) {
         Num[i][j]=hLine[i-1][j] + hLine[i][j] + vLine[i][j-1] + vLine[i][j];
         tried[i][j]=false;
     }
     
     while (ntried!=HorSize*VerSize) {
         r=rand()%(HorSize*VerSize-ntried)+1;
         
         num=0;
         for (i=1; i<=HorSize; i++) {
             for (j=1; j<=VerSize; j++) {
                 if (!tried[i][j]) num++;
                 if (num==r) {bi=i; bj=j; break;}
             }
             if (num==r) break;
         }
         
         SolvingLoop.Clear();
         SolvingLoop.SetSize();
         Num[bi][bj]=-1;
         tried[bi][bj]=true;
         ntried++;
         for (i=1; i<=HorSize; i++) for (j=1; j<=VerSize; j++) SolvingLoop.GridVal[i][j]=Num[i][j];
         SolvingLoop.Solve();
         
         if (diff==2) {if (solns>1) Num[bi][bj]=hLine[bi-1][bj] + hLine[bi][bj] + vLine[bi][bj-1] + vLine[bi][bj];}
         else if (SolvingLoop.Solved()!=0) Num[bi][bj]=hLine[bi-1][bj] + hLine[bi][bj] + vLine[bi][bj-1] + vLine[bi][bj];
     }
     
     if (diff==0) if (SolvingLoop.Solved()!=0) Generate ();
}

bool LoopGen(int l_min, int dir[], int &x, int &y, int &end, int &begin) {
     int i, j, k, VertNum[16][16], allowed[4];
     for (i=0; i<=HorSize; i++) for (j=0; j<=VerSize; j++) VertNum[i][j]=-l_min;
     
     y = rand() % (HorSize+1);
     x = rand() % (VerSize+1);
     
     for (end=0; VertNum[y][x]==-l_min; end++) {
         VertNum[y][x]=end;
         k=0;
         
         if (y!=0) if (VertNum[y-1][x] <= end - l_min) {allowed[k]=0; k++;}
         if (x!=VerSize) if (VertNum[y][x+1] <= end - l_min) {allowed[k]=1; k++;}
         if (y!=HorSize) if (VertNum[y+1][x] <= end - l_min) {allowed[k]=2; k++;}
         if (x!=0) if (VertNum[y][x-1] <= end - l_min) {allowed[k]=3; k++;}
         
         if (k==0) return (false);
         else dir[end]=allowed[rand()%k];
         
         if (dir[end]==0) y--;
         if (dir[end]==1) x++;
         if (dir[end]==2) y++;
         if (dir[end]==3) x--;
     }
     
     begin=VertNum[y][x];
     return(true);
}

void Generate () {
     int hLine[17][17], vLine[17][17];
     int i, j, end, begin, l_min, k=0;
     int x, y, dir[257];
     
     l_min=3*(HorSize+1)*(VerSize+1)/4;
     while (!LoopGen(l_min,dir,x,y,end,begin));
     
     for (i=0; i<17; i++) for (j=0; j<17; j++) hLine[i][j]=0;
     for (i=0; i<17; i++) for (j=0; j<17; j++) vLine[i][j]=0;

     for (i=begin; i<end; i++) {
         if (dir[i]==0) {vLine[y][x]  =1; y--;}
         if (dir[i]==1) {hLine[y][x+1]=1; x++;}
         if (dir[i]==2) {vLine[y+1][x]=1; y++;}
         if (dir[i]==3) {hLine[y][x]  =1; x--;}
     }
     
     GridGen(hLine,vLine);
}
