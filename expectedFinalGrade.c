#include <stdio.h>
#include <string.h>
#include "dataType.h"
#include "io.h"
#include "startUp.h"
#include "expectedFinalGrade.h"

float calculateItemScore(item t) {
    if (t.gradesNumber <= 0)
        return 0.00;
    float itemSum = 0.00;
    for (int i = 1; i <= t.gradesNumber; ++ i) 
        itemSum += t.grades[i];
    itemSum = itemSum * t.percentage / t.fullMark / (double) t.gradesNumber;
    return itemSum;
}

void viewAllCourses() {
    char buf[205];
    char Final[] = "Final";

    printf("Enter an expected course total([0, 100]) or any negative back: ");
    float exp = -1.00;
    fflush(stdin);
    fgets(buf, sizeof(buf), stdin);
    buf[strcspn(buf, "\n")] = '\0';
    sscanf(buf, "%f", &exp);
    printf("\n\n");

    if (exp < 0.00) return;
    
    printf("|\t(*)Danger\t|\tCourse Code\t|\tCourse Name\t|\tLowest Final for Expected Course Total\t|\n");
    for (int t = 1; t <= courseNumber; ++ t) {
        if (allCourse[t].isDeleted) continue;
        float sumScore = 0.00;
        item final = {0};
        for (int i = 1; i <= allCourse[t].itemNumber; ++ i) {
            item *it = &allCourse[t].itemList[i];
            if (it -> isDeleted) continue;
            if (!strcmp(it -> itemName, Final)) {
                final = *it;
                continue;
            }
            // float tmp = calculateItemScore(*it);
            // printf("i:%d calc:%.2f\n", i, tmp);
            // sumScore += tmp;
            sumScore += calculateItemScore(*it);
        }
        // printf("sumScore:%.2f\n", sumScore);
        float ret = exp - sumScore;
        float score = ret * final.fullMark / final.percentage;
        if (score > 100.0) {
            printf("|\t*\t|\t%s\t|\t%s\t|\t%.2f\t|\n", allCourse[t].courseId, allCourse[t].courseName, score);
        }
        else 
            printf("|\t\t|\t%s\t|\t%s\t|\t%.2f\t|\n", allCourse[t].courseId, allCourse[t].courseName, score);
    }
}

void expectedFinalGradeMenu() {
    int opt = -1;
    readAllCourse(allCourse);
    while (opt = startExpectedFinalGradeMenu()) {
        if (opt == 1) viewAllCourses();
        if (opt == 3) break;
    }
    // writeAllCourse(allCourse, courseNumber);
}