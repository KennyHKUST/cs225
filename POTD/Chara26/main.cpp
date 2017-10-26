#include <iostream>
#include "chara.h"
using namespace std;


int main() {
  Chara c;
  c.addToQueue("as");
  c.addToQueue("ad");
  c.addToQueue("ab");
  c.addToQueue("ae");
  c.addToQueue("af");
  c.addToQueue("ag");
  cout<<c.getStatus()<<endl;
  cout<<c.popFromQueue()<<endl;
  cout<<c.popFromQueue()<<endl;
  cout<<c.popFromQueue()<<endl;
  cout<<c.getStatus()<<endl;
  cout<<c.popFromQueue()<<endl;
  cout<<c.popFromQueue()<<endl;
  cout<<c.getStatus()<<endl;
  cout<<c.popFromQueue()<<endl;
  cout<<c.getStatus()<<endl;
  cout<<c.popFromQueue()<<endl;
  return 0;
}
