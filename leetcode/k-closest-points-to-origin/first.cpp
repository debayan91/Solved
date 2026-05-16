class Solution {
public:
    class point {
    public:
        int x, y, dist;
        point(int x, int y) {
            this->x = x;
            this->y = y;
            this->dist = (x * x + y * y);
        }
    };

    class cmp {
    public:
        bool operator()(point* a, point* b) { return a->dist < b->dist; }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<point*, vector<point*>, cmp> pq;
        for(auto a : points){
            point* c = new point(a[0], a[1]);
            pq.push(c);
            if(pq.size() > k) pq.pop();
        }
        while(pq.size() != 0){
            point* p = pq.top();
            pq.pop();
            res.push_back({p->x, p->y});
        }
        return res;
    }
};