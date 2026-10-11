
bool b[100009][4];
int w[100009][4];

class BusBooking {
    int total, count;

public:
    BusBooking(int n) {
        total = 0, count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 4; j++) {
                b[i][j] = w[i][j] = 0;
            }
        }
    }

    void toggle(string s) {
        int i = stoi(s.substr(1)), j = s[0] - 'A';
        if (b[i][j]) {
            total -= w[i][j];
            b[i][j] = w[i][j] = 0;
            count--;
        } else {
            int cost = 1;
            if (!j && b[i][1])
                cost = 3;
            else if (j == 3 && b[i][2])
                cost = 3;
            w[i][j] = cost;
            total += cost;
            b[i][j] = 1;
            count++;
        }
    }

    int getTotalTime() { return total; }

    int getMinTime() { return count; }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */