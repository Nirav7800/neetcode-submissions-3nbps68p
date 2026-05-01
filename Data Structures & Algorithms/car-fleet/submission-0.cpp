class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>arr;
        int n = position.size();
        for(int i=0;i<n;i++) {
            arr.push_back({position[i],speed[i]});
        }


        sort(arr.begin(),arr.end());

        //calculate time taken for each car to reach target
        vector<double>tt(n,0);
        for(int i=0;i<n;i++) {
            double time = (1.0*(target-(arr[i].first))/(arr[i].second));
            tt[i]=time;
            cout<<tt[i]<<" ";
        }
        cout<<endl;

        int count =1;
        int prev = tt[n-1];
        stack<double>st;
        for(int i=n-1;i>=0;i--) {
           while(!st.empty() && st.top()<tt[i]) st.pop();
           if(!st.empty()) tt[i]=st.top();
           st.push(tt[i]);
        }
        for(int i=1;i<n;i++) {
            cout<<tt[i]<<" ";
            if(tt[i]!=tt[i-1]) count++;
        }
        return count;
    }
};