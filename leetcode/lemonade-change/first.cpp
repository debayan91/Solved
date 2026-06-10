class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> m;
        for(int bill : bills){
            int retur = bill - 5;
            m[bill]++;
            // possible return 0 5 15
            if(retur == 5){
                if(m.count(5) && m[5] > 0){
                    m[5]--;
                }else{
                    return false;
                }
            }
            
            if(retur == 15){
                // return is 15 - 10 + 5 or 5 + 5 + 5
                if(m.count(10) && m[10] > 0 && m.count(5) && m[5] > 0){
                    m[5]--;
                    m[10]--;
                }else if(m.count(5) && m[5] > 2){
                    m[5] -= 3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};