class Solution {
public:
    bool isAlphabet(char ch)
    {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
    }

    bool isNum(char ch)
    {
        return (ch >= '0' && ch <= '9');
    }

    bool isAlphaNumeric(char ch)
    {
        return isAlphabet(ch) || isNum(ch);
    }

    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while(left < right)
        {
            if(!isAlphaNumeric(s[left]))
            {
                left ++;
                continue;
            }

            if(!isAlphaNumeric(s[right]))
            {
                right --;
                continue;
            }

            if(tolower(s[left]) != tolower(s[right]))
                return false;
            right --;
            left ++;
        }
        return true;
    }
};
