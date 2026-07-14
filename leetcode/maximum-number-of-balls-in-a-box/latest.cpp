class Solution {
public:
    int countBalls(int lowlimit, int highlimit) {
        unordered_map<int, int> m;
        int mx = 0;
        for(int i = lowlimit; i <= highlimit; i++){
            int n = i;
            int sum = 0;
            while(n){
                sum += n % 10;
                n /= 10;
            }
            m[sum]++;
            mx = max(mx, m[sum]);
        }
        return mx;
    }
};