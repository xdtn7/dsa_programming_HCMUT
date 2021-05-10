template <typename E> 
int count(List<E> &L,E K){
   int cnt =0;
   for(L.moveToStart(); L.currPos() < L.length(); L.next()){
      if(L.getValue() == K) cnt++;
   }
   return cnt;
}
//-------------------------------
template <typename T> 
void del(List<T> &L,T k){
    L.moveToStart();
   while(L.currPos() < L.length()){
      if(L.getValue() == k) {
         L.remove();
      }
      else L.next();
   }
}
//--------------------------------
template <typename T> 
void DuplicationKiller(List<T> &L){
   L.moveToStart();
   while(L.currPos() < L.length()){
    bool del = false;
    int temp_pos = L.currPos();
    T temp_value = L.getValue();
    L.next();
        while(L.currPos() < L.length()){
          if(L.getValue() == temp_value) {
             del = true;
             L.remove();
          }
          else L.next();
        }
    L.moveToPos(temp_pos);
    if(del == true) {
       L.remove();
    }
    else L.next();
   }
}
//----------------------------------
template <typename E>

void interchange(List<E>* L){
   E tmp = L->remove();
   L->next();
   L->insert(tmp);
}
//---------------------------------
template <typename E>
List<E>* merge(List<E>* in1, List<E>* in2){
    List<E>* tmp;
    tmp = new LList<E>();
    
    in1->moveToStart();
    in2->moveToStart();

        
    while((in1->currPos() < in1->length())&&(in2->currPos() < in2->length())){
            if(in1->getValue() < in2->getValue()){
                    tmp->next();
                    tmp->insert(in1->getValue());
                    in1->next();
            }
            else{
                    tmp->next();
                    tmp->insert(in2->getValue());
                    in2->next();
            }
        
    }
    while(in1->currPos() < in1->length()){
            tmp->next();
            tmp->insert(in1->getValue());
            in1->next();
    }
    while(in2->currPos() < in2->length()){
            tmp->next();
            tmp->insert(in2->getValue());
            in2->next();
    }
    tmp->moveToStart();
    return tmp;
        
    
    
}