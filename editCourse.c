#include <stdio.h>
#include <string.h>
#include "dataType.h"
#include "io.h"
#include "startUp.h"
#include "editCourse.h"

void addCourse() {
    char buf[205];
    printf("Enter NEW course ID (Character+Number, lenghth < 10) or any single key back:");
    fflush(stdin);
    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\n")] = '\0';
    if (strlen(buf) == 1) return;
    ++ courseNumber;
    int cur = courseNumber;
    sscanf(buf, "%s", allCourse[cur].courseId);
    puts("");

    printf("Enter course name (less than 50 characters with spaces):");
    fflush(stdin);
    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\n")] = '\0';
    strcpy(allCourse[cur].courseName, buf);

    puts("Add course successfully but evaluation items.");
    putchar('\n');

    printf("The newly added course is %s, %s.\n", allCourse[cur].courseId, allCourse[cur].courseName);
    putchar('\n');

    fflush(stdin);
    printf("Continue to set the evaluation items for this course? (Y or y: yes; any other character: no): ");
    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\n")] = '\0';
    if (strlen(buf) > 1 || (buf[0] != 'Y' && buf[0] != 'y')) return;

    printf("Enter number of evaluation items for the new course:");
    scanf("%d", &allCourse[cur].itemNumber);

    printf("Input name, percentage, full marks for each item\n");
    printf("(attention: no space in names and the total percentage should be 100):\n");

    item* it;
    for (int i = 1; i <= allCourse[cur].itemNumber; ++ i) {
        fflush(stdin);
        fgets(buf, sizeof(buf), stdin);
        buf[strcspn(buf, "\n")] = '\0';
        it = &allCourse[cur].itemList[i];
        sscanf(buf, "%s %f %f", it -> itemName, &(it -> fullMark), &(it -> percentage));
    }   
    putchar('\n');
    printCurrentRecorded();
    
    putchar('\n');
    writeAllCourse();
    addCourse();
    return;
}

void editCourseMenu() {
    int opt = -1;
    readAllCourse(allCourse);
    while (opt = startEditCourseMenu()) {
        if (opt == 1) addCourse();
        if (opt == 2) {

        }
        if (opt == 3) {

        }
        if (opt == 4) {

        }
        if (opt == 5) break;
        writeAllCourse();
    }
    writeAllCourse();
}