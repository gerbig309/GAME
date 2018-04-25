#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#include <string.h>

struct _player{

  int military; 

  int oligarchy; 

  int people; 

  int turns;

  };

typedef struct _player player;

//this will be the header file
int typeEvent(int* eventNumber);
int RNG();
//                             //





int RNG(){
  // assign a variable like so: n = RNG()

  //returns some value between 0 to 99

  time_t t;

  srand((unsigned) time(&t));

  if (t < 0) t = -t;

  return t % 100;

}

int typeEvent (int* eventNumber){

     // prompts which type of event is wanted and changes what value the random number generater generates based on the response

    char * response;

    int random = RNG();

    printf("Type M to visit your miitary, O to visit your oligarchy, or P to visit the people.\n");

    while(scanf("%c", response) != " "){

       if(strlen(response) > 5) return -1;

     }

    // if -1 is returned don't change event number and call same event again

     if (strcmp (response,"M")){

    *eventNumber= random % 5;

      return 0;

    }

      if(strcmp(response,"O")){

      *eventNumber = random %5 + 5;

      return 0;

    }

      if(strcmp(response,"P")){

      *eventNumber = random %5 + 10;

      return 0;

    }

      if (strcmp (response,"Q")){

      return -2;

    }

    return -1;
      }
 

int main () {

    player* user = (player *) malloc(sizeof(player));

    if(!user){

      printf("didn't create user correctly");

      return 0;

    }

    user->military = 10;

    user->oligarchy = 10;

    user->people = 10;

    user->turns = 1; //Initialize player stats

    printf("Welcome to our game! In this, you are a dictator trying not to be overthrown. To do this, you will have to make decisions to balance your reputaion between the people, military, and the oligarchy. Each turn you will decide where you want to go, and based on the location, be given an event that you will respond to. Based on your response, your reputation with each faction will change. The lower yor reputation with any given faction, the more likely you will be overthrown. The game gets more difficult over time, and the longer your reign, the better you must maintain your reputation. The goal of the game is to last as long as possible without being overthrown. Good luck!\n");


  
  int typeErr=0;

  int eventErr=0;

  int eventNumber=-1;

  int revolt = 0;

  while (1){ //Starts loop to play game. Loop will continue until fail condition met

  typeErr = typeEvent(&eventNumber);
  if(typeErr==0) break;
  if(typeErr==-2) break;
  }
  printf("eventNumber: %d " ,eventNumber);
  free(user);
  return 0;
}
