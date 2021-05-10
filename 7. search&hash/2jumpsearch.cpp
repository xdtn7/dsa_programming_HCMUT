// Write function jumpsearch(T arr[],int n, T k,int j) to search key k in the ascending-sorted array arr with 
// size n using jump search method with j. The method return true if the key k is found in the array arr. 
// To make sure the function applying jump search, please print the values compared to key k during searching process. 
// These printed values are followed by commas. The prototype of the function is as follows:

// template <typename T>

// bool jumpsearch(T arr[], int n, T k, int j);

template <typename T>

bool jumpsearch(T arr[], int n, T k, int j){
    int i = 0;
    for(i = 0; i*j < n; i++){
        cout<<arr[i*j]<<",";
        if (k == arr[i*j]) {
            return true;
        }
        else if (k < arr[i*j]) {
            break;
        }
    }
    for(int l = (i-1)*j+1; l > 0 && l < i*j && l < n; l++){
        cout<<arr[l]<<",";
        if(k == arr[l]){
            
            return true;
        }
        else if( k < arr[l]){
            return false;
        }
    }
    return false;
}