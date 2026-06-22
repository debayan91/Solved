class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = size(gas);
        int start = 0;
        for(int i = 0; i < n; i++){
            int diff = gas[i] - cost[i];
            if(diff < 0) continue;

            int current = 0;
            int counter = 0;
            int j = i;
            while(current >= 0 && counter < n){
                current += gas[j] - cost[j];
                // if(current < 0) break;
                j = (j + 1) % n;
                counter++;
            }
            if(counter == n && current >= 0) return i;
            j = j == 0 ? n - 1 : j - 1; // the actual index where we failed
            
            // if we did not find the same index and stopped somewhere
            if(j > i) i = j - 1;
            else return -1;
        }
        return -1;
    }
};