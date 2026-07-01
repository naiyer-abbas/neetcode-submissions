class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> um;
        for(auto &e: s)
        {
            um[e] ++;
        }

        for(auto &e: t)
        {
            um[e] --;
        }

        for(auto &e: um)
        {
            if(e.second != 0)
                return false;
        }
        return true;
    }
};
