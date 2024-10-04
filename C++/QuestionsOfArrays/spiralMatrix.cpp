#include<iostream>
using namespace std;
void spiralMatrix(int mat[][4], int n, int m){
    int srow = 0, scol = 0;
    int erow = n-1, ecol = m-1;
    while(srow<=erow && scol<=ecol){
//top
for(int j=scol; j<=ecol; j++){
    cout<<mat[srow][j]<<" ";
}
//right
for(int j=srow+1; j<=erow; j++){
    cout<<mat[j][ecol]<<" ";
}
//bottom
for(int j=ecol-1; j>=scol; j--){
    if(srow==erow){
        break;
    }
    cout<<mat[erow][j]<<" ";
}
//left
for(int j=erow-1; j>= srow+1; j--){
    if(scol==ecol){
        break;
    }
    cout<<mat[j][scol]<<" ";
}
srow++;
scol++;
erow--;
ecol--;
    }

}
int main(){
int matrix[4][4] = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
};
spiralMatrix(matrix, 4, 4);
return 0;
}