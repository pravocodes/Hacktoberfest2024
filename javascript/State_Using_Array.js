class Stack {
    constructor(capacity) {
        if (capacity <= 0) {
            throw new Error("Capacity must be greater than zero.");
        }
        this.capacity = capacity;
        this.stack = [];
        this.top = -1;
    }

    push(value) {
        if (this.isFull()) {
            console.error(`Error: Stack is full. Cannot push ${value}.`);
            return;
        }
        this.stack[++this.top] = value;
    }

    pop() {
        if (this.isEmpty()) {
            console.error("Error: Stack is empty. Cannot pop.");
            return;
        }
        this.top--;
    }

    peek() {
        if (this.isEmpty()) {
            console.warn("Warning: Stack is empty. Returning -1 as a placeholder.");
            return -1; // Placeholder for error condition
        }
        return this.stack[this.top];
    }

    isFull() {
        return this.top === this.capacity - 1;
    }

    isEmpty() {
        return this.top === -1;
    }

    getCapacity() {
        return this.capacity;
    }

    getSize() {
        return this.top + 1;
    }
}

try {
    const stack = new Stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);

    console.log("Top element is:", stack.peek());

    stack.pop();
    console.log("Top element after pop is:", stack.peek());

    stack.pop();
    stack.pop();
    stack.pop(); // This will trigger an error message

} catch (error) {
    console.error("Exception:", error.message);
}
