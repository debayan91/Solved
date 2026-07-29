class Solution {
public:
    vector<string> res;

    void b(int target, const string& current, string& num, int index,
           long long sum, long long last) {

        if (index == num.size()) {
            if (sum == target)
                res.push_back(current);
            return;
        }

        int start = index;

        for (int stop = index; stop < num.size(); stop++) {

            if (stop > start && num[start] == '0')
                break;

            string curr = num.substr(start, stop - start + 1);
            long long val = stoll(curr);

            if (start == 0) {
                b(target, current + curr, num, stop + 1, val, val);
            } else {
                // +
                b(target, current + "+" + curr, num, stop + 1, sum + val, val);

                // -
                b(target, current + "-" + curr, num, stop + 1, sum - val, -val);

                // *
                b(target, current + "*" + curr, num, stop + 1,
                  sum - last + last * val, last * val);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        b(target, "", num, 0, 0, 0);
        return res;
    }
};