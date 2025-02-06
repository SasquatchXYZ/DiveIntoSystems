#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data; // used to store a list element's data value
    struct node* next; // used to point to the next node in the list
};

int main()
{
    struct node *head, *temp;
    int i;

    head = NULL; // and empty linked list

    head = malloc(sizeof(struct node)); // allocate memory for the first node
    if (head == NULL)
    {
        printf("Error allocating memory\n");
        exit(1);
    }
    head->data = 10; // set the data field
    head->next = NULL; // set next to NULL (there is no element)

    // add 2 more nodes to the head of the list:
    for (i = 0; i < 2; i++)
    {
        temp = malloc(sizeof(struct node)); // allocate a node
        if (temp == NULL)
        {
            printf("Error allocating memory\n");
            exit(1);
        }
        temp->data = i; // set the data field
        temp->next = head; // set next to point to the current first node
        head = temp; // change head to point to the newly added node
    }

    return 0;
}
