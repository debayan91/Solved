class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 0; i < triangle.size(); i++){
            int size = i + 1;
            if(size == 1) continue;
            if(size == 2){
                for(int& a : triangle[i]) a += triangle[0][0];
            }else{
                for(int j = 0; j <= i; j++){
                    if(j == 0){
                        triangle[i][j] += triangle[i - 1][j];
                    }else if(j == i){
                        triangle[i][j] += triangle[i - 1].back();
                    }else{
                        int a = j - 1;
                        int b = j;
                        triangle[i][j] += min(triangle[i - 1][a], triangle[i - 1][b]);
                    }
                }
            }
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};