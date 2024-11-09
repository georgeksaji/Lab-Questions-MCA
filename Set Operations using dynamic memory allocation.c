#include<stdio.h>
#include<stdlib.h>

void display(int n,int m,int *t1,int *t2)
{
    int i;
     printf("\nArray 1: {");
    for(i=0;i<n;i++)
    {
        printf(" %d ",*(t1+i));
    }
    printf("}");
    printf("\nArray 2: {");
    for(i=0;i<m;i++)
    {
        printf(" %d ",*(t2+i));
    }
    printf("}");
}

void set_union(int n,int m,int *t1,int *t2)
{
    int counter=m,i,j,*t3;
    int flag=0;
    t3=(int *)malloc((n+m)*sizeof(int));
    for(i=0;i<m;i++)
    {
        *(t3+i)=*(t2+i);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<counter;j++)
        {
            if(*(t3+j)==*(t1+i))
            {
                flag++;
            }
        }
        if(flag==0)
        {
            *(t3+counter)=*(t1+i);
            counter++;
        }
        flag=0;

    }
    printf("\nUnion of array elements: {");
    {
        for(i=0;i<counter;i++)
        {
            printf(" %d ",*(t3+i));
        }
        printf("}");
    }
}

void set_intersection(int n,int m,int *t1,int *t2)
{
    int counter=0,i,j,*t4;
    int flag=0;
    t4=(int *)malloc((n+m)*sizeof(int));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(*(t2+j)==*(t1+i))
            {
                flag++;
            }
        }
        if(flag!=0)
        {
            *(t4+counter)=*(t1+i);
            counter++;
        }
        flag=0;

    }
    printf("\nIntersection of array elements: {");
    {
        for(i=0;i<counter;i++)
        {
            printf(" %d ",*(t4+i));
        }
        printf("}");
    }
}
void set_difference(int n,int m,int *t1,int *t2)
{
    int choice;
    int counter=0,i,j,*t5;
    int flag=0;
    t5=(int *)malloc((n+m)*sizeof(int));
    printf("\nSelect Operation\n1.A-B\n2.B-A\n:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            printf("\nArray A - Array B: ");
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    if(*(t2+j)==*(t1+i))
                    {
                        flag++;
                    }
                }
                if(flag==0)
                {
                    *(t5+counter)=*(t1+i);
                    counter++;
                }
                flag=0;
        
            }
            break;
        }
        case 2:
        {
          printf("\nArray B - Array A: ");
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(*(t2+i)==*(t1+j))
                    {
                        flag++;
                    }
                }
                if(flag==0)
                {
                    *(t5+counter)=*(t2+i);
                    counter++;
                }
                flag=0;
        
            } 
            break;
        }
    }
        printf("\nDifference of array elements: {");
        {
            for(i=0;i<counter;i++)
            {
                printf(" %d ",*(t5+i));
            }
            printf("}");
        }
}

void process(int n,int m,int *t1,int *t2)
{
    int op;
    while(1)
    {
        printf("\nChoose the operation you want to perform:\n1.Display\n2.Union\n3.Intersection\n4.Difference\n5.Exit\n:");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            {
                display(n,m,t1,t2);
                break;
            }
            case 2:
            {
                set_union(n,m,t1,t2);
                break;
            }
            case 3:
            {
                set_intersection(n,m,t1,t2);
                break;
            }
            case 4:
            {
                set_difference(n,m,t1,t2);
                break;
            }
            case 5:
            {
                return;
            }
            default:
            {
                printf("\nInccorrect Operation");
            }
        }
    }
}

int main()
{
    int i,n,m,*t1,*t2;
    printf("Enter the size of array 1:");
    scanf("%d",&n);
    printf("Enter the size of array 2:");
    scanf("%d",&m);
    t1=(int *)malloc(n*sizeof(int));
    t2=(int *)malloc(m*sizeof(int));
    printf("\nEnter the elements to array 1: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",t1+i);
    }
    printf("\nEnter the elements to array 2: ");
    for(i=0;i<m;i++)
    {
        scanf("%d",t2+i);
    }

    int k;
    for(i=0;i<n;i++)
    {
        for(k=i+1;k<n;k++)
        {
        if(*(t1+i)==*(t1+k))
        {
            printf("Ivalid set with value repetition.");
            return 0;
        }
        }
    }
    for(i=0;i<m;i++)
    {
        for(k=i+1;k<m;k++)
        {
        if(*(t2+i)==*(t2+k))
        {
            printf("Ivalid set with value repetition.");
            return 0;
        }
        }
    }
    process(n,m,t1,t2);
    return 0;
    
}