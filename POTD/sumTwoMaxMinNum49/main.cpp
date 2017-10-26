#include <iostream>
#include <queue>
#include <string>
using namespace std;

vector<int> checkSums(vector<int> v){


	//write your code here
	vector<int> sums;
	priority_queue<int> q;
	priority_queue<int, vector<int>, greater<int>> q2;
	for(auto val: v){
		q.push(val);
		q2.push(val);
	}
	int sum = q.top();
	q.pop();
	sum += q.top();
	sums.push_back(sum);
	int smallSum = q2.top();
	q2.pop();
	smallSum += q2.top();
	sums.push_back(smallSum);
	

	return sums;
}


int main(){

vector<int> v1;

v1 = {20,32,12,65,0,19,76,15,2,39};

vector<int>answer = checkSums(v1);

cout << "The sum of the sum of the largest two elements is " << answer[0] <<endl;
cout << "The sum of the sum of the smallest two elements is " << answer[1] <<endl;

return 0;

}
