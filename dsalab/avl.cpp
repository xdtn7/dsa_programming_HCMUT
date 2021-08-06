//Helping functions

void remove(const T &value){
    //TODO
    root = remove(root, value);
}

Node* max(Node* node) {
    Node *curr = node;
    while (curr->pRight) {
        curr = curr->pRight;
    }
    
    return curr;
}

Node *rRotate(Node *node) {
    Node* subLeft = node->pLeft;
    node->pLeft = subLeft->pRight;
    subLeft->pRight = node;
    return subLeft;
}

Node *lRotate(Node *node) {
    Node* subRight = node->pRight;
    node->pRight = subRight->pLeft;
    subRight->pLeft = node;
    return subRight;
}

Node *rebalance(Node *node, int bfactor) {
    if(bfactor > 1){
        Node* left = node->pLeft;
        int b = getHeightRec(left->pLeft)-getHeightRec(left->pRight);
        if(b >=1){
            node = rRotate(node);
        }
        else{
            node->pLeft = lRotate(node->pLeft);
            node = rRotate(node);
        }
    }
    else{
        Node* right = node->pRight;
        int b = getHeightRec(right->pLeft)-getHeightRec(right->pRight);
        if(b <=-1){
            node = lRotate(node);
        }
        else{
            node->pRight = rRotate(node->pRight);
            node = lRotate(node);
        }
    }
    return node;
}
    
Node* remove(Node* node, const T &value) {
    if(node == NULL) return NULL;
    if(node->data > value)  node->pLeft = remove(node->pLeft, value);
    else if (node->data < value) node->pRight = remove(node->pRight, value);
    else {
        //1 subNode NULL
        if(node->pLeft == NULL || node->pRight == NULL){
            Node* tmp = (node->pLeft?node->pLeft:node->pRight);
            delete node;
            return tmp;
        }
        else{
            Node* maxLeft = max(node->pLeft);
            node->data = maxLeft->data;
            node->pLeft = remove(node->pLeft, maxLeft->data);
        }
        
    }
    int balance = getHeightRec(node->pLeft)-getHeightRec(node->pRight);
    if(balance > 1 || balance < -1){
        node = rebalance(node, balance);
    }
    return node;
}
//---------------------------------------------------------------------------
//Helping functions
void insert(const T &value){
    //TODO
    root = insert(root, value);
}

Node *rRotate(Node *node) {
    Node* subLeft = node->pLeft;
    node->pLeft = subLeft->pRight;
    subLeft->pRight = node;
    return subLeft;
}

Node *lRotate(Node *node) {
    Node* subRight = node->pRight;
    node->pRight = subRight->pLeft;
    subRight->pLeft = node;
    return subRight;
}

Node *rebalance(Node *node, int bfactor) {
    if(bfactor > 1){
        Node* left = node->pLeft;
        int b = getHeightRec(left->pLeft)-getHeightRec(left->pRight);
        if(b >=1){
            node = rRotate(node);
        }
        else{
            node->pLeft = lRotate(node->pLeft);
            node = rRotate(node);
        }
    }
    else{
        Node* right = node->pRight;
        int b = getHeightRec(right->pLeft)-getHeightRec(right->pRight);
        if(b <=-1){
            node = lRotate(node);
        }
        else{
            node->pRight = rRotate(node->pRight);
            node = lRotate(node);
        }
    }
    return node;
} 

Node* insert(Node* node, const T &value){
    if(node==NULL){
        return new Node(value);
    }
    if(node->data > value){
        node->pLeft = insert(node->pLeft, value);
    }
    else {
        node->pRight = insert(node->pRight, value);
    }
    int balance = getHeightRec(node->pLeft)-getHeightRec(node->pRight);
    if(balance > 1 || balance < -1){
        node = rebalance(node, balance);
    }
    return node;
}



//----------------------------------------------------------------------------------
void clear(){
    clear(root);
}

void clear(Node* node){
    if(node==NULL) {
        delete node;
        return;
    }
    clear(node->pLeft);
    clear(node->pRight);
    delete node;
}

bool search(const T &value){
    return search(root, value);
}

bool search(Node* node, const T &value){
    if(node==NULL) return false;
    if(node->data > value) return search(node->pLeft, value);
    else if(node->data < value) return search(node->pRight, value);
    else return true;
}
 
void printInorder(){
    return printInorder(root);
}

void printInorder(Node* node){
    if(node==NULL) return;
    printInorder(node->pLeft);
    cout<<node->data<<" ";
    printInorder(node->pRight);
}