#include "Game.h"
Game new_Game()
{
    Game this = (Game)malloc(sizeof(struct Game));
    this->size = 0;
    this->capacity = 5;
    this->round = 0;
    this->getPopulations = &getPopulations;
    this->showPopulations = &showPopulations;
    this->startRounds = &startRounds;
    this->delete = &deleteGame;
    this->colonies = NULL;
}
void expand(int **arr, const Game this)
{
    this->capacity = this->capacity * 2;
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

void getPopulations(const Game this)
{

    int *arr = (int *)malloc(this->capacity * sizeof(int));
    char temp;
    do
    {
        if (this->capacity == this->size)
        {
            expand(&arr, this);
        }
        scanf("%d%c", &arr[this->size], &temp);
        this->size++;

    } while (temp != '\n');
    this->colonies = malloc(this->size * sizeof(struct Colony *));
    for (size_t i = 0; i < this->size; i++)
    {
        this->colonies[i] = new_Colony(rand()%222+33, arr[i], rand() % 2 + 97, rand() % 2 + 97);
    }
    free(arr);
}

void printRound(const Game this)
{
    printf("----------------------------------------------------------------------\n%zu.ROUND\n",this->round);
    printf("Colony\t\tPopulation\tFood\t\tWins\t\tLoses\n");
    for(size_t i=0;i<this->size;i++)
    {
        char* str=this->colonies[i]->toString(this->colonies[i]);
        printf("%s",str);
        free(str);
    }
}
void roundEnd(const Game this)
{
    for (size_t i = 0; i < this->size; i++)
    {
        this->colonies[i]->produce(this->colonies[i]);
        this->colonies[i]->roundImpact(this->colonies[i]);
    }
}
int checkWinner(const Game this)
{
    int counter = 0;
    for (size_t i = 0; i < this->size; i++)
    {
        if (this->colonies[i]->food > 0 && this->colonies[i]->population > 0)
        {
            counter++;
            if (counter > 1)
                return 0;
        }
    }
    return 1;
}

void showPopulations(const Game this)
{
    printRound(this);
    getch();
}

void startRounds(const Game this)
{
    this->round++;
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = i + 1; j < this->size; j++)
        {
            this->colonies[i]->fight(this->colonies[i], this->colonies[j]);
            this->colonies[i]->checkAndReset(this->colonies[i]);
            this->colonies[j]->checkAndReset(this->colonies[j]);
        }
    }
    roundEnd(this);
    printRound(this);

    if (checkWinner(this))
        return;
    else
    {
        printf("\nPRESS A KEY TO CONTINUE  |  Press q FOR EXIT\n");
        char g = getch();
        if (g == 'q')
            return;
        startRounds(this);
    }
}

void deleteGame(const Game this)
{
    if (this == NULL)
        return;
    for (size_t i = 0; i < this->size; i++)
    {
        this->colonies[i]->delete (this->colonies[i]);
    }
    free(this->colonies);
    free(this);
}