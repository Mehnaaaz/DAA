#include <stdio.h>
#include <stdlib.h>

// Define a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
struct Node* insertNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to remove duplicates from a sorted linked list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);  // Free memory for the duplicate node
        } else {
            current = current->next;
        }
    }
}

int main() {
    struct Node* list = NULL;

    // Insert elements into the sorted linked list
    list = insertNode(list, 1);
    list = insertNode(list, 2);
    list = insertNode(list, 2);
    list = insertNode(list, 3);
    list = insertNode(list, 3);
    list = insertNode(list, 4);

    printf("Original List: ");
    printList(list);

    // Remove duplicates
    removeDuplicates(list);

    printf("List After Removing Duplicates: ");
    printList(list);

    return 0;
}
