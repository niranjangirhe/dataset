#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int amt;
	cout<<"Enter Total Amount that you want change of : ";
	cin>>amt;
	amt++;
	cout<<"Enter total number of denomination (coins) : ";
	cin>>n;
	n++;
	int a[n][amt]={0};
	int c[n];
	c[0]=0;
	int cu[n][amt][amt];
	memset(cu, 0, sizeof cu);

	for(int i=1;i<n;i++)
	{
	    cout<<"Enter \""<<i<<"\" denomination value : ";
		cin>>c[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<amt;j++)
		{
			if(i==0 || j==0)
			{
				a[i][j]=0;
			}
			else if(c[i]>j)
			{
				a[i][j]=a[i-1][j];

				for(int l=0;l<amt;l++)
				{
					cu[i][j][l]=cu[i-1][j][l];
				}

			}
			else
			{
				if(a[i-1][j]<1+a[i][j-c[i]])
				{
					a[i][j]=a[i-1][j];
					for(int l=0;l<amt;l++)
					{
						cu[i][j][l]=cu[i-1][j][l];
					}
				}
				else
				{
					a[i][j]=1+a[i][j-c[i]];
					for(int l=0;l<amt;l++)
					{
						cu[i][j][l]=cu[i][j-c[i]][l];
					}
					for(int l=0;l<amt;l++)
					{
						if(cu[i][j][l]==0)
						{
							cu[i][j][l]=c[i];
							break;
						}
					}
				}
			}

			if(i==1)
			{
				a[1][j]=j;
				for(int k=0;k<amt;k++)
				{
					cu[1][j][k]=k<j?1:0;
					//cout<<cu[i][j][k];
				}
				//cout<<endl;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<amt;j++)
		{
			cout<<a[i][j]<<" ";
			if(a[i][j]<100)
				cout<<" ";
			if(a[i][j]<10)
				cout<<" ";
		}
		cout<<endl;
	}
	//cout<<"n"<<n;
	cout<<"Coin/s that can be used: ";
	for(int j=0;j<amt;j++)
	{
		if(cu[n-1][amt-1][j]!=0)
			cout<<cu[n-1][amt-1][j]<<" ";
	}
	return 0;
}


/*Output
Enter Total Amount that you want change of : 29
Enter total number of denomination (coins) : 4
Enter "1" denomination value : 1
Enter "2" denomination value : 2
Enter "3" denomination value : 5
Enter "4" denomination value : 10
0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29
0   1   1   2   2   3   3   4   4   5   5   6   6   7   7   8   8   9   9   10  10  11  11  12  12  13  13  14  14  15
0   1   1   2   2   1   2   2   3   3   2   3   3   4   4   3   4   4   5   5   4   5   5   6   6   5   6   6   7   7
0   1   1   2   2   1   2   2   3   3   1   2   2   3   3   2   3   3   4   4   2   3   3   4   4   3   4   4   5   5
Coin/s that can be used: 2 2 5 10 10
*/
