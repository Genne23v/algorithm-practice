//
//  main.c
//  Algorithm Practice-Stack
//
//  Created by Wonkeun No on 2021-01-28.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAX_CAPACITY 23
#define ERROR_VALUE -1

//typedef struct stack
//{
//    int top;
//    int data[MAX_CAPACITY];
//}Stack;
typedef struct stack
{
    int top;
    int *data;
    int capacity;
    int min;
}Stack;
void StackInitialize(Stack *stk)    //, int size)    //Add size and uncomment the comments
{
    stk->data = (int*)malloc(23 * sizeof(int));
//    stk->top = -1;
//    stk->capacity = size;
//    stk->min = size;
    stk->top = -1;
}
int StackIsEmpty(Stack *stk)
{
    return (stk->top == -1);
}
int StackSize(Stack *stk)
{
    return (stk->top +1);
}
void StackPrint(Stack *stk)
{
    printf("Stack :: ");
    for (int i=stk->top; i>=0; i--){
        printf("%d ", stk->data[i]);
    }
    printf("\n");
}
void StackPush(Stack *stk, int value)
{
    if (stk->top < MAX_CAPACITY-1){
        stk->top++;
        stk->data[stk->top] = value;
    } else {
        printf("stack overflow\n");
    }
}
int StackPop(Stack *stk)
{
    if (stk->top >= 0){
        int value = stk->data[stk->top];
        stk->top--;
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
void StackPushWithSizeIncrease(Stack *stk, int value)
{
    if (stk->top < stk->capacity-1)
    {
        stk->top++;
        stk->data[stk->top] = value;
        printf("value push : %d \n", value);
    } else {
        stk->capacity = stk->capacity *2;
        stk->data = (int*)realloc(stk->data, stk->capacity * sizeof(int));
        printf("Stack size has been doubled. \n");
        printf("Stack capacity %d\n", stk->capacity);
        StackPush(stk, value);
    }
}

int StackPopWithSizeDecrease(Stack *stk)
{
    if (stk->top >= 0)
    {
        int value = stk->data[stk->top];
        stk->top--;
        if (stk->top < (stk->capacity/2) && stk->capacity > stk->min)
        {
            stk->capacity = stk->capacity/2;
            stk->data = (int*)realloc(stk->data, stk->capacity *sizeof(int));
            printf("Stack size has been reduced by half. \n");
            printf("Stack capacity %d\n", stk->capacity);
        }
        return value;
    } else {
        printf("Stack is empty.\n");
        return -1;
    }
}
typedef struct stackNode_t
{
    int value;
    struct stackNode_t *next;
}StackNode;
void StackPushLinkedList(StackNode **ptrHead, int value)
{
    StackNode *temp = (StackNode*)malloc(sizeof(StackNode));
    if (!temp){
        printf("Memory allocation error");
        return;
    }
    temp->value = value;
    temp->next = *ptrHead;
    *ptrHead = temp;
}
int StackPopLinkedList(StackNode **ptrHead)
{
    StackNode *deleteMe;
    int value;
    if (*ptrHead){
        deleteMe = *ptrHead;
        *ptrHead = deleteMe->next;
        value = deleteMe->value;
        free(deleteMe);
        return value;
    } else {
        printf("Stack is empty. \n");
        return ERROR_VALUE;
    }
}

void sortedInsert(Stack *stk, int element)
{
    int temp;
    if (StackIsEmpty(stk) || element > StackTop(stk))
    {
        StackPush(stk, element);
    } else {
        temp = StackPop(stk);
        sortedInsert(stk, element);
        StackPush(stk, temp);
    }
}

void sortStack(Stack *stk)
{
    int temp;
    if (StackIsEmpty(stk) == 0)
    {
        temp = StackPop(stk);
        sortStack(stk);
        sortedInsert(stk, temp);
    }
}
void sortStack2(Stack *stk)
{
    int temp;
    Stack stk2;
    StackInitialize(&stk2);
    while (StackIsEmpty(stk) == 0)
    {
        temp = StackPop(stk);
        while ((StackIsEmpty(&stk2) == 0) && (StackTop(&stk2) < temp))
        {
            StackPush(stk, StackPop(&stk2));
        }
        StackPush(&stk2, temp);
    }
    while (StackIsEmpty(&stk2) == 0)
    {
        StackPush(stk, StackPop(&stk2));
    }
}

void bottomInsert(Stack *stk, int element)
{
    int temp;
    if (StackIsEmpty(stk))
    {
        StackPush(stk, element);
    } else {
        temp = StackPop(stk);
        bottomInsert(stk, element);
        StackPush(stk, temp);
    }
}

void reverseStack(Stack *stk)
{
    int temp;
    if (StackIsEmpty(stk) == 0)
    {
        temp = StackPop(stk);
        reverseStack(stk);
        bottomInsert(stk, temp);
    }
}
typedef struct queue
{
} Queue;
void QueueInitialize(Queue *que)
{
    
}
int QueueIsEmpty(Queue *que)
{
    return 1;
}
void QueueAdd(Queue *que, int value)
{
    
}
int QueueRemove(Queue *que)
{
    return 1;
}
void reverseStack2(Stack *stk)
{
    Queue que;
    QueueInitialize(&que);
    while(StackIsEmpty(stk) == 0)
    {
        QueueAdd(&que, StackPop(stk));
    }
    while(QueueIsEmpty(&que) == 0)
    {
        StackPush(stk, QueueRemove(&que));
    }
}

void reverseKElementInStack(Stack *stk, int k)
{
    Queue que;
    QueueInitialize(&que);
    int i=0;
    while (StackIsEmpty(stk) == 0 && i<k)
    {
        QueueAdd(&que, StackPop(stk));
        i++;
    }
    while (QueueIsEmpty(&que) == 0)
    {
        StackPush(stk, QueueRemove(&que));
    }
}

void reverseQueue(Queue *que)
{
    Stack stk;
    StackInitialize(&stk);
    while(QueueIsEmpty(que) == 0)
    {
        StackPush(&stk, QueueRemove(que));
    }
    while(StackIsEmpty(&stk) ==0)
    {
        QueueAdd(que, StackPop(&stk));
    }
}

int QueueSize()
{
    return 1;
}
void reverseKElementInQueue(Queue *que, int k)
{
    Stack stk;
    StackInitialize(&stk);
    int i =0, diff, temp;
    while (QueueIsEmpty(que) == 0 && i<k)
    {
        StackPush(&stk, QueueRemove(que));
        i++;
    }
    while (StackIsEmpty(&stk)== 0)
    {
        QueueAdd(que, StackPop(&stk));
    }
    diff = QueueSize(que) -k;
    while (diff > 0)
    {
        temp = QueueRemove(que);
        QueueAdd(que, temp);
        diff -=1;
    }
}

#define MAX_SIZE 10
typedef struct doubleStack
{
    int top1;
    int top2;
    int data[MAX_SIZE];
}DoubleStack;
void DoubleStackInitialize(DoubleStack *stk, int size)
{
    stk->top1 = -1;
    stk->top2 = MAX_SIZE;
}
void StackPush1(DoubleStack *stk, int data)
{
    if (stk->top1 < stk->top2 -1)
    {
        stk->data[++stk->top1] = data;
    } else {
        printf("Stack is full\n");
    }
}
void StackPush2(DoubleStack *stk, int data)
{
    if (stk->top1 < stk->top2-1)
    {
        stk->data[--stk->top2] = data;
    } else {
        printf("Stack is full\n");
    }
}
int StackPop1(DoubleStack *stk)
{
    if (stk->top1 >= 0)
    {
        int value = stk->data[stk->top1--];
        printf("%d is being popped from Stack 1\n", value);
        return value;
    } else {
        printf("Can't pop because stack is empty. \n");
    }
    return ERROR_VALUE;
}
int StackPop2(DoubleStack *stk)
{
    if (stk->top2 < MAX_SIZE)
    {
        int value = stk->data[stk->top2++];
        printf("%d is being popped from Stack 2\n", value);
        return value;
    } else {
        printf("Can't pop because stack is empty. \n");
    }
    return ERROR_VALUE;
}

int isBalancedParenthesis(char *expn, int size)
{
    Stack stk;
    StackInitialize(&stk);
    char ch;
    for (int i=0; i<size;i++)
    {
        ch = expn[i];
        if (ch == '{' || ch == '[' || ch == '('){
            StackPush(&stk, ch);
        } else if (ch == '}'){
            if (StackPop(&stk) != '{'){
                return 0;
            }
        } else if (ch == ']'){
            if (StackPop(&stk) != '['){
                return 0;
            }
        } else if (ch == ')'){
            if (StackPop(&stk) != '('){
                return 0;
            }
        }
    }
    return (StackSize(&stk) == 0);
}

int maxDepthParenthesis(char *expn, int size)
{
    Stack stk;
    StackInitialize(&stk);
    int maxDepth = 0;
    int depth = 0;
    char ch;
    for (int i=0; i<size; i++){
        ch = expn[i];
        if (ch == '('){
            StackPush(&stk, ch);
            depth +=1;
        } else if (ch == ')'){
            StackPop(&stk);
            depth -=1;
        }
        if (depth < maxDepth){
            maxDepth = depth;
        }
    }
    return maxDepth;
}
int maxDepthParenthesis2(char *expn, int size)
{
    int maxDepth = 0;
    int depth = 0;
    char ch;
    for (int i=0; i<size; i++){
        ch = expn[i];
        if (ch == '('){
            depth +=1;
        } else if (ch == ')'){
            depth -=1;
        }
        if (depth > maxDepth){
            maxDepth = depth;
        }
    }
    return maxDepth;
}

int max(int length, int top)
{
    if (length >= top){
        return length;
    } else {
        return top;
    }
}
int longestContBalParen(char *string, int size)
{
    Stack stk;
    StackInitialize(&stk);
    StackPush(&stk, -1);
    int length = 0;
    for (int i=0; i<size; i++){
        if (string[i] == '('){
            StackPush(&stk, i);
        } else {
            StackPop(&stk);
            if (StackSize(&stk) != 0){
                length = max(length, i - StackTop(&stk));
            } else {
                StackPush(&stk, i);
            }
        }
    }
    return length;
}

int reverseParenthesis(char *expn, int size)
{
    Stack stk;
    StackInitialize(&stk);
    int openCount = 0;
    int closeCount = 0;
    char ch;
    
    if (size % 2 == 1)
    {
        printf("Invalid odd length %d\n", size);
        return -1;
    }
    for (int i=0; i<size; i++){
        ch = expn[i];
        if (ch == '('){
            StackPush(&stk, ch);
        } else if (ch == ')'){
            if (StackSize(&stk) != 0 && StackTop(&stk) == '('){
                StackPop(&stk);
            } else {
                StackPush(&stk, ')');
            }
        }
    }
    while (StackSize(&stk) != 0)
    {
        if (StackPop(&stk) == '('){
            openCount +=1;
        } else {
            closeCount +=1;
        }
    }
    int reversal = ceil(openCount / 2.0) + ceil(closeCount /2.0);
    return reversal;
}

int findDuplicateParenthesis(char *expn, int size)
{
    Stack stk;
    StackInitialize(&stk);
    char ch;
    int count;
    
    for (int i=0; i<size; i++)
    {
        ch = expn[i];
        if (ch == ')'){
            count = 0;
            while (StackSize(&stk) != 0 && StackTop(&stk) != '('){
                StackPop(&stk);
                count +=1;
            }
            if (count <= 1){
                return 1;
            }
        } else {
            StackPush(&stk, ch);
        }
    }
    return 0;
}

void pinrtParenthesisNumber(char *expn, int size)
{
    char ch;
    Stack stk;
    StackInitialize(&stk);
    int output[10];
    int outputIndex = 0;
    int count = 1;
    
    for (int i=0; i<size; i++){
        ch = expn[i];
        if (ch == '(') {
            StackPush(&stk, count);
            output[outputIndex++] = count;
            count +=1;
        } else if (ch == ')'){
            output[outputIndex++] = StackPop(&stk);
        }
    }
    printf("Parenehesis number: ");
    for (int i=0; i<outputIndex; i++){
        printf(" %d", output[i]);
    }
}

int precedence(char x)
{
    if (x == '(')
    {
        return 0;
    }
    if (x == '+' || x == '-')
    {
        return 1;
    }
    if (x== '*' || x == '/' || x == '%')
    {
        return 2;
    }
    if (x == '^')
    {
        return 3;
    }
    return 4;
}
void infixToPostfix(char *expn, char *output)
{
    Stack stk;
    StackInitialize(&stk);
    char ch, op;
    int i = 0;
    int index = 0;
    int digit = 0;
    
    while((ch = expn[i++]) != '\0'){
        if (isdigit(ch)){
            output[index++] = ch;
            digit = 1;
        } else {
            if (digit) {
                output[index++] = ' ';
                digit = 0;
            }
            switch (ch) {
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                    while (!StackIsEmpty(&stk) && precedence(ch) <= precedence(StackTop(&stk))){
                        op = StackPop(&stk);
                        output[index++] = op;
                        output[index++] = ' ';
                    }
                    StackPush(&stk, ch);
                    break;
                case '(':
                    StackPush(&stk, ch);
                    break;
                case ')':
                    while(!StackIsEmpty(&stk) && (op = StackPop(&stk)) != '('){
                        output[index++] = op;
                        output[index++] = ' ';
                    }
                    break;
            }
        }
    }
    while (!StackIsEmpty(&stk)){
        op = StackPop(&stk);
        output[index++] = op;
        output[index++] = ' ';
    }
    output[index++] = '\0';
}

void reverseString(char *a)
{
    int lower = 0;
    int upper = strlen(a) -1;
    char tempChar;
    while (lower < upper) {
        tempChar = a[lower];
        a[lower] = a[upper];
        a[upper] = tempChar;
        lower++;
        upper--;
    }
}
void replaceParenthesis(char *a)
{
    int lower = 0;
    int upper = strlen(a) -1;
    while (lower <= upper)
    {
        if (a[lower] == '('){
            a[lower] = ')';
        } else if (a[lower] == ')'){
            a[lower] ='(';
        }
        lower++;
    }
}
void infixToPrefix(char *expn, char *output)
{
    reverseString(expn);
    replaceParenthesis(expn);
    infixToPostfix(expn, output);
    reverseString(output);
}

int postfixEvaluete(char *postfix)
{
    Stack s;
    StackInitialize(&s);
    int i = 0, op1, op2;
    char ch;
    int digit = 0;
    int value = 0;
    
    while ((ch = postfix[i++]) != '\0')
    {
        if (isdigit(ch)){
            digit = 1;
            value = value *10 + (ch -'0');
        } else if (ch == ' '){
            if (digit == 1){
                StackPush(&s, value);
                digit = 0;
                value = 0;
            }
        } else {
            op2 = StackPop(&s);
            op1 = StackPop(&s);
            switch (ch) {
                case '+':
                    StackPush(&s, op1 + op2);
                    break;
                case '-':
                    StackPush(&s, op1 - op2);
                    break;
                case '*':
                    StackPush(&s, op1 * op2);
                    break;
                case '/':
                    StackPush(&s, op1 / op2);
                    break;
            }
        }
    }
    return StackTop(&s);
}

int *StockSpanRange(int arr[], int size)
{
    int *SR = (int*)malloc(sizeof(int) * size);
    SR[0] = 1;
    int i = 1;
    int j;
    while (i < size){
        SR[i] = 1;
        j = i-1;
        while((j >= 0) && (arr[i] >= arr[j])){
            SR[i] += 1;
            j -= 1;
        }
        i += 1;
    }
    return SR;
}
int *StockSpanRange2(int *arr, int size)
{
    Stack stk;
    StackInitialize(&stk);
    int *SR = (int*)malloc(sizeof(int) * size);
    StackPush(&stk, 0);
    SR[0] = 1;
    int i = 1;
    
    while(i < size) {
        while (StackSize(&stk) != 0 && arr[StackTop(&stk)] <= arr[i]){
            StackPop(&stk);
        }
        if (StackSize(&stk) == 0){
            SR[i] = i + 1;
        } else {
            SR[i] = i - StackTop(&stk);
        }
        StackPush(&stk, i);
        i += 1;
    }
    return SR;
}

int GetMaxArea(int arr[], int size)
{
    int maxArea = -1;
    int minHeight = 0;
    int i = 1;
    int j;
    int currArea;
    
    while (i < size)
    {
        minHeight = arr[i];
        j = i-1;
        while (j >= 0)
        {
            if (minHeight > arr[j]){
                minHeight = arr[j];
            }
            currArea = minHeight * (i - j +1);
            if (maxArea < currArea){
                maxArea = currArea;
            }
            j -= 1;
        }
        i +=1;
    }
    return maxArea;
}
int GetMaxArea2(int arr[], int size)
{
    Stack stk;
    StackInitialize(&stk);
    int maxArea = 0;
    int i = 0;
    int top, topArea;
    
    while (i < size)
    {
        while ((i < size) && (StackSize(&stk) == 0 || arr[StackTop(&stk)] <= arr[i]))
        {
            StackPush(&stk, i);
            i += 1;
        }
        while (StackSize(&stk) != 0 && (i == size || arr[StackTop(&stk)] > arr[i]))
        {
            top = StackTop(&stk);
            StackPop(&stk);
            if (StackSize(&stk) == 0){
                topArea = arr[top] * i;
            } else {
                topArea = arr[top] * (i - StackTop(&stk) - 1);
            }
            if (maxArea < topArea)
                maxArea = topArea;
        }
    }
    return maxArea;
}

void nextLargestElement(int arr[], int size)
{
    int *output = (int*)malloc(sizeof(int) * size);
    int outIndex = 0;
    int next = -1;
    
    for (int i=0; i<size; i++){
        for (int j= i+1; j<size; j++){
            if (arr[i] < arr[j]){
                next = arr[j];
                break;
            }
        }
        output[outIndex++] = next;
    }
    //printfArray(output, outIndex);
}
void nextLargestElement2(int arr[], int size)
{
    Stack stk;
    StackInitialize(&stk);
    int *output = (int*)malloc(sizeof(int) * size);
    int index = 0;
    int curr;
    
    for (int i=0; i<size; i++){
        curr = arr[i];
        while(StackIsEmpty(&stk) == 0 && arr[StackTop(&stk)] <= curr){
            index = StackPop(&stk);
            output[index] = curr;
        }
        StackPush(&stk, i);
    }
    while(StackIsEmpty(&stk) == 0)
    {
        index = StackPop(&stk);
        output[index] = -1;
    }
}

void nextSmallestElemeent(int arr[], int size)
{
    Stack stk;
    StackInitialize(&stk);
    int *output = (int*)malloc(sizeof(int) * size);
    int curr, index;
    
    for (int i=0; i<size; i++){
        curr = arr[i];
        while (StackIsEmpty(&stk) == 0 && arr[StackTop(&stk)] > curr){
            index = StackPop(&stk);
            output[index] = curr;
        }
        StackPush(&stk, i);
    }
    while (StackIsEmpty(&stk) == 1){
        index = StackPop(&stk);
        output[index] = -1;
    }
}

void nextLargestElementCircular(int arr[], int size)
{
    Stack stk;
    int curr, index;
    StackInitialize(&stk);
    int *output = (int*)malloc(sizeof(int) * size);
    
    for (int i=0; i<size; i++){
        curr = arr[i % size];
        while (StackIsEmpty(&stk) == 0 && arr[StackTop(&stk)] <= curr)
        {
            index = StackPop(&stk);
            output[index] = curr;
        }
        StackPush(&stk, i);
    }
    while (StackIsEmpty(&stk) == 0)
    {
        index = StackPop(&stk);
        output[index] = -1;
    }
}

int infi = 999999;
void RottenFruitUtil(int arr[][5], int maxCol, int maxRow, int currCol, int currRow, int **traversed, int day)
{
    if (currCol < 0 || currCol >= maxCol || currRow < 0 || currRow >= maxRow)
        return;
    
    if (traversed[currCol][currRow] <= day || arr[currCol][currRow] == 0)
        return;
    
    traversed[currCol][currRow] = day;
    
    RottenFruitUtil(arr, maxCol, maxRow, currCol-1, currRow, traversed, day +1);
    RottenFruitUtil(arr, maxCol, maxRow, currCol+1, currRow, traversed, day +1);
    RottenFruitUtil(arr, maxCol, maxRow, currCol, currRow+1, traversed, day +1);
    RottenFruitUtil(arr, maxCol, maxRow, currCol-1, currRow-1, traversed, day +1);
}
int RottenFruit(int arr[][5], int maxCol, int maxRow)
{
    int **traversed;
    traversed = (int*)malloc(maxCol * sizeof(int*));
    
    for (int i=0; i<maxCol; i++){
        traversed[i] = (int*)malloc(maxRow * sizeof(int));
        for (int j=0; j<maxRow; j++){
            traversed[i][j] = infi;
        }
    }
    for (int i=0; i<maxCol; i++){
        for (int j=0; j<maxRow; j++){
            if (arr[i][j] == 2){
                RottenFruitUtil(arr, maxCol, maxRow, i, j, traversed, 0);
            }
        }
    }
    int maxDay = 0;
    for (int i=0; i<maxCol; i++){
        for (int j=0; j<maxRow; j++){
            if (arr[i][j] == 1){
                if (traversed[i][j] == infi){
                    return -1;
                }
                if (maxDay < traversed[i][j]){
                    maxDay = traversed[i][j];
                }
            }
        }
    }
    for (int i=0; i<maxCol; i++){
        free(traversed[i]);
    }
    free(traversed);
    return maxDay;
}

void StepsOfKnightUtil(int size, int currCol, int currRow, int **traversed, int dist)
{
    if (currCol < 0 || currCol >= size || currRow < 0 || currRow >= size){
        return;
    }
    if (traversed[currCol][currRow] <= dist){
        return;
    }
    traversed[currCol][currRow] = dist;
    
    StepsOfKnightUtil(size, currCol-2, currRow-1, traversed, dist+1);
    StepsOfKnightUtil(size, currCol-2, currRow+1, traversed, dist+1);
    StepsOfKnightUtil(size, currCol+2, currRow-1, traversed, dist+1);
    StepsOfKnightUtil(size, currCol+2, currRow+1, traversed, dist+1);
    StepsOfKnightUtil(size, currCol-1, currRow-2, traversed, dist+1);
    StepsOfKnightUtil(size, currCol+1, currRow-2, traversed, dist+1);
    StepsOfKnightUtil(size, currCol-1, currRow+2, traversed, dist+1);
    StepsOfKnightUtil(size, currCol+1, currRow+2, traversed, dist+1);
}
int StepsOfKnight(int size, int srcX, int srcY, int dstX, int dstY)
{
    int **traversed;
    traversed = (int**)malloc(size * sizeof(int*));
    
    for (int i=0; i<size; i++){
        traversed[i] = (int*)malloc(size * sizeof(int));
        for (int j=0; j<size; j++){
            traversed[i][j] = infi;
        }
    }
    StepsOfKnightUtil(size, srcX-1, srcY-1, traversed, 0);
    int retval = traversed[dstX-1][dstY-1];
    
    for (int i=0; i<size; i++){
        free(traversed[i]);
    }
    free(traversed);
    
    return retval;
}

void DistNearestFillUtil(int arr[][5], int maxCol, int maxRow, int currCol, int currRow, int **traversed, int dist)
{
    if (currCol < 0 || currCol >=maxCol || currRow < 0 || currRow >= maxRow){
        return;
    }
    if (traversed[currCol][currRow] <= dist){
        return;
    }
    traversed[currCol][currRow] = dist;
    
    DistNearestFillUtil(arr, maxCol, maxRow, currCol-1, currRow, traversed, dist+1);
    DistNearestFillUtil(arr, maxCol, maxRow, currCol+1, currRow, traversed, dist+1);
    DistNearestFillUtil(arr, maxCol, maxRow, currCol, currRow+1, traversed, dist+1);
    DistNearestFillUtil(arr, maxCol, maxRow, currCol, currRow-1, traversed, dist+1);
}
void DistNearestFill(int arr[][5], int maxCol, int maxRow)
{
    int **traversed;
    traversed = (int**)malloc(maxCol * sizeof(int*));
    
    for (int i=0; i<maxCol; i++)
    {
        traversed[i] = (int*)malloc(maxRow * sizeof(int));
        for (int j=0; j<maxRow; j++){
            traversed[i][j] = infi;
        }
    }
    for (int i=0; i<maxCol; i++){
        for (int j=0; j<maxRow; j++){
            if (arr[i][j] == 1){
                DistNearestFillUtil(arr, maxCol, maxRow, i, j, traversed, 0);
            }
        }
    }
    for (int i=0; i<maxCol; i++){
        for (int j=0; j<maxRow; j++){
            printf("%d, ", traversed[i][j]);
        }
        printf("\n");
    }
    for (int i=0; i<maxCol; i++){
        free(traversed[i]);
    }
    free(traversed);
}

int findLargestIslandUtil(int arr[][5], int maxCol, int maxRow, int currCol, int currRow, int value, int **traversed)
{
    if (currCol < 0 || currCol >= maxCol || currRow < 0 || currRow >= maxRow)
        return 0;
    
    if (traversed[currCol][currRow] == 1 || arr[currCol][currRow] != value)
        return 0;
    
    traversed[currCol][currRow] = 1;
    
    return 1 + findLargestIslandUtil(arr, maxCol, maxRow, currCol-1, currRow-1, value, traversed) +
            findLargestIslandUtil(arr, maxCol, maxRow, currCol-1, currRow, value, traversed) +
            findLargestIslandUtil(arr, maxCol, maxRow, currCol-1, currRow+1, value, traversed) +
            findLargestIslandUtil(arr, maxCol, maxRow, currCol, currRow-1, value, traversed) +
            findLargestIslandUtil(arr, maxCol, maxRow, currCol, currRow+1, value, traversed) +
            findLargestIslandUtil(arr, maxCol, maxRow, currCol+1, currRow-1, value, traversed) +
            findLargestIslandUtil(arr, maxCol, maxRow, currCol+1, currRow, value, traversed) +
            findLargestIslandUtil(arr, maxCol, maxRow, currCol+1, currRow+1, value, traversed);
}
int findLargestIsland(int arr[][5], int maxCol, int maxRow)
{
    int maxVal = 0;
    int currVal = 0;
    int **traversed;
    traversed = (int**)malloc(maxCol * sizeof(int*));
    
    for (int i=0; i<maxCol; i++){
        traversed[i] = (int*)malloc(maxRow * sizeof(int));
        for (int j=0; j<maxRow; j++){
            traversed[i][j] = infi;
        }
    }
    for (int i=0; i<maxCol; i++){
        for (int j=0; j<maxRow; j++){
            currVal = findLargestIslandUtil(arr, maxCol, maxRow, i, j, arr[i][j], traversed);
            if (currVal > maxVal){
                maxVal = currVal;
            }
        }
        break;
    }
    for (int i=0; i<maxCol; i++){
        free(traversed[i]);
    }
    free(traversed);
    return maxVal;
}

int isKnown(int relation[][5], int a, int b)
{
    if (relation[a][b] == 1){
        return 1;
    }
    return 0;
}
int findCelebrity(int relation[][5], int count)
{
    Stack stk;
    StackInitialize(&stk);
    int first = 0, second = 0;
    
    for (int i=0; i<count; i++){
        StackPush(&stk, i);
    }
    first = StackPop(&stk);
    
    while (StackSize(&stk) != 0){
        second = StackPop(&stk);
        if (isKnown(relation, first, second)) {
            first = second;
        }
    }
    for (int i=0; i<count; i++){
        if (first != i && isKnown(relation, first, i)){
            return -1;
        }
        if (first != i && isKnown(relation, i, first) == 0){
            return -1;
        }
    }
    return first;
}
int findCelebrity2(int relation[][5], int count)
{
    int first = 0;
    int second = 0;
    
    for (int i=0; i<(count-1); i++){
        if (isKnown(relation, first, second)){
            first = second;
        }
        second = second + 1;
    }
    for (int i=0; i<count; i++){
        if (first != i && isKnown(relation, first, i)){
            return -1;
        }
        if (first != i && isKnown(relation, i, first) == 0){
            return -1;
        }
    }
    return first;
}

int main() {
    Stack stk;
    StackInitialize(&stk);
    StackPush(&stk, 3);
    StackPush(&stk, 1);
    StackPush(&stk, 5);
    StackPush(&stk, 2);
    StackPush(&stk, 4);
//    sortStack2(&stk);
//    StackPrint(&stk);
//    char *expn = "())((()))(())()(()";
//    int size = strlen(expn);
//    int value = longestContBalParen(expn, size);
//    printf("Longest balanced parenthesis length: %d \n", value);
//    char *expn = "())((()))(())()(()()()()))";
//    char *expn2 = ")(())(((";
//    int size = strlen(expn2);
//    int value = reverseParenthesis(expn, size);
//    printf("Given iquation: %s \n", expn);
//    printf("The number of parenthesis reverse: %d \n", value);
//    char *expn = "(((a + b)) + c)";
//    printf("Given equation: %s \n", expn);
//    int size = strlen(expn);
//    int value = findDuplicateParenthesis(expn, size);
//    printf("Duplicatee parenthesis: %d\n", value);
//    char expn[] = "10 + ((3)) * 5 / (16 - 4)";
//    char out[100];
//    infixToPostfix(expn, out);
//    printf("Infix: %s \n", expn);
//    printf("Postfix: %s \n", out);
//    char expn[] = "10 + ((3)) * 5 / ( 16 - 4 )";
//    char out [100];
//    infixToPostfix(expn, out);
//    printf("Infix: %s \n", expn);
//    printf("Postfix: %s \n", out);
//    char expn[] = "10 + ((3)) * 5 / (16 - 4)";
//    char out[100];
//    printf("Infix: %s \n", expn);
//    infixToPrefix(expn, out);
//    printf("Postfix: %s \n", out);
    char expn[] = "6 5 2 3 + 8 * + 3 + *";
    int value = postfixEvaluete(expn);
    printf("Given postfix: %s \n", expn);
    printf("Result: %d \n", value);
    
    return 0;
}
