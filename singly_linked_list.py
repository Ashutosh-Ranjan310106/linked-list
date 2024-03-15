class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    def insert_at_beginning(self, data):
        new_node=Node(data)
        if self.head is None:
            self.head = new_node
            return 0
        new_node.next = self.head
        self.head = new_node
        return 0
    def insert_in_between(self,data,key):
        new_node=Node(data)
        temp = self.head
        if self.head is None:
            self.head = new_node
            return 0
        while temp is not None:
            if temp.data==key:
                new_node.next=temp.next
                temp.next=new_node
                return 0
            temp = temp.next
        return -1
    
    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return 0
        temp = self.head
        while temp.next is not None:
            temp = temp.next
        temp.next = new_node
        return -1
    def delete_node(self,key):     
        prev=None;
        temp=self.head;
        if temp is not None and temp.data==key:
            self.head=temp.next;
            del temp
            return 0;
        while temp.next!=None:
            if temp.data==key:
                break;
            prev=temp;
            temp=temp.next;
        if (temp.next is None):
            if (temp.data==key): # to deleate last element if key was at last
                prev.next=None;
                del temp
                return 0;
            
            return -1;
        prev.next=temp.next;
        del temp;
        return 0;
    def print_linked_list(self):
        temp = self.head
        while temp is not None:
            print(temp.data, end=" ")
            temp = temp.next
        print()

# Example usage:

linked_list = LinkedList()
linked_list.insert_at_beginning(20)
linked_list.insert_at_beginning(25)
linked_list.insert_at_end(45)
linked_list.insert_in_between(67,20)
linked_list.delete_node(20)
linked_list.print_linked_list()

