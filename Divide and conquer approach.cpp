#include<iostream>
#include<vector>
using namespace std;
void read_matrix(vector<vector<int> >&mat, int n)
{
    int i, j, ele;
    cout<<"Enter "<<n*n<<" elements of the matrix: "<< endl;
    for(i=0; i<n; i++)
    {
        vector<int> row; for(j=0; j<n; j++)
        {
            cin>>ele;
            row.push_back (ele);
        }
        mat.push_back (row);
    }
}
void print_matrix(vector<vector<int> > mat)
{
    int n=mat.size(), i, j;
    cout<<"\nOutput Matrix: "<<endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            cout<<mat [i][j]<<" ";
        cout << "\n";
    }
}

void RecurSqrMatrixMul(vector<vector<int>> &mat1, vector<vector<int>> &mat2, vector<vector<int>> &mat3,
                       int top1, int left1, int top2, int left2, int size)
{
    if (size==1)
    {
        mat3 [top1] [left2] += mat1[top1] [left1] * mat2[top2][left2];
    }
    else
    {
        RecurSqrMatrixMul(mat1, mat2, mat3, top1, left1, top2, left2, size/2);
        RecurSqrMatrixMul(mat1, mat2, mat3, top1, left1+size/2, top2+size /2,left2, size/2);
        RecurSqrMatrixMul(mat1,mat2,mat3, top1,left1, top2, left2+size/2,size/2);
        RecurSqrMatrixMul(mat1, mat2, mat3, top1,left1+size/2, top2+size/2,left2+size/2, size/2);
        RecurSqrMatrixMul(mat1, mat2, mat3, top1+size/2,left1, top2, left2, size/2);
        RecurSqrMatrixMul (mat1, mat2, mat3, top1+size/2,left1+size/2, top2+size/2,left2, size/2);
        RecurSqrMatrixMul (mat1, mat2, mat3, top1+size/2,left1, top2, left2+size/2,size/2);
        RecurSqrMatrixMul (mat1, mat2,mat3, top1+size/2,left1+size/2, top2+size/2,left2+size/2, size/2);
    }
}

int main()
{
    vector<vector<int> > mat1,mat2;
    int i, j, n;
    cout<<"\nEnter the size of matrix: ";
    cin>>n;
    read_matrix(mat1,n);
    read_matrix(mat2, n);
    vector< vector<int> > mat3(n, vector<int>(n, 0));
    RecurSqrMatrixMul(mat1,mat2, mat3,0,0,0,0,n);
    print_matrix(mat3);
}
