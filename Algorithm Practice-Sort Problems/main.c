#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_LEN 10
#define WORD_LEN 8

typedef struct node_t
{
    char key[WORD_LEN +1];
    int count;
}Node;

void swap(Node arr[], int lhs, int rhs)
{
    Node temp;
    memcpy(&temp, &arr[lhs], sizeof(Node));
    memcpy(&arr[lhs], &arr[rhs], sizeof(Node));
    memcpy(&arr[rhs], &temp, sizeof(Node));
}
void QSort(Node arr[], int lower, int upper)
{
    if (upper <= lower){
        return;
    }
    int pivot = arr[lower].count;
    int start = lower;
    int stop = upper;

    while (lower < upper) {
        while (arr[lower].count <= pivot){
            lower++;
        }
        while (arr[upper].count > pivot){
            upper--;
        }
        if (lower < upper) {
            swap(arr, upper, lower);
        }
    }
    swap(arr, upper, start);
    QSort(arr, start, upper-1);
    QSort(arr, upper+1, stop);
}
void QSelect(Node arr[], int lower, int upper, int k)
{
    if (upper <= lower){
        return;
    }
    int pivot = arr[lower].count;
    int start = lower;
    int stop = upper;

    while (lower < upper){
        while (lower < upper && arr[lower].count <= pivot){
            lower++;
        }
        while (lower < upper && arr[upper].count > pivot){
            upper--;
        }
        if (lower < upper) {
            swap(arr, upper, lower);
        }
    }
    swap(arr, upper, start);
    if (k<upper){
        QSelect(arr, start, upper-1, k);
    }
    if (k>upper){
        QSelect(arr, upper+1, stop, k);
    }
}
int main(){

    FILE *fp = fopen("test.txt", "r");
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);

    char* buffer = (char*)malloc(size+1);
    memset(buffer, 0, size+1);

    fseek(fp, 0, SEEK_SET);
    fread(buffer, size, 1, fp);
    fclose(fp);
    Node countTable[TABLE_LEN];

    int keyCount = 0;
    char tempWord[WORD_LEN+1] = {0,};

    int j=0;
    for (int i=0; i<size; i++){
        if (buffer[i] == ' ' || buffer[i] == '\n'){
            bool bFound = false;

            for (int k=0; k<keyCount; k++){
                if (strcmp(countTable[k].key, tempWord)==0){
                    countTable[k].count++;
                    bFound = true;
                    break;
                }
            }
            if (!bFound){
                strcpy(countTable[keyCount].key, tempWord);
                countTable[keyCount].count =1;
                keyCount++;
            }
            memset(tempWord, 0x0, WORD_LEN);
            j=0;
        } else {
            tempWord[j++] = buffer[i];
        }
    }
    Node countTableCopy[TABLE_LEN];
    memcpy(&countTableCopy, &countTable, sizeof(Node)*TABLE_LEN);

    int k=2;
    QSort(countTable, 0, keyCount-1);
    printf("%d th element: %s, %d\n", k, countTable[k].key, countTable[k].count);
    QSelect(countTable, 0, keyCount-1, k);
    printf("%d th element: %s, %d\n", k, countTableCopy[k].key, countTableCopy[k].count);

    free(buffer);

    return 0;
}

