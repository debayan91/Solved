class Solution {
public:
    vector<bool> canEat(vector<int>& cc, vector<vector<int>>& qr) {
        int nq = size(qr);
        vector<bool> res(nq, false);
        int n = size(cc);
        vector<unsigned long int> prefix(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            prefix[i] = prefix[i - 1] + cc[i - 1];
            // cout << prefix[i] << " ";
        }
        // prefix[i] is the number of candies you gotta eat before you can eat
        // ith candy
        for (int i = 0; i < nq; i++) {
            unsigned long int type = qr[i][0];
            unsigned long int days = qr[i][1];
            unsigned long int cap = qr[i][2];

            if ((days + 1) * cap <= prefix[type])
                continue;

            if (days + 1 > prefix[type + 1])
                continue;

            res[i] = true;
        }
        return res;
    }
};