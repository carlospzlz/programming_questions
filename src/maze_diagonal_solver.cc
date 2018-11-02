#include <unistd.h>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

enum class Cell
{
    kPath = 0,
    kStart,
    kEnd,
    kObstacle,
    kVisited,
    kCurrent,
};

std::vector<std::string> kRepresentation{
    // Black
    "  ",
    // Blue
    "\033[48;5;19m  \033[0m",
    // Green
    "\033[48;5;46m  \033[0m",
    // Red
    "\033[48;5;160m  \033[0m",
    // Yellow
    "\033[48;5;240m  \033[0m",
    // Light Yellow
    "\033[48;5;11m  \033[0m",
};

struct pairHash
{
    inline std::size_t operator()(const std::pair<int, int>& p) const
    {
        return p.first * 31 + p.second;
    }
};

std::vector<std::pair<size_t, size_t>> getAllPositions(size_t width,
                                                       size_t height)
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

std::vector<std::vector<Cell>> createMaze(size_t width, size_t height,
                                          size_t obstacles_number)
{
    std::vector<std::vector<Cell>> maze;
    maze.resize(height);
    for (auto& row : maze)
    {
        row.resize(width);
    }
    maze[0][0] = Cell::kStart;
    maze[height - 1][width - 1] = Cell::kEnd;
    auto positions = getAllPositions(width, height);
    obstacles_number = std::min(obstacles_number, width * height);
    size_t obstacles_count = 0;
    while (obstacles_count < obstacles_number)
    {
        srand(time(NULL));
        size_t random_index = rand() % positions.size();
        auto& random_position = positions[random_index];
        if (random_position != std::pair<size_t, size_t>{0, 0} &&
            random_position != std::pair<size_t, size_t>{width - 1, height - 1})
        {
            maze[random_position.first][random_position.second] =
                Cell::kObstacle;
        }
        std::swap(random_position, positions.back());
        positions.pop_back();
        ++obstacles_count;
    }
    return maze;
}

void print(const std::vector<std::vector<Cell>>& maze)
{
    static size_t count = 0;
    system("clear");
    for (const auto& row : maze)
    {
        for (const auto cell : row)
        {
            std::cout << kRepresentation[static_cast<size_t>(cell)];
        }
        std::cout << std::endl;
    }
    std::cout << "Iterations: " << ++count << std::endl;
    std::cout.flush();
    usleep(1E5);
}

bool dfs_rec(size_t i, size_t j, std::vector<std::vector<Cell>>& maze)
{
    if (maze[i][j] == Cell::kEnd)
    {
        return true;
    }
    maze[i][j] = Cell::kCurrent;
    print(maze);
    maze[i][j] = Cell::kVisited;
    if (j < (maze[0].size() - 1))
    {
        auto& cell = maze[i][j + 1];
        if (cell != Cell::kVisited && cell != Cell::kObstacle)
        {
            if (dfs_rec(i, j + 1, maze))
            {
                return true;
            }
        }
    }
    if (i < (maze.size() - 1))
    {
        auto& cell = maze[i + 1][j];
        if (cell != Cell::kVisited && cell != Cell::kObstacle)
        {
            if (dfs_rec(i + 1, j, maze))
            {
                return true;
            }
        }
    }
    return false;
}

void dfs(std::vector<std::vector<Cell>>& maze)
{
    dfs_rec(0, 0, maze);
}

void bfs(std::vector<std::vector<Cell>>& maze)
{
    std::queue<std::pair<size_t, size_t>> positions_to_process;
    positions_to_process.push({0, 0});
    while (!positions_to_process.empty())
    {
        auto& position = positions_to_process.front();
        auto i = position.first;
        auto j = position.second;
        positions_to_process.pop();
        if (maze[i][j] == Cell::kEnd)
        {
            return;
        }
        maze[i][j] = Cell::kCurrent;
        print(maze);
        maze[i][j] = Cell::kVisited;
        if (j < (maze[0].size() - 1))
        {
            auto& cell = maze[i][j + 1];
            if (cell != Cell::kVisited && cell != Cell::kObstacle)
            {
                positions_to_process.push(std::pair<size_t, size_t>(i, j + 1));
                maze[i][j + 1] = Cell::kVisited;
            }
        }
        if (i < (maze.size() - 1))
        {
            auto& cell = maze[i + 1][j];
            if (cell != Cell::kVisited && cell != Cell::kObstacle)
            {
                positions_to_process.push(std::pair<size_t, size_t>(i + 1, j));
                maze[i + 1][j] = Cell::kVisited;
            }
        }
    }
}

int main(int argc, char* args[])
{
    if (argc < 5)
    {
        std::cout
            << "Usage: maze_diagonal_bfs <width> <height> <obstacles> <dfs|bfs>"
            << std::endl;
        return 0;
    }
    auto width = atoi(args[1]);
    auto height = atoi(args[2]);
    assert(width > 0 && height > 0);
    auto obstacles = atoi(args[3]);
    std::vector<std::vector<Cell>> maze = createMaze(width, height, obstacles);
    if (strcmp(args[4], "dfs") == 0)
    {
        dfs(maze);
    }
    else if (strcmp(args[4], "bfs") == 0)
    {
        bfs(maze);
    }
    else
    {
        std::cout << args[4] << "?" << std::endl;
    }
    return 0;
}
