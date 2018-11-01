#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_set>

enum class Cell
{
    kPath = 0,
    kStart,
    kEnd,
    kObstacle,
    kVisited,
    kCurrent,
};

std::vector<std::string> kRepresentation
{
    // Black
    "  ",
    // Blue
    "\033[48;5;19m  \033[0m",
    // Green
    "\033[48;5;46m  \033[0m",
    // Red
    "\033[48;5;160m  \033[0m",
    // Yellow
    "\033[48;5;43m  \033[0m",
    // Light Yellow
    "\033[48;5;103m  \033[0m",
};

struct pairHash {
    inline std::size_t operator()(const std::pair<int, int>& p) const {
        return p.first * 31 + p.second;
    }
};

std::vector<std::pair<size_t, size_t>> getAllPositions(size_t width, size_t height)
{
    std::vector<std::pair<size_t, size_t>> positions;
    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            positions.emplace_back(i, j);
        }
    }
    return positions;
}

std::vector<std::vector<Cell>> createMaze(size_t width,
                                         size_t height,
                                         size_t obstacles_number)
{
    std::vector<std::vector<Cell>> maze;
    maze.resize(height);
    for (auto& row : maze)
    {
        row.resize(width);
    }
    maze[0][0] = Cell::kStart;
    maze[width - 1][height - 1] = Cell::kEnd;
    auto positions = getAllPositions(width, height);
    obstacles_number  = std::min(obstacles_number, width * height);
    size_t obstacles_count = 0;
    while (obstacles_count < obstacles_number)
    {
        size_t random_index = rand() % positions.size();
        auto& random_position = positions[random_index];
        if (random_position != std::pair<size_t, size_t>{0, 0} &&
            random_position != std::pair<size_t, size_t>{width - 1, height - 1})
        {
            maze[random_position.first][random_position.second] = Cell::kObstacle;
        }
        std::swap(random_position, positions.back());
        positions.pop_back();
        ++obstacles_count;
    }
    return maze;
}

void print(const std::vector<std::vector<Cell>>& maze)
{
    for (const auto& row : maze)
    {
        for (const auto cell : row)
        {
            std::cout << kRepresentation[static_cast<size_t>(cell)];
        }
        std::cout << std::endl;
    }
}

int main(int argc, char* args[])
{
    if (argc < 4)
    {
        std::cout << "Usage: maze_diagonal_bfs <width> <height> <obstacles>"
                  << std::endl;
        return 0;
    }
    std::vector<std::vector<Cell>> maze =
        createMaze(atoi(args[1]), atoi(args[2]), atoi(args[3]));
    print(maze);
    return 0;
}
