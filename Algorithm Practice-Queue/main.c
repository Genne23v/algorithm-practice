//
//  main.c
//  Algorithm Practice-Queue
//
//  Created by Wonkeun No on 2021-02-07.
//
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 10
#define ERROR_VALUE -999

typedef struct Queue_t
{
    int front;
    int back;
    int size;
    int data[MAX_CAPACITY];
}Queue;
void QueueInitialize(Queue *que)
{
    que->back = 0;
    que->front = 0;
    que->size = 0;
}
void QueueAdd(Queue *que, int value)
{
    if (que->size >= MAX_CAPACITY)
    {
        printf("\n Queue is full. ");
        return;
    } else
    {
        que->size++;
        que->data[que->back] = value;
        que->back = (que->back +1) % (MAX_CAPACITY-1);
    }
}
int QueueRemove(Queue *que)
{
    int value;
    if (que->size <= 0){
        printf("Queue is empty.");
        return ERROR_VALUE;
    } else {
        que->size--;
        value = que->data[que->front];
        que->front = (que->front +1) % (MAX_CAPACITY -1);
    }
    return value;
}
int QueueFront(Queue *que)
{
    return que->data[que->front];
}
int QueueBack(Queue *que)
{
    return que->data[que->back-1];
}
int QueueRemoveBack(Queue *que)
{
    int value;
    if (que->size <= 0){
        printf("Queue is empty.");
        return ERROR_VALUE;
    } else {
        que->size--;
        value = que->data[que->back-1];
        que->back = (que->back-1) % (MAX_CAPACITY-1);
    }
    return value;
}
int QueueIsEmpty(Queue *que)
{
    return que->size == 0;
}
int QueueSize(Queue *que)
{
    return que->size;
}

typedef struct queueNode_t
{
    int value;
    struct queueNode_t *next;
}QueueNode;
void printList(QueueNode *tail)
{
    if (!tail){
        return;
    }
    QueueNode *head = tail->next;
    printf("\n%d ", head->value);
    QueueNode *currNode = head->next;
    
    while(currNode != head){
        printf("%d ", currNode->value);
        currNode = currNode->next;
    }
}
int LinkedQueueAdd(QueueNode **ptrTail, int value)
{
    QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
    
    if (!temp){
        printf("Memory allocation error");
        return 0;
    }
    QueueNode *tail = *ptrTail;
    
    if (!tail) {
        temp->value = value;
        temp->next = temp;
        *ptrTail = temp;
    } else {
        temp->value = value;
        temp->next = tail->next;
        tail->next = temp;
        *ptrTail = temp;
    }
    return 1;
}

int LinkedQueueRemove(QueueNode **ptrTail)
{
    QueueNode *tail = *ptrTail;
    QueueNode *deleteMe;
    int value;
    
    if (!tail){
        return ERROR_VALUE;
    }
    if (tail->next == tail){
        value = tail->value;
        free(tail);
        *ptrTail = NULL;
        return value;
    }
    deleteMe = tail->next;
    value = deleteMe->value;
    tail->next = deleteMe->next;
    free(deleteMe);
    return value;
}

typedef struct Stack_t
{
    int top;
    int data[0];
}Stack;
void StackInitialize(Stack *stk)
{
    
}
void StackPush(Stack *stk, int value)
{
    
}
int StackPop(Stack *stk)
{
    return 1;
}
int StackIsEmpty(Stack *stk)
{
    return 1;
}
typedef struct StackQueue_t
{
    Stack stk1;
    Stack stk2;
}StackQueue;
void StackQueueInitialize(StackQueue *que)
{
    StackInitialize(&que->stk1);
    StackInitialize(&que->stk2);
}
void StackQueuAdd(StackQueue *que, int value)
{
    StackPush(&que->stk1, value);
}
int StackQueueRemove(StackQueue *que)
{
    int value;
    if (!StackIsEmpty(&que->stk2))
        return StackPop(&que->stk2);
    
    while (!StackIsEmpty(&que->stk1)){
        value = StackPop(&que->stk1);
        StackPush(&que->stk2, value);
    }
    return StackPop(&que->stk2);
}

int CircularTour(int arr[][2], int n)
{
    Queue que;
    QueueInitialize(&que);
    int nextPump = 0, prevPump;
    int count = 0;
    int petrol = 0;
    
    while (QueueSize(&que) != n)
    {
        while (petrol >= 0 && QueueSize(&que) != n)
        {
            QueueAdd(&que, nextPump);
            petrol += (arr[nextPump][0] - arr[nextPump][1]);
            nextPump = (nextPump +1) % n;
        }
        while (petrol < 0 && QueueSize(&que) > 0)
        {
            prevPump = QueueRemove(&que);
            petrol -= (arr[prevPump][0] - arr[prevPump][1]);
        }
        count += 1;
        if (count ==n) {
            return -1;
        }
    }
    if (petrol >= 0){
        return QueueRemove(&que);
    } else {
        return -1;
    }
}

void printArray(arr[], int index)
{
    
}
int convertXY(int src, int dst)
{
    Queue que;
    int arr[100];
    int steps = 0;
    int index = 0;
    int value;
    QueueInitialize(&que);
    QueueAdd(&que, src);
    
    while(QueueSize(&que) != 0)
    {
        value = QueueRemove(&que);
        arr[index++] = value;
        if (value == dst){
            printArray(arr, index);
            return steps;
        }
        steps++;
        if (value < dst){
            QueueAdd(&que, value * 2);
        } else {
            QueueAdd(&que, value-1);
        }
    }
    return -1;
}

void maxSlideWindows(int arr[], int size, int k)
{
    Queue que;
    QueueInitialize(&que);
    for (int i=0; i<size; i++){
        if (QueueSize(&que) && QueueFront(&que) <= i -k){
            QueueRemove(&que);
        }
        while(QueueSize(&que) && arr[QueueBack(&que)] <= arr[i]){
            QueueRemoveBack(&que);
        }
        QueueAdd(&que, i);
        if (i >= (k-1)){
            printf(" %d ", arr[QueueFront(&que)]);
        }
    }
}

int minOfMaxSlidingWindows(int arr[], int size, int k)
{
    Queue que;
    QueueInitialize(&que);
    int minVal = 999999;
    for (int i=0; i<size; i++)
    {
        if (QueueSize(&que) && QueueFront(&que) <= i-k){
            QueueRemove(&que);
        }
        while (QueueSize(&que) && arr[QueueBack(&que)] <= arr[i])
        {
            QueueRemove(&que);
        }
        QueueAdd(&que, i);
        if ((i >= k-1) && minVal > arr[QueueFront(&que)]) {
            minVal = arr[QueueFront(&que)];
        }
    }
    printf("The smallest value in max value: %d", minVal);
    return minVal;
}

void maxOfSlidingWindows(int arr[], int size, int k)
{
    Queue que;
    QueueInitialize(&que);
    int maxVal = -999999;
    for (int i=0; i<size; i++){
        if (QueueSize(&que) && QueueFront(&que) <= i-k){
            QueueRemove(&que);
        }
        while(QueueSize(&que) && arr[QueueBack(&que)] >= arr[i] ){
            QueueRemove(&que);
        }
        QueueAdd(&que, i);
        
        if (i >= k-1 && maxVal < arr[QueueFront(&que)]){
            maxVal = arr[QueueFront(&que)];
        }
    }
    printf("The largest value in min values: %d ", maxVal);
}

void firstNegSlidingWindows(int arr[], int size, int k)
{
    Queue que;
    QueueInitialize(&que);
    for (int i=0; i<size; i++)
    {
        if (QueueSize(&que) && QueueFront(&que) <= i-k){
            QueueRemove(&que);
        }
        if (arr[i] < 0){
            QueueAdd(&que, i);
        }
        if (i >= k-1){
            if (QueueSize(&que) > 0){
                printf("%d ", arr[QueueFront(&que)]);
            } else {
                printf("NAN");
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
//    QueueNode *tail = NULL;
//    LinkedQueueAdd(&tail, 1);
//    LinkedQueueAdd(&tail, 2);
//    LinkedQueueAdd(&tail, 3);
//    for (int i=0; i<3; i++){
//        printf("%d ", LinkedQueueRemove(&tail));
//    }

//    int tour[3][2] = {{8,6}, {1, 4}, {7,6}};
//    printf("Circular Tour: %d ", CircularTour(tour, 3));

//    int arr[] = {11, 2, 75, 92, 59, 90, 55};
//    int k = 3;
//    maxSlideWindows(arr, 7, 3);
//    minOfMaxSlidingWindows(arr, 7, 3);
    
    int arr[] = {3, -2, -6, 10, -14, 50, 14, 21};
    int k = 3;
    firstNegSlidingWindows(arr, 8, 3);
    
    return 0;
}
