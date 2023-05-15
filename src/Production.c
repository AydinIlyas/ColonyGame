#include "Production.h"
#include <stdlib.h>
Production new_Production()
{
    Production this= (Production)malloc(sizeof(struct Production));
    this->delete=&delete_Production;
    return this;
}

void delete_Production(const Production this)
{
    if(this==NULL)return;
    free(this);
}