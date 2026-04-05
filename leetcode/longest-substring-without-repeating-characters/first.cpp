class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int max_len = 0;
        unordered_map<char,int> umap;
        int start = 0;
        int len = 0;
        for(int i=0;i<n;i++){
            if(umap.count(s[i]) == 0 || umap[s[i]] < start){
                umap[s[i]] = i;
                //len++;

                len = i - start + 1;
                max_len = max(len,max_len);
            }else{
                //if we have encountered the same element in the past
                int location = umap[s[i]]; //index of where it was
                //we cannot take anything that came before it 
                //so our substring starting index becomes the one after it
                //now before we change substring length we need to compare it to current max
                
                //now the new string starts at after the bad element
                start = location + 1;
                //update the value in the map
                umap[s[i]] = i;
                //now we face a different problem - what if some characters that came before, came before the starting point
                //we need to do all this only if the thing comes after the start point - so we change the condition that leads to this
                len = i - start + 1;
                max_len = max(len,max_len);

            }
        }
        return max_len;
    }
};