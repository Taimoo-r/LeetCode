class p{
public:
    set<int> followers;
    set<int> following;
    vector<int> posts; // user’s own tweets
};

class Twitter {
public:
    unordered_map<int, p> users;
    int timestamp = 0;                 // global time for ordering
    unordered_map<int,int> tweetTime;  // tweetId -> timestamp

    Twitter() {
    }
    
    void postTweet(int uId, int tId) {
        users[uId].posts.push_back(tId);
        tweetTime[tId] = timestamp++;
    }
    
    vector<int> getNewsFeed(int uId) {
        vector<int> feed;
        // collect user + followees
        vector<int> candidates;
        for(int tweet : users[uId].posts) candidates.push_back(tweet);
        for(int followee : users[uId].following) {
            for(int tweet : users[followee].posts) candidates.push_back(tweet);
        }
        // sort tweets by timestamp descending
        sort(candidates.begin(), candidates.end(), [&](int a, int b){
            return tweetTime[a] > tweetTime[b];
        });
        // take top 10
        for(int i = 0; i < min(10, (int)candidates.size()); i++)
            feed.push_back(candidates[i]);
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        users[followeeId].followers.insert(followerId);
        users[followerId].following.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        users[followeeId].followers.erase(followerId);
        users[followerId].following.erase(followeeId);
    }
};