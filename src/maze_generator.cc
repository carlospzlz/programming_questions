#include <unistd.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Position
{
   public:
    Position() : x(0), y(0) {}
    Position(int x, int y) : x(x), y(y) {}
    bool operator==(const Position& other) const
    {
        return x == other.x && y == other.y;
    }
    int x;
    int y;
};

class Maze
{
   public:
    const static std::string WALL;
    const static std::string PATH;
    const static std::string START;
    const static std::string END;
    const static std::string CURRENT;

    Maze(int width, int height, const Position& start, const Position& end);
    void carve();
    void print();

   private:
    int m_width;
    int m_height;
    Position m_start;
    Position m_end;
    Position m_current;
    int m_counter;
    std::vector<std::vector<bool>> m_maze;

    void carveRec(const Position& pos);
    bool isEndReached(const Position& pos);
    std::vector<Position> getNeighbours(const Position& pos, bool carved);
};

const std::string Maze::WALL = "  ";

const std::string Maze::PATH = "\033[48;5;231m  \033[0m";

const std::string Maze::START = "\033[48;5;46m  \033[0m";

const std::string Maze::END = "\033[48;5;19m  \033[0m";

const std::string Maze::CURRENT = "\033[48;5;160m  \033[0m";

Maze::Maze(int width, int height, const Position& start, const Position& end)
    : m_width(width), m_height(height), m_start(start), m_end(end), m_counter(0)
{
    m_maze.resize(m_height);
    for (int i = 0; i < m_height; ++i)
    {
        m_maze[i].resize(m_width, false);
    }
}

void Maze::carve()
{
    m_maze[m_start.y][m_start.x] = true;
    m_current = m_start;
    carveRec(m_start);
}

void Maze::carveRec(const Position& pos)
{
    m_current = pos;
    ++m_counter;

    print();

    if (pos == m_end)
    {
        m_maze[m_end.y][m_end.x] = true;
        return;
    }

    if (getNeighbours(pos, true).size() < 2)
    {
        m_maze[pos.y][pos.x] = true;
        if (isEndReached(pos))
        {
            carveRec(m_end);
        }
        std::vector<Position> uncarved_neighbours = getNeighbours(pos, false);
        std::random_shuffle(uncarved_neighbours.begin(),
                            uncarved_neighbours.end());
        for (auto& uncarved_neighbour : uncarved_neighbours)
        {
            carveRec(uncarved_neighbour);
        }
    }
}

bool Maze::isEndReached(const Position& pos)
{
    return pos.x > m_end.x - 2 && pos.x < m_end.x + 2 && pos.y > m_end.y - 2 &&
           pos.y < m_end.y + 2;
}

std::vector<Position> Maze::getNeighbours(const Position& pos, bool carved)
{
    std::vector<Position> neighbours;
    if (pos.x > 0)
    {
        if (m_maze[pos.y][pos.x - 1] == carved)
        {
            neighbours.push_back(Position(pos.x - 1, pos.y));
        }
    }
    if (pos.x < m_width - 1)
    {
        if (m_maze[pos.y][pos.x + 1] == carved)
        {
            neighbours.push_back(Position(pos.x + 1, pos.y));
        }
    }
    if (pos.y > 0)
    {
        if (m_maze[pos.y - 1][pos.x] == carved)
        {
            neighbours.push_back(Position(pos.x, pos.y - 1));
        }
    }
    if (pos.y < m_height - 1)
    {
        if (m_maze[pos.y + 1][pos.x] == carved)
        {
            neighbours.push_back(Position(pos.x, pos.y + 1));
        }
    }
    return neighbours;
}

void Maze::print()
{
    system("clear");
    std::vector<std::vector<std::string>> maze_to_print;
    maze_to_print.resize(m_height);
    for (int i = 0; i < m_height; ++i)
    {
        maze_to_print[i].resize(m_width);
        for (int j = 0; j < m_width; ++j)
        {
            maze_to_print[i][j] = m_maze[i][j] ? PATH : WALL;
        }
    }
    maze_to_print[m_start.y][m_start.x] = START;
    maze_to_print[m_end.y][m_end.x] = END;
    maze_to_print[m_current.y][m_current.x] = CURRENT;

    for (int i = 0; i < m_height; ++i)
    {
        for (int j = 0; j < m_width; ++j)
        {
            std::cout << maze_to_print[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "Iterations: " << m_counter << std::endl;
    std::cout.flush();
    usleep(1E5);
}

int main(int argc, char* argv[])
{
    if (argc < 7)
    {
        std::cout << "Usage: maze_generator <width> <height> <start_x> "
                     "<start_y> <end_x> <end_y>"
                  << std::endl;
        return 0;
    }
    Maze my_maze(atoi(argv[1]), atoi(argv[2]),
                 Position(atoi(argv[3]), atoi(argv[4])),
                 Position(atoi(argv[5]), atoi(argv[6])));
    my_maze.carve();
    return 0;
}
