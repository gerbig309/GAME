#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<assert.h>
#include"game.h"

#define BUFFERSIZE 10

typedef int (*f)(player (*user));
//declare typdef
//not currently  scaled for full implementation, just proof of concept/syntax
// in actual implementation events will exist in their own library for scalable implementation

int main () {
    player * user = (player *) malloc(sizeof(player));
    if(!user){
      printf("didn't create user correctly");
      return 0;
    }
    user->military = 10;
    user->oligarchy = 10;
    user->people = 10;
    user->turns = 1; //Initialize player stats
    printf("Welcome to our game! In this, you are a dictator trying not to be overthrown. To do this, you will have to make decisions to balance your reputaion between the people, military, and the oligarchy. Each turn you will decide where you want to go, and based on the location, be given an event that you will respond to. Based on your response, your reputation with each faction will change. The lower yor reputation with any given faction, the more likely you will be overthrown. The game gets more difficult over time, and the longer your reign, the better you must maintain your reputation. The goal of the game is to last as long as possible without being overthrown. Good luck!\n");
  f eList[15] = {&event0, &event1, &event2, &event3, &event4, &event5, &event6, &event7, &event8, &event9, &event10, &event11, &event12, &event13, &event14};
  int typeErr=0;
  int eventErr=0;
  int eventNumber=-1;
  int revolt = 0;
  printf("Military:%d Oligarchy:%d People:%d Turn Number:%d\n", user->military, user->oligarchy, user->people, user->turns);
  while(1){
    typeErr=typeEvent(&eventNumber);
    if(typeErr==-2) break;
    if(typeErr==0){
      while(1){
         // typeErr=1 denotes a successful iteration of typeEvent
       eventErr = eList[eventNumber](user);
       revolt=coup(user);
         if(eventErr==-2||revolt==-2) break;
         if(eventErr==0){
	   turnEnd(user);
           break;
         }
         //eventErr denotes a successful iteration of the event function
         //if the event function doesn't get a valid input it will keep prompting
         //the user with the same prompt
       }
    }
     if(eventErr==-2||revolt==-2)break;
  }
  printf("You made it all the way to turn %d!\nYour reputation: Military:%d Oligarchy:%d People:%d\n\n",user->turns,user->military,user->oligarchy,user->people);
  free(user);
  return 0;
}
