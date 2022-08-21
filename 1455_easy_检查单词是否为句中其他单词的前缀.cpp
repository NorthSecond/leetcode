/*
 * @lc app=leetcode.cn id=1455 lang=cpp
 *
 * [1455] 检查单词是否为句中其他单词的前缀
 */

// @lc code=start

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream ss(sentence);
        vector<string> swords;
        string tmp;
        while(ss>>tmp){
            swords.push_back(tmp);
        }

        int ans = -1;
        for (int i = 0; i < swords.size(); ++i){
            if(swords[i].find(searchWord) == 0){
                ans = i + 1;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

