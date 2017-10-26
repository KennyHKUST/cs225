#include <string>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
//first map each char of the pattern with a number
//represent the pattern as a list of number
//do the same for the str
//compare if two vectors are the same


bool wordPattern(string pattern, string str) {
	vector<int> vpattern;
	vector<int> vstr;
	map<char, int> mymap;
	for(unsigned long i = 0; i < pattern.length(); i++){
		auto it = mymap.find(pattern[i]);
		if(it == mymap.end()){
			if(mymap.begin() == mymap.end()){
				mymap.insert(pair<char, int>(pattern[i], 0));
				vpattern.push_back(0);	
			}
			else{
				it--;
				mymap.insert(pair<char, int>(pattern[i], it->second + 1));
				vpattern.push_back(it->second + 1);	
			}
			//vpattern.push_back(it->second + 1);
		}
		else
			vpattern.push_back(it->second);		
	}

    //write your code here
    unordered_map<string, int> mystring;
    stringstream ss(str);
    //vector<string> tokens;
    string buf;
    while (ss >> buf){
    	//cout<<buf<<endl;
        auto it = mystring.find(buf);
		if(it == mystring.end()){
			if(mystring.begin() == mystring.end()){
				mystring.insert(pair<string, int>(buf, 0));
				vstr.push_back(0);	
			}
			else{
				int n = 0;
				for(auto &key_val: mystring){
					if(key_val.second > n)
						n = key_val.second;
				}
				mystring.insert(pair<string, int>(buf, n+1));
				vstr.push_back(n + 1);	
			}
		}
		else
			vstr.push_back(it->second);		
    }


	// for(unsigned long i = 0; i < vstr.size(); i++)
	// 	cout<<vstr[i]<<endl;

    if(vpattern == vstr)
    	return true;
    return false;
}

int main(){

string s1= "dog cat cat cat cat cat cat cat dog";
string p1 = "abbbbbbba";
string s2 = "fish dog dog dog dog dog dog cat";
string p2 = "abbbbbba";
cout << " The pattern p1 matches string s1 " << wordPattern(p1,s1)<< endl;
cout << " The pattern p2 matches string s2 " << wordPattern(p2,s2)<< endl;
 





return 0;

}


