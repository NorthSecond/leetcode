/*
 * @lc app=leetcode.cn id=1460 lang=cpp
 *
 * [1460] 通过翻转子数组使两个数组相等
 */

// @lc code=start
// #include <bits/stdc++.h>
// using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp1, mp2;
        for (int& i : target){
            mp1[i]++;
        }
        for(int& i: arr){
            mp2[i]++;
        }

        for(auto& i : mp1){
            if(mp2[i.first] != i.second){
                return false;
            }
        }

        for(auto& i : mp2){
            if(mp1[i.first] != i.second){
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

