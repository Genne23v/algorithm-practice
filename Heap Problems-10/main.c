//
//  main.c
//  Algorithm-10
//
//  Created by Wonkeun No on 2021-02-21.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findMaxInMinHeap(int *heap, int n)
{
    int half = n/2;
    int max_value = heap[half];
    
    for (int i= half+1; i<n; i++)
    {
        if (max_value < heap[i])
            max_value = heap[i];
    }
    return max_value;
}

int main(int argc, const char * argv[]) {
    int minHeap[] = {1, 2, 4, 10, 5, 6, 7};
    printf("max: %d\n", findMaxInMinHeap(minHeap, 7));
    return 0;
}
