// Write function isComplete to check if the binary tree root is complete or not? 
// Note an empty binary tree is not complete. The prototype of the function is as follows:

// template <typename E>

// bool isComplete(BNode<E> * root);

// where BNode is defined in lecture slides.

// Your code starts at line 40.

template <typename E>
int countNodes(BNode<E>* root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left()) + countNodes(root->right());
}

template <typename E>
bool isCompleteprime(BNode<E> * root, int index, int numNode) {
    if (root == NULL)
        return true;
  
    if (index >= numNode)
        return false;
  
    return (isCompleteprime(root->left(), 2*index + 1, numNode) &&
            isCompleteprime(root->right(), 2*index + 2, numNode));
}

template <typename E>
bool isComplete(BNode<E> * root) {

    bool x = isCompleteprime(root, 0, countNodes(root));
    return x;
}