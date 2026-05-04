class Twitter {
public:
//user->follow
    unordered_map<int,unordered_set<int>>followmp;
//user to post
int count;
   unordered_map<int,vector<pair<int,int> >>post;
    Twitter() {
        post.clear();
        followmp.clear();
        count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].push_back({count++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        //get all of the follow;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >minH;
        for(auto p:post[userId]){
            minH.push(p);
            if(minH.size()>10){
                minH.pop();
            }
        }

        //get post from its follow
        for(auto f:followmp[userId]){
            for(auto p:post[f]){
               minH.push(p);
                if(minH.size()>10){
                    minH.pop();
                }
            }
        }

        vector<int>recentposts;
        while(!minH.empty()) {
            recentposts.push_back(minH.top().second);
            minH.pop();
        }
        reverse(recentposts.begin(),recentposts.end());
        
        return recentposts;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
        followmp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
         if(followerId!=followeeId)
        followmp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */