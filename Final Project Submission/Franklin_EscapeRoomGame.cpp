
//Escape Room Game
//-text-based adventure

//This program will be a game that continually takes user inputs as commands and translates
//them into things that will happen in the Game

#include <iostream>
#include <fstream>

using namespace std;

int selectDifficulty();
void rules();
void roomDescription();
string getCommand();
void resultOfCommand();
void statusUpdate();


int main()
{
  cout << "Here is a welcome message: " << endl;
//welcome message
  selectDifficulty();
//  difficulty menu
//  user selects difficulty
//  function returns difficulty
  rules();
//  give user lit of commands and rules
  roomDescription();
//  give user description of Room
//loop
  getCommand();
//    get user input for command
//    format input so it can be read
//    return command
  resultOfCommand();
//    check result of command
//    update variables based on result
//    display result in text
  statusUpdate();
//    check health
//    incriment and check time
//    check game status
  cout << "Here is the end-of-game message:" << endl;
//display end-of-game message
}

int selectDifficulty()
{
  cout << "Here is the difficulty menu" << endl;
  //  difficulty menu
  //  user selects difficulty
  cout << "You have selcted difficulty " << difficulty << endl;
  //  function returns difficulty
}

void rules()
{
  cout << "Here are the rules and commands:" << endl;
  //  give user lit of commands and rules
}

void roomDescription()
{
  cout << "Here is a description of the room:" << endl;
  //  give user description of Room
}

string getCommand()
{
  cout << "Getting user input for command" << endl;
  //    get user input for command
  //    format input so it can be read
  cout << "Got command: " << command << endl;
  //    return command
}

void resultOfCommand()
{
  cout << "checking the result of the command..." << endl;
  //    check result of command
  cout << "Updating variables.." << endl;
  //    update variables based on result
  cout << "Here is the result:" << endl;
  //    display result in text
}

void statusUpdate()
{
  cout << "Checking player health..." << endl;
  //    check health
  cout << "Checking time..." << endl;
  //    incriment and check time
  cout << "Checking game status..." << endl;
  //    check game status
}
