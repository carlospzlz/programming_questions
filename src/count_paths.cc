#include <iostream>
#include <vector>

void drawMatrix(int i, int j, const std::vector<std::vector<int>>& M)
{
  system("clear");
  for (int k = 0; k < M.size(); ++k)
  {
    for (int l = 0; l < M[0].size(); ++l)
    {
      if (i == k && j == l)
      {
        std::cout << "\033[37;41m " << M[k][l] << " \033[0m ";
      }
      else
      {
        std::cout << "\033[37m " << M[k][l] << " \033[0m ";
      }
    }
    std::cout << std::endl;
  }
}

int main()
{
  std::vector<std::vector<int>> M = {
    {1, 1, 0, 0},
    {1, 1, 0, 0},
    {1, 1, 0, 0},
  };
  drawMatrix(0, 0, M);
  return 0;
}
