#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

bool gameOver;
int w, h;
int x, y, fruitx, fruity, score;
enum eDirection{STOP = 0, LEFT, RIGHT, UP, DOWN};
int tailx[111], taily[111], ntail;
eDirection dir;

void Setup(){
	gameOver = 0;
	x = h / 2;
	y = w / 2;
	while((fruitx == x and fruity == y) or fruitx == 0 or fruitx == h or fruity == 0 or fruity == w){
			fruitx = rand() % h;
			fruity = rand() % w;
		}
	score = 0;
	ntail = 0;
}

void Draw(){
	system("cls");
	//dir = STOP;
	char ar[h + 1][w + 1];
	
	for(int i = 0; i <= h; i++)
		for(int j = 0; j <= w; j++)
			ar[i][j] = ' ';
	for(int i = 0; i < ntail; i++)
		ar[tailx[i]][taily[i]] = 'o';		
	
	for(int i = 0; i <= h; i++)
		for(int j = 0; j <= w; j++){
			if(i == x and j == y){
				ar[i][j] = '0';
				continue;
			}
			if(i == fruitx and j == fruity){
				ar[i][j] = 'F';
				continue;
			}
			if(i == 0 or i == h){
				ar[i][j] = '#';
				continue;
			}
			if(j == 0 or j == w){
				ar[i][j] = '#';
				continue;
			}
			
		}
	
	for(int i = 0; i <= h; i++){
		for(int j = 0; j <= w; j++)
			cout << ar[i][j];
		cout << "\n";	
	}		
		
	cout << "Score:" << score << "\n";	
}

void Input(){
	if(_kbhit()){
		switch(_getch ()){
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'a':
				dir = LEFT;
				break;
			case 'x':
				gameOver = 1;
				break;				
		}
	}
}

void Logic(){
	if(dir == STOP)
		return;
	int prevx = tailx[0];
	int prevy = taily[0];
	int prev2x, prev2y;
	tailx[0] = x;
	taily[0] = y;
	for(int i = 1; i < ntail; i++){
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}
	
	switch(dir){
		case UP:
			x--;
			break;
		case DOWN:
			x++;
			break;
		case RIGHT:
			y++;
			break;
		case LEFT:
			y--;
			break;			
	}
	
	if(x >= h or x <= 0 or y >= w or y <= 0){
		if(x >= h)
			x = 1;
		if(x <= 0)
			x = h - 1;
		if(y >= w)
			y = 1;
		if(y <= 0)
			y = w - 1;			
	}
	for(int i = 0; i < ntail; i++)
		if(tailx[i] == x and taily[i] == y)
			gameOver = 1;
	if(x == fruitx and y == fruity){
		score++;
		ntail++;
		while((fruitx == x and fruity == y) or fruitx == 0 or fruitx == h or fruity == 0 or fruity == w){
			fruitx = rand() % h;
			fruity = rand() % w;
		}
	}	
}

int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie();
	//cout.tie();
	srand(time(NULL));
	cin >> w >> h;
	
	Setup();
	while(!gameOver){
		int cnt = 0;
		//while(cnt < (int)1e7){
		//	cnt++;
		//}
		Draw();
		Input();
		Logic();
	}
	
	return 0;
}
