class FreqStack {
public:
    // val -> timestamps at which it reached each freq
    unordered_map<int, vector<int>> m;

    set<array<int, 3>> st;

    int timer = 0;

    FreqStack() {}

    void push(int val) {
        int freq = m[val].size();

        if (freq > 0) {
            int oldTime = m[val].back();
            st.erase({freq, oldTime, val});
        }

        m[val].push_back(timer);

        st.insert({freq + 1, timer, val});

        timer++;
    }

    int pop() {
        auto it = prev(st.end());

        auto [freq, time, val] = *it;

        st.erase(it);

        m[val].pop_back();

        if (freq == 1) {
            m.erase(val);
        } else {

            int prevTime = m[val].back();

            st.insert({freq - 1, prevTime, val});
        }

        return val;
    }
};