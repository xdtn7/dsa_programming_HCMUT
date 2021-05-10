// Write function BFtraversal to travel on a binary tree root in breadth-first manner to conduct 
// function f for each traversed node? Class Queue with concrete class LQueue and class Stack with 
// concrete class AStack have been provided for your convenience. Your code starts at line 195. The prototype of the function is as follows:

// template <typename E>

// void BFtraversal(BNode<E> * root, void (*f)(E));

// where BNode is defined in lecture slides.

// Your code starts at line 200.


template <typename E>
void BFtraversal(BNode<E> * root, void (*f)(E)){
    
    if(root == NULL) return;
    
    Queue<BNode<E>*>* q = new LQueue<BNode<E>*>();
    
    q->enqueue(root);
    
    while(q->length() != 0){
        BNode<E> * tmp = q->dequeue();
        f(tmp->element());
        if(tmp->left() != NULL) q->enqueue(tmp->left());
        if(tmp->right() != NULL) q->enqueue(tmp->right());
    }
    
}