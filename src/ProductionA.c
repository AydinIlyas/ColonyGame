#include "ProductionA.h"

ProductionA new_ProductionA()
{
    ProductionA this= (ProductionA)malloc(sizeof(struct ProductionA));
    this->super=new_Production();
    this->super->produce=&produceA;
    this->produce=&produceA;
    this->delete=&delete_ProductionA;
    return this;
}
int produceA(const ProductionA this)
{
    return (rand()%10)+1;
}
void delete_ProductionA(const ProductionA this)
{
    if(this==NULL)return;
    this->super->delete(this->super);
    free(this);
}