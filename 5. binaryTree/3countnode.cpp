// Write function count to return the number of nodes in a binary tree? The prototype of the function is as follows:

// template <typename E>

// int count(BNode<E> * root);

// where BNode is defined in lecture slides.

// Your code starts at line 40.

template <typename E>

int count(BNode<E> * root){
    if(root == NULL) return 0;
    
    return 1 + count(root->left()) + count(root->right());
}