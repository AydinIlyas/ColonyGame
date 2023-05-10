#include "Game.h"

Game new_Game()
{
    Game this=(Game)malloc(sizeof(struct Game));
    this->read=&read;
    this->delete=&deleteGame;
}
void read(const Game this)
{
    int i=0, j=0; 
  int arr[10000]; 
  char temp; 
  do { 
      scanf("%d%c", &arr[i], &temp); 
      i++; 
  } while(temp != '\n'); 
   
  for(j=0; j<i; j++) { 
    printf("%d ", arr[j]); 
  } 

}

void deleteGame(const Game this)
{
    if(this==NULL)return;
    free(this);
}