#include<bits/stdc++.h>
using namespace std;
int left(int i){return 2*i + 1;}
int right(int i){return 2*i + 2;}
void maxHeapify(int* arr, int n, int i)
{
    int lt = left(i);
    int rt = right(i);
    int biggest = i;
    if(lt<n && arr[lt]>arr[biggest])
        biggest = lt;
    if(rt<n && arr[rt]>arr[biggest])
        biggest = rt;
    if(biggest != i)
    {
        swap(arr[i], arr[biggest]);
        maxHeapify(arr, n, biggest);
    }
}
void buildHeap(int* arr, int n)
{
    for(int i=(n-2)/2 ; i>=0 ; i--)
        maxHeapify(arr, n, i);
}
void heapSort(int* arr, int n)
{
    buildHeap(arr, n);
    for(int i=n-1 ; i>=1 ; i--)
    {
        swap(arr[i], arr[0]);
        maxHeapify(arr, i, 0);
    }
}
int main()
{
    int input[10] = {-15, 115, 16, 78, -785, -999, 566, 8, 81, 400};
    heapSort(input, 10);
    for(int i=0 ; i<10 ; i++)
        cout<<input[i]<<" ";
    return 0;
}