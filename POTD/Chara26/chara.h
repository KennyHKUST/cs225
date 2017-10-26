#ifndef _CHARA_H
#define _CHARA_H

#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Chara {
public:
	string getStatus();
  	void addToQueue(string name);
  	string popFromQueue();
  	Chara();
  	~Chara();
private:
	struct node{
		node* next;
		string data;
	};
	//int size;
	node* head;
	node* tail;
};

#endif
