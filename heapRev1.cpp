#include<iostream>
using namespace std;

class Heap{
    int *harr;
    int curr_size;
    int capacity;
public:
    Heap(int size); 
    void insert(int val);
    void deleteKey(int key);
    int getMin();
    int extractMin();
    void decreaseKey(int key, int newVal); 
    int parent(int); 
    int leftKey(int);
    int rightKey(int); 
    void heapify(int key);
};

void swap (int *x, int *y){
    int temp = *x;
    *x = *y;
    *y= temp;
}

Heap::Heap(int size){
    harr = new int[size];
    capacity = size;
    curr_size = 0;
}

int Heap::parent(int key){
    return (key - 1)/2;
}

int Heap::leftKey(int key){
    return (2*key + 1);
}

int Heap::rightKey(int key){
    return (2*key + 2);
}

void Heap::insert(int val){
    if(curr_size == capacity){
        cout << "\n No space left in the heap";
        return;
    }else{
        harr[curr_size] = val;
        int index = curr_size;
        curr_size++;
        while(index!=0 && harr[parent(index)] > harr[index]){
            swap(&harr[parent(index)], &harr[index]);
            index = parent(index);
        }
    }
}

void Heap::deleteKey(int key){
    decreaseKey(key, INT_MIN);
    extractMin();
}

void Heap::decreaseKey(int key, int val){
    int index = key;
    harr[key] = val;
    while(index!=0 && harr[parent(index)] > harr[index]){
        swap(&harr[parent(index)], &harr[index]);
         index = parent(index);
    }
}

int Heap::getMin() { return harr[0]; } 

int Heap::extractMin(){
    if (curr_size == 0){
        cout << "\n empty heap";
        return INT_MAX;
    }else if(curr_size == 1){
        curr_size--;
        return harr[0];
    } else {
        int root = harr[0]; 
	    harr[0] = harr[curr_size-1]; 
	    curr_size--; 
	    heapify(0); 
        return root; 
    }
}

void Heap::heapify(int key){
    int left = leftKey(key);
    int right = rightKey(key);
    int smallest = key;
    if (left < curr_size && harr[left]  < harr[key]){
        smallest = left;
    }
    if (right < curr_size && harr[right]  < harr[smallest]){
        smallest = right;
    }
    if (smallest != key){
        swap(&harr[key], &harr[smallest]);
        heapify(smallest);
    }
}






int main(){
    Heap h(11);
    h.insert(3); 
	h.insert(2); 
	h.deleteKey(1); 
	h.insert(15); 
	h.insert(5); 
	h.insert(4); 
	h.insert(45);
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1); 
	cout << h.extractMin() << "\n"; 
    return 0;
}