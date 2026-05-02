class Solution {
public:
    int getSum(int a, int b) {
        int ans =0;
        int c = 0;
        for(int i=0;i<32;i++){
            if((1<<i)&a && (1<<i)&b) {
                if(c==1){
                    ans|=(1<<i);
                }else{
                    c=1;
                }
            } else {
                if((1<<i)&a) {
                    if(c!=1) {
                      ans|=(1<<i);
                    } 
                } else if((1<<i)&b) {
                    if(c!=1) {
                      ans|=(1<<i);
                    } 
                } else {
                    if(c==1) {
                       ans|=(1<<i);
                       c=0;
                    }
                }
            }
        }
        return ans;
    }
};
