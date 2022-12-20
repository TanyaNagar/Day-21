#include <iostream>
using namespace std;

int binary_search(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    // int mid = (start + end) / 2;  
    int mid = start + (end - start)/2;   // to prevent integer overflow we have used this formula
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] < key)
        {                    // go to the right part of the arr
            start = mid + 1; // mid se next wla element start bna diya nd end same rhega
        }
        else
        {                  // go to the left part
            end = mid - 1; // mid se pehla element end bn jaayega nd start same rhega
        }
       // mid = (start + end) / 2; // start or end are updated acco. to the conditions so we have to update mid also
       mid = start + (end - start)/2;
    }
    return -1; // if ele. is not present in arr return -1
}

int main()
{
    int odd[5] = {5, 9, 11, 67, 85}; // array should be sorted in binary search
    int even[5] = {2, 8, 16, 34, 94};
    int oddIndex = binary_search(odd, 5, 67);
    cout<<"Index of 67 is "<<oddIndex<<endl;
    int evenIndex = binary_search(even,5,16);
    cout<<"Index of 16 is "<<evenIndex<<endl;
}


// TIME COMPLEXITY --> O(log N)