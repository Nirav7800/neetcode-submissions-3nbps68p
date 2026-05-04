class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n+m;
        //first make the partition of size total/2;
        int rsize = total/2;
        int lo = 0;
        int hi = n;
        int idx = hi;
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            //check if this partition is valid
            int restneeded = (total+1)/2-mid;
            int leftcut1 = (mid==0)?INT_MIN:nums1[mid-1];
            int leftcut2 = (restneeded==0)?INT_MIN:nums2[restneeded-1];

            int rightcut1 = (mid==n)?INT_MAX:nums1[mid];
            int rightcut2 = (restneeded==m)?INT_MAX:nums2[restneeded];

            //check if its valid cut
            if(leftcut1<=rightcut2 && leftcut2<=rightcut1){
                if(total%2) {
                    return max(leftcut1,leftcut2);
                } else {
                    return (max(leftcut1,leftcut2)+min(rightcut1,rightcut2))/2.0;
                }
            }else if(leftcut1>rightcut2) {
                hi=mid-1;
            }else {
                lo=mid+1;
            }
        }

        return 0.0;
    }
};
