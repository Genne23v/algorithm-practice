#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int one, int two)
{
    
}

typedef struct HT
{
    int i;
} HashTable;

void HashInit(HashTable *hs)
{
    
}

void HashAdd(HashTable *hs, int value)
{
}

void HashAdd2(HashTable *hs, int key, int value)
{
}

int HashFind(HashTable *hs, int value)
{
    return 1;
}

int HashGet(HashTable *hs, int value)
{
    return 1;
}

void HashRemove(HashTable *hs, int value)
{
}

typedef struct CT
{
    int i;
} Counter;

void CounterInit(Counter *hs)
{
}

void CounterAdd(Counter *hs, int value)
{
}

int CounterFind(Counter *hs, int value)
{
    return 1;
}

int CounterGetCount(Counter *hs, int value)
{
    return 1;
}

void CounterRemove(Counter *hs, int value)
{
}

void CounterDelete(Counter *hs, int value)
{
}

int more(int value1, int value2)
{
    return value1 > value2;
}

void Sort(int arr[], int size)
{
    int i, j, temp;
    for (i = 0; i < (size - 1); i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (more(arr[j], arr[j + 1]))
            {
                /* Swapping */
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printRepeating4(int arr[], int size)
{
    int *count = (int*)malloc(sizeof(int) * size);
    
    for (int i=0; i<size; i++){
        count[i] = 0;
    }
    
    printf("Identical Eleement:");
    for (int i=0; i<size; i++){
        if (count[arr[i]] == 1) {
            printf("%d", arr[i]);
        } else {
            count[arr[i]]++;
        }
    }
}

int removeeDuplicates(int arr[], int size)
{
    int j=0;
    if (size==0){
        return 0;
    }
//    Sort(arr, size);
    for (int i=1; i<size; i++){
        if (arr[i] != arr[j]){
            j++;
            arr[j] = arr[i];
        }
    }
    return j+1;
}
int findMissingNumber2(int data[], int size, int range)
{
    int xorSum = 0;
    for (int i=1; i<=range; i++){
        xorSum ^= i;
    }
    for (int i=0; i<size; i++){
        xorSum ^=data[i];
    }
    return xorSum;
}

void missingValues(int arr[], int size)
{
    Sort(arr, size);
    int value = arr[0];
    int i =0;
    printf("Missing values:");
    
    while(i<size){
        if (value == arr[i]){
            value +=1;
            i +=1;
        } else {
            printf(" %d ", value);
            value+=1;
        }
    }
}

void MissingValues2(int arr[], int size)
{
    HashTable ht;
    HashInit(&ht);
    
    int minVal = 99999;
    int maxVal = -99999;
    for (int i=0; i<size; i++){
        HashAdd(&ht, arr[i]);
        if (minVal > arr[i]){
            minVal = arr[i];
        }
        if (maxVal < arr[i]){
            maxVal = arr[i];
        }
    }
    
    for (int i=minVal; i<maxVal; i++){
        if (HashFind(&ht, i)==0){
            printf("%d", i);
        }
    }
}

void OddCount(int arr[], int size)
{
    Counter ctr;
    CounterInit(&ctr);
    int count;
    for (int i=0; i<size; i++){
        CounterAdd(&ctr, arr[i]);
    }
    for (int i=0; i<size; i++){
        count = CounterGetCount(&ctr, arr[i]);
        if (count>0 && count%2==1){
            printf("%d", count);
            CounterDelete(&ctr, arr[i]);
        }
    }
}

void OddCount2(int arr[], int size)
{
    int xorSum = 0;
    int first = 0;
    int second = 0;
    int setBit;
    
    for (int i=0; i<size; i++){
        xorSum = xorSum ^ arr[i];   //XOR sum, not numbers' sum
    }
    setBit = xorSum & ~(xorSum -1); //What is the idea? For 3 and 5, xorSum is 110. setBit is 010
    
    for (int i=0; i<size; i++){
        if (arr[i] & setBit){   //For 4, 4, 3, 5, 6, 6 => 010 & (101 || 011)
            first = first ^ arr[i];
        } else {
            second = second ^ arr[i];
        }
    }
    printf("%d & %d\n", first, second);
}

void SumDistinct(int arr[], int size)
{
    int sum =0;
    Sort(arr, size);
    
    for(int i=0; i<(size-1); i++){  //Because last one doesn't need to be compared
        if (arr[i] != arr[i+1]){
            sum += arr[i];
        }
    }
    sum += arr[size-1];
    printf("%d", sum);
}

void minAbsSumPair(int data[], int size)
{
    int minSum, sum, minFirst, minSecond;
    
    if(size<2) {
        printf("Invalid Input");
    }
    minFirst =0;
    minSecond =1;
    minSum = abs(data[0] + data[1]);
    for(int i =0; i<size; i++){
        for(int j=i+1; j<size; j++){
            sum = abs(data[i] + data[j]);
            if (sum<minSum){
                minSum = sum;
                minFirst =i;
                minSecond = j;
            }
        }
    }
    printf("The two elements with minimum sum are : %d, %d", data[minFirst], data[minSecond]);
}

void minAbsSumPair2(int data[], int size)
{
    int minSum, sum, minFirst, minSecond;
    
    if (size < 2){
        printf("Invalid Input");
    }
    Sort(data, size);
    
    minFirst =0;
    minSecond =size-1;
    minSum = abs(data[minFirst] + data[minSecond]);
    for(int i=0, j=size-1; i<j;){
        sum = (data[i] + data[j]);
        if (abs(sum) < minSum){
            minSum = abs(sum);
            minFirst = i;
            minSecond = j;
        }
        if (sum<0){
            i++;
        } else if (sum>0){
            j--;
        } else {
            break;
        }
    }
    printf("Two elements with minimum sum are : %d, %d", data[minFirst], data[minSecond]);
}

int FindPair(int data[], int size, int value)
{
    for(int i=0; i<size; i++){
        for(int j=i+1; i<size; j++){
            if ((data[i] + data[j]) == value){
                return 1;
            }
        }
    }
    return 0;
}

int FindPair2(int data[], int size, int value)
{
    int first=0, second=size-1;
    int curr;
    Sort(data, size);
    
    while(first<second){
        curr = data[first] + data[second];
        if (curr == value){
            printf("The pair is %d, %d", data[first], data[second]);
            return 1;
        } else if (curr < value){
            first++;
        } else {
            second--;
        }
    }
    return 0;
}

int FindPair3(int data[], int size, int value)
{
    HashTable hs;
    HashInit(&hs);
    
    for(int i=0; i<size; i++){
        if(HashFind(&hs, value-data[i])){
            printf("The pair is : %d, %d", data[i], (value-data[i]));
            return 1;
        }
        HashAdd(&hs, data[i]);
    }
    return 0;
}

int FindDifference(int arr[], int size, int value)
{
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(abs(arr[i] - arr[j]) == value){
                printf("The pair is : %d, %d", arr[i], arr[j]);
                return 1;
            }
        }
    }
    return 0;
}

int FindDifference2(int arr[], int size, int value)
{
    int first=0;
    int second=0;
    int diff;
    Sort(arr, size);
    
    while(first<second){
        diff = abs(arr[first] - arr[second]);
        if (diff == value){
            printf("The pair is : %d %d", arr[first], arr[second]);
            return 1;
        } else if (diff < value) {
            first +=1;
        } else {
            second +=1;
        }
    }
    return 0;
}

int findMinDiff(int arr[], int size)
{
    Sort(arr, size);
    int diff = 999999;
    
    for(int i=0; i<(size-1); i++){
        if ((arr[i+1] - arr[i]) < diff){
            diff = arr[i+1] = arr[i];
        }
    }
    return diff;
}

int minDiffPair(int arr1[], int size1, int arr2[], int size2)
{
    int minDiff = 999999;
    int first = 0;
    int second =0 ;
    int out1, out2, diff;
    Sort(arr1, size1);
    Sort(arr2, size2);
    
    while(first < size1 && second < size2){
        diff = abs(arr1[first] - arr2[second]);
        if (minDiff > diff){
            minDiff = diff;
            out1 = arr1[first];
            out2 = arr2[second];
        }
        if (arr1[first] < arr2[second]){
            first +=1;
        } else {
            second +=1;
        }
    }
    printf("The pair: %d, %d\n", out1, out2);
    printf("THe difference: %d", minDiff);
    
    return minDiff;
}

void ClosestPair(int arr[], int size, int value)
{
    int diff = 999999;
    int first = -1;
    int second = -1;
    int curr;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            curr = abs(value - (arr[i] + arr[j]));
            if (curr < diff){
                diff = curr;
                first = arr[i];
                second = arr[j];
            }
        }
    }
    printf("The closest pair is: %d, %d", first, second);
}

void ClosestPair2(int arr[], int size, int value)
{
    int first = 0, second = 0;
    int start = 0;
    int stop = size -1;
    int diff, curr;
    Sort(arr, size);
    diff = 999999;
    
    while(start < stop){
        curr = (value - (arr[start] + arr[stop]));
        if (abs(curr) < diff){
            diff = abs(curr);
            first = arr[start];
            second = arr[stop];
        }
        if (curr == 0){
            break;
        } else if (curr > 0) {
            start++;
        } else {
            stop--;
        }
    }
    printf("The closest pair is: %d, %d", first, second);
}

int SumPairRestArray(int arr[], int size)
{
    int total, low, high, curr, value;
    Sort(arr, size);
    total = 0;
    
    for(int i=0; i<size; i++){
        total += arr[i];
    }
    
    value = total/2;
    low =0;
    high = size-1;
    
    while(low<high){
        curr = arr[low] + arr[high];
        if (curr == value){
            printf("The pair is: %d, %d", arr[low], arr[high]);
            break;
        } else if ( curr > value) {
            high--;
        } else {
            low++;
        }
    }
    return 0;
}

void ZeroSumTripleets(int arr[], int size)
{
    for(int i=0; i<(size-2); i++){
        for(int j=i+1; j<(size-1); j++){
            for(int k=j+1; k<size; k++){
                if (arr[i] + arr[j] + arr[k] == 0){
                    printf("The triplet is: %d, %d, %d", arr[i], arr[j], arr[k]);
                }
            }
        }
    }
}

void ZeroSumTriplets2(int arr[], int size)
{
    int start, stop, i;
    Sort(arr, size);
    for (i=0; i<(size-2); i++){
        start = i+1;
        stop = size-1;
        
        while (start < stop){
            if (arr[i] + arr[start] + arr[stop] == 0){
                printf("The triplet is: %d, %d, %d", arr[i], arr[start], arr[stop]);
                start +=1;
                stop -=1;
            } else if (arr[i] + arr[start] + arr[stop] > 0){
                stop -=1;
            } else {
                start +=1;
            }
        }
    }
}

void findTriplet(int arr[], int size, int value)
{
    for (int i=0; i<(size-2); i++){
        for (int j=i+1; j<(size-1); j++){
            for (int k=j+1; k<size; k++){
                if (arr[i] + arr[j] + arr[k] == value){
                    printf("The triplet is: %d, %d, %d", arr[i], arr[j], arr[k]);
                }
            }
        }
    }
}

void findTriplet2(int arr[], int size, int value)
{
    int start, stop;
    Sort(arr, size);
    for (int i=0; i<size-2; i++){
        start = i+1;
        stop = size-1;
        
        while (start<stop){
            if (arr[i] + arr[start] + arr[stop] == value){
                printf("The triplet is: %d, %d, %d", arr[i], arr[start], arr[stop]);
                start +=1;
                stop -=1;
            } else if (arr[i] + arr[start] + arr[stop] > value){
                stop -=1;
            } else {
                start +=1;
            }
        }
    }
}

void ABCTriplet(int arr[], int size)
{
    int start, stop;
    Sort(arr, size);
    
    for(int i=0; i<(size-2); i++){
        start = i+1;
        stop = size-1;
        while (start < stop){
            if (arr[i] == arr[start] + arr[stop]){
                printf("The triplet is: %d, %d, %d", arr[i], arr[start], arr[stop]);
                start +=1;
                stop -=1;
            } else if (arr[i] > arr[start] + arr[stop]){
                start +=1;
            } else {
                stop -=1;
            }
        }
    }
}

void SmallerThanTripletCount(int arr[], int size, int value)
{
    int start, stop;
    int count =0;
    Sort(arr, size);
    
    for(int i=0; i<(size-2); i++){
        start = i+1;
        stop = size -1;
        while(start < stop){
            if (arr[i] + arr[start] + arr[stop] >= value){
                stop -=1;
            } else {
                count += stop - start;  //What does this count mean?
                start +=1;
            }
        }
    }
    printf("%d", count);
}

void APTriplets(int arr[], int size)
{
    int i, j, k;
    for(i=1; i < (size-1); i++){
        j = i-1;
        k = i+1;
        while (j >= 0 && k < size){
            if (arr[j] + arr[k] == 2 * arr[i]){
                printf("The triplet is: %d, %d, %d", arr[j], arr[i], arr[k]);
                k +=1;
                j -=1;
            } else if (arr[j] + arr[k] < 2 * arr[i]){
                k +=1;
            } else {
                j -=1;
            }
        }
    }
}

void GPTriplets(int arr[], int size)
{
    int i;
    for(i=1; i < size-1; i++){
        int j = i-1;
        int k = i+1;
        
        if (arr[i] * arr[i] == arr[j] * arr[k]){
            printf("The triplet is: %d, %d, %d", arr[i], arr[j], arr[k]);
            j -= 1;
            k += 1;
        } else if (arr[i] * arr[i] > arr[j] * arr[k]) {
            k +=1;
        } else {
            j -=1;
        }
    }
}

int numberOfTriangles(int arr[], int size)
{
    int i, j, k, count = 0;
    
    for (i=0; i < size-2; i++){
        for (j=i+1; j < size-1; j++){
            for (k=j+1; k < size; k++){
                if (arr[i] + arr[j] > arr[k]){
                    count +=1;
                }
            }
        }
    }
    return count;
}

int numberOfTriangles2(int arr[], int size)
{
    int i, j, k, count =0;
    Sort(arr, size);
    
    for (i=0; i<(size-2); i++){
        k = i+2;
        for (j=i+1; j<(size-1); j++){
            while (k < size && arr[i] + arr[j] > arr[k]){
                k +=1;
            }
            count += k-j-1;
        }
    }
    return count;
}

int getMax(int data[], int size)
{
    int max = data[0], count = 1, maxCount =1;
    for(int i=0; i < size; i++){
        count =1;
        for(int j=i+1; j < size; j++){
            if (data[i] == data[j])
            count ++;
        }
        if (count > maxCount){
            max = data[i];
            maxCount = count;
        }
    }
    return max;
}

int getMax2(int data[], int size)
{
    int max = data[0], maxCount = 1;
    int curr = data[0], currCount = 1;
    Sort(data, size);
    
    for(int i=1; i < size; i++){
        if (data[i] == data[i-1]){
            currCount++;
        } else {
            currCount = 1;
            curr = data[i];
        }
        if (currCount > maxCount){
            maxCount = currCount;
            max = curr;
        }
    }
    return max;
}

int getMax3(int data[], int size, int range)
{
    int max = data[0], maxCount = 1;
    
    int *count = (int*)malloc(sizeof(int)*range);
    for (int i=0; i < size; i++){
        count[data[i]]++;
        if (count[data[i]] > maxCount){
            maxCount = count[data[i]];
            max = data[i];
        }
    }
    return max;
}

int getMajority(int data[], int size)
{
    int max = 0, count = 0, maxCount = 0;
    for(int i=0; i < size; i++){
        for (int j=i+1; j < size; j++){
            if (data[i]=data[j]){
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            max = data[i];
        }
    }
    if (maxCount > size/2){
        return max;
    } else {
        printf("Majority does not exist");
        return 0;
    }
}

int getMajority2(int data[], int size)
{
    int majIndex = size / 2, count = 1;
    Sort(data, size);
    int candidate = data[majIndex];
    count =0;
    
    for (int i=0; i < size; i++) {
        if (data[i] == candidate){
            count++;
        }
    }
    
    if (count > size /2){
        return data[majIndex];
    } else {
        printf("Majority does not exist");
        return 0;
    }
}

int getMajority3(int data[], int size)
{
    int majIndex = 0, count = 1;
    int candidate;
    
    for (int i=1; i < size; i++){
        if (data[majIndex] == data[i]){
            count++;
        } else {
            count--;
        }
        if (count ==0){
            majIndex = i;
            count =1;
        }
    }
    candidate = data[majIndex];
    count = 0;
    
    for (int i=0; i < size; i++){
        if (data[i] == candidate) {
            count++;
        }
    }
    if (count > size/2){
        return data[majIndex];
    } else {
        printf("Majority does not exist");
        return 0;
    }
}

int FirstIndex(int arr[], int size, int low, int high, int value)
{
    int mid;
    if (high >= low){
        mid = (low + high)/2;
    }
    if ((mid == 0 || arr[mid-1] < value) && (arr[mid] == value)){
        return mid;
    } else if (arr[mid] < value){
        return FirstIndex(arr, size, mid+1, high, value);
    } else {
        return FirstIndex(arr, size, low, mid-1, value);
    }
    return -1;
}
int isMajority(int arr[], int size)
{
    int i;
    int majority = arr[size/2];
    i = FirstIndex(arr, size, 0, size-1, majority);
    
    if (((i + size/2) <= (size-1)) && arr[i + size/2] == majority){
        return 1;
    } else {
        return 0;
    }
}

int SearchBotinicArrrayMax(int data[], int size)
{
    int start = 0, end = size-1;
    int mid = (start + end)/2;
    int maximumFound = 0;
    if (size < 3){
        printf("Invalid Input");
    }
    while (start <= end){
        mid = (start + end) /2;
        if (data[mid-1] < data[mid] && data[mid] > data[mid+1]){
            maximumFound =1;
            break;
        } else if (data[mid-1] < data[mid] && data[mid] < data[mid+1]){
            start = mid+1;
        } else if (data[mid-1] > data[mid] && data[mid] > data[mid+1]) {
            end = mid-1;
        } else {
            break;
        }
        
        if (maximumFound == 0){
            printf("No Maxima Found");
            return 0;
        }
    }
    return data[mid];
}

int FindMaxBitonicArray(int data[], int size)
{
    int start = 0, end = size-1, mid;
    
    if (size < 3){
        printf("Invalid Input");
    }
    while (start <= end){
        mid = (start + end)/2;
        if (data[mid-1] < data[mid] && data[mid] > data[mid+1]){
            return mid;
        } else if (data[mid-1] < data[mid] && data[mid] < data[mid+1]){
            start = mid +1;
        } else if (data[mid-1] > data[mid] && data[mid] > data[mid+1]){
            end = mid-1;
        } else {
            break;
        }
    }
    printf("Maxima not found");
    return -1;
}
int BinarySearch(int data[], int start, int end, int key, int isInc)
{
    int mid;
    if (end < start)
        return -1;
    
    mid = (start + end)/2;
    if (key == data[mid])
        return mid;
    
    if ((isInc != 0 && key < data[mid]) || (isInc == 0 && key > data[mid])){
        return BinarySearch(data, start, mid-1, key, isInc);
    } else {
        return BinarySearch(data, mid+1, end, key, isInc);
    }
}
int SearchBitonicArray(int data[], int size, int key)
{
    int max = FindMaxBitonicArray(data, size);
    int k = BinarySearch(data, 0, max, key, 1);
    if (k != -1){
        return k;
    } else {
        return BinarySearch(data, max+1, size-1, key, 0);
    }
}

int findLastIndex(int data[], int size, int start, int end, int key)
{
    int mid;
    if (end < start)
        return -1;
    
    mid = (start + end)/2;
    if (key == data[mid] && (mid == end || data[mid+1] != key))
        return mid;
    
    if (key < data[mid]){
        return findLastIndex(data, size, start, mid-1, key);
    } else {
        return findLastIndex(data, size, mid+1, end, key);
    }
}
int findFirstIndex(int data[], int size, int start, int end, int key)
{
    int mid;
    if (end < start)
        return -1;
    
    mid = (start + end)/2;
    if (key == data[mid] && (mid == start || data[mid-1] != key))
        return mid;
    
    if (key < data[mid]){
        return findLastIndex(data, size, start, mid-1, key);
    } else {
        return findLastIndex(data, size, mid+1, end, key);
    }
}
int findKeyCount(int data[], int size, int key)
{
    int firstIndex, lastIndex;
    firstIndex = findFirstIndex(data, size, 0, size-1, key);
    lastIndex = findLastIndex(data, size, 0, size-1, key);
    
    return (lastIndex - firstIndex +1);
}

void maxProfit(int stocks[], int size)
{
    int buy =0, sell =0;
    int curMin = 0;
    int currProfit = 0;
    int maxProfit = 0;
    
    for (int i=0; i<size; i++){
        if (stocks[i] < stocks[curMin]){
            curMin = i;
        }
        currProfit = stocks[i] - stocks[curMin];
        
        if (currProfit > maxProfit){
            buy = curMin;
            sell = i;
            maxProfit = currProfit;
        }
    }
    printf("Purchase day is: %d at price: %d\n", buy, stocks[buy]);
    printf("Sell day is: %d at price: %d\n", sell, stocks[sell]);
}

int findMedian(int dataFirst[], int sizeFirst, int dataSecond[], int sizeSecond)
{
    int medianIndex = ((sizeFirst + sizeSecond) + (sizeFirst + sizeSecond) %2) /2;  //cealing func
    int i=0, j=0;
    int count =0;
    
    while(count < medianIndex -1){
        if (i < sizeFirst-1 && dataFirst[i] < dataSecond[j]){
            i++;
        } else {
            j++;
        }
        count++;
    }
    if (dataFirst[i] < dataSecond[j]){
        return dataFirst[i];
    } else {
        return dataSecond[j];
    }
}

int BinarySearch01Util(int data[], int start, int end)
{
    int mid;
    if (end < start){
        return -1;
    }
    mid = (start + end)/2;
    if (data[mid] == 1 && data[mid-1] == 0){
        return mid;
    }
    if (data[mid] == 0){
        return BinarySearch01Util(data, mid+1, end);
    } else {
        return BinarySearch01Util(data, start, mid-1);
    }
}
int BinarySearch01(int data[], int size)
{
    if (size == 1 && data[0] ==1){
        return 0;
    }
    return BinarySearch01Util(data, size, -1);
}

int RotationMaxUtil(int arr[], int start, int end)
{
    int mid;
    if (end <= start){
        return arr[start];
    }
    mid = (start + end)/2;
    if (arr[mid] > arr[mid+1])
        return arr[mid];
    
    if (arr[start] <= arr[mid]){
        return RotationMaxUtil(arr, mid+1, end);
    } else {
        return RotationMaxUtil(arr, start, mid-1);
    }
}
int RotationMax(int arr[], int size)
{
    return RotationMaxUtil(arr, 0, size-1);
}

int FindRotationMaxUtil(int arr[], int start, int end)
{
    int mid;
    if (end <= start)
        return start;
    
    mid = (start + end) /2;
    if (arr[mid] > arr[mid+1])
        return mid;
    
    if (arr[start] <= arr[mid]){
        return FindRotationMaxUtil(arr, mid+1, end);
    } else {
        return FindRotationMaxUtil(arr, start, mid-1);
    }
}
int FindRotationMax(int arr[], int size)
{
    return FindRotationMaxUtil(arr, 0, size-1);
}
int CountRotation(int arr[], int size)
{
    int maxIndex = FindRotationMaxUtil(arr, 0, size-1);
    return (maxIndex +1) % size;
}

int BinarySearchRotateArrayUtil(int data[], int start, int end, int key)
{
    int mid;
    if (end < start)
        return -1;
    
    mid = (start + end) /2;
    if (key == data[mid])
        return mid;
    
    if (data[mid] > data[start]){
        if (data[start] <= key && key < data[mid]){
            return BinarySearchRotateArrayUtil(data, start, mid-1, key);
        } else {
            return BinarySearchRotateArrayUtil(data, mid+1, end, key);
        }
    } else {
        if (data[mid] < key && data[end] >= key){
            return BinarySearchRotateArrayUtil(data, mid+1, end, key);
        } else {
            return BinarySearchRotateArrayUtil(data, start, mid-1, key);
        }
        
    }
}
int BinarySearchRotateArray(int data[], int size, int key)
{
    return BinarySearchRotateArrayUtil(data, 0, size-1, key);
}

int minAbsDiffAdjCircular(int arr[], int size)
{
    int diff = 999999;
    if (size < 2)
        return -1;
    
    for (int i=0; i<size; i++){
        if (abs(arr[i] - arr[(i+1) % size]) < diff){
            diff = abs(arr[i] - arr[(i+1) % size]);
        }
    }
    return diff;
}

void transformArrayAB1(int data[], int size)
{
    int N = size /2;
    for (int i=1; i<N; i++){
        for (int j=0; j<i; j++){
            //swap(data, N-i + 2*j, N-i +2*j + 1);  For 8 elements, (3,4)->(2,3)(4,5)->(1,2)(3,4)(5,6)
        }
    }
}

int checkPermutation(int data1[], int size1, int data2[], int size2)
{
    if (size1 != size2)
        return 0;
    
    Sort(data1, size1);
    Sort(data2, size2);
    
    for(int i=0; i<size1; i++){
        if (data1[i] != data2[i])
            return 0;
    }
    return 1;
}

int checkPermutation2(int array1[], int size1, int array2[], int size2)
{
    int i;
    if (size1 != size2)
        return 0;
    
    HashTable hs;
    HashInit(&hs);
    
    for (i=0; i<size1; i++){
        HashAdd(&hs, array1[i]);
    }
    for (i=0; i<size2; i++){
        if (!HashFind(&hs, array2[i]))
            return 0;
    }
    return 1;
}

int FindElementIn2DArray(int **arr, int r, int c, int value)
{
    int row =0;
    int column = c-1;
    while (row < r && column >= 0){
        if (arr[row][column] == value){
            return 1;
        } else if (arr[row][column] > value){
            column -=1;
        } else {
            row +=1;
        }
    }
    return 0;
}

int isAP(int arr[], int size)
{
    int diff;
    if (size <=1)
        return 1;
    
    Sort(arr, size);
    diff = arr[1] - arr[0];
    for (int i=2; i<size; i++){
        if (arr[i] - arr[i-1] != diff)
            return 0;
    }
    return 1;
}
int isAP2(int arr[], int size)
{
    int first = 999999;
    int second = 999999;
    int diff, value;
    HashTable hs;
    HashInit(&hs);
    
    for (int i=0; i<size; i++){
        if (arr[i] < first){
            second = first;
            first = arr[i];
        } else if (arr[i] < second){
            second = arr[i];
        }
    }
    diff = second - first;
    
    for (int i=0; i<size; i++){
        if (HashFind(&hs, arr[i]))
            return 0;
        HashAdd(&hs, arr[i]);
    }
    for (int i=0; i<size; i++){
        value = first + i *diff;
        if (!HashFind(&hs, value) || HashGet(&hs, value) != 1)
            return 0;
    }
    return 1;
}

int isAP3(int arr[], int size)
{
    int first = 999999;
    int second = 999999;
    int *count = (int*)calloc(0, size);
    int diff, index;
    for (int i=0; i<size; i++){
        if (arr[i] < first){
            second = first;
            first = arr[i];
        } else if (arr[i] < second){
            second = arr[i];
        }
    }
    diff = second - first;
    
    for (int i=0; i<size; i++){
        index = (arr[i] - first) / diff;
    }
    if (index > size-1 || count[index] != 0){
        return 0;
    }
    count[index] =1;
    
    for (int i=0; i<size; i++){
        if (count[i] != 1){
            return 0;
        }
    }
    return 1;
}

int findBalancedPoint(int arr[], int size)
{
    int first = 0;
    int second = 0;
    for (int i=1; i<size; i++){
        second += arr[i];
    }
    
    for (int i=0; i<size; i++){
        if (first == second){
            printf("%d\n", i);
            return i;
        }
        if (i < size-1){
            first += arr[i];
        }
        second -= arr[i+1];
    }
    return -1;
}

int findFloor(int arr[], int size, int value)
{
    int start = 0;
    int stop = size-1;
    int mid;
    while(start <= stop){
        mid = (start+stop) /2;
        
        if (arr[mid] == value || arr[mid] < value && (mid == size-1 || arr[mid+1] > value)){
            return mid;
        } else if (arr[mid] < value){
            start = mid+1;
        } else {
            stop = mid-1;
        }
    }
    return -1;
}
int findCeil(int arr[], int size, int value)
{
    int start = 0;
    int stop = size-1;
    int mid;
    while(start <= stop){
        mid = (start+stop) /2;
        
        if (arr[mid] == value || (arr[mid] > value && (mid == 0 || arr[mid-1] < value))){
            return mid;
        } else if (arr[mid] < value){
            start = mid+1;
        } else {
            stop = mid-1;
        }
    }
    return -1;
}

int ClosestNumber(int arr[], int size, int num)
{
    int start = 0;
    int stop = size-1;
    int output = -1;
    int minDist = 9999;
    int mid;
    while(start < stop){
        mid = (start + stop) /2;
        if (minDist > abs(arr[mid] - num)){
            minDist = abs(arr[mid] - num);
            output = arr[mid];
        }
        if (arr[mid] == num){
            break;
        } else if (arr[mid] > num){
            stop = mid-1;
        } else {
            start = mid+1;
        }
    }
    return output;
}

int DuplicateKDistance(int arr[], int size, int k)
{
    HashTable hs;
    for (int i=0; i<size; i++){
        if (HashFind(&hs, arr[i]) && i - HashGet(&hs, arr[i]) <= k){    //HashGet finds location of the element in the array
            printf("%d, %d, %d", arr[i], HashGet(&hs, arr[i]), i);
            return 1;
        } else {
            HashAdd2(&hs, arr[i], i);
        }
    }
    return 0;
}

void frequencyCounts(int arr[], int size)
{
    int index;
    for (int i=0; i<size; i++){
        while(arr[i] > 0){
            index = arr[i]-1;
            if (arr[index] > 0){
                arr[i] = arr[index];
                arr[index] = -1;
            } else {
                arr[index] -= 1;
                arr[i] = 0;
            }
        }
    }
    for (int i=0; i<size; i++){
        printf("%d : %d \n", i+1, abs(arr[i]));
    }
}

void KLargestElement(int arrIn[], int size, int k)
{
    int *arr = (int*)malloc(size * sizeof(int));
    for (int i=0; i<size; i++){
        arr[i] = arrIn[i];
    }
    Sort(arr, size);
    for (int i=0; i<size; i++){
        if (arrIn[i] >= arr[size-k]){
            printf(" %d ", arrIn[i]);
        }
    }
}

void QuickSelectUtil(int arr[], int lower, int upper, int k)
{
    if (upper <= lower)
        return;

    int pivot = arr[lower];
    int start = lower;
    int stop = upper;

    while (lower < upper) {
        while (arr[lower] <= pivot) {
            lower++;
        }
        while (arr[upper] > pivot) {
            upper--;
        }
        if (lower < upper) {
            swap(arr, upper, lower);
        }
    }

    swap(arr, upper, start); // upper는 피벗의 위치입니다.
    if (k < upper)
        QuickSelectUtil(arr, start, upper - 1, k); // pivot - 1은 왼쪽 부분 배열의 상위 인덱스입니다.
    if (k > upper)
        QuickSelectUtil(arr, upper + 1, stop, k); // pivot + 1은 오른쪽 부분 배열의 하위 인덱스입니다.
}
void KLargestElement2(int arrIn[], int size, int k)
{
    int *arr = (int*)malloc(size * sizeof(int));
    for (int i=0; i<size; i++){
        arr[i] = arrIn[i];
    }
    QuickSelectUtil(arr, 0, size-1, size-k);
    for (int i=0; i<size; i++){
        if (arrIn[i] >= arr[size-k]){
            printf("%d ", arrIn[i]);
        }
    }
}

int FixPoint(int arr[], int size)
{
    for (int i=0; i<size; i++){
        if (arr[i] == i){
            return i;
        }
    }
    return -1;
}

int FixPoint2(int arr[], int size)
{
    int low = 0;
    int high = size-1;
    int mid;
    while(low <= high){
        mid = (high + low) /2;
        if (arr[mid] == mid){
            return mid;
        } else if (arr[mid] > mid){
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return -1;
}

void subArraySums(int arr[], int size, int value)
{
    int first = 0;
    int second = 0;
    int sum = arr[first];
    while(second < size && first < size){
        if (sum == value){
            printf("%d, %d", first, second);
        }
        if (sum < value){
            second +=1;
            if (second < size){
                sum += arr[second];
            }
        } else {
            sum -= arr[first];
            first += 1;
        }
    }
}

int maxConSub(int arr[], int size)
{
    int currMax = 0;
    int maximum = 0;
    for (int i=0; i<size; i++){
        //currMax = max(arr[i], currMax + arr[i]);
        if (currMax < 0){
            currMax = 0;
        }
        if (maximum < currMax){
            maximum = currMax;
        }
    }
    printf("%d", maximum);
    return maximum;
}

void MaxConSubArr(int arr1[], int size1, int arr2[], int size2)
{
    int currMax = 0;
    int maximum = 0;
    HashTable hs;
    HashInit(&hs);
    
    for (int i=0; i<size2; i++){
        HashAdd(&hs, arr2[i]);
    }
    for (int i=0; i<size1; i++){
        if (HashFind(&hs, arr1[i])){
            currMax = 0;
        }else {
//            currMax = max(arr1[i], currMax + arr1[i]);
            if (currMax < 0){
                currMax = 0;
            }
            if (maximum < currMax){
                maximum = currMax;
            }
        }
    }
    printf(" %d ", maximum);
}

int MaxConSubArr2(int arr1[], int size1, int arr2[], int size2)
{
    Sort(arr2, size2);
    int currMax = 0;
    int maximum = 0;
    
    for (int i=0; i<size1; i++){
        if (BinarySearch(arr2, size2, arr1[i])){
            currMax = 0;
        } else {
            currMax = max(arr1[i], currMax + arr1[i]);
            if (currMax < 0) {
                currMax = 0;
            }
            if (maximum < currMax){
                maximum = currMax;
            }
        }
    }
    printf(" %d ", maximum);
    return maximum;
}

void RainWater(int arr[], int size)
{
    int water = 0;
    int *leftHigh = (int*)calloc(size, sizeof(int));
    int *rightHigh = (int*)calloc(size, sizeof(int));
    int max = arr[0];
    leftHigh[0] = arr[0];
    
    for (int i=1; i<size; i++){
        if (max < arr[i]){
            max = arr[i];
        }
        leftHigh[i] = max;
    }
    max = arr[size-1];
    rightHigh[size-1] = arr[size-1];
    
    for (int i=(size-2); i>=0; i--){
        if (max < arr[i]){
            max = arr[i];
        }
        rightHigh[i] = max;
    }
    
    for (int i=0; i<size; i++){
        water += min(leftHigh[i], rightHigh[i]) - arr[i];
    }
    printf("The amount of rain water: ", water);
}

int RainWater2(int arr[], int size)
{
    int water = 0;
    int leftMax = 0, rightMax = 0;
    int left = 0;
    int right = size-1;
    
    while(left <= right){
        if (arr[left] < arr[right]){
            if (arr[left] > leftMax){
                leftMax = arr[left];
            } else {
                water += leftMax - arr[left];
            }
            left += 1;
        } else {
            if (arr[right] > rightMax){
                rightMax = arr[right];
            } else {
                water += rightMax - arr[right];
            }
            right -= 1;
        }
    }
    printf("The amount of rain water: %d", water);
}

int main() {
    int arr[] = {2, 1, 4, 7, 3, 4, 5, 3, 1, 4, 4, 2};
    
    //printf("%d", findMissingNumber2(arr, 5, 6));
    //missingValues(arr, 5);
    //OddCount2(arr, 12);
    //SumDistinct(arr, 12);
    //int data[] = {4, 3, -2, 5, -3, 1, -5, 2, -1, 9};
//    minAbsSumPair2(data, 10);
//    ClosestPair2(arr, 12, 4);
//    int data[] = {11, 4, 6, 3, 7, 1, 2, 12, 9, 8, 10};
//    SumPairRestArray(data, 8);
//    SmallerThanTripletCount(data, 11, 9);
//    int triangle[] = {1, 2, 3, 4, 5};
//    printf("%d", numberOfTriangles2(triangle, 5));
//    int data[] = {1, 2, 2, 2, 2, 3, 4};
//    printf("%d", getMajority3(data, 7));
//    printf("%d", isMajority(data, 7));
//    int data[] = {1, 2, 3, 4, 5, 6, 9, 11, 10, 8, 7};
//    printf("%d", SearchBitonicArray(data, 11, 9));
//    int stocks[] = {350, 375, 411, 370, 405, 511, 543, 499, 606, 523};
//    maxProfit(stocks, 10);
//    int data[] = {5, 29, 18, 51, 11};
//    printf("%d", minAbsDiffAdjCircular(data, 5));
//    int data[] = {-7, 1, 5, 2, -4, 3, 0};
//    printf("%d", findBalancedPoint(data, 7));
//    int data[] = {1, 2, 3, 1, 4, 5};
//    printf("%d", DuplicateKDistance(data, 6, 3));
    int data[] ={4, 2, 3, 2, 2, 1, 3, 1, 1};
    frequencyCounts(data, 9);
    
    return 0;
}



