// Write function count to return the height of a binary tree? The prototype of the function is as follows:

// template <typename E>

// int height(BNode<E> * root);

// where BNode is defined in lecture slides.

// Your code starts at line 40.

int max(int a, int b){
    return (a > b) ? a : b;
}

template <typename E>
int height(BNode<E> * root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left()), height(root->right()));
}
