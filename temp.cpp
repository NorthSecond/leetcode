// 脚手架测试代码

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define debug(x) std::cout<<x<<std::endl

int main(void){
    unordered_map<int, size_t> mp;
    debug(mp.size());
    mp[1] ++;
    debug(mp.size());
    mp[1]--;
    if(!mp[1]){
        mp.erase(1);
    }
    debug(mp.size());
}