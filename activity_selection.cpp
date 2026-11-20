#include<bits/stdc++.h>
using namespace std;

void activitySelection(vector<pair<int, int>>&activities, vector<int>&profit, int n)
{
   
    sort(activities.begin(), activities.end());

    cout << "Selected activities: ";
    int lastFinishTime = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if(activities[i].second >= lastFinishTime)
        {
            cout << "(" << activities[i].second << ", " << activities[i].first << ") ";
            mx += profit[i];
            lastFinishTime = activities[i].first;
        }
    }
    cout << "Maximum profit: " << mx << endl;
}
int main()
{
   int n ;
   cin >> n;
   vector<pair<int, int>> activities;
   vector<int>profit(n);
   for(int i = 0; i < n; i++)
   {
      cin >> activities[i].first >> activities[i].second;
      cin >> profit[i];
   }
    activitySelection(activities, profit, n);
    return 0;
}