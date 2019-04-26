
//Escape Room Game
//-text-based adventure

//This program will be a game that continually takes user inputs as commands and translates
//them into things that will happen in the Game

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

const int LOSE = 0, WIN = 1, PLAYING = 2;
const int INITIAL = 0, WATERED = 1, HARVESTED = 3, GROWN = 4, DESTROYED = 5, OPEN = 7, OFF = 9, DEAD = 10, FED = 11, EMPTY = 12, MOVED = 13, EATEN = 14, GIVEN = 15, USED = 16, BURNED = 17;

int selfExams=0;
int radioState=INITIAL,doorState=INITIAL,parrotState=INITIAL,plantState=INITIAL,rackState=INITIAL,bucketState=INITIAL,carpetState=INITIAL,ventState=INITIAL,paintingState=INITIAL,chestState=INITIAL,candleState=INITIAL,peanutStateL=INITIAL,lampState=INITIAL,keypadState=INITIAL,keyState=INITIAL,underwearState=INITIAL,bedState=INITIAL,forkState=INITIAL,ratState=INITIAL,peanutState=INITIAL;
bool candleOnNightstand = true, lampLight = true, fire = true, riddle = false;

int selectDifficulty(int& maxMoves);
void displayRules();
void roomDescription();
void getCommand(string commandAction, string commandObject, string& command);
void resultOfCommand(string command, int& gameStatus, string objectUsedOn, int& moves);
void statusUpdate(int maxMoves, int& moves);
void getObject(string& objectUsedOn);
void displayEndScreen(int gameStatus, int maxMoves, int moves);




int main()
{

  int gameStatus = PLAYING;
  int maxMoves, moves;
  string commandAction, commandObject, command, objectUsedOn;

  cout << "Welcome to the Franklin Escape Room Game!" << endl;
  cout << "This is a text-based game in which the user enters commands in an attempt to escape the room" << endl  << endl;

  displayRules();

  cout << "--------------------------------------------------------------------------------------------------" << endl << endl;

  selectDifficulty(maxMoves);

  cout << "--------------------------------------------------------------------------------------------------" << endl << endl;
  cout << "You awake to the sound of a funky tune suddenly starting up." << endl;
  cout << "Still sleepy, you sit up, only to realize this isn't your BED" << endl;
  cout << "You get out of the BED and quickly realize that this isn't your ROOM either" << endl << endl;

  roomDescription();

  cout << "--------------------------------------------------------------------------------------------------" << endl;

  for (moves = 1; moves <= maxMoves && gameStatus == PLAYING; moves++)
  {
    statusUpdate(maxMoves, moves);
    getCommand(commandAction, commandObject, command);
    resultOfCommand(command, gameStatus, objectUsedOn, moves);
    cout << "--------------------------------------------------------------------------------------------------" << endl;
  }

  displayEndScreen(gameStatus, maxMoves, moves);

  return 0;
}

int selectDifficulty(int& maxMoves)
{
  int difficulty;

  cout << "To begin, first select your desired difficulty" << endl;

  do
  {
    cout << "\n1.) Easy -no action limit-" << endl;
    cout << "2.) Medium -40 action limit-" << endl;
    cout << "3.) Hard -20 action limit-" << endl;
    cout << "------------------------------" << endl;
    cout << "Enter difficulty 1 through 3: ";
    cin >> difficulty;

    if (cin.fail() || ((difficulty != 1) && (difficulty != 2) && (difficulty != 3)))
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "-Invalid input- Please enter a number 1 through 3" << endl;
    }
  }
  while ((difficulty != 1) && (difficulty != 2) && (difficulty != 3));

  cout << "You have selcted difficulty " << difficulty << endl;

  if (difficulty == 2)
    maxMoves = 40;
  else if (difficulty == 3)
    maxMoves = 20;
  else maxMoves = 999999;

  return difficulty;
}

void displayRules()
{
  cout << "This game works by the player entering two words every turn." << endl;
  cout << "The first word is an action, and the second is the object that is being acted upon" << endl << endl;
  cout << "Here is a list of valid actions:" << endl;
  cout << "Examine, Consume, Attack, Search, Take, Enter, Use" << endl;
  cout << "Objects that can be interacted with are capitalized, e.g. LAMP" << endl;
  cout << "An example of a valid command would be: 'examine lamp'" << endl << endl;
  cout << "You can enter the command 'help' to display this information again" << endl;
}

void roomDescription()
{
  cout << "Looking around, you see that you are in a ROOM about the size of a standard living room. There is a large CARPET on" << endl;
  cout << "the FLOOR that you stood on when you first got out of the BED. The BED is in one corner, and next to it is a" << endl;
  cout << "NIGHTSTAND. On it is an unlit CANDLE and a LAMP, which is plugged into an OUTLET in the WALL. Next to the NIGHTSTAND is" << endl;
  cout << "a potted PLANT, and past that, in the other corner, is a hung PAINTING. On the other side of the ROOM is a FIREPLACE" << endl;
  cout << "with a decent fire going. On one side of it, in the corner, is a BUCKET of water. On the other side, a coat RACK is" << endl;
  cout << "standing tall. On top of the RACK is a live PARROT, just sitting there. Past that, there is a large VENT in the WALL," << endl;
  cout << "and in the corner next to it, there is what looks like a treasure CHEST. At the end of the room is the only DOOR you" << endl;
  cout << "can see, and next to it is a KEYPAD of some sort. Finally, in the middle of the ROOM, there is a large wooden TABLE. On" << endl;
  cout << "the TABLE is the RADIO that woke you up and a silver FORK." << endl;
}

void getCommand(string commandAction, string commandObject, string& command)
{
  cin >> commandAction >> commandObject;
  //cout << commandAction << commandObject << endl;
  command = (commandAction + commandObject);
  //cout << command.size() << endl;
  int commandSize = command.size();

  char commandLetters[commandSize];

  for (int index = 0; index < commandSize; index++)
  {
    command[index] = tolower(command[index]);
  }
  // cout << command;
}

void getObject(string& objectUsedOn)
{
  cin >> objectUsedOn;

  int objectSize = objectUsedOn.size();

  char objectLetters[objectSize];

  for (int index = 0; index < objectSize; index++)
  {
    objectUsedOn[index] = tolower(objectUsedOn[index]);
  }
  objectUsedOn = ("on" + objectUsedOn);
}

void statusUpdate(int maxMoves, int& moves)
{
  if ((maxMoves == 40)||(maxMoves == 20))
    cout << "You have " << (maxMoves - moves + 1) << " moves left" << endl << endl;
}

void displayEndScreen(int gameStatus, int maxMoves, int moves)
{
  if (gameStatus == WIN)
  {
    cout << "  __   __  _______  __   __    _     _  ___   __    _  __  " << endl;
    cout << " |  | |  ||       ||  | |  |  | | _ | ||   | |  |  | ||  | " << endl;
    cout << " |  |_|  ||   _   ||  | |  |  | || || ||   | |   |_| ||  | " << endl;
    cout << " |       ||  | |  ||  |_|  |  |       ||   | |       ||  | " << endl;
    cout << " |_     _||  |_|  ||       |  |       ||   | |  _    ||__| " << endl;
    cout << "   |   |  |       ||       |  |   _   ||   | | | |   | __  " << endl;
    cout << "   |___|  |_______||_______|  |__| |__||___| |_|  |__||__| " << endl;


  }
  else
  {
    cout << " __   __  _______  __   __    ___      _______  _______  _______  __  " << endl;
    cout << "|  | |  ||       ||  | |  |  |   |    |       ||       ||       ||  | " << endl;
    cout << "|  |_|  ||   _   ||  | |  |  |   |    |   _   ||  _____||    ___||  | " << endl;
    cout << "|       ||  | |  ||  |_|  |  |   |    |  | |  || |_____ |   |___ |  | " << endl;
    cout << "|_     _||  |_|  ||       |  |   |___ |  |_|  ||_____  ||    ___||__| " << endl;
    cout << "  |   |  |       ||       |  |       ||       | _____| ||   |___  __  " << endl;
    cout << "  |___|  |_______||_______|  |_______||_______||_______||_______||__| " << endl;

    if (moves > maxMoves)
      cout << "\nYou ran out of moves!" << endl;
  }
}

void resultOfCommand(string command, int& gameStatus, string objectUsedOn, int& moves)
{
  string answer;
  int num;

  if (command == "examinebed")
    cout << "\nThe BED is size double, and it looks very clean and well kept. It was made neatly before you got out of it, but now\nthe covers and sheets are very disturbed and thrown about. There may have been something there that you missed." << endl;
  else if (command == "consumebed")
    cout << "\nYou fail to consume the BED. Why would you want to?" << endl;
  else if (command == "attackbed")
  {
    if (underwearState == INITIAL)
      cout << "\nYou do no real damage to the BED, but while throwing the covers and pillows around you see a pair of UNDERWEAR mixed\nin with the sheets. You were sleeping with that? Gross." << endl;
    else cout << "\nYou fail to do any more real damage to the BED." << endl;
  }
  else if (command == "searchbed")
  {
    if (underwearState == INITIAL)
      cout << "\nRustling through the BED, you find a pair of underwear mixed in with the sheets. You really don't want to think about\nwhere this came from." << endl;
    else cout << "\nYou find nothing else of interest in the BED, save for a few weird stains." << endl;
  }
  else if (command == "takebed")
    cout << "\nUm, the BED is kind of too big to take anywhere. You can't even move it. It might be bolted down." << endl;
  else if (command == "usebed")
  {
    cout << "\nYou enter the bed, cover yourself up, close your eyes, and fall asleep. You have a happy dream. When you wake up\nafter a few hours, your fatigue is gone and you feel very refreshed." << endl;
    if (plantState == WATERED)
      plantState = GROWN;
  }
  else if (command == "enterbed")
  {
    if (bedState == INITIAL)
    {
      cout << "\nYou enter the bed, cover yourself up, close your eyes, and fall asleep. You have a happy dream. When you wake up\nafter a few hours, your fatigue is gone and you feel very refreshed." << endl;
      bedState = USED;
    }
    else cout << "\nYou enter the bed, cover yourself up, close your eyes, and fall asleep. You have a very scary nightmare and wake\nup after less than an hour. You feel exhausted." << endl;
  }




  else if (command == "examineplant")
  {
    if (plantState == INITIAL)
      cout << "\nThe PLANT looks like it is healthy and growing nicely. You don't recognize what kind of plant it is, but you don't\nbelieve it bears fruit. You think something good might happen if you continue to care for it, though." << endl;
    else if (plantState == WATERED)
      cout << "\nThe PLANT you watered seems to be growing by the second! If you can find a way to wait for a few hours, it should be\nfully grown by then." << endl;
    else if (plantState == GROWN)
      cout << "\nThe PLANT is fully grown now! On close inspection you see that this was a peanut plant all along, and a big PEANUT\nis poking out of the dirt in the pot. It must have grown from you watering it." << endl;
    else if (plantState == HARVESTED)
      cout << "\nThe PLANT has no more peanuts you can harvest, but it is very pretty now that it is fully grown." << endl;
    else if (plantState == DESTROYED)
      cout << "\nThe pot is shattered on the ground, and dirt is spread all around it, with  pieces of the PLANT that have fallen\noff the main body sticking out." << endl;
    else if (plantState == EATEN)
      cout << "\nYou ate the PLANT earlier. It is gone." << endl;
    else if (plantState == BURNED)
      cout << "\nThe PLANT is burnt to a crisp." << endl;
  }
  else if (command == "consumeplant")
    {
      if ((plantState != EATEN)&&(plantState != BURNED))
      {
        cout << "\nThrough greuling effort and much time, you manage to entirely consume the PLANT. It tasted horrible and you felt\nsomething crunchy in there somewhere. It was not worth it." << endl;
        plantState = EATEN;
      }
      else cout << "\nYou already ate the PLANT." << endl;
    }
  else if (command == "attackplant")
  {
    if ((plantState != DESTROYED)&&(plantState != EATEN)&&(plantState != BURNED))
    {
      cout << "\nYou walk up to the PLANT with rage in your eyes. You start punching at its leaves, knocking some of them off and\nsnapping some stems. Then you pick up the pot it is in and smash it on the ground, scattering dirt and PLANT pieces\neverywhere." << endl;
      plantState = DESTROYED;
    }
    else cout << "\nyou are not able to destroy the PLANT any more." << endl;
  }
  else if (command == "searchplant")
  {
    if ((plantState != DESTROYED)&&(plantState != EATEN)&&(plantState != BURNED))
    {
      if (plantState != HARVESTED)
        cout << "\nYou dig through the dirt in the pot a bit and find a PEANUT grwing from the PLANT. This must be a peanut PLANT. It looks\npretty tasty." << endl;
      else cout << "\nYou don't find anything else useful in the PLANT or the pot." << endl;
    }
    else cout << "\nThere isn't really anything to search through." << endl;
  }
  else if (command == "takeplant")
   cout << "\nYou are now carrying the potted PLANT" << endl;
  else if (command == "enterplant")
  {
    cout << "\nYou try to enter the pot, but you only manage to step on the PLANT, and you accidentaly push down so hard in an effort to enter the pot that you break it into pieces." << endl;
    plantState = DESTROYED;
  }
  else if (command == "useplant")
  {
    if ((plantState != DESTROYED)&&(plantState != EATEN)&&(plantState != BURNED))
    {
      cout << "\nWhat do you want to use the plant on? ";
      getObject(objectUsedOn);

      if (objectUsedOn == "ondoor")
      {
        cout << "\nYou throw the potted PLANT against the DOOR, smashing the pot to pieces and destroying the PLANT." << endl;
        plantState = DESTROYED;
      }
      else if (objectUsedOn == "onfloor")
        cout << "\nYou put the PLANT on the FLOOR" << endl;
      else if (objectUsedOn == "onwall")
      {
        cout << "\nYou throw the potted PLANT against the WALL, smashing the pot to pieces and destroying the PLANT." << endl;
        plantState = DESTROYED;
      }
      else if (objectUsedOn == "onfireplace")
      {
        if (fire == true)
        {
          cout << "\nYou throw the PLANT into the fire, and it burns to a crisp." << endl;
          plantState = BURNED;
        }
        else if (fire = false)
          cout << "\nThat does not do anything except get ashes on the PLANT." << endl;
      }
      else if (objectUsedOn == "onrats")
        cout << "\nThe RATS do not at all seemed phased by the PLANT." << endl;
      else if (objectUsedOn == "onunderwear")
        cout << "\nThis manages to make the UNDERWEAR smell a bit better" << endl;
      else if (objectUsedOn == "onman")
        cout << "\nThe man does not seem interested in the PLANT. He said he wanted something valuable." << endl;
      else if (objectUsedOn == "onhole")
        cout << "\nThe PLANT kind of manages to cover up the hole, but you can still clearly see it." << endl;
      else cout << "\nThat does not do anything." << endl;
    }
    else cout << "\nThe PLANT is no more..." << endl;
  }




  else if (command == "examinedoor")
  {
    if (doorState == INITIAL)
      cout << "\nThe DOOR is a solid block of metal with a handle. You do not see any hinges, and assume it opens on some internal\nmechanism. You can't tell how thick it is, but you know you won't be able to break it down." << endl;
    else if (doorState == OPEN)
      cout << "\nThe DOOR is now open, and your path to freedom awaits." << endl;
  }
  else if (command == "consumedoor")
    cout << "\nYou fail to consume the DOOR. Obviously." << endl;
  else if (command == "attackdoor")
    cout << "\nYou cannot even manage to leave a single scratch on it." << endl;
  else if (command == "searchdoor")
    cout << "\nThere is nothing to search through here." << endl;
  else if (command == "takedoor")
    cout << "\nYou cannot take the DOOR." << endl;
  else if (command == "enterdoor")
  {
    if (doorState == INITIAL)
      cout << "\nThe DOOR is locked shut. You cannot enter it at this point." << endl;
    else if (doorState == OPEN)
    {
      cout << "You walk through the DOOR and safely escape the ROOM!" << endl;
      gameStatus = WIN;
    }
  }
  else if (command == "usedoor")
  {
    if (doorState == INITIAL)
      cout << "\nThe DOOR is locked shut. You cannot enter it at this point." << endl;
    else if (doorState == OPEN)
    {
      cout << "You walk through the DOOR and safely escape the ROOM!" << endl;
      gameStatus = WIN;
    }
  }





  else if (command == "examinefloor")
  {
    cout << "\nIt is a standard hardwood FLOOR. It seems pretty solid to you.";
    if (rackState == INITIAL)
      cout << " There is a spot near the coat RACK that looks to be \ndifferent color than the rest of it." << endl;
    else cout << " There is a HOLE in the FLOOR where the RACK fell over." << endl;
  }
  else if (command == "consumefloor")
    cout << "\nYou fail to consume the FLOOR. Where would you even start?" << endl;
  else if (command == "attackfloor")
    cout << "\nYou stomp as hard as you can on the FLOOR all over the ROOM. When you stomp near the coat RACK, one of the\nfloorboards comes loose and reveals a HOLE in the FLOOR, but falls back into place after. You now know there is a hole,\nhowever." << endl;
  else if (command == "searchfloor")
    cout << "\nYou feel around every inch of the floor, and find a HOLE near the RACK being covered up by a loose floorboard.\nYou also feel something under the CARPET." << endl;
  else if (command == "takefloor")
    cout << "\nYou cannot take the FLOOR." << endl;
  else if (command == "enterfloor")
  {
    if ((carpetState == MOVED)&&((underwearState != GIVEN)||(riddle == false)))
      cout << "\nYou cannot exit through the FLOOR until you pass the old MAN's tests." << endl;
    else if ((carpetState != MOVED))
      cout << "\nYou cannot see anywhere to enter the FLOOR. You don't know about the CARPET though." << endl;
    else if ((carpetState == MOVED)&&(underwearState == GIVEN)&&(riddle == true))
    {
      cout << "\nYou exit the ROOM through the FLOOR and successfully escape!" << endl;
      gameStatus = WIN;
    }
  }
  else if (command == "usefloor")
    cout << "\nYou sit on the floor." << endl;






  else if (command == "examinewall")
    {
      cout << "\nThe WALL is made of brick, and it seems very sturdy and solid. You don't hear anything when you put your ear to it.\nThere is the FIREPLACE and VENT on one WALL, and the DOOR and KEYPAD on\nthe other.";
      if (paintingState == INITIAL)
        cout << "There is also a PAINTING on the same side that has the NIGHTSTAND." << endl;
    }
  else if (command == "consumewall")
    cout << "\nYou fail to consume the WALL. Like, which WALL? All of them? Are you trying to eat your way out?" << endl;
  else if (command == "attackwall")
    cout << "\nYou only hurt yourself trying to break down the WALL. You won't be able to escape that way." << endl;
  else if (command == "searchwall")
    cout << "\nYou can't find anything new that you can't see from just looking at the ROOM." << endl;
  else if (command == "takewall")
    cout << "\nYou cannot take the WALL" << endl;
  else if (command == "enterwall")
    cout << "\nThere is no place to enter the wall, except maybe through the VENT." << endl;
  else if (command == "usewall")
    cout << "There is nothing you can use the WALL on." << endl;





  else if (command == "examineradio")
  {
    if (radioState == INITIAL)
      cout << "\nThe RADIO is a model which you've never seen before. There are no knobes, dials, or anything to control it except\nfor one main button to turn it on and off." << endl;
    else if (radioState == DESTROYED)
      cout << "\nThe RADIO has been destroyed. Its various bits and pieces are strewn all over the TABLE, but you see nothing that \ncan help you. You are beiginning to miss the amazing music it provided you." << endl;
  }
  else if (command == "consumeradio")
  {
    cout << "\nYou are not able to consume the RADIO, but in trying to, your saliva seeped into it and caused a malfunction. You\nare still able to turn it back on, however" << endl;

  }
  else if (command == "attackradio")
  {
    if (radioState == INITIAL)
      cout << "\nYou attack the RADIO with a flurry of punches, but it is too sturdy. You'll have to do something else to destroy it." << endl;
    else if (radioState == DESTROYED)
      cout << "\nThe RADIO is already destroyed. There is nothing you could do to it, anyway." << endl;
  }
  else if (command == "searchradio")
  cout << "\nYou are unable to find anything useful in the RADIO." << endl;
  else if (command == "takeradio")
  cout << "\nYou are now carrying the RADIO" << endl;
  else if (command == "enterradio")
  cout << "\nYou cannot enter the RADIO." << endl;
  else if (command == "useradio")
  {
    if (radioState != DESTROYED)
    {
      cout << "\nWhat do you want to use the RADIO on? ";
      getObject(objectUsedOn);

      if (objectUsedOn == "onfloor")
        cout << "\nYou play the RADIO near the FLOOR, and you thinkn you might hear something near the CARPET." << endl;
      else if (objectUsedOn == "onfireplace")
      {
        if (fire = true)
        {
          cout << "\nYou throw the RADIO in the FIREPLACE, and it is destroyed in the fire." << endl;
          radioState = DESTROYED;
        }
        else cout << "\nThat does not do anything." << endl;
      }
      else if (objectUsedOn == "onself")
        cout << "\nYou start jamming out to those funky tunes!" << endl;
      else if (objectUsedOn == "onparrot")
      {
        if ((parrotState != DEAD)&&(parrotState != EATEN))
          cout << "\nThe PARROT starts bobbing its head to the funky jams!" << endl;
        else cout << "\nYou take the RADIO and dance over the PARROT's corpse." << endl;
      }
      else if (objectUsedOn == "onbucket")
      {
        if ((bucketState != DESTROYED)&&(bucketState != EMPTY))
        {
          cout << "\nYou throw the RADIO in the water BUCKET, and it short-circuits. There are a few small explosions in the RADIO,\nand it is destroyed. You take it out of the BUCKET afterwards." << endl;
          radioState = DESTROYED;
        }
        else cout << "\nThat does not do anything. There is no water." << endl;
      }
      else if (objectUsedOn == "oncarpet")
      {
        if (carpetState == INITIAL)
          cout << "\nYou think you might hear what sounds like humming coming from below the CARPET." << endl;
        else cout << "\nThat does not do anything." << endl;
      }
      else if (objectUsedOn == "onrats")
        cout << "\nThe RATS seem to calm down a bit when you bring the music over to them. A few of them begin wagging their tails, but\nthey revert to the way they were before after a while." << endl;
      else if (objectUsedOn == "onman")
        cout << "\nThe MAN appreciates the tunes, and starts humming and dancing a bit to the music." << endl;
      else cout << "\nThat does not do anything." << endl;
    }
    else cout << "\nThe RADIO is destroyed." << endl;
  }





  else if (command == "examinenightstand")
  {
    cout << "\nThe NIGHTSTAND is just a small wooden set of drawers right next to the BED. On it is the LAMP";
    if (candleOnNightstand == true)
      cout << " and the CANDLE";
    cout << "." << endl;
  }
  else if (command == "consumenightstand")
    cout << "\nYou fail to consume the NIGHTSTAND. Please just stop." << endl;
  else if (command == "attacknightstand")
    cout << "\nYou take out your frustration on the innocent NIGHTSTAND, but you are unable to damage it. You are too weak." << endl;
  else if (command == "searchnightstand")
    cout << "\nIn the top drawer of the NIGHTSTAND, you find a small piece if not paper. On it is a scribbled note that says: 'Screw\nthat coat RACK! That monster, it thinks it can get away with this?! I'll kill it, I swear I will!' Dang, sounds\nlike this dude had some grudge against that coat RACK." << endl;
  else if (command == "takenightstand")
    cout << "\nYou do not have the strength to take the NIGHTSTAND anywhere." << endl;
  else if (command == "enternightstand")
    cout << "\nThe NIGHTSTAND is too small to enter. You can only get a bit of your leg into the drawer." << endl;
  else if (command == "usenightstand")
  {
    cout << "\nWhat do you want to use the NIGHTSTAND on? (Here's a hint: you won't be able to do anythinig with it) ";
    getObject(objectUsedOn);

    cout << "\nYeah that makes no sense and doesn't do anything." << endl;
  }





  else if (command == "examinelamp")
  {
    if (lampState == DESTROYED)
      cout << "\nThe LAMP has been destroyed. The bulb is shattered and its shade is ripped all over. Broken pieces lie about." << endl;
    else
    {
      cout << "\nThe LAMP on the NIGHTSTAND is a standard table LAMP. There is a switch to turn it on and off, and it is currently\nplugged into an OUTLET in the WALL next to the NIGHTSTAND. It is currently ";
      if (lampLight == true)
        cout << "on." << endl;
      else cout << "off." << endl;
    }
  }
  else if (command == "consumelamp")
    cout << "\nYou fail to consume the LAMP. It is still plugged in to the OUTLET, anyway." << endl;
  else if (command == "attacklamp")
  {
    if (lampState == INITIAL)
    {
      cout << "\nYou completely annihilate this LAMP. Like it wasn't even a challenge, it's just all broken. What a loser." << endl;
      lampLight = false;
    }
    else cout << "\nYou already completely destroyed this LAMP." << endl;
  }
  else if (command == "searchlamp")
    cout << "\nYou don't find anything useful in the lampshade or anywhere else around the LAMP." << endl;
  else if (command == "takelamp")
  {
    if (lampState == DESTROYED)
      cout << "\nThe LAMP is long gone. You broke it dude." << endl;
    else if (lampState == MOVED)
      cout << "\nYou already took the LAMP." << endl;
    else
    {
      cout << "\nYou take the LAMP out of the WALL, but as you do, the cord snaps, getting stuck in the OUTLET." << endl;
      lampState = MOVED;
    }
  }
  else if (command == "enterlamp")
    cout << "\nListen, you can't just... enter a LAMP. C'mon, you know this." << endl;
  else if (command == "uselamp")
    {
      if (lampState == DESTROYED)
        cout << "\nThe LAMP is long gone. You broke it dude." << endl;
      else if (lampState == MOVED)
        cout << "\nYou took the LAMP out of the WALL, and the cord snapped. You can't turn it back on." << endl;
      else
      {
        if (lampLight == true)
        {
          cout << "\nYou press the button on the LAMP, turning it off." << endl;
          lampLight = false;
        }
        else if (lampLight = false)
        {
          cout << "\nYou press the button on the LAMP, turning it on." << endl;
          lampLight = true;
        }
      }
    }






  else if (command == "examinefireplace")
  {
    if (fire == true)
      cout << "\nThe FIREPLACE is made out of chiselled stone, and the fire is burning bright and warm, illumination the ROOM. It seems\nlike there might be something in the fire, but it could just be whatever fuel is burning." << endl;
    else cout << "\nThe fire has been doused, along with the light and warmth it provided. You can see that what was keeping the fire\ngoing was not wood, but a bunch of BOOKS." << endl;
  }
  else if (command == "consumefireplace")
  {
    if (fire == true)
      cout << "\nYou badly burn your tongue on the fire as you attempt to...eat the FIREPLACE. Needless to say, you fail." << endl;
    else cout << "\nYou fail to consume the FIREPLACE. You are only left with an ashy taste in your mouth." << endl;
  }
  else if (command == "attackfireplace")
    cout << "\nYou take a few swings at the FIREPLACE but can't do any damage to it." << endl;
  else if (command == "searchfireplace")
  {
    if (fire = true)
      cout << "\nYou can't really search it while the fire is going." << endl;
    else cout << "\nYou find more of the BOOKS lying about the FIREPLACE." << endl;
  }
  else if (command == "takefireplace")
    cout << "\nYou can't take the FIREPLACE. It is fixed into the WALL." << endl;
  else if (command == "enterfireplace")
  {
    if (fire = true)
    {
      cout << "\nYou enter the FIREPLACE with the fire still burning, and you burn alive. You are dead, sorry." << endl;
      gameStatus = LOSE;
    }
    else cout << "You enter the still warm FIREPLACE, and you fit quite comfortably. You are able to sit and be cozy inside." << endl;
  }
  else if (command == "usefireplace")
    cout << "\nYou sit next the fire for a while, warming yourself up and improving your mood. You walk away after a while happier than\nyou were before." << endl;





  else if (command == "examineself")
  {
    selfExams++;
    if (selfExams == 1)
      cout << "\nUm, okay... that's kind of weird. You take a reeeeeaaally good look at yourself. Everything seems to be in order. You\nare still yourself." << endl;
    else if (selfExams == 2)
      cout << "\nIs there something... specific that you're trying to accomplish? Once again, you examine yourself VERY thoroughly.\nNothing out of the ordinary." << endl;
    else if (selfExams > 2)
      cout << "\nStop." << endl;
  }
  else if (command == "consumeself")
    cout << "\nNO!.... NO NO NO!" << endl;
  else if (command == "attackself")
    cout << "\nAll of the sudden, you forget the true scope of your power, and there is only one way to test your strength. You knock\nyourself a few times in the face, and then you give yourself a few good blows to the stomach. You fall to the\nground in pain, but the damage isn't that bad, and you get up and shake it off after a few minutes." << endl;
  else if (command == "searchself")
    cout << "\nYou are wearing the same clothes you last remember wearing, but if you had anything in your pockets before, they\naren't there anymore" << endl;
  else if (command == "takeself")
    cout << "\nYou already have yourself." << endl;
  else if (command == "enterself")
    cout << "\nThe max you can get in is a few fingers." << endl;
  else if (command == "useself")
    cout << "\ntechnically, you're using yourself whenever you do anything." << endl;






  else if (command == "examineparrot")
  {
    if (parrotState == INITIAL)
      cout << "\nThe PARROT appears to be a multicolored, but mostly red, Macaw. It is sitting atop the coat RACK, looking around the\nroom, but keeping quiet for the most part. You remember that birds like these are supposed to be able to talk." << endl;
    else if (parrotState == FED)
      cout << "\nThe PARROT is happily sitting on top of the RACK now that it has eaten its favorite snack. It looks at you and squawks\nthe word 'Hello'" << endl;
    else if ((parrotState == DEAD)||(parrotState == EATEN))
      cout << "\nThe PARROT is lying dead on the ground. All of its beauty and grace has been lost. It did not deserve such a fate. Why\ndid you do this?" << endl;
  }
  else if (command == "consumeparrot")
  {
    if ((parrotState != EATEN)&&(parrotState != DEAD))
    {
      cout << "\nYou grab the PARROT and take a big bite out of its head, killing it instantly. You then throw its corpse on the ground\nlike the monster you are." << endl;
      parrotState = EATEN;
    }
    else if (parrotState == DEAD)
    {
      cout << "You take a big bite out of the parrot's corpse." << endl;
      parrotState = EATEN;
    }
    else if (parrotState == EATEN)
      cout << "\nYou take yet another bite out of the parrot's corpse." << endl;
  }
  else if (command == "attackparrot")
  {
    if ((parrotState == DEAD)||(parrotState == EATEN))
      cout << "\nYou kick the still corpse of the PARROT." << endl;
    else
    {
      cout << "\nYou snatch the PARROT out of its resting place and strangle it to death." << endl;
      parrotState = DEAD;
    }
  }
  else if (command == "searchparrot")
    cout << "\nThe PARROT has nothing on it." << endl;
  else if (command == "takeparrot")
  {
    if ((parrotState != EATEN)&&(parrotState != DEAD))
      cout << "\nYou manage to snatch the PARROT, but it struggles to escape. Wishing not to harm it, you let it go." << endl;
    else cout << "\nYou are now carrying the dead body of the PARROT." << endl;
  }
  else if (command == "enterparrot")
    cout << "\nThere is literally no way you can even begin to do that." << endl;
  else if (command == "useparrot")
  {
    cout << "\nWhat do you want to use the PARROT on? ";
    getObject(objectUsedOn);

    if (objectUsedOn == "onfireplace")
    {
      if ((parrotState != EATEN)&&(parrotState != DEAD)&&(fire == true))
      {
        cout << "\nYou throw the PARROT into the fire. You can hear it squawking in pain, and in a few seconds it comes flying out, but\nit is badly burned and dies shortly after." << endl;
      }
      else if (fire == true)
        cout << "\nYou cook the corpse of the PARROT at the fire, making it nice and crispy." << endl;
    }
    else if (objectUsedOn == "onrats")
    {
      if ((parrotState != EATEN)&&(parrotState != DEAD))
      {
        cout << "\nYou grab the PARROT and bring it over to the RATS. The PARROT squawked loudly, and all of the RATS scurried away. They\ncome back after a while, but they now respect you and they keep their distance." << endl;
        ratState = MOVED;
      }
      else
      {
        cout << "\nYou throw the dead PARROT at the RATS and they approach it slowly. They take a good look and reaalize your power.\nThey now fear and respect you, and will not block your path." << endl;
        ratState = MOVED;
      }
    }
    else if (objectUsedOn == "onman")
      cout << "The man is not interested in the PARROT." << endl;
    else cout << "That does not do anything." << endl;
  }





  else if (command == "examinebucket")
  {
    if (bucketState == INITIAL)
      cout << "\nThe BUCKET is a metal pail that is partially filled with what seems like regular water." << endl;
    else if (bucketState == EMPTY)
      cout << "\nThe BUCKET has been completely emptied of all its water." << endl;
    else if (bucketState == DESTROYED)
      cout << "\nThe BUCKET has been destroyed. It is filled with dents, and any water that was left in it was spilled all over the\nFLOOR." << endl;
  }
  else if (command == "consumebucket")
    cout << "\nYou fail to consume the BUCKET itself, but you do take a sip of the water inside of it. It's pretty refreshing." << endl;
  else if (command == "attackbucket")
  {
    cout << "\nYou wail on the BUCKET, denting it up more and more. The water that was in it is no more." << endl;
    bucketState = DESTROYED;
  }
  else if (command == "searchbucket")
    cout << "\nThere is nothing special inside the bucket. It seems like it's only ever been used to carry water." << endl;
  else if (command == "takebucket")
    cout << "\nYou are now carrying the bucket." << endl;
  else if (command == "enterbucket")
  {
    if (bucketState == INITIAL)
    {
      cout << "\nYou stick your head in the BUCKET of water and drown yourself." << endl;
      gameStatus = LOSE;
    }
    else cout << "\nYou stick your head in the BUCKET, and you wear it as a hat." << endl;
  }
  else if (command == "usebucket")
  {
    cout << "\nWhat will you use the BUCKET on? ";
    getObject(objectUsedOn);

    if ((objectUsedOn == "onbed")&&(bucketState == INITIAL))
      cout << "\nYou pour a bit of water on the BED. Now it looks like you peed on it." << endl;
    else if ((objectUsedOn == "onplant")&&(bucketState == INITIAL))
    {
      if (plantState == INITIAL)
      {
        cout << "\nYou water the PLANT and it looks like it really liked it. You'll need to wait a few hours to see the effect of it.\nThat's enough time for a good nap." << endl;
        plantState = WATERED;
      }
      else if ((plantState == WATERED)||(plantState == GROWN)||(plantState == HARVESTED))
        cout << "\nYou already watered the PLANT." << endl;
    }
    else if ((objectUsedOn == "onradio")&&(bucketState == INITIAL)&&(radioState == INITIAL))
    {
      cout << "\nYou throw the RADIO in the water BUCKET, and it short-circuits. There are a few small explosions in the RADIO,\nand it is destroyed. You take it out of the BUCKET afterwards." << endl;
      radioState = DESTROYED;
    }
    else if ((objectUsedOn == "onfireplace")&&(bucketState == INITIAL)&&(fire == true))
    {
      cout << "\nYou empty the BUCKET into the fire, extinguising it. With the fire extinguished, you can see that the kindling that\nwas fueling the fire was actually a large stack of BOOKS." << endl;
      fire = false;
      bucketState = EMPTY;
    }
    else if ((objectUsedOn == "onself")&&(bucketState == INITIAL))
    {
      cout << "\nYou dump the BUCKET over your head, drenching yourself in water. You are now very cold." << endl;
      bucketState = EMPTY;
    }
    else if ((objectUsedOn == "onparrot")&&(bucketState == INITIAL))
      cout << "\nYou try to throw some water on the PARROT, but it dodges." << endl;
    else if ((objectUsedOn == "oncandle")&&(bucketState == INITIAL)&&(candleState == BURNED))
    {
      cout << "\nYou pour some water on the CANDLE, extinguishing its flame." << endl;
      candleState = INITIAL;
    }
    else if ((objectUsedOn == "onrats")&&(bucketState == INITIAL))
      cout << "\nYou try to pour some water on the RATS, but they are unphased by it. They are from the sewer after all." << endl;
    else if ((objectUsedOn == "onman")&&(bucketState == INITIAL))
      cout << "\nYou pour some water on the MAN, and he is very annoyed with you and tells you to cut it out." << endl;
    else if ((objectUsedOn == "onkeypad")&&(bucketState == INITIAL)&&(keypadState != DESTROYED))
    {
      cout << "\nYou splash some of the water in the BUCKET onto the KEYPAD. It short-circuits and lets off some smoke, and the screen goes\ndark. You broke it." << endl;
      keypadState = DESTROYED;
    }
    else cout << "That does not do anything." << endl;
  }





  else if (command == "examinecandle")
  {
    if (candleState == DESTROYED)
      cout << "\nThe CANDLE has been completely destroyed. It's parts are all over the place." << endl;
    else if (candleState == EATEN)
      cout << "\nYou ate the candle earlier. You can't really examine it now." << endl;
    else cout << "\nThe CANDLE is one made of standard candle wax, and it is sitting on a candlestick. It is fairly large, but you could still\nhold it easily with the candlestick." << endl;
  }
  else if (command == "consumecandle")
  {
    if (candleState == EATEN)
    {
      cout << "\nYou already ate the CANDLE! How do you not remember that??" << endl;
    }
    else if (candleState == DESTROYED)
      cout << "\nThe candle is no more..." << endl;
    else
    {
      cout << "\nOkay... you eat the entire CANDLE, wick and all." << endl;
      candleState = EATEN;
    }
  }
  else if (command == "attackcandle")
  {
    if ((candleState == DESTROYED)||(candleState == EATEN))
      cout << "\nYou already destroyed the CANDLE" << endl;
    else
    {
      cout << "\nYou smash the CANDLE in your hands, destroying it." << endl;
      candleState = DESTROYED;
    }
  }
  else if (command == "searchcandle")
    cout << "\nThere is nothing to search" << endl;
  else if (command == "takecandle")
  {
    if ((candleState == DESTROYED)||(candleState == EATEN))
      cout << "\nThere is nothing to take. The CANDLE is no more." << endl;
    else cout << "\nYou are now carrying the CANDLE." << endl;
  }
  else if (command == "entercandle")
    cout << "\nHow do you expect to do that? Get real." << endl;
  else if (command == "usecandle")
  {
    cout << "\nWhat would you like to use the CANDLE on? ";
    getObject(objectUsedOn);

    if ((objectUsedOn == "onbed")&&(candleState == BURNED))
      cout << "\nThe BED is fireproof, and will not burn" << endl;
    else if ((objectUsedOn == "onplant")&&(candleState == BURNED))
    {
      if ((plantState != BURNED)&&(plantState != DESTROYED)&&(plantState != EATEN))
      {
      cout << "\nYou burn the PLANT to a crisp with the CANDLE's flame." << endl;
      plantState = BURNED;
      }
      else cout << "\nThat does not do anything." << endl;
    }
    else if ((objectUsedOn == "onfireplace")&&(candleState == INITIAL))
    {
      if (fire == true)
      {
        cout << "\nYou hold the CANDLE up to the fire, lighting it. The CANDLE is now burning." << endl;
        candleState = BURNED;
      }
      else if (fire == false)
      {
        cout << "\nYou relight the fire with your CANDLE." << endl;
        fire = true;
      }
    }
    else if ((objectUsedOn == "onself")&&(candleState == BURNED))
      cout << "\nYou hold the lit CANDLE up to your body, and give yourself a little burn scar. It looks super rad." << endl;
    else if ((objectUsedOn == "onparrot")&&(candleState == BURNED))
    {
      if ((parrotState == INITIAL)||(parrotState == FED))
        cout << "\nYou hold the flame up to the PARROT, but it flies away before it gets too close." << endl;
      else cout << "\nThat does not do anything." << endl;
    }
    else if ((objectUsedOn == "onbucket")&&(candleState == BURNED)&&(bucketState == INITIAL))
    {
      cout << "\nYou submerge the CANDLE in the BUCKET of water, extinguishing the flame." << endl;
      candleState = INITIAL;
    }
    else if ((objectUsedOn == "onrats")&&(candleState == BURNED))
    {
      cout << "\nThe RATS are extremely terrified of the CANDLE flame. After shoving it in their faces, they now respect you and will not\nget in your way." << endl;
      ratState = MOVED;
    }
    else if ((objectUsedOn == "onbooks")&&(candleState == BURNED)&&(fire == false))
    {
      cout << "\nYou put the CANDLE up to the BOOKS, lighting them ablaze once again. The fire is now burning bright." << endl;
      fire = true;
    }
    else if ((objectUsedOn == "onpainting")&&(candleState == BURNED)&&(paintingState != DESTROYED)&&(paintingState != EATEN))
    {
      cout << "\nYou burn up the painting with the CANDLE's flame in many different places. It then falls off the wall, and appears\ncompletely destroyed now." << endl;
    }
    else if (objectUsedOn == "onman")
      cout << "\nThe MAN does not seem interested in the CANDLE at all." << endl;
    else if (objectUsedOn == "onroom")
      cout << "\nBurning the entire ROOM down would be very bad. Let's not do that." << endl;
    else cout << "\nThat does not do anything." << endl;
  }





  else if (command == "examinecarpet")
  {
    if (carpetState == INITIAL)
      cout << "\nThe carpet has an interesting pattern that reminds you of a colorful quilt. It is mostly flat across the ground, but is\nfolded a bit in the middle, and it feels strange when you step there." << endl;
    else if (carpetState == MOVED)
      cout << "\nThe carpet has been thrown to the side of the ROOM, next to the BED. It is folded on top of itself and bunched up from\nbeing thrown." << endl;
  }
  else if (command == "consumecarpet")
    cout << "\nYou fail to consume the CARPET, but while you try, you realize there may be something under it." << endl;
  else if (command == "attackcarpet")
  {
    if (carpetState == INITIAL)
    {
      cout << "\nYou attack the CARPET, moving it to the side and revealing a gated hole in the FLOOR. On the other side of the gate is a bearded, naked, old MAN. He says to you: If you give me something valuable and answer my riddle, I will let you out of here." << endl;
      carpetState = MOVED;
    }
    else cout << "\nYou punch the CARPET into the WALL a few times." << endl;
  }
  else if (command == "searchcarpet")
  {
    if (carpetState == INITIAL)
    {
      cout << "\nYou search the CARPET, moving it to the side and revealing a gated hole in the FLOOR. On the other side of the gate is a bearded, naked, old MAN. He says to you: If you give me something valuable and answer my riddle, I will let you out of here." << endl;
      carpetState = MOVED;
    }
    else cout << "\nThere is nothing else to find within the CARPET." << endl;
  }
  else if (command == "takecarpet")
    cout << "\nThe CARPET is too big to take." << endl;
  else if (command == "entercarpet")
    cout << "\nThere is no way to enter the CARPET. You try, but you look really dumb doing it." << endl;
  else if (command == "usecarpet")
    cout << "\nThere isn't really anything you can do with the CARPET." << endl;





  else if (command == "examinevent")
  {
    if (ventState == INITIAL)
      cout << "\nThe VENT in the WALL is grated in a way where you can barely see past it, but you think you could definitely fit through\nit if you opened it. There are four screw on each corner which, if taken off, would open it." << endl;
    else if ((ventState == OPEN)&&(ratState == INITIAL))
      cout << "\nThe VENT is now open, but there are RATS in the way. You'll have to scare them off with something or they will eat you." << endl;
    else if ((ventState == OPEN)&&(ratState == MOVED))
      cout << "\nThe RATS are no longer in your way, and the VENT is clear to enter." << endl;
  }
  else if (command == "consumevent")
    cout << "\nYou fail to consume the VENT." << endl;
  else if (command == "attackvent")
    cout << "\nYou cannot break through the VENT, even with all your might." << endl;
  else if (command == "searchvent")
    cout << "\nIt is extremely hard to see through the VENT. You can see some screws on the VENT that would probably open it up if they\nwere taken off." << endl;
  else if (command == "takevent")
    cout << "\nYou are not able to take the VENT with you." << endl;
  else if (command == "usevent")
  {
    if (ventState == INITIAL)
      cout << "\nYou cannot use the vent to escape unless you are able to unscrew it somehow." << endl;
    else if ((ventState == OPEN)&&(ratState == INITIAL))
      cout << "\nThe RATS are in your way. You'll have to scare them off before you can escape." << endl;
    else if ((ventState == OPEN)&&(ratState == INITIAL))
    {
      cout << "\nYou are successfully able to escape through the vent!" << endl;
      gameStatus = WIN;
    }
  }
  else if (command == "entervent")
  {
    if (ventState == INITIAL)
      cout << "\nYou cannot use the vent to escape unless you are able to unscrew it somehow." << endl;
    else if ((ventState == OPEN)&&(ratState == INITIAL))
      cout << "\nThe RATS are in your way. You'll have to scare them off before you can escape." << endl;
    else if ((ventState == OPEN)&&(ratState == INITIAL))
    {
      cout << "\nYou are successfully able to escape through the vent!" << endl;
      gameStatus = WIN;
    }
  }





  else if (command == "examinerats")
  {
    if (ratState == INITIAL)
      cout << "\nThese RATS look pretty feral, and they start to go crazy when you get close. Maybe they are rabid. For some reason, \nhowever, they won't enter the room." << endl;
    else cout << "\nThe RATS are acting more timid now, and will move out of your way when you get close." << endl;
  }
  else if (command == "consumerats")
    cout << "\nYou snatch up and eat one of the RATS alive like a barbarian. It was the most disgusting thing you've ever tasted, and you\nvomited multiple times before finishing. You don't realize this now, but those RATS were carrying various diseases,\nand because you ate one, you now have only six weeks to live." << endl;
  else if (command == "attackrats")
    cout << "\nYou punch a few of the RATS as hard as you possibly can. With each punch you kill one, but more replace them." << endl;
  else if (command == "searchrats")
    cout << "\nYou snatch up one of the RATS and look at it very closely. You notice some ticks and a few growths over the rat's body.\nGross. You throw it back in the VENT" << endl;
  else if (command == "takerats")
    cout << "\nYou grab a rat, but you don't really have anywhere to put it. You try your pockets, but it jumps out and scurries back to the VENT." << endl;
  else if (command == "enterrats")
    cout << "\nDude, what?" << endl;
  else if (command == "userats")
    cout << "\nThere isn't really anything you can do with the RATS." << endl;





  else if (command == "examinebooks")
  {
    cout << "\nThe BOOKS in the FIREPLACE all seem to be the same. From the pages you can find that are not burnt, you are able to \npiece it together." << endl;
    cout << "It is a book about a farmer who had a big farm. At night, all of the creatures on his farm wanted to go in the barn so \nthey could be warm, but the farmer did not have enough space for them, so he had to choose who to let in. First, he let\nhis family in, then the cows, the dogs, the sheep, and the horses. The other animals were upset, but the farmer had no \nother choice." << endl;
  }
  else if (command == "consumebooks")
    cout << "\nIt takes you many hours, but you are able to eat all of the pages on one of the books in the library. Your throat recieved\nmultiple paper cuts in the process." << endl;
  else if (command == "attackbooks")
    cout << "\nYou attack the BOOKS, but it doesn't accomplish anything." << endl;
  else if (command == "searchbooks")
  {
    cout << "\nThe BOOKS were all the same. Different pages of each of them were burned up, but one passage was present in all of them:" << endl;
    cout << "\nIt is a book about a farmer who had a big farm. At night, all of the creatures on his farm wanted to go in the barn so \nthey could be warm, but the farmer did not have enough space for them, so he had to choose who to let in. First, he let\nhis family in, then the cows, the dogs, the sheep, and the horses. The other animals were upset, but the farmer had no \nother choice." << endl;
  }
  else if (command == "takebooks")
    cout << "\nYou take one of the BOOKS." << endl;
  else if (command == "enterbooks")
    cout << "\nAs much fun as it would be to enter the story of the book, this isn't the magic treehouse." << endl;
  else if (command == "usebooks")
    cout << "\nThe BOOKS are not able to be used." << endl;





  else if (command == "examinepainting")
  {
    if (paintingState == EATEN)
      cout << "\nYou ate the PAINTING, remember? All that's left is the frame." << endl;
    else if (paintingState == INITIAL)
      cout << "\nIt is a painting of a farm. There is a farmer, his wife and four children, two dogs, nine cows, four horses, seven \nsheep, three goats, ten chickens, six ducks, and eight pigs." << endl;
    else cout << "\nThe PAINTING has been destroyed. You can no longer make out what it is supposed to be a painting of." << endl;
  }
  else if (command == "consumepainting")
  {
    if (paintingState != EATEN)
    {
      cout << "\nYou are successfully able to consume the everything but the frame of the PAINTING." << endl;
      paintingState = EATEN;
    }
    else if (paintingState == EATEN)
      cout << "\nYou already ate the PAINTING! How do you not remember that?!" << endl;
    else cout << "\nThe painting is gone. You can't eat it anymore. Not that you ever should have." << endl;
  }
  else if (command == "attackpainting")
  {
    if (paintingState == INITIAL)
    {
      cout << "\nYou rip the PAINTING off the wall, tearing it to shreds and snapping the frame into pieces." << endl;
      paintingState = DESTROYED;
    }
    else cout << "\nYou cannot do any more damage to the painting." << endl;
  }
  else if (command == "searchpainting")
  {
    if (paintingState == INITIAL)
      cout << "\nThere is nothing off about the PAINTING itself, but looking behind it, you see a small scribble on the WALL\nthat reads: 'Drown the fire.'" << endl;
    else cout << "\nYou can no longer search the PAINTING, but looking at where it was on the WALL, you see a small scribble\nthat reads: 'Drown the fire.'" << endl;
  }
  else if (command == "takepainting")
  {
    if (paintingState == INITIAL)
      cout << "\nYou take the PAINTING off the WALL and put it down on the FLOOR, but as you do, you notice some small writing\non the WALL that reads: 'Drown the fire.' You then put the PAINTING back on the WALL." << endl;
    else cout << "\nYou can no longer take the PAINTING." << endl;
  }
  else if (command == "enterpainting")
  {
    if (paintingState == INITIAL)
      cout << "\nAs much as you wish you could enter the world of the PAINTING, that's just not possible." << endl;
    else cout << "\nYou can no longer enter the PAINTING. I mean, you never could, but you can still be sad about it." << endl;
  }
  else if (command == "usepainting")
  {
    if (paintingState == INITIAL)
      cout << "\nBefore you can use the PAINTING on anything, you feel like its image is important. It is a painting of a farm.\nThere is a farmer, his wife and four children, two dogs, nine cows, four horses, seven \nsheep, three goats, ten chickens, six ducks, and eight pigs." << endl;
    else cout << "You can no longer use the PAINTING." << endl;
  }





  else if (command == "examineoutlet")
    cout << "\nIt just looks like a standard lectrical OUTLET. You remember that they can be dangerous if you mess with them.\nBe careful" << endl;
  else if (command == "consumeoutlet")
    cout << "\nYou fail to consume the OUTLET. It is fixed into the WALL." << endl;
  else if (command == "attackoutlet")
    cout << "\nYou punch the OUTLET, but just hurt yourself from hitting the WALL." << endl;
  else if (command == "searchoutlet")
    cout << "\nYou can't seem to remove the OUTLET cover from the WALL, and you can't really search it from the outside." << endl;
  else if (command == "takeoutlet")
    cout << "\nYou can't take the OUTLET out of the WALL." << endl;
  else if (command == "enteroutlet")
    cout << "\nYou are able to stick the tip of your fingernail in the socket, but you can't get any farther than that." << endl;
  else if (command == "useoutlet")
    cout << "\nThe OUTLET is already being used by the LAMP cord. There is another open socket, though. What could fit in there?" << endl;





  else if (command == "examineman")
  {
    cout << "\nThe MAN is skinny and frail and appears to be fairly old. He is not wearing much, and is only minimally covered up.\nHe also seems pretty jittery and nervous. You think it is best to be careful around him." << endl;
    if (underwearState == INITIAL)
      cout << "As you stare at the old MAN, he stares back even harder, and says: 'I'm still waiting for you to give me something\nvaluable!'" << endl;
    else if (underwearState == GIVEN)
    {
      cout << "The MAN seems happy with his underwear, but you still need to answer his riddle: 'If you could talk to animals, what's\nthe first thing they would say?'" << endl;
      cout << "What is your answer? ";

      cin >> answer;

      int answerSize = answer.size();

      for (int index = 0; index < answerSize; index++)
        answer[index] = tolower(answer[index]);

      if (answer == "hello")
      {
        riddle = true;
        cout << "\nThe old MAN looks at you and smiles. He unlocks the gate in the gound and backs away, signaling you to follow him to\nsafety. You can now enter the FLOOR to exit." << endl;
      }
      else cout << "\nThe old MAN frowns at you and says you are wrong! He tells you to try again once you figure it out." << endl;
    }
  }
  else if (command == "consumeman")
    cout << "\nUnfortunately, the MAN is out of reach." << endl;
  else if (command == "attackman")
    cout << "\nYou try to attack the old MAN, but he keeps out of your reach. Luckily he doesn't seem to hold a grudge, and almost\nimmediately forgets you tried to attack him. Good thing he isn't hostile." << endl;
  else if (command == "searchman")
    cout << "\nYou are not able to get close enough to the MAN to search him." << endl;
  else if (command == "takeman")
    cout << "\nIf anything, it's the MAN who will be taking you. Best to let him keep his distance." << endl;
  else if (command == "enterman")
    cout << "\nI hope you aren't thinking what I think you're thinking..." << endl;
  else if (command == "useman")
    cout << "\nUse him... for what? I think you should just leave him alone. But if you want to talk to him, you should examine him." << endl;





  else if (command == "examinekeypad")
  {
    if (keypadState == DESTROYED)
      cout << "\nThe KEYPAD has been destroyed." << endl;
    else cout << "\nIt is a KEYPAD which has a screen and a number pad, with a button for each number one through nine and an enter button. You\nassume it requires some kind of numerical code." << endl;
  }
  else if (command == "consumekeypad")
    cout << "\nYou fail to consume the KEYPAD" << endl;
  else if (command == "attackkeypad")
  {
    if (keypadState == INITIAL)
    {
      cout << "\nYou kick the KEYPAD with all of your strength and completely bust it up. Welp. You're not getting out that way." << endl;
      keypadState = DESTROYED;
    }
    else cout << "\nYou already destroyed the KEYPAD and proved your strength." << endl;
  }
  else if (command == "searchkeypad")
    cout << "\nThere is nothing to search here. You can only see the KEYPAD itself." << endl;
  else if (command == "takekeypad")
    cout << "\nThe KEYPAD is fixed into the WALL stronger than anything else in the ROOM. You can't take it." << endl;
  else if (command == "enterkeypad")
    cout << "\nYou could enter numbers into the KEYPAD, but you can't enter the KEYPAD itself." << endl;
  else if (command == "usekeypad")
  {
    if ((keypadState == INITIAL)&&(doorState == INITIAL))
    {
      cout << "\nThe KEYPAD requires a 5 digit code to open the DOOR. Enter the 5 numbers you want to input with no spaces: ";

      cin >> num;

      if (num == 59274)
      {
        cout << "\nThe KEYPAD glows green as you enter the final number and makes a beep sound. You hear a bunch of noises coming\nfrom inside the WALL behind the DOOR, and then the DOOR slowly comes open, revealing the exit to the ROOM." << endl;
        doorState = OPEN;
      }
      else
      {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nYou press the enter button after you finish. The KEYPAD glows red and makes a buzzing sound. Then, the characters\nthat you entered are cleared from the screen." << endl;
      }
    }
    else if ((keypadState == INITIAL)&&(doorState == OPEN))
    {
      cout << "\nYou already opened the DOOR with the KEYPAD. It is not accepting any more entries." << endl;
    }
    else cout << "\nThe KEYPAD has been destroyed. You can no longer use it." << endl;
  }





  else if (command == "examinechest")
  {
    if (chestState == INITIAL)
      cout << "\nIt looks like an actual treasure CHEST, straight out of a pirate movie. It has a very strong-looking padlock that has it\nshut tight. You realize you'll need a key to open it" << endl;
    else cout << "\nIt looks like an actual treasure CHEST, straight out of a pirate movie. Now open, you see it is filled with more gold\nCOINS than you can carry." << endl;
  }
  else if (command == "consumechest")
    cout << "\nYou fail to consume the CHEST. It is simply too big." << endl;
  else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;





  else if (command == "examinehole")
    cout << "\nThe RACK opened up a small HOLE in the FLOOR. It seems like the HOLE was there before, but it was hastily covered up. You\ncan't tell for sure, but it seems like a good place to hide something." << endl;
  else if (command == "consumehole")
    cout << "\nThat's... not how this works. You can't consume a hole... it's negative space. There's nothing to consume! Please, I don't\nunderstand!" << endl;
    else if (command == "")
    cout << "\n" << endl;
    else if (command == "")
  cout << "\n" << endl;
  else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;





  else if (command == "examinepeanut")
  {
    if ((peanutState == EATEN)||(peanutState == DESTROYED))
      cout << "\nThe PEANUT is no more..." << endl;
    else cout << "\nIt's just a regular PEANUT" << endl;
  }
  else if (command == "consumepeanut")
  {
    if (peanutState == INITIAL)
    {
      cout << "\nYou eat the peanut, but it is not as tasty as you had hoped it would be." << endl;
      peanutState = EATEN;
    }
    else if (peanutState == GIVEN)
      cout << "\nThe PARROT has already eaten the PEANUT." << endl;
    else if (peanutState == EATEN)
      cout << "\nYou already ate the PEANUT." << endl;
    else if (peanutState == DESTROYED)
      cout << "\nThe PEANUT is no more..." << endl;
  }
  else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;





  else if (command == "examinekey")
  {
    if ((keyState == EATEN)||(keyState == DESTROYED))
      cout << "\nThe KEY is no more..." << endl;
    else cout << "\nIt is a rusty KEY that looks perfect for opening old treasure chests, if there were any." << endl;
  }
  else if (command == "consumekey")
  {
    if (keyState = EATEN)
      cout << "\nYou already ate the KEY you fool." << endl;
    else if (keyState = DESTROYED)
      cout << "\nThe KEY is no more..." << endl;
    else
    {
      cout << "\nYou swallow the KEY whole, never to be seen again." << endl;
      keyState = EATEN;
    }
  }
  else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;





  else if (command == "examinecoins")
    cout << "\nThe gold COINS give off a glow and a shine, and you can tell they are very valuable. The sides of each coin are beautifully\ncarved and decorated, and the edges are very smooth, like a flathead screwdriver" << endl;
  else if (command == "consumecoins")
    cout << "\nYou swallow a handful of gold COINS. They do not rest easy in your stomach. You feel much heavier." << endl;
    else if (command == "")
    cout << "\n" << endl;
    else if (command == "")
  cout << "\n" << endl;
  else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;





  else if (command == "examineunderwear")
    cout << "\nYou really don't want to do that..." << endl;
  else if (command == "consumeunderwear")
  {
    if ((underwearState != DESTROYED)||(underwearState != GIVEN)||(underwearState != EATEN))
    {
      cout << "\nWOW... you just ate a random pair of UNDERWEAR. You did'nt know whose it was or where it's been... wow." << endl;
      underwearState = EATEN;
    }
    else if (underwearState == DESTROYED)
      cout << "\nThe UNDERWEAR is no more..." << endl;
    else if (underwearState == GIVEN)
      cout << "\nUnfortunately, you gave it to the old MAN." << endl;
    else if (underwearState == EATEN)
      cout << "\nI still can't believe you actually ate that underwear." << endl;
  }
    else if (command == "")
    cout << "\n" << endl;
    else if (command == "")
  cout << "\n" << endl;
  else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;





  else if (command == "examinefork")
    cout << "\nThe FORK is a metallic silver color, just like standard silverware you would find in a restaurant. It looks like it might be\nable to fit somewhere..." << endl;
  else if (command == "consumefork")
  {
    if (forkState == DESTROYED)
      cout << "\nThe FORK is no more..." << endl;
    else
    {
      cout << "\nYou choke on the fork and die. Serves you right!" << endl;
      gameStatus = LOSE;
    }
  }
    else if (command == "")
    cout << "\n" << endl;
    else if (command == "")
  cout << "\n" << endl;
  else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;
else if (command == "")
cout << "\n" << endl;






  else if (command == "examineroom")
  {
    cout << "\nYou recall what the room looked like when you first examined it:" << endl;
    roomDescription();
  }
  else if (command == "consumeroom")
    cout << "Dude... really?" << endl;



  else
  {
    cout << "-Invalid command- type 'help' if you need a refresher on the rules" << endl;
    moves--;
  }
}
