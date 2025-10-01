class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int d = numBottles; //drunk 
        int empty = numBottles; //initial empty
        while(empty >= numExchange){
            // d += empty / numExchange; 
            // empty = empty / numExchange + empty % numExchange;
            // numExchange++;

            empty -= numExchange;
            empty++;
            d++;
            numExchange++;

        }
        return d;
    }
};