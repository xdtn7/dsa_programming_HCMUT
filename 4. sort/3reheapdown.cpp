// Based on class List defined on page 98 to implement a min heap used for heap sort, write function 
// template <typename E> void reheapDown(List<E> &L, int heapsize).

// reheapDown: the element at the root is compared to its children and swapped with the smaller 
// child if it is greater than the smaller child. This process is repeated until it is smaller 
// or equal to the smaller child or it is put in the leaf.

// Your code starts from line 79.

template <typename E> 
void reheapDown(List<E> &L, int heapsize){
    if(heapsize > L.length()) throw out_of_range("Heap size cannot be greater than the length of the list");
   int i = 0;
    while(i*2+1<heapsize && 2*i+2<heapsize){
        L.moveToPos(i);
        E tmp = L.getValue();
        L.moveToPos(2*i+1);
        E tmp1 = L.getValue();
        L.moveToPos(2*i+2);
        E tmp2 = L.getValue();
        if((tmp1 < tmp2) && (tmp > tmp1)) {
            L.moveToPos(2*i+1);
            //E t2 = L.getValue();
            L.remove();
            L.insert(tmp);
            L.moveToPos(i);
            L.remove();
            L.insert(tmp1);  
            i = 2*i+1;
        }
        else if (tmp > tmp2){
            L.moveToPos(2*i+2);
            //E t2 = L.getValue();
            L.remove();
            L.insert(tmp);
            L.moveToPos(i);
            L.remove();
            L.insert(tmp2);  
            i = 2*i+2;
        }
        else break;
    }
}