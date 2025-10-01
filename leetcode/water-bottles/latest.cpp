class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int d = numBottles; //drunk 
        int empty = numBottles; //initial empty
        while(empty >= numExchange){
            d += empty / numExchange; 
            empty = empty / numExchange + empty % numExchange;
        }
        return d;
    }
};