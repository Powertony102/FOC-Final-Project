#include <stdio.h>
#include "startUp.h"

void startMenu() {
    printf("\n============== Main Menu ==============\n");
    printf("\t1. Edit Course\n");
    printf("\t2. Edit Grade\n");
    printf("\t3. Expected Final Grade\n");
    printf("\t4. View Course\n");
    printf("\t5. Exit\n");
    printf("=======================================\n\n");
}

int startEditCourseMenu() {
    printf("\n============== Edit Course ==============\n");
    printf("\t1. Add Course\n");
    printf("\t2. Delete Course\n");
    printf("\t3. Delete All Courses\n");
    printf("\t4. Modify Course\n");
    printf("\t5. Back\n");
    printf("=======================================\n\n");
    printf("Enter a number and choose an operation:");
    int opt = 0;
    scanf("%d", &opt);
    puts("");
    return opt;
}

int startEditGradeMenu() {
    printf("============== Main Menu ==============\n");
    printf("\t1. Add Grade\n");
    printf("\t2. Delete Grade\n");
    printf("\t3. Delete All Grades\n");
    printf("\t4. Modify Grade\n");
    printf("\t5. Back\n");
    printf("==========================================\n");
    printf("Enter a number and choose an operation:");
    int opt = 0;
    scanf("%d", &opt);
    puts("");
    return opt;
}

int startExpectedFinalGradeMenu() {
    printf("\n============== Calculate Expected Final ==============\n");
    printf("\t1. View All Courses\n");
    printf("\t2. View Single Course\n");
    printf("\t3. Back\n");
    printf("=======================================================\n\n");
    printf("Enter a number and choose an operation:");
    int opt = 0;
    scanf("%d", &opt);
    puts("");
    return opt;
}