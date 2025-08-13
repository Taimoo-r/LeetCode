class Twitter {
public:
    list<pair<int, int>> l;
    unordered_map<int, unordered_set<int>> mp; // follower -> set of followees

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        l.push_front({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> tweets;
        for(auto it = l.begin(); it != l.end() && tweets.size() < 10; ++it) {
            if(it->first == userId || mp[userId].count(it->first)) {
                tweets.push_back(it->second);
            }
        }
        return tweets;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        mp[followerId].erase(followeeId);
    }
};
