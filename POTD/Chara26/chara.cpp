#include "chara.h"

Chara::Chara(){

	head = NULL;
	tail = NULL;

}
Chara::~Chara(){
	while(getStatus() != "Empty")
		popFromQueue();
}
string Chara::getStatus(){
	node* p = head;
	int n = 0;
	while(p != NULL){
		p = p->next;
		n++;
	}
	if(n == 0)
		return "Empty";
	
	if(n <= 3)
		return "Light";

	if(n <= 6)
		return "Moderate";

	return "Heavy";
}


void Chara::addToQueue(string name){

	node* p = new node();
	p->data = name;
	p->next = NULL;

	if(getStatus() == "Empty"){
		head = p;
		tail = p;
	}
	else{
		tail->next = p;
		tail = p;
	}

}

string Chara::popFromQueue(){
	if(head == NULL)
		return " ";
	node* p = head;
	head = head->next;
	string s = p->data;
	delete p;
	return s;
}
