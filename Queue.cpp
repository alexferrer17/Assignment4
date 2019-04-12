#include <iostream>
#include <fstream>
#include "Queue.h"
//Generic queue made by a doubly link list

using namespace std;


Queue::Queue()
{
  front = rear = NULL;
  size = 0;
}

Queue::~Queue()
{
  //destructur
}

void Queue::insertFront(int data)
{

 DlNode* newNode = DlNode::getnode(data);
  //if this is true then the new element cant fit in the queue
  //this can be an Overflow condition
  if(newNode == NULL)
  {
    cout << "Overflow" << '\n';
  }

  else //it can be added
  {
    if(front == NULL)
    {
      rear = front;
      front = newNode;
    }
    else //if front is not empty we have to move the poointers forward
    {
      newNode->next = front;
      front->prev = newNode;
      front = newNode;
    }
    //adds one to the size
    size++;
  }
}


void Queue::insertRear(int data)
{
  DlNode* newNode = DlNode::getnode(data);
  //If true can't fit a new key
  if(newNode == NULL)
  {
    cout << "Overflow" << '\n';
  }
  else //pointer exists
  {
    if(rear == NULL) //if there is no rear
    {
      front = rear;
      rear = newNode;
    }
    else //if there is at least one key
    {
      newNode->prev = rear;
      rear-> next = newNode;
      rear = newNode;

    }
    //add to size
    size++;
  }
}

void Queue::deleteFront()
{

  if (isEmpty())
  {
    cout << "Underflow" << '\n';
  }
  else
  {
    DlNode* temp = front;
       front = front->next;

       //if there is only one key
       if (front == NULL)
       {
          rear = NULL;
       }

       else
       {
          front->prev = NULL;
       }

       free(temp); //destructur for temp

       // Decrements size by 1
       size--;
  }
}

void Queue::deleteRear()
{
  //if there is no pointer
  if (isEmpty())
  {
    cout << "Underflow" << '\n';
  }
  else
  {
    DlNode* temp = rear;
    rear = rear->prev;

    //if there is only one key
    if(rear == NULL)
    {
      front = NULL;
    }
    else
    {
      rear->next = NULL;
    }
    free(temp);
    //decrease size
    size--;

  }
}

bool Queue::isEmpty()
{
  return (front == NULL);
}

void Queue::incrementWT()
{
  DlNode * temp = front;
  while(temp != nullptr)
  {
    temp ->time++;
    temp = temp -> next;
  }
}
