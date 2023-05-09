#ifndef Production_h
#define Production_h
#include <stdlib.h>
#include <time.h>
struct Production {

    int (*produce)();
    void (*delete)(struct Production*);
};
typedef struct Production* Production;

Production new_Production();
void delete_Production(const Production);
#endif