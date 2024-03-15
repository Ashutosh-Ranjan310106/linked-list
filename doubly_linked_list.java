class Node {
    int data;
    Node prev;
    Node next;

    public Node(int data) {
        this.data = data;
        this.prev = null;
        this.next = null;
    }
}

class DoublyLinkedList {
    Node head;

    public void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            newNode.next = head;
            head.prev = newNode;
            head = newNode;
        }
    }

    public void insertInBetween(int data, int key) {
        Node newNode = new Node(data);
        Node temp = head;
        while (temp != null) {
            if (temp.data == key) {
                newNode.next = temp.next;
                if (temp.next != null) {
                    temp.next.prev = newNode;
                }
                temp.next = newNode;
                newNode.prev = temp;
                break;
            }
            temp = temp.next;
        }
    }

    public void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.prev = temp;
        }
    }

    public void deleteNode(int key) {
        Node temp = head;
        if (temp != null && temp.data == key) {
            head = temp.next;
            if (head != null) {
                head.prev = null;
            }
            return;
        }
        while (temp != null && temp.data != key) {
            temp = temp.next;
        }
        if (temp == null) {
            return; // Key not found
        }
        if (temp.next != null) {
            temp.next.prev = temp.prev;
        }
        if (temp.prev != null) {
            temp.prev.next = temp.next;
        }
    }

    public void printLinkedList() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public void printInReverse() {
        Node temp = head;
        while (temp != null && temp.next != null) {
            temp = temp.next;
        }
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.prev;
        }
        System.out.println();
    }
}

class Main {
    public static void main(String[] args) {
        DoublyLinkedList list = new DoublyLinkedList();
        list.insertAtBeginning(20);
        list.insertAtBeginning(25);
        list.insertAtEnd(45);
        list.insertAtEnd(67);
        list.insertInBetween(68, 25);
        list.printLinkedList();
        System.out.println("After deleting 20:");
        list.deleteNode(20);
        list.printLinkedList();
        System.out.println("In reverse:");
        list.printInReverse();
    }
}
