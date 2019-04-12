#include <iostream>
#include <fstream>

using namespace std;
//doubly link list node
class DlNode
{
public:
  int data;
  DlNode *prev;
  DlNode *next;
  int time;

  static DlNode* getnode(int data)
   {
       DlNode* newNode = (DlNode*)malloc(sizeof(DlNode));
       newNode->data = data;
       newNode->prev = newNode->next = NULL;
       return newNode;
   }


};
