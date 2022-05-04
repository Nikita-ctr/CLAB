#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct product{
    char name[40];
    int count;
    int price;
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
}
DbLinkedList;


DbLinkedList * createDblLinkedList() {
    DbLinkedList *tmp = (DbLinkedList*) malloc(sizeof(DbLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}

Node* getNth(DbLinkedList *list, size_t index) {
    Node *tmp = list->head;
    size_t i = 0;

    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }

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

void* deleteNth(DbLinkedList *list, size_t index) {
    Node *elm = NULL;
    void *tmp = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm;

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

void sort(Node *start)
{
    Node *tmp;
    Node *a;
    int t;
    bool flag=1;
    while(flag==1)
    {
        tmp=start;
        a=tmp->next;
        flag=0;
        while(a)
        {
            if((tmp->product.price)>(a->product.price))
            {
                t=tmp->product.price;
                tmp->product.price=a->product.price;
                a->product.price=t;
                flag=1;
            }
            tmp=tmp->next;
            a=a->next;
        }
    }
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
        printf("\n");
        printf("count: '%d' ",tmp->product.count);

        printf("price: (%d) ",tmp->product.price);

        tmp = tmp->next;
        printf("\n");
    }

}


int main() {
DbLinkedList *list=createDblLinkedList();
    printf("before: \n");
    struct product pr1={"milk", 10, 30};
    struct product pr2={"oranges", 50, 10};
    struct product pr3={"fish", 5, 40};
    struct product pr4={"cheese", 13, 20};
    push(list,pr1);
    push(list,pr2);
    push(list,pr3);
    push(list,pr4);
    printDblLinkedList(list);
    totalCost(list->head);
    printf("\n");
    printf("after: \n");
    deleteNth(list,0);
    sort(list->head);

    printDblLinkedList(list);
    totalCost(list->head);
}
