class MyQueue {
public:
    stack<int> main;
    stack<int> secondary;
    MyQueue() {}

    void push(int x) {
        main.push(x);
    }

    int pop() {
        if (secondary.size() > 0) {
            int temp = secondary.top();
            secondary.pop();
            return temp;
        } else {
            int n = main.size() - 1;
            for (int i = 0; i < n ; i++) {
                int temp = main.top();
                secondary.push(temp);
                main.pop();
            }
            int temp = main.top();
            main.pop();
            return temp;
        }
    }

    int peek() {
        if (secondary.size() > 0)
            return secondary.top();
        int n = main.size();
        for (int i = 0; i < n ; i++) {
            int temp = main.top();
            secondary.push(temp);
            main.pop();
        }
        return secondary.top();
    }

    bool empty() { return (main.empty() && secondary.empty()); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */