#include <bits/stdc++.h>

using namespace std;

vector<int> largeToLeft(vector<int> &nums)
{
    int n = nums.size();

    vector<int> res(n, INT_MIN);

    stack<int> st;

    for (int i = 0; i < n; i++)
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

    vector<int> res = largeToLeft(vec);

    cout << "Large to Left : ";
    for (int r : res)
    {
        cout << r << " ";
    }
    cout << endl;
}