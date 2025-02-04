#include<iostream>

using namespace std;

int minCoins(int n, int a[], int dp[]) {

		if(n == 0) return 0;

		int ans = ;

		for(int i = 0; i<a.length; i++) {
			if(n-a[i] >= 0) {
				int subAns = 0;
				if(dp[n-a[i]] != -1) {
					subAns = dp[n-a[i]];
				} else {
					subAns = minCoins(n-a[i], a, dp);
				}
				if(subAns != Integer.MAX_VALUE &&
						subAns + 1 < ans) {
					ans = subAns + 1;
				}
			}
		}
		return dp[n] = ans;
	}

int main()
{
    int n = 18;
		int a[] = {7, 5, 1};

		int dp[n+1]={-1};

		dp[0] = 0;

		int ans = minCoins(n, a, dp);
		cout<<ans;

		for(int x: dp) {
			cout<<x<<" ";
		}

}
