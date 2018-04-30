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

int event0(player * user) {
  if(!user) return -1;
  char response[BUFFERSIZE];
  printf("That pesky foreign president tweeted something dumb again. Will you have the military up their training time to display force?\n");
  int err = parseResponse(response);
  if(err == 1){
    user->military -= 2;
    user->oligarchy += 1;
    user->people += 1;
    printf("Your people and staff are happy to feel safer, but the military is going to have to put in some extra work.\n");
    return 0;
  }
  if(err == 2){
    user->military += 1;
    user->oligarchy -= 3;
    user->people -= 2;
    printf("The troops are glad they don't have to work any harder than they do, but your country isn't too happy with your choice.\n");
    return 0;
  }
  if(err == -2) return -2;
  else {
    printf("Your options are yes/no/quit\n");
    return -1;
}
}
int event1(player * user) {
  if(!user) return -1;
  char response[BUFFERSIZE];
  printf("Your generals have been complaining that they've been too busy to golf lately. Will you reserve a golf course for them for a holiday weekend?\n");
  int err  = parseResponse(response);
  if(err == 1){
    user->military += 2;
    user->oligarchy -= 2;
    user->people -= 3;
    printf("Your generals are very happy with your choice, but they're the only ones.\n");
    return 0;
  }
  if(err == 2){
    user->military -= 1;
    user->people += 1;
    printf("The 99 percent are happy to have a win every once in a while.\n");
    return 0;
  }
  if(err == -2) return -2;
  else {
    printf("Your options are yes/no/quit\n");
    return -1;
}
}

int event2(player * user) {
  if(!user) return -1;
  char response[BUFFERSIZE];
  printf("A general was caught drinking and driving on his way back from a long day at the office. Will you pardon his crime?\n");
  int err = parseResponse(response);
  if(err == 1){
    user->military += 1;
    user->oligarchy -= 2;
    printf("Your Minister of Justice isn't especially happy with you, but the general is very greatful.\n");
    return 0;
  }
  if(err == 2){
    user->military -= 2;
    user->oligarchy += 1;
    printf("The Justice Department can't wipe the grins off of their faces.\n");
    return 0;
  }
  if(err == -2) return -2;
  else {
    printf("Your options are yes/no/quit\n");
    return -1;
}
}

int event3(player * user) {
  if(!user) return -1;
  char response[BUFFERSIZE];
  printf("A foreign government asks you to aid them in a war against a tyrant. Will you send troops to war to improve foreign relations?\n");
  int err = parseResponse(response);
  if(err == 1){
    user->military -= 2;
    user->oligarchy += 1;
    user->people += 1;
    printf("Your government and people are proud of you. Your troops sure aren't.\n");
    return 0;
  }
  if(err == 2){
    user->military += 1;
    user->oligarchy -= 1;
    user->people += 1;
    printf("Your oligarchy really could've used some leverage on that country, but at least your troops are safe.\n");
    return 0;
  }
  if(err == -2) return -2;
  else {
    printf("Your options are yes/no/quit\n");
    return -1;
}
}

int event4(player * user) {
  if(!user) return -1;
  char response[BUFFERSIZE];
  printf("The UN is demanding that you remove a military installation from a foreign country. Will you cave to their demands and force thousands of troops to move elsewhere?\n");
  int err = parseResponse(response);
  if(err == 1){
    user->military -= 2;
    user->oligarchy += 1;
    user->people += 1;
    printf("The UN is please with your choice, but your pile of hate mail from the troops is quite a bit bigger this week.\n");
    return 0;
  }
  if(err == 2){
    user->military += 2;
    user->oligarchy -= 1;
    printf("The generals respect your decision to stand your ground, but the oligarchs are practically drowning in paperwork.\n");
    return 0;
  }
  if(err == -2) return -2;
  else {
    printf("Your options are yes/no/quit\n");
    return -1;
}
}

int event5(player * user) {
  if(!user) return -1;
  char response[BUFFERSIZE];
  printf("Your favorite secretary has been caught stealing from one of your lower level politicians. Will you fire them for it?\n");
  int err = parseResponse(response);
  if(err == 1){
    user->oligarchy -= 3;
    user->people += 1;
    printf("Standing up for the little guy, look at you go.\n");
    return 0;
  }
  if(err == 2){
    user->military += 1;
    user->oligarchy += 1;
    user->people -= 3;
    printf("Stealing from the government will not be tolerated!\n");
    return 0;
  }
  if(err == -2) return -2;
  else {
    printf("Your options are yes/no/quit\n");
    return -1;
}
}

int event6(player * user) {
  if(!user) return -1;
  char response[BUFFERSIZE];
  printf("The government holiday party got a bit out of hand last year when an oligarch's guest snuck in a flask. Will you allow non-government officials to attend this year?\n");
  int err = parseResponse(response);
  if(err == 1){
    user->military -= 3;
    user->oligarchy += 1;
    user->people += 1;
    printf("Everyone loves parties! Oh wait, except maybe the guards that have to take care of the drunks...\n");
    return 0;
  }
  if(err == 2){
    user->oligarchy += 2;
    user->people -= 3;
    printf("It's a much more exclusive party now. That feels great for the people who get to go.\n");
    return 0;
  }
  if(err == -2) return -2;
  else {
    printf("Your options are yes/no/quit\n");
    return -1;
}
}

int event7(player * user) {
  if(!user) return -1;
  char response[BUFFERSIZE];
  printf("An admiral and your Minister of Trade are arguing over funding. Funnel funding from social security to please them both?\n");
 int err = parseResponse(response);
  if(err == 1){
    user->military += 1;
    user->oligarchy += 1;
    user->people -= 3;
    printf("Social security is just another one of your piggy banks.\n");
    return 0;
  }
  if(err == 2){
    user->military -= 2;
    user->oligarchy -= 2;
    user->people += 2;
    printf("Wow, your ethics professor would be proud.\n");
    return 0;
  }
  if(err == -2) return -2;
  else {
    printf("Your options are yes/no/quit\n");
    return -1;
}
}

int event8(player * user) {
  if(!user) return -1;
  char response[BUFFERSIZE];
  printf("Your press secretary was found guilty of tax evasion. Fire them publicly to maintain standards in your oligarchy?\n");
  int err = parseResponse(response);
  if(err == 1){
    user->oligarchy -= 1;
    user->people += 1;
    printf("The public is glad to know you have some standards.\n");
    return 0;
  }
  if(err == 2){
    user->military -= 2;
    user->oligarchy += 2;
    user->people -= 3;
    printf("After all, why get into politics if you can't play fast and loose with the law?\n");
    return 0;
  }
  if(err == -2) return -2;
  else {
    printf("Your options are yes/no/quit\n");
    return -1;
}
}

int event9(player * user) {
  if(!user) return -1;
  char response[BUFFERSIZE];
  printf("This is the third fire drill this month in the capitol building. Will you tell the general in charge of safety that you can't get any work done if you have to do all these dumb drills?\n");
  int err = parseResponse(response);
  if(err == 1){
    user->military -= 3;
    user->oligarchy += 1;
    printf("Yeah, drills are for their people, not yours.\n");
    return 0;
  }
  if(err == 2){
    user->military += 1;
    user->oligarchy -= 3;
    printf("The work has slowed to a crawl, but at least your general is happy.\n");
    return 0;
  }
  if(err == -2) return -2;
  else {
    printf("Your options are yes/no/quit\n");
    return -1;
}
}

int event10(player * user) {
  if(!user) return -1;
  char response[BUFFERSIZE];
  printf("Food rations are all so plain and the people are hungry! Allow the people to use their food rations on military-only installations?\n");
  int err = parseResponse(response);
  if(err == 1){
    user->military -= 4;
    user->people += 1;
    printf("Who would've known that cabbage soup tastes better with salt!\n");
    return 0;
  }
  if(err == 2){
    user->military += 1;
    user->people -= 3;
    printf("Maybe this way you can get more people to join up.\n");
    return 0;
  }
  if(err == -2) return -2;
  else {
    printf("Your options are yes/no/quit\n");
    return -1;
}
}

int event11(player * user) {
  if(!user) return -1;
  char response[BUFFERSIZE];
  printf("It's been too long since a good celebration. Will you throw an extravagant military parade for the people?\n");
  int err = parseResponse(response);
  if(err == 1){
    user->military -= 3;
    user->oligarchy += 1;
    user->people += 1;
    printf("All the generals in the capitol building are complaining about having to get their dress uniforms dry-cleaned.\n");
    return 0;
  }
  if(err == 2){
    user->military += 1;
    user->people -= 1;
    printf("If the people want entertainment, they can watch public broadcasting.\n");
    return 0;
  }
  if(err == -2) return -2;
  else {
    printf("Your options are yes/no/quit\n");
    return -1;
}
}

int event12(player * user) {
  if(!user) return -1;
  char response[BUFFERSIZE];
  printf("The radio propaganda has been getting a bit stale lately. Will you have your Minister of Internal Affairs make a whole new campaign?\n");
  int err = parseResponse(response);
  if(err == 1){
    user->oligarchy -= 2;
    user->people += 2;
    printf("Maybe now you can get that 40-year-old jingle out of your head.\n");
    return 0;
  }
  if(err == 2){
    user->oligarchy += 1;
    user->people -= 2;
    printf("Those tunes are just so catchy, why wouldn't they like them?\n");
    return 0;
  }
  if(err == -2) return -2;
  else {
    printf("Your options are yes/no/quit\n");
    return -1;
}
}

int event13(player * user) {
  if(!user) return -1;
  char response[BUFFERSIZE];
  printf("The son of your Minister of Finance is being bullied in school. He recommends you station soldiers in the school to intimidate the other children.\n");
  int err = parseResponse(response);
  if(err == 1){
    user->military -= 1;
    user->oligarchy += 2;
    user->people -= 3;
    printf("If the son of a government official can't have fun, then no-one can.\n");
    return 0;
  }
  if(err == 2){
    user->oligarchy -= 2;
    user->people += 1;
    printf("Yeah, probably a good call.\n");
    return 0;
  }
  if(err == -2) return -2;
  else {
    printf("Your options are yes/no/quit\n");
    return -1;
}
}

int event14(player * user) {
  if(!user) return -1;
  char response[BUFFERSIZE];
  printf("The streets are starting to stink in the capitol. Will you redirect military funding to improve the sewage plant?\n");
  int err = parseResponse(response);
  if(err == 1){
    user->military -= 2;
    user->people += 1;
    printf("Wow, that smell is way worse outside your mansion. That was probably a good idea.\n");
    return 0;
  }
  if(err == 2){
    user->military += 1;
    user->people -= 2;
    printf("Why aren't the toilets flushing? Uh-oh.\n");
    return 0;
  }
  if(err == -2) return -2;
  else {
    printf("Your options are yes/no/quit\n");
    return -1;
}
}

typedef int (*f)(player (*user));                 //declare typdef
//not currently  scaled for full implementation, just proof of concept/syntax
// in actual implementation events will exist in their own library for scalable implementation


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
  scanf("%s",response);
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

int coup(player * user){
  int threshold = 3 + user->turns / 3;
  int badnews = RNG();
  if(user->military <= threshold){
    if(badnews < (20 + 10 * (user->turns / 3) + 10 * (threshold - user->military))){
      printf("The military revolts!\n");
      return -2;
    }
  }
  if(user->oligarchy <= threshold){
    if(badnews < (20 + 10 * (user->turns / 3) + 10 * (threshold - user->oligarchy))){
      printf("The oligarchy revolts!\n");
      return -2;
    }
  }
  if(user->people <= threshold){
    if(badnews < (20 + 10 * (user->turns / 3) + 10 * (threshold - user->people))){
      printf("The people revolt!\n");
      return -2;
    }
  }
  return 0;
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
    int responseNumber;
    int random = RNG();
    printf("Type 'military' to visit your miitary, 'oligarchy' to visit your oligarchy, or 'people' to visit the people.\n");
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
    else{
      printf("Your options are 'military', 'oligarchy', 'people' or 'quit'\n");
      return -1;
   }
}


void turnEnd(player * user){
  user->turns += 1;
  printf("Your reputation: Military:%d Oligarchy:%d People:%d\n"
         "\nTurn number:%d\n",user->military,user->oligarchy,user->people,user->turns);
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

