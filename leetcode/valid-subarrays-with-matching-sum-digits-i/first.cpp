class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = size(nums);
        vector<long long> prefix(n + 1, 0);
        for(int i = 0 ;i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int count = 0;
        for(int i = 0; i < n; i++){ // n
            for(int j = i; j < n; j++){
                long long s = prefix[j + 1] - prefix[i]; // 1
                int last = abs(s) % 10;
                while(s >= 10){
                    s /= 10;
                }
                int first = (int)s;
                if(first == x && last == x) count++;
            }
        }
        return count;
    }
};