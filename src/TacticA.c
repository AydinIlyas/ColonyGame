#include "TacticA.h"
#include <stdlib.h>

TacticA new_TacticA()
{
    TacticA this=(TacticA)malloc(sizeof(struct TacticA));
    this->super=new_Tactic();
    this->super->fight=&fightA;
    this->delete=&deleteTacticA;
    return this;
}
int fightA(const TacticA this)
{
    return rand()%1001;
}

void deleteTacticA(const TacticA this)
{
    if(this==NULL)return;
    this->super->delete(this->super);
    free(this);
}