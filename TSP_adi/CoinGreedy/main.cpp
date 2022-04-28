#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <bits/stdc++.h>
#define t 10000
#include <ctime>
using namespace std;
using namespace std :: chrono;
int main()
{
    int n,value, Amount;
    cout << "Enter the Amount: ";
    cin>>Amount;
    cout << "Enter the number of coins: ";
    cin>>n;
    array<int,2> data[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter value of coin "<<(i+1)<<" :";
        cin>>value;
        data[i][1] = i+1;
        data[i][0] = value;
    }
    sort(data,data+n);
    reverse(data,data+n);
    int exgf=Amount;
    int total=0;
    int Ncoin=0;
    for(int i=0;i<n;i++)
    {
        int num = exgf/data[i][0];
        if(num > 0)
        {
            total = total + num * data[i][0];
            Ncoin = Ncoin + 1 * num;
            exgf = exgf - num * data[i][0];
        }
    }
    cout<<"Total No. of coins required : "<<Ncoin<<endl;
    return 0;
}
/*Output
Enter the Amount: 29
Enter the number of coins: 4
Enter value of coin 1 :1
Enter value of coin 2 :2
Enter value of coin 3 :5
Enter value of coin 4 :10
Total No. of coins required : 5
*/
