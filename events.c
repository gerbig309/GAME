int eparseArg(){
  char[5] input;
  while(scanf("%c", input) != EOF){
    if(strlen(input) > 5){
      printf("Your options are yes, no, or quit. Only enter lower case please.\n");
      return -1;
    }
  }
  if(strcmp(input, "yes")) return 1;
  if(strcmp(input, "no")) return 2;
  if(strcmp(input, "quit")) return 3;
  else{
    printf("Your options are yes, no, or quit. Only enter lower case please.\n");
    return -1;
  }
}

int event0(player * user) {
  if(!user) return -1;
  printf("That pesky foreign president tweeted something dumb again. Will you have the military up their training time to display force?\n");
  int err = eparseArg();
  while(err == -1){
    err = eparseArg();
  }
  if(err == 1){
    user->military -= 2;
    user->oligarchy += 1;
    user->people += 1;
    printf("Your people and staff are happy to feel safer, but the military is going to have to put in some extra work.\n");
    return 0;
  }
  if(err == 2){
    user->military += 1;
    user->oligarchy -= 1;
    user->people -= 1;
    printf("The troops are glad they don't have to work any harder than they do, but your country isn't too happy with your choice.\n");
    return 0;
  }
  if(err == 3) return -2;
}

int event1(player * user) {
  if(!user) return -1;
  printf("Your generals have been complaining that they've been too busy to golf lately. Will you reserve a golf course for them for a holiday weekend?\n");
  int err = eparseArg();
  while(err == -1){
    err = eparseArg();
  }
  if(err == 1){
    user->military += 2;
    user->oligarchy -= 1;
    user->people -= 2;
    printf("Your generals are very happy with your choice, but they're the only ones.\n");
    return 0;
  }
  if(err == 2){
    user->military -= 1;
    user->people += 1;
    printf("The 99% are happy to have a win every once in a while.\n");
    return 0;
  }
  if(err == 3) return -2;
}

int event2(player * user) {
  if(!user) return -1;
  printf("A general was caught drinking and driving on his way back from a long day at the office. Will you pardon his crime?\n");
  int err = eparseArg();
  while(err == -1){
    err = eparseArg();
  }
  if(err == 1){
    user->military += 1;
    user->oligarchy -= 1;
    printf("Your Minister of Justice isn't especially happy with you, but the general is very greatful.\n");
    return 0;
  }
  if(err == 2){
    user->military -= 1;
    user->oligarchy += 1;
    printf("The Justice Department can't wipe the grins off of their faces.\n");
    return 0;
  }
  if(err == 3) return -2;
}

int event3(player * user) {
  if(!user) return -1;
  printf("A foreign government asks you to aid them in a war against a tyrant. Will you send troops to war to improve foreign relations?\n");
  int err = eparseArg();
  while(err == -1){
    err = eparseArg();
  }
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
  if(err == 3) return -2;
}

int event4(player * user) {
  if(!user) return -1;
  printf("The UN is demanding that you remove a military installation from a foreign country. Will you cave to their demands and force thousands of troops to move elsewhere?\n");
  int err = eparseArg();
  while(err == -1){
    err = eparseArg();
  }
  if(err == 1){
    user->military -= 2;
    user->oligarchy += 1;
    user->people +1 1;
    printf("The UN is please with your choice, but your pile of hate mail from the troops is quite a bit bigger this week.\n");
    return 0;
  }
  if(err == 2){
    user->military += 2;
    user->oligarchy -= 1;
    printf("The generals respect your decision to stand your ground, but the oligarchs are practically drowning in paperwork.\n");
    return 0;
  }
  if(err == 3) return -2;
}

int event5(player * user) {
  if(!user) return -1;
  printf("Your favorite secretary has been caught stealing from one of your lower level politicians. Will you fire them for it?\n");
  int err = eparseArg();
  while(err == -1){
    err = eparseArg();
  }
  if(err == 1){
    user->oligarchy -= 1;
    user->people +1 1;
    printf("Standing up for the little guy, look at you go.\n");
    return 0;
  }
  if(err == 2){
    user->military += 1;
    user->oligarchy += 1;
    user->people -= 2;
    printf("Stealing from the government will not be tolerated!\n");
    return 0;
  }
  if(err == 3) return -2;
}

int event6(player * user) {
  if(!user) return -1;
  printf("The government holiday party got a bit out of hand last year when an oligarch's guest snuck in a flask. Will you allow non-government officials to attend this year?\n");
  int err = eparseArg();
  while(err == -1){
    err = eparseArg();
  }
  if(err == 1){
    user->military -= 2;
    user->oligarchy += 1;
    user->people += 1;
    printf("Everyone loves parties! Oh wait, except maybe the guards that have to take care of the drunks...\n");
    return 0;
  }
  if(err == 2){
    user->oligarchy += 2;
    user->people -= 2;
    printf("It's a much more exclusive party now. That feels great for the people who get to go.\n");
    return 0;
  }
  if(err == 3) return -2;
}

int event7(player * user) {
  if(!user) return -1;
  printf("An admiral and your Minister of Trade are arguing over funding. Funnel funding from social security to please them both?\n");
  int err = eparseArg();
  while(err == -1){
    err = eparseArg();
  }
  if(err == 1){
    user->military += 1;
    user->oligarchy += 1;
    user->people -= 2;
    printf("Social security is just another one of your piggy banks.\n");
    return 0;
  }
  if(err == 2){
    user->military -= 1;
    user->oligarchy -= 1;
    user->people += 2;
    printf("Wow, your ethics professor would be proud.\n");
    return 0;
  }
  if(err == 3) return -2;
}

int event8(player * user) {
  if(!user) return -1;
  printf("Your press secretary was found guilty of tax evasion. Fire them publicly to maintain standards in your oligarchy?\n");
  int err = eparseArg();
  while(err == -1){
    err = eparseArg();
  }
  if(err == 1){
    user->oligarchy -= 1;
    user->people += 1;
    printf("The public is glad to know you have some standards.\n");
    return 0;
  }
  if(err == 2){
    user->military -= 1;
    user->oligarchy += 2;
    user->people -= 2;
    printf("After all, why get into politics if you can't play fast and loose with the law?\n");
    return 0;
  }
  if(err == 3) return -2;
}

int event9(player * user) {
  if(!user) return -1;
  printf("This is the third fire drill this month in the capitol building. Will you tell the general in charge of safety that you can't get any work done if you have to do all these dumb drills?\n");
  int err = eparseArg();
  while(err == -1){
    err = eparseArg();
  }
  if(err == 1){
    user->military -= 2;
    user->oligarchy += 1;
    printf("Yeah, drills are for their people, not yours.\n");
    return 0;
  }
  if(err == 2){
    user->military += 1;
    user->oligarchy -= 1;
    printf("The work has slowed to a crawl, but at least your general is happy.\n");
    return 0;
  }
  if(err == 3) return -2;
}

int event10(player * user) {
  if(!user) return -1;
  printf("Food rations are all so plain and the people are hungry! Allow the people to use their food rations on military-only installations?\n");
  int err = eparseArg();
  while(err == -1){
    err = eparseArg();
  }
  if(err == 1){
    user->military -= 1;
    user->people += 1;
    printf("Who would've known that cabbage soup tastes better with salt!\n");
    return 0;
  }
  if(err == 2){
    user->military += 1;
    user->people -= 1;
    printf("Maybe this way you can get more people to join up.\n");
    return 0;
  }
  if(err == 3) return -2;
}

int event11(player * user) {
  if(!user) return -1;
  printf("It's been too long since a good celebration. Will you throw an extravagant military parade for the people?\n");
  int err = eparseArg();
  while(err == -1){
    err = eparseArg();
  }
  if(err == 1){
    user->military -= 2;
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
  if(err == 3) return -2;
}

int event12(player * user) {
  if(!user) return -1;
  printf("The radio propaganda has been getting a bit stale lately. Will you have your Minister of Internal Affairs make a whole new campaign?\n");
  int err = eparseArg();
  while(err == -1){
    err = eparseArg();
  }
  if(err == 1){
    user->oligarchy -= 2;
    user->people += 2;
    printf("Maybe now you can get that 40-year-old jingle out of your head.\n");
    return 0;
  }
  if(err == 2){
    user->oligarchy += 1;
    user->people -= 1;
    printf("Those tunes are just so catchy, why wouldn't they like them?\n");
    return 0;
  }
  if(err == 3) return -2;
}

int event13(player * user) {
  if(!user) return -1;
  printf("The son of your Minister of Finance is being bullied in school. He recommends you station soldiers in the school to intimidate the other children.\n");
  int err = eparseArg();
  while(err == -1){
    err = eparseArg();
  }
  if(err == 1){
    user->military -= 1;
    user->oligarchy += 2;
    user->people -= 2;
    printf("If the son of a government official can't have fun, then no-one can.\n");
    return 0;
  }
  if(err == 2){
    user->oligarchy -= 1;
    user->people += 1;
    printf("Yeah, probably a good call.\n");
    return 0;
  }
  if(err == 3) return -2;
}

int event14(player * user) {
  if(!user) return -1;
  printf("The streets are starting to stink in the capitol. Will you redirect military funding to improve the sewage plant?\n");
  int err = eparseArg();
  while(err == -1){
    err = eparseArg();
  }
  if(err == 1){
    user->military -= 1;
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
  if(err == 3) return -2;
}
