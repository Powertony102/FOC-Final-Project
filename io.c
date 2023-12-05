#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataType.h"

int courseNumber;
course allCourse[105];

void writeCourse(const course output) {
    char filename[55];
    strcpy(filename, output.courseId);
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("writeCourse:Failed to open %s\n", filename);
        return;
    }
    // The First three line will be courseId,couseName,itemNumber
    fprintf(file, "%s\n", output.courseId);
    fprintf(file, "%s\n", output.courseName);
    fprintf(file, "%d\n", output.itemNumber);
    /* 
    if its isdeleted = 0, then it can be outputed.
    Otherwise, it represents that it has been deleted. So it cannot be outputed.
    */
    for (int i = 1; i <= output.itemNumber; ++ i) {
        item it = output.itemList[i];
        if (it.isDeleted) continue;
        /*
        Each line of each item, the information will be outputed as the format as the following
        it.itemName,it.fullMark,it.percentage,it.gradesNumber
        */
        fprintf(file, "%s %f %f %d\n", it.itemName, it.fullMark, it.percentage, it.gradesNumber);
        for (int j = 1; j <= it.gradesNumber; ++ j) {
            fprintf(file, "%f\n", it.grades[j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

course readCourse(const char *filename) {
    course input;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("readCourse:Failed to open %s\n", filename);
        exit(0);
    }

    char buf[205], smallBuf[25];
    fgets(buf, sizeof(buf), file);
    buf[strcspn(buf, "\n")] = '\0';
    strcpy(input.courseId, buf);

    fgets(buf, sizeof(buf), file);
    buf[strcspn(buf, "\n")] = '\0';
    strcpy(input.courseName, buf);

    fgets(buf, sizeof(buf), file);
    sscanf(buf, "%d", &input.itemNumber);
    
    int i = 1;
    while (i <= input.itemNumber) {
        fgets(buf, sizeof(buf), file);
        if (buf[0] == '\n' && (int) strlen(buf) == 1) 
            continue;
        input.itemList[i].isDeleted = 0;
        sscanf(buf, "%s %f %f %d", input.itemList[i].itemName, &input.itemList[i].fullMark, 
        &input.itemList[i].percentage, &input.itemList[i].gradesNumber); 
        if (input.itemList[i].gradesNumber > 0) {
            for (int j = 1; j <= input.itemList[i].gradesNumber; ++ j) {
                fgets(smallBuf, sizeof(smallBuf), file);
                smallBuf[strcspn(smallBuf, "\n")] = '\0';
                sscanf(smallBuf, "%f", &input.itemList[i].grades[j]);
            }
        }
        ++ i;
    }
    fclose(file);
    return input;
}

void writeAllCourse() {
    FILE *file = fopen("courseInfo", "w");
    if (file == NULL) {
        printf("Failed to open courseInfo\n");
        return;
    }

    fprintf(file, "%d\n", courseNumber);
    for (int i = 1; i <= courseNumber; ++ i) {
        fprintf(file, "%s\n", allCourse[i].courseId);
        writeCourse(allCourse[i]);
    }
    fclose(file);
}

void readAllCourse() {
    FILE *file = fopen("courseInfo", "r");
    if (file == NULL) {
        printf("Failed to open courseInfo\n");
        return;
    }

    char buf[205], courseID[55];
    fgets(buf, sizeof(buf), file);
    buf[strcspn(buf, "\n")] = '\0';
    courseNumber = 0;
    sscanf(buf, "%d", &courseNumber);

    for (int i = 1; i <= courseNumber; ++ i) {
        fgets(buf, sizeof(buf), file);
        buf[strcspn(buf, "\n")] = '\0';
        sscanf(buf, "%s", courseID);
        allCourse[i] = readCourse(courseID);
    }
    fclose(file);
}

void printCurrentRecorded() {
    readAllCourse();
    printf("There're totally %d courses recorded:", courseNumber);
    printf("\n\n");
    for (int i = 1; i <= courseNumber; ++ i) {
        printf("%d.\t%s\t%s\n", i, allCourse[i].courseId, allCourse[i].courseName);
    }
}

void printSpecificCourse(const int id) {
    printf("\t%s %s\n", allCourse[id].courseId, allCourse[id].courseName);
    printf("\t-----------------------------------\n");
    printf("\t|\t No.\t|\t Item\t|\t Percentage\t|\t Full Mark\t|\t Grades\n");
    for (int i = 1; i <= allCourse[id].itemNumber; ++ i) {
        item *it = &allCourse[id].itemList[i];
        printf("\t|\t %d\t|\t %s\t|\t %f\t|\t %f\t| ", i, it -> itemName, it -> percentage, it -> fullMark);
        if (it -> gradesNumber == 0) {
            putchar('\n');
            continue;
        }
        for (int j = 1; j <= it -> gradesNumber; ++ j) {
            printf("%d: %.2f  ", j, it -> grades[j]);
        }
        putchar('\n');
    }
    printf("\t-----------------------------------\n\n");
}

void printSpecificItem(const int courseID, const int itemID) {
    printf("\t%s %s\n", allCourse[courseID].courseId, allCourse[courseID].courseName);
    printf("\t-----------------------------------\n");
    item *it = &allCourse[courseID].itemList[itemID];
    printf("\t| %d\t| %s\t| %f\t| %f\t| ", 1, it -> itemName, it -> percentage, it -> fullMark);
    if (it -> gradesNumber != 0) {
        for (int j = 1; j <= it -> gradesNumber; ++ j) {
            printf("%d: %.2f  ", j, it -> grades[j]);
        }
    }
    putchar('\n');
    printf("\t-----------------------------------\n\n");
}