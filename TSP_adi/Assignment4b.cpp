#include <iostream>

using namespace std;

int  main()
{

    int n;
    cout<<"Enter the amount :";
    cin>>n;
    n++;
    int c;
    cout<<"Enter the max coin :";
    cin>>c;
    c++;
    int arr[c][n];
    int i=0,j=0,k=0;

    while(j<n)
    {
        if(j<n)
            arr[i][j]=0;
        if(k<c)
            arr[k][i]=0;
        j++;
        k++;
    }
    for(i=1; i<n; i++)
    {
        arr[1][i]=i;
    }




    for(i=2; i<c; i++)
    {
        for(j=1; j<n; j++)
        {
            if(i>j)
            {
                arr[i][j]=arr[i-1][j];
            }
            else
            {
                arr[i][j]=min(arr[i-1][j],1+arr[i][j-i]);
            }
        }
    }

   cout<<"\nMinimum no of Coins :"<<arr[c-1][n-1]<<endl;

}
