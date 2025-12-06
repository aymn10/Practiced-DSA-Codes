// Q: Create a linked list storing heights of 10 students and delete from middle, beginning, and end
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int height;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* temp;
    struct Node* newnode;

    for (int i = 1; i <= 10; i++) {
        newnode = malloc(sizeof(struct Node));
        newnode->height = i * 10;
        newnode->next = head;
        head = newnode;
    }

    temp = head;
    for (int i = 1; i < 5; i++) temp = temp->next;
    struct Node* mid = temp->next;
    temp->next = mid->next;
    free(mid);

    temp = head;
    head = head->next;
    free(temp);

    temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    struct Node* last = temp->next;
    temp->next = NULL;
    free(last);

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->height);
        temp = temp->next;
    }

    return 0;
}
