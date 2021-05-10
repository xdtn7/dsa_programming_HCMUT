#include <iostream>
#include <list>
#include <vector>

using namespace std;

class ChainingHash {
private:
public:
    int (*hash)(int);
    list<int> *data;
    int size;
    

    ChainingHash() {
        throw "Cannot create a hash with no hash function!";
    }
    
    ChainingHash(int size, int (*hash)(int)) {
        this->hash = hash;
        this->size = size;
        this->data = new list<int>[size];
    }

    

    void insert(int key) {
        int n = hash(key);
        list<int>::iterator it = data[n].begin();
        advance(it, data[n].size());
        data[n].insert(it, key);
    }

    void remove(int key) {
        int n = hash(key);
        data[n].remove(key);       
    }

    bool search(int key) {
        for(int i = 0; i < size; i++){
            if(data[i].end() != find(data[i].begin(), data[i].end(), key)) return true; 
        }
        return false;
    }
    
    int count() {
        int total = 0;
        for (int i = 0; i < this->size; i++) {
            total += this->data[i].size();
        }
        return total;
    }
    
    void dump() {
        for (int i = 0; i < this->size; i++) {
            cout << "Slot " << i << ": " << this->data[i].size() << " element(s)" << endl;
        }
    }
};

void print(std::list<int> const &list){
    for (auto const &i: list) {
        cout << i << endl;
    }
}

int hashWith11(int key) {
    return key % 11;
}
int hashWith15(int key) {
    return key % 15;
}
int hashWith17(int key) {
    return key % 17;
}

int main() {
    ChainingHash* hashTable = new ChainingHash(11, hashWith11);
    int data[] = {28, 81, 55, 92, 33, 29, 18, 23, 40, 99, 79, 74, 49, 64, 17};
    int size = sizeof(data)/ sizeof(int);
    for (int i = 0; i < size; i++) {
        hashTable->insert(data[i]);
    }

    int indices[] = { 1, 5, 7 };
    int indicesSize = sizeof(indices)/ sizeof(int);
    for (int i = 0; i < indicesSize; i++) {
        hashTable->remove(data[indices[i]]);
    }

    //cout<<hashTable->data[0]

    hashTable->dump();  
    int p;
    while(true){
        cin >> p;
        if(p == 99) break;
        print(hashTable->data[p]);
    }
    
}