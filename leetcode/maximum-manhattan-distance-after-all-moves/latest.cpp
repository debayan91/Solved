class Solution {
public:
    int maxDistance(string moves) {
        int x = 0;
        int y = 0;
        int inst = 0;
        for(char c : moves){
            if(c == 'U'){
                y++;
            }
            if(c == 'D'){
                y--;
            }
            if(c == 'L'){
                x++;
            }
            if(c == 'R'){
                x--;
            }
            if(c == '_'){
                inst++;
            }
        }
        return abs(x) + abs(y) + inst;
    }
};