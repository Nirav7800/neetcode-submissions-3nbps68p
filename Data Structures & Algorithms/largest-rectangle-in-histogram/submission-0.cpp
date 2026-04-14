class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nsl(n,-1);
        vector<int>nsr(n,n);

        //populate next smaller on left
        stack<int>s1;
        for(int i=0;i<n;i++) {
            while(!s1.empty() && heights[s1.top()]>=heights[i]) {
                s1.pop();
            }
            if(!s1.empty()) nsl[i]=s1.top();
            s1.push(i);
        }

        //populate next smaller on right
        stack<int>s2;
        for(int i=n-1;i>=0;i--) {
            while(!s2.empty() && heights[s2.top()]>=heights[i]) {
                s2.pop();
            }
            if(!s2.empty()) nsr[i]=s2.top();
            s2.push(i);
        }

        int largest_rectangle = 0;
        for(int i=0;i<n;i++) {
            int l = nsl[i];
            int r = nsr[i];
            largest_rectangle=max(largest_rectangle,heights[i]*(r-l-1));
        }
        return largest_rectangle;

    }
};
