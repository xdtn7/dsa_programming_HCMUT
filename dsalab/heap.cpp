//Helping functions go here

static void heapSort(T* start, T* end){
    //TODO
    int size = end-start;
    for(int i=1; i<size; i++){
        bool sw=1;
        int j = i;
        while(sw){
            sw=0;
            if(start[j] > start[(j-1)/2]){
                swap(start[j], start[(j-1)/2]);
                sw=1;
                j = (j-1)/2;
                if(j==0) break;
            }
        }
          //Sorting<T>::printArray(start,end);

    }
    //cout<<"\n";
    for(int i=size-1;i>0;i--){
        swap(start[0], start[i]);
        bool sw=1;
        int j =0;
        while(sw){
            sw=0;
            if(j*2+1>i-1) break;
            if(j*2+2>i-1 ){
                if( start[j] < start[j*2+1])
                    swap(start[j], start[j*2+1]);
                break; 
            }
            
            if(start[j*2+1] > start[j*2+2]){
                if(start[j] < start[j*2+1]) {
                    swap(start[j], start[j*2+1]);
                    j = j*2+1;
                    sw=1;
                }
            }
            else{
                if(start[j] < start[j*2+2]) {
                    swap(start[j], start[j*2+2]);
                    j = j*2+2;
                    sw=1;
                }
            }
              //Sorting<T>::printArray(start,end);
        }
    }
    Sorting<T>::printArray(start,end);
}
//-------------------------------------------------------------------------------
template<class T>
int Heap<T>::size(){
    return count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return count==0;
}

template<class T>
T Heap<T>::peek(){
    return elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    for(int i=0; i < count; i++){
        if(item == elements[i]) return true;
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if(count!=0){
        swap(elements[0], elements[--count]);
        reheapDown(0);
        return true;
    }
    else return false;
    
}
//------------------------------------------------------------------
template<class T>
void Heap<T>::push(T item){
    if(count == capacity) ensureCapacity(1.5*capacity);
    elements[count] = item;
    count++;
    reheapUp(count-1);

}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    T* e = new T[minCapacity];
    for(int i = 0; i < count; i++){
        e[i] = elements[i];
    }
    capacity = minCapacity;
    delete[] elements;
    elements = e;
}

template<class T>
void Heap<T>::reheapUp(int position){
    bool sw=1;
    int i = position;
    while(sw){
        sw=0;
        if(i==0) break;
        if(elements[i]>elements[(i-1)/2]){
            swap(elements[i], elements[(i-1)/2]);
            sw=1;
            i=(i-1)/2;
        }
    }
}
//----------------------------------------------------------------
void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    if(index>=numberOfElements || index <0) return;
    bool sw=1;
    int j =0;
    while(sw){
        sw=0;
        if(j*2+1>numberOfElements-1) break;
        if(j*2+2>numberOfElements-1 ){
            if( maxHeap[j] < maxHeap[j*2+1])
                swap(maxHeap[j], maxHeap[j*2+1]);
            break; 
        }
        
        if(maxHeap[j*2+1] > maxHeap[j*2+2]){
            if(maxHeap[j] < maxHeap[j*2+1]) {
                swap(maxHeap[j], maxHeap[j*2+1]);
                j = j*2+1;
                sw=1;
            }
        }
        else{
            if(maxHeap[j] < maxHeap[j*2+2]) {
                swap(maxHeap[j], maxHeap[j*2+2]);
                j = j*2+2;
                sw=1;
            }
        }
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    if(index>=numberOfElements || index <0) return;
    bool sw=1;
    int j = index;
    while(sw){
        sw=0;
        if(j==0) break;
        if(maxHeap[j] > maxHeap[(j-1)/2]){
            swap(maxHeap[j], maxHeap[(j-1)/2]);
            sw=1;
            j = (j-1)/2;
            
        }
    }
}
//------------------------------------------------------------------------

template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for(int i=0; i<count; i++){
        if(elements[i]==item) return i;
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    for(int i=0; i<count; i++){
        if(elements[i]==item) {
            swap(elements[i], elements[count-1]);
            count--;
            if(i ==0) reheapDown(i);
            else if(elements[i]<=elements[(i-1)/2]) reheapDown(i);
            else reheapUp(i);
        }
    }
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    delete[] elements;
    count = 0;
}

//----------------------------------------------------------------------

