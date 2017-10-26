#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long bernstein(string str, int M)
{
	unsigned long b_hash = 5381;
	//Your code here
	for(unsigned long i = 0; i < str.length(); i++){
		//b_hash = b_hash * 33 + char; 
		//33 is the magic number for no reason;
		b_hash = b_hash*33 + (int)str[i];
	}
	return b_hash % M;
}

string reverse(string str)
{
	reverse(str.begin(), str.end());
	//Your code here

	return str;
}

int main()
{	
	string s = "POTS";
	int M = 13;
	cout<<"Bernstein hash of "<<s<<" with range "<<M<<" is: "<<bernstein(s, M)<<'\n'; 	
	cout<<"Bernstein hash of the reverse of "<<s<<" - " <<reverse(s)<<" - with range "<<M<<", is: "<<bernstein(reverse(s), M)<<'\n';
}
