class Twitter {
   private:
    unordered_map<int, vector<int>> userTweetMap;
    unordered_map<int, unordered_set<int>> userFllowerMap;
    unordered_map<int, int> tweetTimeStampMap;
    int timeStamp;

   public:
    Twitter() { timeStamp = 0; }

    void postTweet(int userId, int tweetId) {
        userTweetMap[userId].push_back(tweetId);
        tweetTimeStampMap[tweetId] = ++timeStamp;
    }

    vector<int> getNewsFeed(int userId) {
        unordered_set<int> following;
        if (userFllowerMap.find(userId) != userFllowerMap.end()) {
            following = userFllowerMap[userId];
        }
        unordered_set<int> relevent = following;
        relevent.insert(userId);
        vector<int> news;
        priority_queue<pair<int, int>> pq;
        for (auto curr : relevent) {
            if (userTweetMap.find(curr) != userTweetMap.end()) {
                vector<int>& currTweets = userTweetMap[curr];
                if (!currTweets.empty()) {
                    int currSize = min(10, static_cast<int>(currTweets.size()));
                    for (int i = currTweets.size() - 1;
                         i >= static_cast<int>(currTweets.size()) -currSize; i--) {
                        pq.push({tweetTimeStampMap[currTweets[i]], currTweets[i]});
                    }
                }
            }
        }
       while (!pq.empty() && news.size()<10) {
            news.push_back(pq.top().second);
            pq.pop();
        }
        return news;
    }

    void follow(int followerId, int followeeId) { userFllowerMap[followerId].insert(followeeId); }

    void unfollow(int followerId, int followeeId) {
        if (userFllowerMap.find(followerId) != userFllowerMap.end())
            userFllowerMap[followerId].erase(followeeId);
    }
};
