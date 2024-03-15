class Node {
    constructor(data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    insert_at_beginning(data) {
        const new_node = new Node(data);
        if (this.head === null) {
            this.head = new_node;
            return;
        }
        new_node.next = this.head;
        this.head.prev = new_node;
        this.head = new_node;
    }

    insert_in_between(data, key) {
        const new_node = new Node(data);
        let temp = this.head;
        if (this.head === null) {
            this.head = new_node;
            return;
        }
        while (temp !== null) {
            if (temp.data === key) {
                new_node.next = temp.next;
                temp.next = new_node;
                new_node.prev = temp;
                if (new_node.next !== null) {
                    new_node.next.prev = new_node;
                }
                return;
            }
            temp = temp.next;
        }
        return -1;
    }

    insert_at_end(data) {
        const new_node = new Node(data);
        if (this.head === null) {
            this.head = new_node;
            return;
        }
        let temp = this.head;
        while (temp.next !== null) {
            temp = temp.next;
        }
        temp.next = new_node;
        new_node.prev = temp;
    }

    delete_node(key) {
        let temp = this.head;
        if (temp !== null && temp.data === key) {
            this.head = temp.next;
            if (this.head !== null) {
                this.head.prev = null;
            }
            return;
        }
        while (temp !== null && temp.data !== key) {
            temp = temp.next;
        }
        if (temp === null) {
            return; // Key not found
        }
        if (temp.next !== null) {
            temp.next.prev = temp.prev;
        }
        if (temp.prev !== null) {
            temp.prev.next = temp.next;
        }
    }

    print_linked_list() {
        let temp = this.head;
        while (temp !== null) {
            process.stdout.write(temp.data + " ");
            temp = temp.next;
        }
        console.log();
    }

    print_in_reverse() {
        let temp = this.head;
        while (temp !== null && temp.next !== null) {
            temp = temp.next;
        }
        while (temp !== null) {
            process.stdout.write(temp.data + " ");
            temp = temp.prev;
        }
        console.log();
    }
}

// Example usage:

const linkedList = new LinkedList();
linkedList.insert_at_beginning(20);
linkedList.insert_at_beginning(25);
linkedList.insert_at_end(45);
linkedList.insert_in_between(67, 20);
linkedList.delete_node(20);
linkedList.print_linked_list();
linkedList.print_in_reverse();
