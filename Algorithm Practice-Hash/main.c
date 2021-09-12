//
//  main.c
//  Algorithm Practice-Hash
//
//  Created by Wonkeun No on 2021-02-23.
//

#include <stdio.h>
#include <stdlib.h>
#define EMPTY_NODE 0
#define FILED_NODE 1
#define DELETED_NODE 2

unsigned int Hash(int key, int size)
{
    unsigned int hashValue = key;
    return hashValue &size;
}
int CollisionFunction(int i)
{
    return i;
}
typedef struct hashTable_t
{
    int size;
    int *array;
    char *flag;
} HashTable;
void HashInit(HashTable *hTable, int size)
{
    hTable->size = size;
    hTable->array = (int*)malloc(hTable->size * sizeof(int));
    hTable->flag = (char*)malloc(hTable->size * sizeof(char));
    for (int i=0; i<hTable->size; i++)
    {
        hTable->flag[i] = EMPTY_NODE;
    }
}
int HashAdd(HashTable *hTable, int value)
{
    int hashValue = Hash(value, hTable->size);
    int i=0;
    
    for (i=0; i<hTable->size; i++)
    {
        if (hTable->flag[hashValue] == EMPTY_NODE || hTable->flag[hashValue] == DELETED_NODE)
        {
            hTable->array[hashValue] = value;
            hTable->flag[hashValue] = FILED_NODE;
            break;
        }
        hashValue += CollisionFunction(i);
        hashValue = hashValue % hTable->size;
    }
    if (i != hTable->size)
        return 1;
    else
        return 0;
}
int HashFind(HashTable *hTable, int value)
{
    int hashValue = Hash(value, hTable->size);
    for (int i=0; i<hTable->size; i++)
    {
        if ((hTable->flag[hashValue] == FILED_NODE && hTable->array[hashValue] == value) || hTable->flag[hashValue] == EMPTY_NODE){
            break;
        }
        hashValue += CollisionFunction(i);
        hashValue = hashValue % hTable->size;
    }
    if (hTable->flag[hashValue] == FILED_NODE && hTable->array[hashValue] == value)
        return 1;
    else
        return 0;
}
int HashRemove(HashTable *hTable, int value)
{
    int hashValue = Hash(value, hTable->size);
    for (int i=0; i<hTable->size; i++)
    {
        if ((hTable->flag[hashValue] == FILED_NODE && hTable->array[hashValue] == value) || hTable->flag[hashValue] == EMPTY_NODE){
            break;
        }
        hashValue += CollisionFunction(i);
        hashValue = hashValue % hTable->size;
    }
    if (hTable->flag[hashValue] == FILED_NODE && hTable->array[hashValue] == value)
    {
        hTable->flag[hashValue] = DELETED_NODE;
        return 1;
    } else {
        return 0;
    }
}
void HashPrint(HashTable *hTable)
{
    for (int i=0; i<hTable->size; i++)
    {
        if (hTable->flag[i] == FILED_NODE)
            printf(" %d ", hTable->array[i]);
    }
    printf("\n");
}

int CollisionFunction2(int i)
{
    return i * i;
}

#define TABLE_SIZE 500
typedef struct dataNode_t
{
    int key;
    int value;
    struct dataNode_t *next;
}DataNode;
typedef struct linkedHashTable_t
{
    int tableSize;
    DataNode **listArray;
}LinkedHashTable;
unsigned int LinkedHash(int key, int tableSize)
{
    unsigned int hashValue = 0;
    hashValue = key;
    return hashValue & tableSize;
}
void LinkedHashInit(LinkedHashTable *hTable)
{
    hTable->tableSize = TABLE_SIZE;
    hTable->listArray = (DataNode**)malloc(hTable->tableSize * sizeof(DataNode*));
    for (int i=0; i < hTable->tableSize; i++)
    {
        hTable->listArray[i] = NULL;
    }
}
void LinkedHashPrint(LinkedHashTable *hTable)
{
    DataNode *head;
    for (int i=0; i < hTable->tableSize; i++)
    {
        head = hTable->listArray[i];
        while (head)
        {
            printf(" [ %d -> %d ]", head->key, head->value);
            head = head->next;
        }
    }
    printf("\n");
}
int LinkedHashFind(LinkedHashTable *hTable, int value)
{
    DataNode *head;
    int index = LinkedHash(value, hTable->tableSize);
    head = hTable->listArray[index];
    while (head)
    {
        if (head->key == value)
            return 1;
        head = head->next;
    }
    return 0;
}
void LinkedHashAdd(LinkedHashTable *hTable, int value)
{
    int index = LinkedHash(value, hTable->tableSize);
    DataNode *temp = (DataNode*)malloc(sizeof(DataNode));
    temp->key = value;
    temp->next = hTable->listArray[index];
    hTable->listArray[index] = temp;
}
int LinkedHashRemove(LinkedHashTable *hTable, int value)
{
    DataNode *currNode;
    DataNode *nextNode;
    int index = LinkedHash(value, hTable->tableSize);
    currNode = hTable->listArray[index];
    if (currNode && currNode->key == value)
    {
        hTable->listArray[index] = currNode->next;
        free(currNode);
        return 1;
    }
    while (currNode)
    {
        nextNode - currNode->next;
        if (nextNode && nextNode->key == value)
        {
            currNode->next = nextNode->next;
            free(nextNode);
            return 1;
        }
        else
            currNode = nextNode;
    }
    return 0;
}

#include <string.h>
void CounterAdd(LinkedHashTable *hTable, int key)
{
    DataNode *head;
    int index = LinkedHash(key, hTable->tableSize);
    head = hTable->listArray[index];
    while (head)
    {
        if (head->key == 0)
        {
            head->value += 1;
            return ;
        }
        head = head->next;
    }
    DataNode *temp = (DataNode*)malloc(sizeof(DataNode));
    temp->key = key;
    temp->value = 1;
    temp->next = hTable->listArray[index];
    hTable->listArray[index] = temp;
}
int FindCount(LinkedHashTable *hTable, int key)
{
    DataNode *head;
    int index = LinkedHash(key, hTable->tableSize);
    head = hTable->listArray[index];
    while(head)
    {
        if (head->key == key)
        {
            return head->value;
        }
        head = head->next;
    }
    return 0;
}
int CounterRemove(LinkedHashTable *hTable, int key)
{
    DataNode *currNode;
    DataNode *nextNode;
    int index = LinkedHash(key, hTable->tableSize);
    currNode = hTable->listArray[index];
    
    if (currNode && currNode->key == key)
    {
        if (currNode->value == 1)
        {
            hTable->listArray[index] = currNode->next;
            free(currNode);
        } else {
            currNode->value -= 1;
        }
        return 1;
    }
    while (currNode)
    {
        nextNode = currNode->next;
        if (nextNode && nextNode->key == key)
        {
            if (nextNode->value == 1)
            {
                currNode->next = nextNode->next;
                free(nextNode);
            } else {
                nextNode->value -= 1;
            }
            return 1;
        } else {
            currNode = nextNode;
        }
    }
    return 0;
}

int isAnagram(char *str1, char *str2)
{
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    
    if (size1 != size2)
    {
        return 0;
    }
    LinkedHashTable cm;
    LinkedHashInit(&cm);
    for (int i=0; i<size1; i++)
    {
        CounterAdd(&cm, str1[i]);
    }
    for (int i=0; i<size2; i++)
    {
        if (FindCount(&cm, str2[i]) == 0)
        {
            return 0;
        } else {
            CounterRemove(&cm, str2[i]);
        }
    }
    return 1;
}

char *removeDuplicate(char *str, int size)
{
    LinkedHashTable hs;
    LinkedHashInit(&hs);
    char *ret = (char*)malloc(sizeof(char) * size);
    int retIndex = 0;
    for (int i=0; i<size; i++)
    {
        if (FindCount(&hs, str[i]) == 0)
        {
            ret[retIndex] = str[i];
            retIndex += 1;
            CounterAdd(&hs, str[i]);
        }
    }
    ret[retIndex] = '\0';
    return ret;
}

int findMissing(int arr[], int size, int start, int end)
{
    LinkedHashTable cm;
    LinkedHashInit(&cm);
    for (int i=0; i<size; i++)
    {
        CounterAdd(&cm, arr[i]);
    }
    int curr = start;
    while (curr <= end)
    {
        if (FindCount(&cm, curr) == 0)
        {
            return curr;
        }
        curr += 1;
    }
    return -999999;
}

void printRepeating(int arr[], int size)
{
    LinkedHashTable cm;
    LinkedHashInit(&cm);
    int val;
    printf("Repeated element: ");
    for (int i=0; i<size; i++)
    {
        val = arr[i];
        if (FindCount(&cm, val))
        {
            printf(" %d ", val);
        } else {
            CounterAdd(&cm, val);
        }
    }
}

int printFirstRepeating(int arr[], int size)
{
    LinkedHashTable cm;
    LinkedHashInit(&cm);
    int i=0;
    for (i=0; i<size; i++)
    {
        CounterAdd(&cm, arr[i]);
    }
    for (i=0; i<size; i++)
    {
        if (FindCount(&cm, arr[i]) > 1)
        {
            printf("\n 1st repeated number: %d", arr[i]);
            return arr[i];
        }
    }
    return -999999;
}

void PrintSortByOrder(int arr[], int size, int arr2[], int size2)
{
    int i, key, count;
    LinkedHashTable cm;
    LinkedHashInit(&cm);
    for (i=0; i<size; i++)
    {
        CounterAdd(&cm, arr[i]);
    }
    for (i=0; i<size2; i++)
    {
        key = arr2[i];
        count = FindCount(&cm, key);
        for (int j=0; j<count; j++)
        {
            printf("%d", key);
            CounterRemove(&cm, key);
        }
    }
    for (i=0; i<size; i++)
    {
        key = arr[i];
        if (FindCount(&cm, key))
        {
            printf("%d", key);
            CounterRemove(&cm, key);
        }
    }
}

int main(int argc, const char * argv[])
{
    LinkedHashTable myTable;
    LinkedHashInit(&myTable);   //size removed
    LinkedHashAdd(&myTable, 88);
    LinkedHashAdd(&myTable, 88);
    LinkedHashAdd(&myTable, 18);
    LinkedHashAdd(&myTable, 49);
    LinkedHashAdd(&myTable, 58);
    LinkedHashAdd(&myTable, 69);
    LinkedHashPrint(&myTable);
    LinkedHashRemove(&myTable, 88);
    LinkedHashRemove(&myTable, 88);
    LinkedHashPrint(&myTable);
    printf("Find 88: %d\n", LinkedHashFind(&myTable, 88));
    printf("Find 18: %d\n", LinkedHashFind(&myTable, 18));
           
    
    return 0;
}
