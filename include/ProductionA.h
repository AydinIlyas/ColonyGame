#ifndef ProductionA_h
#define ProductionA_h

#include "Production.h"
struct ProductionA {
    Production super;
    void (*delete)(struct ProductionA*);
};
typedef struct ProductionA* ProductionA;

ProductionA new_ProductionA();
int produceA(const ProductionA);
void delete_ProductionA(const ProductionA);
#endif