#include<bits/stdc++.h>

using namespace std;

void st_match(string text,string pattern)
{
    int n = text.length();
    int m = pattern.length();

    for(int i=0;i<=n-m;i++)
    {
        int count=0,j=0;
        for(j=0;j<m;j++)
        {
            if(text[i+j]!=pattern[j])
            {
                break;
            }
        }
        if(j==m)
        {
            cout<<"\nIndex found at "<<i;
        }

    }

}

int main()
{
   string text = "AABAACAADAABAABA";
   string pattern = "AABA";

   st_match(text,pattern);

}
