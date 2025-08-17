class SmallestInfiniteSet {
public:
    unordered_set<int> vis;
    priority_queue<int , vector<int> , greater<int>> pq ;
    SmallestInfiniteSet() {
        for (int i = 1 ; i <= 1000 ; i++) {
            vis.insert(i);
            pq.push(i);
        }
    }

    int popSmallest() {
        int x = pq.top();
        vis.erase(x);
        pq.pop();
        return x;
    }

    void addBack(int num) {
        if(vis.find(num) == vis.end())
            pq.push(num);
        vis.insert(num);
    }
};