template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* data = new Node(e);
    if(tail != NULL){
        
        tail->next = data;
        data->previous = tail;
        tail = tail->next;
        
    }
    else{
        head = tail = data;
    }
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    int i;
    Node*t;
    Node*data = new Node(e);
    if(index == 0){
        if(tail == NULL){
            head = tail = data;
            count++;
        }
        else{
            head->previous = data;
            data->next = head;
            head = data;
            count++;
        }
        
        
    }
    else if(index == count) {
        tail->next = data;
        data->previous = tail;
        tail = tail->next;
        count++;
    }
    else{
        for(i = 0, t=head; t!= NULL; i++, t = t->next){
            if(i == index){
                t->previous->next = data;
                data->previous = t->previous;
                data->next = t;
                t->previous = data;
                count++;
            }
        }
    }
    
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}
//----------------------------------------------------------------------------------------------------
template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    int i;
    Node* p;
    for(i = 0, p = head; p != NULL; i++, p=p->next){
        if(index == i) return p->data;
    }
    return -1;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    int i;
    Node* p;
    for(i = 0, p = head; p != NULL; i++, p=p->next){
        if(index == i) {
            p->data = e;
        }
    }
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return count==0;
    
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    int i;
    Node* p;
    for(i = 0, p = head; p != NULL; i++, p=p->next){
        if(p->data == item) {
            return i;
        }
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    int i;
    Node* p;
    for(i = 0, p = head; p != NULL; i++, p=p->next){
        if(p->data == item) {
            return 1;
        }
    }
    return 0;
    
}
//------------------------------------------------------------------------------------------------------
/*
 * TODO: Implement class Iterator's method
 * Note: method remove is different from SLinkedList, which is the advantage of DLinkedList
 */
template <class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin) 
{
    this->pList = pList;
    if (begin) {
        if (pList) {
            this->current = pList->head;
            this->index = 0;
        } else {
            this->current = NULL;
            this->index = -1;
        }
    } else {
        this->current = NULL;
        if (pList) {
            this->index = pList->size();
        } else this->index = -1;
    }
}

template <class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator=(const DLinkedList<T>::Iterator &iterator)
{
    this->current = iterator.current;
    this->index = iterator.index;
    this->pList = iterator.pList;
    return *this;
}

template <class T> 
void DLinkedList<T>::Iterator::set(const T &e)
{
    if (current == NULL) {
        throw std::out_of_range("Segmentation fault!");
    }
    current->data = e;
}

template<class T>
T& DLinkedList<T>::Iterator::operator*() 
{
    if (current == NULL) {
        throw std::out_of_range("Segmentation fault!");
    }
    return current->data;
}

template<class T>
void DLinkedList<T>::Iterator::remove() 
{
    /*
    * TODO: delete Node in pList which Node* current point to. 
    *       After that, Node* current point to the node before the node just deleted.
    *       If we remove first node of pList, Node* current point to nullptr.
    *       Then we use operator ++, Node* current will point to the head of pList.
    */
    if(current == pList->head){
        pList->removeAt(0);
    }
    else{
        int i = 0;
        for( Node* p = pList->head; p!=NULL; i++, p=p->next){
            if(p == current) {
                pList->removeAt(i);
                current =current->previous;
                return;
            }
        }
    }
}

template<class T>
bool DLinkedList<T>::Iterator::operator!=(const DLinkedList::Iterator &iterator) 
{
    return (current != iterator.current);
}

template<class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++() 
{
    current = current->next;
    return *this;
}

template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int) 
{
    Iterator iterator = *this;
    current = current->next;
    return iterator;
}
//---------------------------------------------------------------------------------------