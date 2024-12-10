// File name: board_game.hpp
// Purpose: Game Arcade - Header File
// Author(s): Ahmad Ismail Ali
// ID(s): 20220010, 20220048, 20220160
// Section: S6
// Date: 17-12-2023
#ifndef BOARD_GAME_H
#define BOARD_GAME_H
#include <bits/stdc++.h>
using namespace std;

class Board
{
protected:
    int n_rows, n_cols, n_moves = 0;
    char **board;

public:
    Board();
    virtual void display_board();
    virtual bool update_board(int x, int y, char symbol);
    virtual bool is_winner() = 0, is_draw() = 0, game_is_over() = 0; // Board states
};

class X_O_Board : public Board
{
public:
    X_O_Board();
    bool is_winner(), is_draw(), game_is_over();
};

class PyramBoard : public Board
{
public:
    PyramBoard();
    bool is_winner(), is_draw(), game_is_over();
    bool update_board(int x, int y, char symbol);
    int get_num_columns(int x);
    void display_board();
};

class Board42 : public Board
{
public:
    Board42();
    bool update_board(int x, int y, char symbol);
    bool is_winner(), is_draw(), game_is_over();
};

class Board25 : public Board
{
public:
    Board25();
    bool is_winner(), is_draw(), game_is_over();
    int wins(char symbol);
    char winner(char c1, char c2);
};

class Player
{
protected:
    string name;
    char symbol;

public:
    Player(char symbol);
    Player(int order, char symbol);
    virtual void get_move(int &x, int &y);
    string to_string();
    char get_symbol();
};

class RandomPlayer : public Player
{
    int d, e;

public:
    RandomPlayer(char symbol, int dd, int ee);
    void get_move(int &x, int &y);
};

class GameManager
{
    Board *boardPtr;
    Board25 five_by_five;
    Player *players[2];

public:
    GameManager(Board *, Player *playerPtr[2]);
    GameManager(Board25, Player *playerPtr[2]);
    void run(), run25();
};
#endif
