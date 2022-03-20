#include<bits/stdc++.h>
using namespace std;
#define DIAGONAL -1
#define LEFT -3
#define UP -2
int arrow[100][100];

int LCSlength(string str1, string str2 , int  m , int n){
int i,j;

int c[100][100];

for(i=0;i<=m;i++){
    c[i][0]=0;
    }

    for(j=0;j<=n;j++){
    c[0][j]=0;
    }

for(i=1;i<=m;i++){
    for(j=1;j<=n;j++)
    {
        if(str1[i-1]==str2[j-1]){

            c[i][j]=(c[i-1][j-1])+1;
            arrow[i][j]=DIAGONAL;
        }

        else{
            if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                arrow[i][j]=UP;
            }

            else{
                c[i][j]=c[i][j-1];
                arrow[i][j]=LEFT;
            }
        }
    }
}

return c[m][n] ;
}

void lcsPrint(int arrow[100][100] , string str1 , int i , int j){
    if(i==0 || j==0){
        return;
    }

    if(arrow[i][j]==DIAGONAL){
        lcsPrint(arrow,str1,i-1,j-1);
        cout<<str1[i-1];
    }
    else if(arrow[i][j]==UP){
         lcsPrint(arrow,str1,i-1,j);

    }
    else{
         lcsPrint(arrow,str1,i,j-1);
    }
}



int main(){
    string str1, str2;
    cin>>str1>>str2;
    int m = str1.length();
    int n = str2.length();
    
    int len = LCSlength(str1, str2, m, n);
    cout<<len<<endl;

    lcsPrint(arrow, str1, m, n);
}