
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *last = NULL;

// Insert at beginning
void insertBeginning()
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;

    if (last == NULL)
    {
        last = newnode;
        newnode->next = newnode;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
    }

    printf("Node inserted at beginning.\n");
}

// Insert at end
void insertEnd()
{
    struct node *newnode;
    int value;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;

    if (last == NULL)
    {
        last = newnode;
        newnode->next = newnode;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
        last = newnode;
    }

    printf("Node inserted at end.\n");
}

// Insert at middle using position
void insertMiddle()
{
    struct node *newnode, *temp;
    int value, pos, i;

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

    if (last == NULL)
    {
        printf("List is empty. Insert at position 1 first.\n");
        return;
    }

    temp = last->next;

    for (i = 1; i < pos - 1 && temp != last; i++)
    {
        temp = temp->next;
    }

    if (i != pos - 1)
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
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = temp->next;
    temp->next = newnode;

    if (temp == last)
        last = newnode;

    printf("Node inserted successfully.\n");
}

// Delete from beginning
void deleteBeginning()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    if (temp == last)
        last = NULL;
    else
        last->next = temp->next;

    free(temp);

    printf("First node deleted.\n");
}

// Delete from end
void deleteEnd()
{
    struct node *temp, *prev;

    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    if (temp == last)
    {
        free(last);
        last = NULL;
    }
    else
    {
        while (temp != last)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = last->next;
        free(last);
        last = prev;
    }

    printf("Last node deleted.\n");
}

// Delete from middle using position
void deleteMiddle()
{
    struct node *temp, *prev;
    int pos, i;

    if (last == NULL)
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

    if (pos == 1)
    {
        deleteBeginning();
        return;
    }

    temp = last->next;

    for (i = 1; i < pos && temp != last; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (i != pos)
    {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;

    if (temp == last)
        last = prev;

    free(temp);

    printf("Node deleted successfully.\n");
}

// Display circular linked list
void display()
{
    struct node *temp;

    if (last == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = last->next;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to first node)\n");
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n--- Circular Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Middle/Position\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from Middle/Position\n");
        printf("6. Delete from End\n");
        printf("7. Display\n");
        printf("8. Exit\n");

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
                display();
                break;

            case 8:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 8);

    return 0;
}