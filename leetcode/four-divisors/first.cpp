class Solution {
public:
    int ok(int a){
        int count = 0;
        int sum = 0;
        for(int i = 1; i <= a; i++){
            if(a % i == 0){
                count++;
                if(count > 4) return 0;
                sum += i;
            }
        }
        if(count == 4) return sum;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(int i : nums) sum += ok(i);
        return sum;
    }
};