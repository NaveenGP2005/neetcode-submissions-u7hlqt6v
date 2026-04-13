class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int i = 0, j = 0, size = arr.size();
        if (size == 0 || k == 0) return {};
        vector<int> ans(size - k + 1);
        deque<int> dq;
        while (j < size) {
            while (!dq.empty() && dq.back() < arr[j]) {
                dq.pop_back();
            }
            dq.push_back(arr[j]);
            if (j - i + 1 < k) {
                j++;
            } else if (j - i + 1 == k) {    // <-- changed to else if
                ans[i] = dq.front();
                if (!dq.empty() && dq.front() == arr[i]) dq.pop_front();
                i++;
                j++;
            }
        }
        return ans;
    }
};
