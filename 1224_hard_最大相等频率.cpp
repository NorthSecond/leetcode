/*
 * @lc app=leetcode.cn id=1224 lang=cpp
 *
 * [1224] 最大相等频率
 */

// @lc code=start

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        size_t len = nums.size();
        unordered_map<int, size_t> mp;
        for(int& i : nums){
            ++mp[i];
        }
        unordered_map<size_t, size_t> mpmp;
        for(auto& i :mp){
            mpmp[i.second]++;
        }
        for (int i = len - 1; i >= 0; --i){
            if(mpmp.size() == 1){
                if(mpmp.begin()->first == 1){
                    // 1234567
                    return i + 1;
                }else{
                    // 11111111
                    if(mp.size() == 1){
                        return i + 1;
                    }
                }
            }else if (mpmp.size() == 2)
            {
                for(auto& j : mpmp){
                    if(j.first == 1 && j.second == 1){
                        // 1112223334445
                        return i + 1;
                    }
                }
                if(abs((int)(mpmp.begin()->first - (++mpmp.begin())->first)) == 1){
                    if ((mpmp.begin()->first > (++mpmp.begin())->first && mpmp.begin()->second == 1) || (mpmp.begin()->first < (++mpmp.begin())->first && (++mpmp.begin())->second == 1)){
                        return i + 1;
                    }
                }
            }

            --mpmp[mp[nums[i]]];
            if (mpmp[mp[nums[i]]] == 0){
                mpmp.erase(mp[nums[i]]);
            }
            --mp[nums[i]];
            if(mp[nums[i]] == 0){
                mp.erase(nums[i]);
            }else{
                ++mpmp[mp[nums[i]]];
            }
        }
        return 0;
    }
};
// @lc code=end
