#include<stdio.h>
#include<string.h>

void computeLPS(char* pat[], int M, int* lps)
{
    lps[0]=0;
    int len=0;
    int i=1;

    while(i<M)
    {
        if(pat[i] == pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }

        else if(len!=0)
        {
            len = lps[len-1];
        }

        else{
            lps[i]=0;
            i++;

        }       
    }

}

void KMP(char* txt, char* pat)
{
    int M=strlen(pat);
    int N=strlen(txt);

    int lps[N];

    computeLPS(pat, M, lps);

    int i=0; 
    int j=0;

    while((N-i)>=(M-j))
    {
        if(pat[j]==txt[i])
        {
            i++;
            j++;
        }

        if(j==M)
        {
            printf("Pattern found at %d", i-j);
            j=lps[j-1];
        }

        else if(i<N && pat[j]!=txt[i])
        {
            if(j!=0)
            {
                j=lps[j-1];
            }

            else 
            {
                i=i+1;
            }
        }
    }
}