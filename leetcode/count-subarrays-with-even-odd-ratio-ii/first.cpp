class Solution {
public:
    long long count = 0;
    void merge(vector<long long>& odd, vector<long long>& even, int l, int m,
               int r, int a, int b) {
        int n1 = m - l + 1, n2 = r - m;
        vector<long long> left(n1);
        vector<long long> right(n2);
        for (int i = 0; i < n1; i++) {
            int index = l + i;
            left[i] = 1LL * even[index] * b - 1LL * odd[index] * a;
        }
        for (int i = 0; i < n2; i++) {
            int index = m + 1 + i;
            right[i] = 1LL * even[index] * b - 1LL * odd[index] * a;
        }
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (left[i] < right[j]) {
                i++;
            } else {
                count += n1 - i;
                j++;
            }
        }
        i = 0, j = 0;
        int k = l;

        vector<long long> ol(n1), orr (n2), el(n1), er(n2);
        for (int i = 0; i < n1; i++) {
            ol[i] = odd[l + i];
            el[i] = even[l + i];
        }
        for (int i = 0; i < n2; i++) {
            orr [i] = odd[m + 1 + i];
            er[i] = even[m + 1 + i];
        }
        i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (left[i] < right[j]) {
                odd[k] = ol[i];
                even[k++] = el[i++];
            } else {
                odd[k] = orr [j];
                even[k++] = er[j++];
            }
        }
        while (i < n1) {
            odd[k] = ol[i];
            even[k++] = el[i++];
        }
        while (j < n2) {
            odd[k] = orr [j];
            even[k++] = er[j++];
        }
    }
    void ms(vector<long long>& odd, vector<long long>& even, int l, int r,
            int a, int b) {
        if (l >= r)
            return;
        int m = l + (r - l) / 2;
        ms(odd, even, l, m, a, b);
        ms(odd, even, m + 1, r, a, b);
        merge(odd, even, l, m, r, a, b);
    }
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = size(nums);
        vector<long long> odd(n + 1, 0), even(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2) {
                odd[i + 1] = odd[i] + 1;
                even[i + 1] = even[i];
            } else {
                even[i + 1] = even[i] + 1;
                odd[i + 1] = odd[i];
            }
        }
        ms(odd, even, 0, n, a, b);
        return count;
    }
};