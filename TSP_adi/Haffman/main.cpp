#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
    string c;
    int freq;
    node *l=NULL, *r=NULL;
};
void iterate(node* n, map<string,string> &ans, string code)
{
    if(n->l==NULL && n->r==NULL)
    {
        ans[n->c]=code;
        return;
    }
    iterate(n->l,ans,code+"0");
    iterate(n->r,ans,code+"1");
}
int findpos(vector<node*> vec,int s)
{
    int ct=0;
    for (auto it : vec)
        {
            if(it->freq>s)
            {
                //cout<<"-->"<<ct<<endl;
                return ct;
            }

            ct++;
        }
    return vec.size();
}
int main()
{
    string word;
    cout << "Enter a string : ";
    cin>>word;
    int arr[256]={0};
    for(int i=0;i<word.size();i++)
    {
        arr[(int) word[i]]+=1;
        //cout<<arr[(int) word[i]]<<endl;
    }
    vector<pair<int,pair<int,char>>> v;
    cout<<"Char Frequency"<<endl;
    for(int i=0;i<256;i++)
    {
        if(arr[i]!=0)
        {
            v.push_back(make_pair(arr[i],make_pair(0,(char) i)));
            cout<<" "<<(char) i<<"       "<<arr[i]<<endl;
        }
    }
    sort(v.begin(),v.end());
    cout<<"\n\nAfter sorting\nFrequency char"<<endl;
    for (auto x : v)
    {
       cout<<"    "<<x.first<<"        "<<(char) x.second.second<<endl;
    }
    cout<<"\n\nTree making"<<endl;
    vector<node*> nv;

    for(int i=0;i<v.size();i++)
    {
        node* n = new node();
        n->c=(char) v[i].second.second;
        n->freq=v[i].first;
        nv.push_back(n);
    }
    int ct=0;
    cout<<"\nvector size "<<nv.size()<<endl;
    while(nv.size()>1)
    {
        cout<<"--------------\n";
        for(int q=0;q<nv.size();q++)
        {
            cout<<nv[q]->c<<"-";
        }
        cout<<"\n--------------\n";
        int freqSum=0;
        //left node
        node* n;
        n=nv[0];
        freqSum+= n->freq;
        cout<<"left "<<n->c<<" freq "<<n->freq<<"->";

        //right node
        node* n1;
        n1=nv[1];
        freqSum+= n1->freq;
        cout<<"right "<<n1->c<<" freq "<<n1->freq<<endl;

        node* n2=new node();
        n2->freq=freqSum;
        n2->c="("+n->c+n1->c+")";
        n2->l=n;
        n2->r=n1;

        nv.insert(nv.begin() + findpos(nv,n2->freq), n2);
        nv.erase(nv.begin());
        nv.erase(nv.begin());
    }
    cout<<"--------------\n";
    for(int q=0;q<nv.size();q++)
    {
        cout<<nv[q]->c<<"-";
    }
    cout<<"\n--------------\n";

    //tree iterate
    map<string,string> ans;
    iterate(nv[0],ans,"");
    for(auto x:ans)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
}
/*OUTPUT
Enter a string : aabcccdededeccacbacade
Char Frequency
 a       5
 b       2
 c       7
 d       4
 e       4


After sorting
Frequency char
    2        b
    4        d
    4        e
    5        a
    7        c


Tree making

vector size 5
--------------
b-d-e-a-c-
--------------
left b freq 2->right d freq 4
--------------
e-a-(bd)-c-
--------------
left e freq 4->right a freq 5
--------------
(bd)-c-(ea)-
--------------
left (bd) freq 6->right c freq 7
--------------
(ea)-((bd)c)-
--------------
left (ea) freq 9->right ((bd)c) freq 13
--------------
((ea)((bd)c))-
--------------
a 01
b 100
c 11
d 101
e 00
*/
