#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <cstdint>
#include <span>
#include <bitset>

class Twitter {
private:
    std::array<std::bitset<501>, 501> follows;
    std::array<int, 10'000> tweetIds;
    std::array<int, 10'000> tweetAuthors;
    int clock_;

public:
    Twitter() {
        follows = std::array<std::bitset<501>, 501>();
        for (int i = 0; i < 501; i++) {
            follows[i].set(i);
        }

        clock_ = 0;
    };
    
    void postTweet(int userId, int tweetId) {
        tweetAuthors[clock_] = userId;
        tweetIds[clock_] = tweetId;
        clock_++;
    }
    
    std::vector<int> getNewsFeed(int userId) {
        std::vector<int> topTen;
        topTen.reserve(10);
        
        const std::bitset<501>& userFollows = follows[userId];

        for (int i = clock_ - 1; i >= 0; i--) {
            if(userFollows.test(tweetAuthors[i])) {
                topTen.emplace_back(tweetIds[i]);
            }

            if (topTen.size() >= 10) {
                return topTen;
            }
        }

        return topTen;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].set(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) [[unlikely]] return;
        follows[followerId].reset(followeeId);
    }
};
