#include "Colony.h"

Colony new_Colony(char symbol,int population,char tactic,char production)
{
    Colony this=(Colony)malloc(sizeof(struct Colony));
    this->symbol=symbol;
    this->population=population;
    this->food=population*population;
    this->tacticCh=tactic;
    if(this->tacticCh=='a')
    this->Tactic=new_TacticA();
    else 
    this->Tactic=new_TacticB();

    this->productionCh=production;
    if(this->productionCh=='a')
    this->Production=new_ProductionA();
    else 
    this->Production=new_ProductionB();

    this->wins=0;
    this->loses=0;

    this->fight=&fight;
    this->delete=&deleteColony;
    this->toString=&toString;
    
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

void produce(const Colony this)
{
    if(this->productionCh=='a')
    {
        this->food+=((ProductionA)this->Production)->super->produce(this->Production);
    }
    else{
        this->food+=((ProductionB)this->Production)->super->produce(this->Production);
    }
}
int LengthInt(int num){
	int length = floor(log10(abs(num))) + 1;
	return length;
}
char* toString(const Colony this)
{
    int length=0;
    length+=3;
    length+=LengthInt(this->population);
    length+=LengthInt(this->food);
    
    char* str=(char*)malloc(sizeof(char)*length+10);

    sprintf(str,"%c\t\t%d\t\t%d\t\t%c\t\t%c\n",this->symbol,this->population,this->food,this->tacticCh,this->productionCh);
    return str;
}

void deleteColony(const Colony this)
{
    if(this==NULL)return;
    
    if(this->tacticCh=='a')
    ((TacticA)this->Tactic)->delete(this->Tactic);
    else 
    ((TacticB)this->Tactic)->delete(this->Tactic);

    if(this->productionCh=='a')
    ((ProductionA)this->Production)->delete(this->Production);
    else 
    ((ProductionB)this->Production)->delete(this->Production);
    free(this);

}