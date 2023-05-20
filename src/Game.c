#include "Game.h"
#include <conio.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
Game new_Game()
{
    Game this = (Game)malloc(sizeof(struct Game));
    this->sizeAll = 0;
    this->sizeAlive = 0;
    this->capacity = 5;
    this->round = 0;
    this->gameStatus = 1;
    this->getPopulations = &getPopulations;
    this->showPopulations = &showPopulations;
    this->startRounds = &startRounds;
    this->delete = &deleteGame;
    this->allColonies = NULL;
    this->aliveColonies = NULL;
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
    printf("\nENTER POPULATIONS (FORMAT: 'X X X') : ");
    int *arr = (int *)malloc(this->capacity * sizeof(int));
    char temp;
    char input[1000];
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " \n");
    while (token != NULL)
    {
        char *endptr;
        long number = strtol(token, &endptr, 10);
        if(this->sizeAll==this->capacity)
        {
            expand(&arr,this);
        }

        // Check for conversion errors
        if (isspace(*endptr) || *endptr == '\0')
        {
            if (number > 0 && number <= (int)sqrt(INT_MAX))
            {
                arr[this->sizeAll] = (int)number;
                this->sizeAll++;
            }
            else
            {
                printf("Integer value out of range for Food(Food=Pop^2): %d\n", number);
            }
        }
        else
        {
            printf("INVALID INPUT: %s\n", token);
        }

        token = strtok(NULL, " \n");
    }
    printf("\n");

    if(this->sizeAll<=1)
    {
        printf("\nTHERE SHOULD BE AT LEAST 2 POPULATIONS!\nPRESS q FOR EXIT | r FOR RESTART");
        char ch=getch();
        this->gameStatus=ch=='r'?2:0;
    }

    this->allColonies = malloc(this->sizeAll * sizeof(struct Colony *));
    for (size_t i = 0; i < this->sizeAll; i++)
    {
        this->allColonies[i] = new_Colony(rand() % 222 + 33, arr[i], rand() % 2 + 97, rand() % 2 + 97);
    }

    this->aliveColonies = malloc(this->sizeAll * sizeof(struct Colony *));
    this->sizeAlive = this->sizeAll;
    for (size_t i = 0; i < this->sizeAlive; i++)
    {
        this->aliveColonies[i] = this->allColonies[i];
    }
    free(arr);
}

void printRound(const Game this, int started)
{
    printf("----------------------------------------------------------------------\n");
    if (started == 1)
        printf("%zu.ROUND\n", this->round);
    printf("Colony\t\tPopulation\tFood\t\tWins\t\tLoses\n");
    for (size_t i = 0; i < this->sizeAll; i++)
    {
        char *str = this->allColonies[i]->toString(this->allColonies[i]);
        printf("%s", str);
        free(str);
    }
}
void roundEnd(const Game this)
{
    for (size_t i = 0; i < this->sizeAlive; i++)
    {
        this->aliveColonies[i]->produce(this->aliveColonies[i]);
        this->aliveColonies[i]->roundImpact(this->aliveColonies[i]);
    }
}
bool checkWinner(const Game this)
{
    int counter = 0;
    for (size_t i = 0; i < this->sizeAlive; i++)
    {
        if (this->aliveColonies[i]->alive)
        {
            counter++;
            if (counter > 1)
                return false;
        }
    }
    return true;
}

void showPopulations(const Game this)
{
    if(this->gameStatus==0||this->gameStatus==2)return;
    printRound(this, 0);
    printf("\nPRESS ANY KEY TO START GAME\t|\tr FOR RESTART\t|\tq FOR EXIT\n\n");
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
void shrinkAlives(const Game this, int deads)
{
    Colony *tmp = malloc((this->sizeAlive - deads) * sizeof(struct Colony *));
    for (size_t i = 0, j = 0; i < this->sizeAlive; i++)
    {
        if (this->aliveColonies[i]->alive)
        {
            tmp[j] = this->aliveColonies[i];
            j++;
        }
    }
    free(this->aliveColonies);
    this->aliveColonies = tmp;
    this->sizeAlive -= deads;
}
void startRounds(const Game this)
{
    if (this->gameStatus == 2 || this->gameStatus == 0)
        return;
    this->round++;
    int deads = 0;
    for (size_t i = 0; i < this->sizeAlive; i++)
    {
        for (size_t j = i + 1; j < this->sizeAlive; j++)
        {
            this->aliveColonies[i]->fight(this->aliveColonies[i], this->aliveColonies[j]);
            if (this->aliveColonies[i]->checkAndReset(this->aliveColonies[i]))
                deads++;
            if (this->aliveColonies[j]->checkAndReset(this->aliveColonies[j]))
                deads++;
        }
    }
    roundEnd(this);
    printRound(this, 1);
    if (deads)
    {
        shrinkAlives(this, deads);
    }

    char g;
    if (checkWinner(this))
    {
        printf("\nGAME OVER!\n");
        printf("\nPRESS ANY KEY TO EXIT\t|\tr FOR RESTART\n\n");
        g = getch();
        if (g == 'r')
        {
            this->gameStatus = 2;
        }
        else
        {
            this->gameStatus = 0;
        }
        return;
    }
    else
    {
        printf("\nPRESS ANY KEY TO CONTINUE\t|\tr FOR RESTART\t|\tPress q FOR EXIT\n\n");
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
    for (size_t i = 0; i < this->sizeAll; i++)
    {
        this->allColonies[i]->delete (this->allColonies[i]);
    }
    free(this->allColonies);
    free(this->aliveColonies);
    free(this);
}
