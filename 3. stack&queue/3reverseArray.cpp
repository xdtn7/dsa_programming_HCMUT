// Based on the Stack ADT given in Figure 4.17 page 121, write a part of function reverse using a stack to reverse an array.

// template <typename E>

// void reverse(E* L, int n) { //L is the array of E and n is the size of the array

//     Stack<E>* S = new AStack<E>();

//     //Your work is from here (line 65)

//    ...

//    //until here

// }

for(int i = 0; i < n; i++){
    S->push(L[i]);
}
for(int i = 0; i < n; i++){
    L[i] = S->pop();
}