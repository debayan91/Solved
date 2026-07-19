class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int index = 0;
        for(int i = 1; i <= n; i++){
            if(i == target[index]){
                index++;
                res.push_back("Push");
                if(index == size(target)) return res;
            } else {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};