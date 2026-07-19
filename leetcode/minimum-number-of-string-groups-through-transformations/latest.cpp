class Solution {
public:
    string ms(string s){
        // find maz shifdt of s
        int n = size(s);
        if(n < 2) return s;
        int n2 = 2 * n;
        s = s + s;
        // msize = 2
        int i = 0, j = 1, k;
        while(i < n && j < n){ // i ->> n j is by offset
            k = 0;
            while(k < n && s[i + k] == s[j + k]) k++;
            if(s[i + k] < s[j + k]){
                i += k + 1;
                i = i == j ? i + 1 : i;
                
            } else {
                j += k + 1;
                j = i == j ? j + 1 : j;
            }
        }
        i = min(i, j);
        s = s.substr(i, n);
        return s;
    }
    int minimumGroups(vector<string>& words) {
        unordered_set<string> st; // groups
        for(string& word : words){
            string even = "", odd = "";
            for(int i = 0; i < size(word); i++){
                if(i % 2) odd += word[i];
                else even += word[i];
            }
            string mxodd = ms(odd);
            // for(int i = 0; i < size(odd); i++){
            //     string a = odd.substr(0, i);
            //     string b = odd.substr(i, size(odd) - i + 1);
            //     string c = b + a;
            //     mxodd = max(mxodd, c);
            // }
            string mxeven = ms(even);
            // for(int i = 0; i < size(even); i++){
            //     string a = even.substr(0, i);
            //     string b = even.substr(i, size(even) - i + 1);
            //     string c = b + a;
            //     mxeven = max(mxeven, c);
            // }

            string current = mxodd + "****" + mxeven;
            st.insert(current);
        }
        return st.size();
    }
};