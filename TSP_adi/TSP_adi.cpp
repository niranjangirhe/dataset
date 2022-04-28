#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define vch vector<char>
#define vvll vector<vector<ll>>
#define mod 1000000007

void rvec(vector<int> &arr, int n)
{
    for(int i=0;i<n;i++)
        cin>>arr[i];
}

int tsp(vector<vector<int>> &g, int index, vector<int> arr)
{
    if(arr.size()==0)
        return g[index][0];
    int ans=INT_MAX;
    for(int i=0;i<arr.size();i++)
    {
        vector<int> remaining_indices;
        for(int j=0;j<arr.size();j++)
        {
            if(i!=j)
                remaining_indices.push_back(arr[j]);
        }
        int cost=g[index][arr[i]]+tsp(g,arr[i],remaining_indices);
        if(ans>cost)
            ans=cost;
    }
    return ans;
}

int main()
{
/*
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);
*/
    int n;
    cin>>n;
   vector<vector<int>> g(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>g[i][j];
    vector<int> arr;
    for(int i=1;i<n;i++)
        arr.push_back(i);
    int ans=tsp(g,0,arr);
    cout<<ans<<endl;
}
