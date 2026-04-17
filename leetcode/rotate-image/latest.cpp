namespace {

// Initializer to configure fast I/O before main() runs
auto const fastIOInit{
    [] -> int {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        return 0;
    } ()
};

} // namespace
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < size(matrix); i++){
            for(int j = i; j < size(matrix[i]); j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < size(matrix); i++){
            reverse(begin(matrix[i]), end(matrix[i]));
        }
    }
};