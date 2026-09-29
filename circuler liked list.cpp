#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* append(struct Node* head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (head == NULL) {
        new_node->next = new_node;
        return new_node;
    }

    struct Node* current = head;
    while (current->next != head) {
        current = current->next;
    }

    current->next = new_node;
    new_node->next = head;

    return head;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("(Back to Head)\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("enter number of node ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("enter data of node  %d: ", i + 1);
        scanf("%d", &value);
        head = append(head, value);
    }

    printf("\nYour Circular Linked List:\n");
    display(head);

    return 0;
}
