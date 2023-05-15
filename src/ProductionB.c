#include "ProductionB.h"
#include <stdlib.h>

ProductionB new_ProductionB()
{
    ProductionB this= (ProductionB)malloc(sizeof(struct ProductionB));
    this->super=new_Production();
    this->super->produce=&produceB;
    this->delete=&delete_ProductionB;
    return this;
}
int produceB(const ProductionB this)
{
    return (rand()%10)+1;
}
void delete_ProductionB(const ProductionB this)
{
    if(this==NULL)return;
    this->super->delete(this->super);
    free(this);
}