//Helping functions
int max(int a, int b) { return (a > b) ? a : b; }

int height(Node* node) {

    if (node == NULL)
        return 0;
 
    return 1 + max(height(node->pLeft), height(node->pRight));
}

int diameter(Node* tree){
    if (tree == NULL)
        return 0;
 
    int lheight = height(tree->pLeft);
    int rheight = height(tree->pRight);
 
    int ldiameter = diameter(tree->pLeft);
    int rdiameter = diameter(tree->pRight);
 
    return max(lheight + rheight + 1,
            max(ldiameter, rdiameter));
}

int getDiameter(){
    //TODO
    return diameter(root);
}
//-----------------------------------------------------------------------------------
// STUDENT ANSWER BEGIN
// You can define other functions here to help you.


void BFS()
{
    if(root == NULL) return;
    queue<Node *>* q = new queue<Node *>;
    q->push(root);
    
    while (!q->empty()){
        Node* node = q->front();
        cout<< node->value<<" ";
        q->pop();
        if(node->pLeft != NULL){
            q->push(node->pLeft);
        }
        if(node->pRight != NULL){
            q->push(node->pRight);
        }
    }
    delete q;
}
// STUDENT ANSWER END
//-----------------------------------------------------------------------------------------------------
// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

int cnt(Node* node){
    if(node->pLeft != NULL && node-> pRight == NULL){
        return cnt(node->pLeft);
    }
    else if (node->pLeft == NULL && node-> pRight != NULL){
        return cnt(node->pRight);
    }
    else if (node->pLeft == NULL && node-> pRight == NULL){
        return 0;
    }
    else {
        return 1 + cnt(node->pLeft) + cnt(node->pRight);
    }
}

int countTwoChildrenNode()
{
    if(root == NULL) return 0;
    else return cnt(root);
}
// STUDENT ANSWER END
//------------------------------------------------------------------------------
// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

bool BST(Node* node){
    if(node->pLeft != NULL && node-> pRight == NULL){
        if(node->pLeft->value < node->value)
            return 1 && BST(node->pLeft);
        else return 0;
        
    }
    else if (node->pLeft == NULL && node-> pRight != NULL){
        if(node->pRight->value > node->value)
            return 1 && BST(node->pRight);
        else return 0;
    }
    else if (node->pLeft == NULL && node-> pRight == NULL){
        return 1;
    }
    else {
        if(node->pLeft->value < node->value && node->pRight->value > node->value)
            return 1 && BST(node->pLeft) && BST(node->pRight);
        else return 0;
    }
    
}

bool isBST() {
    // TODO: return true if a tree is a BST; otherwise, return false.
    if(root == NULL) return 1;
    else return BST(root);
}

// STUDENT ANSWER END
//--------------------------------------------------------------------------------------------
//Helping functions

int sl(Node* node){
    if(node->pLeft != NULL && node-> pRight == NULL){
        return sl(node->pLeft);
    }
    else if (node->pLeft == NULL && node-> pRight != NULL){
        return sl(node->pRight);
    }
    else if (node->pLeft == NULL && node-> pRight == NULL){
        return node->value;
    }
    else {
        return sl(node->pLeft) + sl(node->pRight);
    }
}

int sumOfLeafs(){
    //TODO
    if(root == NULL) return 0;
    else return sl(root);
}