class MedianFinder {
public:
    priority_queue<int> maxQ; // smaller half
    priority_queue<int, vector<int>, greater<int>> minQ; // larger half
    MedianFinder() {
    }
    void addNum(int num) {
        maxQ.push(num);
        minQ.push(maxQ.top());
        maxQ.pop();
        if (minQ.size() > maxQ.size()) {
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }
    double findMedian() {
        if (maxQ.size() > minQ.size()) {
            return maxQ.top();
        }
        return (maxQ.top() + minQ.top()) / 2.0;
    }
};