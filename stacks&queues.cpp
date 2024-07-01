//Package Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a package
struct package {
    char description[100];
    struct package *next;
};

// Stack structure for processed packages
struct stack {
    struct package *top;
};

// Initialize the stack
void initStack(struct stack *s) {
    s->top = NULL;
}

// Push a package onto the stack
void push(struct stack *s, char *description) {
    struct package *newPackage = (struct package *)malloc(sizeof(struct package));
    strcpy(newPackage->description, description);
    newPackage->next = s->top;
    s->top = newPackage;
    printf("Package '%s' added to the processed packages stack.\n", description);
}

// Pop a package from the stack
void pop(struct stack *s) {
    if (s->top == NULL) {
        printf("No packages to process.\n");
        return;
    }
    struct package *temp = s->top;
    s->top = s->top->next;
    printf("Package '%s' processed.\n", temp->description);
    free(temp);
}

// Display all packages in the stack
void displayStack(struct stack *s) {
    struct package *current = s->top;
    if (current == NULL) {
        printf("No processed packages.\n");
        return;
    }
    printf("Processed packages:\n");
    while (current != NULL) {
        printf("- %s\n", current->description);
        current = current->next;
    }
}
// Queue structure for pending packages
struct queue {
    struct package *front;
    struct package *rear;
};

// Initialize the queue
void initQueue(struct queue *q) {
    q->front = q->rear = NULL;
}

// Enqueue a package into the queue
void enqueue(struct queue *q, char *description) {
    struct package *newPackage = (struct package *)malloc(sizeof(struct package));
    strcpy(newPackage->description, description);
    newPackage->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newPackage;
    } else {
        q->rear->next = newPackage;
        q->rear = newPackage;
    }
    printf("Package '%s' added to the pending packages queue.\n", description);
}

// Dequeue a package from the queue
void dequeue(struct queue *q) {
    if (q->front == NULL) {
        printf("No pending packages to remove.\n");
        return;
    }
    struct package *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    printf("Package '%s' removed from the pending packages queue.\n", temp->description);
    free(temp);
}

// Display all packages in the queue
void displayQueue(struct queue *q) {
    struct package *current = q->front;
    if (current == NULL) {
        printf("No pending packages.\n");
        return;
    }
    printf("Pending packages:\n");
    while (current != NULL) {
        printf("- %s\n", current->description);
        current = current->next;
    }
}
int main() {
    struct stack processedPackages;
    struct queue pendingPackages;
    int choice;
    char description[100];

    initStack(&processedPackages);
    initQueue(&pendingPackages);

    printf("Package Management System\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Package\n");
        printf("2. Process Package\n");
        printf("3. View Pending Packages\n");
        printf("4. View Processed Packages\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from the buffer

        switch (choice) {
            case 1:
                printf("Enter package description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline character
                enqueue(&pendingPackages, description);
                break;
            case 2:
                if (pendingPackages.front != NULL) {
                    strcpy(description, pendingPackages.front->description);
                    dequeue(&pendingPackages);
                    push(&processedPackages, description);
                } else {
                    printf("No pending packages to process.\n");
                }
                break;
            case 3:
                displayQueue(&pendingPackages);
                break;
            case 4:
                displayStack(&processedPackages);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

