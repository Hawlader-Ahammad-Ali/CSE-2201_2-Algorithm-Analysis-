
#include<bits/stdc++.h>
using namespace std;

int crossingSum(vector<int>& a, int low, int mid, int high)
{
    int sum = 0;
    int leftMax = INT_MIN;

    for(int i = mid; i >= low; i--)
    {
        sum += a[i];
        leftMax = max(leftMax, sum);
    }

    sum = 0;
    int rightMax = INT_MIN;

    for(int i = mid+1; i <= high; i++)
    {
        sum += a[i];
        rightMax = max(rightMax, sum);
    }

    return leftMax + rightMax;
}

int maxSubarray(vector<int>& a, int low, int high)
{
    if(low == high)
        return a[low];

    int mid = (low + high) / 2;

    int leftSum = maxSubarray(a, low, mid);

    int rightSum = maxSubarray(a, mid+1, high);

    int crossSum = crossingSum(a, low, mid, high);

    return max({leftSum, rightSum, crossSum});
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << maxSubarray(a, 0, n-1);
}
