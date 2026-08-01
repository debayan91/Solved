class Solution {
public:
    int maximumWidth(vector<int>& v) {
        int n = size(v);
        unordered_map<int,int> fr;
        vector<int> distinct;
        for(int a : v){
            if(!fr.count(a)) distinct.push_back(a);
            fr[a]++;
        }
        unordered_map<int,int> frr;
        for(auto& [a, c] : fr){
            frr[a] += c;
            frr[2 * a] += c / 2;
        }
        int nn = size(distinct);
        for(int i = 0; i < nn; i++){
            for(int j = i + 1; j < nn; j++){
                frr[distinct[i] + distinct[j]] += min(
                    fr[distinct[i]], fr[distinct[j]]
                );
            }
        }
        int res = 0;
        for(auto& [a, width] : frr) res = max(res, width);
        return res;
    }
};