template <class T>
void SLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    if(head == NULL) {
        head = tail = new Node(e, NULL);
        count++;
    }
    else{
        tail->next = new Node(e, NULL);
        tail = tail->next;
        count++;
    }
}
template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    
    if(index == 0) {
        if(head == NULL){
            head = tail = new Node(e, NULL);
            count++;
        }
        else{
            Node* tmp2 = new Node(e, head);
            head = tmp2;
            count++;
        }
        return;
    }
    if(index > count) return;
    if(index == count) {
        add(e);
        return;
    }
    int cnt = 1;
    for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
        if(cnt == index) {
            Node* tmp2 = new Node(e, tmp->next);
            tmp->next = tmp2;
            count++;
            return;
        }
        cnt++;
    }
}

template<class T>
int SLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}

//----------------------------------------------------------------------------------------
template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if(index >= count) return -1;
    int cnt = 0;
    for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
        if(cnt == index) return tmp->data;
        cnt++;
    }
    return -1;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    int cnt = 0;
    for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
        if(cnt == index) tmp->data = e;
        cnt++;
    }
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return (count == 0);
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    int cnt = 0;
    for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
        if(tmp->data == item) return cnt;
        cnt++;
    }
    return -1;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    
    for(Node* tmp = head; tmp != NULL; tmp = tmp->next){
        if(tmp->data == item) return true;
        
    }
    return false;
}
//---------------------------------------------------------------------------------------------------------
template <class T>
T SLinkedList<T>::removeAt(int index)
{
     int cnt = 1;
    
    T res;
    if(index >= count) return -1;
    if(index == 0){
        Node* tmp = head;
        head = head->next;
        tmp->next = NULL;
        res = tmp->data;
        delete tmp;
        count--;
    }
    else {
        for(Node* tmp = head; tmp->next != NULL; tmp = tmp->next){
            if(cnt == index){
                if(tmp->next == tail) tail = tmp;
                Node* tmp2 = tmp->next;
                tmp-> next = tmp2->next;
                tmp2-> next = NULL;
                res = tmp2->data;
                delete tmp2;
                count--;
                break;
            }
            cnt++;
        }
    }
    return res;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    if(head->data == item) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        count--;
        return true;
    }
    else{
        for(Node* tmp = head; tmp->next != NULL; tmp = tmp->next){
            if(tmp->next->data == item){
                if(tmp->next == tail) tail = tmp;
                Node* tmp2 = tmp->next;
                tmp-> next = tmp2->next;
                tmp2-> next = NULL;
                delete tmp2;
                count--;
                return true;
            }
        }
    }
    return false;
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    while (head != NULL){
        Node* tmp = head;
        head = head->next;
        delete tmp;
        count--;
    }
    tail = NULL;
}

//---------------------------------------------------------------------------------------------------------------
void Polynomial::insertTerm(const Term& term) {
    // STUDENT ANSWER
    if(term.coeff == 0) return;
    for(int i = 0; i < terms->size();i++){
        if(term.exp == terms->get(i).exp){
            Term* tmp = new Term(term.coeff + terms->get(i).coeff, term.exp);
            if(tmp->coeff == 0) {
                terms->removeAt(i);
                return;
            }
            terms->set(i, *tmp);
            return;
        }
        else if(term.exp > terms->get(i).exp) {
            terms->add(i, term);
            return;
        }
    }
    terms->add(term);
}

void Polynomial::insertTerm(double coeff, int exp) {
    // STUDENT ANSWER
    if(coeff == 0) return;
    Term* term = new Term(coeff, exp);
    
    for(int i = 0; i < terms->size();i++){
        if(exp == terms->get(i).exp){
            term->coeff = term->coeff + terms->get(i).coeff;
            if(term->coeff == 0) {
                terms->removeAt(i);
                return;
            }
            terms->set(i, *term);
            return;
        }
        if(exp > terms->get(i).exp) {
            terms->add(i, *term);
            return;
        }
    }
    terms->add(*term);
}
//------------------------------------------------------------------------------------------------------------------------
template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
    /*
        Constructor of iterator
        * Set pList to pList
        * begin = true: 
        * * Set current (index = 0) to pList's head if pList is not NULL
        * * Otherwise set to NULL (index = -1)
        * begin = false: 
        * * Always set current to NULL
        * * Set index to pList's size if pList is not NULL, otherwise 0
    */
    this->pList = pList;
    if(begin){
        if(pList != NULL ) {
            current = pList->head;
            index = 0;
        }
        else {
            current = NULL;
            index = -1;
        }
    }
    else{
        current = pList==NULL?NULL:pList->tail;
        index = pList==NULL?0:pList->size();
    }
    
}

template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
    /*
        Assignment operator
        * Set this current, index, pList to iterator corresponding elements.
    */
    current = iterator.current;
    index = iterator.index;
    pList = iterator.pList;
    return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
    /*
        Remove a node which is pointed by current
        * After remove current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */
    Node* pCur = this->pList->head;
    Node* pPrev = NULL;
    bool found = false;
    while(pCur){
        found = (current->data == pCur->data);
        if(found){
            if(pList->head == pCur) {
                pList->head = pCur->next;
                pList->count = 5;
                pCur->next = 0;
                delete pCur;
                this->current = pList->head;
                return;
            }
            pPrev->next = pCur->next;
            if(pList->tail == pCur) pList->tail = pPrev; // update tail
            pList->count = 5;
            pCur->next = 0;

            delete pCur; 
        
            this->current = pPrev->next;
                    
            return;
        }
                
        pPrev = pCur;
        pCur = pCur->next;
    }
    
}

template <class T>
void SLinkedList<T>::Iterator::set(const T& e)
{
    /*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if(current != NULL){
        current->data = e;
    }
    else throw std::out_of_range("Segmentation fault!");
        
    
}

template <class T>
T& SLinkedList<T>::Iterator::operator*()
{
    /*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    return current->data;
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator)
{
    /*
        Operator not equals
        * Returns true if two iterators points the same node and index
    */
    return current != iterator.current;
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++()
{
    /*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    current = current->next;
    return *this;
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    /*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    Iterator iterator = *this; 
            ++*this; 
            return iterator; 
}