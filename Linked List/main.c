//
//  main.c
//  Linked List
//
//  Created by Wonkeun No on 2021-01-17.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
    int value;
    struct listNode *next;
} ListNode;

int insertNode(ListNode **ptrHead, int value)
{
    ListNode *tempNode = (ListNode*)malloc(sizeof(ListNode));
    if (!tempNode){
        return -1;
    }
    tempNode->value = value;
    tempNode->next = *ptrHead;
    *ptrHead = tempNode;
    return 1;
}

int insertAtEnd(ListNode **ptrHead, int value)
{
    ListNode *head = *ptrHead;
    ListNode *tempNode = (ListNode*)malloc(sizeof(ListNode));
    
    if (!tempNode){
        return -1;
    }
    tempNode->value = value;
    tempNode->next = NULL;
    
    if (head == NULL){
        tempNode->next = *ptrHead;
        *ptrHead = tempNode;
        return 1;
    }
    while (head->next != NULL){
        head = head->next;
    }
    
    tempNode->next = head->next;
    head->next = tempNode;
    return 1;
}

void printList(ListNode *head)
{
    printf("Print the list: ");
    while(head){
        printf(" %d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int sortedInsert(ListNode **ptrHead, int value)
{
    ListNode *head = *ptrHead;
    ListNode *tempNode = (ListNode*)malloc(sizeof(ListNode));
    printf("Input element %d \n", value);
    
    if (!tempNode){
        return -1;
    }
    
    tempNode->value = value;
    tempNode->next = NULL;
    
    if (head == NULL || head->value > value){
        tempNode->next = *ptrHead;
        *ptrHead = tempNode;
        return 1;
    }
    
    while (head->next != NULL && head->next->value < value){
        head = head->next;
    }
    
    tempNode->next = head->next;
    head->next = tempNode;
    return 1;
}

int searchList(ListNode *head, int value)
{
    while(head){
        if (head->value == value){
            printf("\nValue is found.\n");
            return 1;
        }
        head = head->next;
    }
    printf("\nValue is not found.\n");
    return 0;
}

void deleteFirstNode(ListNode **ptrHead)
{
    ListNode *currNode = *ptrHead;
    ListNode *nextNode;
    
    if (currNode == NULL){
        return;
    }
    nextNode = currNode->next;
    free(currNode);
    *ptrHead = nextNode;
}

void deleteNode(ListNode **ptrHead, int delValue)
{
    printf("\n Delete Node\n");
    ListNode *currNode = *ptrHead;
    ListNode *nextNode;
    
    if (currNode && currNode->value == delValue){
        *ptrHead = currNode->next;
        free(currNode);
        return;
    }
    
    while (currNode != NULL){
        nextNode = currNode->next;
        if (nextNode && nextNode->value == delValue){
            currNode->next = nextNode->next;
            free(nextNode);
            return;
        } else {
            currNode = nextNode;
        }
    }
}

void deleteNodes(ListNode **ptrHead, int delValue)
{
    ListNode *currNode = *ptrHead;
    ListNode *nextNode;
    ListNode *delNode;
    
    while(currNode != NULL && currNode->value == delValue){
        *ptrHead = currNode->next;
        delNode = currNode;
        currNode = currNode->next;
        free(delNode);
    }
    
    while(currNode != NULL){
        nextNode = currNode->next;
        if (nextNode && nextNode->value == delValue){
            currNode->next = nextNode->next;
            free(nextNode);
        } else {
            currNode = nextNode;
        }
    }
}

void deleteList(ListNode **ptrHead)
{
    ListNode *deleteMe = *ptrHead;
    ListNode *nextNode;
    
    while(deleteMe != NULL){
        nextNode = deleteMe->next;
        free(deleteMe);
        deleteMe = nextNode;
    }
    *ptrHead = NULL;
}

void reverseList(ListNode **ptrHead)
{
    ListNode *currNode = *ptrHead;
    ListNode *prevNode;
    ListNode *nextNode;
    
    if (!currNode){
        return;
    }
    
    if (!currNode->next){
        return;
    }
    
    prevNode = currNode;
    currNode = currNode->next;
    prevNode->next = NULL;
    
    while(currNode){
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    *ptrHead = prevNode;
}

ListNode *reverseRecurseUtil(ListNode *currentNode, ListNode *nextNode)
{
    ListNode *ret;
    if (!currentNode){
        return NULL;
    }
    
    if (!currentNode->next){
        currentNode->next = nextNode;
        return currentNode;
    }
    ret = reverseRecurseUtil(currentNode->next, currentNode);
    currentNode->next = nextNode;
    return ret;
}
void reverseRecurse(ListNode **ptrHead)
{
    *ptrHead = reverseRecurseUtil(*ptrHead, NULL);
}

void removeDuplicate(ListNode *head)
{
    ListNode *deleteMe;
    while(head){
        if ((head->next) && head->value == head->next->value){
            deleteMe = head->next;
            head->next = deleteMe->next;
            free(deleteMe);
        } else {
            head = head->next;
        }
    }
}

void copyListReversed(ListNode *head, ListNode **ptrHead2)
{
    ListNode *tempNode = NULL;
    ListNode *tempNode2 = NULL;
    while (head){
        tempNode2 = (ListNode*)malloc(sizeof(ListNode));
        tempNode2->value = head->value;
        tempNode2->next = tempNode;
        tempNode = tempNode2;
        head = head->next;
    }
    *ptrHead2 = tempNode;
}

void copyList(ListNode *head, ListNode **ptrHead2)
{
    ListNode *headNode = NULL;
    ListNode *tailNode = NULL;
    ListNode *tempNode = NULL;
    
    if (head == NULL){
        return;
    }
    
    headNode = (ListNode*)malloc(sizeof(ListNode));
    tailNode = headNode;
    headNode->value = head->value;
    headNode->next = NULL;
    head = head->next;
    
    while(head){
        tempNode = (ListNode*)malloc(sizeof(ListNode));
        tempNode->value = head->value;
        tempNode->next = NULL;
        tailNode->next = tempNode;
        tailNode = tailNode->next;
        head = head->next;
    }
    *ptrHead2 = headNode;
}

int compareList(ListNode *head1, ListNode *head2)
{
    if (head1 == NULL && head2 == NULL){
        return 1;
    } else if ((head1 == NULL) || (head2 == NULL) || head1->value != head2->value){
        return 0;
    } else {
        return compareList(head1->next, head2->next);
    }
}
int compareList2(ListNode *head1, ListNode *head2)
{
    while (head1 == NULL && head2 == NULL){
        if (head1->value != head2->value){
            return 0;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1 == NULL && head2 == NULL){
        return 1;
    }
    return 0;
}

int findLength(ListNode *head)
{
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

ListNode *nthNodeFromBeginning(ListNode *head, int index)
{
    int count =0;
    while (head && count < index-1){
        count++;
        head = head->next;
    }
    
    if (head){
        return head;
    } else {
        return NULL;
    }
}

ListNode *nthNodeFromEnd1(ListNode *head, int index)
{
    int size = findLength(head);
    int startIndex;
    if (size && size < index){
        printf("%dth element was not found", index);
        return NULL;
    }
    
    startIndex = size - index +1;   //Not -1?
    return nthNodeFromBeginning(head, index);   //Not startIndex?
}
ListNode *nthNodeFromEnd2(ListNode *head, int index)
{
    int count = 0;
    ListNode *temp = NULL;
    ListNode *curr = head;
    while (curr && count < index -1){
        count++;
        curr = curr->next;
    }
    if (!curr){
        return NULL;
    }
    temp = head;
    while (curr){
        temp = temp->next;
        curr = curr->next;
    }
    return temp;
}

int loopDetect(ListNode *head)
{
    printf("Check loop");
    ListNode *slowPtr;
    ListNode *fastPtr;
    slowPtr = fastPtr = head;
    
    while(fastPtr->next && fastPtr->next->next){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr){
            printf("A loop is found");
            return 1;
        }
    }
    printf("A loop is not found");
    return 0;
}
int reverseListLoopDetect(ListNode *head)
{
    ListNode **ptrHead = &head;
    ListNode *head2 = head;
    reverseList(ptrHead);
    if (*ptrHead == head2){
        return 1;
    } else {
        reverseList(ptrHead);
        return 0;
    }
}

int loopTypeDetect(ListNode *const head)
{
    ListNode *slowPtr;
    ListNode *fastPtr;
    slowPtr = fastPtr = head;
    
    while(fastPtr->next && fastPtr->next->next){
        if (head == fastPtr->next || head == fastPtr->next->next){
            printf("A circle list is found");
            return 2;
        }
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr){
            printf("A loop is found");
            return 1;
        }
    }
    printf("Loop is not found");
    return 0;
}

void removeLoop(ListNode **ptrHead)
{
    int loopLength;
    ListNode *slowPtr, *fastPtr, *head;
    slowPtr = fastPtr = head = *ptrHead;
    ListNode *loopNode = NULL;
    
    while (fastPtr->next && fastPtr->next->next){
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
        if (fastPtr == slowPtr || fastPtr->next == slowPtr){
            loopNode = slowPtr;
            break;
        }
    }
    if (loopNode){
        ListNode *temp = loopNode->next;
        loopLength =1;
        while(temp != loopNode){
            loopLength++;
            temp = temp->next;
        }
        temp = head;
        ListNode *breakNode = head;
        for (int i=0; i<loopLength; i++){
            breakNode = breakNode->next;
        }
        while (temp != breakNode->next){
            temp = temp->next;
            breakNode = breakNode->next;
        }
        breakNode->next = NULL;
    }
    
}

ListNode *findIntersection(ListNode *head, ListNode *head2)
{
    int l1 = 0;
    int l2 = 0;
    ListNode *tempHead = head;
    ListNode *tempHead2 = head2;
    
    while(tempHead){
        l1++;
        tempHead = tempHead->next;
    }
    while(tempHead2){
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
    while(head != head2){
        head = head->next;
        head2 = head2->next;
    }
    return head;
}

typedef struct doubleLinkedList
{
    int value;
    struct doubleLinkedList *prev;
    struct doubleLinkedList *next;
}Node;

int insertDoubleNode(Node **ptrHead, int value)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    if (!temp){
        printf("Memory allocation error");
        return 0;
    }
    Node *head = *ptrHead;
    if (!head){
        temp->value = value;
        temp->next = NULL;
        temp->prev = NULL;
        *ptrHead = temp;
    } else {
        temp->value = value;
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        *ptrHead = temp;
    }
    return 1;
}

int sortedDoubleInsert(Node **ptrHead, int value)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    if(!temp){
        printf("Memory allocation error");
        return 0;
    }
    temp->value = value;
    Node *curr = *ptrHead;
    
    if (!curr){
        temp->next = NULL;
        temp->prev = NULL;
        *ptrHead = temp;
        return 1;
    }
    if (curr->value <= value){
        temp->next = curr;
        temp->prev = NULL;
        curr->prev = temp;
        *ptrHead = temp;
        return 1;
    }
    while (curr->next && curr->next->value > value){
        curr = curr->next;
    }
    if (!curr->next){
        temp->next = NULL;
        temp->prev = curr;
        curr->next = temp;
    } else {
        temp->next = curr->next;
        temp->next->prev = temp;
        temp->prev = curr;
        curr->next = temp;
    }
    return 1;
}

void deleteFirstDoubleNode(Node **ptrHead)
{
    Node *head = *ptrHead;
    Node *deleteMe;
    if (head == NULL){
        return;
    }
    deleteMe = head;
    head = head->next;
    *ptrHead = head;
    if (head != NULL){
        head->prev = NULL;
    }
    free(deleteMe);
}

void deleteDoubleNode(Node **ptrHead, int value)
{
    Node *curr = *ptrHead;
    Node *next;
    Node *deleteMe;
    
    if (curr == NULL){
        return;
    }
    if (curr->value == value){
        deleteMe = curr;
        curr = curr->next;
        if (curr){
            curr->prev = NULL;
        }
        *ptrHead = curr;
        free(deleteMe);
        return;
    }
    next = curr->next;
    while (next != NULL){
        if (next->value == value){
            curr->next = next->next;
            if (curr->next){
                curr->next->prev = curr;
            }
            free(next);
            return;
        }
        curr = next;
        next = next->next;
    }
}

void removeDuplicates(Node *head)
{
    Node *deleteMe;
    while (head){
        if ((head->next) && head->value == head->next->value){
            deleteMe = head->next;
            head->next = deleteMe->next;
            if (head->next){
                head->next->prev = head;
            }
            free(deleteMe);
        } else {
            head = head->next;
        }
    }
}

void reverseDoubleList(Node **ptrHead)
{
    Node *curr = *ptrHead;
    Node *tempNode;
    while (curr){
        tempNode = curr->next;
        curr->next = curr->prev;
        curr->prev = tempNode;
        if(!curr->prev){            //Become the head
            *ptrHead = curr;
            return;
        }
        curr = curr->prev;
    }
    return;
}

Node *copyDoubleListReversed(Node *head)
{
    Node *temp = NULL;
    Node *head2 = NULL;
    Node *curr = head;
    while(curr){
        temp = (Node*)malloc(sizeof(Node));
        temp->value = curr->value;
        temp->next = head2;
        temp->prev = NULL;
        if (head2){
            head2->prev = temp;
        }
        head2 = temp;
        curr = curr->next;
    }
    return head2;
}

Node *copyDoubleList(Node *head)
{
    Node *head2 = NULL;
    Node *tail2 = NULL;
    Node *tempNode = NULL;
    
    if (!head){
        return NULL;
    }
    head2 = (Node*)malloc(sizeof(Node));
    tail2 = head2;
    head2->value = head->value;
    head2->next = NULL;
    head2->prev = NULL;
    head = head->next;
    
    while(head){
        tempNode = (Node*)malloc(sizeof(Node));
        tempNode->value = head->value;
        tempNode->next = NULL;
        tail2->next = tempNode;
        tempNode->prev = tail2;
        tail2 = tail2->next;
        head = head->next;
    }
    return head2;
}

int insertAtStart(Node **ptrTail, int value)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    if (!temp){
        printf("Memory allocation erro");
        return 0;
    }
    Node *tail = *ptrTail;
    if (!tail){
        temp->value = value;
        temp->next = temp;
        *ptrTail = temp;
    } else {
        temp->value = value;
        temp->next = tail->next;
        tail->next = temp;
    }
    return 1;
    
}

int insertAtCircularEnd(Node **ptrTail, int value)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    if (!temp){
        printf("Memory allocation error");
        return 0;
    }
    Node *tail = *ptrTail;
    if (!tail){
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

int searchCircularList(Node *tail, int value)
{
    if (!tail){
        return 0;
    }
    if (tail->value == value){
        return 1;
    }
    Node *curr = tail->next;
    while (curr != tail){
        if (curr->value == value){
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

void printCircularList(Node *tail)
{
    if (!tail){
        return;
    }
    Node *head = tail->next;
    printf("\n%d", head->value);
    Node *currNode = head->next;
    while (currNode != head){
        printf("%d ", currNode->value);
        currNode = currNode->next;
    }
}

int deleteHeadNode(Node **ptrTail)
{
    Node *tail = *ptrTail;
    Node *deleteMe;
    if (!tail){
        return 0;
    }
    if (tail->next == tail){
        free(tail);
        *ptrTail = NULL;
        return 1;
    }
    deleteMe = tail->next;
    tail->next = deleteMe->next;
    free(deleteMe);
    return 1;
}

int deleteCircularNode(Node **ptrTail, int value)
{
    Node *tail = *ptrTail;
    Node *curr = tail;
    Node *prev = NULL;
    Node *deleteMe;
    
    if (!tail){
        return 0;
    }
    prev = curr;
    curr = curr->next;
    
    while (curr != tail){
        if (curr->value == value){
            prev->next = curr->next;
            free(curr);
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }
    if (curr->value == value){
        prev->next = curr->next;
        free(curr);
        *ptrTail = prev;
        return 1;
    }
    return 0;
}

void deleteCircularList(Node **ptrTail)
{
    Node *tail = *ptrTail;
    Node *curr;
    Node *next;
    if (!tail){
        return;
    }
    curr = tail->next;
    free(tail);
    while (curr != tail){
        next = curr->next;
        free(curr);
        curr = next;
    }
    *ptrTail = NULL;
}

int InsertAtStart(Node **ptrHead, int value)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    if (!temp){
        printf("Memory allocation error");
        return 0;
    }
    Node *head = *ptrHead;
    
    if (!head){
        temp->value = value;
        temp->next = temp;
        temp->prev = temp;
        *ptrHead = temp;
    } else {
        temp->value = value;
        temp->prev = head->prev;
        temp->prev->next = temp;
        temp->next = head;
        head->prev = temp;
        *ptrHead = temp;
    }
    return 1;
}

int insertAtDoubleCircularEnd(Node **ptrHead, int value)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    if (!temp){
        printf("Memory allocation error");
        return 0;
    }
    Node *head = *ptrHead;
    if (!head){
        temp->value = value;
        temp->next = temp;
        temp->prev = temp;
        *ptrHead = temp;
    } else {
        temp->value = value;
        temp->next = head;
        temp->prev = head->prev;
        head->prev->next = temp;
        head->prev = temp;
        
    }
    return 1;
}

int removeFromStart(Node **ptrHead)
{
    Node *head = *ptrHead;
    if (!head){
        printf("EmptyListEror");
    }
    int value = head->value;
    if (head->next == head){
        free(head);
        *ptrHead = NULL;
        return value;
    }
    Node *tail = head->prev;
    Node *next = head->next;
    next->prev = tail;
    tail->next = next;
    free(head);
    *ptrHead = next;
    return value;
}

int removeFromEnd(Node **ptrHead)
{
    Node *head = *ptrHead;
    if (!head){
        printf("EmptyListError");
    }
    Node *tail = head->prev;
    int value = head->value;
    if (tail->next == tail){
        free(tail);
        *ptrHead = NULL;
        return value;
    }
    Node *prev = tail->prev;
    prev->next = head;
    head->prev = prev;
    free(tail);
    return value;
}

int main() {
    ListNode *head = NULL;
    
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    insertNode(&head, 6);
//    printList(head);
//    ListNode *ptrHead = NULL;
//    copyList(head, ptrHead);
    
    head->next->next->next->next->next->next = head->next->next;
    removeLoop(head);
    
    return 0;
}
