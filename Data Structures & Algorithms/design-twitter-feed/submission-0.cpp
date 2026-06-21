class User {
public:
    vector<int> tweets;                // tweetIds
    unordered_set<int> following;
};

class Twitter {
private:
    unordered_map<int, User> users;        // user -> User
    unordered_map<int, int> tweetTime;     // tweetId -> timestamp

    int timer;

public:
    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        users[userId].tweets.push_back(tweetId);
        tweetTime[tweetId] = timer++;
    }

    vector<int> getNewsFeed(int userId) {

        vector<pair<int,int>> news; // {time,tweetId}

        // own tweets
        for(int tweet : users[userId].tweets) {
            news.push_back({tweetTime[tweet], tweet});
        }

        // followees tweets
        for(int followee : users[userId].following) {

            for(int tweet : users[followee].tweets) {
                news.push_back({tweetTime[tweet], tweet});
            }
        }

        sort(news.begin(), news.end(),
            [](auto &a, auto &b){
                return a.first > b.first;
            });

        vector<int> ans;

        for(int i=0; i<min(10,(int)news.size()); i++) {
            ans.push_back(news[i].second);
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {

        if(followerId == followeeId)
            return;

        users[followerId].following.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        users[followerId].following.erase(followeeId);
    }
};