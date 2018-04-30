#ifndefine _GAME_H_
#define _GAME_H_
//Header File for dictator game ECEN1310 Final Project
//Created by Nick Goralka and Shane Gerbig

typedef struct _player player;

//Event functions Called throughout the game
int event0(player *user);
int event1(player *user);
int event2(player *user);
int event3(player *user);
int event4(player *user);
int event5(player *user);
int event6(player *user);
int event7(player *user);
int event8(player *user);
int event9(player *user);
int event10(player *user);
int event11(player *user);
int event12(player *user);
int event13(player *user);
int event14(player *user);
//RNG creates a random number when called
int RNG();
/*
-coup is checks if any of the favorablity points in your government fell bellow the threshold for you to loose
if any of the favorability points do fall below the threshold it ends the game 
-the threshold for the game ending scales as the game progresses and increments up every five turns 
*/
int coup(player * user);
//turnEnd is called at the end of every turn and simply prints all of the player's stats 
void turnEnd(player * user);
//typeEvent is called to semirandomly select with event the players is prompted with. 
//It asks which sect of their government they would like to see in their office.
int typeEvent (int* eventNumber);
