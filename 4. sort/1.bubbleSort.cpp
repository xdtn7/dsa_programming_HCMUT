// Based on class List defined on page 98, write function template <typename E> void bubbleSort(List<E> &L) that sorts the elements of L in ascending 
// using Bubble sort. Your code starts from line 79.

template <typename E> 
void bubbleSort(List<E> &L){
    int i, j;
    int n = L.length();
    for(i = 0; i < n-1; i++){
        bool sw = false;
        for(j = 0; j < n-i-1; j++){
            L.moveToPos(j);
            E a = L.getValue();
            L.moveToPos(j+1);
            E b = L.getValue();
            if(a > b){
            //add b on i pos
                L.moveToPos(j);
                L.remove();
                //L.prev();
                L.insert(b);
            //add a on j pos
                L.moveToPos(j+1);
                L.remove();
                //L.prev();
                L.insert(a);
                
                sw = true;
            }
        }
        if(!sw) break;
    }
}