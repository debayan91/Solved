class Twitter {
public:
    unordered_map<int, unordered_set<int>> m; // a and who he follows
    unordered_map<int, vector<array<int, 2>>> posts;
    int timer = 0;

    Twitter() {}

    void postTweet(int a, int t) { posts[a].push_back({timer++, t}); }

    vector<int> getNewsFeed(int a) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
        for (auto& post : posts[a]) {
            pq.push(post);
            if (pq.size() > 10)
                pq.pop();
        }
        for (auto& i : m[a]) {
            for (auto& post : posts[i]) {
                pq.push(post);
                if (pq.size() > 10)
                    pq.pop();
            }
        }
        vector<int> res(pq.size()); int i = pq.size() - 1;
        while(!pq.empty()){
            res[i--] = pq.top()[1]; pq.pop();
        }
        return res;
    }

    void follow(int b, int a) { // b follows a
        m[b].insert(a);
    }

    void unfollow(int b, int a) { // b unfollows a
        if (m[b].count(a))
            m[b].erase(a);
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