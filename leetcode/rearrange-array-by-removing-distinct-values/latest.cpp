class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int,int> f; for(int i : nums) f[i]++;
        vector<int> res; 
        while(size(res) < size(nums)){
            for(auto& [a, b] : f){
                if(b > 0){
                    res.push_back(a);
                    b--;
                }
            }
        }
        return res;
    }
};