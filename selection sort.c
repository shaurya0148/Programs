#include<stdio.h>
int main(){
    int a[]={3,6,1,7,4,2}
    int n=sizeof(a)/sizeof(*a);
    printf("before sortinf: ")
    for(int p=0; p<n; p++){
        printf("%d", a[p]);
    }
}