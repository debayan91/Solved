class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        sort(begin(nums), end(nums));

        int n = size(nums);

        vector<int> v(n);

        int x = n - 1;

        for(int i = 0; i < n; i++){
            if(i % 2){
                v[i] = nums[x--];
            }
        }


        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                v[i] = nums[x--];
            }
        }


        nums = v;
    }
};