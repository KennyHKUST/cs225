
/* Your code here! */
#include <iostream>
#include <queue> 
#include <time.h>
#include "maze.h"
#include <map>
#include <stack> 
using namespace std;
RGBAPixel r(255, 0, 0);
RGBAPixel b(0, 0, 0);
RGBAPixel w(255, 255, 255);
void SquareMaze::makeMaze(int w, int h){
	width = w;
	height = h;
	int n = 0;
	maze.resize(width);
	set.addelements(width * height);
	for(int i = 0; i < width; i++){
		maze[i].resize(height);
		for(int j = 0; j < height; j++){
			pair<int, int> coor(i, j);
			Square s(coor);
			maze[i][j] = s;
			//set.addelements(n);
			n++;
		}
	}
	// for(unsigned long i = 0; i < 800 * 800; i++)
	// 	;
	
	bfs();
	cout<<"makeMaze finished"<<endl;
}
//ignore this function 
void SquareMaze::makeMazeHelp(){
	vector<vector<bool>> visited(width);
	for(int i = 0; i < width; i++){
		visited[i].resize(height);
		for(int j = 0; j < height; j++){
			visited[i][j] = false;
		}
	}
	time_t t;
	srand((unsigned) time(&t));
	int loop = width * height / 2;
	while(loop >= 0){
		;
	}
}
void SquareMaze::bfs(){
	vector<vector<bool>> visited(width);
	//initialize the visited vector
	for(int i = 0; i < width; i++){
		visited[i].resize(height);
		for(int j = 0; j < height; j++){
			visited[i][j] = false;
		}
	}
	time_t t;
	srand((unsigned) time(&t));
	queue<Square> q;
	q.push(maze[0][0]);
	while(!q.empty()){
		Square s = q.front();
		q.pop();
		int x = s.coor.first; //width
		int y = s.coor.second;//height
		if(!visited[x][y]){
			visited[x][y] = true;
			int num = rand() % 2;//random generate the num of walls to be set
			int dir = rand() % 2;//random generate the collapsed wall
			int elementInSet = width * y + x;
			//cout<<"random generator"<<endl;
			//cout<<"dir = "<<dir<<endl;

			// if(dir == 0 && x == width - 1)
			// 	dir = 1;//cannot set the grid to be false
			// if(dir == 1 && y == height - 1)
			// 	dir = 0;//cannot set the grid to be false
			// int num2 = rand() % 2;
			// if(num2 == 0){
			// 	if(x + 1 < width)
			// 		q.push(maze[x + 1][y]);
			// 	if(y + 1 < height)
			// 		q.push(maze[x][y + 1]);
			// }
			// else{

			if(y + 1 < height)
				q.push(maze[x][y + 1]);	
			if(x + 1 < width)
				q.push(maze[x + 1][y]);
			
			if(dir == 0 && x == width - 1)
				dir = 1;

			if(dir == 1 && y == height - 1)
				dir = 0;

			while(num >= 0){
				if(dir == 0 && x != width - 1){
					int elementRightInSet = width * y + x + 1;
					if(set.find(elementInSet) != set.find(elementRightInSet)){
						setWall(x, y, 0, false);
						set.setunion(elementInSet, elementRightInSet);
					}
					// dir = 100;//prevent executing again in the next if function
					// if(y != height - 1 && num == 1)
					// 	dir = 1;
				}
				if(dir == 1 && y != height - 1){
					int elementBottomInSet = width * (y + 1) + x;
					if(set.find(elementInSet) != set.find(elementBottomInSet)){
						setWall(x, y, 1, false);
						set.setunion(elementInSet, elementBottomInSet);
					}
					// if(x != width - 1 && num == 1)
					// 	dir = 0;
				}
				if(dir == 0)
					dir = 1;//try bottom
				else
					dir = 0;//try right
				num--;
			}


			// if(x + 2 < width)
			// 	q.push(maze[x + 2][y]);
			// if(x + 3 < width)
			// 	q.push(maze[x + 3][y]);
			// if(x + 4 < width)
			// 	q.push(maze[x + 4][y]);

			// if(y + 2 < height)
			// 	q.push(maze[x][y + 2]);			
			// if(y + 3 < height)
			// 	q.push(maze[x][y + 3]);
			// if(y + 4 < height)
			// 	q.push(maze[x][y + 4]);

			// cout<<"x = "<<x<<" y = "<<y<<endl;
			// cout<<"dir = "<<dir<<endl;
			// if(dir == 0 && x != width - 1){
			// 	int elementRightInSet = width * y + x + 1;
			// 	if(set.find(elementInSet) != set.find(elementRightInSet)){
			// 		setWall(x, y, 0, false);
			// 		set.setunion(elementInSet, elementRightInSet);
			// 	}
			// 	dir = 100;//prevent executing again in the next if function
			// 	if(y != height - 1 && num == 1)
			// 		dir = 1;//try bottom
			// }
			// if(dir == 1){
			// 	int elementBottomInSet = width * (y + 1) + x;
			// 	if(set.find(elementInSet) != set.find(elementBottomInSet)){
			// 		setWall(x, y, 1, false);
			// 		set.setunion(elementInSet, elementBottomInSet);
			// 	}
			// 	if(x != width - 1 && num == 1)
			// 		dir = 0;//try right
			// }
			// if(dir == 0 && x != width - 1){
			// 	int elementRightInSet = width * y + x + 1;
			// 	if(set.find(elementInSet) != set.find(elementRightInSet)){
			// 		setWall(x, y, 0, false);
			// 		set.setunion(elementInSet, elementRightInSet);
			// 	}
			// 	dir = 100;//no need to try
			// }



		}
	}




}


bool SquareMaze::canTravel(int x, int y, int dir) const{
	//cout<<"x = "<<x<<" y = "<<y<<" dir = "<<dir<<endl;
	if(dir == 0 && x < width - 1){
		//cout<<maze[x][y].rightWall<<endl;
		return maze[x][y].rightWall == false;
	}

	if(dir == 1 && y < height - 1){
		//cout<<maze[x][y].bottomWall<<endl;
		return maze[x][y].bottomWall == false;
	}

	if(dir == 2 && x != 0){
		//cout<<maze[x-1][y].rightWall<<endl;
		return maze[x-1][y].rightWall == false;
	}

	if(dir == 3 && y != 0){
		//cout<<maze[x][y-1].bottomWall<<endl;
		return maze[x][y-1].bottomWall == false;
	}

	return false;
}

void SquareMaze::setWall(int x, int y, int dir, bool exists){
	if(dir == 0){
		if(exists)
			maze[x][y].rightWall = true;
		else 
			maze[x][y].rightWall = false;
	}
	if(dir == 1){
		if(exists)
			maze[x][y].bottomWall = true;
		else 
			maze[x][y].bottomWall = false;
	}

}
vector<int> SquareMaze::solveMaze(){

	solveMazeHelp();

	// for(unsigned long i = 0; i < mazeSolve.size(); i++){
	// 	for(unsigned long j = 0; j < mazeSolve[i].size(); j++){
	// 		//cout<<mazeSolve[i][j].prevStep<<endl;
	// 		cout<<endl;
	// 	}
	// }
	int x = checkBottomVisited();
	//int x = 0;
	int y = height - 1;
	vector<int> result;
	cout<<x<<endl;
	while(mazeSolve[x][y].prevStep != -1){
		int backStep = mazeSolve[x][y].prevStep;
		result.push_back(backStep);
		stepBack(x, y, backStep);
		//cout<<"?"<<endl;
	}
	// cout<<"the path is "<<endl;
	// for(auto &val: path)
	// 	cout<<val<<endl;

	reverse(result.begin(), result.end());
	// for(auto &val: result){
	// 	//val = changePrevDir(val);
	// 	cout<<val<<endl;
	// }
	path = result;
	return result;
}
void SquareMaze::stepBack(int &x, int &y, int dir){
	dir = changePrevDir(dir);
	if(dir == 0)
		x++;
	if(dir == 1)
		y++;
	if(dir == 2)
		x--;
	if(dir == 3)
		y--;
}
void SquareMaze::solveMazeHelp(){
	stack<Cell> s;
	mazeSolve.resize(width);
	for(int i = 0; i < width; i++)
		mazeSolve[i].resize(height);
	Cell square(0, 0, -1, 0);
	s.push(square);
	while(!s.empty()){
		Cell c = s.top();
		s.pop();
		int prevDir = changePrevDir(c.prevStep);
		int x = c.cx;
		int y = c.cy;
		mazeSolve[x][y] = c;
		int distance = c.distance;
		for(int i = 0; i < 4; i++){
			if(canTravel(x, y, i) && i != prevDir){
				stackPush(s, x, y, i, distance+1);


			}
		}
	}
}

int SquareMaze::checkBottomVisited(){
	// while(!dir.empty()){
	// 	int direction = changePrevDir(dir.back());
	// 	dir.pop_back();
	// 	if(direction == 0)
	// 		x++;
	// 	if(direction == 1)
	// 		y++;
	// 	if(direction == 2)
	// 		x--;
	// 	if(direction == 3)
	// 		y--;
	// 	if(y == height - 1)
	// 		return;
	// }
	int max_distance = 0;
	int y = height - 1;
	int x = width - 1;
	for(int i = width - 1; i >= 0; i--){
		if(mazeSolve[i][y].distance > max_distance){
			max_distance = mazeSolve[i][y].distance;
			x = i;
		}
	}
	cout<<"x is "<<x<<endl;
	return x;
}

void SquareMaze::stackPush(stack<Cell> &s, int x, int y, int i, int dis){
	//curr.push_back(i);
	if(i == 0){
		//Path *p = new Path(x+1, y, i, curr);
		x++;

	}
	if(i == 1){
		//Path *p = new Path(x, y+1, i, curr);
		y++;

	}
	if(i == 2){
		//Path *p = new Path(x-1, y, i, curr);
		x--;

	}
	if(i == 3){
		//Path *p = new Path(x, y-1, i, curr);
		y--;

	}
	Cell p = Cell(x, y, i, dis);
	s.push(p);
}

pair<pair<int, int>, pair<int, vector<int>>> SquareMaze::makeAPair(int x, int y, int dir, vector<int> * v){

	pair<int, int> firstCoor(x, y);
	pair<int, vector<int>> def(dir, *v);
	pair<pair<int, int>, pair<int, vector<int>>> p(firstCoor, def);
	return p;
}

int SquareMaze::changePrevDir(int prevDir){
	if(prevDir == 0)
		prevDir = 2;
	else if(prevDir == 1)
		prevDir = 3;
	else if(prevDir == 2)
		prevDir = 0;
	else if(prevDir == 3)
		prevDir = 1;
	else
		prevDir = -1;
	return prevDir;
}
void SquareMaze::blacken(PNG &p, int x, int y, int dir) const{
	for(int k = 0; k <= 10; k++){
		if(dir == 0){
			*p((x+1)*10, y*10+k) = b;

		}
		if(dir == 1){
			*p(x*10+k, (y+1)*10) = b;
	
		}

	}
}
void SquareMaze::fillRed(PNG &p, int &x, int &y, int dir) const{
	for(int k = 0; k <= 10; k++){
		*p(x, y) = r;
		if(dir == 0)//rightward
			x++;
		if(dir == 1)//downward
			y++;
		
		if(dir == 2)//leftward
			x--;
		if(dir == 3)//upward
			y--;
		

	}
	if(dir == 0)
		x--;
	if(dir == 1)
		y--;
	if(dir == 2)
		x++;
	if(dir == 3)
		y++;

}
PNG* SquareMaze::drawMaze() const{
	int PNGWidth = width * 10 + 1;
	int PNGHeight = height * 10 + 1;
	PNG* p = new PNG(PNGWidth, PNGHeight);
	//for(int k = 0; k <= 10; k++){
	int k = 0;
		for(int i = 0; i < PNGWidth; i++){
			if(i < 1 || i > 9){
				*(*p)(i, k) = b;
				// (*p)(i, k)->blue = 0;
				// (*p)(i, k)->green = 0;
			}

		}
		for(int i = 0; i < PNGHeight; i++){
			*(*p)(k, i) = b;
			// (*p)(k, i)->blue = 0;
			// (*p)(k, i)->green = 0;
		}
	//}
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			Square s = maze[i][j];
			//cout<<"x = "<<i<<" y = "<<j<<endl;
			if(s.rightWall){
				//cout<<"drawright"<<endl;
				//cout<<"x = "<<i<<" y = "<<j<<endl;
				blacken(*p, i, j, 0);
			}
			if(s.bottomWall){
				//cout<<"drawbottom"<<endl;
				//cout<<"x = "<<i<<" y = "<<j<<endl;
				blacken(*p, i, j, 1);
			}
		}
	}
	return p;
}
PNG* SquareMaze::drawMazeWithSolution(){
	PNG* p = drawMaze();
	//vector<int> path = solveMaze();
	// path.push_back(1);
	// path.push_back(0);
	// path.push_back(1);
	// path.push_back(0);
	int x = 5;
	int y = 5;
	for(auto &dir: path)
		fillRed(*p, x, y, dir);

	x = x - 5;
	y = height * 10;
	for(int i = 1; i < 10; i++)
		*(*p)(x + i, y) = w;
	return p;
}



