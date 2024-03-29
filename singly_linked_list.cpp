#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* create_node(int data){
    struct Node* node=new Node;
    
    node->data=data;
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
                *head=new_node;
            }
            return 0;
        }
        int insert_in_between(struct Node** head, int data,int key){
            struct Node* new_node=create_node(data);
            
            if (*head==NULL){
                *head=new_node;
                return 0;
            }
            struct Node* temp=*head;
            while(temp!=NULL){
                if (temp->data==key){
                    new_node->next=temp->next;
                    temp->next=new_node;
                    return 0;
                }
                temp=temp->next;
            }
                return -1;
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
            }
            return 0;
        }


        int delete_node(struct Node** head, int key){
            struct Node* prev=nullptr;
            struct Node* temp=*head;
            if (temp!=NULL && temp->data==key){
                *head=temp->next;
                delete  temp;
                return 0;
            }
            while(temp->next!=nullptr){
                if (temp->data==key){
                    break;
                }
                prev=temp;
                temp=temp->next;
            }
            if (temp->next==nullptr){
                if (temp->data==key){  //to deleate last element if key was at last
                    prev->next=nullptr;
                    delete  temp;
                    return 0;
                }
                return -1;
            }
            prev->next=temp->next;
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

};
int main(){
    linked_list list_object;
    struct Node** head=list_object.create_linked_list();
    list_object.insert_at_beginng(head,20);
    list_object.insert_at_beginng(head,25);
    list_object.insert_at_end(head,45);
    list_object.insert_in_between(head,56,25);
    list_object.print_linked_list(head);
    
}


