// Based on the Stack ADT given in Figure 4.17 page 121, write function dec2bin to return a binary string of the positive decimal input.

// The prototype of the function is:

string dec2bin(const unsigned int& x);

string dec2bin(const unsigned int& x){
    Stack<int>* t = new AStack<int>();
    int tmp = x;
    string res;

    while(tmp>0){
        t->push( tmp %2);
        tmp = tmp/2;
        
    }

    while(t->length() > 0){
        
        if(t->pop() == 0) res = res + "0";
        else res = res + "1";
    }
    return res;
}