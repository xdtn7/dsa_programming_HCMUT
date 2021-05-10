// Write function LNRtraversal to travel in LNR manner on a binary tree root to conduct 
// function f for each traversed node? The prototype of the function is as follows:

// template <typename E>

// void LNRtraversal(BNode<E> * root, void (*f)(E));

// where BNode is defined in lecture slides.

// Your code starts at line 40.

template <typename E>

void LNRtraversal(BNode<E> * root, void (*f)(E)){
    if(root == NULL) return;
    if(root->left() != NULL) LNRtraversal(root->left(), f);
    f(root->element());
    if(root->right() != NULL) LNRtraversal(root->right(), f);
}