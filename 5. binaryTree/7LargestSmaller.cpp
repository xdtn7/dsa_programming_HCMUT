// Write function LargestSmaller to print the largest key in the binary search tree from root travel 
// which is smaller than the input key? The prototype of the function is as follows:

// template <typename E>

// void LargestSmaller(BNode<E> * root, E key);

// where BNode is defined in lecture slides.

// Your code starts at line 40.

template <typename E>
void LargestSmaller(BNode<E> * root, E key) {
    static int result = -1;
    bool exist = false;
    if (root==NULL) return;
    
    if(root->element() < key){
        result = root->element();
        LargestSmaller(root->right(), key);
        exist = true;
    }
    else {
        LargestSmaller(root->left(), key);
    }
    if (exist) {
        if(result != -1) cout<<result;
        exist = false;
        result = -1;
    }
    else return;
}