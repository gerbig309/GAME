#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<assert.h>

#define BUFFERSIZE 10

//Will be header file: function declarations
int readResponse(char* response);
int parseResponse(char* response);
int whisper (char *in, char *out);
int RNG();
int typeEvent (int* eventNumber);
//

struct _player{
  int military; 
  int oligarchy; 
  int people; 
  int turns;
  };
typedef struct _player player;

int readResponse(char* response){
  if(!response) return -1;
    scanf("%s",response);    
    return 1;
}

int parseResponse(char* response){
  if(!response) return -1;
  /*return values
"yes": 1 
"no": 2
"military": 3
"oligarcy" : 4
"people": 420
"quit"= -2
none of these -> 100
  */
  char buffer[BUFFERSIZE];
  int err= whisper(response,buffer);
  assert(err);	  
  //whisper is used so that if a user enters response in caps it will still work
  if(err==-1)return -1;
  if(strcmp("yes", buffer)==0) return 1;
  if(strcmp("no",buffer)==0) return 2;
  if(strcmp("military",buffer)==0)return 3;
  if(strcmp("oligarchy",buffer)==0) return 4;
  if(strcmp("people",buffer)==0) return 420;
  if(strcmp("quit",buffer)==0) return -2;
  else return 100;
}

int whisper (char *in, char *out) {
  if( in == NULL || out ==NULL) return -1;
  int i = 0;
  while (in [i] != '\0'){
    char c = in [i];
      if (c<='Z' && c>='A'){
        c= c + ('a' -'A');
  }
  out [i] =c;
  i++;
  }
  out [i] = '\0';
  return 1;
}


int RNG(){ // assign a variable like so: n = RNG()
  //returns some value between 0 to 99
  time_t t;
  srand((unsigned) time(&t));
  if (t < 0) t = -t;
  return t % 100;
}

int typeEvent (int* eventNumber){
     // prompts which type of event is wanted and changes what value the random number generater generates based on the response
    char response[BUFFERSIZE];
    int err,responseNumber;
    int random = RNG();
    printf("Type 'military' to visit your miitary, 'oligarchy' to visit your oligarchy, or 'people' to visit the people.\n");
    err=readResponse(response);
    assert(err);
    responseNumber=parseResponse(response);
    //debugging jazz
    
    if(responseNumber==3){
    *eventNumber = random % 5;
    return 0;
    }
    if(responseNumber==4){
      *eventNumber= random%5 +5;
      return 0;
    }
    if(responseNumber==420){
      *eventNumber=random%5+10;
      return 0;
    }
    if(responseNumber==-2){
      return -2;
    }
    else return -1;
   }

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
    
  int typeErr=0;
  int eventErr=0;
  int eventNumber=-1;
  int revolt = 0;
  printf("Military:%d Oligarchy:%d People:%d Turn Number:%d\n", user->military, user->oligarchy, user->people, user->turns);
  while(1){
    typeErr=typeEvent(&eventNumber);
    if(typeErr==-2) break;
    if(typeErr==0){
      printf("eventNumber= %d\n",eventNumber);
    }
  }
  //delete line bellow, for debugging purposes
  printf("game over bitch\n");
  free(user);
  return 0;
}
