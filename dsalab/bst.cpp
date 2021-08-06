//Helping functions

void add(T value){
    Node* tmp = root;
    if(root == NULL) {
        tmp = new Node(value);
        root = tmp;
        return;
    }
    while(true){
        if(tmp->value >= value) {
            if(tmp->pLeft != NULL) {
                tmp = tmp->pLeft;
            }
            else{
                tmp->pLeft = new Node(value);
                break;
            }
        }
        else if(tmp->value < value){
            if(tmp->pRight != NULL) {
                tmp = tmp->pRight;
            }
            else{
                tmp->pRight = new Node(value);
                break;
            }
        }
    }
    return;
}

void deleteNode(T value){
    //TODO
    Node* tmp = root;
    if(root == NULL) {
        return;
    }
    while(true){
        
        if(tmp->value > value) {
            if(tmp->pLeft != NULL) {
                tmp = tmp->pLeft;
            }
            else{
                break;
            }
        }
        else if(tmp->value < value){
            if(tmp->pRight != NULL) {
                tmp = tmp->pRight;
            }
            else{
                break;
            }
        }
        else {
            if((tmp->pRight == NULL)) tmp = (tmp->pLeft);
            else if((tmp->pLeft == NULL)) tmp = (tmp->pRight);
            else{
                Node * t = tmp->pRight;
                Node* p=NULL;
                while(t->pLeft != NULL){
                    p =t;
                    t = t->pLeft;
                }
                tmp->value  = t->value;
                if(t->pRight != NULL) {
                    *t = *(t->pRight);
                }
                else {
                    if(p != NULL){
                        p->pLeft = NULL;
                        //delete t;
                    }
                    else {
                        tmp->pRight = NULL;
                        //delete t;
                    }
                }
            }
            break;
        }
    }
    return;
    
    
}
//----------------------------------------------------------------
// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
bool find(T i, Node* node){
    if(node==NULL) return false;
    if(node->value== i) return true;
    else return (find(i, node->pLeft) || find(i, node->pRight));
}
bool find(T i) {
    // TODO: return true if value i is in the tree; otherwise, return false.
    return find(i, root);
}

T sum(T l, T r, Node* node){
    T tmp = 0;
    if(node==NULL) return 0;
    if(node->value >= l && node->value <= r) tmp = node->value;
    return tmp + sum(l,r,node->pLeft) + sum(l,r,node->pRight);
}
T sum(T l, T r) {
    // TODO: return the sum of all element in the tree has value in range [l,r].
    return sum(l,r,root);
}

// STUDENT ANSWER END
//-----------------------------------------------------------------------------------------------------
// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
T getMin(Node* node){
    if(node->pLeft==NULL) return node->value;
    else return getMin(node->pLeft);
}
T getMin() {
    //TODO: return the minimum values of nodes in the tree.
    return getMin(root);
}
T getMax(Node* node){
    if(node->pRight==NULL) return node->value;
    else return getMax(node->pRight);
}
T getMax() {
    //TODO: return the maximum values of nodes in the tree.
    return getMax(root);
}

// STUDENT ANSWER END
//-------------------------------------------------------------------------------------
// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
int getHeight(Node* node) {
    if(node==NULL) return 0;
    int l = getHeight(node->pLeft);
    int r = getHeight(node->pRight);
    int subheight;
    if(l >= r) subheight = l;
    else subheight = r;
    return 1 + subheight;
}
int getHeight() {
    // TODO: return height of the binary tree.
    return getHeight(root);
}

string preOrder(Node* node) {
    // TODO: return the sequence of values of nodes in pre-order.
    if(node==NULL) return "";
    return  to_string(node->value) + " " + preOrder(node->pLeft) +  preOrder(node->pRight);
}
string preOrder() {
    // TODO: return the sequence of values of nodes in pre-order.
    return preOrder(root);
}

string inOrder(Node* node) {
    // TODO: return the sequence of values of nodes in pre-order.
    if(node==NULL) return "";
    return inOrder(node->pLeft) + to_string(node->value) + " " +  inOrder(node->pRight);
}
string inOrder() {
    // TODO: return the sequence of values of nodes in in-order.
    return inOrder(root);
}
string postOrder(Node* node) {
    // TODO: return the sequence of values of nodes in pre-order.
    if(node==NULL) return "";
    return postOrder(node->pLeft) +  postOrder(node->pRight) + to_string(node->value)+ " " ;
}
string postOrder() {
    // TODO: return the sequence of values of nodes in post-order.
    return postOrder(root);
}

// STUDENT ANSWER END
//-------------------------------------------------------------------------------------------------
