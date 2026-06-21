class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) {
            freq[c - 'A']++;
        }
        priority_queue<int> pq;
        for (int f : freq) {
            if (f > 0) pq.push(f);
        }
        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;
            int cycle = n + 1;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    int curr = pq.top();
                    pq.pop();
                    curr--;
                    if (curr > 0) {
                        temp.push_back(curr);
                    }
                }
                time++;
                if (pq.empty() && temp.empty()) {
                    break;
                }
            }
            for (int t : temp) {
                pq.push(t);
            }
        }
        return time;
    }
};