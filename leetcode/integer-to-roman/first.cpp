class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> v = {
            {1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},  {10, "X"},
            {40, "XL"}, {50, "L"},   {90, "XC"}, {100, "C"}, {400, "CD"},
            {500, "D"}, {900, "CM"}, {1000, "M"}};
        string res = "";
        int index = v.size() - 1;
        while(num > 0){
            while(v[index].first > num) index--;
            int k = num / v[index].first;
            num = num % v[index].first;
            for(int i = 0; i < k; i++) res += v[index].second;
        }
        return res;
    }
};