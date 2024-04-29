// Given a string str, the task is to find the longest substring which is a palindrome.

// Examples:

// Input: str = “forgeeksskeegfor” 
// Output: “geeksskeeg”

#include <bits/stdc++.h>

using namespace std;

string longestPalindromicSubstr(string str)
{
    int n = str.size();
    int start_idx = 0;
    int max_len = 1;

    for(int i = 1; i < n; i++) {
        int l = i - 1;
        int r = i;

        while(l >= 0 && r < n && str[l] == str[r]) {
            l--;
            r++;
        }

        l++;
        r--;

        int len = r - l + 1;
        if(len > max_len) {
            start_idx = l;
            max_len = len;
        }

        l = i - 1;
        r = i + 1;

        while(l >= 0 && r < n && str[l] == str[r]) {
            l--;
            r++;
        }

        l++;
        r--;

        len = r - l + 1;
        if(len > max_len) {
            start_idx = l;
            max_len = len;
        }
    }

    return str.substr(start_idx, max_len);
}

string longestPalindromicSubstrDP(string str)
{
    int n = str.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int start_idx = 0;
    int max_len = 1;

    for (int i = 0; i < n; i++)
        dp[i][i] = true;

    for (int l = 2; l <= n; l++)
    {
        for (int i = 0; i + l <= n; i++)
        {
            int j = i + l - 1;

            if (str[i] == str[j])
            {
                if (l == 2)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }

                if (dp[i][j] && l > max_len)
                {
                    max_len = l;
                    start_idx = i;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return str.substr(start_idx, max_len);
}

int main()
{
    string str;
    cin >> str;
    string res = longestPalindromicSubstr(str);
    cout << "Without DP : " << res << endl;
    
    res = longestPalindromicSubstrDP(str);
    cout << "With DP : " << res << endl;
}