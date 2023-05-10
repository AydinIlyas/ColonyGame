#include "Colony.h"

Colony new_Colony(char symbol,int population,char tactic)
{
    Colony this=(Colony)malloc(sizeof(struct Colony));
    this->symbol=symbol;
    this->population=population;
    this->food=population*population;
    if(tactic=='a')
    this->Tactic=new_TacticA();
    else 
    this->Tactic=new_TacticB();
    this->tacticCh=tactic;
    this->wins=0;
    this->loses=0;

    this->fight=&fight;
    
}

void fight(const Colony first, const Colony second)
{
    int First=first->tacticCh=='a'?((TacticA)first->Tactic)->super->fight(first->Tactic):((TacticB)first->Tactic)->super->fight(first->Tactic);
    printf("First: %d\n",First);
    int Second=second->tacticCh=='a'?((TacticA)second->Tactic)->super->fight(second->Tactic):((TacticB)second->Tactic)->super->fight(second->Tactic);
    printf("Second: %d\n",Second);
    int winner=First>Second?1:(First<Second)?2:0;
    printf("Winner: %d\n",winner);

}

void deleteColony(const Colony this)
{
    
}