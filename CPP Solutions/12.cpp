class Solution {
public:
    string intToRoman(int num) {
        char* table[4][9] = {{"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"M", "MM", "MMM"}};
        string result = "";
        if (num / 1000) {
            result += table[3][num / 1000 - 1];
        }
        if (num / 100 % 10) {
            result += table[2][num / 100 % 10 - 1];
        }
        if (num / 10 % 10) {
            result += table[1][num / 10 % 10 - 1];
        }
        if (num % 10) {
            result += table[0][num % 10 - 1];
        }
        return result;
    }
};
