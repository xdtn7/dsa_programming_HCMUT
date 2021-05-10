// Write function binarysearch(T arr[],int left, int right, T k) to search key k in the ascending-sorted array arr with lower 
// bound index left and upper bound index right using binary search method. The method return true if the key k is found in 
// the array arr, otherwise it returns false. To make sure the function applying binary search, please print the values 
// (followed by comma) compared to key k during searching process. The prototype of the function is as follows:

// template <typename T>

// bool binarysearch(T arr[], int left, int right, T k);

template <typename T>

bool binarysearch(T arr[], int left, int right, T k){
    if(left > right) return false;
    int mid = (right-left)/2 + left;
    if (k == arr[mid]) {
        cout<<arr[mid]<<",";
        return true;
    }
    else if (k > arr[mid]) {
        cout<<arr[mid]<<",";
        return binarysearch(arr, mid +1, right, k);
    }
    else {
        cout<<arr[mid]<<",";
        return binarysearch(arr, left , mid -1, k);
    }
}