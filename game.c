this will be the c file for the user to run

//Player Structer 
  //keeps track of Money, Approval by sects, turn country,
  
//Each event is its own function with two outcomes
  //Call event is also function
  
  // fgets() or getchar() instead of scanf()?
  struct_player{
  int military; 
  int oligarcy; 
  int people; 
  double money;
  int turns;
  };
  typedef struct_player player;


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
    printf("Military, Oligarcy, or People");
    int arb = scanf("%s", response);
    if (strlen(response) > 5 ) {
    printf("usage");
    return -1;
    // if -1 is returned don't change event number and call same event again
    }
    if (strngcmp (*response,"M"){
    eventNumber= rndm();
      //or rndm()%5
      //or rndm()%5 =10
    }
    while (err!=1){
    err = EventSelect(eventNumber);
    if (err == -2){
      //quit
    }
        else{
          err = EventSelect(eventNumber);
        }
    }
    }
   }
        
        
  int main () {
  //allocate memory for player struct
    //initialize values, print them to the player
  //print some instructions
  //get varification that they read it
  int err;
  int random;
  while (1);
  if (err == 1){
  random = rndm ();
  }
  err = EventSelect(random);
  if (err == -2 || "resources depleated"){
  //end program, print score
  }
  }
  
  
