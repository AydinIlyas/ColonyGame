#ifndef ProductionB_h
#define ProductionB_h

#include "Production.h"

struct ProductionB {
    Production super;
    int (*produce)(struct ProductionB*);
    void (*delete)(struct ProductionB*);
};
typedef struct ProductionB* ProductionB;

ProductionB new_ProductionB();
int produceB(const ProductionB);
void delete_ProductionB(const ProductionB);
#endif