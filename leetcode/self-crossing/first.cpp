class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int i;
        if (distance.size() < 4) {
            return false;
        }
        for (i = 3; i < distance.size(); i++) {
            if (distance[i - 1] <= distance[i - 3]) {
                if (distance[i] >= distance[i - 2]) {
                    return true; // case 1 ie outward
                }
            }
            if ((i > 3) && distance[i - 1] == distance[i - 3]) {
                if (distance[i] + distance[i - 4] >= distance[i - 2]) {
                    return true; // case 2 -- rectangle ish
                }
            }
            if (i >= 5 && distance[i - 2] > distance[i - 4] &&
                distance[i - 1] < distance[i - 3]) {
                if (distance[i - 1] + distance[i - 5] >= distance[i - 3]) {
                    if (distance[i] + distance[i - 4] >= distance[i - 2]) {
                        return true;
                    }
                } else {
                    if (distance[i] >= distance[i - 2]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};