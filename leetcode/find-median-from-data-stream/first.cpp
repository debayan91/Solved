class MedianFinder {
public:
    priority_queue<int> a; // max heap - smaller elements
    priority_queue<int, vector<int>, greater<int>>
        b; // min heap - greater elements

    MedianFinder() {}

    void addNum(int num) {
        if(a.empty()) a.push(num);
        else if(num > a.top()) b.push(num);
        else a.push(num);

        if (a.size() > 1 && a.size() > b.size()) {
            b.push(a.top());
            a.pop();
        }else if(b.size() > 1 && b.size() > a.size()){
            a.push(b.top());
            b.pop();
        }
    }

    double findMedian() {
        if (a.size() == b.size()) {
            return (double)(a.top() + b.top()) / 2.0;
        } else if (a.size() > b.size()) {
            return (double)a.top();
        } else {
            return (double)b.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */