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

// Write method void printInRange(int low, int high) for class BST to print in the ascending order the keys v of nodes in the BST such that low <= v <= high

// Your code starts at line 24.

void printInRange(int low, int high){
    static BNode<E> * tmp = NULL;
    BNode<E> * t = NULL;
    static int cnt = 0;
    static int n = 0;
    if(cnt == 0) tmp = root;
    cnt++;
    if(tmp == NULL) {
        cnt--;
        return;
    }
    t = tmp;
    tmp = t->left;
    printInRange(low, high);
    tmp = t;
    if(tmp->key >= low && tmp->key <= high) {
        if(n == 0) cout<<tmp->key;
        else cout<<" "<<tmp->key;
        n++;
    }
    tmp = t->right;
    printInRange(low, high);
    tmp = t;
    cnt--;
    if(cnt== 0){
        tmp = NULL;
        n = 0;
    }
    return;
}