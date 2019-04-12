#include <iostream>
#include <fstream>
#include "Register.h"


Register::Register() //constructor
{
  data = StudentQueue();
  line2 = StudentQueue();
}
Register::~Register()
{
  //DESTRUCTOR
}

void Register::printStats() //prints all the statistics for the programme
{
  int count = data.getTotal();
  int timewaited[count];
  for (int i = 0; i < count; i++)
  {
    timewaited[i] = data.looktTimeWaited();
    data.exitLine();
  }

  float median;

  for(int i = 0; i < count; i++)
  {

    for(int j = i; j > 0 && timewaited[j-1] > timewaited[j]; j--)
    {
      int tmp = timewaited[j];
      timewaited[j] = timewaited[j - 1];
      timewaited[j - 1] = tmp;
    }
  }


  if(count%2 != 0)
  {
    median = timewaited[count/2];
  }
  else
  {
    median = (timewaited[count/2] + timewaited[count/2 - 1])/2.0;
  }
  float meanWait = 0.0;
  int countTen = 0;
  int longestWait = 0;
  for(int i = 0; i < count; i++)
  {
    meanWait += timewaited[i];
    if(timewaited[i] > 10)
    {
      countTen++;
    }
    if(timewaited[i] > longestWait)
    {
      longestWait = timewaited[i];
    }
  }
  meanWait = meanWait / count;

  int longestIdle = 0;
  int idleFive = 0;
  float meanIdle = 0.0;

  for(int i = 0; i < windowSize; i++) //goes through the waited data
  {
    meanIdle += Data[i];
    if(Data[i] > longestIdle)
    {
      longestIdle = Data[i];
    }
    if(Data[i] > 5)
    {
      idleFive++;
    }
  }
  meanIdle = meanIdle / windowSize;
  cout << "The mean for the wait time: " << meanWait << endl;
  cout << "The median wait time: " << median << endl;
  cout << "Mean window idle time: " << meanIdle << endl;
  cout << "Longest window idle time: " << longestIdle << endl;
  cout << "Longest wait time: " << longestWait << endl;
  cout << "Count of how many waited over 10 minutes: " << countTen << endl;
  cout << "Number of windows idle over 5 min: " << idleFive << endl;
}




void Register::RunSimulation(string fileName) //runs enterely the programme
{

  cout << "Registrars Office simulation" << endl;
  string firstLine = "";
  fstream file(fileName);
  if(file.is_open())
  {
    //std::cout << "inside the file" << '\n';
    int time = 0;
    getline(file,firstLine);
    openWindow(stoi(firstLine));
    getline(file,firstLine);
    int timeMarker = stoi(firstLine);
    isNew = true;
    int number1 = 0;

    while(true)
    {
      if(time == timeMarker)
      {
        isNew = false;
        getline(file,firstLine);
        number1 = stoi(firstLine);
        for(int i = 0; i < number1; i++)
        {
          getline(file,firstLine);
          line2.enterQueue(stoi(firstLine));
        }
        getline(file,firstLine);

        if(!file.eof())
        {
          timeMarker = stoi(firstLine);
        }
      }
      lineWindow();
      line2.incrementWaitTime();
      if(isDone() && !isNew)
      {
        break;
      }
      decreaseTime();
      time++;
    }
    printStats();


  }
}

void Register::openWindow(int a)
{
  window = new int[a];
  Data = new int[a];
  windowSize = a;
  for(int i = 0; i < a; i++)
  {
    window[i] = 0;
    Data[i] = 0;
  }
}

void Register::lineWindow()
{
  for(int i = 0; i < windowSize; i++)
  {
    if(window[i] == 0 && !line2.isEmpty())
    {
      window[i] = line2.looktTimeWaited();
      data.enterQueue(line2.looktTimeWaited());
      line2.exitLine();
    }
  }
}
bool Register::isDone() //method indicates when finished
{
  for(int i=0; i<windowSize; i++)
  {
    if(window[i]!=0)
    {
      return false;
    }
  }
  return true;
}
void Register::decreaseTime() //decrements time by 1
{
  for (int i = 0; i < windowSize; i++)
  {
    if (window[i] == 0)
    {
      Data[i]++;
    }
  }

  for (int i = 0; i < windowSize; i++)
  {
    if (window[i] != 0)
    {
      window[i]--;
    }
  }
}
