#include "StudentQueue.h"

StudentQueue::StudentQueue()
{
  line = Queue();
  total = 0;
}
StudentQueue::~StudentQueue()
{
  //destructur
}
void StudentQueue::enterQueue(int wait)
{
  line.insertFront(wait);
}
void StudentQueue::exitQueue()
{
  line.deleteFront();
}
bool StudentQueue::isEmpty()
{
  return line.isEmpty();
}
void StudentQueue::incrementWaitTime()
{
  line.incrementWT();
}
int StudentQueue::getTotal()
{
  return total;
}
int StudentQueue::looktTimeWaited()
{
  return line.front->time;
}
void StudentQueue::exitLine()
{
  line.deleteFront();
}
