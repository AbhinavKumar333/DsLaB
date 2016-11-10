#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int binary(int l,int u,int key,int a[]){
	int m,c;
	c = 0;
		m=(l+u)/2;
		if(key == a[m]){	c=1; 	}

		else if(key < a[m]){	return (binary(l,m-1,key,a));	}

		else{	return (binary(m+1,u,key,a));	}

	return (c);
}

void main(){
	int s,l,u,key,c,i;int n[100];

	printf("Enter the numbers of elements to be searched");
	scanf("%d",&c);
	printf("Enter the elements");
	for(i=0;i<c;i++){
		scanf("%d",&n[i]);
	}

	u = c-1;
	l = 0;

	printf("Enter the element to be searched");
	scanf("%d",&key);

	s = binary(l,u,key,n);
	if(s == 1) {	printf("Number found");		}
	else if(s ==0) {	printf("Number not found");	}


}
