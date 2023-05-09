#include "TacticA.h"
#include "TacticB.h"
int main()
{
    srand(time(NULL));
    TacticA t=new_TacticA();
    printf("%d\n",t->fight(t));
    t->delete(t);

    TacticB b=new_TacticB();
    printf("%d",b->fight(b));
    b->delete(b);

}