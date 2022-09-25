struct LinkedList {
    int val;
    LinkedList *next;
    LinkedList *prev; 
    LinkedList() : val(0), next(nullptr), prev(nullptr) {}
    LinkedList(int x) : val(x), next(nullptr), prev(nullptr) {}
    LinkedList(int x, LinkedList *next, LinkedList *prev) : val(x), next(next), prev(prev) {}
};

class MyCircularQueue {
public:
    int space;
    LinkedList* left = new LinkedList();
    LinkedList* right = new LinkedList();
    
    MyCircularQueue(int k) {
        space = k;
        left->next = right;
        right->prev = left;
    }
    
    bool enQueue(int value) {
        if(space == 0)  return false;
        LinkedList* temp = new LinkedList(value, right, right->prev);
        temp->prev->next = temp;
        right->prev = temp;
        space--;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())   return false;
        LinkedList* del = left->next;
        left->next = left->next->next;
        left->next->prev = left;
        delete del;
        space++;
        return true;
    }
    
    int Front() {
        if(isEmpty())   return -1;
        return left->next->val;
    }
    
    int Rear() {
        if(isEmpty())   return -1;
        return right->prev->val;
    }
    
    bool isEmpty() {
        return left->next == right;  
    }
    
    bool isFull() {
        return (space == 0);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */