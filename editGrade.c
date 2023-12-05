#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dataType.h"
#include "io.h"
#include "startUp.h"

void addGrade(int courseID, int itemID) {
    char buf[205];
    float score = 0.00;
    do {
        printf("Enter a grade to added to the item or a negative number back: ");
        fflush(stdin);
        fgets(buf, sizeof(buf), stdin);
        sscanf(buf, "%f", &score);
        if (score < 0.00) break;
        allCourse[courseID].itemList[itemID].grades[++ allCourse[courseID].itemList[itemID].gradesNumber] = score;
    } while (score >= 0.00);
    printSpecificItem(courseID, itemID);
}

void editGradeMenu() {
    char buf[205];
    printCurrentRecorded();
    int courseID = 0, itemID = 0;

    printf("Enter a number to edit the related course grades or any other key back: ");
    fflush(stdin);
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &courseID);
    putchar('\n');
    printSpecificCourse(courseID);

    printf("Enter the No. of an Item whose grades to be edited or any other key back: ");
    fflush(stdin);
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &itemID);
    putchar('\n');
    printSpecificItem(courseID, itemID);

    int opt = 0;
    while (opt = startEditGradeMenu()) {
        if (opt == 1) addGrade(courseID, itemID);
        if (opt == 2) {

        }
        if (opt == 3) {

        }
        if (opt == 4) {

        }
        if (opt == 5) {
            writeAllCourse();
            return;
        }
    }
}