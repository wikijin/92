//#include <iostream>
//
//using namespace std;
//
//void insert_sort(int *arr,int n)
//{
//    int i,j;
//    for(i = 1 ; i < n ; ++i)
//    {
//        int tmp = arr[i];
//        j = i - 1;
//        while( j >= 0 && arr[j] > tmp)
//        {
//            arr[j+1] = arr[j];
//            j--;
//        }
//        arr[j+1]  = tmp;
//    }
//}
//
//int main()
//{
//    int arr[] = {8,7,6,5,4,3,2,1,0};
//    insert_sort(arr,9);
//    for(int i = 0  ; i < 9 ; ++i)
//    {
//        cout<<arr[i]<<" ";
//    }
//    cout<<endl;
//    return 0;
//}

#include <iostream>

using namespace std;

void merge_sort(int *arr,int start,int end,int *temp)
{
    if(end > start+1)
    {
        int mid = start + (end - start) / 2;
        merge_sort(arr,start,mid,temp);
        merge_sort(arr,mid,end,temp);
        int i = start , j = mid , k = start;
        while(i < mid || j < end)
        {
            if(j >= end || (i < mid && arr[i] <= arr[j]))
            {
                temp[k++] = arr[i++];
            }
            else
            {
                temp[k++] = arr[j++];
            }
        }
        for(i = start ; i < end ; ++i)
        {
            arr[i] = temp[i];
        }
    }
}


int main()
{
    int temp[8];
    int arr[]  = {8,7,6,5,4,3,2,1};
    merge_sort(arr,0,8,temp);
    for(int i = 0 ; i < 8 ; ++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
