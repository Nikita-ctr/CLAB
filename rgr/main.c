#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct object {
    char name[15];
    int number;
    int count;
    double duration;
    struct object *next;
} Airport;


Airport *HEAD = NULL;
void addLast(Airport *head, char name[15], int count, double duration, int
number) {
    while (head->next != NULL)
        head = head->next;
    Airport *new = (Airport *) malloc(sizeof(Airport));
    memcpy(new->name, name, sizeof(&name));
    new->count = count;
    new->number = number;
    new->duration = duration;
    new->next = NULL;
    head->next = new;
}
void addFirst(char name[15], int count, double duration, int number) {
    HEAD = (Airport *) malloc(sizeof(Airport));
    memcpy(HEAD->name, name, sizeof(&name));
    HEAD->count = count;
    HEAD->number = number;
    HEAD->duration = duration;
    HEAD->next = NULL;
}
int connectToDB() {
    FILE *file;
    if ((file = fopen("DBFile.txt", "r")) == NULL) return 0;
    int count, number;
    double duration;
    char name[15], numberC[10], countC[10], durationC[10];
    while (!feof(file)) {
        fscanf(file, "%s\n%s\n%s\n%s\n", name, numberC, countC, durationC);
        number = atoi(numberC);
        count = atoi(countC);
        duration = atof(durationC);
        if (HEAD == NULL) addFirst(name, count, duration, number);
        else addLast(HEAD, name, count, duration, number);
    }
    fclose(file);
    return 1;
}
void print(Airport *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    int n = 1;
    printf("\n");
    while (head != NULL) {
        printf("| %d. | NAME - %-10s | COUNT - %-5d | DURATION - %-5.1f | NUMBER - %-5d |\n",
        n, head->name, head->count, head->duration, head->number);
        n++;
        head = head->next;
    }
    printf("\n");
}
void userData() {
    char name[15];
    int count, number;
    float duration;
    printf("Enter data through a space(format:name count number duration): ");
    scanf("%s %d %d %f", name, &count, &number, &duration);
    addLast(HEAD, name, count, duration, number);
    printf("\n");
}
void disconnectFromDB() {
    FILE *file;
    if ((file = fopen("DBFile", "w")) == NULL) {
        puts("Error");
        return;
    }
    while (HEAD != NULL) {
        fprintf(file, "%s\n%d\n%d\n%.1f\n",
                HEAD->name, HEAD->number, HEAD->count, HEAD->duration);
        HEAD = HEAD->next;
    }
    fclose(file);
}
void deleteByID(Airport *head, int id) {
    int count = 1;
    Airport *old;
    while (head != NULL) {
        if (count == id) {
            old->next = head->next;
            puts("Element was deleted!");
            return;
        }
        count++;
        old = head;
        head = head->next;
    }
    puts("Element not found!");
}
void editNote(Airport *head, int id) {
    int count = 1, flag = 0;
    while (head != NULL) {
        if (count == id) {
            flag = 1;
            break;
        }
        count++;
        head = head->next;
    }
    if (flag == 0) {
        printf("Element not found\n");
        return;
    }
    printf("\n\t--- Possible actions ---\n");
    printf("1 - name\n2 - count\n3 - number\n4 - duration\n0 - exit\n");
    int key;
    while (1) {
        printf("Select an action to the edit: ");
        scanf("%d", &key);
        switch (key) {
            case 0:
                return;
            case 1:
                printf("Enter new name: ");
                scanf("%s", head->name);
                break;
            case 2:
                printf("Enter new count: ");
                int count;
                scanf("%d", &count);
                head->count = count;
                break;
            case 3:
                printf("Enter new number: ");
                int number;
                scanf("%d", &number);
                head->number = number;
                break;
            case 4:
                printf("Enter new duration: ");
                float duration;
                scanf("%f", &duration);
                head->duration = duration;
                break;
            default:
                puts("Repeat action");
        }
    }
}
void orderByNumber(Airport *head) {
    int from, to;
    printf("Enter range:\nfrom");
    scanf("%d", &from);
    printf("to ");
    scanf("%d", &to);
    Airport *now = head;
    int n = 1, count = 0;
    printf("\n");
    while (now != NULL) {
        if (now->number >= from && now->number <= to) {
            printf("| %d. | NAME - %-10s | COUNT - %-5d | DURATION - %-5.1f | NUMBER - %-5d |\n",
            n, now->name, now->count, now->duration, now->number);
            count++;
        }
        n++;
        now = now->next;
    }
    if (count == 0) printf("Nothing found\n");
    else printf("\n");
}
void orderByDuration(Airport *head) {
    float from, to;
    printf("Enter range:\nfrom");
    scanf("%f", &from);
    printf("to");
    scanf("%f", &to);
    Airport *now = head;
    int n = 1, count = 0;
    printf("\n");
    while (now != NULL) {
        if (now->duration >= from && now->duration <= to) {
            printf("| %d. | NAME - %-10s | COUNT - %-5d | DURATION - %-5.1f | NUMBER - %-5d |\n",
            n, now->name, now->count, now->duration, now->number);
            count++;
        }
        n++;
        now = now->next;
    }
    if (count == 0) printf("Nothing found\n");
    else printf("\n");
}
void orderByName(Airport *head) {
    char name[15];
    printf("Enter name:");
    scanf("%s", name);
    Airport *now = head;
    int n = 1, count = 0;
    printf("\n");
    while (now != NULL) {
        if (strcmp(now->name, name) == 0) {
            printf("| %d. | NAME - %-10s | COUNT - %-5d | DURATION - %-5.1f | NUMBER - %-5d |\n",
            n, now->name, now->count, now->duration, now->number);
            count++;
        }
        n++;
        now = now->next;
    }
    if (count == 0) printf("Nothing found\n");
    else printf("\n");
}
Airport *sortToAscending(Airport *head) {
    if (head == NULL) return NULL; //проверка списка на NULL
    Airport *newElement, *currentElement, *beforeNewElement;
    Airport *newHead = NULL; //указатель на первый элемент нового списка
    for (Airport *i = head; i != NULL;) { //проходим по всем элементам списка
        newElement = i; //указатель на текущий элемент списка
        i = i->next; //переход на следующий элемент списка
        currentElement = newHead;
        /*находим место вставки нового элемента*/
        for (beforeNewElement = NULL; currentElement != NULL &&
                                      newElement->duration > currentElement->duration;) {
            beforeNewElement = currentElement;
            currentElement = currentElement->next;
        }
        if (beforeNewElement == NULL) { //вставка в начало нового список
            newElement->next = newHead;
            newHead = newElement;
        } else { //вставка нового элемента в найденное место
            newElement->next = currentElement;
            beforeNewElement->next = newElement;
        }
    }
    print(newHead);
    return newHead;
}
Airport *sortToDescending(Airport *head) {
    if (head == NULL) return NULL;
    Airport *newElement, *currentElement, *beforeNewElement;
    Airport *newHead = NULL;
    for (Airport *i = head; i != NULL;) {
        newElement = i;
        i = i->next;
        currentElement = newHead;
        for (beforeNewElement = NULL; currentElement != NULL &&
                                      newElement->duration < currentElement->duration;) {
            beforeNewElement = currentElement;
            currentElement = currentElement->next;
        }
        if (beforeNewElement == NULL) {
            newElement->next = newHead;
            newHead = newElement;
        } else {
            newElement->next = currentElement;
            beforeNewElement->next = newElement;
        }
    }
    print(newHead);
    return newHead;
}
void getInf() {
    printf("\n\t\t--- DATABASE HELP ---\n");
    printf("1 - add a note (addLast)\n2 - delete a note by key (deleteByID)\n"
           "3 - edit a node (editNote)\n4 - data output (print)\n5 - order by number (orderByNumber)"
                                  "\n6 - order by name (orderByName)\n7 - order by duration (orderByDuration)\n"
                                  "8 - ascending sort (sortToAscending)\n9 - descending sort (sortToDescending)\n"
                                "0 - finish work (disconnectFromDB)\n");
}
int main() {
    if (connectToDB() == 0) {
        printf("\nFailed to connect to database\n");
        return 0;
    }
    int key, id;
    getInf();
    while (1) {
        printf("\nSelect an action ");
        scanf("%d", &key);
        switch (key) {
            case 0:
                disconnectFromDB();
                printf("\n\t--- Work finished ---\n");
                return 0;
            case 1:
                userData();
                break;
            case 2:
                printf("Enter id of the object to be deleted: ");
                scanf("%d", &id);
                deleteByID(HEAD, id);
                break;
            case 3:
                printf("Enter id of the object to be edit: ");
                scanf("%d", &id);
                editNote(HEAD, id);
                break;
            case 4:
                print(HEAD);
                break;
            case 5:
                orderByNumber(HEAD);
                break;
            case 6:
                orderByName(HEAD);
                break;
            case 7:
                orderByDuration(HEAD);
                break;
            case 8:
                HEAD = sortToAscending(HEAD);
                break;
            case 9:
                HEAD = sortToDescending(HEAD);
                break;
            default:
                printf("Unknown action. Please repeat");
        }
    }
}