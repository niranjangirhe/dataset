#include<bits/stdc++.h>

using namespace std;
#define INF 9999

int coinchange(vector<int> coins,int amount)
{
    int l=coins.size();
    int dp[l+1][amount+1];

    for(int i=0;i<=l;i++)
    {
        for(int j=0;j<=amount;j++)
        {

            if(j==0)
            {
               dp[i][j]=0;
            }
            else if(i==0)
            {
                dp[i][j]=INF;
            }
            else if(j<i)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=min(1+dp[i][j-i],dp[i-1][j]);
            }
        }
    }
    if(dp[l][amount]==INF)
    {
        return -1;
    }
    else{
        return dp[l][amount];
    }
}

int main()
{
    int n;
    cout<<"\nEnter the Number of Coins:";
    cin>>n;
    vector<int> coins;
    for(int i=0;i<n;i++)
    {
        int temp;cin>>temp;
        coins.push_back(temp);
    }
    cout<<"\nEnter the Amount :";
    int amount;
    cin>>amount;

    int ans = coinchange(coins,amount);
    cout<<ans;
}
