// Q: Menu-driven program to perform create, insert, delete, search-delete, and reverse operations on a circular linked list
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create(int data) {
    struct Node* newnode = malloc(sizeof(struct Node));
    newnode->data = data;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head) temp = temp->next;
    temp->next = newnode;
    newnode->next = head;
}

void insertAt(int data, int pos) {
    struct Node* newnode = malloc(sizeof(struct Node));
    newnode->data = data;

    if (pos == 1) {
        struct Node* temp = head;
        while (temp->next != head) temp = temp->next;
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) temp = temp->next;

    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteAt(int pos) {
    if (head == NULL) return;

    struct Node* temp = head;

    if (pos == 1) {
        while (temp->next != head) temp = temp->next;
        struct Node* del = head;
        head = head->next;
        temp->next = head;
        free(del);
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) temp = temp->next;

    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
}

void searchDelete(int key) {
    if (head == NULL) return;

    struct Node* temp = head;
    struct Node* prev = NULL;

    do {
        if (temp->data == key) {
            if (temp == head) {
                struct Node* last = head;
                while (last->next != head) last = last->next;
                head = head->next;
                last->next = head;
                free(temp);
                return;
            } else {
                prev->next = temp->next;
                free(temp);
                return;
            }
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);
}

void reverse() {
    if (head == NULL || head->next == head) return;

    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* nextnode;

    do {
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    } while (curr != head);

    head->next = prev;
    head = prev;
}

void display() {
    if (head == NULL) return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, data, pos;

    while (1) {
        printf("\nCircular Linked List Menu\n");
        printf("1. Create\n");
        printf("2. Insert at any position\n");
        printf("3. Delete from any position\n");
        printf("4. Search and delete\n");
        printf("5. Reverse\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            create(data);
            display();
            break;

        case 2:
            printf("Enter data and position: ");
            scanf("%d %d", &data, &pos);
            insertAt(data, pos);
            display();
            break;

        case 3:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteAt(pos);
            display();
            break;

        case 4:
            printf("Enter element to search and delete: ");
            scanf("%d", &data);
            searchDelete(data);
            display();
            break;

        case 5:
            reverse();
            display();
            break;

        case 6:
            return 0;
        }
    }
}
