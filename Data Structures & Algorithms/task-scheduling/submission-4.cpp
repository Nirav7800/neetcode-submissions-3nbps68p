class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        // Step 1: Count frequency of each task
        unordered_map<char,int> mp;
        
        // max_freq = maximum frequency among all tasks
        int max_freq = 1;
        
        for(auto t : tasks){
            mp[t]++;
            max_freq = max(max_freq, mp[t]);
        }

        // Step 2: Count how many tasks have the maximum frequency
        // Example: A=3, B=3 → count = 2
        int count = 0;
        for(auto &p : mp){
            if(p.second == max_freq){
                count++;
            }
        }

        /*
        Step 3: Calculate minimum time using bucket formula

        Idea:
        The most frequent task determines the skeleton of the schedule.

        Example:
        tasks = A A A B B B
        n = 2

        Place most frequent task first:

        A _ _ | A _ _ | A

        Here:
        max_freq = 3
        blocks = max_freq - 1 = 2

        Each block size = n + 1
        (1 task + n cooldown slots)

        So total block slots:
        (max_freq - 1) * (n + 1)

        The last row must contain all tasks with max_freq.
        If A and B both appear 3 times → last row = A B

        So we add:
        + count
        */

        int time = (max_freq - 1) * (n + 1) + count;

        /*
        Step 4: Sometimes we have enough tasks to fill all idle slots.

        Example:
        A A A B B B C C

        We can schedule without idle:
        A B A B A B C C

        So the answer cannot be smaller than total tasks.
        */

        return max((int)tasks.size(), time);
    }
};