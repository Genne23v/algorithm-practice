//
//  main.c
//  Algorithm Practice-Heap
//
//  Created by Wonkeun No on 2021-02-19.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comp(int a, int b, int inc)
{
    if (inc)
        return a > b;
    return a < b;
}
void percollateDown(int *a, int position, int size, int isMinHeap)
{
    int lChild = 2 * position +1;
    int rChild = lChild +1;
    
    int small = -1;
    int temp;
    
    if (lChild < size)
    {
        small = lChild;
    }
    if (rChild < size && comp(a[lChild], a[rChild], isMinHeap))
    {
        small = rChild;
    }
    if (small != -1 && comp(a[position], a[small], isMinHeap))
    {
        temp = a[position];
        a[position] = a[small];
        a[small] = temp;
        percollateDown(a, small, size, isMinHeap);
    }
}

void percolateUp(int *a, int position, int isMinHeap)
{
    int parent = (position -1)/2;
    int temp;
    
    if (parent >=0)
    {
        if (comp(a[parent], a[position], isMinHeap))
        {
            temp = a[position];
            a[position] = a[parent];
            a[parent] = temp;
            percolateUp(a, parent, isMinHeap);
        }
    }
}

typedef struct Heap
{
    int capaicity;
    int size;
    int *array;
    int isMinHeap;
}Heap;

int HeapTop(Heap *hp)
{
    return hp->array[0];
}
int HeapSize(Heap *hp)
{
    return hp->size;
}

void heapify(int arr[], int size, int isMinhHeap)
{
    for (int i = (size)/2; i>=0; i--)
    {
        percollateDown(arr, i, size, isMinhHeap);
    }
}
void HeapInitialize(Heap *hp, int arr[], int size, int isMinHeap)
{
    hp->size = hp->capaicity = size;
    hp->array = arr;
    hp->isMinHeap = isMinHeap;
    heapify(arr, size, isMinHeap);
}
void HeapInitialize2(Heap *hp, int size, int isMinHeap)
{
    hp->size = 0;
    hp->capaicity = size;
    hp->isMinHeap = isMinHeap;
    hp->array = (int*)malloc((size+1) * sizeof(int));
}
void HeapAdd(Heap *hp, int value)
{
    if (hp->size == hp->capaicity)
    {
        return ;
    }
    hp->size++;
    hp->array[hp->size-1] = value;
    percolateUp(hp->array, hp->size-1, hp->isMinHeap);
}
int HeapRemove(Heap *hp)
{
    int value = hp->array[0];
    hp->array[0] = hp->array[hp->size -1];
    hp->size--;
    percollateDown(hp->array, 0, hp->size, hp->isMinHeap);
    return value;
}
void HeapSort(int arr[], int size, int inc)
{
    Heap hp;
    int *b = (int*)malloc(sizeof(int) * size);
    for (int i=0; i<size; i++)
    {
        b[i] = arr[i];
    }
    HeapInitialize(&hp, b, size, inc);
    for (int i=0; i<size; i++)
    {
        arr[i] = HeapRemove(&hp);
    }
}

void Sort(int arr[], int size, int isMinHeap)
{
    
}
int KthSmallest(int arr[], int size, int k)
{
    Sort(arr, size, 1);
    return arr[k-1];
}
int KthSmallest2(int arr[], int size, int k)
{
    Heap hp;
    HeapInitialize(&hp, arr, size, 1);
    int i=0;
    int value = 0;
    while (i<size && i<k)
    {
        value = HeapRemove(&hp);
        i += 1;
    }
    return value;
}

int KthLargestStream(int k)
{
    Heap hp;
    HeapInitialize2(&hp, 100, 1);
    int size = 0;
    int data;
    
    while (1)
    {
        printf("Data: ");
        scanf("%d", &data);
        if (size < k-1)
        {
            HeapAdd(&hp, data);
        } else {
            if (size == k-1) {
                HeapAdd(&hp, data);
            } else if (HeapTop(&hp) < data){
                HeapAdd(&hp, data);
                HeapRemove(&hp);
            }
            printf("%dth largest element: ", HeapTop(&hp));
        }
        size += 1;
    }
}

int isMinHeap(int arr[], int size)
{
    int lChild, rChild;
    for (int parent=0; parent<(size/2 +1); parent++)
    {
        lChild = parent *2 +1;
        rChild = parent *2 +2;
        
        if (((lChild < size) && (arr[parent] > arr[lChild])) || ((rChild < size) && (arr[parent] > arr[rChild])))
            return 0;
    }
    return 1;
}

int isMaxHeap(int arr[], int size)
{
    int lChild, rChild;
    for (int parent=0; parent<(size/2 +1); parent++)
    {
        lChild = parent *2 +1;
        rChild = lChild +1;
        
        if (((lChild < size) && (arr[parent] < arr[lChild])) || ((rChild < size) && (arr[parent] < arr[rChild])))
            return 0;
    }
    return 1;
}

int KSmallestProduct(int arr[], int size, int k)
{
    Sort(arr, size, 1);
    int product = 1;
    for (int i=0; i<k; i++)
    {
        product *= arr[i];
    }
    return product;
}
int KSmallestProduct2(int arr[], int size, int k)
{
    Heap hp;
    HeapInitialize(&hp, arr, size, 1);
    int i=0;
    int product = 1;
    while (i<size && i<k)
    {
        product *= HeapRemove(&hp);
        i += 1;
    }
    return product;
}
void swap(int arr[], int a, int b)
{
    
}
void QuickSelectUtil(int arr[], int lower, int upper, int k)
{
    if (upper <= lower)
        return;
    
    int pivot = arr[lower];
    int start = lower;
    int stop = upper;
    
    while (lower < upper)
    {
        while (lower < upper && arr[lower] <= pivot)
        {
            lower++;
        }
        while (lower <= upper && arr[upper] > pivot)
        {
            upper--;
        }
        if (lower < upper)
        {
            swap(arr, upper, lower);
        }
    }
    swap (arr, upper, start);
    if (k < upper){
        QuickSelectUtil(arr, start, upper-1, k);
    }
    if (k > upper){
        QuickSelectUtil(arr, upper+1, stop, k);
    }
}
int KSmallestProduct3(int arr[], int size, int k)
{
    QuickSelectUtil(arr, 0, size-1, k);
    int product = 1;
    
    for (int i=0; i<k; i++)
    {
        product *= arr[i];
    }
    return product;
}

void PrintLargerHalf(int arr[], int size)
{
    Sort(arr, size, 1);
    for (int i=size/2; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void printArray(int arr[], int size)
{
    
}
void PrintLargerHalf2(int arr[], int size)
{
    Heap hp;
    HeapInitialize(&hp, arr, size, 1);
    for (int i=0; i<size/2; i++)
    {
        HeapRemove(&hp);
    }
    printArray(arr, size/2);
}
void PrintLargerHalf3(int arr[], int size)
{
    QuickSelectUtil(arr, 0, size-1, size/2);
    for (int i=size/2; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortK(int arr[], int size, int k)
{
    Heap hp;
    HeapInitialize(&hp, arr, k, 1);
    int *output = (int*)malloc(sizeof(int)*size);
    int index =0;
    
    for (int i=k; i<size; i++)
    {
        output[index++] = HeapRemove(&hp);
        HeapAdd(&hp, arr[i]);
    }
    while(HeapSize(&hp) > 0)
    {
        output[index++] = HeapRemove(&hp);
    }
    for (int i=k; i<size; i++)
    {
        arr[i] = output[i];
    }
    printArray(output, index);
}

int findConsume(int cups[], int size)
{
    int time = 60;
    Sort(cups, size, 0);
    int total;
    int index, temp;
    
    while (time >0)
    {
        total += cups[0];
        cups[0] = ceil(cups[0] /2.0);
        index = 0;
        temp = cups[0];
        while(index < size -1 && temp < cups[index +1])
        {
            cups[index] = cups[index +1];
            index += 1;
        }
        cups[index] = temp;
        time -=1;
    }
    printf("Total &d ", total);
    return total;
}
int findConsume2(int cups[], int size)
{
    int time = 60;
    Heap hp;
    HeapInitialize(&hp, cups, size, 0);
    int total = 0;
    int value;
    
    while (time > 0)
    {
        value = HeapRemove(&hp);
        total += value;
        value = ceil(value / 2.0);
        HeapAdd(&hp, value);
        time -= 1;
    }
    printf("Total : %d \n", total);
    return total;
}

int JoinRopes(int ropes[], int size)
{
    Sort(ropes, size, 0);
    printArray(ropes, size);
    int total = 0;
    int value = 0;
    int temp, index;
    int length = size;
    
    while (length >= 2)
    {
        value = ropes[length -1] + ropes[length -2];
        total += value;
        index = length -2;
        while (index > 0 && ropes[index-1] < value)
        {
            ropes[index] = ropes[index-1];
            index -= 1;
        }
        ropes[index] = value;
        length--;
    }
    printf("Total : %d \n", total);
    return total;
}
int JoinRopes2(int ropes[], int size)
{
    Heap hp;
    HeapInitialize(&hp, ropes, size, 1);
    int total = 0;
    int value = 0;
    
    while (HeapSize(&hp) > 1)
    {
        value = HeapRemove(&hp);
        value += HeapRemove(&hp);
        HeapAdd(&hp, value);
        total += value;
    }
    printf("Total : &d ", total);
    return total;
}

typedef struct medianHeap
{
    Heap minHeap;
    Heap maxHeap;
} MedianHeap;
void MedianHeapInit(MedianHeap *heap)
{
    HeapInitialize2(&heap->minHeap, 100, 1);
    HeapInitialize2(&heap->maxHeap, 100, 0);
}
void MedianHeapAdd(MedianHeap *heap, int value)
{
    if (HeapSize(&heap->maxHeap) == 0 || HeapTop(&heap->maxHeap) >= value)
        HeapAdd(&heap->maxHeap, value);
    else
        HeapAdd(&heap->minHeap, value);
    
    if (HeapSize(&heap->maxHeap) > HeapSize(&heap->minHeap) +1)
    {
        value = HeapRemove(&heap->maxHeap);
        HeapAdd(&heap->minHeap, value);
    }
    if (HeapSize(&heap->minHeap) > HeapSize(&heap->maxHeap) +1)
    {
        value = HeapRemove(&heap->minHeap);
        HeapAdd(&heap->maxHeap, value);
    }
}
#define ERROR_VALUE -9999
int getMedian(MedianHeap *heap)
{
    if (HeapSize(&heap->maxHeap) == 0 && HeapSize(&heap->minHeap) == 0)
        return ERROR_VALUE;
    if (HeapSize(&heap->maxHeap) == HeapSize(&heap->minHeap)) {
        return (HeapTop(&heap->maxHeap) + HeapTop(&heap->minHeap)) /2;
    } else if (HeapSize(&heap->maxHeap) > HeapSize(&heap->minHeap)){
        return HeapTop(&heap->maxHeap);
    } else {
        return HeapTop(&heap->minHeap);
    }
}

int main(int argc, const char * argv[]) {
    
    KthLargestStream(9);
    
    return 0;
}
