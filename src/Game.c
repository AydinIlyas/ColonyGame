#include "Game.h"
Game new_Game()
{
    Game this = (Game)malloc(sizeof(struct Game));
    this->size = 0;
    this->capacity = 5;
    this->round = 0;
    this->gameStatus = 1;
    this->getPopulations = &getPopulations;
    this->showPopulations = &showPopulations;
    this->startRounds = &startRounds;
    this->delete = &deleteGame;
    this->allColonies = NULL;
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
    printf("\nENTER POPULATIONS (FORMAT: 'X X X' NO SPACE AT THE END!) : ");
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
    this->allColonies = malloc(this->size * sizeof(struct Colony *));
    for (size_t i = 0; i < this->size; i++)
    {
        this->allColonies[i] = new_Colony(rand() % 222 + 33, arr[i], rand() % 2 + 97, rand() % 2 + 97);
    }
    free(arr);
}

void printRound(const Game this, int started)
{
    printf("----------------------------------------------------------------------\n");
    if (started == 1)
        printf("%zu.ROUND\n", this->round);
    printf("Colony\t\tPopulation\tFood\t\tWins\t\tLoses\n");
    for (size_t i = 0; i < this->size; i++)
    {
        char *str = this->allColonies[i]->toString(this->allColonies[i]);
        printf("%s", str);
        free(str);
    }
}
void roundEnd(const Game this)
{
    for (size_t i = 0; i < this->size; i++)
    {
        this->allColonies[i]->produce(this->allColonies[i]);
        this->allColonies[i]->roundImpact(this->allColonies[i]);
    }
}
int checkWinner(const Game this)
{
    int counter = 0;
    for (size_t i = 0; i < this->size; i++)
    {
        if (this->allColonies[i]->food > 0 && this->allColonies[i]->population > 0)
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
    printRound(this, 0);
    printf("\nPRESS A KEY TO START GAME\t|\tr FOR RESTART\t|\tq FOR EXIT\n\n");
    char ch = getch();
    if (ch == 'r')
    {
        this->gameStatus = 2;
    }
    else if (ch == 'q')
    {
        this->gameStatus = 0;
    }
    else
    {
        this->gameStatus = 1;
    }
}

void startRounds(const Game this)
{
    if (this->gameStatus == 2 || this->gameStatus == 0)
        return;
    this->round++;
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = i + 1; j < this->size; j++)
        {
            this->allColonies[i]->fight(this->allColonies[i], this->allColonies[j]);
            this->allColonies[i]->checkAndReset(this->allColonies[i]);
            this->allColonies[j]->checkAndReset(this->allColonies[j]);
        }
    }
    roundEnd(this);
    printRound(this, 1);

    char g;
    if (checkWinner(this))
    {
        printf("\nPRESS A KEY TO EXIT\t|\tr FOR RESTART\n\n");
        g=getch();
        if(g=='r')
        {
            this->gameStatus=2;
        }
        else{
            this->gameStatus=0;
        }
        return;
    }
    else
    {
        printf("\nPRESS A KEY TO CONTINUE\t|\tr FOR RESTART\t|\tPress q FOR EXIT\n\n");
        g = getch();
        if (g == 'q')
        {
            this->gameStatus = 0;
        }
        else if (g == 'r')
        {
            this->gameStatus = 2;
        }
        startRounds(this);
    }
}

void deleteGame(const Game this)
{
    if (this->gameStatus == 2)
        system("cls");
    if (this == NULL)
        return;
    for (size_t i = 0; i < this->size; i++)
    {
        this->allColonies[i]->delete (this->allColonies[i]);
    }
    free(this->allColonies);
    free(this);
}