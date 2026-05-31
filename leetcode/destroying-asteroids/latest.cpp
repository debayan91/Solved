class Solution {
public:
    bool asteroidsDestroyed(long long mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        for(int i = 0; i < asteroids.size(); i++){
            if(mass < asteroids[i]) return false;
            mass += asteroids[i];
        }
        return true;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();