// Write function BSTinsert to insert a new node into the binary search tree root and 
// return the root of the binary search tree with new node added? Your code starts at
//  line 48. The prototype of the function is as follows:

// template <typename E>

// BNode<E>* BSTinsert(BNode<E> * root,E val);

// where BNode is defined in lecture slides.

// Your code starts at line 50.

template <typename E>

BNode<E>* BSTinsert(BNode<E> * root,E val){
    if(root == NULL) {
        root = new BNode<E>();
        root->setElement(val);
        return root;
    }
    else if(val <= root->element()) root->setLeft(BSTinsert(root->left(), val));
    else if(val > root->element()) root->setRight(BSTinsert(root->right(), val));
    
    return root;
}