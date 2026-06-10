class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        int sum = 1;   // first child
        int i = 0;
        int last = 1;  // candies given to current child

        while (i < n - 1) {

            // equal
            if (ratings[i + 1] == ratings[i]) {
                sum += 1;
                last = 1;
                i++;
            }

            // ascending
            else if (ratings[i + 1] > ratings[i]) {
                last = last + 1;
                sum += last;
                i++;
            }

            // descending
            else {
                int start = i;
                int peakCandy = last;

                while (i + 1 < n && ratings[i + 1] < ratings[i]) {
                    i++;
                }

                int need = 1;

                // assign candies from valley back toward peak, excluding peak
                for (int j = i; j > start; j--) {
                    sum += need;
                    need++;
                }

                // peak must be greater than first descending child
                if (need > peakCandy) {
                    sum += need - peakCandy;
                }

                last = 1; // current position is valley
            }
        }

        return sum;
    }
};