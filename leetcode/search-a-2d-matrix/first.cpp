class Solution {
public:
    bool bs(vector<vector<int>>& matrix, int l, int h, int target){
        if(l > h) return false;
        int mid = (h + l) / 2;
        //cout<<mid<<endl;
        int cols = matrix[0].size();
        int i = mid / cols;
        int j = mid % cols;
        if(matrix[i][j] == target) return true;
        if(matrix[i][j] < target) return bs(matrix, mid + 1, h, target);
        else return bs(matrix, 0, mid - 1, target);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int last = rows * cols - 1;
        return bs(matrix,0,last,target);
    }
};