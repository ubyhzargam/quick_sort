#include<iostream>
using namespace std;

int Partition(int A[],int l, int h)
{
    int s;
    int pivot=A[l];
    int i=l,j=h;
    do
    {
        do
        {i++;}while(A[i]<=pivot);
        do
        {j--;}while(A[j]>pivot);
        if(i<j)
        {
            s=A[i];
            A[i]=A[j];
            A[j]=s;
        }
    } while (i<j);
    s=A[l];
    A[l]=A[j];
    A[j]=s;
    return j;
}

void QuickSort(int A[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=Partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

void Display(int A[], int n)
{
    cout<<"The elements in sorted order are given by : "<<endl;
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
}

int main()
{
    cout<<"Enter the number of elements to be entered in the array : "<<endl;
    int n;
    cin>>n;
    int A[50];
    cout<<"Enter the elements in the array which are to be sorted : "<<endl;
    for(int i=0;i<n;i++)
        cin>>A[i];
    A[n]=INT32_MAX;
    QuickSort(A,0,n);
    Display(A,n);
    return 0;
}
