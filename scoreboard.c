

struct _playerSB{
  char name[20];
  int score;
};
typdef struct _playerSB playerSB;

void addToScoreboard(int turns){
  FILE * scoreboard = fopen("scores.txt", "a");
  playerSB user;
  user->score = turns;
  printf("\nYou made the scoreboard! Please type your name: ");
  scanf("%s", user->name);
  fprintf(scoreboard, "%s %d\n", user->name, user->score);
  fclose(scoreboard);
}

void arrangeScores(){
  int i, j;
  playerSB playertemp;
  playerSB player[5];
  FILE * scoreboard = fopen("scoreboard.txt", "r");
  for(i=0; i<5; i++){
    fscanf(scoreboard, "%s %d%*c", player[i]->name, &player[i]->score);
    printf("Name: %s, score: %d\n", player[i]->name, player[i]->points);
  }
  for(i=0; i<5; i++){
    for(j=0; j<4; j++){
      if(player[j]->score > player[j+1]->score){
	playertemp = player[j];
	player[j] = player[j+1];
	player[j+1] = playertemp;
      }
    }
  }
  fclose(scoreboard);
  FILE * newscoreboard = fopen("scoreboard.txt", "w");
  void rewind(FILE * newscoreboard);
  for(i=0; i<5; i++){
    printf("%s %d\n", player[i]->name, player[i]->score);
    fprintf(newscoreboard, "%s %d\n", player[i]->name, player[i]->score);
  }
  fclose(newscoreboard);
}

int checkhighscore(int score){
  int i;
  playerSB playertemp;
  FILE * scoreboard = fopen("scoreboard.txt", "r");
  for(i=0; i<5; i++){
    fscanf(scoreboard, "%s %d", playertemp->name, playertemp->score);
    if(score > playertemp->score){
      addToScoreboard(score);
      arrangeScores();
    }
  }
  return 0;
}
      
