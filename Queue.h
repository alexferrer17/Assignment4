
#include "DlNode.h"

using namespace std;
//header to represent a queue made of a doubly link list
class Queue
{
private:
  int size;

public:
  DlNode* front;
  DlNode* rear;
  Queue();
  ~Queue();
  void insertFront(int key);
  void insertRear(int key);
  void deleteFront();
  void deleteRear();
  void incrementWT();

  bool isEmpty();

};
