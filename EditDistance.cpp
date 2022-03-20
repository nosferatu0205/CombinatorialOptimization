#include<bits/stdc++.h>
using namespace std;

#define ncDIAGONAL -1
#define UP -3
#define DIAGONAL -2
#define LEFT -4
int idx[100][100];


int editDistance(string str1, string str2, int m, int n){
    int i, j;
    int c[100][100];

    for(i=0; i<=m; i++){
        for(j=0; j<=n; j++){
            if(i==0){
                c[i][j] = j;
                idx[i][j] = LEFT;
            }
            else if(j==0){
                c[i][j] = i;
                idx[i][j] = UP;
            }
            else if(str1[i-1]==str2[j-1]){
                c[i][j] = c[i-1][j-1];
                idx[i][j] = ncDIAGONAL;
            }
            else{
                if(c[i-1][j-1]<=c[i-1][j] && c[i-1][j-1]<=c[i][j-1]){
                    c[i][j]=1+c[i-1][j-1];
                    idx[i][j]=DIAGONAL; //indices replaced
                 }

                 else if(c[i-1][j]<=c[i-1][j-1] && c[i-1][j]<=c[i][j-1]){
                    c[i][j]=1+c[i-1][j];
                    idx[i][j]=UP; //indices deleted
                 }
                 else if(c[i][j-1]<=c[i-1][j] && c[i][j-1]<=c[i-1][j-1]){
                    c[i][j]=1+c[i][j-1];
                    idx[i][j]=LEFT; //indices inserted
                 }
            }
        }
    }
    return c[m][n];
}

void printPath(string str1, string str2, int i, int j){
        if(i==0 && j==0){
        return;
        }
        else if(idx[i][j]==ncDIAGONAL){
            printPath(str1, str2, i-1, j-1);
            cout<<endl;
            cout<<"No change "<<str1[i-1];

        }

        else if(idx[i][j]==DIAGONAL){
            printPath(str1, str2, i-1, j-1);
            cout<<endl;
            cout<<"replace "<<str1[i-1]<<" with "<<str2[j-1];
        }
        else if(idx[i][j]==UP){
            printPath(str1, str2, i-1, j);
            cout<<endl;
            cout<<"delete "<<str1[i-1];

        }
        else if(idx[i][j]==LEFT){
            printPath(str1, str2, i, j-1);
            cout<<endl;
            cout<<"insert "<<str2[j-1];
        }
}

int main(){
    string str1, str2;
    cin>>str1>>str2;
    int i = str1.length();
    int j = str2.length();
    int idx[100][100];
    int c = editDistance(str1, str2, i, j);
    cout<<c<<endl;
    printPath(str1, str2, i, j);
    return 0;
}

