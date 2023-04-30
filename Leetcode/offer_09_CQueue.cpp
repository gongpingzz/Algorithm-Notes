class CQueue {
public:
    CQueue() {
    }
    
    void appendTail(int value) {
        inStack.push(value);
    }
    
    int deleteHead() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                std::cout << inStack.top() << std::endl;
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        if (outStack.empty()) {
            std::cout << "empty queue!" << std::endl;
            return -1;
        }
        int head = outStack.top();
        outStack.pop();
        return head;
    }
private:
    // 负责进栈
    std::stack<int> inStack;
    // 负责出栈
    std::stack<int> outStack;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */