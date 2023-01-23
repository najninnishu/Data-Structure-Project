#include <stdio.h>
#include<stdlib.h>
int *table = NULL;
int length = 0;
void arraydemolish(int *p)
{
    if(p!=NULL)
    {
        free(p);
    }
}
void insert()
{
    int num;
    printf(" Give Integer : ");
    scanf("%d",&num);
    length++;
    if ( (table=(int*)realloc(table,length*sizeof(int)))==0)
    {
        printf("ERROR");
    }
    table[length-1]=num;
}
void display()
{
    int x;
    for(x=0; x<length; x++)
    {
        printf(" %d\n",table[x]);
    }
}
int FindNum(int num)
{
    int i;
    for(i=0; i<length; i++)
    {
        if(table[i]==num)
        {
            return(i);
        }
    }
    return(-1);
}
void SortTable()
{
    int *echo[length],*tmp,i,j;
    for(i=0; i<length; i++)
    {
        echo[i]=&table[i];
    }
    for(i=0; i<length; i++)
    {
        for(j=i+1; j<length; j++)
        {
            if(*echo[j]<*echo[i])
            {
                tmp=echo[i];
                echo[i]=echo[j];
                echo[j]=tmp;
            }
        }
    }
    for(i=0; i<length; i++)
    {
              printf("%d : %d\n",i+1,*echo[i]);

    }
}
int Delete(int num)
{
    int x;
    x=FindNum(num);
    if (x==-1)
    {
        return(-1);
    }
    else
    {
        table[x]=table[length-1];
        length--;
        table=(int*)realloc(table,length*sizeof(int));
        return(1);
    }
}

int main(int argc,char* argv[])
{
    int out,U,num;
    do
    {
        putchar('\n');
        printf("          ......................DYNAMIC TABLE.......................          \n");
        printf("            >>>>>>>>>>>>>>>>>>>>>>>LIST<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
        printf(" 1: Insert number\n");
        printf(" 2: Display table\n");
        printf(" 3: Find Number\n");
        printf(" 4: Sort table\n");
        printf(" 5: Delete number\n");
        printf(" 6: Exit\n\n");
        printf(" Choose :  ");
        scanf("%d",&U);
        switch (U)
        {
        case 1 :
        {
            printf("Insert Numbers to table\n\n");
            insert();
            break;
        }
        case 2 :
        {
            printf("Display Table\n\n");
            display();
            break;
        }

        case 3 :
        {
            printf(" Give number : ");
            scanf("%d",&num);
            printf(" The number is  : %d",num);
            out=FindNum(num);
            if(out==-1)
            {
                printf(" Not Found\n");
            }
            else
            {
                printf(" Number is at  %d\n",out+1);
            }
            break;
        }

        case 4 :
        {
            printf(" Sorted Table is : \n");
            SortTable();
            break;
        }
        case 5 :
        {
            printf(" Give number to delete : ");
            scanf("%d",&num);
            out=Delete(num);
            if(out==1)
            {
                printf("\n%d has been deleted.\n",num);
            }
            else
            {
                if(out==-1)
                {
                    printf("\n%d don't exist.\n",num);
                }
                else
                {
                    printf("\nDid not deleted %d.\n",num);
                }
            }
            break;
        }
        }
    }
    while(U!=0);
    arraydemolish(table);
    exit(0);
}

