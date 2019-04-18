
//Escape Room Game
//-text-based adventure

//This program will be a game that continually takes user inputs as commands and translates
//them into things that will happen in the Game

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int LOSE = 0, WIN = 1, PLAYING = 2;
int gameStatus = PLAYING;

const int INITIAL = 0, WATERED = 1, HARVESTED = 3, GROWN = 4, DESTROYED = 5, LOCKED = 6, OPEN = 7, ON = 8, OFF = 9, DEAD = 10, FED = 11, EMPTY = 12, MOVED = 13, EATEN = 14, GIVEN = 15, USED = 16, BURNED = 17;
int plantState=INITIAL,doorState=LOCKED,radioState=ON,parrotState=INITIAL,selfExams=0,rackState=INITIAL,bucketState=INITIAL,carpetState=INITIAL,ventState=INITIAL,paintingState=INITIAL,chestState=INITIAL,candleState=INITIAL,peanutState=INITIAL,lampState=INITIAL,keypadState=INITIAL,keyState=INITIAL,underwearState=INITIAL,bedState=INITIAL,forkState=INITIAL;

int selectDifficulty();
void displayRules();
void roomDescription();
void getCommand();
void resultOfCommand();
void statusUpdate();
void getObject();

int maxMoves;
string commandAction, commandObject, command, objectUsedOn;
bool candleOnNightstand = true, lampLight = true, fire = true;


int main()
{

  cerr << "Here is a welcome message: " << endl;
  cout << "Welcome to the Franklin Escape Room Game!" << endl;
  cout << "This is a text-based game in which the user enters commands in an attempt to escape the room" << endl  << endl;

  displayRules();

  cout << "--------------------------------------------------------------------------------------------------" << endl << endl;

  selectDifficulty();

  cout << "--------------------------------------------------------------------------------------------------" << endl << endl;
  cout << "You awake to the sound of a funky tune suddenly starting up." << endl;
  cout << "Still sleepy, you sit up, only to realize this isn't your BED" << endl;
  cout << "You get out of the BED and quickly realize that this isn't your ROOM either" << endl << endl;

  roomDescription();

  cout << "--------------------------------------------------------------------------------------------------" << endl << endl;

  for (int move = 1; move <= maxMoves, gameStatus == PLAYING; move++)
  {
    getCommand();
    resultOfCommand();
    statusUpdate();
  cout << "--------------------------------------------------------------------------------------------------" << endl << endl;
  }

  return 0;
}

int selectDifficulty()
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
  else maxMoves = 9999;

  return difficulty;
}

void displayRules()
{
  //cerr << "Here are the rules and commands:" << endl;
  //  give user list of commands and rules
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
  //cerr << "Here is a description of the room:" << endl;
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

void getCommand()
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
  //cout << command;
}

void getObject()
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

void statusUpdate()
{
  //cerr << "Checking player health..." << endl;
  //    check health
  //cerr << "Checking time..." << endl;
  //    incriment and check time
  //cerr << "Checking game status..." << endl;
  //    check game status
}

void resultOfCommand()
{
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
    if (bedState == INITIAL)
    {
      cout << "\nYou enter the bed, cover yourself up, close your eyes, and fall asleep. You have a happy dream. When you wake up\nafter a few hours, your fatigue is gone and you feel very refreshed." << endl;
      bedState = USED;
    }
    else cout << "\nYou enter the bed, cover yourself up, close your eyes, and fall asleep. You have a very scary nightmare and wake\nup after less than an hour. You feel exhausted." << endl;
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
      getObject();

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
    cout << "\nYou stomp as hard as you can on the FLOOR all over the ROOM. When you stomp near the coat RACK, one of the\nfloorboards comes loose and reveals a HOLE in the FLOOR, but falls back into place after. You now know there is a hole , however." << endl;
  else if (command == "searchfloor")
    cout << "\nYou feel around every inch of the floor, and find a HOLE near the RACK being covered up by a loose floorboard.\nYou also feel something under the CARPET." << endl;
  else if (command == "takefloor")
    cout << "\nYou cannot take the FLOOR." << endl;
  else if (command == "enterfloor")
  {
    if ((carpetState == MOVED)&&(underwearState != GIVEN))
      cout << "\nYou cannot exit through the FLOOR until you pass the old MAN's tests." << endl;
    else if ((carpetState != MOVED)&&(underwearState != GIVEN))
      cout << "\nYou cannot see anywhere to enter the FLOOR. You don't know about the CARPET though." << endl;
    else if ((carpetState == MOVED)&&(underwearState == GIVEN))
    {
      cout << "\nYou exit the ROOM through the FLOOR and successfully escape!" << endl;
      gameStatus = WIN;
    }
  }
  else if (command == "usefloor")
    cout << "\nYou sit on the floor." << endl;






  else if (command == "examinewall")
    cout << "\nThe WALL is made of brick, and it seems very sturdy and solid. You don't hear anything when you put your ear to it.\nThere is the FIREPLACE and VENT on one WALL, the PAINTING on the one across from it, and the DOOR and KEYPAD on the other." << endl;
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
      getObject();



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
          cout << "\nYou throw the RADIO in the water BUCKET, and it short-circuits. There are a few small explosions in the RADIO,\nand it is destroyed. You take it out of teh BUCKET afterwards." << endl;
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
        cout << "\nThe RATS seem to calm down a bit when you bring the music over to them. A few of them begin wagging their tails, but\nthey are clearly still hostile." << endl;
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
  





  else if (command == "examinelamp")
  {
    if (lampState == DESTROYED)
      cout << "\nThe LAMP has been destroyed. The bulb is shattered and its cone is ripped all over. Broken pieces lie about." << endl;
    else
    {
      cout << "\nThe LAMP on the NIGHTSTAND is a standard table lamp. There is a switch to turn it on and off, and it is currently\nplugged into an OUTLET in the WALL next to the NIGHTSTAND. It is currently ";
      if (lampLight == true)
        cout << "on." << endl;
      else cout << "off." << endl;
    }
  }
  else if (command == "examinefireplace")
  {
    if (fire == true)
      cout << "\nThe FIREPLACE is made out of chiselled stone, and the fire is burning bright and warm, illumination the ROOM. It seems\nlike there might be something in the fire, but it could just be whatever fuel is burning." << endl;
    else cout << "\nThe fire has been doused, along with the light and warmth it provided. You can see that what was keeping the fire\ngoing was not wood, but a bunch of BOOKS." << endl;
  }
  else if (command == "examineself")
  {
    selfExams++;
    if (selfExams == 1)
      cout << "\nUm, okay... that's kind of weird. You take a reeeeeaaally good look at yourself. Everything seems to be in order. You are still yourself." << endl;
    else if (selfExams == 2)
      cout << "\nIs there something... specific that you're trying to accomplish? Once again, you examine yourself VERY thoroughly. Nothing out of the ordinary." << endl;
    else if (selfExams > 2)
      cout << "\nStop." << endl;
  }
  else if (command == "examineparrot")
  {
    if (parrotState == INITIAL)
      cout << "\nThe PARROT appears to be a multicolored, but mostly red, Macaw. It is sitting atop the coat RACK, looking around the\nroom, but keeping quiet for the most part. You remember that birds like these are supposed to be able to talk." << endl;
    else if (parrotState == FED)
      cout << "\nThe PARROT is playfully chewing on the PEANUT on top of the RACK. It is no longer paying any attention to you." << endl;
    else if (parrotState == DEAD)
      cout << "\nThe PARROT is lying dead on the ground. All of its beauty and grace has been lost. It did not deserve such a fate. Why\ndid you do this?" << endl;
  }
  else if (command == "examinebucket")
  {
    if (bucketState == INITIAL)
      cout << "\nThe BUCKET is a metal pail that is partially filled with what seems like regular water." << endl;
    else if (bucketState == EMPTY)
      cout << "\nThe BUCKET has been completely emptied of all its water." << endl;
    else if (bucketState == DESTROYED)
      cout << "\nThe BUCKET has been destroyed. It is filled with dents, and any water that was left in it was spilled all over the FLOOR." << endl;
  }
  else if (command == "examinecandle")
  {
    if (candleState == DESTROYED)
      cout << "\nThe CANDLE has been completely destroyed. It's parts are all over the place." << endl;
    else if (candleState == EATEN)
      cout << "\nYou ate the candle earlier. You can't really examine it now." << endl;
    else cout << "\nThe CANDLE is one made of standard candle wax, and it is sitting on a candlestick. It is fairly large, but you could still\nhold it easily with the candlestick." << endl;
  }
  else if (command == "examinecarpet")
  {
    if (carpetState == INITIAL)
      cout << "\nThe carpet has an interesting pattern that reminds you of a colorful quilt. It is mostly flat across the ground, but is\nfolded a bit in the middle, and it feels strange when you step there." << endl;
    else if (carpetState == MOVED)
      cout << "\nThe carpet has been thrown to the side of the ROOM, next to the BED. It is folded on top of itself and bunched up from\nbeing thrown." << endl;
  }
  else if (command == "examinevent")
  {
    if (ventState == INITIAL)
      cout << "\nThe VENT in the WALL is grated in a way where you can barely see past it, but you think you could definitely fit through\nit if you opened it. There are four screw on each corner which, if taken off, would open it." << endl;
    else if (ventState == OPEN)
      cout << "\nThe VENT is now open, but there are RATS in the way. You'll have to scare them off with something or they will eat you." << endl;
  }
  else if (command == "examinerats")
    cout << "\nThese RATS look pretty feral, and they start to go crazy when you get close. Maybe they are rabid. For some reason, \nhowever, they won't enter the room." << endl;
  else if (command == "examinebooks")
  {
    cout << "\nThe BOOKS in the FIREPLACE all seem to be the same. From the pages you can find that are not burnt, you are able to \npiece it together." << endl;
    cout << "It is a book about a farmer who had a big farm. At night, all of the creatures on his farm wanted to go in the barn so \nthey could be warm, but the farmer did not have enough space for them, so he had to choose who to let in. First, he let\nhis family in, then the cows, the dogs, the sheep, and the horses. The other animals were upset, but the farmer had no \nother choice." << endl;
  }
  else if (command == "examinepainting")
  {
    if (paintingState == EATEN)
      cout << "\nYou ate the PAINTING, remember? All that's left is the frame." << endl;
    else if (paintingState == INITIAL)
      cout << "\nIt is a painting of a farm. There is a farmer, his wife and four children, two dogs, nine cows, four horses, seven \nsheep, three goats, ten chickens, six ducks, and eight pigs." << endl;
    else if (paintingState == DESTROYED)
      cout << "\nThe PAINTING is now on the FLOOR, torn to shreds. You can no longer make out what is is supposed to be a painting of." << endl;
  }
  else if (command == "examineoutlet")
    cout << "\nIt just looks like a standard lectrical OUTLET. You remember that they can be dangerous if you mess with them. Be careful" << endl;
  else if (command == "examineman")
    cout << "\nThe MAN is skinny and frail and appears to be fairly old. He is not wearing much, and is only minimally covered up. He also\nseems pretty jittery and nervous. You think it is best to be careful around him." << endl;
  else if (command == "examinekeypad")
  {
    if (keypadState == DESTROYED)
      cout << "\nThe KEYPAD has been destroyed." << endl;
    else cout << "\nIt is a KEYPAD which has a screen and a number pad, with a button for each number one through nine and an enter button. You\nassume it requires some kind of numerical code." << endl;
  }
  else if (command == "examinechest")
  {
    if (chestState == INITIAL)
      cout << "\nIt looks like an actual treasure CHEST, straight out of a pirate movie. It has a very strong-looking padlock that has it\nshut tight. You realize you'll need a key to open it" << endl;
    else cout << "\nIt looks like an actual treasure CHEST, straight out of a pirate movie. Now open, you see it is filled with more gold\nCOINS than you can carry." << endl;
  }
  else if (command == "examinehole")
    cout << "\nThe RACK opened up a small HOLE in the FLOOR. It seems like the HOLE was there before, but it was hastily covered up. You\ncan't tell for sure, but it seems like a good place to hide something." << endl;
  else if (command == "examinepeanut")
  {
    if ((peanutState == EATEN)||(peanutState == DESTROYED))
      cout << "\nThe PEANUT is no more..." << endl;
    else cout << "\nIt's just a regular PEANUT" << endl;
  }
  else if (command == "examinekey")
  {
    if ((keyState == EATEN)||(keyState == DESTROYED))
      cout << "\nThe KEY is no more..." << endl;
    else cout << "\nIt is a rusty KEY that looks perfect for opening old treasure chests, if there were any." << endl;
  }
  else if (command == "examinecoins")
    cout << "\nThe gold COINS give off a glow and a shine, and you can tell they are very valuable. The sides of each coin are beautifully\ncarved and decorated, and the edges are very smooth, like a flathead screwdriver" << endl;
  else if (command == "examineunderwear")
    cout << "\nYou really don't want to do that..." << endl;
  else if (command == "examinefork")
    cout << "\nThe FORK is a metallic silver color, just like standard silverware you would find in a restaurant. It looks like it might be\nable to fit somewhere..." << endl;







  else if (command == "consumelamp")
    cout << "\nYou fail to consume the LAMP. It is still plugged in to the OUTLET, anyway." << endl;
  else if (command == "consumefireplace")
  {
    if (fire == true)
      cout << "\nYou badly burn your tongue on the fire as you attempt to...eat the FIREPLACE. Needless to say, you fail." << endl;
    else cout << "\nYou fail to consume the FIREPLACE. You are only left with an ashy taste in your mouth." << endl;
  }
  else if (command == "consumeself")
    cout << "\nNO!.... NO NO NO!" << endl;
  else if (command == "consumeparrot")
  {
    if (parrotState != EATEN)
    {
      cout << "\nYou take a big bite out of the parrot's head, killing it instantly. You then throw its corpse on the ground like the\nmonster you are." << endl;
      parrotState = DEAD;
    }
    else cout << "\nYou take yet another bite out of the parrot's corpse." << endl;
  }
  else if (command == "consumebucket")
    cout << "\nYou fail to consume the BUCKET itself, but you do take a sip of the water inside of it. It's pretty refreshing." << endl;
  else if (command == "consumecandle")
  {
    if (candleState != EATEN)
    {
      cout << "\nOkay... you eat the entire CANDLE, wick and all." << endl;
      candleState = EATEN;
    }
    else cout << "\nYou already ate the CANDLE! How do you not remember that??" << endl;
  }
  else if (command == "consumecarpet")
    cout << "\nYou fail to consume the CARPET, but while you try, you realize there may be something under it." << endl;
  else if (command == "consumevent")
    cout << "\nYou fail to consume the VENT." << endl;
  else if (command == "consumerats")
    cout << "\nYou snatch up and eat one of the RATS alive like a barbarian. It was the most disgusting thing you've ever tasted, and you\nvomited multiple times before finishing. You don't realize this now, but those rats were carrying various diseases,\nand because you ate one, you now have only six weeks to live." << endl;
  else if (command == "consumebooks")
    cout << "\nIt takes you many hours, but you are able to eat all of the pages on one of the books in the library. Your throat recieved\nmultiple paper cuts in the process." << endl;
  else if (command == "consumepainting")
  {
    if (paintingState != EATEN)
    {
      cout << "\nYou are successfully able to consume the everything but the frame of the PAINTING." << endl;
      paintingState = EATEN;
    }
    else cout << "\nYou already ate the PAINTING! How do you not remember that?!" << endl;
  }
  else if (command == "consumeoutlet")
    cout << "\nYou fail to consume the OUTLET. It is fixed into the WALL." << endl;
  else if (command == "consumeman")
    cout << "\nUnfortunately, the MAN is out of reach." << endl;
  else if (command == "consumekeypad")
    cout << "\nYou fail to consume the KEYPAD" << endl;
  else if (command == "consumechest")
    cout << "\nYou fail to consume the CHEST. It is simply too big." << endl;
  else if (command == "consumehole")
    cout << "\nThat's... not how this works. You can't consume a hole... it's negative space. There's nothing to consume! Please, I don't\nunderstand!" << endl;
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
  else if (command == "consumecoins")
    cout << "\nYou swallow a handful of gold COINS. They do not rest easy in your stomach. You feel much heavier." << endl;
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
  else if (command == "consumeroom")
    cout << "Dude... really?" << endl;



  else
  {
    cout << "-Invalid command- type help if you need a refresher on the rules" << endl;
  }
  //cerr << "checking the result of the command..." << endl;
  //    check result of command
  //cerr << "Updating variables.." << endl;
  //    update variables based on result
  //cerr << "Here is the result:" << endl;
  //    display result in text
}
