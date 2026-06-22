class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int k) {
        int m = *max_element(begin(piles), end(piles));
        int n = size(piles);
        if(k == n) return m;
        int l = 1;
        int h = m;
        int mn = m;
        while (l <= h) {
            int mid = (l + h) / 2;
            long long sum = 0;
            for(int pile : piles){
                int q = pile / mid;
                int r = pile % mid;
                sum += q;
                if(r) sum++;
            }
            if(sum <= k) mn = min(mid, mn);
            if(sum > k) { // we need more hours at that speed 
                l = mid + 1;
            }else{
                h = mid - 1;
            }
        }
        return mn;
    }
};