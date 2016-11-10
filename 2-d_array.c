#include<stdio.h>
#include<stdlib.h>

void main(){
    int *a,p,q,choice,temp,m,n,i,j;
    printf("Enter the array size");
    scanf("%d%d",&p,&q);

    a=(int *)calloc(p*q,sizeof(int));

    printf("Enter the array elements\n");
    for(i=0;i<p;i++){
        for(j=0;j<q;j++){
            scanf("%d",(a+i*q+j));
        }
    }
    printf("The array is:\n");
     for(i=0;i<p;i++){
        for(j=0;j<q;j++){
            printf("%d\t",*(a+i*q+j));
        }printf("\n");
    }


    printf("Enter:\n1. Swap column\n2. Swap Row");
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter the column to be swapped");
        scanf("%d%d",&m,&n);
        for(i=0;i<p;i++){
            temp=*(a+i*q+(m-1));
            *(a+i*q+(m-1))=*(a+i*q+(n-1));
            *(a+i*q+(n-1))=temp;
        }
    }
    else{
        printf("Enter the column to be swapped");
        scanf("%d%d",&m,&n);
        for(j=0;j<q;j++){
            temp=*(a+j+q*(m-1));
            *(a+j+q*(m-1))=*(a+j+q*(n-1));
            *(a+j+q*(n-1))=temp;
        }
    }
    for(i=0;i<p;i++){
        for(j=0;j<q;j++){
            printf("%d\t",*(a+i*q+j));
        }printf("\n");
    }
}
