#include "StudentQueue.h"

class Register
{
private:
  StudentQueue line2;
  StudentQueue data;
  int *window;
  int *Data;
  int windowSize; //how many windows they are
  bool isNew;
public:
  Register(); //constructor
  ~Register();

  void printStats(); //prints all the stats for the programme
  void RunSimulation(); //initializes the programme
  void decreaseTime(); //decrements the time by 1
  void openWindow(int a); //opens a new window
  void lineWindow(); //tells the information about times in the line
  bool isDone(); //checks if its done


};
