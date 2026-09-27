class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = size(nums);

        map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }


        vector<int> v(n, n);

         for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                
               int a = nums[i], b = nums[j];

                for(int s : {a + b, a - b, b - a}){
                    if(!pos.count(s)) continue;

                    auto it = upper_bound(begin(pos[s]), end(pos[s]), j);

                    if(it != end(pos[s])) v[i] = min(v[i], *it);
                }
            }
         }

        int mx = 0;

        for (int i = 0; i < n; i++) {
            int a = n;
            for (int j = i; j < n; j++) {
                a = min(a, v[j]);
                if (j >= a)
                    break;
                mx = max(mx, j - i + 1);
            }
        }
        return mx;
    }
};