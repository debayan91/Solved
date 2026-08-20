class Solution {
public:
    int rotatedDigits(int n) {
        unordered_set<int> st = {0, 1, 8, 2, 5, 6, 9};
        unordered_set<int> st2 = {2, 5, 6, 9};
        int count = 0;
        for(int i = 1; i <= n; i++){
            int a = i;
            bool flag = 0;
            while(a > 0){
                if(!st.count(a % 10)) break;
                if(st2.count(a % 10)) flag = 1;
                a /= 10;
            }
            if(a && !st.count(a % 10)){
                
            } else {
                if(flag) count++;
            }
        }
        return count;
    }
};