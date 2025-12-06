// Q: Create a doubly linked list of Aadhar numbers of 4 employees and insert the 5th Aadhar at 3rd position
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>

struct Employee {
    long long aadhar;
    struct Employee* prev;
    struct Employee* next;
};

int main() {
    struct Employee* e1 = malloc(sizeof(struct Employee));
    struct Employee* e2 = malloc(sizeof(struct Employee));
    struct Employee* e3 = malloc(sizeof(struct Employee));
    struct Employee* e4 = malloc(sizeof(struct Employee));
    struct Employee* e5 = malloc(sizeof(struct Employee));

    e1->aadhar = 111122223333;
    e1->prev = NULL;
    e1->next = e2;

    e2->aadhar = 222233334444;
    e2->prev = e1;
    e2->next = e3;

    e3->aadhar = 333344445555;
    e3->prev = e2;
    e3->next = e4;

    e4->aadhar = 444455556666;
    e4->prev = e3;
    e4->next = NULL;

    e5->aadhar = 555566667777;

    struct Employee* head = e1;

    e5->next = e3;
    e5->prev = e2;
    e2->next = e5;
    e3->prev = e5;

    struct Employee* temp = head;

    while (temp != NULL) {
        printf("%lld\n", temp->aadhar);
        temp = temp->next;
    }

    return 0;
}
