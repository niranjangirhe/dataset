#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> pietable(string pattern)
{
    int s = pattern.size();
    vector<int> pie(s,0);

    for(int i=1;i<s;i++)
    {
        int j = pie[i-1];
        while(j>0 && pattern[i]!=pattern[j])
        {
            j=pie[j-1];
        }
        if(pattern[i]==pattern[j])
        {
           j++;
        }
        pie[i]=j;

    }
    return pie;

}

int main()
{
    string pattern ="abcdbcd";
    vector<int> table = pietable(pattern);
    string text = "abcdbcddcabadcbabcdbcd";

    int i=0,j=0,pos=-1;
    while(i<text.size())
    {
        if(pattern[j]==text[i])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=table[j-1];
            }
            else
                i++;
        }
        if(j==pattern.size())
        {
            cout<<i-pattern.size();
            j=0;
        }
    }


}
