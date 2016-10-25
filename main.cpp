//#include "skjut.h"
//#include "funktioner.h"
//#include "playerinput.h"
#include "SDL_functions.h"
#include "FMain.h"
#include "map_loader.h"
#include "golf_club.h"

//using namespace std;

#define GOLFCOURT_HOLE 9
#define PLAYER = 4

bool GameRunning = true;

Players players;
IsPlaying isplaying[4];
//int br[9],ho[9];
golf_ball_position GolfBallPosition[GOLFCOURT_HOLE];
int GolfCourseWidth[GOLFCOURT_HOLE],GolfCourseHeight[GOLFCOURT_HOLE];
Bools bo;
int ActiveGolfCourse = 0;
//int mapnow=0;

int main(int, char**)
{
	SDL_Log( "Randomizing data..." );
	srand((unsigned)time(0));

	//InitVideo();
	//SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	// Initializes the video subsystem
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) 
	{
		//cerr << "Unable to init SDL: " << SDL_GetError() << endl;
		SDL_Log( "Unable to init, SDL Error: %s\n", SDL_GetError() );
		exit(1);
	}

	char GolfCourtFile[] = "golfcourts/level1";
	stdd::vector<std::vector<int> > array2D;

	// Set up sizes. (HEIGHT x WIDTH)
	array2D.resize(90);
	for (int i = 0; i < 90; ++i)
	array2D[i].resize(90);

	// Put some values in
	array2D[1][2] = 6;
	array2D[3][1] = 5;

	char ab[]="level1";
	
	tyta = new int **[GOLFCOURT_HOLE];
	for(int CurrentHole=0; CurrentHole < GOLFCOURT_HOLE; CurrentHole++)
	{	
		ifstream infil;
		ab[5]='1'+CurrentHole;
		infil.open(ab);
		infil >> GolfCourseWidth[CurrentHole] >> GolfCourseHeight[CurrentHole] >> GolfBallPosition[CurrentHole].x >> GolfBallPosition[CurrentHole].y;				
	
		tyta[CurrentHole]= new int *[GolfCourseWidth[CurrentHole]];
		for(int i=0; i<GolfCourseWidth[CurrentHole]; ++i)
			tyta[CurrentHole][i]= new int[GolfCourseHeight[CurrentHole]];

		for(int i=0; i<GolfCourseWidth[CurrentHole]; i++)
			for(int j=0; j<GolfCourseHeight[CurrentHole]; j++)
			{
				infil >> tyta[CurrentHole][i][j];
			}
		infil.close();
	}

	float value=0;	
	int x2=0,y2=0; //mouse related
	int isp=0;
	
	GolfClub Club;
	GolfClub Clubs[]={GolfClub(6.0f,8.0f),
	GolfClub(6.0f,7.0f),
	GolfClub(9.0f,3.0f),
	GolfClub(6.0f,9.0f),
	GolfClub(11.0f,2.2f),
	GolfClub(0.0f,13.0f)};
	
	float RHeight,RWidth;
	
	Pos windPos={0,0};
	Pos WPos={0,0};

	UseWind(bo.FirstShot,windPos,WPos);	

	for(int playerID=0; playerID < PLAYERS; playerID++)
	{
		//isplaying[playerID].ball=GolfBallPosition[ActiveGolfCourse];
		isplaying[playerID].Ball.setPosition(GolfBallPosition[ActiveGolfCourse]);
	}
	
	while(!GameRunning) // bo.Done
	{
		while(!players.picked)
		{
			SDL_ShowCursor(SDL_ENABLE);
			PickPlayers();
		}
		//if(bo.done)
		//	break;	
		if(bo.PickGolfClub)
		{
			SDL_ShowCursor(SDL_ENABLE);
		}
		else
		{
			SDL_ShowCursor(SDL_DISABLE);
		}
		int Starttime=SDL_GetTicks();

		//LandSatt(isp);
        	CheckBallLanded(isp);
		
		EventHandler(bo,RHeight,RWidth,x2,y2,Club,Clubs,isp,value);
			
		const int x=55;
		const int a=670;
		const int b=725;
		const int c=30;
		
		if(bo.FireGolfBall==false)
		{
			SDL_GetMouseState(&x2,&y2);
		}

		static int button=1;
		static bool down=false;
		static bool set=true;		
		if(bo.FireGolfBall==true)
		{		
			FireGolfBall(set,x2,y2,isp,Club,bo,value,windPos,WPos);	
		}
		else
		{			
			set=true;			
		}
			
		for(int i=1; i<18; ++i)
			for(int j=1; j<17; ++j) //ritar ut allt
			{
				if(bo.RMove)
					DrawIMGAlpha(surf.ImageSurface, i*50-50-(int)RWidth%50, j*50-50-(int)RHeight%50, 50, 50,(((50+yta[i-1+((int)RWidth/50)][j-1+(int)RHeight/50])/50)*50-50), (yta[i-1+(int)RWidth/50][j-1+(int)RHeight/50]%50)*50-50,0,false);
				else
					DrawIMGAlpha(surf.ImageSurface, i*50-50-(int)bredd1%50, j*50-50-(int)hojd1%50, 50, 50,(((50+yta[i-1+((int)bredd1/50)][j-1+(int)hojd1/50])/50)*50-50), (yta[i-1+(int)bredd1/50][j-1+(int)hojd1/50]%50)*50-50,0,false);
			}		
		
		if(bo.MouseRightDown)
		{
			if((x2 > 700 && ((RWidth+20)/50) < (bredd-18)))		
				RWidth+=20;

			if((x2 < 100) && RWidth-20 > 0 )
				RWidth-=20;

			if(y2 > 500 && ((RHeight+20)/50)<(hojd-17))
				RHeight+=20;

			if(y2 < 100 && (RHeight-20) > 0)
				RHeight-=20;	
		}
		else if(bo.RMove==false)
		{			
			drawcircle((int)isplaying[isp].ball.x-(int)bredd1,(int)isplaying[isp].ball.y-(int)hojd1,3+(int)(isplaying[isp].ball.current_height/200),3+(int)(isplaying[isp].ball.current_height/200)); //bollen
			if(bo.FireGolfBall==false && bo.PickGolfClub==false)
			DrawLine(isplaying[isp].ball.x-bredd1,isplaying[isp].ball.y-hojd1,x2,y2);
		}

		if( bo.MouseRightDown==false && bo.RMove)
		{
			float x,y;
			x=30*(RWidth-bredd1)/(sqrtf(powf(abs(RWidth-bredd1),2)+powf(abs(RHeight-hojd1),2)));
			y=30*(RHeight-hojd1)/(sqrtf(powf(abs(RWidth-bredd1),2)+powf(abs(RHeight-hojd1),2)));
			if(abs(RWidth-bredd1) < 30)
				if(abs(RHeight-hojd1) < 30)
					bo.RMove=false;			
			RWidth-=x;
			RHeight-=y;
		}

		if(bo.FireGolfBall==false && bo.PickGolfClub && bo.RMove==false)
		{
			//Draws golf clubs
			DrawIMGAlpha( surf.GolfImageSurface, 640, 10, 153, 278, 1, 1,0,false);
		}
		Matare(isplaying[isp].ball);
		if(bo.PickGolfClub==false && bo.MouseDown && bo.FireGolfBall==false)
					{
						value=Power(bo.Power);
						
						if(bo.Power)
						{
							bo.SetValue=false;
							bo.FireGolfBall=true;							

							float temp;
							value > 1.0f ? temp=2.0f-value : temp=value;
							if(temp<0.1f)
								temp=0.1f;
							isplaying[isp].ball.height *= temp;
							isplaying[isp].ball.distance *= temp;
						}
					}
		
		ViewPower(value);	
		viewWind(WPos,isplaying[isp].ball);
		//if(bo.Rmove==false)
		viewBird();
			
		SDL_Flip(surf.ScreenSurface);
		
		//cout << SDL_GetTicks()-Starttime << endl;
		if(SDL_GetTicks()-Starttime <20)
			SDL_Delay(20-(SDL_GetTicks()-Starttime));
	}	
	return 0;	
}
