//
//  main.c
//  Algorithm-6.1
//
//  Created by Wonkeun No on 2021-01-24.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} ListNode;

int insertNode(ListNode **ptrHead, int value)
{
    ListNode *tempNode = (ListNode*)malloc(sizeof(ListNode));
    if (!tempNode)
        return -1;
    
    tempNode->value = value;
    tempNode->next = *ptrHead;
    *ptrHead = tempNode;
    return 1;
}
int insertNodeKthFromBeginning(ListNode **ptrHead, int value, int k)
{
    if (k < 1)
        return -1;
    
    int count = k-1;
    ListNode *cur = (*ptrHead), *prev;
    while(cur && count > 0){
        count--;
        prev = cur;
        cur = cur->next;
    }
    if (count > 0)
        return -1;
    
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    if (!newNode)
        return -1;
    
    newNode->value = value;
    newNode->next = cur;
    
    if (k == 1)
        *ptrHead = newNode;
    else
        prev->next = newNode;
    
    return 1;
}

int insertNodeKthFromEnd(ListNode **ptrHead, int value, int k)
{
    int count = k-1;
    ListNode* first = (*ptrHead), *prev = NULL;
    while (first && count >0){
        count--;
        first = first->next;
    }
    
    if (count > 0)
        return -1;
    
    ListNode *temp = (*ptrHead);
    while(first){
        prev = temp;
        temp = temp->next;
        first = first->next;
    }
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    if (!newNode)
        return -1;
    
    newNode->value = value;
    newNode->next = temp;
    
    if (prev == NULL)
        *ptrHead = newNode;
    else
        prev->next = newNode;
    
    return 1;
}

void deleteNode(ListNode *curr)
{
    if (curr == NULL || curr->next == NULL)
        return;
    
    ListNode *deleteMe = curr->next;
    curr->value = deleteMe->value;
    
    free(deleteMe);
}

int searchList(ListNode *head, int value)
{
    int count = 0;
    while (head){
        if (head->value == value){
            count++;
        }
        head = head->next;
    }
    return count;
}

ListNode *loopDetect(ListNode *head)
{
    printf("loop detect");
    ListNode *slowPtr;
    ListNode *fastPtr;
    slowPtr = fastPtr = head;
    
    while (fastPtr->next && fastPtr->next->next){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr){
            printf("\nloop found \n");
            return slowPtr;
        }
    }
    printf("\nloop not found \n");
    return NULL;
}
ListNode *findIntersection(ListNode *head, ListNode *head2)
{
    int l1 = 0;
    int l2 = 0;
    ListNode *tempHead = head;
    ListNode *tempHead2 = head2;
    
    ListNode *loop = loopDetect(head);
    
    while(tempHead != loop){
        l1++;
        tempHead = tempHead->next;
    }
    while (tempHead2 != loop){
        l2++;
        tempHead2 = tempHead2->next;
    }
    int diff;
    if (l1 < l2){
        ListNode *temp = head;
        head = head2;
        head2 = temp;
        diff = l2 - l1;
    } else {
        diff = l1 - l2;
    }
    for (; diff > 0; diff--){
        head = head->next;
    }
    while (head != head2){
        head = head->next;
        head2 = head2->next;
    }
    return head;
}

int countNodesSub(ListNode *head, ListNode* joint)
{
    int count = 1;
    ListNode *curr = joint;
    while(curr->next != joint){
        count++;
        curr = curr->next;
    }
    while(head != joint){
        count++;
        head = head->next;
        joint = joint->next;
    }
    return count;
}
int countNodes(ListNode *head)
{
    ListNode *slowPtr;
    ListNode *fastPtr;
    slowPtr = fastPtr = head;
    
    while(fastPtr->next && fastPtr->next->next){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr){
            return countNodesSub(head, slowPtr);
        }
    }
    return 0;
}

typedef struct PolyNode
{
    int coef;
    int exp;
    struct Node *next;
}ListPolyNode;

void polyAdd(ListPolyNode *poly1, ListPolyNode *poly2, ListPolyNode *polySum)
{
    while(poly1 && poly2)
    {
        polySum->coef = 0;
        
        int poly1exp = poly1->exp;
        if (poly1exp >= poly2->exp){
            polySum->coef += poly1->coef;
            polySum->exp = poly1->exp;
            poly1 = poly1->next;
        }
        if (poly1exp <= poly2->exp){
            polySum->coef += poly2->coef;
            polySum->exp = poly2->exp;
            poly2 = poly2->next;
        }
        
        if (poly1 || poly2)
        {
            polySum->next = (ListPolyNode*)malloc(sizeof(ListPolyNode));
            if (!polySum->next)
                return;
            polySum = polySum->next;
            polySum->next = NULL;
        }
    }
    while (poly1 || poly2)
    {
        if (poly1){
            polySum->coef = poly1->coef;
            polySum->exp = poly1->exp;
            poly1 = poly1->next;
        }
        if (poly2){
            polySum->coef = poly2->coef;
            polySum->exp = poly2->exp;
            poly2 = poly2->next;
        }
        if (poly1 || poly2){
            polySum->next = (ListPolyNode*)malloc(sizeof(ListPolyNode));
            if (!polySum->next){
                return;
            }
            polySum = polySum->next;
            polySum->next = NULL;
        }
    }
}

int checkReverse(ListNode *head1, ListNode *head2)
{
    ListNode *currNode = head1;
    ListNode *prevNode;
    ListNode *nextNode;
    if (!currNode || !currNode->next)
        return 0;
    
    prevNode = currNode;
    currNode = currNode->next;
    prevNode->next = NULL;
    while(currNode){
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    int ret = 1;
    if (prevNode->value != head2->value)
        ret &=0;
    
    currNode = prevNode->next;
    prevNode->next = NULL;
    ListNode *currNode2 = head2->next;
    while (currNode && currNode2)
    {
        if (currNode->value != currNode2->value){
            ret &=0;
        }
        currNode = currNode->next;
        currNode2 = currNode2->next;
    }
    if (currNode != NULL || currNode2 != NULL)
        ret &=0;
    
    return ret;
}

ListNode *findMiddle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    
    if (!head)
        return head;
    
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode *reverseRecurseUtil(ListNode *currentNode, ListNode *nextNode)
{
    ListNode *ret;
    if (!currentNode)
        return NULL;
    
    if (!currentNode->next)
    {
        printf("%d ", currentNode->value);
        currentNode->next = nextNode;
        return currentNode;
    }
    
    ret = reverseRecurseUtil(currentNode->next, currentNode);
    printf("%d ", currentNode->value);
    currentNode->next = nextNode;
    return ret;
}
void printfReverseRecurse(ListNode **ptrHead)
{
    *ptrHead = reverseRecurseUtil(*ptrHead, NULL);
}

void deleteMiddleNode(ListNode *node)
{
    ListNode *deleteNode = node->next;
    node->value = deleteNode->value;
    node->next = deleteNode->next;
    
    free(deleteNode);
}

typedef struct randomNode
{
    int value;
    struct randomNode *next;
    struct randomNode *random;
}ListRandomNode;
ListRandomNode *copyRandomList(ListRandomNode *head)
{
    if (!head)
        return NULL;
    ListRandomNode *cur = head;
    
    while(cur)
    {
        ListRandomNode *copy = (ListRandomNode*)malloc(sizeof(ListRandomNode));
        copy->value = cur->value;
        copy->next = cur->next;
        cur->next = copy;
        cur = copy->next;
    }
    cur = head;
    while(cur)
    {
        if (cur->random)
            cur->next->random = cur->random->next;
        
        cur = cur->next->next;
    }
    cur = head;
    ListRandomNode *newHead = head->next;
    while(cur)
    {
        ListRandomNode *temp = cur->next;
        cur->next = temp->next;
        if (temp->next)
            temp->next = temp->next->next;
        cur = cur->next;
    }
    return newHead;
}

int main() {
    ListNode *head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 5);
    insertNode(&head, 7);
    
    
    int ans = insertNodeKthFromBeginning(&head, 3, 4);
    ans = insertNodeKthFromEnd(&head, 3, 4);
    
    return 0;
}
