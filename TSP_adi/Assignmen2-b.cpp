// C++ implementation of worst case linear time algorithm
// to find k'th smallest element
#include<iostream>
#include<algorithm>
#include<climits>
#include<chrono>
using namespace std::chrono;

using namespace std;

int partition(int arr[], int l, int r, int k);
int findMedian(int arr[],int s,int n);

int findMedian(int arr1[],int s,int n)
{
    n=n+s;
 for(int i=s+1; i<=n; i++)          //Insertion sort to sort the array
    {
        int c=arr1[i];
        int j=i-1;
        while(j>=s && arr1[j]>c)
        {
            arr1[j+1]=arr1[j];
            j--;
        }
        arr1[j+1]=c;
    }


    return arr1[(s+n)/2];
}

int medianofmedian(int arr[], int l, int r, int k)
{

	if (k > 0 && k <= r - l + 1)
	{
		int n = r-l+1;


		int i, median[(n+4)/5];
		for (i=0; i<n/5; i++)
			median[i] = findMedian(arr,5*i,4);
		if (i*5 < n)
		{
			median[i] = findMedian(arr,5*i,n%5-1);
			i++;
		}


		int medOfMed = (i == 1)? median[i-1]:
								medianofmedian(median, 0, i-1, i/2);


		int pos = partition(arr, l, r, medOfMed);

		if (pos-l == k-1)
			return arr[pos];
		if (pos-l > k-1)
			return medianofmedian(arr, l, pos-1, k);


		return medianofmedian(arr, pos+1, r, k-pos+l-1);
	}
	return INT_MAX;

}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swap1(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r, int x)
{

	int i;
	for (i=l; i<r; i++)
		if (arr[i] == x)
		break;
	swap(&arr[i], &arr[r]);


	i = l;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}
 int partition(int arr[], int low, int high)
{

    // pivot
    int pivot = arr[high];


    int i = (low - 1);

    for(int j = low; j <= high - 1; j++)
    {


        if (arr[j] < pivot)
        {
            i++;
            swap1(arr, i, j);
        }
    }
    swap1(arr, i + 1, high);
    return (i + 1);
}


void main_quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        main_quickSort(arr, low, pi - 1);
        main_quickSort(arr, pi + 1, high);
    }
}
void quickSort(int arr[], int s, int n){
   if (s < n)
   {
      int h = n-s+1;
      int medofmed = medianofmedian(arr, s, n, h/2);
      int pos = partition(arr, s, n, medofmed);
      quickSort(arr, s, pos - 1);
      quickSort(arr, pos + 1, n);
    }
}
int main()
{
    cout<<"Enter the Number of Elements :";
    int n;cin>>n;
    int arr[n];
    int arr1[n];
    for(int i=0; i<n; i++)
    {
            arr[i]= rand()%10000+ 1;
            arr1[i]=arr[i];
    }
    auto start = high_resolution_clock::now();
    quickSort(arr,0,n);
    auto stop = high_resolution_clock::now();
    auto duration1 = duration_cast < microseconds > (stop - start);
      cout << "\n\nTime taken By Median of Median Algo: " << (duration1.count()) << " microseconds" << endl;
    auto start1 = high_resolution_clock::now();
    main_quickSort(arr1,0,n);
    auto stop1 = high_resolution_clock::now();
    auto duration2 = duration_cast < microseconds > (stop1 - start1);
      cout << "\n\nTime taken By Quick_sort : " << (duration2.count()) << " microseconds" << endl;



}

