#include <iostream>
#include <queue>
#include <string>
using namespace std;

vector<int> zigZag(vector<int> v1, vector<int> v2){

	//write your code here
	priority_queue<int> q1;
	priority_queue<int> q2;
	for(auto val: v1)
		q1.push(val);
	for(auto val: v2)
		q2.push(val);

	vector<int> result;
	while(!q1.empty() && !q2.empty()){
		result.push_back(q1.top());
		result.push_back(q2.top());
		q1.pop();
		q2.pop();
	}
	while(!q1.empty()){
		result.push_back(q1.top());
		q1.pop();
	}
	while(!q2.empty()){
		result.push_back(q2.top());
		q2.pop();
	}
	return result;

}


int main(){

vector<int> v1, v2;
v1 = {50,40,20,30,10};
v2 = {1,2,3,4,5};

vector<int>answer = zigZag(v1,v2);

cout << "The zig zag vector is " <<endl;
for (int i =0; i < answer.size(); i ++){
	cout << answer[i]<<endl;
}

return 0;

}
