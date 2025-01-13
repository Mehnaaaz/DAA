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

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct Node* result;

    if (list1->data <= list2->data) {
        result = list1;
        result->next = mergeSortedLists(list1->next, list2);
    } else {
        result = list2;
        result->next = mergeSortedLists(list1, list2->next);
    }

    return result;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Insert elements into the first sorted list
    list1 = insertNode(list1, 1);
    list1 = insertNode(list1, 3);
    list1 = insertNode(list1, 5);

    // Insert elements into the second sorted list
    list2 = insertNode(list2, 2);
    list2 = insertNode(list2, 4);
    list2 = insertNode(list2, 6);

    // Display the lists
    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Merge the sorted lists
    struct Node* mergedList = mergeSortedLists(list1, list2);
    printf("Merged List: ");
    printList(mergedList);

    // Free allocated memory (optional but recommended)
    struct Node* temp;
    while (mergedList != NULL) {
        temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }

    return 0;
}
