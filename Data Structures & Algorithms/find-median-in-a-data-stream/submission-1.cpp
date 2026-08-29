#include <cmath>

class MedianFinder {
public:
    MedianFinder() {}

    void addNum(int num) {
        const int n1 = small_half.size();
        const int n2 = large_half.size();

        // Initial insert
        if (n1 == 0 && n2 == 0) {
            small_half.push(num);
            return;
        }

        // Add to correct container
        if (num > small_half.top())
            large_half.push(num);
        else 
            small_half.push(num);

        const int diff = std::abs(static_cast<int>(small_half.size()) - static_cast<int>(large_half.size()));

        if (diff > 1) {
            if (n2 > n1) {
                small_half.push(large_half.top());
                large_half.pop();
            } else {
                large_half.push(small_half.top());
                small_half.pop();
            }
        }
        
    }
    
    double findMedian() {
        const std::size_t n1 = small_half.size();
        const std::size_t n2 = large_half.size();

        if (n1 == n2) {
            // Even length
            return (small_half.top() + large_half.top()) / 2.0;
        }

        return n1 > n2 ? small_half.top() : large_half.top(); 
    }
private: 
    /*
    Keep two containres to partition the stream into containers: 
     1) Container with smaller half of numbers in stream
     2) Container with larger half of numbers in stream
    
    Rules: 
     - Containers must be balanced since the median is found at the boundary of 
    those two containers
     - Must be at least a 1 number (cardinality) difference
    */

    std::priority_queue<int> small_half; // Max heap (by default)
    std::priority_queue<
        int, 
        std::vector<int>, // Container
        std::greater<int>
    > large_half; // Min Heap
};
