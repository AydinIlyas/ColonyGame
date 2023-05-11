#include "TacticA.h"
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
    this->super->power=(rand()%1001);
    return this->super->power;
}

void deleteTacticA(const TacticA this)
{
    if(this==NULL)return;
    this->super->delete(this->super);
    free(this);
}