#include <stdio.h>
#include "dataType.h"
#include "startUp.h"
#include "editCourse.h"
#include "editGrade.h"
#include "expectedFinalGrade.h"
#include "io.h"

int main() {
    int opt = 0;
    startMenu();
    while (~scanf("%d", &opt) && opt != 5) {
        if (opt == 3) // expected final grade
            expectedFinalGrade();
    }
    return 0;
}

/*
    if (opt == 1) // edit course   
    if (opt == 2) // edit grade

    if (opt == 4) // view course
*/