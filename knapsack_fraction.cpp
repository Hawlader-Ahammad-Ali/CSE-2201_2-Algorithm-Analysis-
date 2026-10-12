#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const double tol = 1e-5;
struct tupple{
    int weight;
    int value ;
    double vpw;
};

bool compare(tupple a , tupple b){
    return (a.vpw  > b.vpw);
}
double Knapsack(vector<tupple>&knap , int n , double w)
{
   sort(knap.begin(),knap.end() , compare);
   double ans = 0;
   for(int i = 0 ; i < n ; i++)
   {
       if( !(w-knap[i].weight  < 0 ))
       {
           ans += knap[i].value;
           w -= knap[i].weight;
       }
       else
       {

           ans+= (w * knap[i].vpw);

           break;
       }
   }
    return ans;
}
int main()
{
   int n ;
   double w ;
   cin >> n >> w;
   vector<tupple>knap(n);
   for(int i = 0 ; i < n ; i++)
   {
       cin >> knap[i].weight ;
   }
    for(int i = 0 ; i < n ; i++)
   {
       cin >> knap[i].value;
       knap[i].vpw =  (knap[i].value)  /(knap[i].weight);
   }
   cout << "Maximum profit = " << Knapsack(knap , n ,w) << endl;
}
