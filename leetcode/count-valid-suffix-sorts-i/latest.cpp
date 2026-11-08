class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = size(nums);
        if (n == 1) {
            if (nums[0] == target[0])
                return 1;
            return 0;
        }
        int i = n - 1, count = 0;
        while (i > 0 && target[i - 1] >= target[i])
            i--;
        map<int, int> m;
        for (int j = n - 1; j >= i; j--) {
            m[nums[j]]++;
            m[target[j]]--;

            if (!m[nums[j]])
                m.erase(nums[j]);
            if (!m[target[j]])
                m.erase(target[j]);
        }
        bool flag = 1;
        for(int j = 0; j < i; j++){
            if(nums[j] != target[j]) flag = 0;
        }
        for(int j = i; j < n; j++){
            if(m.size() == 0 && flag){
                count++;
            }
            m[nums[j]]++;
            m[target[j]]--;

            if (!m[nums[j]])
                m.erase(nums[j]);
            if (!m[target[j]])
                m.erase(target[j]);
            if(nums[j] != target[j]) flag = 0;
        }
        return count;
    }
};