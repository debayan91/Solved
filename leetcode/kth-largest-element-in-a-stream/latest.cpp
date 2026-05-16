class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    void put(int val){
        pq.push(val);
        if(pq.size() > k) pq.pop();
    }
    KthLargest(int n, vector<int>& nums) {
        k = n;
        for(int i : nums) put(i);
    }
    
    int add(int val) {
        put(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */