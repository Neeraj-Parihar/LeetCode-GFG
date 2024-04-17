#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int n = s.length();

        // Skip trailing spaces
        int i = n - 1;
        while (i >= 0 && s[i] == ' ')
            i--;

        // Count characters until space or beginning of string
        while (i >= 0 && s[i] != ' ') {
            ans++;
            i--;
        }

        return ans;
    }
};