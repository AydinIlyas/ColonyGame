#include "TacticA.h"
#include "TacticB.h"
#include "ProductionA.h"
#include "ProductionB.h"
#include "Colony.h"
typedef void* Object;
int main()
{
    srand(time(NULL));
    Colony clny1=new_Colony('a',10,'a');
    Colony clny2=new_Colony('b',20,'b');
    clny1->fight(clny1,clny2);















    // for(int i=0;i<20;i++)
    // {
    //     char c=rand();
    //     printf("%c\t",c);
    // }
    
    













    // Object tactic=new_TacticA();
    // printf("%d\n",((TacticA)tactic)->super->fight(tactic));
    // ((TacticA)tactic)->delete(tactic);

    // tactic=new_TacticB();
    // printf("%d\n",((TacticB)tactic)->super->fight(tactic));
    // ((TacticB)tactic)->delete(tactic);
    // ProductionA prdA=new_ProductionA();
    // printf("%d\t",prdA->produce(prdA));
    // prdA->delete(prdA);//130 239

    // ProductionB prdB=new_ProductionB();
    // printf("%d",prdB->produce(prdB));
    // prdB->delete(prdB);
}