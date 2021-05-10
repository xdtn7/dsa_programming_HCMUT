// Based on class List defined on page 98, write function template <typename E> void heapSort(List<E> &L) to 
// sort the list L in descending order. Functions template <typename E> void reheapUp(List<E> &L,int heapsize)
//  and template <typename E> void reheapDown(List<E> &L,int heapsize) are provided for your convenience.

// Your code starts from line 79.

template <typename E> 
void heapSort(List<E> &L){
    
    int n = L.length();
    reheapUp<E>(L, n);
    //return;
    
    for(int j = n-1; j>0; j--) {
            L.moveToStart();
            E tmp = L.getValue();
            L.moveToPos(j);
            E tmp2 = L.getValue();
            L.remove();
            L.insert(tmp);
            L.moveToStart();
            L.remove();
            L.insert(tmp2);
            
            reheapDown<E>(L, j);
    }
    
}