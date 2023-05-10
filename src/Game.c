#include "Game.h"
Game new_Game()
{
    Game this = (Game)malloc(sizeof(struct Game));
    this->read = &read;
    this->delete = &deleteGame;
}
void expand(int *arr, size_t capacity)
{
    int *myrealloced_array = realloc(arr, capacity * sizeof(int));
    if (myrealloced_array)
    {
        arr = myrealloced_array;
    }
    else
    {
        // deal with realloc failing because memory could not be allocated.
        printf("Realloc failed");
    }
}

void read(const Game this)
{
    size_t size = 0;
    size_t capacity = 5;
    int *arr = malloc(capacity * sizeof(int));
    char temp;
    do
    {
        scanf("%d%c", &arr[size], &temp);
        size++;
        if (capacity == size)
        {
            capacity *= 2;
            printf("\n%d\n", capacity);
            expand(arr, capacity);
        }
    } while (temp != '\n');
    
    for (int i = 0; i < size; i++)
    {
        
    }
}

void deleteGame(const Game this)
{
    if (this == NULL)
        return;
    free(this);
}