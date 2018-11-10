#include "rotate_matrix.h"
#include "gtest/gtest.h"

TEST(RotateMatrix, SquareMatrix)
{
    std::vector<std::vector<int>> matrix =
    {{1, 2, 3},
     {4, 5, 6},
     {7, 8, 9}};
    std::vector<std::vector<int>> expected =
    {{7, 4, 1},
     {8, 5, 2},
     {9, 6, 3}};
    auto result = rotateMatrix(matrix);
    EXPECT_EQ(result, expected);
}

TEST(RotateMatrix, SingleRow)
{
    std::vector<std::vector<int>> matrix =
    {{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    std::vector<std::vector<int>> expected =
    {{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}};
    auto result = rotateMatrix(matrix);
    EXPECT_EQ(result, expected);
}

TEST(RotateMatrix, SingleColumn)
{
    std::vector<std::vector<int>> matrix =
    {{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}};
    std::vector<std::vector<int>> expected =
    {{9, 8, 7, 6, 5, 4, 3, 2, 1}};
    auto result = rotateMatrix(matrix);
    EXPECT_EQ(result, expected);
}

TEST(RotateMatrixInPlace, SquareMatrix3x3)
{
    std::vector<std::vector<int>> matrix =
    {{1, 2, 3},
     {4, 5, 6},
     {7, 8, 9}};
    std::vector<std::vector<int>> expected =
    {{7, 4, 1},
     {8, 5, 2},
     {9, 6, 3}};
    rotateMatrixInPlace(matrix);
    EXPECT_EQ(matrix, expected);
}

TEST(RotateMatrixInPlace, SquareMatrix5x5)
{
    std::vector<std::vector<int>> matrix =
    {{1,   2,  3,  4,  5},
     {6,   7,  8,  9, 10},
     {11, 12, 13, 14, 15},
     {16, 17, 18, 19, 20},
     {21, 22, 23, 24, 25}};
    std::vector<std::vector<int>> expected =
    {{21, 16,  11, 6,  1},
     {22, 17,  12, 7,  2},
     {23, 18,  13, 8,  3},
     {24, 19,  14, 9,  4},
     {25, 20,  15, 10, 5}};
    rotateMatrixInPlace(matrix);
    EXPECT_EQ(matrix, expected);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
