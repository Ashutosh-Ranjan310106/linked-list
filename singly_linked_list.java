class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class linked_list {
    Node head;

    linked_list() {
        this.head = null;
    }

    void insert_at_beginning(int data) {
        Node new_node = new Node(data);
        if (this.head == null) {
            this.head = new_node;
        } else {
            new_node.next = this.head;
            this.head = new_node;
        }
    }

    void insert_in_between(int data, int key) {
        Node new_node = new Node(data);
        if (this.head == null) {
            this.head = new_node;
            return;
        }
        Node temp = this.head;
        while (temp != null) {
            if (temp.data == key) {
                new_node.next = temp.next;
                temp.next = new_node;
                return;
            }
            temp = temp.next;
        }
    }

    void insert_at_end(int data) {
        Node new_node = new Node(data);
        if (this.head == null) {
            this.head = new_node;
            return;
        }
        Node temp = this.head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = new_node;
    }

    void delete_node(int key) {
        Node prev = null;
        Node temp = this.head;
        if (temp != null && temp.data == key) {
            this.head = temp.next;
            return;
        }
        while (temp != null && temp.data != key) {
            prev = temp;
            temp = temp.next;
        }
        if (temp == null) {
            return; // Key not found
        }
        prev.next = temp.next;
    }

    void print_linked_list() {
        Node temp = this.head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}

class Main {
    public static void main(String[] args) {
        linked_list list = new linked_list();
        list.insert_at_beginning(20);
        list.insert_at_beginning(25);
        list.insert_in_between(56, 20);
        list.insert_at_end(45);

        list.print_linked_list();
    }
}
