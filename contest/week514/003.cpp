#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSquareArea(vector<vector<int>>& mat) {
        int m = mat.size();
        if (m == 0) return 0;
        int n = mat[0].size();

        // 1. 构建二维前缀和数组 (大小为 (m+1) x (n+1)，初始化为 0)
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                pre[r + 1][c + 1] = mat[r][c] + pre[r][c + 1] + pre[r + 1][c] - pre[r][c];
            }
        }

        // 2. Lambda 检查函数：判断是否存在两个边长为 k 且不重叠的全 1 正方形
        auto check = [&](int k) -> bool {
            int r_min = 1e9, r_max = -1e9;
            int c_min = 1e9, c_max = -1e9;
            bool found = false;

            // 遍历所有可能的左上角坐标 (r, c)
            for (int r = 0; r <= m - k; ++r) {
                for (int c = 0; c <= n - k; ++c) {
                    // 利用前缀和在 O(1) 时间内计算当前 k x k 正方形的元素和
                    int total = pre[r + k][c + k] - pre[r][c + k] - pre[r + k][c] + pre[r][c];
                    
                    // 如果该区域内的全为 1（即元素和等于正方形面积）
                    if (total == k * k) {
                        found = true;
                        r_min = min(r_min, r);
                        r_max = max(r_max, r);
                        c_min = min(c_min, c);
                        c_max = max(c_max, c);
                    }
                }
            }

            if (!found) return false;

            // 只要最左上和最右下的正方形在行方向或列方向上的间距 >= k，即说明可以容纳两个不重叠的正方形
            return (r_max - r_min >= k) || (c_max - c_min >= k);
        };

        // 3. 二分查找最大边长 k
        int low = 1, high = min(m, n), mid;
        int max_k = 0;

        while (low <= high) {
            mid = (high + low) / 2;
            if (check(mid)) {
                max_k = mid;     // 当前边长可行，记录答案并尝试更大的边长
                low = mid + 1;
            } else {
                high = mid - 1;   // 当前边长不可行，缩小范围
            }
        }

        // 返回单个正方形的最大面积
        return max_k * max_k;
    }
};

int main()
{
    vector<vector<int>> mat={{1,1,1,0},{1,1,1,1},{0,0,1,1}};
    Solution sol;
    int ans = sol.maxSquareArea(mat);
    cout<<ans<<endl;
    return 0;
}