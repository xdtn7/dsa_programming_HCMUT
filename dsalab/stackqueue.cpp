bool isBipartite(vector<vector<int>> graph) {
    int size = (int)graph.size();
    int* color = new int[size];
    for(int i=0; i<size; i++) color[i]=-1;
    color[0]=1;
    
    queue <int> q;
    q.push(0);
    
    while(!q.empty()){
        int u = q.front(); 
        q.pop();
        int n = (int)graph[u].size();
        for(int i=0; i< n; i++){
            //cout<<graph[u][i]<<" "<<endl;
            
            if(color[graph[u][i]]==-1){
                color[graph[u][i]]=1-color[u];
                q.push(graph[u][i]);
            }
            else if(color[graph[u][i]]==color[u]) return false;

        }
    }
    return true;  
}
//-----------------------------------------------------------------------------------------
void bfs(vector<vector<int>> graph, int start) {
    int n = (int)graph.size();
	bool *visited = new bool[n];
	for (int i = 0; i < n; ++i) {
	    visited[i] = false;
	}
	
	queue<int> q;
	visited[start] = true;
	q.push(start);
	
	while (!q.empty()) {
	    int curr = q.front();
	    q.pop();
	    cout << curr << " ";
	    for (int i = 0; i < (int)graph[curr].size(); ++i) {
	        if (visited[graph[curr][i]] == false) {
	            q.push(graph[curr][i]);
	            visited[graph[curr][i]] = true;
	        }
	    }
	}
}
//------------------------------------------------------------------------------------------------
void push(T item) {
    // TODO: Push new element into the end of the queue
    list.add(item);
}

T pop() {
    // TODO: Remove an element in the head of the queue
    return list.removeAt(0);
}

T top() {
    // TODO: Get value of the element in the head of the queue
    return list.get(0);
}

bool empty() {
    // TODO: Determine if the queue is empty
    return list.empty();
}

int size() {
    // TODO: Get the size of the queue
    
    return list.size();
}

void clear() {
    // TODO: Clear all elements of the queue
    
    list.clear();
}
//---------------------------------------------------------------------------------
vector<int> topologicalSorting(vector<vector<int>> graph) {

    vector<int> vect;
    int V = (int)graph.size();
    vector<int> indegree(V, 0);
    
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < (int)graph[i].size(); ++j) {
            indegree[graph[i][j]]++;
        }
    }
    
    queue<int> q;
    
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    int cnt = 0;
    vector<int> topOrder;
    
    while (!q.empty()) {
        
        int u = q.front();
        q.pop();
        topOrder.push_back(u);
        
        for (int i = 0; i < (int)graph[u].size(); ++i) {
            if (--indegree[graph[u][i]] == 0) q.push(graph[u][i]);
        }
        cnt++;
    }
    
    if (cnt != V) return vect;
    
    return topOrder;
}
//-----------------------------------------------------------------------------------
int baseballScore(string ops){
/*TODO*/
    stack<int> s;
    int sum = 0;
    for (int i = 0; i < (int)ops.size(); ++i) {
        if ((int)ops[i] >= 48 && (int)ops[i] <= 57) {
            s.push((int)ops[i] - 48);
        } else if (ops[i] == 'C') {
            s.pop();
        } else if (ops[i] == 'D') {
            int u = 2 * s.top();
            s.push(u);
        } else if (ops[i] == '+') {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.push(a);
            s.push(a + b);
        }
    }
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    return sum;
}
//-------------------------------------------------------------------------------------------
void push(T item) {
    // TODO: Push new element into the top of the stack
    list.add(0, item);
}

T pop() {
    // TODO: Remove an element on top of the stack
    return list.removeAt(0);    
}

T top() {
    // TODO: Get value of the element on top of the stack
    return list.get(0);    
}

bool empty() {
    // TODO: Determine if the stack is empty
    return list.empty(); 
}

int size() {
    // TODO: Get the size of the stack
    return list.size();   
}

void clear() {
    // TODO: Clear all elements of the stack
    list.clear();
}
//-------------------------------------------------------------------------------------------
string removeDuplicates(string S){
    /*TODO*/
    stack<char> s;
    for (int i = 0; i < (int)S.size(); ++i) {
        if (s.empty()) {
            s.push(S[i]);
            continue;
        }
        if (S[i] != s.top()) {
            s.push(S[i]);
        }
        else {
            s.pop();
        }
    }
    string res = "";
    
    while (!s.empty()) {
        res += s.top();
        s.pop();
    }
    
    int n = (int)res.size();
    for (int i = 0; i < n / 2; ++i) {
        swap(res[i], res[n - i - 1]);
    }
    
    return res;
}
//----------------------------------------------------------------------------------
bool isValidParentheses (string s){
    /*TODO*/
    stack<char> stac;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (stac.empty()) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stac.push(s[i]);
                continue;
            } else return false;
        }
        else if (s[i] == ')') {
            if (stac.top() == '(') {
                stac.pop();
                continue;
            } else return false;
        }
        else if (s[i] == '}') {
            if (stac.top() == '{') {
                stac.pop();
                continue;
            } else return false;
        }
        else if (s[i] == ']') {
            if (stac.top() == '[') {
                stac.pop();
                continue;
            } else return false;
        }
        else stac.push(s[i]);
    }
    if (stac.empty()) return true;
    else return false;
}