#define sz(a) (int)(a).size()

class KthLargest {
    // Idea: maintain 2 heaps, one for store the largest k elements and the other for the other n - k elements. The first heap is a min-heap, whereas the second heap is a max-heap
    priority_queue<int, vector<int>, greater<int>> top;
    priority_queue<int> rest;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) : k(k), rest(nums.begin(), nums.end()) {
        while (!rest.empty() && sz(top) < k) {
            top.push(rest.top()); rest.pop();
        }
    }
    
    int add(int val) {
        if (sz(top) < k) {
            top.push(val);
        } else {
            rest.push(val);
            if (rest.top() > top.top()) {
                top.push(rest.top());
                rest.pop();
                rest.push(top.top());
                top.pop();
            }
        }
        return top.top();
    }
};
