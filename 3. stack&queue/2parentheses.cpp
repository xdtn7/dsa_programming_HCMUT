// A common problem for compilers and text editors is to determine if the parentheses (or other brackets) in a string are balanced and properly nested. 
// For example, the string “((())())()” contains properly nested pairs of parentheses, but the string “)()(” does not, and the string “())” does 
// not contain properly matching parentheses. 
// Based on Stack ADT given in Figure 4.17 page 121, write function parentheses to check if a string contains 
// properly nested pairs of parentheses. Remind that C++ method string::length can be used to get the length of the string.

// The prototype of the function is:

// bool parentheses(const string &L);

bool parentheses(const string &L){
    
    Stack<char>* t = new AStack<char>();
    
    for(size_t i = 0; i < L.size(); i++){
        
        if( L[i] == '(') {
            t->push(L[i]);
            continue;
        }
        if(t->length() == 0) return false;
        else t->pop();
    }
    
    if(t->length() != 0) return false;
    else return true;
}



