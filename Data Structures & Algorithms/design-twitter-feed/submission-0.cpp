#define sz(a) (int)(a).size()

using pii = pair<int,int>;

// IDs are unique but not necessarily chronological
// At most 500 users -> when retrieving the 10 most recent tweets need to look at at most 500 * 10 tweets

class Twitter {
public:
    // Key: userId
    // Value: posted tweets, where each tweet is (timestamp, tweetId)
    // Timestamps per user always stored in chronological order
    unordered_map<int, vector<pii>> users;

    // Key: userId
    // Value: list of userIds that user follows
    unordered_map<int, unordered_set<int>> follows;
    int ts = 0;

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        users[userId].push_back({++ts, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Stores 10 most recent relevant tweets -> should be min pq so least recent  can always be removed quickly
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (auto &tweet : users[userId]) {
            pq.push(tweet);
            if (sz(pq) > 10) {
                pq.pop();
            }
        }
        for (auto followee : follows[userId]) {
            for (auto &tweet : users[followee]) {
                pq.push(tweet);
                if (sz(pq) > 10) {
                    pq.pop();
                }
            }
        }
        vector<int> feed;
        while (!pq.empty()) {
            feed.push_back(pq.top().second);
            pq.pop();
        }
        reverse(feed.begin(), feed.end());
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
