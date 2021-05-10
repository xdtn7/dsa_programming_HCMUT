// Write function findMax that returns the maximum index of the maximum value in the input array. 
// That means if the maximum value appears in many different indexes of the input array, the last 
// index is returned. Assume that the size of the input array is always greater than 0.

// The time complexity of your algorithm should be O(n).

// The prototype of function findMax is as follows:

// template <typename T>

// int findMax(T arr[],int n); // where arr is the input array and n is the size of the array.

// Your code starts at line 11.

template <typename T>
int findMax(T arr[], int n){
   int tmp = 0;
   for(int i = 1; i < n; i++) if(arr[tmp] <= arr[i]) tmp = i;
   return tmp;
}