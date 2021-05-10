// Write function BSTdelete to delete the first node of the binary search tree root whose value 
// is val and return the root of the binary search tree with the node deleted? If there is no 
// node whose value is val, the root of the current BST is returned. Your code starts at line 48. 
// The prototype of the function is as follows:

// template <typename E>

// BNode<E>* BSTdelete(BNode<E> * root,E val);

// where BNode is defined in lecture slides.

// Your code starts at line 50.

template <typename E>
BNode<E>* BSTdelete(BNode<E> * root,E val){
    if(root == NULL) {
        return root;
    }
    else if(val < root->element()) {
        BNode<E>* tmp = BSTdelete(root->left(), val);
        if(tmp == NULL) delete root->left();
        root->setLeft(tmp);
    }
    else if(val > root->element()) {
        BNode<E>* tmp = BSTdelete(root->right(), val);
        if(tmp == NULL) delete root->right();
        root->setRight(tmp);
    }
    else if(val == root->element()){
        if(root->isLeaf()){
            return NULL;
        }
        else{
            if(root->left() == NULL) return root->right();
            else if(root->right() == NULL) return root->left();
            BNode<E>* tmp = root->right();
            while(tmp->left() != NULL){
                tmp = tmp->left();
            }
            root->setElement(tmp->element());
            root->setRight(BSTdelete(root->right(), val));
        }
    }
    return root;
}