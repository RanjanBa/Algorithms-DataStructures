#include <bits/stdc++.h>

using namespace std;

vector<int> largeToRight(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, INT_MIN);

    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty())
        {
            if (st.top() > nums[i])
            {
                res[i] = st.top();
                break;
            }
            else
            {
                st.pop();
            }
        }

        st.push(nums[i]);
    }

    return res;
}

int main()
{
    int n = 0;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    cout << "Original Array : ";
    for (int r : vec)
    {
        cout << r << " ";
    }
    cout << endl;

    vector<int> res = largeToRight(vec);

    cout << "Large to Right : ";
    for (int r : res)
    {
        cout << r << " ";
    }
    cout << endl;
}