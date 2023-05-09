#include "Tactic.h"
Tactic new_Tactic()
{
    Tactic this=(Tactic)malloc(sizeof(struct Tactic));
    
    this->power=-1;
    this->delete=&delete_Tactic;
    return this;
}
void delete_Tactic(const Tactic this)
{
    if(this==NULL)
    {
        return;
    }
    free(this);
}