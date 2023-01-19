#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::vector;
using std::ifstream;
using std::string;
using std::istringstream;

enum class State {kEmpty, kObstacle, kClosed};

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

    vector<vector<State>> board;
    
    if (boardFile){
        string line;
        while (getline(boardFile, line)) {
            board.push_back(ParseLine(line));
        }
    }

    return board;
}

int Heuristic(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

void AddToOpen(int x, int y, int g, int h, vector<vector<int>> &openNodes, vector<vector<State>> &board) {
    // Create node and append to end of openNodes array
    vector<int> node = {x, y, g, h};
    openNodes.push_back(node);
    board[x][y] = State::kClosed;
}

vector<vector<State>> Search(vector<vector<State>> board, vector<int> init, vector<int> goal) {
    vector<vector<State>> solution_board;
    vector<vector<int>> open;

    // initialize start node
    int nodeHeuristic = Heuristic(init[0], init[1], goal[0], goal[1]);
    vector<int> startNode = {init[0], init[1], 0, nodeHeuristic};

    // add to open
    AddToOpen(startNode[0], startNode[1], startNode[2], startNode[3],  open, board);

    cout << "No path found!" << "\n";
    return solution_board;
}

string CellString(State cell) {
    switch(cell) {
        case State::kObstacle: return "⛰️ ";
        default: return "0  ";
    }
}


void PrintBoard(vector<vector<State>> board) {
    for (auto i: board) {
        for (State j: i) {
            cout << CellString(j);
        }
        cout << "\n";
    }
}


int main() {
    vector<vector<State>> board = ReadBoardFile("./board.txt");

    vector<int> init = {0, 0};
    vector<int> goal = {4, 5}; 
    auto solution = Search(board, init, goal);

    PrintBoard(solution);
}