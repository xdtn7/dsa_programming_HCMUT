// Write function powerSet that returns the power set of the input array? For example, 
// if the input is ['a','b','c'], the output is [[],['a'],['b'],['a','b'],['c'],['a','c'],['b','c'],['a','b','c']]. 
// The prototype of the function is at follows:

// template <typename T>

// vector<vector<T>> powerSet(vector<T> arr); // where arr is the input array

// Your code starts at line 11. Write the asymptotic time complexity of your function in the comment at the beginning of your function.

template <typename T>
vector<vector<T>> powerSet(vector<T> arr){
    vector<vector<T>> res;
	
	auto bg = arr.begin();
	int sz = arr.size();
	int size = pow(2, arr.size());
	for(int cnt = 0; cnt < size; cnt++){
		vector<T> tmp;
		for (int i = 0; i < sz; i++){
       		
       		if(cnt & (1 << i)) tmp.push_back(*(bg + i));
    	}
		res.push_back(tmp);
	}
    return res;
}