#include "rotate_matrix.h"
#include <iostream>

std::vector<std::vector<int>> rotateMatrix(
    const std::vector<std::vector<int>>& matrix)
{
    std::vector<std::vector<int>> rotated_matrix;
    rotated_matrix.resize(matrix[0].size());
    for (auto& row : rotated_matrix)
    {
        row.resize(matrix.size());
    }
    // i, j -> j, num_rows - i - 1
    for (decltype(matrix.size()) i = 0; i < matrix.size(); ++i)
    {
        for (decltype(matrix.size()) j = 0; j < matrix[i].size(); ++j)
        {
            rotated_matrix[j][matrix.size() - i - 1] = matrix[i][j];
        }
    }
    return rotated_matrix;
}

void rotateMatrixInPlace(std::vector<std::vector<int>>& matrix)
{
    decltype(matrix.size()) n = matrix.size();
    for (decltype(n) i = 0; i < n - 1; ++i)
    {
        // i, j     j, n-i
        // n-j, i   n-i, n-j
        for (decltype(n) j = i; j < n - i - 1; ++j)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = tmp;
        }
    }
}
