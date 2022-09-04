/*
 * @lc app=leetcode.cn id=1582 lang=cpp
 *
 * [1582] 二进制矩阵中的特殊位置
 */

// @lc code=start
// #define VSCODE

#ifdef VSCODE
#include <bits/stdc++.h>
using namespace std;
#endif // DEBUG

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int usint;

#define fre(x, i) for (i = 0; i < x; ++i)

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<int> r(m, 0), c(n, 0);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                r[i] += mat[i][j];
                c[j] += mat[i][j];
            }
        int res = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (r[i] == 1 && c[j] == 1 && mat[i][j])
                    ++res;
            }
        return res;
    }
};
// @lc code=end
