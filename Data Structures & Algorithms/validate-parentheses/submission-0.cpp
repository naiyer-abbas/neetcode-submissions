class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        unordered_map <char, char> um;
        um['('] = ')';
        um['{'] = '}';
        um['['] = ']';
        for(auto &e: s)
        {
            if(e == '(' || e == '{' || e == '[')
                st.push(e);
            else
            {
                if(st.empty())
                    return false;
                if(um[st.top()] == e)
                    st.pop();
                else
                    return false;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};
