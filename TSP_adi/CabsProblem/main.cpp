#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
void print(vector<pair<int,pair<int,int>>> time, int n)
{
    cout<<"\nPas  ST  ET\n------------------------\n";
    for(int i=0;i<n;i++)
    {
        cout<<" "<<time[i].second.second<<"   "<<time[i].second.first<<"   "<<time[i].first<<endl;
    }
}
void calCab(vector<pair<int,pair<int,int>>> time, int n)
{
    int minET_index=0;
    int cab=1;
    cout<<"\n\ncab "<<cab<<" takes passenger no "<<time[0].second.second<<endl;
    for(int i=1;i<n;i++)
    {
        //second.first == starting time
        //first == ending time
        if(time[i].second.first>=time[minET_index].first)
            minET_index++;
        else
            cab++;
        cout<<"cab "<<cab<<" takes passenger no "<<time[i].second.second<<endl;
    }
    cout<<"\n\nTotal Cab Required : "<< cab;
}
int main()
{
    int n;
    cout << "Enter Total Passengers : ";
    cin>>n;
    vector<pair<int,pair<int,int>>> time;
    for(int i=0;i<n;i++)
    {
        int st,et;
        cout<<"\n======================================\n";
        cout<<"Pas "<<i+1<<"  starting, ending time : ";
        cin>>st>>et;
        time.push_back(make_pair(et,make_pair(st,i+1)));
    }
    sort(time.begin(), time.end());
    print(time,n);
    calCab(time,n);
    return 0;
}

/*Enter Total Passengers : 5

======================================
Pas 1  starting, ending time : 2 9

======================================
Pas 2  starting, ending time : 6 8

======================================
Pas 3  starting, ending time : 4 10

======================================
Pas 4  starting, ending time : 1 4

======================================
Pas 5  starting, ending time : 8 9

Pas  ST  ET
------------------------
 4   1   4
 2   6   8
 1   2   9
 5   8   9
 3   4   10


cab 1 takes passenger no 4
cab 1 takes passenger no 2
cab 2 takes passenger no 1
cab 2 takes passenger no 5
cab 3 takes passenger no 3


Total Cab Required : 3
*/
