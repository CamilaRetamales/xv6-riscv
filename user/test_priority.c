#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/param.h"

int main(void) {
    set_priority(1, 1000);
    return 0;
}