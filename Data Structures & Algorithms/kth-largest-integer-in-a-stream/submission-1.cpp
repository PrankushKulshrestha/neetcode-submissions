class KthLargest {
private: 
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (const int& num : nums)
        {
            min_heap.push(num);
            if (min_heap.size() > k)
                min_heap.pop();
        }
    }
    int add(int val) {
        min_heap.push(val);
        if (min_heap.size() > k)
            min_heap.pop();        
        return min_heap.top();
    }
};
