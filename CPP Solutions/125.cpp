class Solution {
public:
    bool isPalindrome(string s) {
        stringstream ss;
        for (char ch: s) {
            if ('0' <= ch && ch <= '9') {
                ss << (char)ch;
            }
            else if ('a' <= ch && ch <= 'z') {
                ss << (char)ch;
            }
            else if ('A' <= ch && ch <= 'Z') {
                ss << (char)(ch + ('a' - 'A'));
            }
        }
        
        string str = ss.str();
        int len = str.size();
        for (int i = 0; i < len / 2; i++) {
            if (str[i] != str[len - i - 1]) return false;
        }
        return true;
    }
};