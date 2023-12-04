#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataType.h"

void write(const course output) {
    char filename[55];
    strcpy(filename, output.courseId);
    FILE *file = fopen(filename, "w");
    if (file == NULL)
        return printf("Failed to open %s\n", filename), void();
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
        fprintf(file, "%s,%f,%f,%d\n", it.itemName, it.fullMark, it.percentage, it.gradesNumber);
        for (int j = 1; j <= it.gradesNumber; ++ j) {
            fprintf(file, "%f\n", it.grades[j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void read(const char *filename, course &input) {
    FILE *file = fopen(filename, "r");
    if (file == NULL)
        return printf("Failed to open %s\n", filename), void();
    char buf[205], smallBuf[25];
    /*
    Read info from buf area
    */   
    fgets(buf, sizeof(buf), file);
    strcpy(input.courseId, buf);
    fgets(buf, sizeof(buf), file);
    strcpy(input.courseName, buf);
    fgets(buf, sizeof(buf), file);
    sscanf(buf, "%d", &input.itemNumber);
    for (int i = 1; i <= input.itemNumber; ++ i) {
        input.itemList[i].isDeleted = 0;
        fgets(buf, sizeof(buf), file);
        item *it = &input.itemList[i];
        sscanf(buf, "%s,%f,%f,%d", it -> itemName, &(it -> fullMark), &(it -> percentage), & (it -> gradesNumber));
        if (it -> gradesNumber > 0) {
            for (int j = 1; j <= it -> gradesNumber; ++ j) {
                fgets(smallBuf, sizeof(smallBuf), file);
                sscanf(smallBuf, "%f", &(it -> grades[j]));
            }
        }
        /*sscanf(buf, "%s,%f,%f,%d", input.itemList[i].itemName, &input.itemList[i].fullMark, 
        &input.itemList[i].percentage, &input.itemList[i].gradesNumber); 
        if (input.itemList[i].gradesNumber > 0) {
            for (int j = 1; j <= input.itemList[i].gradesNumber; ++ j) {
                fgets(smallBuf, sizeof(smallBuf), file);
                sscanf(smallBuf, "%f", &input.itemList[i].grades[j]);
            }
        }
        */
    }
    fclose(file);
}