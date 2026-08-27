class Solution {
public:
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
    quickSelect(points, k, 0, points.size() - 1);
    return std::vector<std::vector<int>>(points.begin(), points.begin() + k);
  }

  Solution() {
    std::random_device rd;
    gen = std::mt19937(rd());
  }

private:
  std::mt19937 gen;

  int dist(const std::vector<int>& point) {
    return point[0] * point[0] + point[1] * point[1];
  }
  
  void quickSelect(std::vector<std::vector<int>>& points, int k, int low, int high) {
    if (low >= high) return;
    int pivotIndex = partition(points, low, high);
    if (pivotIndex == k) return;
    else if (pivotIndex < k) quickSelect(points, k, pivotIndex + 1, high);
    else quickSelect(points, k, low, pivotIndex - 1);
  }

  int partition(std::vector<std::vector<int>>& points, int low, int high) {
    std::uniform_int_distribution<> dis(low, high);
    int initPivotIndex = dis(gen);
    std::swap(points[initPivotIndex], points[high]);
    std::vector<int> pivot = points[high];
    int pivotDist = dist(pivot);
    int insertPos = low - 1;
    for (int i = low; i < high; i++) {
      if (dist(points[i]) <= pivotDist) {
        std::swap(points[++insertPos], points[i]);
      }
    }
    std::swap(points[++insertPos], points[high]);
    return insertPos;
  }
};
