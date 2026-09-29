class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if (intervals.empty()) {
        intervals.push_back(std::move(newInterval));
        return intervals;
    }
    const auto s{newInterval[0]};
    const auto e{newInterval[1]};

    if (e < intervals.front()[0]) {
        intervals.insert(intervals.begin(), std::move(newInterval));
        return intervals;
    } else if (s > intervals.back()[1]) {
        intervals.push_back(std::move(newInterval));
        return intervals;
    }

    const auto p{std::ranges::lower_bound(intervals, s, {},
                                          [](auto &a) { return a[1]; })};
    const auto nop{p == intervals.end()};
    const auto l{nop ? s : std::min(s, (*p)[0])};
    const auto q{std::ranges::upper_bound(intervals, e, {},
                                          [](auto &a) { return a[0]; })};
    const auto r{std::max(e, (*(q-1))[1])};
    intervals.insert(intervals.erase(nop ? intervals.begin() : p, q), std::vector{l, r});

    return std::move(intervals);
    }
};
