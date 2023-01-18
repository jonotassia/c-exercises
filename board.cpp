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

enum class State {kEmpty, kObstacle};

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
    PrintBoard(board);
}