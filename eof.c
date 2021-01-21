#include <stdio.h>

int main ()
{
    long nc, nl, nw;
    int c;

    nc=0;
    nl=0;
    nw=0;
    while((c=getchar())!=EOF)
    {
        if(c=='\n')
        {
        ++nl;
        }else if (c==' ')
        {
            ++nw;
        }else
        {
            nc++;
        }
           
    }
    
    printf("number of chars %ld \n",nc);
    printf("number of lines %ld \n",nl);
    printf("number of words %ld \n",nw);


}