class MyCalendarThree {
public:
    vector<pair<int,int>> events;

    MyCalendarThree() {

    }

    int book(int start, int end) {
        events.push_back({start, end});

        vector<pair<int,int>> points;

        for (auto [s,e] : events) {
            points.push_back({s, +1});
            points.push_back({e, -1});
        }

        sort(points.begin(), points.end());

        int cur = 0;
        int ans = 0;

        for (auto [x, delta] : points) {
            cur += delta;
            ans = max(ans, cur);
        }

        return ans;
    }
};