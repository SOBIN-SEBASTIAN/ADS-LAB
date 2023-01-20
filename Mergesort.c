#include<stdio.h>
void main()
{
    int a[20],b[20],i,j,n1,n2,n3,t1,t2,k;
    printf("enter the number of elements in array1 ");
    scanf("%d",&n1);
    printf("enter the elements in 1st array \n");
    for(i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the number of elements in array2 ");
    scanf("%d",&n2);
    printf("enter the elements in 2nd array \n");
     for(j=0;j<n2;j++)
    {
        scanf("%d",&b[j]);
    }
    printf("\n array 1:-\n");//for display array 1
    for(i=0;i<n1;i++)
    {
        printf("%d",a[i]);
    }

    printf("\n array 2:-\n");//for display array 2
    for(j=0;j<n2;j++)
    {
        printf("%d \t",b[j]);
    }
    t1=0;
    for(i=0;i<n1-1;i++)
    {
        for(j=i+1;j<n1;j++)
        {
        if (a[i]>a[j])
        {
          t1=a[i];
          a[i]=a[j];
          a[j]=t1;
        }
        }
    }
    printf("\n array after sorting 1:-\n");//for printing array1 after sorting
    for(i=0;i<n1;i++)
    {
        printf("\n%d \t ",a[i]);
    }
     t2=0;
     for(i=0;i<n2-1;i++)
        {
    for(j=i+1;j<n2;j++)
    {
        if (b[i]>b[j])
        {
          t2=b[i];
          b[i]=b[j];
          b[j]=t2;
        }
    }
        }
     printf("\n array 2 after sorting:-\n");//for printing array 2 after sorting
    for(j=0;j<n2;j++)
    {
        printf("\n%d\t",b[j]);
    }
    n3=n1+n2;
    k=n1;
    for(i=0;i<n3;i++)
    {
        a[k]=b[i];
        k++;

    }
    printf("\n merged array is:-\n");
    for(i=0;i<n3;i++)
    {
        printf("\n %d \t",a[i]);
    }

}
