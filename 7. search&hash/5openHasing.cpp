

#include <iostream>
#include <list>
#include <vector>

using namespace std;

enum STATUS_TYPE {NIL, NON_EMPTY, DELETED};
class OpenHash {
private:
    int (*hp)(int, int);
    STATUS_TYPE* status;
    int* data;
    int size;
    
public:
    OpenHash() {
        throw "Cannot create a hash with no hash function!";
    }
    
    OpenHash(int size, int (*hp)(int, int)) {
        this->hp = hp;
        this->size = size;
        this->data = new int[size];
        this->status = new STATUS_TYPE[size];
        for (int i = 0; i < size; i++) {
            this->status[i] = NIL;
        }
    }
    
 //   {{ STUDENT_ANSWER }}

    int insert(int key) {
        for(int i =0; ; i++){
            int n = hp(key, i);
            if(n >= size) throw ("Not found!");
            if(status[n] != NON_EMPTY) {
                data[n] = key;
                status[n] = NON_EMPTY;
                return n;
            }
        }
        
    }

    void  remove(int key) {
        for(int i = 0; i < size; i++){
            if(key == data[i]) {
                data[i] = 0;
                status[i] = DELETED;
            }
        }
    }

    int search(int key) {
        for(int i = 0; i < size; i++){
            if(key == data[i]) {
                return i;
            }
        }
        return -1;
    }
    
    void dump() {
        for (int i = 0; i < this->size; i++) {
            if (this->status[i] != NON_EMPTY)
                cout << "Slot " << i << ": Empty" << endl;
            else cout << "Slot " << i << ": " << this->data[i] << endl;
        }
    }
};
//Given some hash function:

int linearProbing(int key, int i) {
    return ((key % 11) + i) % 11;
}

int quadraticProbing(int key, int i) {
    return ((key % 11) + i + 3 * i * i) % 11;
}

int doubleHashing(int key, int i) {
    int h1 = key % 11;
    int h2 = 1 + (key % 10);
    return (h1 + i * h2) % 11;
}

int main() {
    OpenHash* hashTable = new OpenHash(11, linearProbing);
    int data[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
    int size = sizeof(data) / sizeof(int);

    for (int i = 0; i < size; i++) {
        hashTable->insert(data[i]);
    }

    hashTable->dump();
}
