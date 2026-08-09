using ll = long long;
class Solution {
public:
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& q) {
        // segtree
        int n = size(nums), qn = size(q);

        vector<ll> res;

        struct Node {
            ll count = 0, sum = 0, sumsq = 0;
            ll first = -1, last = -1, sum_prod = 0;
        };

        vector<Node> seg(4 * n);

        auto peak = [&](int i) -> bool {
            if (i == 0 || i == n - 1)
                return 0;
            return (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]);
        };

        auto merge = [&](Node a, Node b) -> Node {
            if (a.count == 0)
                return b;
            if (b.count == 0)
                return a;
            return {a.count + b.count,
                    a.sum + b.sum,
                    a.sumsq + b.sumsq,
                    a.first,
                    b.last,
                    a.sum_prod + b.sum_prod + 1LL * a.last * b.first};
        };

        function<void(int, int, int)> build = [&](int i, int l,
                                                  int r) { // index
            if (l == r) {
                if (peak(l)) {
                    seg[i] = {1, l, 1LL * l * l, l, l, 0};
                }
                return;
            }
            int m = l + (r - l) / 2;
            build(2 * i, l, m);
            build(2 * i + 1, m + 1, r);

            seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
        };

        function<void(int, int, int, int)> update = [&](int i, int l, int r,
                                                        int index) {
            if (l == r) {
                seg[i] = Node();

                if (peak(index)) {
                    seg[i] = {1, index, 1LL * index * index, index, l, 0};
                }

                return;
            }

            int m = l + (r - l) / 2;

            if (index <= m) {
                update(2 * i, l, m, index);
            } else {
                update(2 * i + 1, m + 1, r, index);
            }

            seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
        };

        function<Node(int, int, int, int, int)> query = [&](int i, int l, int r,
                                                            int ql, int qr) {
            if (ql > r || qr < l)
                return Node();

            if (ql <= l && qr >= r)
                return seg[i];

            int m = l + (r - l) / 2;

            Node left = query(2 * i, l, m, ql, qr);
            Node right = query(2 * i + 1, m + 1, r, ql, qr);

            return merge(left, right);
        };

        ////////

        build(1, 0, n - 1);

        for (auto& a : q) {
            if (a[0] == 1) {
                ll l = a[1], r = a[2];

                if (r - l < 2) {
                    res.push_back(0);
                    continue;
                }

                Node current = query(1, 0, n - 1, l + 1, r - 1);

                if (current.count == 0) {
                    res.push_back(0);
                    continue;
                }

                // ll rr = 1LL * (l + r) * current.sum - current.sumsq - 1LL * l
                // * r * current.count;

                // res.push_back(rr);

                ll ss = 1LL * (l + r) * current.sum - current.sumsq -
                        1LL * l * r * current.count;
                ll dd = 1LL * r * (current.sum - current.last) +
                        1LL * l * (current.sum - current.first) -
                        current.sum_prod - 1LL * l * r * (current.count - 1);

                res.push_back(ss - dd);
            } else {
                int index = a[1], value = a[2];

                nums[index] = value;

                for (int i = max(0, index - 1); i <= min(n - 1, index + 1);
                     i++) {
                    update(1, 0, n - 1, i);
                }
            }
        }

        return res;
    }
};
