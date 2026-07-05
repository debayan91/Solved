class Solution {
public:
    long long getSum(vector<int>& nums) {

        
        long long mx = 0;

        
        int n = size(nums);

        
        vector<long long> p(n+1, 0);
        for(int i = 0; i < n; i++){
            p[i + 1] = p[i] + nums[i];
        }


        vector<int> rad(n);
        int l = 0;
        int h = -1; // odd 
        for(int i = 0; i < n; i++){
            int k;
            if(i > h) k = 1;
            else k = min(rad[l + h - i], h- i + 1);
            while(i-k >= 0 && i +k < n && nums[i - k] == nums[i+k]) k++;
            rad[i] = k;
            if(i +k -1 > h){
                l = i -k +1;
                h = i +k -1;
            }
        }

        
        l = 0;
        h = -1;
        vector<int> r2(n); // even
        for(int i = 0; i < n; i++){
            int k;
            if(i > h) k = 0;
            else k = min(r2[l + h - i + 1], h - i + 1);
            while(i-k - 1 >= 0 && i +k < n && nums[i - k - 1] == nums[i+k]) k++;
            r2[i] = k;
            if(i +k -1 > h){
                l = i -k ;
                h = i +k -1;
            }
        }

        
        for(int i = 0; i < n; i++){
            int radius = rad[i];
            if(radius){
                int a = i - radius + 1;
                int b = i + radius - 1;
                long long s = p[b + 1] - p[a];
                mx = max(mx, s);
            }
        }

        
        for(int i = 0; i < n; i++){
            int radius = r2[i];
            if(radius){
                int a = i - radius;
                int b = i + radius - 1;
                long long s = p[b + 1] - p[a];
                mx = max(mx, s);
            }
        }

        
        return mx;
    }
};