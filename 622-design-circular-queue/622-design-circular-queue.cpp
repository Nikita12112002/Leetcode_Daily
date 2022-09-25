class MyCircularQueue {
public:
    vector<int>arr;
    int front , rear , cursize ,  sz;
    MyCircularQueue(int k) {
        
        arr.resize(k);
         front=-1;
         rear=-1;
        cursize=0;
        sz=k;
        
    }
    
    bool enQueue(int value) {
        
       if(cursize==sz)
           return false;
        if(rear==-1)
        {
            front=0;
            rear=0;
        }
        else
            rear=(rear+1)%sz;
        arr[rear]=value;
        cursize++;
        return true;
    }
    
    bool deQueue() {
        
        if(front==-1)
            return false;
        
        int  popped = arr[front];
        if(cursize==1)
        {
            front=-1;
            rear=-1;
        }
        else
            front=(front+1)%sz;
        cursize--;
        
        return true;
    }
    
    int Front() {
        
        if(front==-1)
            return -1;
        return arr[front];
    }
    
    int Rear() {
        
       if(rear==-1)
           return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        
        if(front==-1 && rear==-1)
            return true;
        else
            return false;
        
    }
    
    bool isFull() {
        
          if(cursize==sz)
            return true;
        return false;
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