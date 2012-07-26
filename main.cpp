//#include "skjut.h"
//#include "funktioner.h"
//#include "playerinput.h"
#include "SDL_functions.h"
#include "FMain.h"
#include "map_loader.h"
#include "golf_club.h"

Players players;
IsPlaying isplaying[4];
int br[9],ho[9];
//bollpos parameter
golf_ball_position boll[9];
Bools bo;
int mapnow=0;

using namespace std;


int main(int, char**)
{	
	srand((unsigned)time(0));

	char ab[]="level1";
	
	tyta = new int **[9];
	for(int k=0; k<9; k++)
	{	
		ifstream infil;
		ab[5]='1'+k;
		infil.open(ab);
		infil >> br[k] >> ho[k] >> boll[k].x >> boll[k].y;				
	
		tyta[k]= new int *[br[k]];
		for(int i=0; i<br[k]; ++i)
			tyta[k][i]= new int[ho[k]];

		for(int i=0; i<br[k]; i++)
			for(int j=0; j<ho[k]; j++)
				infil >> tyta[k][i][j];

		infil.close();
	}

	InitVideo();
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	Sound Sound_test;
	Sound_test.Load("sounds\\three.wav");
	Sound_test.Play(0);
	float value=0;	
	int x2=0,y2=0; //mouse related
	int isp=0;
	
	
	club klubb;
	club klubbor[]={club(6.0f,8.0f),
		club(6.0f,7.0f),
		club(9.0f,3.0f),
		club(6.0f,9.0f),
		club(11.0f,2.2f),
		club(0.0f,13.0f)};
	
	float RHeight,RWidth;
	
	Pos windPos={0,0};
	Pos WPos;
	UseWind(bo.firstshot,windPos,WPos);	

	for(int i=0; i<4; i++)
	{
		isplaying[i].ball=boll[mapnow];		
	}
	
		while(!bo.done)
		{
			
			while(!players.picked)
			{
				SDL_ShowCursor(SDL_ENABLE);
				PickPlayers();
			}
			//if(bo.done)
			//	break;	
			if(bo.pickClub)
				SDL_ShowCursor(SDL_ENABLE);
			else
				SDL_ShowCursor(SDL_DISABLE);
		
		int Starttime=SDL_GetTicks();

		LandSatt(isp);	
		
		MainEvents(bo,RHeight,RWidth,x2,y2,klubb,klubbor,isp,value);
			
		const int x=55;
		const int a=670;
		const int b=725;
		const int c=30;
		
		if(bo.skjut==false)
			SDL_GetMouseState(&x2,&y2);	

		static int button=1;
		static bool down=false;
		static bool set=true;		
		if(bo.skjut==true)
		{		
			MainSkjut(set,x2,y2,isp,klubb,bo,value,windPos,WPos);	
		}
		else
		{			
			set=true;			
		}
	
				
		for(int i=1; i<18; ++i)
			for(int j=1; j<17; ++j) //ritar ut allt
			{
				if(bo.Rmove)
					DrawIMGAlpha(surf.image, i*50-50-(int)RWidth%50, j*50-50-(int)RHeight%50, 50, 50,(((50+yta[i-1+((int)RWidth/50)][j-1+(int)RHeight/50])/50)*50-50), (yta[i-1+(int)RWidth/50][j-1+(int)RHeight/50]%50)*50-50,0,false);
				else
					DrawIMGAlpha(surf.image, i*50-50-(int)bredd1%50, j*50-50-(int)hojd1%50, 50, 50,(((50+yta[i-1+((int)bredd1/50)][j-1+(int)hojd1/50])/50)*50-50), (yta[i-1+(int)bredd1/50][j-1+(int)hojd1/50]%50)*50-50,0,false);
			}		
		

		
		
		if(bo.mouseRdown)
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
		else if(bo.Rmove==false)
		{			
			drawcircle((int)isplaying[isp].ball.x-(int)bredd1,(int)isplaying[isp].ball.y-(int)hojd1,3+(int)(isplaying[isp].ball.current_height/200),3+(int)(isplaying[isp].ball.current_height/200)); //bollen
			if(bo.skjut==false && bo.pickClub==false)
			DrawLine(isplaying[isp].ball.x-bredd1,isplaying[isp].ball.y-hojd1,x2,y2);
		}

		if( bo.mouseRdown==false && bo.Rmove)
		{
			float x,y;
			x=30*(RWidth-bredd1)/(sqrtf(powf(abs(RWidth-bredd1),2)+powf(abs(RHeight-hojd1),2)));
			y=30*(RHeight-hojd1)/(sqrtf(powf(abs(RWidth-bredd1),2)+powf(abs(RHeight-hojd1),2)));
			if(abs(RWidth-bredd1) < 30)
				if(abs(RHeight-hojd1) < 30)
					bo.Rmove=false;
			
			
			RWidth-=x;
			RHeight-=y;
		}

		if(bo.skjut==false && bo.pickClub && bo.Rmove==false)
		{
			//Draws golf clubs
			DrawIMGAlpha( surf.golfimage, 640, 10, 153, 278, 1, 1,0,false);
		}
		Matare(isplaying[isp].ball);
		if(bo.pickClub==false && bo.mousedown && bo.skjut==false)
					{
						value=Power(bo.power);
						
						if(bo.power)
						{
							bo.setvalue=false;
							bo.skjut=true;							

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
	
			
		SDL_Flip(surf.screen);	 
		
		//cout << SDL_GetTicks()-Starttime << endl;

		
		if(SDL_GetTicks()-Starttime <20)
			SDL_Delay(20-(SDL_GetTicks()-Starttime));
		
	}	
	return 0;	
}