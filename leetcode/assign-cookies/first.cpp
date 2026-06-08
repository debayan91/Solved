class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        int i = 0;
        int j = 0;
        while(i < size(g) && j < size(s)){
            // skip all the cookies that cant satisfy the least greedy kid
            while(j < size(s) && s[j] < g[i]) j++;
            // if no such cookie exists
            if(j >= size(s)) break;
            else {
                i++;
                j++;
            }
        }
        return i;
    }
};