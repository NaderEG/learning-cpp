using std::tolower;
using std::isalnum;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length();

        while (i < j) {
            if(!isalnum(s[i])) {
                i++;
            } else if(!isalnum(s[j])) {
                j--;
            } else {
                if (tolower(s[i]) != tolower(s[j]) ) {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
};
