class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        int m = size(word1);
        int n = size(word2);
        string k = "";
        while(i < m && j < n){
            k += word1[i++];
            k += word2[j++];
        }
        while(i < m){
            k += word1[i++];

        }
        while(j < n){

            k += word2[j++];
        }
        return k;
    }
};