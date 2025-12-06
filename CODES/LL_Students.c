// Q: Create a linked list to store and print roll number, name and age of 3 students
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[50];
    int age;
    struct Student* next;
};

int main() {
    struct Student* n1;
    struct Student* n2;
    struct Student* n3;

    n1 = malloc(sizeof(*n1));
    n2 = malloc(sizeof(*n2));
    n3 = malloc(sizeof(*n3));

    n1->rollno = 1;
    strcpy(n1->name, "Arya");
    n1->age = 16;
    n1->next = n2;

    n2->rollno = 2;
    strcpy(n2->name, "Raju");
    n2->age = 15;
    n2->next = n3;

    n3->rollno = 3;
    strcpy(n3->name, "Diya");
    n3->age = 16;
    n3->next = NULL;

    struct Student* temp = n1;
    printf("The following are the student records:\n\n");

    while (temp != NULL) {
        printf("Roll no: %d\nName: %s\nAge: %d\n\n", temp->rollno, temp->name, temp->age);
        temp = temp->next;
    }

    return 0;
}
