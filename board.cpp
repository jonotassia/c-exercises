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

enum class State {kEmpty, kObstacle, kClosed, kPath};

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

vector<vector<State>> Search(vector<vector<State>> grid, vector<int> init, vector<int> goal) {
    vector<vector<int>> open;

    // initialize start node
    int nodeHeuristic = Heuristic(init[0], init[1], goal[0], goal[1]);
    vector<int> startNode = {init[0], init[1], 0, nodeHeuristic};

    // add to open
    AddToOpen(startNode[0], startNode[1], startNode[2], startNode[3],  open, grid);

    while (open.size() != 0) {
        CellSort(&open);
        vector<int> currentNode = open[0];
        
        int xCurrent = currentNode[0];
        int yCurrent = currentNode[1];
        
        grid[xCurrent][yCurrent] = State::kPath;

        if (xCurrent == goal[0] & yCurrent == goal[1]) {
            return grid;
        }

        // Expand neighbors
        break;
    }

    cout << "No path found!" << "\n";
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

string CellString(State cell) {
    switch(cell) {
        case State::kObstacle: return "⛰️ ";
        case State::kPath: return "🚗   ";
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
    vector<vector<State>> grid = ReadBoardFile("./grid.txt");

    vector<int> init = {0, 0};
    vector<int> goal = {4, 5}; 
    auto solution = Search(grid, init, goal);

    PrintBoard(solution);
}