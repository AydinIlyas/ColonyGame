#ifndef ProductionB_h
#define ProductionB_h

#include "Production.h"

struct ProductionB {
    Production super;
    
    void (*delete)(struct ProductionB*);
};
typedef struct ProductionB* ProductionB;

ProductionB new_ProductionB();
int produceB(const ProductionB);
void delete_ProductionB(const ProductionB);
#endif