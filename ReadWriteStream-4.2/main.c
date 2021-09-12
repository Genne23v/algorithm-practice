#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct node_T
{
    int id;
    int value;
}Node;

typedef struct PQ
{
    Node heap[MAX_SIZE];
    int size;
    const Node END={-1,-1};
    
    PQ() {
        size=0;
    }
    
    void swap(Node *lhs, Node *rhs){
        Node tmp = *lhs;
        *lhs = *rhs;
        *rhs = tmp;
    }
    
    int insert(Node element){
        if(size+1 > MAX_SIZE){
            return 0;
        }
        heap[size] = element;
        int cur = size;
        int parent = (size-1)/2;
        
        while(cur>0 && heap[cur].value > heap[parent].value){
            swap(&heap[cur], &heap[parent]);
            cur=parent;
            parent = (parent-1)/2;
        }
        size++;
        return 1;
    }
    
    Node top(){
        if (size<=0){
            return END;
        }
        return heap[0];
    }
    
    void pop(){
        if(size<=0){
            return;
        }
        size--;
        heap[0] = heap[size];
        int cur =0;
        int left = cur*2+1;
        int right = cur*2+2;
        int maxNode = cur;
        
        while (left<size) {
            if (heap[maxNode].value < heap[left].value){
                maxNode = left;
            }
            if (right < size && heap[maxNode].value < heap[right].value){
                maxNode =right;
            }
            if (maxNode ==cur) {
                break;
            } else {
                swap(&heap[cur], &heap[maxNode]);
                cur = maxNode;
                left = cur*2+1;
                right = cur*2+2;
            }
        }
    }
    
    bool empty(){
        if (size==0){
            return true;
        }
        return false;
    }
}PQ;

PQ g_pq;

void ReadNumber(int arr[], int i, int id)
{
    g_pq.insert({id, arr[i]});
}

Node WriteNumber()
{
    Node ret = g_pq.top();
    g_pq.pop();
    return ret;
}

int main() {
    int inputA[] = {1, 4, 8};
    int inputB[] = {3, 2};
    
    int lenA = sizeof(inputA)/sizeof(int);
    int lenB = sizeof(inputB)/sizeof(int);
    
    int iA = 0;
    int iB = 0;
    
    ReadNumber(inputA, iA++, 0);
    ReadNumber(inputB, iB++, 1);
    
    while(!g_pq.empty()){
        Node n = WriteNumber();
        if(n.id ==0 && iA<lenA){
            ReadNumber(inputA, iA++, 0);
        } else if (n.id ==1 && iB<lenB){
            ReadNumber(inputA, iB++, 1);
        }
        printf("id: %d, value: %d\n", n.id, n.value);
    }
    return 0;
}
