#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <sstream>
#include "Deck.h"
#include "Util.h"
#include "Tools.h"

using namespace std;
using namespace ds;

// Task 1
class Game : public Program {
private:
    static constexpr int MAX_TUBES = 20; // Maximum number of tubes
    Deck tubes[MAX_TUBES];
    string moveHistory[MAX_TUBES * 10]; // Enough capacity for moves
    int numColors;
    static const int maxCapacity = 4;
    int moveCount; // Track the number of moves stored in `moveHistory`

    bool isValidMove(int from, int to) const {
        if (from < 0 || from >= numColors + 2 || to < 0 || to >= numColors + 2) {
            return false; // Out of bounds
        }
        if (tubes[to].Size() >= maxCapacity) {
            return false; // Tube is full
        }
        if (tubes[from].Empty()) {
            return false; // No ball to move
        }
        if (!tubes[to].Empty() && tubes[to].View("top") != tubes[from].View("top")) {
            return false; // Colors do not match
        }
        return true;
    }

public:
    // Task 2
    Game() : numColors(0), moveCount(0) {}

    // Delete copy constructor and assignment operator
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    // Task 3
    void Initialize() override {
        Token balls[MAX_TUBES * maxCapacity]; // Enough capacity for tokens
        int totalBalls = numColors * maxCapacity;

        for (int i = 0; i < numColors; ++i) {
            for (int j = 0; j < maxCapacity; ++j) {
                balls[i * maxCapacity + j] = Token(to_string(i), i);
            }
        }

        srand(static_cast<unsigned int>(time(0))); // Seed for randomness

        for (int i = 0; i < totalBalls; ++i) {
            int randomIndex = rand() % totalBalls;
            swap(balls[i], balls[randomIndex]);
        }

        int index = 0;
        for (int i = 0; i < numColors; ++i) {
            for (int j = 0; j < maxCapacity; ++j) {
                tubes[i].Insert(balls[index++], "gc");
            }
        }
    }

    // Task 4
    void Move(string flag) override {
        stringstream ss(flag);
        string command;
        int from, to;

        ss >> command >> from >> to;
        if (command != "mt" || !isValidMove(from, to)) {
            throw invalid_argument("Invalid move");
        }

        Token ball = tubes[from].View("top");
        tubes[from].Remove("top");
        tubes[to].Insert(ball, "pc");

        moveHistory[moveCount++] = flag;
    }

    // Task 5
    bool Undo() override {
        if (moveCount == 0) {
            return false;
        }

        string lastMove = moveHistory[--moveCount];
        stringstream ss(lastMove);
        string command;
        int from, to;

        ss >> command >> from >> to;
        if (command == "mt") {
            Token ball = tubes[to].View("top");
            tubes[to].Remove("top");
            tubes[from].Insert(ball, "pc");
        }

        return true;
    }

    // Task 6
    bool Completed() const override {
        for (int i = 0; i < numColors + 2; ++i) {
            if (!tubes[i].Empty()) {
                if (tubes[i].Size() != maxCapacity) {
                    return false;
                }
                // Check if all tokens in the tube have the same color
                Token topBall = tubes[i].View("top");
                for (int j = 0; j < tubes[i].Size(); ++j) {
                    Token currentBall = tubes[i].View(to_string(j + 1));
                    if (currentBall.Key() != topBall.Key()) { // Compare the color (Key) of tokens
                        return false;
                    }
                }
            }
        }
        return true;
    }


    // Task 7
    string State() const override {
        return Completed() ? "Game Completed" : "Game In Progress";
    }

    // Task 8
    virtual string Info() const override {
        stringstream out;
        out << "Valid flags for the Move() method:\n";
        out << "  'mt <fromTube> <toTube>' - Moves a ball from the 'fromTube' to 'toTube'.\n";
        out << "       Rules:\n";
        out << "         - You can only place a ball into an empty tube or onto a ball of the same color.\n";
        out << "         - Tubes can hold a maximum of four balls.\n";
        out << "         - If the move is invalid, it will be rejected.\n";
        out << "  'u' - Undo the last move made.\n";
        out << "  'c' - Check if the game is completed, returning true if each tube contains balls of only one color.\n";
        return out.str();
    }

    // Task 9
    string ToString() const override {
        stringstream ss;
        for (int i = 0; i < numColors + 2; ++i) {
            ss << "Tube " << i + 1 << ":" << "\n"
                << tubes[i].ToString() << "\n";
        }
        return ss.str();
    }
};

#endif // GAME_H
