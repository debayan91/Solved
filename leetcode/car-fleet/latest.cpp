class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 1) return n;
        vector<vector<double>> cars;
        for(int i = 0; i < n; i++){
            double arrival = (double)(target - position[i]) / speed[i];
            // if a car arrives faster than another - they definitely merge
            cars.push_back({(double)position[i], (double)speed[i], arrival});
        }
        sort(begin(cars), end(cars), [](auto& a, auto& b){
            return a[0] > b[0];
        });
        // cars sorted by their arrivals
        // if arrival is more and pos is back then no chance
        // if arrival is less and pos is back then merge
        // if arrival is more and pos is front then merge
        // if arrival is less and pos is front then no chance

        // in 2 cases we can merge

        // so now i have the cars sorted by arrival times
        // so car 1 can merge with car 2 iff
        // well car 1 arrives faster - to meet pos(car 1) <= pos(Car 2)
        // same arrival times also merge
        // or if i know that pos(x) > pos(x + 1) then i can merge if arrival(x + 1) <= pos(x + 1)

        int count = 0;
        for(int i = 0; i < n - 1; i++){
            if(cars[i + 1][2] <= cars[i][2]){
                // car i is gonna arrive with car i + 1 at arrival of i + 1
                cars[i + 1][2] = max(cars[i + 1][2], cars[i][2]);
                continue;
            } else {
                count++;
            }
        }
        count++; // last car / fleet
        return count;
    }
};