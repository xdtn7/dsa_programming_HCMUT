// Write function isBST to check if the binary tree root is a binary search tree or not? 
// Note an empty binary tree is not a BST. The prototype of the function is as follows:

// template <typename E>

// bool isBST(BNode<E> * root);

// where BNode is defined in lecture slides.

// Your code starts at line 40.

template <typename E>
bool isBST(BNode<E>* root) {
    static BNode<E>* l=NULL; 
    static BNode<E>* r=NULL;
    static int cnt = 0;
    cnt++;
    
    if (root == NULL) {
        if(cnt == 0) return false;
        cnt--;
        return true;
    }
    if (l != NULL && root->element() < l->element()) {
        cnt--;
        return false;
    }
    if (r != NULL && root->element() > r->element()){
        cnt--;
        return false;
    }
    
    BNode<E>* tmp=r;
    r = root;
    bool lh = isBST(root->left());
    l = root;
    r = tmp;
    bool rh = isBST(root->right());
    cnt--;
    if (cnt == 0) {
        l = NULL;
        r = NULL;
    }
    return lh && rh;
}