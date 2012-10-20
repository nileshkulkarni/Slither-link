#include <assert.h>
#include "bitmap.h"
SimpleWindow Main("main menu",11.8,15.0, Position(1.0, 1.0));
SimpleWindow Howto("how to play",13.5,10.0, Position(1.0, 1.0));
SimpleWindow Exit1("exit window",13.5,15.0, Position(1.0, 1.0));
BitMap Wall(Main);
BitMap Play(Main);
BitMap How(Main);
BitMap Options(Main);
BitMap Loop(Main);
BitMap Exit(Main);
BitMap Hplay(Howto);
//BitMap Wal2(Option);

int MainMouseClickEvent(const Position &p)
{
	if (Play.IsInside(p))
	{	
		 system("./Playfunccall");
		 
	}
	
	if (How.IsInside(p))
	{	//Main.Close();
 		Howto.Open();
		assert(Howto.GetStatus() == WindowOpen);
		 Hplay.Load("hplay.xpm");
		assert(Hplay.GetStatus() == BitMapOkay);
		Hplay.SetPosition(Position(0.0,0.0));
		Hplay.Draw();
	}
	if (Options.IsInside(p))
	{
		system("./acceptheightwidth_new");
	

	}	
	if (Loop.IsInside(p))
	{	 		system("./loopsolverfuncall");
 			
 }
	if (Exit.IsInside(p))
	{
 		ApiEnd();
		assert(Exit1.GetStatus() == WindowOpen);
		}
		return 1;
}
int ApiMain()
 {
 	Main.Open();
 	assert(Main.GetStatus() == WindowOpen);
	Wall.Load("wl3.xpm");
	assert(Wall.GetStatus() == BitMapOkay);
	Wall.SetPosition(Position(0.0,0.0));
	Wall.Draw();
	assert(Main.GetStatus() == WindowOpen);
	Play.Load("play2.xpm");
	assert(Play.GetStatus() == BitMapOkay);
	Play.SetPosition(Position(4.3,4.0));
	Play.Draw();
	assert(Main.GetStatus() == WindowOpen);
	How.Load("how2.xpm");
	assert(How.GetStatus() == BitMapOkay);
	How.SetPosition(Position(4.3,5.5));
	How.Draw();
	assert(Main.GetStatus() == WindowOpen);
	Options.Load("option2.xpm");
	assert(Options.GetStatus() == BitMapOkay);
	Options.SetPosition(Position(4.3,7.0));
	Options.Draw();
	assert(Main.GetStatus() == WindowOpen);
	Loop.Load("loop2.xpm");
	assert(Loop.GetStatus() == BitMapOkay);
	Loop.SetPosition(Position(4.3,8.5));
	Loop.Draw();
	assert(Main.GetStatus() == WindowOpen);
	Exit.Load("exit2.xpm");
	assert(Exit.GetStatus() == BitMapOkay);
	Exit.SetPosition(Position(4.3,10.0));
	Exit.Draw();	
	Main.SetMouseClickCallback(MainMouseClickEvent);
	return 0;
}

