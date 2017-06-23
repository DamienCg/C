#include <iostream>
//for kbhit
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
 
int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}
 
using namespace std;
bool gameOver;
const int width = 25;
const int height = 15;

int tailX[100],tailY[100];
int nTail; /*Corpo*/

int x, y, fruitX, fruitY, score;
enum eDirection{STOP=0, LEFT,RIGHT,UP,DOWN};
eDirection dir;

/*
 * Dati globali per la gestione delle coordinate
dei punti e dei movimenti
*/

void Setup(){
	
	gameOver = false;
	dir = STOP;
	x = width/2;
	y = height/2;
	fruitX = rand()%width;
	fruitY = rand()%height;
	score = 0;
}
void Draw(){
	
	system("clear");
	for(int i=0; i<width+2; i++)
		cout<<"#";
	cout<<endl;
	 
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			
				if(j==0)
					cout<<"#";
				
				if(i==y && j==x)
					cout<<"O";
				else if(i==fruitY && j== fruitX)
				cout<<"F";
				else{
					bool print=false;
					for(int k=0; k<nTail; k++){
						if(tailX[k] == j && tailY[k] == i){
							cout<<"o";
							print=true;
						}
					}
						if(!print)
						cout<<" ";
				}
				if(j==width-1)
				cout<<"#";
		}
		cout<<endl;
	} 
	 for(int i=0; i<width+2; i++)
		cout<<"#";
	 cout<<endl;
	 cout<<"Score: "<<score<<endl;
}


void Input(){
	
	if(kbhit()){//ritorna un booleano
		switch(getchar()){
			case 'a':
			 dir=LEFT;
			 break;
			case 'd':
			 dir=RIGHT;
			 break;
			case 'w':
			 dir=UP;
			 break;
			case 's':
			 dir=DOWN;
			 break;
			case 'x':
			 gameOver= true;
			 break;
		}
	}
}
void Logic(){
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X,prev2Y;
	
	for(int i=1; i<nTail; i++){
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX = prev2X;
		prevY = prev2Y;
		tailX[0] = x;
		tailY[0] = y;
	}
	
	switch(dir){
		case LEFT:
		 x--;
		 break;
		
		case RIGHT:
		 x++;
		 break;
		
		case UP:
		 y--;
		 break;
		 
		case DOWN:
		 y++;
		 break;
		 
		default:
		 break;
	}
	
	if(x >= width) x=0; else if(x < 0) x = width-1;
	if(y >= height)y=0; else if(y < 0) y = height-1;
	
	for(int i=0; i< nTail; i++)
		if(tailX[i] == x && tailY[i] == y)
			gameOver = true;
		
	if(x==fruitX && y==fruitY){
		score+=10;
		fruitX = rand()%width;
		fruitY = rand()%height;
		nTail++;	
	} /*Se le mie coordinate sono sopra un frutto*/
}

int main(){

	Setup();
	while(!gameOver){
		Draw();
		Input();
		Logic();
		usleep(120000);
		//sleep(10);
	}
	return 0;
}
