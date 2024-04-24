    #include<stdio.h>
    #include<string.h>

    void lcslength(char x[], char y[]) 
    {
        int m, n;
        m = strlen(x);
        n = strlen(y);
        int b[m][n], c[m + 1][n + 1];
        for (int i = 0; i <= m; i++) 
        {
            c[i][0] = 0;
        }
        for (int j = 1; j <= n; j++) 
        {
            c[0][j] = 0;
        }

        for (int i = 1; i <= m; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if (x[i - 1] == y[j - 1]) 
                {
                    c[i][j] = c[i - 1][j - 1] + 1;
                    b[i][j] = 3;
                } 
                else if(c[i - 1][j] >= c[i][j - 1]) 
                {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = 1;
                } 
                else 
                {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = 2;
                }
            }
        }
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
                printf("%d ", c[i][j]);
            printf("\n");
        }

        printf("Length of lcs is %d\n", c[m][n]);

        int lcsLength = c[m][n];
        char lcs[lcsLength + 1];
        lcs[lcsLength] = '\0';
        int i = m, j = n, index = lcsLength - 1;
        while (i > 0 && j > 0) {
            if (b[i][j] == 3) {
                lcs[index] = x[i - 1];
                i--;
                j--;
                index--;
            } else if (b[i][j] == 1) {
                i--;
            } else {
                j--;
            }
        }

        printf("LCS string is: %s\n", lcs);
    }

    void main()
    {
        char x[100], y[100];
        printf("Enter 1st string\n");
        gets(x);
        printf("Enter 2nd String\n");
        gets(y);
        lcslength(x, y);
    }