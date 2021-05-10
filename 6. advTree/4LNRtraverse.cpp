// Write function NLRtraversal to travel in NLR manner on a binary tree root to conduct function 
// f for each traversed node? The prototype of the function is as follows:

// template <typename E>

// void NLRtraversal(BNode<E> * root, void (*f)(E));

// where BNode is defined in lecture slides.

// Your code starts at line 40.

template <typename E>
void NLRtraversal(BNode<E> * root, void (*f)(E)){
    if(root == NULL) return;
    f(root->element());
    NLRtraversal(root->left(), f);
    NLRtraversal(root->right(), f);
}