class Solution {
public:
    vector<int> res;

    void merge(vector<pair<int, int>>& nums, int l, int mid, int r) {
        vector<pair<int, int>> temp;

        int i = l;
        int j = mid + 1;

        int p = i;
        int q = mid + 1;

        // while (p <= mid && q <= r) {
        //     if (nums[p].first > nums[q].first) {
        //         res[nums[p].second]++;
        //         q++;
        //     } else {
        //         p++;
        //     }
        // }

        int rightMoved = 0;

        while (p <= mid && q <= r) {
            if (nums[p].first > nums[q].first) { // condition
                rightMoved++; // ones that satisfy the condition
                q++;
            } else {
                res[nums[p].second] += rightMoved; // when it does not
                p++; // what worked for p will work for p + 1
            }
        }

        while (p <= mid) {
            res[nums[p].second] += rightMoved; // for all the other ps
            p++;
        }

        while (i <= mid && j <= r) {
            if (nums[i].first <= nums[j].first) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i++]);
        }

        while (j <= r) {
            temp.push_back(nums[j++]);
        }

        for (int k = l; k <= r; k++) {
            nums[k] = temp[k - l];
        }
    }

    void mergeSort(vector<pair<int, int>>& nums, int l, int r) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);

        merge(nums, l, mid, r);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        res.assign(n, 0);

        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1);

        return res;
    }
};