#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

static constexpr size_t max_align = alignof(max_align_t);
alignas(max_align) static unsigned char BUFFER[64 * 1024 * 1024];
static size_t pos = 0;

void *operator new(const size_t size) {
    const size_t padding = (max_align - (pos % max_align)) % max_align;
    pos += padding + size;
    return static_cast<void *>(&BUFFER[pos - size]);
}

void *operator new[](const size_t size) { return operator new(size); }
void operator delete(void *) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete(void *, size_t) noexcept {}
void operator delete[](void *, size_t) noexcept {}

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0; // 5
        int b = 0; // 10
        for(int bill : bills){
            int retur = bill - 5;
            if(bill == 5) a++;
            if(bill == 10) b++;
            // possible return 0 5 15
            if(retur == 5){
                if(a > 0){
                    a--;
                }else{
                    return false;
                }
            }
            
            if(retur == 15){
                // return is 15 - 10 + 5 or 5 + 5 + 5
                if(a > 0 && b > 0){
                    a--;
                    b--;
                }else if(a > 2){
                    a -= 3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};