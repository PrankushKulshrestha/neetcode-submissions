class Twitter {
private:
    vector<pair<int, int>> tweets[501];
    unordered_set<int> follows[501];
    int time;

public:
    Twitter() {
        time = 0;
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>
        > pq;
        if (!tweets[userId].empty()) {
            int idx = tweets[userId].size() - 1;
            pq.push({
                tweets[userId][idx].first,
                userId,
                idx
            });
        }
        for (int followee : follows[userId]) {
            if (!tweets[followee].empty()) {
                int idx = tweets[followee].size() - 1;
                pq.push({
                    tweets[followee][idx].first,
                    followee,
                    idx
                });
            }
        }
        vector<int> result;
        while (!pq.empty() && result.size() < 10) {
            auto [timestamp, user, idx] = pq.top();
            pq.pop();
            result.push_back(tweets[user][idx].second);
            if (idx > 0) {
                idx--;
                pq.push({
                    tweets[user][idx].first,
                    user,
                    idx
                });
            }
        }
        return result;
    }
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};