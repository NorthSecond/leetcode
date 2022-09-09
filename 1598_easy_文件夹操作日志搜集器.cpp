/*
 * @lc app=leetcode.cn id=1598 lang=cpp
 *
 * [1598] 文件夹操作日志搜集器
 */

#define VSCODE

#ifdef VSCODE
#include <bits/stdc++.h>
using namespace std;
#endif // !VSCODE

// @lc code=start
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (auto& log : logs) {
            if (log == "../") {
                ans = max(0, ans - 1);
            } else if (log == "./") {
                continue;
            } else {
                ans++;
            }
        }
    }
};
// @lc code=end

