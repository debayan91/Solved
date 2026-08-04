class Solution {
public:
    int get(vector<int>& b, int current, int k){
        int count = 0, res = 0;
        int i = 0;
        while(i < size(b)){
            if(b[i] <= current) count++;
            else count = 0;
            if(count == k){
                res++;
                count = 0;
            }
            i++;
        }
        return res;
    }
    int minDays(vector<int>& b, int m, int k) {
        int n = size(b);
        if(1LL * m * k > n) return -1;
        int l = 0;
        int r = *max_element(begin(b), end(b)); // range
        int res = -1;
        while(l <= r){
            int mid = l + (r - l) / 2; // middle
            int mb = get(b, mid, k); // how many can i get here
            if(mb >= m){ // is it enough (or more)
                res = mid;
                r = mid - 1;
            } else { // we need more
                l = mid + 1;
            }
        }
        return res;
    }
};