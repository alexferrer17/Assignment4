#include "Queue.h"

class StudentQueue
{
private:
  Queue line;
  int total;
  int timewaited[1000];
public:
  StudentQueue(); //constructor
  ~StudentQueue();//DESTRUCTOR
  void enterQueue(int wait); //enters an element to the queue
  void exitQueue();
  void incrementWaitTime(); //increments time by one
  int looktTimeWaited(); //peeks at time waited
  void exitLine();

  bool isEmpty();
  int getTotal(); //returns the toal



};
