/* By Joshua Pomeroy
 * Program demonstrating a linked list
 * Requires at least 1 argument at command line
 * Takes the given arguments and adds them to a linked list
 * Removes duplicate values
 * Inserts upper case words at the front of the list
 * Inserts lower case words at the back of the list
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// node structure, contains a pointer to a char and a pointer to another node
typedef struct node{
    char* data;
    struct node* next;
} Node;

// Linkedlist structure, contains a pointer to a node named head
typedef struct Linkedlist{
    struct node* head;
} Linked_List;

// Function prototypes
void insertAtBeginning(Linked_List* LL, char ele[]);
void insertAtTheEnd(Linked_List* LL, char ele[]);
void deleteNode(Linked_List* LL, char ele[]); 
int findNode(Linked_List LL, char ele[]);
void displayLinkedList(Linked_List LL);
void freeLinkedList(Node* head);

/* Main function
 * Confirms that there is at least 1 argument given on the command line
 * Creates the initial linked list and initializes it.
 * Runs the loop to populate the linked list correctly.
*/
int main(int argc, char **argv){
    if (argc == 1){
        printf("ERROR: The program must read at least an argument.\n");
        exit(1);
    }

    Linked_List LL;
    Node* head = NULL;
    LL.head = head;
    LL.head = (Node*) malloc(sizeof(Node));
    if (LL.head == NULL) {
        return EXIT_FAILURE;
    } 
    LL.head->data = NULL;
    LL.head->next = NULL;

    for (int i = 1; i <= argc-1; i++){
        if (findNode(LL, argv[i])){
            deleteNode(&LL, argv[i]);
        } else{
            if (isupper(argv[i][0])){
                insertAtBeginning(&LL, argv[i]);
            } else{
                insertAtTheEnd(&LL, argv[i]);
            }
        }
    }
    
    displayLinkedList(LL);
    freeLinkedList(LL.head);
    return EXIT_SUCCESS;
}

// Function to insert a passed string at the beginning of a passed linked list
void insertAtBeginning(Linked_List* LL, char ele[]) {
    if (!(LL->head->data)){
        LL->head->data = ele;
    } else{
        Node* new_node;
        new_node = (Node*) malloc(sizeof(Node));

        new_node->data = ele;
        new_node->next = LL->head;
        LL->head = new_node;
    }
}

// Function to insert a passed string at the end of a passed linked list
void insertAtTheEnd(Linked_List* LL, char ele[]) {
    if (!(LL->head->data)){
        LL->head->data = ele;
    } else{
        Node* current = LL->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (Node*) malloc(sizeof(Node));
    current->next->data = ele;
    current->next->next = NULL;
    }
}

// Function to delete and free a node with the passed value within a passed linked list
void deleteNode(Linked_List* LL, char ele[]){
    // Set next and data of head to NULL if head is the only item
    if (!strcmp(LL->head->data, ele)){
        LL->head->data = NULL;
        LL->head->next = NULL;
        return;
    }

    // If there is only two items compare the second item with ele
    if (!LL->head->next->next){
        if(!strcmp(LL->head->next->data, ele)){
            LL->head->next = NULL;
            free(LL->head->next);
        }
    } else{
        Node* current = LL->head;
        while (current->next != NULL){
            if (!strcmp(current->next->data, ele)){
                Node* temp = current->next->next;
                free(current->next);
                current->next = temp;
                break;
            }
            current = current->next;
        }
    }
}

// Function to find the passed string in the passed linked list, returns 1 if found and 0 if not found
int findNode(Linked_List LL, char ele[]){
    Node* current = LL.head;

    while(current->next != NULL){
        if (!strcmp(current->data, ele)){
            return 1;
        }
        current = current->next;
    }
    if (current->data && !strcmp(current->data, ele)){
        return 1;
    }
    return 0;
}

// Function to print out the linked list as a comma seperated list
void displayLinkedList(Linked_List LL) {
    Node* current;

    // If the list is empty
    if (!(LL.head->data)){
        printf("The list:- \n");
        return;
    } else{
        current = LL.head;
    }
    
    printf("The list:- ");
    while (current->next != NULL) {
        printf("%s, ", current->data);
        current = current->next;
    }
    printf("%s\n", current->data);
}

// Function to fully free the linked list at the end of usage
void freeLinkedList(Node* head){
    if (head->next == NULL){
        free(head);
        return;
    }
    freeLinkedList(head->next);
    free(head);
}