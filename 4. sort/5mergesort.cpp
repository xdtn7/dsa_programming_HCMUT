// Given the method merge:

// template <typename T>

// void merge(T arr[],int left, int mid, int right);

// where arr is an array of type T, left is the index of the first element in the first half, mid is the index of the last element in the first half, right is the index of the last element in the second half. This method will merge the first sorted half (from left to mid) and the second sorted half (from mid+1 to right) into the sorted part (from left to right) of array arr.

// Based on the idea of merge sort, write method mergesort(T arr[], int left, int right) to sort a part (from left to right) of the array arr?

// The prototype of method mergesort is:

// template <typename T>

// void mergesort(T arr[],int left, int right);

// Your code starts at line 11.

template <typename T>
void mergesort(T arr[],int left, int right){
    if(left >= right) return;
    int i = (left+right)/2;
    mergesort(arr,left,i);
    mergesort(arr,i+1,right);
    merge(arr,left,i,right);
}