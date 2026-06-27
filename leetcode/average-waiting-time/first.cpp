class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int time = 0;
        double waitsum = 0;
        int n = size(customers);
        for(auto& c : customers){
            int start;
            if(time == 0){
                start = c[0];
            }else{
                start = max(c[0], time);
            }
            int wait = max(0, start - c[0]) + c[1];
            time = start + c[1];
            waitsum += wait;
        }
        return waitsum / n;
    }
};