#include<bits/stdc++.h>

using namespace std;

int max1 =0;
int min1 =9999;

int getsmaller(int a,int b)
{
    if(a<b)
    {
        return a;
    }
    return b;
}
int getbigger(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}

minmax(int arr[],int s,int e)
{
    int mid = s+(e-s)/2;
    if(e-s>2)
    {
    minmax(arr,s,mid);
    minmax(arr,mid,e);
    }
    else
    {
        if((e-s)==1)
        {
        max1 = max(max1,arr[s]);
        min1 = min(min1,arr[s]);
        }
        else
        {
             max1 = max(max1,getbigger(arr[s],arr[s+1]));
             min1 = min(min1,getsmaller(arr[s],arr[s+1]));
        }

    }


}

int main()
{
    int arr[10]={5,7,9,3,1,2,6,8,4};
    minmax(arr,0,9);
    cout<<max1<<min1;




}
