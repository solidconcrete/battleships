#include <iostream>
#include <iomanip>
#include <stdlib.h> 
#include <ctime>
using namespace std;
int lifey=20, lifee=20, turn;
void placement (int dir, int size, char board[10][10]);
void show (char board[10][10]);
void shoot(char board[10][10], char yousee[10][10]);
void eshoot(char board[10][10]);
int main()
{
  int i, j, randomx, randomy, dir, size;
  char you[10][10]={0}, enemy[10][10], enemy2[10][10];
  srand ( time(NULL) );
 for(i=0; i<10; i++)
 for(j=0; j<10; j++)
{
  enemy[i][j]=46;
  enemy2[i][j]=46;
  you[i][j]=46;
}
i=1;
for(size=4; size>0; size--) //randomly fill both boards
{

  for(j=0; j<i; j++)
  {
    dir=rand()%2+1;
    placement(dir, size, enemy);
    dir=rand()%2+1;
    placement(dir, size, you);
  }
  i++;
}

//cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
//   cout<<setw(20)<<"ENEMY BOARD"<<endl<<endl<<"   ";
//   show (enemy2);
//   show (enemy);
//
//cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
//   cout<<setw(20)<<"YOUR BOARD"<<endl<<endl<<"   ";
//   show (you);
//   cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
   turn=1;
  while((lifey>0)&&(lifee>0))         // shoot function
  {
  	cout<<endl<<setw(20)<<"ENEMY BOARD";
    show(enemy2);
//    show(enemy);
    cout<<setw(20)<<"YOUR BOARD";
    show(you);
    system("pause");
    if(turn==1)
    	shoot(enemy, enemy2);
    else 
    	eshoot(you);
//    system ("cls");
//    cout<<setw(20)<<"ENEMY BOARD";
//    show(enemy);
//    show(enemy2);
//    cout<<setw(20)<<"YOUR BOARD";
//    show(you);
    
  }
  if (lifey==0)
  cout<<endl<<"YOU LOSE"<<endl;
  else cout<<"YOU WIN"<<endl;
  system("Pause");
  return 0;
  
}
void placement(int dir, int size, char board[10][10])
{
  int randomx, randomy, i;
  bool place=true;
  if(dir==1)
  {
    randomx=rand()%10;     
    randomy=rand()%(11-size)+(-1+size);
    for(i=0; i<size; i++)
    {
      if((board[randomy-i][randomx]==45)||(board[randomy-i][randomx]==35))
      place=false;
    }
    if(place==true)
    {
      board[randomy][randomx]=35;   
      if(randomy!=9)
      {
          board[randomy+1][randomx]=45; 
        if(randomx!=9)
          board[randomy+1][randomx+1]=45;
        if(randomx!=0)
          board[randomy+1][randomx-1]=45;
      }
      for(i=0; i<size; i++)
      {
        board[randomy-i][randomx]=35;   //continue building the ship
        if(randomx!=9)
          board[randomy-i][randomx+1]=45; //make surrounding area unusable
        if(randomx!=0)
          board[randomy-i][randomx-1]=45;
      }
      
      if(randomy-size>=0)
      {
        board[randomy-size][randomx]=45;
        if(randomx!=9)
        board[randomy-size][randomx+1]=45;
        if(randomx!=0)
        board[randomy-size][randomx+-1]=45;
      }
    }
    else 
    {
      cout<<"retrying "<<randomy<<" "<<randomx;
      placement(dir, size, board);  
    }
  }
  else
  {
    randomy=rand()%10;      //find usable area
    randomx=rand()%(11-size);
    for(i=0; i<size; i++)
    {
      if((board[randomy][randomx+i]==45)||(board[randomy][randomx+i]==35))
      place=false;
    }
    if(place==true)
    {
      board[randomy][randomx]=35;   
      if(randomx!=0)
      {
          board[randomy][randomx-1]=45; 
        if(randomy!=9)
          board[randomy+1][randomx-1]=45;
        if(randomy!=0)
          board[randomy-1][randomx-1]=45;
      }
      for(i=0; i<size; i++)
      {
        board[randomy][randomx+i]=35;  
        if(randomy!=9)
          board[randomy+1][randomx+i]=45;
        if(randomy!=0)
          board[randomy-1][randomx+i]=45;
      }
      
      if(randomx+size<=9)
      {

       board[randomy][randomx+i]=45;
       if(randomy!=0)
        board[randomy-1][randomx+i]=45;
      if(randomy!=9)
        board[randomy+1][randomx+i]=45;
      }
    }
    else 
    {
      cout<<"retrying "<<randomy<<" "<<randomx;
      placement(dir, size, board);  
    }
  }
}
//system ("pause");

void show(char board[10][10])
{
char letter;
int i, j;
cout<<endl<<endl<<"   ";
  for(letter=65; letter<=74; letter++)
  cout<<letter<<"  ";
  cout<<endl;
  for(i=0; i<10; i++)
  {
    cout<<i<<"  ";
    for(j=0; j<10; j++)
    {
        cout<<board[i][j]<<"  ";
    }
    cout<<endl;
  }
}
void shoot(char board[10][10], char yousee[10][10])
{
	bool iskill=1;
    int x, y, y1, x1;
    cout<<endl<<"YOUR TURN"<<endl;
    char X;
    cout<<endl<<"Enter coordinates:";
    cin>>X>>y;
    x=int(X)-65;
 	y1=y;
 	x1=x;
    if(board[y][x]==35)
    {
      lifee--;
      board[y][x]=88;
      yousee[y][x]=88;   
	  cout<<endl<<"first"<<endl;   
    while((board[y1][x]!=45)&&(y1>=0))
    {
    	y1--;
    	if(board[y1][x]==35)
    	{
			cout<<"HIT";
			return;
		}
	}
	y1=y;
	cout<<endl<<"second"<<endl;
	while((board[y1][x]!=45)&&(y1<=9))
    {
    	y1++;
    	if(board[y1][x]==35)
    	{	
//			iskill=0;
			cout<<"HIT";
			return;
		}
	}


	while((board[y][x1]!=45)&&(x1>0))
    {
    	x1--;
    	if(board[y][x1]==35)
    	{
			cout<<"HIT";
			return;
		}
	}
	x1=x;
	cout<<endl<<"second"<<endl;
	while((board[y][x1]!=45)&&(x1<9))
    {
    	x1++;
    	if(board[y][x1]==35)
    	{	
//			iskill=0;
			cout<<"HIT";
			return;
		}
	}
	x1=x; y1=y;
//	if(iskill)
		cout<<"SHIP DESTROYED";
		if((board[y][x1-1]==88)||(board[y][x1+1]==88))
		{
			if((board[y][x1-1]==88)||(board[y][x1-1]==45))
			{
				yousee[y+1][x1]=111;
				yousee[y-1][x1]=111;
				while((board[y][x1]!=45)&&(x1>0))
				{
					x1--;
					yousee[y+1][x1]=111;
					yousee[y-1][x1]=111;
				}
				yousee[y][x1]=111;	
			}
			x1=x;
			if((board[y][x1+1]==88)||(board[y][x1+1]==45))
			{
				yousee[y+1][x1]=111;
				yousee[y-1][x1]=111;
				while((board[y][x1]!=45)&&(x1<9))
				{
					x1++;
					yousee[y+1][x1]=111;
					yousee[y-1][x1]=111;
				}
				yousee[y][x1]=111;	
			}
		}
		else
		{
			if((board[y1-1][x]==88)||(board[y1-1][x]==45))
			{
				if(x!=9)
					yousee[y1][x+1]=111;
				if(x!=0)	
					yousee[y1][x-1]=111;
				while((board[y1][x]!=45)&&(y1>0))
				{
					y1--;
					if(x!=9)
						yousee[y1][x+1]=111;
					if(x!=0)	
						yousee[y1][x-1]=111;
				}
				yousee[y1][x]=111;	
			}
			y1=y;
			if((board[y1+1][x]==88)||(board[y1+1][x]==45))
			{
				if(x!=9)
					yousee[y1][x+1]=111;
				if(x!=0)	
					yousee[y1][x-1]=111;
				while((board[y1][x]!=45)&&(y1<9))
				{
					y1++;
					if(x!=9)
					yousee[y1][x+1]=111;
					if(x!=0)	
					yousee[y1][x-1]=111;
				}
				yousee[y1][x]=111;	
			}
		}

    }
    else
    {
      turn=2;
      yousee[y][x]=111;
      cout<<"MISS"<<endl;
    }
    
}
    
  void eshoot(char board[10][10])
  {
  	int x, y;
  	bool iskill=1;
    cout<<endl<<"ENEMY TURN"<<endl;
    x=rand()%10;
    y=rand()%10;
//    if(board!=)
    cout<<x<<" "<<y<<endl;
    if(board[y][x]==35)
    {
      lifey--;
      board[y][x]=88;
      if((board[y-1][x]!=35)&&(board[y][x+1]!=35)&&(board[y+1][x]!=35)&&(board[y][x-1]!=35))
        cout<<endl<<"SHIP DESTROYED"<<endl<<endl<<"   ";
      else 
      cout<<endl<<"HIT"<<endl<<"   ";
    }
    else 
    {
      turn=1;
      board[y][x]=111;
      cout<<"MISS";
    }
  }

