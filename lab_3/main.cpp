#include <iostream>
#include <cstring>


typedef struct node
{
    char el;
    struct node *next;
} Stack;

Stack* Head=NULL;


//TODO рисунок как вставлять в стек
void Push(char element)
{
    Stack *p;
    p = (Stack*)malloc(sizeof(Stack));
    if(p!=NULL)
    {
        p->el=element;
        p->next=Head;
        Head=p;
        printf("Push elem %c \n",element);

    }
    else
    {
        puts("Error! Not free memory!");
    }
}


//TODO рисунок как удалять из стека
char Pop()
{
    char a=Head->el;
    Stack* p=Head;
    Head=Head->next;
    free(p);
    printf("Pop elem %c \n",a);
    return a;
}

int IsOperation(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        return 1;
    return 0;
}



int Prior(char oper)
{
    if(oper=='+' ||oper=='-' )
        return 1;
    if(oper=='*' ||oper=='/')
        return 2;
    return 0;
}


int calculate(char postfix[])
{
    int a=0,b=0,ind=0,rez=0;
    for(;postfix[ind]!=NULL;ind++)
    {
        switch(postfix[ind]) /*проверяем чем являтся элемент*/
        {
            case '+':b=Pop();a=Pop();
                rez=a+b; Push(rez);break;
            case '-':b=Pop();a=Pop();
                rez=a-b; Push(rez);break;
            case '*':b=Pop();a=Pop();
                rez=a*b; Push(rez);break;
            case '/':b=Pop();a=Pop();
                rez=a/b; Push(rez);break;
            default: Push(postfix[ind]-'0');break; /*иначе это число*/
        }
    }
    return rez;
}


int main()
{
    char infix[100],postfix[100],q;
    int i=0,j=0,len;
    int rezult;

   scanf("%[n]",infix);
    Push('('); /* 1.Ввести в стек левую скобку '('*/
    len=strlen(infix);
    infix[len]=')'; /*2. Добавить в конец строки с инфиксным выражением правую скобку ')'*/
    infix[len+1]='\0';


    while(Head!=NULL) /* Пока стек не пуст */
    {
        for(;infix[i]!= '\0';i++)/* считываем символы из строки содержащей инфиксное выражение слева направо */
        {
            if(infix[i]=='(') /* Если текущий символ в инфиксной строке – левая скобка */
                Push('('); /* помещаем ее в стек.*/
            else
            if(infix[i]==')') /* Если текущий символ в инфиксной строке – правая скобка */
            {
/* извлекаем знаки операций из стека и вставляем их в результирующую строку, до тех пор пока на вершине стека не появиться левая скобка */
                for(;(q=Pop())!= '(';j++)
                    postfix[j]=q;
            }
            else if(IsOperation(infix[i])) /* Если текущий символ в инфиксной строке – знак операции */
            {
                do{
                    q=Pop(); /* извлекаем знаки операций из стека */
                    if(Prior(q)>=Prior(infix[i])) /* если операции имеют равный или более высокий приоритет по сравнению с текущей операцией вставляем извлеченные знаки операций в результирующую строку */
                    {
                        postfix[j]=q;
                        j++;
                    }
                    else{ /*иначе назад в стек*/
                        Push(q);
                        break;
                    }
                }while(1);
                /* Вставим текущий символ в стек */
                Push(infix[i]);
            }
            else
            {
/* Иначе текущий символ в инфиксной строке – цифра, копируем его в результирующую строку*/
                postfix[j]=infix[i];
                j++;
            }
        }
    }
/*Заканчиваем результирующую строку*/
    postfix[j]='\0';
    puts(postfix);
    rezult=calculate(postfix);
    printf("rezult = %d",rezult);
}

