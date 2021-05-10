// Write function isFull to check if the binary tree root is full or not? 
// Note an empty binary tree is not full. The prototype of the function is as follows:

// template <typename E>

// bool isFull(BNode<E> * root);

// where BNode is defined in lecture slides.

// Your code starts at line 40.

template <typename E>

bool isFull(BNode<E> * root){
    if(root == NULL) return false;
    if(root->isLeaf()) return true;
    else{
        if(root->left() != NULL && root->right() != NULL)
            return true && isFull(root->left()) && isFull(root->right());
    }
    return false;
}