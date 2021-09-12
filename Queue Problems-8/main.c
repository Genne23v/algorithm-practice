//
//  main.c
//  Algorithm-8
//
//  Created by Wonkeun No on 2021-02-09.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MIN 20
#define ERROR_VALUE -999

typedef struct Queue_t
{
    int front;
    int back;
    int size;
    int capacity;
    int *data;
}Queue;
void QueueInitialize(Queue *que)
{
    que->back = 0;
    que->front = 9;
    que->size = 0;
    que->data = malloc(sizeof(int) * MIN);
    memset((void*)que->data, 0x0, sizeof(int) * MIN);
    que->capacity = MIN;
}
void QueueUninitialize(Queue *que)
{
    free(que->data);
}
void QueueAdd(Queue *que, int value)
{
    if (que->size >= que->capacity)
    {
        que->data = realloc(que->data, que->capacity + MIN);
        if (que->data)
            que->capacity += MIN;
        else {
            printf("\n Memory allocation error");
            return;
        }
    } else {
        que->size++;
        que->data[que->back] = value;
        que->back = (que->back +1) % (que->capacity -1);
    }
}
int QueueRemove(Queue *que)
{
    int value;
    if (que->size <= 0){
        printf("\n Queue is empty. ");
        return ERROR_VALUE;
    } else {
        que->size--;
        value = que->data[que->front];
        que->front = (que->front -1) % (que->capacity -1);
        if (que->size < (que->capacity / 2) && que->capacity > MIN){
            int *newData = malloc(sizeof(int) * que->capacity / 2);
            for (int i=0; i<que->size; i++){
                newData[i] = que->data[(que->front + i) % (que->capacity -1)];
            }
            que->capacity = que->capacity /2;
            free(que->data);
            que->data = newData;
        }
    }
    return value;
}

int QueueIsEmpty(Queue *que)
{
    if (que->size <= 0)
        return 1;
    
    return 0;
}
int QueueSize(Queue *que)
{
    return que->size;
}

#define MAX_CAPACITY 50

typedef struct stack
{
    int top;
    int data[MAX_CAPACITY];
}Stack;
void StackInitialize(Stack *stk)
{
    stk->top = -1;
}
void StackAdd(Queue *que, int value)
{
    const int ORG_SIZE = que->size;
    QueueAdd(que, value);
    for (int i=0; i<ORG_SIZE; i++){
        int temp = QueueRemove(que);
        QueueAdd(que, temp);
    }
}
void StackPush(Stack *stk, int value)
{
    if (stk->top < MAX_CAPACITY - 1){
        stk->top++;
        stk->data[stk->top] = value;
        printf("value push : %d \n", value);
    } else {
        printf("stack overflow\n");
    }
}
int StackPop(Stack *stk)
{
    if (stk->top >= 0){
        int value = stk->data[stk->top];
        stk->top--;
        printf("value pop : %d \n", value);
        return value;
    }
    printf("stack empty\n");
    return ERROR_VALUE;
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

void ReverseStack(Stack *stk)
{
    Queue que;
    QueueInitialize(&que);
    while (!StackIsEmpty(stk)){
        QueueAdd(&que, StackPop(stk));
    }
    while (!QueueIsEmpty(&que)){
        StackPush(stk, QueueRemove(&que));
    }
    QueueUninitialize(&que);
}

void ReverseQueue(Queue *que)
{
    Stack stk;
    StackInitialize(&stk);
    while (!QueueIsEmpty(que)){
        StackPush(&stk, QueueRemove(que));
    }
    while (!StackIsEmpty(&stk)){
        QueueAdd(que, StackPop(&stk));
    }
}

int JosephysProblem(int n, int k)
{
    Queue que;
    QueueInitialize(&que);
    int ans = 0;
    
    for (int i=0; i<n; i++){
        QueueAdd(&que, i+1);
    }
    while (!QueueIsEmpty(&que)){
        for (int i=1; i<k; i++){
            QueueAdd(&que, QueueRemove(&que));
        }
        ans = QueueRemove(&que);
    }
    return ans;
}

int Equal(int lhs, int rhs)
{
    if (lhs == rhs) return 1;
    return 0;
}
int CompStack(Stack *stk1, Stack *stk2)
{
    if (StackSize(stk1) != StackSize(stk2))
        return 0;
    
    while (!StackIsEmpty(stk1)){
        if (!Equal(StackPop(stk1), StackPop(stk2)))
            return 0;
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
