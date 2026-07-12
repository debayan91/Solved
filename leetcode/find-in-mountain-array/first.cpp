/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peak(MountainArray &ma, int l, int h) {
        if(l == h) return l;
        int m  = (l + h) / 2;
        int mid = ma.get(m);
        int before = ma.get(m - 1);
        int after = ma.get(m + 1);
        if(before < mid && after < mid){
            return m;
        }
        if(after > mid){
            return peak(ma, m + 1, h);
        } else {
            return peak(ma, l, m - 1);
        }
    }
    int find_asc(MountainArray &ma, int l, int h, int target) {
        if(l > h) return -1;
        int m  = (l + h) / 2;
        int mid = ma.get(m);
        if(mid == target){
            return m;
        }
        if(target > mid){
            return find_asc(ma, m + 1, h, target);
        } else {
            return find_asc(ma, l, m - 1, target);
        }
    }
    int find_desc(MountainArray &ma, int l, int h, int target) {
        if(l > h) return -1;
        int m  = (l + h) / 2;
        int mid = ma.get(m);
        if(mid == target){
            return m;
        }
        if(target < mid){
            return find_desc(ma, m + 1, h, target);
        } else {
            return find_desc(ma, l, m - 1, target);
        }
    }
    int findInMountainArray(int target, MountainArray &ma) {
        int n  = ma.length();
        int p = peak(ma, 1, n - 2);
        int found = find_asc(ma, 0, p, target);
        if(found == -1){
            found = find_desc(ma, p + 1, n - 1, target);
        }
        return found;
    }
};