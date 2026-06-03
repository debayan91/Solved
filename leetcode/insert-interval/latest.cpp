class Solution {
public:
    vector<int> merge(vector<int>& a, vector<int>& b) {
        a[0] = min(a[0], b[0]);
        a[1] = max(a[1], b[1]);
        return a;
    }
    bool overlap(vector<int>& a, vector<int>& b) {
        if ((b[0] >= a[0] && b[0] <= a[1]) || (b[1] >= a[0] && b[1] <= a[1]))
            return true;
        if ((a[0] >= b[0] && a[0] <= b[1]) || (a[1] >= b[0] && a[1] <= b[1]))
            return true;
        return false;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& a) {
        if (intervals.size() == 0) {
            intervals.push_back(a);
            return intervals;
        }
        int i = 0;
        for (i = 0; i < intervals.size(); i++) {
            if (a[0] < intervals[i][0])
                break;
        }
        intervals.insert(intervals.begin() + i, a);
        // new interval is at intervals[i]
        int n = intervals.size();
        if (i == n - 1) {

            while (i > 0 && overlap(intervals[i], intervals[i - 1])) {
                vector<int> merged = merge(intervals[i], intervals[i - 1]);

                intervals.erase(intervals.begin() + i - 1,
                                intervals.begin() + i + 1);
                intervals.insert(intervals.begin() + i - 1, merged);

                i--;
            }

        } else if (i == 0) {
            while (intervals.size() > 1 &&
                   overlap(intervals[0], intervals[1])) {
                vector<int> merged = merge(intervals[0], intervals[1]);

                intervals.erase(intervals.begin(), intervals.begin() + 2);
                intervals.insert(intervals.begin(), merged);
            }
        } else {
            while (i > 0 && overlap(intervals[i], intervals[i - 1])) {
                vector<int> merged = merge(intervals[i], intervals[i - 1]);

                intervals.erase(intervals.begin() + i - 1,
                                intervals.begin() + i + 1);
                intervals.insert(intervals.begin() + i - 1, merged);

                i--;
            }

            while (i + 1 < intervals.size() &&
                   overlap(intervals[i], intervals[i + 1])) {
                vector<int> merged = merge(intervals[i], intervals[i + 1]);

                intervals.erase(intervals.begin() + i,
                                intervals.begin() + i + 2);
                intervals.insert(intervals.begin() + i, merged);
            }
        }
        return intervals;
    }
};