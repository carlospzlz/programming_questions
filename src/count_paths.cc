#include <iostream>
#include <unistd.h>
#include <vector>

void drawMatrix(std::pair<int, int> target,
                const std::vector<std::vector<int>>& M,
                int color_code) {
  system("clear");
  for (int i = 0; i < M.size(); ++i) {
    for (int j = 0; j < M[0].size(); ++j) {
      if (i == target.first && j == target.second) {
        std::cout << "\033[37;" << color_code << "m " << M[i][j] << " \033[0m ";
      } else {
        std::cout << "\033[37m " << M[i][j] << " \033[0m ";
      }
    }
    std::cout << std::endl;
  }
  usleep(.5E6);
}

void countNumberOfPathsRec(std::pair<int, int> start, std::pair<int, int> end,
                           std::vector<std::vector<int>>& M) {
  if (M[start.first][start.second] == 0){
    return;
  }
  M[start.first][start.second] = 0;
  drawMatrix(start, M, 41);
  if (start.first > 0) {
    drawMatrix({start.first - 1, start.second}, M, 44);
    M[start.first][start.second] += M[start.first - 1][start.second];
  }
  if (start.second > 0) {
    drawMatrix({start.first, start.second - 1}, M, 43);
    M[start.first][start.second] += M[start.first][start.second - 1];
  }
  drawMatrix(start, M, 42);
  if (start == end) {
    return;
  }
  if (start.first < end.first) {
    countNumberOfPathsRec({start.first + 1, start.second}, end, M);
  }
  if (start.second < end.second) {
    countNumberOfPathsRec({start.first, start.second + 1}, end, M);
  }
}

int main() {
  std::vector<std::vector<int>> M = {
      {1, 1, 1, 1, 1},
      {1, 0, 1, 0, 1},
      {1, 1, 1, 0, 1},
      {0, 0, 1, 1, 1}
  };
  countNumberOfPathsRec({1, 0}, {3, 4}, M);
  countNumberOfPathsRec({0, 1}, {3, 4}, M);
  return 0;
}
