#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Player Structer 
  //keeps track of Money, Approval by sects, turn country,
  
//Each event is its own function with two outcomes
  //Call event is also function
  
  // fgets() or getchar() instead of scanf()?
  struct_player{
  int military; 
  int oligarchy; 
  int people; 
  double money;
  int turns;
  };
  typedef struct_player player;

int coup(){
  int threshold = 3 + user->turns / 5;
  int badnews = RNG();
  if(user->military <= threshold){
    if(badnews < 20 + 10(user->turns / 5)){
      printf("The military revolts!");
      return -2;
    }
  }
  if(user->oligarchy <= threshold){
    if(badnews < 20 + 10(user->turns / 5)){
      printf("The oligarchy revolts!");
      return -2;
    }
  }
  if(user->people <= threshold){
    if(badnews < 20 + 10(user->turns / 5)){
      printf("The people revolt!");
      return -2;
    }
  }
  if(user->money <= 0){
    printf("You done gone and spent all the money!");
    return -2;
  }
  printf("Your pockets are full and your country is happy...for now.");
  return 0;
}
    

int RNG(){ // assign a variable like so: n = RNG()
  time_t t;
  srand((unsigned) time(&t));
  if (t < 0) t = -t;
  return t % 100;
}

void turnstart(){
  user->turns += 1;
  printf("Your reputation: Military:%d Oligarchy:%d People:%d\nNational Budget:$%f billion.\nTurn number:%d\n",user->military,user->oligarchy,user->people,user->money,user->turns);
}

int parseArg(){
  char[5] input;
  while(scanf("%c", input) != EOF){
    if(strlen(input) > 5){
      printf("Your options are 1, 2, yes, no, or quit. Only enter lower case please.\n");
      return -1;
    }
  }
  if(strcmp(input, "yes")) return 1;
  if(strcmp(input, "no")) return 2;
  if(strcmp(input, "1")) return 3;
  if(strcmp(input, "2")) return 4;
  if(strcmp(input, "quit")) return 5;
  else{
    printf("Your options are 1, 2, yes, no, or quit. Only enter lower case please.\n");
    return -1;
  }
}

  int EventPrototype () {
    if (arguements are invalid) return -1;
    printf("the situation");
    char response [5];
    int arb = scanf("%s", response);
    if (strlen(response) > 5 ) {
    printf("usage");
    return -1;
    // if -1 is returned don't change event number and call same event again
    }
    if (strngcmp (*response,"yes"){
    do this/ modify player struct
    return 1;
    }
    if (strngcmp (*response, "no"){
    do this 
    return 1;
    }
    if (strgcmp (*response, "quit"){
    End of game protocalls 
    return -2;
    }
    else{
    printf("options: yes/no/quit");
    return -1;
    }
  }

  int EventSelect (int n) {
    // int n is a randomly generated number
  if (n!= "acceptable value") return -1;
  // protection
    //determines which event will be run
  if (n>"min treshold"&& n< "max threshold") {
  return event1();
    //cascading error returns
  }
  }

   int typeEvent (){
     // prompts which type of event is wanted and changes what value the random number generater generates based on the response
    char response [5];
    int eventNumber;
    printf("Type M to visit your miitary, O to visit your oligarchy, or P to visit the people.\n");
     while(scanf("%c", &response) != EOF){
       if(strlen(response) > 5) return -1;
     }
    // if -1 is returned don't change event number and call same event again
    if (strngcmp (response,"M"){
    eventNumber= RNG() % 5;
    }
    if(strcmp(response,"O"){
      eventNumber = RNG()%5 + 5;
    }
    if(strcmp(response,"P"){
      eventNumber = RNG()%5 + 10;
    }
    while (err!=1){
    err = EventSelect(eventNumber);
    if (err == -2){
      return eventNumber;
      //quit
    }
        else{
          err = EventSelect(eventNumber);
        }
    }
    }
   }
        
        
  int main () {
    user = (player *) malloc(sizeof(player));
    if(!user){
      printf("didn't create user correctly");
      return 0;
    }
    user->military = 10;
    user->oligarchy = 10;
    user->people = 10;
    user->money = 100;
    user->turns = 0; //Initialize player stats
    printf("Welcome to our game! In this, you are a dictator trying not to be overthrown. To do this, you will have to make decisions to balance your reputaion between the people, military, and the oligarchy. Each turn you will decide where you want to go, and based on the location, be given an event that you will respond to. Based on your response, your reputation with each faction will change. The lower yor reputation with any given faction, the more likely you will be overthrown. The game gets more difficult over time, and the longer your reign, the better you must maintain your reputation. The goal of the game is to last as long as possible without being overthrown. Good luck!\n");
    
  int err;
  int random;
  while (1){ //Starts loop to play game. Loop will continue until fail condition met
  if (err == 1){ //Indicates event completed correctly. If not, for example a user error, then will not give new event
  random = RNG();
  }
  err = EventSelect(random); //Selects event
  if (err == -2){
    printf("You made it all the way to turn %d!\nYour reputation: Military:%d Oligarchy:%d People:%d\nNational Budget:$%f billion.\n",user->turns,user->military,user->oligarchy,user->people,user->money);
  }
    free(user);
    return 0;
  }
  }
  
  
