class Solution {
public:
    char slowestKey(vector<int>& nums, string s) {
        int x = nums[0];
        char c = s[0];
        for(int i = 1; i < size(nums); i++){
            int d = nums[i] - nums[i - 1];
            cout << d << endl;
            if(d > x){
                x = d;
                c = s[i];
            } else if(d == x) c = max(c, s[i]);
        }
        return c;
    }
};