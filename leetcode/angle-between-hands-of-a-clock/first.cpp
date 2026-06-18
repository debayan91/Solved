class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour %= 12;
        double md = (minutes * 360 / 60);
        double hd = (hour * 360 / 12) + md / 12;
        // cout << hd << " " << md;
        double diff = max(hd - md, md - hd);
        if(diff > 180) diff = 360 - diff;
        return diff;
    }
};