#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

vector<vector<int>> A_i_j(vector<vector<int>> matrix, int row, int column);
int determinant(vector<vector<int>> matrix);
vector<double> isss;
int temp;
int main()
{

    fstream fst{"mydata3.txt"};
    vector<int> dets;
    int n, num;
    while (fst >> n)
    {
        vector<vector<int>> mat;
        for (int i = 0; i < n; i++)
        {
            mat.push_back(vector<int>());
            for (int j = 0; j < n; j++)
            {
                fst >> num;
                mat[i].push_back(num);
            }
        }
        temp = determinant(mat);
        cout << temp << endl;
        dets.push_back(temp);
    }
    for (int i = 1; i < 4; i++)
    {
        cout << "i" << i << " = " << setprecision(2) << double(dets[i]) / double(dets[0]) << endl;
        isss.push_back(double(dets[i]) / double(dets[0]));
    }
    cout << 10 * ((double(dets[1]) / double(dets[0])) - (double(dets[3]) / double(dets[0])));
    return 0;
}

int determinant(vector<vector<int>> matrix)
{
    int deter = 0;
    if (matrix.size() == 1)
        return matrix[0][0];
    if (matrix.size() == 2)
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    for (int index_c = 0; index_c < matrix[0].size(); index_c++)
        deter += (pow(-1, index_c) * matrix[0][index_c] * determinant(A_i_j(matrix, 0, index_c)));
    return deter;
}

vector<vector<int>> A_i_j(vector<vector<int>> matrix, int row, int column)
{
    matrix.erase(matrix.begin() + row);
    for (int i = 0; i < matrix.size(); i++)
        matrix[i].erase(matrix[i].begin() + column);
    return matrix;
}