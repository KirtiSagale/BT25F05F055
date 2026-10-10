
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Insert at beginning
void insertBeginning()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;

    printf("Node inserted at beginning.\n");
}

// Insert at end
void insertEnd()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Node inserted at end.\n");
}

// Insert at a given position
void insertMiddle()
{
    struct node *newnode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        insertBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;

    printf("Node inserted successfully.\n");
}

// Delete from beginning
void deleteBeginning()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);

    printf("First node deleted.\n");
}

// Delete from end
void deleteEnd()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev == NULL)
        head = NULL;
    else
        temp->prev->next = NULL;

    free(temp);

    printf("Last node deleted.\n");
}

// Delete from a given position
void deleteMiddle()
{
    struct node *temp;
    int pos, i;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position.\n");
        return;
    }

    temp = head;

    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Node deleted successfully.\n");
}

// Display in forward direction
void displayForward()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Forward List: NULL <-> ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Display in backward direction
void displayBackward()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward List: NULL <-> ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Middle/Position\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from Middle/Position\n");
        printf("6. Delete from End\n");
        printf("7. Display Forward\n");
        printf("8. Display Backward\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertMiddle();
                break;

            case 3:
                insertEnd();
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteMiddle();
                break;

            case 6:
                deleteEnd();
                break;

            case 7:
                displayForward();
                break;

            case 8:
                displayBackward();
                break;

            case 9:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 9);

    return 0;
}
