template <class T>
void SLinkedList<T>::bubbleSort()
{
    if (this->head == NULL || this->head->next == NULL) return;
    Node *curr = this->head;
    for (int i = 0; i < this->size() - 1; ++i) {
        curr = this->head;
        for (int j = 0; j < this->size() - i - 1; ++j, curr = curr->next) {
            if (curr->data > curr->next->data) {
                swap(curr->data, curr->next->data);
            }
        }
        this->printList();
    }
}
//--------------------------------------------------------------------------------
/* Your helping functions go here */
bool isPermutation (string a, string b) {
    while(true){
        if(a.length()==0) return true;
        char e = a[0];
        size_t i = b.find(e);
        if(i!= string::npos){
            a.erase(a.begin());
            b.erase(i,1);
        }
        else return false;
    }
}
//----------------------------------------------------------------------------------
template <class T>
T *Sorting<T>::Partition(T *start, T *end)
{   
    cout<<"Quick sort: ";
    printArray(start, end);
    T pivot = start[0];
    int low = 0, high = end - start;
    
    while (low < high) {
        do {
            low++;
        }
        while (start[low] <= pivot);
            
        do {
            high--;
        }
        while (start[high] > pivot);
        
        if (low < high) {
            T tmp = start[high];
            start[high] = start[low];
            start[low] = tmp;
        }
    }   
    
    T tmp = start[high];
    start[high] = start[0];
    start[0] = tmp;
    return &start[high];
}

template <class T>
void Sorting<T>::insertionSort(T *start, T *end)
{
    cout<<"Insertion sort: ";
    printArray(start, end);
    int pos = 0;
    int size = end -start;
    while(pos < size){
        for(int i = 0; i < pos; i++){
            if(start[i] > start[pos]){
                T tmp = start[pos];
                for(int j = pos; j > i; j--){
                    start[j] = start[j-1];
                }
                start[i] = tmp;
            }
        }
        pos++;
    }
}

template <class T>
void Sorting<T>::hybridQuickSort(T *start, T *end, int min_size)
{
    int size = end - start;
    if(size == 0) return;
    if(size < min_size){
        insertionSort(start, end);
        return;
    }
    else{
        T* pivot = Partition(start, end);
        
        hybridQuickSort(start, pivot, min_size);
        hybridQuickSort(&pivot[1], end, min_size);
    }
    
    
}
//--------------------------------------------------------------------------


static void merge(T* left, T* middle, T* right){
    /*TODO*/
    int mid = middle - left;
    int last = right-left;
    for(int i = mid-1; i >= 0; i--){
        if(left[i] < left[mid]) continue;
        T tmp = left[i];
        for(int j = mid; j <= last; j++){
            if(left[j]<tmp){
                left[j-1] = left[j];
                if(j == last) {
                    left[j] = tmp;
                    mid--;
                    break;
                }
            }
            else {
                left[j-1] = tmp;
                mid--;
                break;
            }
        }
    }
    Sorting::printArray(left, right);
}
static void mergeSort(T* start, T* end){
    /*TODO*/
    if(end<=start) return;
    T* mid = &start[(end-start)/2+1];
    mergeSort(start, mid-1);
    mergeSort(mid, end);
    merge(start, mid, end);
}
//-----------------------------------------------------------------------
template <class T>
void Sorting<T>::oddEvenSort(T *start, T *end)
{
    /*TODO*/
    int last = end-start;
    bool sw = 1;
    while(sw){
        sw = 0;
        for(int i = 0; i < last-1; i+=2){
            if(start[i]>start[i+1]) {
                swap(start[i],start[i+1]);
                sw =1;
            }
        }
        for(int i = 1; i < last-1; i+=2){
            if(start[i]>start[i+1]) {
                swap(start[i],start[i+1]);
                sw=1;
            }
        }
        printArray(start, end);
    }
}
//-----------------------------------------------------------------------------
static T* Partition(T* start, T* end) {
    // TODO: return the pointer which points to the pivot after rearrange the array.
    int i = 0;
    int j = end-start;
    T pivot = start[0];
    while(i<j){
        do{
            i++;
        }
        while(start[i]<pivot);
        do{
            j--;
        }
        while(start[j]>pivot);
        swap(start[i], start[j]);
    }
    swap(start[i], start[j]);
    swap(start[0], start[j]);
    return &start[j];
}

static void QuickSort(T* start, T* end) {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
    if(start>=end) return;
    T* pivot = Partition(start, end);
    cout<<pivot-start<<" ";
    QuickSort(start, pivot);
    QuickSort(pivot+1, end);
}
//----------------------------------------------------------------------

static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) {
    // TODO
    int last = end-start;
    for(int i = cur_segment_total+segment_idx; i<last;i+=cur_segment_total){
        T tmp = start[i];
        int j;
        for(j = i-cur_segment_total; j>=0 && tmp<start[j]; j-=cur_segment_total){
            start[j+cur_segment_total] = start[j];
        }
        start[j+cur_segment_total] = tmp;
    }
    
}

static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
    // TODO
    // Note: You must print out the array after sorting segments to check whether your algorithm is true.
    for(int phase = num_phases-1; phase>=0; phase--){
        for(int i = 0; i < num_segment_list[phase]; i++){
            sortSegment(start, end, i, num_segment_list[phase]);
        }
        
        cout<<num_segment_list[phase]<<" segments: ";
        printArray(start, end);
    }
    
}
//-------------------------------------------------------------------------------------
template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    int last = end-start;
    for(int i=0;i<last-1;i++){
        int min = i;
        for(int j=i+1;j<last;j++){
            if(start[j]<start[min]){
                min =j;
            }
        }
        swap<T>(start[min],start[i]);
        printArray(start, end);
    }
}
//------------------------------------------------------------------------------
static void merge(T* start, T* middle, T* end) {
    // TODO
    int size = (int)(end - start);
    
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (start[j] > start[j + 1]) {
                swap(start[j], start[j + 1]);
                /* T *tmp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = tmp;*/
            }
        }
    }
}

static void InsertionSort(T* start, T* end) {
    // TODO
    int size = (int)(end - start);
    int j = 0;
    
    for (int i = 1; i < size; ++i) {
        T tmp = start[i];
        
        for (j = i - 1; j >= 0 && tmp < start[j]; --j) {
            start[j + 1] = start[j];
        }
        
        start[j + 1] = tmp;
    }
}

static void TimSort(T* start, T* end, int min_size) {
    // TODO
    // You must print out the array after using insertion sort and everytime calling method merge.
    int n = end - start;
    
    for (int i = 0; i < n; i += min_size) {
        InsertionSort(start + i, start + min((i + min_size - 1), n - 1) + 1); 
    }
    cout << "Insertion Sort: ";
    printArray(start, end);
    
    int i = 0;
    for (int size = min_size; size < n; size *= 2) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            
            if (mid < right) {
                merge(start + left, start + mid, start + right + 1); 
            }
            cout << "Merge " << ++i << ": ";
            printArray(start, end);
        }
    }
}
//-------------------------------------------------------------------------------