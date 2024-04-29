// Given a text txt[0 . . . N-1] and a pattern pat[0 . . . M-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that N > M.

// Examples:

// Input:  txt[] = “THIS IS A TEST TEXT”, pat[] = “TEST”
// Output: Pattern found at index 10

// Input:  txt[] =  “AABAACAADAABAABA”
//           pat[] =  “AABA”
// Output: Pattern found at index 0, Pattern found at index 9, Pattern found at index 12

#include <bits/stdc++.h>

using namespace std;

vector<int> calculateLPS(string str)
{
    int m = str.size();
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;
    while (i < m)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                len = 0;
                i++;
            }
        }
    }

    return lps;
}

int kmp(string str, string pattern)
{
    vector<int> lps = calculateLPS(pattern);
    cout << "LPS : ";
    for (int i : lps)
    {
        cout << i << " ";
    }
    cout << endl;

    int n = str.size();
    int m = pattern.size();

    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (str[i] == pattern[j])
        {
            i++;
            j++;
            if (j == m)
            {
                cout << "Found in idx : " << (i - j) << endl;
                j = lps[j - 1];
            }
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return -1;
}

int main()
{
    string str;
    cin >> str;

    string pattern;
    cin >> pattern;

    kmp(str, pattern);
    return 0;
}