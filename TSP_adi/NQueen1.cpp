#include<bits/stdc++.h>

using namespace std;

bool is_safe(vector<vector<int>> &arr,int x,int y,int n)
{

    for(int row=0;row<x;row++)
    {
        if(arr[row][y])
        {
            return 0;
        }
    }
    int row=x;
    int col=y;
    //Left upper Column
    while(row>=0 && col>=0)
    {
        if(arr[row][col])
        {
            return 0;
        }
        row--;
        col--;

    }
    row=x;
    col=y;
    //Right upper Column
    while(row>=0 && col<n)
    {
        if(arr[row][col])
        {
            return 0;
        }
        row--;
        col++;

    }

    return 1;
}

bool Nqueen(vector<vector<int>> &arr,int x,int n)
{

    if(x>=n)
        return 1;

    for(int col=0; col<n; col++)
    {
        if(is_safe(arr,x,col,n))
        {
            arr[x][col]=1;
            if(Nqueen(arr,x+1,n))
            {
                return true;

            }

            arr[x][col]=0;
        }

    }

   return 0;
}

int main()
{

    vector<vector<int>> arr;
    cout<<"\nEnter the Size of Matrix :";
    int n;
    cin>>n;
    vector<int> temp;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            temp.push_back(0);
        }
        arr.push_back(temp);
    }
    /*
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    cout<<"\n\nResult :\n\n";
    if(Nqueen(arr,0,n))
    {

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }



}
