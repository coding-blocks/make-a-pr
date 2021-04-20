#include <iostream> 
using namespace std;
int binarySearch(int arr[], int l, int r, int x) 
{ 
    while(l <=r) { 
        int mid = (l + r) / 2; 
        if (arr[mid] == x) 
            return mid; 
  
        else if (arr[mid] > x) 
                    l=mid+1;
        else
                r=mid-1;
    } 
    return -1; 
} 
  
int main() 
{ 
    int n,x;
    cout<<"Enter soze of array followed by the elements of array";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    } 
    cout<<"Enter Element to be searched";
    cin>>x; 
    int result = binarySearch(arr, 0, n-1, x); 
    (result == -1) ? cout<<"\nElement is not present in array" 
                   : cout<<"\nElement is present at index "<<result; 
    return 0; 
