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
    struct Node *prev;
} Node;

 typedef struct DbLinkedList{
     size_t size;
     Node *head;
     Node *tail;
 }DbLinkedList;


DbLinkedList * createDblLinkedList() {
    DbLinkedList *tmp = (DbLinkedList*) malloc(sizeof(DbLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}

void push(DbLinkedList *list,data product) {

    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->product = product;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;

    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}


Node* getNth(DbLinkedList *list, struct product index) {
    Node *tmp = list->head;
    size_t i = 0;

    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }

    return tmp;
}

void* deleteNth(DbLinkedList *list, struct product index) {
    Node *elm = NULL;
    void *tmp = NULL;
    elm = getNth(list, index;
    if (elm == NULL) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm->value;

    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }

    free(elm);

    list->size--;

    return tmp;
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
            if(p==tmp->prev) {
                p=tmp->prev->next=p->next;
            }
            if (p==tmp->next) {
                p=tmp->next->prev = p->prev;
            }

            if (!p==tmp->prev) {
                list->head = elm->next;
            }
            if (!elm->next) {
                list->tail = elm->prev;
            }

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

void printDblLinkedList(DbLinkedList *list) {
    Node *tmp = list->head;
    while (tmp) {
        printf("name: '%s' ",tmp->product.name);
        printf("count: '%d' ",tmp->product.count);
        printf("price: (%f) ",tmp->product.price);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(){
    DbLinkedList *list=createDblLinkedList();
    struct product pr1={"milk", 10, 30.5f};
    struct product pr2={"oranges", 50, 10.0f};
    struct product pr3={"fish", 5, 40.1f};
    struct product pr4={"cheese", 13, 20.5f};
    push(list,pr1);
    push(list,pr2);
    push(list,pr3);
    push(list,pr4);

    printf("before: \n");
    printDblLinkedList(list);

//    delete(head);
//    head=sort(head);
//    printf("after:\n");
//
//    printLinkedList(head);
//
//    totalCost(head);
}