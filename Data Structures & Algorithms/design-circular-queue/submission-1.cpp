class MyCircularQueue {
private:
    int front;
    int size ;
    vector<int>q;
    int capacity;

public:
    MyCircularQueue(int k) {
        
        front=0;
        size=0;
        q=vector<int>(k);
        capacity=k;
    }
    
    bool enQueue(int value) {
        
        if(isFull())
        {
            return false;
        }
        int rear_index= (front+size)%capacity;  
        q[rear_index]=value;
        ++size;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
        {
            return false;
        }

        front = (front+1)%capacity;
        --size;
        return true;
        
    }
    
    int Front() {
        if(isEmpty())
        {
            return -1;

        }
        return q[front];
        
    }
    
    int Rear() {
        if(isEmpty())
        {
            return -1;
        }
        int rear_index = (front+size-1)%capacity;
        return q[rear_index];
        
    }
    
    bool isEmpty() {
        return size==0;
        
    }
    
    bool isFull() {
        return size==capacity;
        
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