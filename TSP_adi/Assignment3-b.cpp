#include<iostream>

using namespace std;

int main()
{
    int S[100],F[100],n;
    cout << "Enter the size array : ";
    cin >> n;

    cout << endl << endl;

    cout << "Enter the elements in start time array : " << endl;
    for (int i = 0; i < n; i++)
    {

        cin>>S[i];
    }

    cout << endl << endl;

    cout << "Enter the elements in End time array : " << endl;
    for (int i = 0; i < n; i++)
    {

        cin>>F[i];
    }

    cout << endl << endl;


    for(int i=1;i<n;i++)                //Insertion Sort
    {
        int j=i-1;
        int c=F[i];
        int d=S[i];
        while(j>=0 && F[j]>c)
        {
            F[j+1]=F[j];
            S[j+1]=S[j];
            j--;
        }
        F[j+1]=c;
        S[j+1]=d;
    }
    cout<<"\n\nSORTING END TIME\n\n";

    cout << "Printing elements in start : ";
    for (int i = 0; i < n; i++)
    {
        cout<<S[i]<<" ";
    }

    cout << endl << endl;

    cout << "Printing elements in end : ";
    for (int i = 0; i < n; i++)
    {
        cout<<F[i]<<" ";
    }
    int count=0,min_ft=0,index=0;

    min_ft=F[0];
    count++;

    for(int i=1;i<n;i++)
    {
        if(min_ft>S[i])   //if start time is less than min Final time
        {
            count++;
        }
        else   //if start time is more than min Start time
        {
            index++;
            min_ft=F[index];        //increment min_ft value to next element in Final time array
        }

    }
    cout<<"\n\nMinimum CAB Needed : "<<count<<endl;




}
