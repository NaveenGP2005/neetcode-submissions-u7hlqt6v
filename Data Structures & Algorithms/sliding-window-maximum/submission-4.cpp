class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || k == 0) return {};
        vector<int> ans;
        deque<int> dq; // will store indices, nums[dq.front()] is current max

        for (int j = 0; j < n; ++j) {
            // remove indices whose values are smaller than nums[j]
            while (!dq.empty() && nums[dq.back()] < nums[j]) dq.pop_back();
            dq.push_back(j);

            // remove indices that are out of current window [j-k+1, j]
            if (!dq.empty() && dq.front() <= j - k) dq.pop_front();

            // record once we have the first full window
            if (j >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
