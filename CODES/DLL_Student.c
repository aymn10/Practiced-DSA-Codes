// Q: Create a doubly linked list to store and print roll number, name and age of 3 students
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    int age;
    struct Student* prev;
    struct Student* next;
};

int main() {
    struct Student* n1 = malloc(sizeof(struct Student));
    struct Student* n2 = malloc(sizeof(struct Student));
    struct Student* n3 = malloc(sizeof(struct Student));

    n1->roll = 1;
    strcpy(n1->name, "Arya");
    n1->age = 16;
    n1->prev = NULL;
    n1->next = n2;

    n2->roll = 2;
    strcpy(n2->name, "Raju");
    n2->age = 15;
    n2->prev = n1;
    n2->next = n3;

    n3->roll = 3;
    strcpy(n3->name, "Diya");
    n3->age = 16;
    n3->prev = n2;
    n3->next = NULL;

    struct Student* temp = n1;

    while (temp != NULL) {
        printf("Roll: %d  Name: %s  Age: %d\n", temp->roll, temp->name, temp->age);
        temp = temp->next;
    }

    return 0;
}
