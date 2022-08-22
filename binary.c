#include<stdio.h>
int main(){
    int a[]={1,2,3,4,5,6,7};
    int mid, low=0, high=(sizeof(a)/sizeof(*a))-1;
    int pos=-1;
    int found=0;
    int key=6;

    while(low<=high && found==0){
        mid=(low+high)/2;
        // printf("%d %d %d", low,high, mid);
        // printf(" %d\n",a[mid]);
        if (a[mid]==key){
            printf("%d found at index %d", key, mid);
            found=1;
        }
        else if(a[mid]>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
       
    }
}

//RECURSION:
// binarySearch(arr, x, low, high)
//        if low > high
//            return False 

//        else
//            mid = (low + high) / 2 
//                if x == arr[mid]
//                return mid
    
//            else if x > arr[mid]        // x is on the right side
//                return binarySearch(arr, x, mid + 1, high)
            
//            else                        // x is on the right side
//                return binarySearch(arr, x, low, mid - 1) 