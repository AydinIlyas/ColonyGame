#ifndef Tactic_h
#define Tactic_h

struct Tactic{
    int (*fight)();
    void (*delete)(struct Tactic*);
};
typedef struct Tactic* Tactic;

Tactic new_Tactic();
void delete_Tactic(const Tactic);

#endif