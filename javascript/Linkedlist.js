class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    insert(data) {
        const newNode = new Node(data);
        if (this.head === null) {
            this.head = newNode;
            return;
        }
        
        let current = this.head;
        while (current.next) {
            current = current.next;
        }
        current.next = newNode;
    }

    delete(data) {
        if (this.head === null) return;
        if (this.head.data === data) {
            this.head = this.head.next;
            return;
        }

        let current = this.head;
        while (current.next && current.next.data !== data) {
            current = current.next;
        }
        if (current.next) {
            current.next = current.next.next;
        }
    }
    display() {
        if (this.head === null) {
            console.log('List is empty.');
            return;
        }

        let current = this.head;
        let output = '';
        while (current) {
            output += `${current.data} -> `;
            current = current.next;
        }
        output += 'null';
        console.log(output);
    }
}

const list = new LinkedList();
list.insert(1);
list.insert(2);
list.insert(3);
list.display(); 

list.delete(2);
list.display(); 
