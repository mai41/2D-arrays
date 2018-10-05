#include <iostream>

using namespace std;

//structure to store a matrix
struct matrix
{
    int** data;     //pointer to 2D array that will simulate matrix
    int row, col;
};

// Takes an array of data and stores in matrix according
// to rows and columns
matrix createMatrix(int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int* [row];

    for (int i = 0; i < row; i++)
        mat.data[i] = new int [col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = num[i * col + j];
}

//input the data for matrix
istream& operator>> (istream& in, matrix& mat){
        cout << "Enter no. of rows: ";
        in >> mat.row;
        cout << "Enter no. of columns: ";
        in >> mat.col;
        cout << "Enter element of the matrix: " << endl;
        for (int i = 0;i < mat.row ; i++){
        for (int j = 0;j < mat.col;j++){
                in >> mat.data[i][j];

        }
                }
        return in;

}

//printing out a matrix
ostream& operator<< (ostream& out, matrix mat)
{
    int r = mat.row;
    int c = mat.col;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            out << mat.data[i][j] << "     ";
        }
        out << endl;
    }
    return out;
}

//student no.1
//summation of two matrices
//it takes the two matrices that the summation will occur bet them and return a new matrix
matrix operator+  (matrix mat1, matrix mat2)
{
    matrix matr;
    int r = mat1.row;
    int c = mat1.col;
    int x = 0;
    int *ptr;
    ptr = new int [c * r];
    if(mat1.col == mat2.col && mat1.row == mat2.row)
    {
        int r = mat1.row;
        int c = mat1.col;

        for(int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                ptr[x] = mat1.data[i][j] + mat2.data[i][j];
                x++;
            }
        }
        createMatrix(r,c,ptr,matr);
        cout << "The sum of 2 matrices is: " << endl;
        return matr;
    }
}

//subtraction of two matrices
//it takes the two matrices that the subtraction will occur bet them and return a new matrix
matrix operator-  (matrix mat1, matrix mat2)
{
    matrix matr;
    int r = mat1.row;
    int c = mat1.col;
    int x = 0;
    int *ptr;
    ptr = new int [c * r];

    if(mat1.col == mat2.col && mat1.row == mat2.row)
    {
        for(int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                ptr[x] = mat1.data[i][j] - mat2.data[i][j];
                x++;
            }
        }

        createMatrix(r,c,ptr,matr);
        cout << "The sub of 2 matrices is: " << endl;
        return matr;
    }
}

//multiplication of two matrices
//it takes the two matrices that the multiplication will occur bet them and return a new matrix
matrix operator*  (matrix mat1, matrix mat2)
{
    matrix matr;
    int r = mat1.row;
    int c = mat2.col;
    int x = 0;
    int *ptr;
    ptr = new int [c * r];
    if(mat1.col == mat2.row)
    {

        for (int i = 0; i < r; i++)
        {
            for(int k = 0; k < c; k++)
            {
                ptr[x] = 0;
                for (int j = 0; j < c; j++)
                {
                    ptr[x] = ptr[x] + (mat1.data[i][j] * mat2.data[k][i]);

                }
                x++;
            }
        }

    }
    createMatrix(r,r,ptr,matr);
    cout << "The multiplication of 2 matrices: " << endl;
    return matr;
}

//addition a constant to a matrix
//it takes a matrix and an integer that will be added to the matrix and return a new matrix
matrix operator+  (matrix mat1, int scalar)
{
    matrix matr;
    int r = mat1.row;
    int c = mat1.col;
    int x = 0;
    int *ptr;
    ptr = new int [c * r];
    for(int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ptr[x] = mat1.data[i][j] + scalar;
            x++;
        }
    }
    createMatrix(r,c,ptr,matr);
    cout << "after adding the scalar to matrix: " << endl;
    return matr;
}

//subtraction a constant to a matrix
//it takes a matrix and an integer that will be subtracted from the matrix and return a new matrix
matrix operator-  (matrix mat1, int scalar)
{
    matrix matr;
    int r = mat1.row;
    int c = mat1.col;
    int x = 0;
    int *ptr;
    ptr = new int [c * r];
    for(int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ptr[x] = mat1.data[i][j] - scalar;
            x++;
        }
    }
    createMatrix(r,c,ptr,matr);
    cout << "After subbing a scalar from matrix: " << endl;
    return matr;
}

//multiplication a constant to a matrix
//it takes a matrix and an integer that will be multiplied to the matrix and return a new matrix
matrix operator*  (matrix mat1, int scalar)
{
    matrix matr;
    int r = mat1.row;
    int c = mat1.col;
    int x = 0;
    int *ptr;
    ptr = new int [c * r];
    for(int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            ptr[x] = mat1.data[i][j] * scalar;
            x++;
        }
    }
    createMatrix(r,c,ptr,matr);
    cout << "matrix multiple by a scalar: " << endl;
    return matr;
}

//student no.2
// mat1 changes & return new matrix with the summation
matrix operator+= (matrix& mat1, matrix mat2){
    for (int i = 0; i < mat1.row ; i++){
        for (int j = 0; j < mat1.col; j++){
            mat1.data[i][j] += mat2.data[i][j];
        }
    }
    cout << "The new mat1 is: " << endl;
    return mat1;
}

// mat1 changes + returns new matrix with difference
matrix operator-= (matrix& mat1, matrix mat2)
{
    for (int i = 0; i < mat1.row ; i++){
        for (int j = 0; j < mat1.col; j++){
            mat1.data[i][j] -= mat2.data[i][j];
        }
    }
    cout << "The new mat1 is: " << endl;
    return mat1;
}

//mat changes and returns new matrix + scalar
matrix operator+= (matrix& mat, int scalar)
{
    for (int i = 0;i < mat.row ; i++){
        for (int j = 0;j < mat.col; j++){
            mat.data[i][j] += scalar;
        }
    }
    cout << "The same matrix after adding a scalar is: " << endl;
    return mat;
}

//mat changes and returns new matrix - scalar
matrix operator-= (matrix& mat, int scalar)
{
    for (int i = 0;i < mat.row ; i++){
        for (int j = 0;j < mat.col; j++){
            mat.data[i][j] -= scalar;
        }
    }
    cout << "The same matrix after subbing a scalar is: " << endl;
    return mat;
}

// Add 1 to each element in mat
void   operator++ (matrix& mat)
{
    for (int i = 0;i < mat.row ; i++){
        for (int j = 0;j < mat.col; j++){
            mat.data[i][j]++;
        }
    }

}

// sub 1 from each element in mat
void   operator-- (matrix& mat)
{
    for (int i = 0;i < mat.row ; i++){
        for (int j = 0;j < mat.col; j++){
            mat.data[i][j]--;
        }
}
}

//student no.3
//returns true if 2 matrices are the same
bool   operator== (matrix mat1, matrix mat2)
{
    if ((mat1.row == mat2.row) && (mat1.col == mat2.col))
    {
        for(int i = 0; i < mat1.row; i++)
        {
            for(int j = 0; j < mat1.col; j++)
            {
                if(mat1.data[i][j] != mat2.data[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}

//returns true if 2 matrices are not the same
bool   operator!= (matrix mat1, matrix mat2)
{
    if ((mat1.row == mat2.row) && (mat1.col == mat2.col))
    {
        for(int i = 0; i < mat1.row; i++)
        {
            for(int j = 0; j < mat1.col; j++)
            {
                if(mat1.data[i][j] != mat2.data[i][j])
                {
                    return false;
                }
            }
        }
        return false;
    }
    else
        return true;
}

//returns true if matrix is square
bool   isSquare   (matrix mat3)
{
    if(mat3.row == mat3.col)
    {
        return true;
    }
    else
        return false;
}

//returns true if matrix is square and symmetric
bool   isSymetric (matrix mat)
{
    if(mat.row == mat.col)               //make sure that matrix is square
    {
        for(int i = 0; i < mat.row; i++)     //make sure that matrix is symmetric
            for(int j = 0; j < mat.col; j++)
                if(mat.data[i][j] != mat.data[j][i])
                    return false;
        return true;
    }
    else
        return false;
}

//returns true if matrix is square and identity
bool   isIdentity (matrix mat3)
{
    bool check;
    if(mat3.row == mat3.col)                 //make sure that matrix is square
    {
        for(int i = 0; i < mat3.row; i++)   //make sure that matrix is identity
        {
            for(int j = 0; j < mat3.col; j++)
            {
                if(i == j)
                {
                    if(mat3.data[i][j] == 1)
                    {
                        check = true;
                    }
                    else
                        return false;
                }
                else
                {
                    if(mat3.data[i][j] == 0)
                    {
                        check = true;
                    }
                    else
                        return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}

//returns new matrix with the transpose
matrix transpose (matrix mat3)
{
    matrix newMat;
    int newRow = mat3.row;
    int newCol = mat3.col;
    int x = 0;
    int *ptr;      //pointer to data in the matrix with the transposed
    ptr = new int [newCol * newRow];
    for (int i = 0; i < newRow; i++)
    {
        for (int j = 0; j < newCol; j++)
        {
            ptr[x] = mat3.data[i][j];
            x++;
        }
    }
    createMatrix (newCol,newRow,ptr,newMat);   //creating the transpose of the matrix
    cout << "The transpose of matrix is: " << endl;
    return newMat;
}

int main()
{
    int data1 [] = {10,100,10,100,10,100,10,100};
    int data2 [] = {13,23,33,41,35,67};
    int data3 [] = {1,0,0,0,1,0,0,0,1};
    int data4 [] = {1,2,4,2,3,5,4,5,5};

    matrix mat1 = createMatrix(4, 2, data1, mat1);   //creating matrix no.1
    matrix mat2 = createMatrix(2, 3, data2, mat2);   //creating matrix no.2
    matrix mat3 = createMatrix(3, 3, data3, mat3);   //creating matrix no.3
    matrix mat4 = createMatrix(3, 3, data4, mat4);   //creating matrix no.4

    cin >> mat1; //input data for matrix 1

    cout << "matrix no.1 is: " << endl << mat1 << endl;
    cout << "matrix no.2 is: " << endl << mat2 << endl;
    cout << "matrix no.3 is: " << endl << mat3 << endl;
    cout << "matrix no.4 is: " << endl << mat4 << endl;

    cout << "The boolean of 2 matrices to be identical= ";
    cout << (mat1==mat3) << endl;
    cout << "The boolean of 2 matrices to be not identical= ";
    cout << (mat1!=mat3) << endl;
    cout << "The boolean of a matrix to be symmetric= ";
    cout << isSymetric (mat4) << endl;
    cout << "The boolean of a matrix to be square= ";
    cout << isSquare (mat4) << endl;
    cout << "The boolean of a matrix to be identity= ";
    cout << isIdentity (mat3) << endl;
    cout << endl;

    cout << (mat3+mat4) << endl;
    cout << (mat4-mat3) << endl;
    cout << (mat3*mat4) << endl;
    cout << (mat3+3) << endl;
    cout << (mat4-2) << endl;
    cout << (mat3*4) << endl;

    cout << transpose (mat1) << endl;

    cout << (mat3+=mat4) << endl;
    cout << (mat3-=mat4) << endl;
    cout << (mat3+=3) << endl;
    cout << (mat4-=2) << endl;
    ++mat2;
    cout << "The ++matrix is: " << endl;
    cout << (mat2) << endl;
    --mat1;
    cout << "The --matrix is: " << endl;
    cout << (mat1) << endl;








    return 0;
}
