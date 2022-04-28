#include<bits/stdc++.h>

using namespace std;

struct Item
{
    int weight,profit;

};
bool cmp(struct Item a,struct Item b)
{
    double r1 = (double)a.profit/(double)a.weight;
    double r2 = (double)b.profit/(double)b.weight;
    return r1>r2;

}
double fract_knapsack(struct Item Arr[],int W,int n)
{
    sort(Arr,Arr+n,cmp);
    for(int i=0;i<n;i++)
    {
        cout<<Arr[i].weight<<" "<<Arr[i].profit;
        cout<<endl;
    }
    int new_weight = W;
    double new_profit = 0;
        int a = rand() %
    for(int i=0;i<n;i++){

        if(Arr[i].weight <= new_weight)
        {
            new_weight=new_weight-Arr[i].weight;
            new_profit = new_profit + (double)Arr[i].profit;

        }
        else
        {
            if(new_weight>0)
            {
                new_profit += Arr[i].profit
                          * ((double)new_weight
                             / (double)Arr[i].weight);
                break;
            }
            else
            {
                break;
            }

        }

    }
    return new_profit;

}


int main()
{
    Item Arr[10];
    cout<<"Enter the Number of Objects :";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter the Profit of "<<i+1<<" Object :";
        cin>>Arr[i].profit;
        cout<<"Enter the Weight of "<<i+1<<" Object :";
        cin>>Arr[i].weight;
    }
    double profit1 = fract_knapsack(Arr,15,n);
    cout<<"\n"<<profit1;

}
