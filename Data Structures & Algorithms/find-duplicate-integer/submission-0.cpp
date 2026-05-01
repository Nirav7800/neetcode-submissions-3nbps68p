class Solution {
public:
//https://youtu.be/wjYnzkAhcNk?si=ZZxr9Vie2uxFlJXY
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast =nums[nums[fast]];
        }while(slow!=fast);

        slow = nums[0];
        while(slow!=fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};