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

    insert_at_beginning(data) {
        const new_node  = new Node(data);
        if (this.head === null) {
            this.head = new_node ;
        } else {
            new_node.next = this.head;
            this.head = new_node ;
        }
    }

    insert_in_between(data, key) {
        const new_node  = new Node(data);
        let temp = this.head;
        if (this.head === null) {
            this.head = new_node ;
            return;
        }
        while (temp !== null) {
            if (temp.data === key) {
                new_node .next = temp.next;
                temp.next = new_node ;
                return;
            }
            temp = temp.next;
        }
        return -1;
    }

    insert_at_end(data) {
        const new_node  = new Node(data);
        if (this.head === null) {
            this.head = new_node ;
            return;
        }
        let temp = this.head;
        while (temp.next !== null) {
            temp = temp.next;
        }
        temp.next = new_node ;
    }

    delete_node(key) {
        let prev = null;
        let temp = this.head;
        if (temp !== null && temp.data === key) {
            this.head = temp.next;
            return;
        }
        while (temp.next !== null) {
            if (temp.data === key) {
                break;
            }
            prev = temp;
            temp = temp.next;
        }
        if (temp.next === null) {
            if (temp.data === key) {
                prev.next = null;
                return;
            }
            return -1;
        }
        prev.next = temp.next;
    }

    print_linked_list() {
        let temp = this.head;
        while (temp !== null) {
            console.log(temp.data + " ");
            temp = temp.next;
        }
        console.log();
    }
}

const linkedList = new LinkedList();
linkedList.insert_at_beginning(20);
linkedList.insert_at_beginning(25);
linkedList.insert_at_end(45);
linkedList.insert_in_between(67, 20);
linkedList.delete_node(20);
linkedList.print_linked_list();
