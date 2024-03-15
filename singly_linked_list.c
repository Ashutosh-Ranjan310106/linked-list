#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* create_node(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->next=NULL;
    return node;
}

struct Node** create_linked_list(){
    struct Node** head = malloc(sizeof(struct Node*));
    *head = NULL;
    return head;
}

int insert_at_beginng(struct Node** head, int data){
    struct Node* new_node=create_node(data);
    if (*head==NULL){
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
    if (*head==NULL){
        *head=new_node;
    }else{
        struct Node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    return 0;
}


int delete_node(struct Node** head, int key){
    struct Node* prev=NULL;
    struct Node* temp=*head;
    if (temp!=NULL && temp->data==key){
        *head=temp->next;
        free(temp);
        return 0;
    }
    while(temp->next!=NULL){
        if (temp->data==key){
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    if (temp->next==NULL){
        if (temp->data==key){ // to deleate last element if key was at last
            prev->next=NULL;
            free(temp);
            return 0;
        }
        return -1;
    }
    prev->next=temp->next;
    free(temp);
    return 0;
}
int print_linked_list(struct Node** head){
    struct Node* temp;
    temp = *head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
int main(){
    struct Node** head=create_linked_list();
    insert_at_beginng(head,20);
    insert_at_beginng(head,25);
    insert_in_between(head,56,20);
    insert_at_end(head,45);
    
    
    print_linked_list(head);
    struct Node* temp=*head;
    int key =20;
    while (temp!=NULL){
        if (temp->data==20){
            break;
        }
        temp=temp->next;
        
    }
    printf("\n");
}


