class Solution {
public:
    double solve(double x, int n) {
        if(n==0) return 1;
        if(n==1) return x;
        if(n%2) {
            return x*solve(x,n-1);
        } else {
            double t = solve(x,n/2);
            return t*t;
        }
    }
    double myPow(double x, int n) {
        if(n>0) return solve(x,n);
        else return 1.0/(solve(x,abs(n)));
    }
};
