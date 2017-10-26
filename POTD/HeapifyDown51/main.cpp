#include <iostream>
#include <vector>

using namespace std;

// Priority Queue
vector<int> priorityqueue {-65536, 12, 7, 8, 4, 6, 5, 3 ,1};

// 
void enQueue(const int &x){
	priorityqueue.push_back(x);
	int hole = priorityqueue.size() - 1;
	for(; hole > 1 && x > priorityqueue[hole/2]; hole /= 2){
		priorityqueue[hole] = priorityqueue[hole/2];
	}
	priorityqueue[hole] = x;
}

int maxChild(int hole){
	if(priorityqueue[hole * 2] > priorityqueue[hole * 2 + 1])
		return hole * 2;
	return hole * 2 + 1;
}
void percolateDown(int hole){
	// Your codes here.
	int size = priorityqueue.size() - 1;
	while(hole*2 <= size){
		//cout<<"hole is now "<<hole<<endl;
		if(priorityqueue[hole] < priorityqueue[maxChild(hole)]){
			//cout<<"child now is "<<priorityqueue[hole]<<" maxChild is "<<priorityqueue[maxChild(hole)]<<endl;
			int max = maxChild(hole);
			swap(priorityqueue[hole], priorityqueue[maxChild(hole)]);
			hole = max;
		}
		else
			break;

	}

}
void printQueue(){
	cout << "Current Priority Queue is: ";
	for(auto i = priorityqueue.begin() + 1; i != priorityqueue.end(); ++i){
		cout << *i << " ";
	}
	cout << endl;
}
int deQueue(){
    int minItem = priorityqueue[1];
    priorityqueue[1] = priorityqueue[priorityqueue.size() - 1];
    priorityqueue.pop_back();
    percolateDown(1);
    //printQueue();
    return minItem;
}



int main() {
	enQueue(13);
	enQueue(-1);
	enQueue(10);
	enQueue(15);
	printQueue();
	while(priorityqueue.size() != 1){
		cout << deQueue() << " Pop from Priority Queue" << endl;
	}
	return 0;	
}
