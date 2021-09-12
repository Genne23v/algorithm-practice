//
//  main.c
//  Algorithm-7
//
//  Created by Wonkeun No on 2021-02-06.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//#include <limits.h>

#define MAX_CAPACITY 50
#define ERROR_VALUE -999

typedef struct stack
{
    int top;
    int data[MAX_CAPACITY];
} Stack;

void StackInitialize(Stack *stk);
void StackPush(Stack *stk, int value);
int StackPop(Stack *stk);
int StackIsEmpty(Stack *stk);
int StackSize(Stack *stk);

void StackInitialize(Stack *stk)
{
    stk->top = -1;
}
void StackPush(Stack *stk, int value)
{
    if (stk->top < MAX_CAPACITY -1)
    {
        stk->top++;
        stk->data[stk->top] = value;
        printf("value push : %d \n", value);
    }
    else
    {
        printf("Stack overflow\n");
    }
}
int StackPop(Stack *stk)
{
    if (stk->top >= 0)
    {
        int value = stk->data[stk->top];
        stk->top--;
        printf("value pop : %d \n", value);
        return value;
    }
    else
    {
        printf("Stack empty\n");
        return ERROR_VALUE;
    }
}
int StackTop(Stack *stk)
{
    int value = stk->data[stk->top];
    return value;
}
int StackIsEmpty(Stack *stk)
{
    return (stk->top == -1);
}
int StackSize(Stack *stk)
{
    return (stk->top +1);
}

void Dec2Bin(int dec)
{
    Stack stk;
    StackInitialize(&stk);
    
    while (dec > 0)
    {
        int remainders = dec % 2;
        dec = dec /2;
        StackPush(&stk, dec);
    }
    while (!StackIsEmpty(&stk))
    {
        int bin = StackTop(&stk);
        StackPop(&stk);
        printf("1d", bin);
    }
    printf("\n");
}

int isBalancedHTMLTag(char *html, int size)
{
    Stack stk;
    StackInitialize(&stk);
    char ch;
    
    for (int i=0; i<size; i++)
    {
        ch = html[i];
        
        if (ch == "<")
        {
            StackPush(&stk, ch);
        }
        else if (ch == ">")
        {
            if (StackPop(&stk) != "<")
                return 0;
        }
    }
    return (StackSize(&stk) == 0);
}

const int BUFSIZE = 10;
int isOperator(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return 1;
    }
    return 0;
}
void postfixToInfix(char *expn, char *output)
{
    Stack stk;
    StackInitialize(&stk);
    
    char ch;
    int i=0;
    int digit =0;
    
    char buffer[BUFSIZE];
    memset(buffer, 0x0, BUFSIZE * sizeof(char));
    int buffer_i = 0;
    
    while ((ch = expn[i++]) != '\0')
    {
        if (isdigit(ch)){
            buffer[buffer_i++] = ch;
            digit =1;
        } else {
            if (digit){
                StackPush(&stk, buffer);
                memset(buffer, 0x0, BUFSIZE * sizeof(char));
                buffer_i=0;
                digit = 0;
            } else if (isOperator(ch)){
                char *opnd2 = StackPop(&stk);
                char *opnd1 = StackPop(&stk);
                sprintf(output, "( %s %c %s )", opnd1, ch, opnd2);
                StackPush(&stk, output);
            }
        }
    }
}

#define SWAP(A, B){char T = A; A = B; B = T;}
void ReverseString(char *src)
{
    int len = strlen(src);
    for (int i=0, j=len=1; i<len/2; i++, j--){
        SWAP(src[i], src[j]);
    }
}
void preffixToInfix(char *expn, char *output)
{
    Stack stk;
    StackInitialize(&stk);
    
    char ch;
    int i = strlen(expn);
    int digit =0;
    
    char buffer[BUFSIZE];
    memset(buffer, 0x0, BUFSIZE * sizeof(char));
    int buffer_i = 0;
    
    while(i-- > 0)
    {
        ch = expn[i];
        if (isdigit(ch)){
            buffer[buffer_i++] = ch;
            digit =1;
        } else {
            if (digit){
                ReverseString(buffer);
                StackPush(&stk, buffer);
                
                memset(buffer, 0x0, BUFSIZE * sizeof(char));
                buffer_i = 0;
                digit = 0;
            } else if (isOperator(ch)){
                char *opnd1 = StackPop(&stk);
                char *opnd2 = StackPop(&stk);
                sprintf(output, "( %s %c %s )", opnd1, ch, opnd2);
                StackPush(&stk, output);
            }
        }
    }
}

int isPalindrome(char *s)
{
    int len = strlen(s);
    if (len <= 1) return 1;
    
    Stack stk;
    StackInitialize(&stk);
    
    for (int i=0; i<len; i++){
        int ch = s[i];
        if (isalnum(ch)){
            StackPush(&stk, ch);
        }
    }
    int half = (StackSize(&stk) / 2);
    for (int i=0; i<half; i++){
        int ch = s[i];
        if (tolower(ch) != StackPop(&stk)){
            return 0;
        }
    }
    return 1;
}

typedef struct stackNode_t
{
    int value;
    struct stackNode_t *next;
    struct stackNode_t *prev;
}StackNode;
typedef struct bidirectionalStack
{
    StackNode *head;
    StackNode *tail;
}BiStack;
void StackInitialzie(BiStack *stk)
{
    stk->head = NULL;
    stk->tail = NULL;
}
void StackPushBack(BiStack *stk, int value)
{
    StackNode *temp = (StackNode*)malloc(sizeof(StackNode));
    if (!temp){
        printf("Hemory allocation error");
        return;
    }
    temp->value = value;
    temp->prev = stk->tail;
    temp->next = NULL;
    
    stk->tail = temp;
    if (stk->tail->prev)
        stk->tail->prev->next = stk->tail;
    else {
        stk->head = stk->tail;
        stk->tail->next = NULL;
        stk->head->prev = NULL;
    }
}
void StackPushFront(BiStack *stk, int value)
{
    StackNode *temp = (StackNode*)malloc(sizeof(StackNode));
    if (!temp){
        printf("Memory allocation error");
        return;
    }
    temp->value = value;
    temp->next = stk->head;
    temp->prev = NULL;
    
    stk->head = temp;
    if (stk->head->next)
        stk->head->next->prev = stk->head;
    else {
        stk->tail = stk->head;
        stk->tail->next = NULL;
        stk->head->prev = NULL;
    }
}
int StackPopBack(BiStack *stk)
{
    StackNode *deleteMe;
    int value;
    if (stk->tail) {
        deleteMe = stk->tail;
        stk->tail = deleteMe->prev;
        if (stk->tail)
            stk->tail->next = NULL;
        value = deleteMe->value;
        free(deleteMe);
        return value;
    } else {
        printf("Stack is empty \n");
        return ERROR_VALUE;
    }
}
int StackPopFront(BiStack *stk)
{
    StackNode *deleteMe;
    int value;
    if (stk->head){
        deleteMe = stk->head;
        stk->head = deleteMe->next;
        if (stk->head)
            stk->head->prev = NULL;
        value = deleteMe->value;
        free(deleteMe);
        return value;
    } else {
        printf("Stack is empty \n");
        return ERROR_VALUE;
    }
}

int main(int argc, const char * argv[]) {
    
    
    printf("Hello, World!\n");
    return 0;
}
