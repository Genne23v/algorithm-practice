//
//  main.c
//  Algorithm-9
//
//  Created by Wonkeun No on 2021-02-17.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct tNode
{
    int value;
    struct tNode *lChild;
    struct tNode *rChild;
}treeNode;

#define MAX_CAPACITY_STK 50
#define ERROR_VALUE_STK -999

typedef struct stack
{
    int top;
    int data[MAX_CAPACITY_STK];
}Stack;

void StackInitialize(Stack *stk)
{
    stk->top = -1;
}
void StackPush(Stack *stk, int value)
{
    if (stk->top < MAX_CAPACITY_STK -1)
    {
        stk->top++;
        stk->data[stk->top] = value;
    } else {
        printf("stack overflow\n");
    }
}
int StackPop(Stack *stk)
{
    if (stk->top >= 0)
    {
        stk->top--;
        int value = stk->data[stk->top];
        return value;
    }
    printf("stack empty\n");
    return ERROR_VALUE_STK;
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
    return (stk->top+1);
}
treeNode *insertNode(treeNode *root, int value)
{
    if (root == NULL)
    {
        root = (treeNode*)malloc(sizeof(treeNode));
        if (root == NULL)
        {
            printf("fallel memory shortage...");
            return root;
        }
        root->value = value;
        root->lChild = root->rChild = NULL;
    } else {
        if (root->value >= value)
        {
            root->lChild = insertNode(root->lChild, value);
        } else {
            root->rChild = insertNode(root->rChild, value);
        }
    }
    return root;
}
treeNode* deleteNode(treeNode* root, int value)
{
    if (root == NULL)
        return NULL;

    treeNode* cur = root;
    treeNode* target = NULL; // value와 일치하는 노드의 포인터
    treeNode* parent = NULL;

    if (root->value == value) {
        target = root;
    }
    else {
        Stack stk;
        StackInitialize(&stk);
        StackPush(&stk, (int)cur);

        while (StackSize(&stk) > 0) {
            cur = (treeNode*)StackPop(&stk);
            treeNode* left = cur->lChild;
            treeNode* right = cur->rChild;

            parent = cur;
            if (left) {
                if (left->value == value) {
                    target = left;
                    break;
                }
                StackPush(&stk, (int)left);
            }
            if (right) {
                if (right->value == value)
                {
                    target = left;
                    break;
                }
                StackPush(&stk, (int)right);
            }

        }
    }

    if (target) {
        // 타깃 아래에 있는 말단 노드를 찾아 삭제하려는 노드로 대치하고
        // 말단 노드를 삭제합니다.
        cur = target;
        treeNode* leaf = NULL;

        Stack stk;
        StackInitialize(&stk);
        StackPush(&stk, (int)cur);

        treeNode* left = cur->lChild;
        treeNode* right = cur->rChild;

        // 타깃이 말단이면
        if (!left && !right) {
            // 타깃이 동시에 루트라면 NULL 값을 반환해야 합니다.
            if (target == root) {
                root = NULL;
            }
            if (target == parent->lChild) {
                free(parent->lChild);
                parent->lChild = NULL;
            }
            else {
                free(parent->rChild);
                parent->rChild = NULL;
            }
            return root;
        }

        while (StackSize(&stk) > 0)    {
            cur = (treeNode*)StackPop(&stk);
            left = cur->lChild;
            right = cur->rChild;
            if (left) {
                if (!left->lChild && !left->rChild) {
                    leaf = left;
                    // 왼쪽 자식을 잘라냅니다.
                    cur->lChild = NULL;
                    break;
                }
                StackPush(&stk, (int)left);
            }
            if (right) {
                if (!right->lChild && !right->rChild) {
                    leaf = right;
                    // 오른쪽 자식을 잘라냅니다.
                    cur->rChild = NULL;
                    break;
                }
                StackPush(&stk, (int)right);
            }
        }
        // 타깃의 값을 말단 노드의 값으로 대치합니다.
        target->value = leaf->value;
        free(leaf);
    }

    return root;
}

void printtDepthFirst(treeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    treeNode *curr = root;
    
    while(curr)
    {
        printf("%d", curr->value);
        if (curr->lChild){
            if (curr->rChild){
                treeNode *rightBottomMost = curr->lChild;
                while (rightBottomMost->rChild || rightBottomMost->lChild)
                {
                    if (rightBottomMost->rChild)
                    {
                        rightBottomMost = rightBottomMost->rChild;
                    } else {
                        rightBottomMost = rightBottomMost->lChild;
                    }
                }
                rightBottomMost->lChild = curr->rChild;
            }
            curr = curr->lChild;
        } else {
            curr = curr->rChild;
        }
    }
}

#define MAX_CAPACITY 100
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
        printf("\n Queue is full.");
        return;
    }
    else
    {
        que->size++;
        que->data[que->back] = value;
        que->back = (que->back +1) % (MAX_CAPACITY -1);
    }
}
int QueueRemove(Queue *que)
{
    int value;
    if (que->size <= 0)
    {
        printf("\n Queue is empty.");
        return ERROR_VALUE;
    }
    else
    {
        que->size--;
        value = que->data[que->front];
        que->front = (que->front +1) % (MAX_CAPACITY -1);
    }
    return value;
}
int QueueIsEmpty(Queue *que)
{
    return que->size == 0;
}
int isCompleteBT(treeNode *root)
{
    if (root == NULL)
    {
        return 1;
    }
    Queue que;
    QueueInitialize(&que);
    
    treeNode *curr = root;
    QueueAdd(&que, (int)curr);
    
    int visitNotFull = 0;
    
    while (!QueueIsEmpty(&que))
    {
        curr = (treeNode*)QueueRemove(&que);
        if (curr->lChild)
        {
            if (visitNotFull)
                return 0;
            QueueAdd(&que, (int)curr->lChild);
        }
        else
        {
            visitNotFull = 1;
        }
        if (curr->rChild)
        {
            if (visitNotFull)
                return 0;
            QueueAdd(&que, (int)curr->rChild);
        }
        else
        {
            visitNotFull = 1;
        }
    }
    return 1;
}

int isFullBT(treeNode *root)
{
    if (root == NULL)
        return 1;
    
    Queue que;
    QueueInitialize(&que);
    
    treeNode *curr = root;
    QueueAdd(&que, (int)curr);
    
    while (!QueueIsEmpty(&que))
    {
        curr = (treeNode*)QueueRemove(&que);
        treeNode *left = curr->lChild;
        treeNode *right = curr->rChild;
        if (!left && !right)
            continue;
        if ((!left && right) || (left && !right))
            return 0;
        QueueAdd(&que, (int)left);
        QueueAdd(&que, (int)right);
    }
    return 1;
}

int isPerfectBT(treeNode *root)
{
    if (root == NULL)
        return 1;
    
    Queue que;
    QueueInitialize(&que);
    
    treeNode *curr = root;
    QueueAdd(&que, (int)curr);
    
    int visitNotFull = 0;
    
    while (!QueueIsEmpty(&que))
    {
        curr = (treeNode*)QueueRemove(&que);
        treeNode *left = curr->lChild;
        treeNode *right = curr->rChild;
        
        if ((!left && right) || (left && !right))
            return 0;
        if (left){
            if (visitNotFull)
                return 0;
            QueueAdd(&que, (int)left);
        } else {
            visitNotFull = 1;
        }
        if (right){
            if (visitNotFull)
                return 0;
            QueueAdd(&que, (int)right);
        } else {
            visitNotFull = 1;
        }
    }
    return 1;
}

int treeDepth(treeNode *root)
{
    if (!root){
        return 0;
    }
    else {
        int lDepth = treeDepth(root->lChild);
        int rDepth = treeDepth(root->rChild);
        
        if (lDepth > rDepth){
            return lDepth +1;
        } else {
            return rDepth +1;
        }
    }
}
int isHeightBal(treeNode *root)
{
    if (root == NULL)
        return 1;
    
    int hL = treeDepth(root->lChild);
    int hR = treeDepth(root->rChild);
    
    if (abs(hL-hR) <= 1 && isHeightBal(root->lChild) && isHeightBal(root->rChild))
        return 1;
    
    return 0;
}

int isIsomorphic(treeNode *t1, treeNode* t2)
{
    if (!t1 && !t2)
        return 1;
    if (!t1 || !t2)
        return 0;
    
    return isIsomorphic(t1->lChild, t2->lChild) && isIsomorphic(t1->rChild, t2->rChild);
}

void printDepthFirstStack(treeNode *root)
{
    if (root == NULL)
        return;
    
    Stack stk;
    StackInitialize(&stk);
    treeNode *curr = root;
    StackPush(&stk, (int)curr);
    
    while(StackSize(&stk) > 0)
    {
        curr = (treeNode*)StackPop(&stk);
        printf("%d\n", curr->value);
        
        if (curr->rChild){
            StackPush(&stk, (int)curr->rChild);
        }
        if (curr->lChild){
            StackPush(&stk, (int)curr->lChild);
        }
    }
}

void printZigzag(treeNode *root)
{
    if (!root)
        return;
    
    Stack *curr = (Stack*)malloc(sizeof(Stack));
    Stack *next = (Stack*)malloc(sizeof(Stack));
    
    StackInitialize(&curr);
    StackInitialize(&next);
    StackPush(curr, (int)root);
    
    int way = 1;
    while(!StackIsEmpty(&curr))
    {
        treeNode *node = (treeNode*)StackPop(curr);
        if (node)
        {
            printf("%d\n", node->value);
            if (way){
                if (node->lChild){
                    StackPush(next, (int)node->lChild);
                }
                if (node->rChild){
                    StackPush(next, (int)node->rChild);
                }
            }
        }
        if (StackIsEmpty(curr))
        {
            way = !way;
        }
        Stack *temp = curr;
        curr = next;
        next = temp;
    }
    free(curr);
    free(next);
}

int counter = 0;
treeNode* findNthSmall(treeNode *root, int n)
{
    if (!root)
        return NULL;
    treeNode *left = findNthSmall(root->lChild, n);
    if (left)
        return left;
    if (++counter == n)
        return root;
    return findNthSmall(root->rChild, n);
}

int main(int argc, const char * argv[]) {

    treeNode* root = NULL;
    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 3);
    root = deleteNode(root, 2);
    return 0;
}
