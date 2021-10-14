#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i,n,inverse=0,j;
    char c[3];
    printf("\nEnter number of input: - ");
    scanf("%d",&n);

    int a[n];

    printf("\nEnter input (0's and 1's) :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

//_____________________________________________________________________________________________


    printf("\nUnipolar NRZ: - \n");                                                                 //Unipolar NRZ
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            printf("   ");
        }
        if(a[i]==1)
        {
            printf("___");
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            printf("   ");
        }
        if(a[i]==0)
        {
            printf("___");
        }
    }


//____________________________________________________________________________________


    printf("\n\n");
    printf("\nPolar NRZ-L: - \n");                                                          //Polar NRZ-L
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            printf("   ");
        }
        if(a[i]==0)
        {
            printf("___");
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            printf("   ");
        }
        if(a[i]==1)
        {
            printf("___");
        }
    }


//_____________________________________________________________________________


    printf("\n\n");
    printf("\nPolar NRZ-I: - \n");                                                //Polar NRZ-I
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            inverse++;
        }
        if(inverse%2!=0)
        {
            printf("   ");
        }
        if(inverse%2==0)
        {
            printf("___");
        }
    }
    inverse=0;
    j=n+1;
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            inverse++;
        }
        if(inverse%2!=0)
        {
            j=i;
        }
        if(j==i)
        {
            printf("___");
        }
        if(j!=i)
        {
            printf("   ");
        }
    }


//_____________________________________________________________________



    printf("\n\n");
    printf("\nPolar RZ : - \n");                                           //Polar RZ
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            printf("   ");
        }
        if(a[i]==1)
        {
            printf("_  ");
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            printf("   ");
        }
        if(a[i]==1)
        {
            printf(" | ");
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            printf("   ");
        }
        if(a[i]==1)
        {
            printf(" |_");
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            printf("  _");
        }
        if(a[i]==1)
        {
            printf("   ");
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            printf(" | ");
        }
        if(a[i]==1)
        {
            printf("   ");
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            printf("_| ");
        }
        if(a[i]==1)
        {
            printf("   ");
        }
    }


//__________________________________________________________________


    printf("\n\n");
    printf("\nManchester : - \n");                                             //Manchester
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            printf("_  ");
        }
        if(a[i]==1)
        {
            printf("  _");
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" | ");
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            printf(" |_");
        }
        if(a[i]==1)
        {
            printf("_| ");
        }
    }


//______________________________________________________________________


    printf("\n\n");
    printf("\nDiff-Manchester : - \n");                                         //Diff-Manchester
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n");

    c[0]=' ';
    printf("  _");

    for(i=1;i<n;i++)
    {
        if(a[i]==0)
        {
            if(c[0]==' ')
            {
                printf("  _");
                c[0]=' ';
            }
            else
            {
                printf("_  ");
                c[0]='_';
            }
        }
        if(a[i]==1)
        {
            if(c[0]==' ')
            {
                printf("_  ");
                c[0]='_';
            }
            else
            {
                printf("  _");
                c[0]=' ';
            }
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" | ");
    }
    printf("\n");

    c[0]='_';
    printf("_| ");
    for(i=1;i<n;i++)
    {
        if(a[i]==0)
        {
            if(c[0]==' ')
            {
                printf(" |_");
                c[0]=' ';
            }
            else
            {
                printf("_| ");
                c[0]='_';
            }
        }
        else
        {
            if(c[0]==' ')
            {
                printf("_| ");
                c[0]='_';
            }
            else
            {
                printf(" |_");
                c[0]=' ';
            }
        }
    }


//_____________________________________________________


    printf("\n\n");
    printf("\nAMI : - \n");                                         //AMI
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n");
    inverse=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            printf("   ");
        }
        else if(a[i]==1)
        {
            inverse++;
            if(inverse%2!=0)
            {
                printf("___");
            }
            else
            {
                printf("   ");
            }
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            printf("___");
        }
        else
        {
            printf("   ");
        }
    }
    printf("\n");
    inverse=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            printf("   ");
        }
        else if(a[i]==1)
        {
            inverse++;
            if(inverse%2!=0)
            {
                printf("   ");
            }
            else
            {
                printf("___");
            }
        }
    }


//_________________________________________________________________________________


    printf("\n\n");
    printf("\nPseudoternary : - \n");                                                     //Pseudoternary
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n");
    inverse=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            printf("   ");
        }
        else if(a[i]==0)
        {
            inverse++;
            if(inverse%2!=0)
            {
                printf("___");
            }
            else
            {
                printf("   ");
            }
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            printf("___");
        }
        else
        {
            printf("   ");
        }
    }
    printf("\n");
    inverse=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==1)
        {
            printf("   ");
        }
        else if(a[i]==0)
        {
            inverse++;
            if(inverse%2!=0)
            {
                printf("   ");
            }
            else
            {
                printf("___");
            }
        }
    }
    printf("\n\n");
    printf("\n\nTHANK YOU___________________");
    printf("\n\n");
    printf("\n\n");

//_______________________________________________

    return 0;

}
