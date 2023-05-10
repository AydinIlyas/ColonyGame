#include "Game.h"
typedef void* Object;
int main()
{
    srand(time(NULL));
    Game game=new_Game();
    game->read(game);
    Colony clny1=new_Colony('a',10,'a','b');
    Colony clny2=new_Colony('b',20,'b','a');
    printf("%d ",sizeof(*clny1));
    printf("%d \n",sizeof(*clny2));
    Colony* colonies=malloc(sizeof(struct Colony*));
    colonies[0]=clny1;
    colonies[1]=clny2;
    for(int i=0;i<2;i++)
    {
        printf("%d\n",colonies[i]->population);
    }
    for(int i=0;i<2;i++)
    {
        colonies[i]->delete(colonies[i]);
    }
    // colonies[0]->fight(colonies[0],colonies[1]);
    // printf("%d",);

    // clny1->fight(clny1,clny2);
    // clny1->delete(clny1);
    // clny2->delete(clny2);













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