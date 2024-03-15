#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* create_node(int data){
    struct Node* node=new Node;
    
    node->data=data;
    node->prev=NULL;
    node->next=NULL;
    return node;
}
class linked_list{   
    public:
        Node** create_linked_list(){
            struct Node** head = new Node*;
            *head = nullptr;
            return head;
        }

        int insert_at_beginng(struct Node** head, int data){
            struct Node* new_node=create_node(data);
            
            if (*head==nullptr){
                *head=new_node;
            }else{
                new_node->next=*head;
                (*head)->prev=new_node;
                *head=new_node;
            }
            return 0;
        }
        int insert_in_between(struct Node** head, int data,int key){
            struct Node* new_node=create_node(data);
            struct Node* temp=*head;
            while(temp!=NULL){
                 if (temp->data == key) {
                    new_node->next = temp->next;
                    if (temp->next != nullptr) {
                        temp->next->prev = new_node;
                    }
                    temp->next = new_node;
                    new_node->prev = temp;
                    break;
                }
                temp=temp->next;
            }
            if (temp->next==NULL){
                return -1;
            }
            return 0;
        }
        int insert_at_end(struct Node** head,int data){
            struct Node* new_node = create_node(data);
            if (*head==nullptr){
                *head= new_node;
            }else{
                struct Node* temp=*head;
                while(temp->next!=nullptr){
                    temp=temp->next;
                }
                temp->next= new_node;
                new_node->prev=temp;
            }
            return 0;
        }


        int delete_node(struct Node** head, int key){
            struct Node* temp=*head;
            if (temp!=NULL && temp->data==key){
                *head=temp->next;
                if (temp->next!=NULL){
                    temp->next->prev=nullptr;
                }
                delete  temp;
                return 0;
            }
            while(temp->next!=nullptr){
                if (temp->data==key){
                    break;
                }
                temp=temp->next;
            }
            if (temp->next==nullptr){
                if (temp->data==key){  //to deleate last element if key was at last
                    temp->prev->next=nullptr;
                    delete  temp;
                    return 0;
                }
                return -1;
            }
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete  temp;
            return 0;
        }
        int print_linked_list(struct Node** head){
            struct Node* temp;
            temp = *head;
            while(temp != nullptr){
                cout<< temp->data<< " ";
                temp = temp->next;
            }
            cout<<endl;
            return 0;
        }
        int print_in_reverse(Node** head) {
            Node* temp = *head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->prev;
            }
            cout << endl;
            return 0;
        }

};
int main(){
    linked_list list_object;
    struct Node** head=list_object.create_linked_list();
    list_object.insert_at_beginng(head,20);
    list_object.insert_at_beginng(head,5);
    list_object.insert_at_end(head,45);
    list_object.insert_in_between(head,23,20);
    list_object.print_linked_list(head);
    list_object.print_in_reverse(head);
    
}


