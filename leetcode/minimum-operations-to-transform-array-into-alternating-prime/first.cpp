class Solution {
public:
    int minOperations(vector<int>& nums) {
        int mx = *max_element(begin(nums), end(nums)) * 2;
        vector<bool> prime(mx + 1, true);
        prime[0] = prime[1] = 0;
        for(int i = 2; i * i <= mx; i++){
            if(!prime[i]) continue;
            for(int j = i * i; j <= mx; j += i){
                prime[j] = false;
            }
        }
        int res = 0;
        for(int i = 0; i < size(nums); i++){
            if(i % 2 && prime[nums[i]]){
                int j = nums[i];
                while(prime[j]){
                    j++;
                    res++;
                }
            }
            if(i % 2 == 0 && !prime[nums[i]]){
                int j = nums[i];
                while(!prime[j]){
                    j++;
                    res++;
                }
            }
        }
        return res;
    }
};