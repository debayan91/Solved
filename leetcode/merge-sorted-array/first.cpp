class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums2.insert(end(nums2), begin(nums1), begin(nums1) + m);
        int k = 0;
        int i = 0;
        int j = n;
        while(i < n && j < n + m){
            if(nums2[i] < nums2[j]){
                nums1[k++] = nums2[i++];
            }else{
                nums1[k++] = nums2[j++];
            }
        }
        while(i < n){
            nums1[k++] = nums2[i++];
        }
        while(j < n + m){
            nums1[k++] = nums2[j++];
        }
    }
};