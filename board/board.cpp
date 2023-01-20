#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::vector;
using std::ifstream;
using std::string;
using std::istringstream;
using std::sort;

enum class State {kEmpty, kObstacle, kClosed, kPath, kStart, kFinish};

vector<State> ParseLine(string line) {
    istringstream row(line);

    int i;
    char c;
    vector<State> boardRow;

    while (row >> i) {
        switch(i) {
            case 1: boardRow.push_back(State::kObstacle);
            default: boardRow.push_back(State::kEmpty);
        }
        
        row >> c;
    }

    return boardRow;
}

vector<vector<State>> ReadBoardFile(string path) {
    ifstream boardFile(path);

    vector<vector<State>> grid;
    
    if (boardFile){
        string line;
        while (getline(boardFile, line)) {
            grid.push_back(ParseLine(line));
        }
    }

    return grid;
}

bool Compare(vector<int> nodeSource, vector<int> nodeDest) {
    int fSource = nodeSource[2] + nodeSource[3];
    int fDest = nodeDest[2] + nodeDest[3];

    if (fSource > fDest) {
        return true;
    } 
    
    else {
        return false;
        }
}


/**
 * Sort the two-dimensional vector of ints in descending order.
 */
void CellSort(vector<vector<int>> *v) {
  sort(v->begin(), v->end(), Compare);
}

int Heuristic(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openNodes, vector<vector<State>> &grid) {
    // Create node and append to end of openNodes array
    vector<int> node = {x, y, g, h};
    openNodes.push_back(node);
    grid[x][y] = State::kClosed;
}


bool CheckValidCell(int x, int y, vector<vector<State>> grid) {
    // Check if x and y are smaller than the largest of each side but greater than 0
    bool xOnBoard = (x >= 0 && x < grid.size());
    bool yOnBoard = (y >= 0 && y < grid[x].size());
    
    if (xOnBoard && yOnBoard) {
        // if kEmpty, return true, else false
        switch(grid[x][y]) {
            case State::kEmpty: return true;
            default: return false;
        }
    
    }

    return false;
    
}

void ExpandNeighbors(vector<int> current, int goal[2], vector<vector<int>> &open, vector<vector<State>> &grid) {
    // directional deltas
    const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  	
  	int x = current[0];
  	int y = current[1];
  	int g = current[2];

    for (auto direction:delta) {
        int xStep = x + direction[0];
        int yStep = y + direction[1];

        // If on grid, calculate heuristic and add to open
        if (CheckValidCell(xStep, yStep, grid)) {
            int hStep = Heuristic(xStep, yStep, goal[0], goal[1]);
            int gStep = g + 1;
            AddToOpen(xStep, yStep, gStep, hStep, open, grid);
        }
    }
}

vector<vector<State>> Search(vector<vector<State>> grid, int init[2], int goal[2]) {
    vector<vector<int>> open;

    // initialize start node
    int nodeHeuristic = Heuristic(init[0], init[1], goal[0], goal[1]);
    vector<int> startNode = {init[0], init[1], 0, nodeHeuristic};

    // add to open
    AddToOpen(startNode[0], startNode[1], startNode[2], startNode[3],  open, grid);

    while (open.size() != 0) {
        CellSort(&open);
        vector<int> currentNode = open.back();
        open.pop_back();
        
        int xCurrent = currentNode[0];
        int yCurrent = currentNode[1];
        
        grid[xCurrent][yCurrent] = State::kPath;

        if (xCurrent == goal[0] & yCurrent == goal[1]) {
            grid[init[0]][init[1]] = State::kStart;
            grid[goal[0]][goal[1]] = State::kFinish;
            return grid;
        }

        // If we're not done, expand search to current node's neighbors.
        ExpandNeighbors(currentNode, goal, open, grid);
    }

    cout << "No path found!" << "\n";
    return std::vector<vector<State>>{};
}

string CellString(State cell) {
    switch(cell) {
        case State::kObstacle: return "⛰️ ";
        case State::kPath: return "🚗  ";
        case State::kStart: return "🚦 ";
        case State::kFinish: return "🏁 ";
        default: return "0  ";
    }
}


void PrintBoard(vector<vector<State>> grid) {
    for (auto i: grid) {
        for (State j: i) {
            cout << CellString(j);
        }
        cout << "\n";
    }
}


int main() {
    vector<vector<State>> board = ReadBoardFile("./board.txt");

    int init[2] = {0, 0};
    int goal[2] = {4, 5}; 
    auto solution = Search(board, init, goal);

    PrintBoard(solution);
}