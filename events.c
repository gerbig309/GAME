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
