class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        // {sum, {row, col}}
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;

        // Initialize heap with first element of each row
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        vector<vector<int>> ans;

        while (!pq.empty() && ans.size() < k) {

            // Get smallest sum
            auto curr = pq.top();
            pq.pop();

            int row = curr.second.first;
            int col = curr.second.second;

            // Store actual pair
            ans.push_back({nums1[row], nums2[col]});

            // Push next element from same row
            if (col + 1 < nums2.size()) {
                pq.push({
                    nums1[row] + nums2[col + 1],
                    {row, col + 1}
                });
            }
        }

        return ans;
    }
};
