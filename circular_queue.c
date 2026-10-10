```c
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Insertion operation
void enqueue()
{
    int value;

    if ((rear + 1) % SIZE == front)
    {
        printf("Circular Queue is Full!\n");
    }
    else
    {
        printf("Enter value to insert: ");
        scanf("%d", &value);

        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % SIZE;
        queue[rear] = value;

        printf("%d inserted successfully.\n", value);
    }
}

// Deletion operation
void dequeue()
{
    if (front == -1)
    {
        printf("Circular Queue is Empty!\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

// Display operation
void display()
{
    int i;

    if (front == -1)
    {
        printf("Circular Queue is Empty!\n");
    }
    else
    {
        printf("Circular Queue elements: ");

        i = front;

        while (1)
        {
            printf("%d ", queue[i]);

            if (i == rear)
            {
                break;
            }

            i = (i + 1) % SIZE;
        }

        printf("\n");
    }
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insertion (Enqueue)\n");
        printf("2. Deletion (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program terminated.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
```
