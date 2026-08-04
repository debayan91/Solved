class Solution {
public:
    int minOperations(int n) {
        string b = std::bitset<32>(n).to_string();
        reverse(begin(b), end(b));
        int i = 0, count = 0; 
        
        while(i < size(b)){
            if(b[i] == '0') {
                i++; 
                continue;
            }
            if(b[i] == '1'){
                if(i + 1 < size(b) && b[i + 1] == '0'){
                    count++;
                } else {
                    int sz = 0;
                    while(i < size(b) && b[i] == '1'){
                        i++;
                        sz++;
                    }
                    if(sz == 1){
                        count++;
                    } else {
                        count++;
                        if(i < size(b)){
                            b[i] = '1'; 
                            i--;
                        }
                    }
                }
            }
            i++;
        }
        return count;
    }
};