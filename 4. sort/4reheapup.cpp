// Based on class List defined on page 98 to implement a min heap used for heap sort, 
// write function template <typename E> void reheapUp(List<E> &L, int heapsize).

// reheapUp: the last element of the heap is compared to its parent and swapped if 
// it is less than its parent. This process is repeated until it is higher or equal 
// to its parent or it is put in the root. 

// heapsize: the heap just includes heapsize number of elements in the beginning of the 
// list L. heapsize must be less than or equal to L.length(), otherwise, exception
//  out_of_range("Heap size cannot be greater than the length of the list") is thrown.

// Your code starts from line 79.

template <typename E> 
void reheapUp(List<E> &L, int heapsize){
    
    if(heapsize > L.length()) throw out_of_range("Heap size cannot be greater than the length of the list");
    int i = heapsize-1;
    while(i!=0){
        L.moveToPos(i);
        E temp = L.getValue();
        L.moveToPos((i-1)/2);
        E temp1 = L.getValue();
        if (temp1 >= temp) {
            L.moveToPos((i-1)/2);
            L.remove();
            L.insert(temp);
            L.moveToPos(i);
            L.remove();
            L.insert(temp1);  
            i = (i-1)/2;    
        }
        else break;
    }
}