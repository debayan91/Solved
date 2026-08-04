class Solution {
public:
    bool works(vector<int>& w, int cap, int days){
        int i = 0, current = 0, day = 0;
        while(day < days){
            current = 0;
            while(i < size(w) && current + w[i] <= cap){
                current += w[i++];
            }
            if(i == size(w)) break;
            day++;
        }
        return i == size(w);
    }
    int shipWithinDays(vector<int>& w, int days) {
        int l = 1;
        int r = accumulate(begin(w), end(w), 0);
        int res = -1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(works(w, mid, days)){
                r = mid - 1;
                res = mid;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};