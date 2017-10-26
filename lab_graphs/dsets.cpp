/* Your code here! */
#include "dsets.h"

#include <iostream>
void DisjointSets::addelements(int num){
	while(num > 0){
		set.push_back(-1);
		num--;
	}


}
int DisjointSets::find(int elem){
	if(set[elem] < 0)
		return elem;
	int parent = find(set[elem]);
	set[elem] = parent;
	return parent;

}

void DisjointSets::setunion(int a, int b){
	int roota = find(a);
	int rootb = find(b);
	if(roota == rootb)
		return;
	int newsize = set[roota] + set[rootb];
	//std::cout<<"current a is "<<a<<" current b is "<<b<<std::endl;
	//std::cout<<"current set[a] is "<<set[a]<<" current set[b] is "<<set[b]<<std::endl;
	if(set[roota] > set[rootb]){
		//set[b] += set[a];
		//cout<<"set["<<roota<<"] = "<<rootb<<endl;
		set[rootb] = newsize;
		set[roota] = rootb;
	}
	// else if(b > a){
	// 	set[b] = newsize;
	// 	set[a] = b;
	// }
	else{
		//set[a] += set[b];
		//cout<<"set["<<rootb<<"] = "<<roota<<endl;
		set[roota] = newsize;
		set[rootb] = roota;
	}

} 