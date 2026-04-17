class MinStack {
    Stack<Integer> s = new Stack<>();
    Stack<Integer> s2 = new Stack<>();

    public MinStack() {

    }

    public void push(int val) {
        s.push(val);
        if (s2.isEmpty())
            s2.push(val);
        else {
            int min = s2.peek();
            if (val <= min)
                s2.push(val);
        }
    }

    public void pop() {
        int min = getMin();
        if (s.peek().equals(s2.peek())) {
            s.pop();
            s2.pop();
        } else {
            s.pop();
        }
    }

    public int top() {
        return s.peek();
    }

    public int getMin() {
        if (s2.isEmpty())
            return -1;
        return s2.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */