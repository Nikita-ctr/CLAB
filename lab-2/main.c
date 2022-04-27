#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct product{
     char name[40];
     int count;
     float price;
} data;


 typedef struct Node {
    data product;
    struct Node *next;
} Node;


void push(Node **head,data product) {

    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->product=product;

    tmp->next = (*head);
    (*head) = tmp;

}

Node *delete(Node *p){
char name[40];
Node *tmp=p,*f,*prev=NULL;

    printf("Write name to delete:\n");
    gets(name);

    while (tmp)
    {
        if(!strcmp(name,tmp->product.name))
        {
            if(p==tmp) p=tmp->next;

            f=tmp;
            tmp=tmp->next;

            if(prev) prev->next=tmp;
            free(f);
        } else
        {
            prev=tmp;
            tmp=tmp->next;
        }
    }
    return p;
}

Node *sort(Node *root){
    Node *new_root=NULL;

    while (root != NULL)
    {
        Node *node=root;
        root=root->next;

        if(new_root==NULL||node->product.price < new_root->product.price)
        {
            node->next=new_root;
            new_root=node;
        } else
        {
            Node *current=new_root;
            while (current->next!=NULL && node->product.price >= current->next->product.price)
            {
                current=current->next;
            }
            node->next=current->next;
            current->next=node;
        }
    }
    return new_root;
}

void totalCost(Node *head){
  int total=0;
  Node *p=head;

    while (p){
        total+=p->product.count * p->product.price;
        p=p->next;
    }
    printf("total cost: %d ",total);
}

void printLinkedList(Node *head) {
    while (head) {
        printf("name: '%s' ", head->product.name);
        printf("count: '%d' ", head->product.count);
        printf("price: (%f) ", head->product.price);
        printf("\n");
        head = head->next;
    }
    printf("\n");
}

int main(){
    Node* head = NULL;
    struct product pr1={"milk", 10, 30.5f};
    struct product pr2={"oranges", 50, 10.0f};
    struct product pr3={"fish", 5, 40.1f};
    struct product pr4={"cheese", 13, 20.5f};
    push(&head,pr1);
    push(&head,pr2);
    push(&head,pr3);
    push(&head,pr4);

    printf("before: \n");
    printLinkedList(head);

    delete(head);
    head=sort(head);
    printf("after:\n");

    printLinkedList(head);

    totalCost(head);
}