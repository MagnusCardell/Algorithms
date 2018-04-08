#include <iostream>

using namespace std;

void print_it(int arr[], int n){
    for(int i=0; i<n; ++i){
        cout<<arr[i]<<", ";
    }
    cout<<endl;

}

/* Heapsort on an array
    - First, build a max heap
    - Now, swap the root with last element and decrease the size.
        - continue the swapping until you end up with the next largest item as the root.

    Time complexity: 
    - Sequencial heap actions called, where each 'root' is compared to its left and right child to swap appropriately 
    - Build heap compares n/2 elements, with each element in its branch, so equal to its length, log n --> (n/2)log n
    - The sorting action compares the root with each child, swapping necessarily with each child the length of the tree log n. 
        this action is called on every element in the tree --> n log n
    - TOTAL TIME: (n/2)log n + n log n = n log n

*/
void build_heap(int arr[], int n, int i)
{
    int largest = i; //root
    int l = 2*i + 1; //left child
    int r = 2*i + 2; //right child
 
    // If left child is larger than root, replace largest (swap)
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest, replace
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root, swap root with largest
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // Recursively build_heap the affected sub-tree
        build_heap(arr, n, largest);
    }
}
 

void heapsort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){
        build_heap(arr, n, i);
        //print_it(arr, n);
    }
    //Assert that a complete binary tree is stored in arr (not sorted)

    for (int i=n-1; i>=0; i--) //move from the end to the beginning
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max build_heap on the reduced heap
        build_heap(arr, i, 0);
        //print_it(arr, n);
    }
}

int main(){
    int arr[] = {3,6,1,6,8,4,3,2,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"unsorted array"<<endl;
    print_it(arr, n);

    heapsort(arr,n);

    cout<<"sorted array"<<endl;
    print_it(arr, n);
    return 0;
}