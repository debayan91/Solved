class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(auto a : matrix){
            for(auto b : a){
                pq.push(b);
            }
        }
        while(size(pq) > k){
            pq.pop();
        }
        return pq.top();
    }
};