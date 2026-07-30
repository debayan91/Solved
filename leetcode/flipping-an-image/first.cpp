class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto& a : image){
            reverse(begin(a), end(a));
        }
        for(auto& a : image){
            for(int& b : a){
                b = 1 - b;
            }
        }
        return image;
    }
};