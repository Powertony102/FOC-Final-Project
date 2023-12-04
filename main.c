#include <stdio.h>
#include "startup.h"

int main() {
    int opt = 0;
    startUp();
    while (~scanf("%d", &opt) && opt != 5) {
        /*
        if (opt == 1) // edit course   
        if (opt == 2) // edit grade
        if (opt == 3) // expected final grade
        if (opt == 4) // view course
        */
    }
    return 0;
}