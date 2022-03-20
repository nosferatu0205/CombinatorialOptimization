#include <bits/stdc++.h>
using namespace std;
#define DIAGONAL -1
#define LEFT -3
#define UP -2
int arrow[100][100];

int LCSlength(int str1[], int str2[], int m, int n)
{
    int i, j;

    int c[100][100];

    for (i = 0; i <= m; i++)
    {
        c[i][0] = 0;
    }

    for (j = 0; j <= n; j++)
    {
        c[0][j] = 0;
    }

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {

                c[i][j] = (c[i - 1][j - 1]) + 1;
                arrow[i][j] = DIAGONAL;
            }

            else
            {
                if (c[i - 1][j] >= c[i][j - 1])
                {
                    c[i][j] = c[i - 1][j];
                    arrow[i][j] = UP;
                }

                else
                {
                    c[i][j] = c[i][j - 1];
                    arrow[i][j] = LEFT;
                }
            }
        }
    }

    return c[m][n];
}

void lcsPrint(int str1[], int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }

    if (arrow[i][j] == DIAGONAL)
    {
        lcsPrint(str1, i - 1, j - 1);
        cout << str1[i - 1];
    }
    else if (arrow[i][j] == UP)
    {
        lcsPrint(str1, i - 1, j);
    }
    else
    {
        lcsPrint(str1, i, j - 1);
    }
}

int main()
{
    int len;
    cin >> len;
    cout << endl;
    int str1[len];
    int str2[len];
    for (int i = 0; i < len; i++)
    {
        cin >> str1[i];
    }
    for (int i = 0; i < len; i++)
    {
        str2[i] = str1[i];
    }
    sort(str2, str2 + len);

    int leng = LCSlength(str1, str2, len, len);
    cout << leng << endl;

    lcsPrint(str1, len, len);
}