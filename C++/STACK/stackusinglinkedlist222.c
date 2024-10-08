#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
struct Node {
    int data;
    struct Node* next;
};

// Function 1: Push (insert element into the stack)
void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow (Not enough memory)\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d to stack\n", data);
}

// Function 2: Pop (remove the top element from the stack)
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow (Stack is empty)\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedData = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedData;
}

// Function 3: Peek (return the top element without removing it)
int peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Function 4: Check if stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Function 5: Check if stack is full (based on available memory)
int isFull() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        return 1; // Stack is full if no memory is available
    }
    free(temp);
    return 0; // Stack is not full
}

// Function 6: Display all elements in the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function 7: Size of the stack
int size(struct Node* top) {
    int count = 0;
    struct Node* temp = top;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Main function to test the stack implementation
int main() {
    struct Node* stack = NULL; // Stack is initially empty

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(stack); // Show current stack elements

    printf("Top element is: %d\n", peek(stack));
    printf("Popped element: %d\n", pop(&stack));
    display(stack); // Show stack after popping one element

    printf("Stack is %s\n", isEmpty(stack) ? "empty" : "not empty");

    printf("Current size of stack: %d\n", size(stack));

    printf("Stack is %sfull\n", isFull() ? "" : "not ");

    return 0;
}
