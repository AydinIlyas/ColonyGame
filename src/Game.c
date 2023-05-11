#include "Game.h"
Game new_Game()
{
    Game this = (Game)malloc(sizeof(struct Game));
    this->size=0;
    this->capacity=5;
    this->read = &read;
    this->delete = &deleteGame;
    this->colonies=NULL;
}
void expand(int **arr,const Game this)
{
    this->capacity=this->capacity*2;
    int *myrealloced_array = realloc(*arr, this->capacity * sizeof(int));
    if (myrealloced_array)
    {
        *arr = myrealloced_array;
    }
    else
    {
        // deal with realloc failing because memory could not be allocated.
        printf("Realloc failed");
    }

}

void read(const Game this)
{
    
    int *arr = (int*)malloc(this->capacity * sizeof(int));
    char temp;
    do
    {
        if (this->capacity == this->size)
        {
            expand(&arr,this);
        }
        scanf("%d%c", &arr[this->size], &temp);
        this->size++;

    } while (temp != '\n');
    this->colonies=malloc(this->size*sizeof(struct Colony*));
    for (size_t i = 0; i < this->size; i++)
    {
        this->colonies[i]=new_Colony(rand()%256,arr[i],rand()%2+97,rand()%2+97);
    }
    free(arr);
}

void deleteGame(const Game this)
{
    if (this == NULL)
        return;
    for(size_t i=0;i<this->size;i++)
    {
        this->colonies[i]->delete(this->colonies[i]);
    }
    free(this->colonies);
    free(this);
}