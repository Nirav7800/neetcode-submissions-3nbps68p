class Solution {
public:
 int maxArea(vector<int>& height) {
        int n = height.size();
        int p1 =0;
        int p2 =n-1;
        int ans =0;
        while(p1<p2) {
            int curr = min(height[p1],height[p2])*(p2-p1);
            ans = max(ans,curr);
            if(height[p1]<=height[p2]) p1++;
            else p2--;
        }
        return ans;
    }
};
