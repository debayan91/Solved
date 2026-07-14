class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = size(deck);
        sort(begin(deck), end(deck));
        vector<int> res(n);
        queue<int> q;
        for(int i = 0; i < n; i++) q.push(i);
        for(int i = 0; i < n; i++){
            int index = q.front();
            res[index] = deck[i];
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return res;
    }
};