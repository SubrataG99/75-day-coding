/*
Problem name : << Range LCM Queries >>

Given an array arr[]  and a list of queries queries[][]. Each query can be one of the following two types:
Update Query: [1, index, value] --> Update the element at position index in the array to the given value.
Range Query: [2, L, R] --> Compute and return the Least Common Multiple (LCM) of all elements in the subarray from index L to R (inclusive).
Process all queries sequentially and return a list containing the results of all Type 2 queries.
Note: All operations follow 0-based indexing.

Examples :

Input: arr[] = [2, 3, 4, 6, 8, 16], queries[][] = [[2, 0, 2], [1, 3, 8], [2, 2, 5]]
Output: [12, 16]
Explanation: The queries are processed sequentially, updating the array when required.
[2, 0, 2]: LCM of [2, 3, 4] = 12
[1, 3, 8]: array becomes [2, 3, 4, 8, 8, 16]
[2, 2, 5]: LCM of [4, 8, 8, 16] = 16

Input: arr[] = [1, 2, 3, 4],  queries[][] = [[2, 0, 3], [1, 0, 5], [2, 0, 1]]
Output: [12, 10]
Explanation: The queries are processed sequentially, updating the array when required.
[2, 0, 3]: LCM of [1, 2, 3, 4] = 12
[1, 0, 5]: array becomes [5, 2, 3, 4]
[2, 0, 1]: LCM of [5, 2] = 10
*/

// =============================================================>> Solution
class SegmentTree
{
    int n;
    vector<long long> tree;

    long long lcm_ll(long long a, long long b)
    {
        if (a == 0 || b == 0) return 0;
        return a / std::gcd(a, b) * b;
    }

    void build(int node, int start, int end, const vector<int>& arr)
    {
        if (start == end)
        {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        tree[node] = lcm_ll(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, long long val)
    {
        if (start == end)
        {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = lcm_ll(tree[2 * node], tree[2 * node + 1]);
    }

    long long query(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l) return 1; // neutral for LCM
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        long long left = query(2 * node, start, mid, l, r);
        long long right = query(2 * node + 1, mid + 1, end, l, r);
        return lcm_ll(left, right);
    }

    public:
    SegmentTree(const vector<int>& arr)
    {
        n = (int)arr.size();
        tree.assign(4 * n, 1);
        build(1, 0, n - 1, arr);
    }

    void pointUpdate(int idx, long long val)
    {
        update(1, 0, n - 1, idx, val);
    }

    long long rangeQuery(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

class Solution
{
    public:
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries)
    {
        SegmentTree st(arr);
        vector<long long> ans;
        for (auto &q : queries)
        {
            if (q[0] == 1)
            {
                int index = q[1];
                long long value = q[2];
                st.pointUpdate(index, value);
            }
            else
            {
                int L = q[1], R = q[2];
                ans.push_back(st.rangeQuery(L, R));
            }
        }
        return ans;
    }
};
