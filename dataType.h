#ifndef DATATYPE_H
#define DATATYPE_H

/*
The program has to store two things
One is "course", "course" has a lot of "item"s, so when dealing with "grades", it is actually dealing with the grades of an "item" in each "course".
On top of clarifying the above, we now define the structure we want to use.
*/

typedef struct  {
    int isDeleted;
    char itemName[55]; // The name of the "item", stored as an array of characters.
    float percentage, fullMark; // The percentage and full score of the "item", both of which are of type float.
    int gradesNumber; // The number of how many grades were entered in total.
    float grades[55]; // Stores all grades entered.
} item;

typedef struct  {
    int isDeleted;
    char courseName[55], courseId[15]; // The name of the "course", and the ID of the "course". are character arrays.
    int itemNumber; // The number of how many "item"s were entered in total.
    item itemList[15]; // Stores all "item"s entered.
} course;

#endif