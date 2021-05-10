// Given the data structures of a binary search tree as follows:

// template <typename E>

// class BNode {

// public:

// 	E key;

// 	BNode<E>* left;

// 	BNode<E>* right;

//         BNode(E v,BNode<E>* l = NULL,BNode<E>* r=NULL):key(v),left(l),right(r){}

// }

// and 

// template <typename E>

// class BST {

// private:

// 	BNode<E>* root;

// public:

//        BST(BNode<E> r):root(r){};

// }

// Write method void printGreatestSmaller(E key) for class BST to print in the greatest keys v of  a node in the BST such that v < key

// Your code starts at line 24.

void printGreatestSmaller(E key){
    int result = -1;
    bool checker = false;
    if (root==NULL) return;
    while (root!=NULL) {
        if (root->key < key)
        {   
            result = root->key;
            root = root->right;
            checker = true;
            }
        else
            {   root = root->left;

                }
       
    }
    if (checker == true)
        cout<<result;
    else return;
}