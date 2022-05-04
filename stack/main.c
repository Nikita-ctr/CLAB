#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char* value;
    struct Item* next;
} Item;

typedef struct
{
    void (*Push)(char*);
    char* (*Pop)();
    void (*Print)();
} Stack;


Stack* createStack();

void deleteStack(Stack* stack);

void Push(char*);
char* Pop();
void Print();

void convertInfixExpressionToPostfix(Stack*, char[][255]);
double calculatePostfixExpression(Stack*, char[][255]);

static Item* g_HEAD = NULL;

int main() {
    double result;
    static char postfix[255][255] = {0};

    Stack* stack = createStack(); // allocates memory for stack

    convertInfixExpressionToPostfix(stack, postfix);

    int i = 0;
    while (postfix[i][0] != '\0')
    {
        printf("postfix: %s\n", postfix[i]);
        i++;
    }

    result = calculatePostfixExpression(stack, postfix);

    printf("%f\n", result);

    deleteStack(stack); // free memory

    return 0;
}

Stack* createStack()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    stack->Push = Push;
    stack->Pop = Pop;
    stack->Print = Print;

    printf("Stack created\n");

    return stack;
}

void deleteStack(Stack* stack)
{
    /*
    Item* ptr = g_HEAD;
    Item* current;
    while (ptr->next != NULL)
    {
        current = ptr;
        ptr = (Item*)ptr->next;
        free(current);
    }
    */

    free(stack);
    g_HEAD = NULL;

    //printf("Stack deleted\n");
}

void Push(char* ch)
{
    Item* itemPtr = (Item*)malloc(sizeof(Item));

    itemPtr->value = ch;
    itemPtr->next = (struct Item*)g_HEAD;
    g_HEAD = itemPtr;
}

char* Pop()
{
    Item* current;
    char* ch = g_HEAD->value;

    if (g_HEAD != NULL)
    {
        current = g_HEAD;
        g_HEAD = (Item*)g_HEAD->next;
        free(current);
    }

    return ch;
}

void Print()
{
    Item* ptr = g_HEAD;

    while (ptr != NULL)
    {
        printf("%s ", ptr->value);
        ptr = (Item*)ptr->next;
    }
    printf("\n");
}

int isOperation(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
        return 1;

    return 0;
}

int operationPriority(char operation)
{
    if (operation == '+' || operation == '-')
        return 1;
    if (operation == '*' || operation == '/')
        return 2;

    return 0;
}

void convertInfixExpressionToPostfix(Stack* stack, char postfix[][255])
{
    char infix[255], *q = {0};

    printf("Enter expression to calculate: ");
    fgets(infix, 255, stdin);

    int len = strlen(infix);
    infix[len] = '\0';
    infix[len-1] = ')';

    stack->Push("(");

    int i = 0, j = 0, k = 0, i_ch = 0, i_str = 0;
    while (g_HEAD != NULL)
    {
        for (; infix[i] != '\0'; i++)
        {
            if (infix[i] == '(')
            {
                stack->Push("(");
            }
            else
            {
                if (infix[i] == ')')
                {

                    for (; strcmp(q = stack->Pop(), "("); j++)
                    {
                        i_str++;
                        i_ch = 0;
                        postfix[i_str][i_ch] = *q;
                    }
                }
                else if (isOperation(infix[i]))
                {
                    do
                    {
                        q = stack->Pop();
                        if (operationPriority(*q) >= operationPriority(infix[i]))
                        {
                            i_str++;
                            i_ch = 0;
                            postfix[i_str][i_ch] = *q;
                            j++;
                        }
                        else
                        {
                            stack->Push(q);
                            break;
                        }
                    } while (1);

                    stack->Push(&infix[i]);
                }
                else // else it is number
                {
                    if (k != i)
                    {
                        k = i;
                        i_str++;
                        i_ch = 0;
                    }

                    postfix[i_str][i_ch] = infix[i];
                    i_ch++;

                    k++;
                    j++;
                }
            }
        }
    }
}

double calculatePostfixExpression(Stack* stack, char postfix[][255])
{
    int i = 0;
    double a = 0, b = 0, result = 0;

    //The sprintf() function is identical to printf(), except that the output is in an array.
    //The return value is equal to the number of characters actually included in the array.
    char rez[255];

    for (; postfix[i][0] != '\0'; i++)
    {
        switch (postfix[i][0]) // checks what is element
        {
            case '+':
                b = atof(stack->Pop());
                a = atof(stack->Pop());
                result = a + b;
                snprintf(rez, sizeof(rez), "%f", result);
                stack->Push(rez);
                break;
            case '-':
                b = atof(stack->Pop());
                a = atof(stack->Pop());
                result = a - b;
                snprintf(rez, sizeof(rez), "%f", result);
                stack->Push(rez);
                break;
            case '*':
                b = atof(stack->Pop());
                a = atof(stack->Pop());
                result = a * b;
                snprintf(rez, sizeof(rez), "%f", result);
                stack->Push(rez);
                break;
            case '/':
                b = atof(stack->Pop());
                a = atof(stack->Pop());
                result = a / b;
                snprintf(rez, sizeof(rez), "%f", result);
                stack->Push(rez);
                break;
            default:
                stack->Push(postfix[i]); // push if number
                break;
        }
    }

    return result;
}
