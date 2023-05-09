#include "TacticA.h"
TacticA new_TacticA()
{
    TacticA this=(TacticA)malloc(sizeof(struct TacticA));
    this->super=new_Tactic();
    this->super->fight=&fight;
    this->fight=&fight;
    this->delete=&deleteTacticA;
    return this;
}
int fight(const TacticA this)
{
    srand( time(NULL) );
    this->super->power=(rand()%1000)+0;
    return this->super->power;
}

void deleteTacticA(const TacticA this)
{
    if(this==NULL)return;
    this->super->delete(this->super);
    free(this);
}