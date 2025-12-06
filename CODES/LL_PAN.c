// Q: Create a linked list of PAN numbers of 4 employees and insert the 5th employee PAN at the beginning
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>

struct Employee {
    long long pan;
    struct Employee* next;
};

int main() {
    struct Employee* e1 = malloc(sizeof(struct Employee));
    struct Employee* e2 = malloc(sizeof(struct Employee));
    struct Employee* e3 = malloc(sizeof(struct Employee));
    struct Employee* e4 = malloc(sizeof(struct Employee));
    struct Employee* e5 = malloc(sizeof(struct Employee));

    e1->pan = 1234567891;
    e1->next = e2;

    e2->pan = 2234567891;
    e2->next = e3;

    e3->pan = 3234567891;
    e3->next = e4;

    e4->pan = 4234567891;
    e4->next = NULL;

    e5->pan = 5234567891;
    e5->next = e1;

    struct Employee* head = e5;

    struct Employee* temp = head;
    printf("Employee PAN list:\n\n");

    while (temp != NULL) {
        printf("%lld\n", temp->pan);
        temp = temp->next;
    }

    return 0;
}
