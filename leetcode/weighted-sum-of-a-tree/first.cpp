class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        //
        
        int n = size(nums);

        vector<int> depth(n, 0);

        depth[0] = 1;
        
        for(int i = 0; i < n; i++){

            if(depth[i] > 0) continue;
            
            int current = i;
            int d = 0;


            vector<int> pp;
            
            // while(depth[current] != 0){


                
                
            //     // if(depth[parent[current]] > 0){
            //     //     // we found it 
            //     //     d += depth[parent[current]];
            //     //     break;
            //     // }

                
            //     d++;
            //     current = parent[current];
            // }
            
            // depth[i] = d + 1;


            while(depth[current] == 0){
                pp.push_back(current);
                current = parent[current];
            }

            d = depth[current];

            for(int j = size(pp) - 1; j>=0; j--){
                d++;
                depth[pp[j]] = d;
            }
        }

        int height = *max_element(begin(depth), end(depth));
        
        //

        long long sum = 0;

        for(int i = 0; i < n; i++){
            sum += 1LL * nums[i] * (height - depth[i] + 1);
        }
        return sum;
    }
};