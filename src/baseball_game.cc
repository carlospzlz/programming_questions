#include "baseball_game.h"
#include <stack>

int CalPoints1(const std::vector<std::string>& ops) {
  std::stack<int> round_points;
  for (const std::string& op : ops) {
    if (op == "+") {
      int last_round = round_points.top();
      round_points.pop();
      int points = round_points.top() + last_round;
      round_points.push(last_round);
      round_points.push(points);
    }
    else if (op == "D") {
      round_points.push(2 * round_points.top());
    }
    else if (op == "C") {
      round_points.pop();
    }
    else {
      round_points.push(stoi(op));
    }
  }
  int total_points = 0;
  while (!round_points.empty()) {
    total_points += round_points.top();
    round_points.pop();
  }
  return total_points;
}
