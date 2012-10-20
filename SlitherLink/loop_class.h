class Loop {
      private:
              int HorLine[17][17], VerLine[17][17];
              int VertImp[17][17], VertCer[17][17], GridCer[17][17], GridImp[17][17];
              int GridReg[17][17];
              int Coupled[17][17];
              int LoopNumber[17][17];
              bool Min1[17][17][4], Max1[17][17][4];
              bool empty, cons;
              int maxSegNum, diffic, NumLeft;
              int indent;
             
      public:
             int GridVal[17][17];
             
             Loop (void);
             void Clear();
             void SetSize();
             void InputHor(int,int);
             void InputVer(int,int);
             
             void HorDark (int, int);
             void VerDark (int, int);
             void HorCross (int, int);
             void VerCross (int, int);
             void HorGrey (int, int);
             void VerGrey (int, int);
             
             void SetReg(int,int,int);
             void Couple (int, int, int);
             void SetMin(int, int, int);
             void SetMax(int, int, int);
             
             void sHorDark(int, int);
             void sVerDark(int, int);
             void sHorCross(int, int);
             void sVerCross(int, int);
             void Convert(int, int, int);
             
             int Solved();
             void Solve();
             void Generate (int,int);
             void GuessSolve();
             void TwoLineSet();
             ~Loop () {}
};
