#include <stdio.h>
#include <stdlib.h>

//Node struct
struct Node{
    int val;
    struct Node* next;
    struct Node* prev;
};

//Make new node
struct Node* newNode(int data){
    struct Node *nNode = (struct Node *)malloc(sizeof(struct Node));
    nNode->val = data;
    nNode->next = NULL;
}

//Add node to end of list
void addNode(struct Node** head, int val){
    struct Node* nNode = newNode(val);
    if(*head == NULL){
        *head = nNode;
    } else {
        struct Node* current = *head;
        while(current->next != NULL){
            current = current ->next;
        }
        current->next = nNode;
        nNode->prev = current;
    }
}

//Remove node at a given index
void removeNodeAtIndex(struct Node** head, int index) {
    if (*head == NULL || index < 0) {
        return;
    }

    struct Node* current = *head;
    int i = 0;

    while (i < index && current != NULL) {
        current = current->next;
        i++;
    }
    if (current == NULL) {
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
}

//Print list
void printList(struct Node* head){
    struct Node* current = head;
    int index = 0;
    while(current != NULL){
        printf("[%d] = %d\n", index, current->val);
        index++;
        current = current->next;
    }
}

int main(){
    struct Node *head = NULL;
    int choice, val, index;
    while(1){
        printf("\nOptions");
        printf("\n1 - Add node to list");
        printf("\n2 - Remove node from list");
        printf("\n3 - Print list");
        printf("\n4 - Exit");
        printf("\nEnter option: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter a value to add: ");
                scanf("%d", &val);
                addNode(&head, val);
                break;
            case 2:
                printf("Enter an index to remove: ");
                scanf("%d", &val);
                removeNodeAtIndex(&head, val);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}