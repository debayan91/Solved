class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<int> freq(26);
        for(char c : s1) freq[c - 'a']++;

        vector<int> temp;
        temp = freq;

        int i = 0;
        while(i < n2){
            if(freq[s2[i] - 'a'] == 0) i++;
            else{
                int index = i;
                int len = 0;
                temp = freq;
                while(i < n2 && temp[s2[i] - 'a'] > 0){
                    temp[s2[i] - 'a']--;
                    i++;
                    len++;
                }
                if(len == n1) return true;
                else i = index + 1;
            }
        }
        
        return false;
    }
};