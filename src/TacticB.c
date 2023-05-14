#include "TacticB.h"
TacticB new_TacticB()
{
    TacticB this=(TacticB)malloc(sizeof(struct TacticB));
    this->super=new_Tactic();
    this->super->fight=&fightB;
    this->delete=&deleteTacticB;
    return this;
}

int fightB(const TacticB this)
{
    return rand()%1001;
}

void deleteTacticB(const TacticB this)
{
    if(this==NULL)return;
    this->super->delete(this->super);
    free(this);
}