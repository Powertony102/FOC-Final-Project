#include "dataType.h"

extern int courseNumber;
extern course allCourse[105];

void writeCourse(const course output);
course readCourse(const char *filename);
void writeAllCourse();
int readAllCourse();
void printCurrentRecorded();
void printSpecificCourse(const int id);
void printSpecificItem(const int cpurseID, const int itemID);