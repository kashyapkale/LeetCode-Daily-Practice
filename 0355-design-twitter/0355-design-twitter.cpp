class Twitter {
private:
    unordered_map<int, unordered_set<int>> usersToFollowersMap;
    //pair {userId, tweetId}
    vector<pair<int, int>> newsFeed; 
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        newsFeed.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> followers = usersToFollowersMap[userId];
        vector<int> userNewsFeed;
        int newsFeedLen = newsFeed.size();
        int index = newsFeedLen - 1;
        int counter = 10;
        while(index >= 0 && counter) {
            auto news = newsFeed[index];
            if(followers.find(news.first) != followers.end() || news.first == userId){
                userNewsFeed.push_back(news.second);
                counter--;
            }
            index--;
        }
        
        return userNewsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        usersToFollowersMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        usersToFollowersMap[followerId].erase(followeeId);
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