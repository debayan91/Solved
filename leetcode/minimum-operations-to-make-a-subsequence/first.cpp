class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        set<int> s1(begin(target), end(target));
        vector<int> real;
        for (int i : arr)
            if (s1.count(i))
                real.push_back(i);
        map<int, int> m;
        for (int i = 0; i < size(target); i++) {
            m[target[i]] = i;
        }
        for (int& a : real)
            a = m[a];
        // ps
        set<int> st;
        for (int i : real) {
            if (auto it = st.lower_bound(i); it != st.end()) {
                int val = *it; 
                st.erase(val);
                st.insert(i);
            } else {
                st.insert(i);
            }
        }
        //
        return size(target) - st.size();
    }
};