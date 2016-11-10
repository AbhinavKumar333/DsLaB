#include<stdio.h>

void main(){
	int a[100],*pa,i,n,key;
	printf("Enter the size of array");
	scanf("%d",&n);
	printf("Enter array elements");	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched");
	scanf("%d",&key);
	pa = a;

	for(i=0;i<n;i++){
		if(key==*pa){
			printf("elemet found");
		}pa++;
	}	
}
	
	

