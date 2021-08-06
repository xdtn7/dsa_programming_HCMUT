int binarySearch(int arr[], int left, int right, int x)
{
    if(left > right) return -1;
    
    int mid = (right + left)/2;
    if(x == arr[mid]) {
        cout << "We traverse on index: " << mid << endl;
        return mid;
    }
    else if(x > arr[mid]) {
        cout << "We traverse on index: " << mid << endl;
        return binarySearch(arr, mid + 1, right, x);
    }
    else {
        cout << "We traverse on index: " << mid << endl;
        return binarySearch(arr, left, mid -1, x);
    }
}
//-------------------------------------------------------------------
bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2)
{
   // TODO: If there are two pairs satisfy the condition, assign their values to pair1, pair2 and return true. Otherwise, return false.
   map<int, pair<int, int>> table;
   for(int i = 0; i < n; ++i) {
       for(int j = i + 1; j < n; ++j) {
           int sum = arr[i] + arr[j];
           if(table.find(sum) == table.end())
            table[sum] = make_pair(arr[i], arr[j]);
           else {
               pair1 = make_pair(arr[i], arr[j]);
               pair2 = make_pair(table[sum].first, table[sum].second);
               return true;
           }
       }
   }
   return false;
}
//----------------------------------------------------------------------------------------
int foldShift(long long key, int addressSize)
{
    long long res = 0;
    int n = to_string(key).length();
    int step = pow(10, addressSize);
    for(long long i=pow(10, n- addressSize); i>=0; i/=step, n-= addressSize){
        if(i<=1 && n!=0) {
            long long tmp = pow(10, n);
            res+=key % tmp;
            break;
        }
        res += (key/i)%step;
        res =res%step;
    }
    return res%step;
}

int rotation(long long key, int addressSize)
{
    long long res = 0;
    long long unit = pow(10, to_string(key).length()-1);
    long long rmd = key%10*unit;
    res = key/10 + rmd;
    return foldShift(res, addressSize);
}
//---------------------------------------------------------------------------
int interpolationSearch(int arr[], int left, int right, int x)
{
    if(left<= right && x >= arr[left] && x <= arr[right]){
        int n = right - left;
        int i = left + ((float)(n)/(arr[right]-arr[left]))*(x-arr[left]);
        cout << "We traverse on index: " << i << endl;
        if(x < arr[i]) return interpolationSearch(arr, left, i -1, x);
        else if(x > arr[i]) return interpolationSearch(arr, i+1, right, x);
        else return i;
    }
    return -1;
    
    
}
//--------------------------------------------------------------------------
int jumpSearch(int arr[], int x, int n) {
    int step = sqrt(n);
    int i;
    for(i=0;i<n;i+=step){
        cout<<i<<" ";
        if(arr[i]>x){
            for(int j=i-step+1; j <i;j++){
                cout<<j<<" ";
                if(arr[j]==x) return j;
            }
            return -1;
        }
        else if(arr[i]==x) return i;
    }
    for(i=i-step+1;i<n;i++){
        cout<<i<<" ";
        if(arr[i]==x) return i;
    }
    cout<<n<<" ";
    return -1;
    
}
//-----------------------------------------------------------------------------
long int midSquare(long int seed)
{
    return seed*seed/100%10000;
}
long int moduloDivision(long int seed, long int mod)
{
    return seed%mod;
}
long int digitExtraction(long int seed,int* extractDigits,int size)
{
    string str= to_string(seed);
    string res = "";
    for(int i =0; i<size;i++)
        res+=str[extractDigits[i]];
    
    return stol(res);
}
//----------------------------------------------------------------------
