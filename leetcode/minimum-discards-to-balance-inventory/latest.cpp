class Solution {
public:
    int minArrivalsToDiscard(vector<int>& a, int w, int m) {
        int n = size(a);
        unordered_map<int, int> mp; // type, freq
        vector<bool> kept(n, false);
        int remove = 0;
        int i = 0;

        while(i < n) {
            if(i - w >= 0 && kept[i - w]) {
                mp[a[i - w]]--;
            }

            mp[a[i]]++; // add new

            if(mp[a[i]] > m) {
                mp[a[i]]--;
                remove++;
            } else {
                kept[i] = true;
            }

            i++;
        }

        return remove;
    }
};