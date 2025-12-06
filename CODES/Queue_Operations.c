// Q: Implement a queue with enqueue, dequeue, peek, and display operations
// Time Complexity: O(1) for all operations
// Space Complexity: O(n)

#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int v) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

int peek() {
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
        return -1;
    }
    return queue[front];
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int ch, val;

    while (1) {
        printf("\nQueue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                val = dequeue();
                if (val != -1) printf("Dequeued: %d\n", val);
                break;

            case 3:
                val = peek();
                if (val != -1) printf("Front: %d\n", val);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;
        }
    }
}
