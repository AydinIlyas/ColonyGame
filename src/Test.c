#include "TacticA.h"
int main()
{
    TacticA t=new_TacticA();
    printf("%d",t->fight(t));
    t->delete(t);
    

}