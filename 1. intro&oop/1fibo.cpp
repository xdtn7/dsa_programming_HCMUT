// Write function fibo that returns the nth value of the Fibonacci sequence where n is the input of the function? 
// The time complexity of the function must be O(n). Remind that F0 = 0, F1 = 1 and Fn = Fn-1 + Fn-2

// The prototype of the function is as follows:

// unsigned int fibo(int n);

// Your code starts at line 11.

unsigned int fibo(int n){
    if (n < 0) return -1;
    else if (n == 0 || n == 1) return n;
    else {
        unsigned int fmr = 0, ltr = 1, res = 1;
        for (int i = 2; i < n; i++) {
            fmr = ltr;
            ltr = res;
            res = fmr + ltr;
        }
        return res;
    }
    return 0;
}