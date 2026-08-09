#include <vector>
#include <iostream>

using namespace std;

// 树状数组 (Binary Indexed Tree) 类，用于单点修改和区间求和
class FenwickTree {
private:
    int n;
    vector<int> tree;
public:
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) {
            tree[i] += delta;
        }
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }

    int queryRange(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

class Solution {
public:
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        FenwickTree bit(n);
        // is_peak[i] 记录下标 i 是否是峰值点 (1表示是，0表示不是)
        vector<int> is_peak(n, 0);
        // 检查下标 i 是否为峰值
        auto checkPeak = [&](int i) {
            if (i <= 0 || i >= n - 1) return 0;
            return (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) ? 1 : 0;
        };
        // 预处理初始数组中的所有峰值
        for (int i = 1; i < n - 1; ++i) {
            if (checkPeak(i)) {
                is_peak[i] = 1;
                bit.add(i + 1, 1); // 树状数组下标从 1 开始，所以使用 i + 1
            }
        }

        vector<long long> ans;
        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                int l = q[1];
                int r = q[2];
                // 如果区间长度小于 3，则不可能包含任何峰值子数组
                if (r - l < 2) {
                    ans.push_back(0);
                } else {
                    // 合法的峰值点只能在 [l + 1, r - 1] 之间
                    // 树状数组对应区间为 [l + 2, r]
                    ans.push_back(bit.queryRange(l + 2, r));
                }
            } else if (type == 2) {
                int idx = q[1];
                int val = q[2];
                
                // 修改值之前，先找出可能会受到影响的下标范围
                // 修改 nums[idx] 最多影响 idx-1, idx, idx+1 三个位置
                int start = max(1, idx - 1);
                int end = min(n - 2, idx + 1);

                // 1. 在树状数组中减去旧的峰值状态
                for (int i = start; i <= end; ++i) {
                    if (is_peak[i] == 1) {
                        bit.add(i + 1, -1);
                    }
                }

                // 2. 更新数组中的值
                nums[idx] = val;

                // 3. 重新计算并更新这些位置的新峰值状态
                for (int i = start; i <= end; ++i) {
                    is_peak[i] = checkPeak(i);
                    if (is_peak[i] == 1) {
                        bit.add(i + 1, 1);
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> nums ={1,3,2,4};
    vector<vector<int>> queries={{1,0,3},{2,1,1},{1,0,3}};
    Solution sol;
    vector<long long>ans = sol.countOfPeaks(nums,queries);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}