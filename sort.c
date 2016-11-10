#include<stdio.h>
#include<stdlib.h>

void main(){
    int *a,n,i,j,temp;
    printf("Enter the size of the array");
    scanf("%d",&n);
    a = (int *)malloc(n*sizeof(int));
    printf("Enter the elements");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j+1]<a[j]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }

}

