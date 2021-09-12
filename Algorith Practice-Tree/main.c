//
//  main.c
//  Algorith Practice-Tree
//
//  Created by Wonkeun No on 2021-02-10.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct tNode
{
    int value;
    struct tNode *lChild;
    struct tNode *rChild;
}treeNode;
treeNode *levelOrderBinaryTreeUtil(int arr[], int size, int start)
{
    treeNode *curr = (treeNode*)malloc(sizeof(treeNode));
    curr->value = arr[start];
    curr->lChild = curr->rChild = NULL;
    int left = 2 * start +1;
    int right = 2 * start +2;
    if (left < size){
        curr->lChild = levelOrderBinaryTreeUtil(arr, size, left);
    }
    if (right < size){
        curr->rChild = levelOrderBinaryTreeUtil(arr, size, right);
    }
    return curr;
}
treeNode *levelOrderBinaryTree(int arr[], int size)
{
    return levelOrderBinaryTreeUtil(arr, size, 0);
}

void printPreOrder(treeNode *root)
{
    if (root)
    {
        printf(" %d ", root->value);
        printPreOrder(root->lChild);
        printPreOrder(root->rChild);
    }
}

void printPostOrder(treeNode *root)
{
    if (root)
    {
        printPostOrder(root->lChild);
        printPostOrder(root->rChild);
        printf(" %d ", root->value);
    }
}

void printInOrder(treeNode *root)
{
    if (root)
    {
        printInOrder(root->lChild);
        printf(" %d ", root->value);
        printInOrder(root->rChild);
    }
}

typedef struct queue_t
{
    
}Queue;
void QueueInitialize(Queue *que)
{
    
}
void QueueAdd(Queue *que, int value)
{
    
}
int QueueRemove(Queue *que)
{
    return 1;
}
int QueueSize(Queue *que)
{
    return 1;
}
void PrintBredthFirst(treeNode *root)
{
    Queue que;
    QueueInitialize(&que);
    treeNode *temp = NULL;
    if (root != NULL){
        QueueAdd(&que, (int)root);
    }
    while (QueueSize(&que) != 0){
        temp = (treeNode*)QueueRemove(&que);
        printf("%d ", temp->value);
        if (temp->lChild != NULL){
            QueueAdd(&que, (int)temp->lChild);
        }
        if (temp->rChild != NULL){
            QueueAdd(&que, (int)temp->rChild);
        }
    }
}

typedef struct stack_t
{
    
}Stack;
void StackInitialize(Stack *stk)
{
    
}
void StackPush(Stack *stk, int value)
{
    
}
int StackSize(Stack *stk)
{
    return 1;
}
int StackPop(Stack *stk)
{
    return 1;
}
void PrintDepthFirst(treeNode *root)
{
    Stack stk;
    StackInitialize(&stk);
    treeNode *temp = NULL;
    if (root != NULL){
        StackPush(&stk, (int)root);
    }
    while (StackSize(&stk) != 0)
    {
        temp = (treeNode*)StackPop(&stk);
        printf("%d ", temp->value);
        
        if (temp->rChild != NULL){
            StackPush(&stk, (int)temp->rChild);
        }
        if (temp->lChild != NULL){
            StackPush(&stk, (int)temp->lChild);
        }
    }
}

void PrintLevelOrderLineByLine(treeNode *root)
{
    Queue que1;
    QueueInitialize(&que1);
    Queue que2;
    QueueInitialize(&que2);
    treeNode *temp = NULL;
    
    if (root != NULL)
    {
        QueueAdd(&que1, (int)root);
    }
    while (QueueSize(&que1) != 0 || QueueSize(&que2) != 0)
    {
        while (QueueSize(&que1) != 0)
        {
            temp = (treeNode*)QueueRemove(&que1);
            printf("%d ", temp->value);
            if (temp->lChild != NULL){
                QueueAdd(&que2, (int)temp->lChild);
            }
            if (temp->rChild != NULL){
                QueueAdd(&que2, (int)temp->rChild);
            }
        }
        printf("\n");
        while (QueueSize(&que2) != 0)
        {
            temp = (treeNode*)QueueRemove(&que2);
            printf("%d ", temp->value);
            if (temp->lChild != NULL){
                QueueAdd(&que1, (int)temp->lChild);
            }
            if (temp->rChild != NULL){
                QueueAdd(&que1, (int)temp->rChild);
            }
            
        }
        printf("\n");
    }
}

void PrintLevelOrderLineByLine2(treeNode *root)
{
    Queue que;
    QueueInitialize(&que);
    treeNode *temp = NULL;
    int count;
    if (root != NULL){
        QueueAdd(&que, (int)root);
    }
    while (QueueSize(&que) != 0)
    {
        count = QueueSize(&que);
        while (count > 0)
        {
            temp = (treeNode*)QueueRemove(&que);
            printf("%d ", temp->value);
            if (temp->lChild != NULL){
                QueueAdd(&que, (int)temp->lChild);
            }
            if (temp->rChild != NULL){
                QueueAdd(&que, (int)temp->rChild);
            }
            count -1;
        }
        printf("\n");
    }
}

void PrintSpiralTree(treeNode *root)
{
    Stack stk1;
    StackInitialize(&stk1);
    Stack stk2;
    StackInitialize(&stk2);
    treeNode *temp = NULL;
    
    if (root != NULL){
        StackPush(&stk1, (int)root);
    }
    
    while (StackSize(&stk1) != 0 || StackSize(&stk2) != 0)
    {
        while (StackSize(&stk1) != 0)
        {
            temp = (treeNode*)StackPop(&stk1);
            printf("%d ", temp->value);
            if (temp->rChild != NULL){
                StackPush(&stk2, (int)temp->rChild);
            }
            if (temp->lChild != NULL){
                StackPush(&stk2, (int)temp->lChild);
            }
        }
        while (StackSize(&stk2) != 0)
        {
            temp = (treeNode*)StackPop(&stk2);
            printf("%d ", temp->value);
            if (temp->lChild != NULL){
                StackPush(&stk1, (int)temp->lChild);
            }
            if (temp->rChild != NULL){
                StackPush(&stk1, (int)temp->rChild);
            }
        }
    }
}

treeNode *NthPreOrder(treeNode *root, int index)
{
    static int count = 0;
    treeNode *temp = NULL;
    
    if (root){
        count++;
        if (count == index){
            printf(" %d ", root->value);
            return root;
        }
        temp = NthPreOrder(root->lChild, index);
        if (temp){
            return temp;
        }
        temp = NthPreOrder(root->rChild, index);
        if (temp){
            return temp;
        }
    }
    return NULL;
}

treeNode *NthPostOrder(treeNode *root, int index)
{
    static int count = 0;
    treeNode *temp = NULL;
    
    if (root){
        temp = NthPostOrder(root->lChild, index);
        if (temp){
            return temp;
        }
        temp = NthPostOrder(root->rChild, index);
        if (temp){
            return temp;
        }
        count++;
        if (count == index){
            printf(" %d ", root->value);
            return root;
        }
    }
    return NULL;
}

treeNode *NthInOrder(treeNode *root, int index)
{
    static int count = 0;
    treeNode *temp = NULL;
    if (root){
        temp = NthInOrder(root->lChild, index);
        if (temp){
            return temp;
        }
        count++;
        if (count == index){
            printf(" %d ", root->value);
            return root;
        }
        temp = NthInOrder(root->rChild, index);
        if (temp){
            return temp;
        }
    }
    return NULL;
}

void StackPrint(Stack *stk)
{
    
}
void printAllPathUtil(treeNode *curr, Stack *stk)
{
    if (curr == NULL){
        return;
    }
    StackPush(stk, curr->value);
    if (curr->lChild == NULL && curr->rChild == NULL){
        StackPrint(stk);
        StackPop(stk);
        return;
    }
    printAllPathUtil(curr->rChild, stk);
    printAllPathUtil(curr->lChild, stk);
    StackPop(stk);
}
void printAllPath(treeNode *root)
{
    Stack *stk;
    StackInitialize(&stk);
    printAllPathUtil(root, stk);
}

int numNodes(treeNode *root)
{
    if (!root){
        return 0;
    }else {
        return (1 + numNodes(root->rChild) + numNodes(root->lChild));
    }
}

int sumAllBT(treeNode *root)
{
    if (root == NULL){
        return 0;
    }
    return root->value + sumAllBT(root->lChild) + sumAllBT(root->rChild);
}

int numLeafs(treeNode *root)
{
    if (!root)
        return 0;
    
    if (!root->lChild && !root->rChild)
        return 1;
    else
        return (numLeafs(root->lChild) + numLeafs(root->rChild));
}

int numFullNodesBT(treeNode *root)
{
    int count = 0;
    int left, right;
    if (root == NULL) {
        return 0;
    }
    left = numFullNodesBT(root->lChild);
    right = numFullNodesBT(root->rChild);
    count = left + right;
    if (root->lChild && root->rChild)
        count++;
    
    return count;
}

int searchBT(treeNode *root, int value)
{
    int left, right;
    if (root == NULL){
        return 0;
    }
    if (root->value == value){
        return 1;
    }
    left = searchBT(root->lChild, value);
    if (left){
        return 1;
    }
    right = searchBT(root->rChild, value);
    if (right){
        return 1;
    }
    return 0;
}

#define INT_MIN -999
int findMaxBT(treeNode *root)
{
    int max;
    int left, right;
    if (root == NULL)
        return INT_MIN;
    
    max = root->value;
    left = findMaxBT(root->lChild);
    right = findMaxBT(root->rChild);
    if (left > max){
        max = left;
    }
    if (right > max){
        max = right;
    }
    return max;
}

int treeDepth(treeNode *root)
{
    if (!root)
        return 0;
    else {
        int lDepth = treeDepth(root->lChild);
        int rDepth = treeDepth(root->rChild);
        if (lDepth > rDepth)
            return lDepth + 1;
        else
            return rDepth + 1;
    }
}

int maxDepthBT(treeNode *node)
{
    if (!node)
        return 0;
    
    int ans = maxDepthBT(node->lChild);
    int right = maxDepthBT(node->rChild);
    if (ans < right)
        ans = right;
    
    return ans + 1;
}
int maxLengthPathBT(treeNode *root)
{
    int max;
    int leftPath, rightPath;
    int leftMax, rightMax;
    if (root == NULL)
        return 0;
    
    leftPath = maxDepthBT(root->lChild);
    rightPath = maxDepthBT(root->rChild);
    max = leftPath + rightPath + 1;
    leftMax = maxLengthPathBT(root->lChild);
    rightMax = maxLengthPathBT(root->rChild);
    if (leftMax > max)
        max = leftMax;
    if (rightMax > max)
        max = rightMax;
    
    return max;
}

treeNode *LcaBT(treeNode *root, treeNode *firstPtr, treeNode *secondPtr)
{
    treeNode *left, *right;
    if (root == NULL){
        return NULL;
    }
    if (root == firstPtr || root == secondPtr){
        return root;
    }
    left = LcaBT(root->lChild, firstPtr,secondPtr);
    right = LcaBT(root->rChild, firstPtr, secondPtr);
    if (left && right){
        return root;
    } else if (left) {
        return left;
    } else {
        return right;
    }
}

int isIdentical(treeNode *root1, treeNode *root2)
{
    if (!root1 && !root2){
        return 1;
    } else if (!root1 || !root2){
        return 0;
    } else {
        return ((isIdentical(root1->lChild, root2->lChild) && isIdentical(root1->rChild, root2->rChild)) && (root1->value == root2->value));
    }
}

treeNode *copyTree(treeNode *root)
{
    treeNode *temp;
    if (root != NULL){
        temp = (treeNode*)malloc(sizeof(treeNode));
        if (!temp){
            return NULL;
        }
    temp->value = root->value;
    temp->lChild = copyTree(root->lChild);
    temp->rChild = copyTree(root->rChild);
    return temp;
    } else {
        return NULL;
    }
}

treeNode *copyMirrorTree(treeNode *root)
{
    treeNode *temp;
    if (root != NULL) {
        temp = (treeNode*)malloc(sizeof(treeNode));
        if (!temp) {
            return NULL;
        }
        temp->value = root->value;
        temp->lChild = copyMirrorTree(root->rChild);
        temp->rChild = copyMirrorTree(root->lChild);
        return temp;
    } else {
        return NULL;
    }
}

treeNode *freeTree(treeNode *root)
{
    if (root){
        root->lChild = freeTree(root->lChild);
        root->rChild = freeTree(root->rChild);
        if (root->lChild == NULL && root->rChild == NULL){
            free(root);
            return NULL;
        }
    }
    return NULL;
}

int isCompleteTree(treeNode *root)
{
    Queue que;
    QueueInitialize(&que);
    treeNode *temp = NULL;
    int noChild = 0;
    if (root != NULL)
        QueueAdd(&que, (int)root);
    
    while(QueueSize(&que) != 0)
    {
        temp = (treeNode*)QueueRemove(&que);
        if (temp->lChild != NULL){
            if (noChild == 1){
                return 0;
            }
            QueueAdd(&que, (int)temp->lChild);
        } else {
            noChild = 1;
        }
        if (temp->rChild != NULL){
            if (noChild == 1){
                return 0;
            }
            QueueAdd(&que, (int)temp->rChild);
        } else {
            noChild = 1;
        }
    }
    return 1;
}

int findCount(treeNode *root)
{
    return 1;
}
int isCompleteTreeUtil(treeNode *curr, int index, int count)
{
    if (curr == NULL)
    {
        return 1;
    }
    if (index > count)
    {
        return 0;
    }
    return isCompleteTreeUtil(curr->lChild, index *2 +1, count) && isCompleteTreeUtil(curr->rChild, index *2 +2, count);
}
int isCompleteTree2(treeNode *root)
{
    int count = findCount(root);
    return isCompleteTreeUtil(root, 0, count);
}

int isHeapUtil(treeNode *curr, int parentValue)
{
    if (curr == NULL){
        return 1;
    }
    if (curr->value < parentValue){
        return 0;
    }
    return (isHeapUtil(curr->lChild, curr->value) && isHeapUtil(curr->rChild, curr->value));
}
int isHeap(treeNode *root)
{
    int infi = -999999;
    return (isCompleteTree(root) && isHeapUtil(root, infi));
}
int isHeapUtil2(treeNode *curr, int index, int count, int parentValue)
{
    if (curr == NULL){
        return 1;
    }
    if (index > count){
        return 0;
    }
    if (curr->value < parentValue)
    {
        return 0;
    }
    return isHeapUtil2(curr->lChild, index *2 +1, count, curr->value) && isHeapUtil2(curr->rChild, index *2 +2, count, curr->value);
}
int isHeap2(treeNode *root)
{
    int count = findCount(root);
    int parentValue = - 999999;
    return isHeapUtil2(root, 0, count, parentValue);
}

void iterativePreOrder(treeNode *root)
{
    Stack stk;
    StackInitialize(&stk);
    treeNode *curr = NULL;
    if (root != NULL){
        StackPush(&stk, (int)root);
    }
    while (StackSize(&stk) != 0){
        curr = (treeNode*)StackPop(&stk);
        printf("%d ", curr->value);
        if (curr->rChild != NULL){
            StackPush(&stk, (int)curr->rChild);
        }
        if (curr->lChild != NULL){
            StackPush(&stk, (int)curr->lChild);
        }
    }
}

void iterativePostOrder(treeNode *root)
{
    Stack stk;
    StackInitialize(&stk);
    Stack visited;
    StackInitialize(&visited);
    treeNode *curr = NULL;
    int vtd;
    if (root != NULL){
        StackPush(&stk, (int)root);
        StackPush(&visited, 0);
    }
    while (StackSize(&stk) != 0)
    {
        curr = (treeNode*)StackPop(&stk);
        vtd = StackPop(&visited);
        if (vtd == 1){
            printf("d ", curr->value);
        } else {
            StackPush(&stk, (int)curr);
            StackPush(&visited, 1);
            if (curr->rChild != NULL){
                StackPush(&stk, (int)curr->rChild);
                StackPush(&visited, 0);
            }
            if (curr->lChild != NULL){
                StackPush(&stk, (int)curr->lChild);
                StackPush(&visited, 0);
            }
        }
    }
}

void interativeInOrder(treeNode *root)
{
    Stack stk;
    StackInitialize(&stk);
    Stack visited;
    StackInitialize(&visited);
    treeNode *curr = NULL;
    int vtd;
    if (root != NULL){
        StackPush(&stk, (int)root);
        StackPush(&visited, 0);
    }
    while (StackSize(&stk) != 0){
        curr = (treeNode*)StackPop(&stk);
        vtd = StackPop(&visited);
        if (vtd == 1){
            printf("%d ", curr->value);
        } else {
            if (curr->rChild != NULL){
                StackPush(&stk, (int)curr->rChild);
                StackPush(&visited, 0);
            }
            StackPush(&stk, (int)curr);
            StackPush(&visited, 1);
            if (curr->lChild != NULL){
                StackPush(&stk, (int)curr->lChild);
                StackPush(&visited, 0);
            }
        }
    }
}

treeNode *treeToListRec(treeNode *curr)
{
    treeNode *head, *tail, *tempHead;
    if (!curr){
        return NULL;
    }
    if (curr->lChild == NULL && curr->rChild == NULL){
        curr->lChild = curr;
        curr->rChild = curr;
        return curr;
    }
    if (curr->lChild){
        head = treeToListRec(curr->lChild);
        tail = head->lChild;
        curr->lChild = tail;
        tail->rChild = curr;
    } else {
        head = curr;
    }
    if (curr->rChild){
        tempHead = treeToListRec(curr->rChild);
        tail = tempHead->lChild;
        curr->rChild = tempHead;
        tempHead->lChild = curr;
    } else {
        tail = curr;
    }
    head->lChild = tail;
    tail->rChild = head;
    return head;
}

treeNode *CreateBinaryTreeUtil(int arr[], int start, int end)
{
    treeNode *curr;
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) /2;
    curr = (treeNode*)malloc(sizeof(treeNode));
    curr->value = arr[mid];
    curr->lChild = CreateBinaryTreeUtil(arr, start, mid-1);
    curr->rChild = CreateBinaryTreeUtil(arr, mid+1, end);
    return curr;
}
treeNode *CreateBinaryTree(int arr[], int size)
{
    return CreateBinaryTreeUtil(arr, 0, size-1);
}

treeNode *insertNode(treeNode *root, int value)
{
    if (root == NULL){
        root = (treeNode*)malloc(sizeof(treeNode));
        if (root == NULL){
            printf("Fallel memory shortage");
            return root;
        }
        root->value = value;
        root->lChild = root->rChild = NULL;
    } else {
        if (root->value >= value){
            root->lChild = insertNode(root->lChild, value);
        } else {
            root->rChild = insertNode(root->rChild, value);
        }
    }
    return root;
}
void insertNode2(treeNode **ptrRoot, int value)
{
    *ptrRoot = insertNode(*ptrRoot, value);
}

treeNode *findNode(treeNode *root, int value)
{
    if (!root){
        return NULL;
    }
    if (root->value == value){
        return root;
    } else {
        if (root->value > value){
            return findNode(root->lChild, value);
        } else {
            return findNode(root->rChild, value);
        }
    }
}

treeNode *findMinNode(treeNode *root)
{
    if (root){
        while (root->lChild){
            root = root->lChild;
        }
    }
    return root;
}
int minValue(treeNode *root)
{
    if (root){
        while(root->lChild){
            root= root->lChild;
        }
        return root->value;
    }
    return 99999;
}

treeNode* findMax(treeNode *root)
{
    if (root){
        while (root->rChild){
            root = root->rChild;
        }
    }
    return root;
}
int maxValue(treeNode *root)
{
    if (root){
        while (root->rChild){
            root = root->rChild;
        }
        return root->value;
    }
    return -9999;
}

int isBST(treeNode *root)
{
    if (!root){
        return 1;
    }
    if (root->lChild && maxValue(root->lChild) > root->value){
        return 0;
    }
    if (root->rChild && minValue(root->rChild) <= root->value){
        return 0;
    }
    return (isBST(root->lChild)) && (isBST(root->rChild));
}
//#define INT_MIN -999999
#define INT_MAX 999999
int isBSTUtil2(treeNode *root, int min, int max)
{
    if (!root){
        return 1;
    }
    if (root->value < min || root->value > max){
        return 0;
    }
    return isBSTUtil2(root->lChild, min, root->value) && isBSTUtil2(root->rChild, root->value, max);
}
int isBST2(treeNode *root)
{
    return isBSTUtil2(root, INT_MIN, INT_MAX);
}

int isBSTUtil3(treeNode *root, int *value)
{
    int ret;
    if (root){
        ret = isBSTUtil3(root->lChild, value);
        if (!ret){
            return 0;
        }
        if (*value > root->value)
        {
            return 0;
        }
        *value = root->value;
        ret = isBSTUtil3(root->rChild, value);
        if (!ret){
            return 0;
        }
    }
    return 1;
}
int isBST3(treeNode *root)
{
    int temp = 0;
    return isBSTUtil3(root, &temp);
}

treeNode* deleteNode(treeNode *root, int value)
{
    treeNode *temp = NULL;
    if (root){
        if (root->value == value){
            if (root->lChild == NULL & root->rChild == NULL){
                free(root);
                return NULL;
            } else {
                if (root->lChild ==NULL){
                    temp = root->rChild;
                    free(root);
                    return temp;
                }
                if (root->rChild == NULL){
                    temp = root->lChild;
                    free(root);
                    return temp;
                }
                temp = findMax(root->lChild);
                root->value = temp->value;
                root->lChild = deleteNode(root->lChild, temp->value);
            }
        } else {
            if (root->value > value){
                root->lChild = deleteNode(root->lChild, value);
            } else {
                root->rChild = deleteNode(root->rChild, value);
            }
        }
    }
    return root;
}
void deleteNodeWrapper(treeNode **rootPtr, int value)
{
    *rootPtr = deleteNode(*rootPtr, value);
}

treeNode* LcaBST(treeNode *root, treeNode *firstPtr, treeNode *secondPtr)
{
    if (!firstPtr || !secondPtr || !root)
    {
        return root;
    }
    if (root->value > firstPtr->value && root->value > secondPtr->value)
    {
        return LcaBT(root->lChild, firstPtr, secondPtr);
    }
    if (root->value < firstPtr->value && root->value < secondPtr->value)
    {
        return LcaBT(root->rChild, firstPtr, secondPtr);
    }
    return root;
}

treeNode* trimOutsideRange(treeNode *root, int min, int max)
{
    treeNode *tempNode;
    if (root == NULL){
        return NULL;
    }
    root->rChild = trimOutsideRange(root->rChild, min, max);
    root->lChild = trimOutsideRange(root->lChild, min, max);
    if (root->value < min)
    {
        tempNode = root->rChild;
        freeTree(root->lChild);
        free(root);
        return tempNode;
    }
    if (root->value > max)
    {
        tempNode = root->lChild;
        free(root->rChild);
        free(root);
        return tempNode;
    }
    return root;
}

void printInRaange(treeNode *root, int min, int max)
{
    if (!root)
        return;
    
    printInRaange(root->lChild, min, max);
    if (root->value >= min && root->value <= max)
    {
        printf(" %d ", root->value);
    }
    printInRaange(root->rChild, min, max);
}

int CeilBST(treeNode *root, int value)
{
    int ceil = 0;
    while (root)
    {
        if (root->value == value)
        {
            ceil = root->value;
            break;
        }
        else if (root->value > value)
        {
            ceil = root->value;
            root = root->lChild;
        }
        else
        {
            root = root->rChild;
        }
    }
    return ceil;
}
int FloorBST(treeNode *root, int value)
{
    int floor = 0;
    while (root)
    {
        if (root->value == value)
        {
            floor = root->value;
            break;
        }
        else if (root->value < value)
        {
            floor = root->value;
            root = root->rChild;
        }
        else
        {
            root = root->lChild;
        }
    }
    return floor;
}

int StackTop(Stack *stk)
{
    return 1;
}
int isBSTArray(int preorder[], int size)
{
    Stack stk;
    int value;
    StackInitialize(&stk);
    int root = -999999;
    for (int i=0; i<size; i++){
        value = preorder[i];
        if (value < root)
        {
            return 0;
        }
        while (StackSize(&stk) > 0 && StackTop(&stk) < value)
        {
            root = StackPop(&stk);
        }
        StackPush(&stk, value);
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    int arr[] = {6, 4, 8, 2, 5, 7, 9, 1, 3};
    treeNode *t = levelOrderBinaryTree(arr, sizeof(arr)/sizeof(int));
    
    int preorder[] = {30, 29, 25, 70, 200};
    printf("Is BST Array : %d \n", isBSTArray(preorder, 5));
    
    return 0;
}
