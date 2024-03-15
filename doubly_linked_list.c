#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* create_node(int data){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=data;
    node->prev=NULL;
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
        new_node->prev=NULL;
    }else{
        new_node->next=*head;
        new_node->prev=NULL;
        (*head)->prev=new_node;
        *head=new_node;
    }
    return 0;
}
int insert_in_between(struct Node** head, int data,int key){
    struct Node* new_node=create_node(data);
    struct Node* temp=*head;
    while(temp!=NULL){
        if (temp->data==key){
            new_node->next=temp->next;
            temp->next->prev=new_node;

            temp->next=new_node;
            new_node->prev=temp;
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
    if (*head==NULL){
        *head=new_node;
        new_node->prev=NULL;
    }else{
        struct Node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->prev=temp;
    }
    return 0;
}


int delete_node(struct Node** head, int key){
    struct Node* temp=*head;
    if (temp!=NULL && temp->data==key){
        *head=temp->next;
        temp->next->prev=NULL;
        free(temp);
        return 0;
    }
    while(temp->next!=NULL){
        if (temp->data==key){
            break;
        }
        temp=temp->next;
    }
    if (temp->next==NULL){
        if (temp->data==key){    // to deleate last element if key was at last
            temp->prev->next=NULL;
            free(temp);
            return 0;
        }
        return -1;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
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
int print_in_revese(struct Node** head){
    struct Node* temp;
    temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp!= NULL){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
    return 0;
}
int main(){
    struct Node** head=create_linked_list();
    insert_at_beginng(head,20);
    insert_at_beginng(head,25);
    insert_at_end(head,45);
    insert_at_end(head,67);
    insert_in_between(head,68,25);
    print_linked_list(head);
    printf("\nafter deleting 20:-\n");
    delete_node(head,20);
    print_linked_list(head);
    printf("\nin reverse:-\n");
    print_in_revese(head);
    
}


