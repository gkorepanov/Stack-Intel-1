#ifndef S_REGISTER
#define S_REGISTER

enum {
    ZF,
    SF
};

enum {
#define REG_(name, size, shift)\
    name,

#include "../s_common/s_reglist.h"

#undef REG_
    REG_NUM
};

typedef struct {
    int* shifts;
    int* sizes;
    char* mem;
    bool flags[10];
} reg_t;

reg_t* reg_init();
void reg_put(int number, int value, reg_t* regs);
int reg_get(int number, reg_t* regs);
void reg_free(reg_t* regs);

#endif
