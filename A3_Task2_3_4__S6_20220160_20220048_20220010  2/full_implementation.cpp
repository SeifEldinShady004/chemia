// File name: full_implementation.cpp
// Purpose: Game Arcade - Implementation File
// Author(s): Ahmad Ismail Ali
// ID(s): 20220010, 20220048, 20220160
// Section: S6
// Date: 17-12-2023
#include "board_game.hpp"
// Board class implementation starts here//////////////////////////////
Board::Board() { n_rows = n_cols = 0; }
void Board::display_board()
{
    for (int i = 0; i < n_rows; ++i)
    {
        cout << "\n| ";
        for (int j = 0; j < n_cols; ++j)
        {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << '\n';
}
bool Board::update_board(int x, int y, char symbol)
{
    if ((x < 0 || x > n_rows || y < 0 || y > n_cols) || (board[x][y] != 0))
    {
        cout << "Invalid move.\n";
        return false;
    }
    board[x][y] = symbol;
    return true;
}
// Board class implementation ends here//////////////////////////////

// X_O_Board class implementation starts here//////////////////////////
X_O_Board::X_O_Board()
{
    n_rows = n_cols = 3;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool X_O_Board::is_winner()
{
    char row_win[3], col_win[3], diag_win[2];
    for (int i : {0, 1, 2})
    {
        row_win[i] = board[i][0] & board[i][1] & board[i][2];
        col_win[i] = board[0][i] & board[1][i] & board[2][i];
    }
    diag_win[0] = board[0][0] & board[1][1] & board[2][2];
    diag_win[1] = board[2][0] & board[1][1] & board[0][2];

    for (int i : {0, 1, 2})
    {
        if ((row_win[i] && (row_win[i] == board[i][0])) ||
            (col_win[i] && (col_win[i] == board[0][i])))
            return true;
    }
    if ((diag_win[0] && diag_win[0] == board[1][1]) ||
        (diag_win[1] && diag_win[1] == board[1][1]))
        return true;
    return false;
}
bool X_O_Board::is_draw() { return (n_moves == 9 && !is_winner()); }
bool X_O_Board::game_is_over() { return n_moves >= 9; }
// X_O_Board class implementation ends here//////////////////////////

// PyramBoard class implementation starts here//////////////////////////
PyramBoard::PyramBoard()
{
    n_rows = 3;
    board = new char *[n_rows];
    board[0] = new char[1];
    board[0][0] = 0;
    board[1] = new char[3];
    for (int i : {0, 1, 2})
        board[1][i] = 0;
    board[2] = new char[5];
    for (int i : {0, 1, 2, 3, 4})
        board[2][i] = 0;
}
bool PyramBoard::update_board(int x, int y, char symbol)
{
    if (x < 0 || y < 0 || x >= n_rows || y >= get_num_columns(x))
        return false;
    if (board[x][y] != 0)
        return false;
    board[x][y] = symbol;
    return true;
}
void PyramBoard::display_board()
{
    cout << "             |(0,0)" << setw(2) << board[0][0] << " |\n";
    cout << "      |(1,0)" << setw(2) << board[1][0] << " |(1,1)" << setw(2) << board[1][1] << " |(1,2)" << setw(2) << board[1][2] << " |\n|";
    for (int i = 0; i < 5; ++i)
        cout << "(2," << i << ")" << setw(2) << board[2][i] << " |";
    cout << "\n-----------------------------\n";
}
bool PyramBoard::is_winner()
{
    bool a, b, c, d;
    a = (board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x') || (board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o');
    b = (board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x') || (board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o');
    c = (board[0][0] == 'x' && board[1][2] == 'x' && board[2][4] == 'x') || (board[0][0] == 'o' && board[1][2] == 'o' && board[2][4] == 'o');
    d = (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') || (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o');
    if (a || b || c || d)
        return true;
    for (int i : {0, 1, 2})
    {
        if ((board[2][i] == 'x' && board[2][i + 1] == 'x' && board[2][i + 2] == 'x') ||
            (board[2][i] == 'o' && board[2][i + 1] == 'o' && board[2][i + 2] == 'o'))
            return true;
    }
    return false;
}
bool PyramBoard::is_draw() { return (n_moves == 9 && !is_winner()); }
bool PyramBoard::game_is_over() { return n_moves >= 9; }
int PyramBoard::get_num_columns(int x) { return (x < 0 || x >= 3 ? NAN : (x == 0 ? 1 : (x == 1 ? 3 : 5))); }
// PyramBoard class implementation ends here//////////////////////////

// Board42 class implementation starts here//////////////////////////
Board42::Board42()
{
    n_rows = 7;
    n_cols = 6;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool Board42::is_winner()
{
    for (int i : {0, 1, 2, 3, 4, 5, 6})
    {
        for (int j : {0, 1, 2})
            if ((board[i][j] == 'x' && board[i][j + 1] == 'x' && board[i][j + 2] == 'x' && board[i][j + 3] == 'x') ||
                (board[i][j] == 'o' && board[i][j + 1] == 'o' && board[i][j + 2] == 'o' && board[i][j + 3] == 'o'))
                return true;
    }
    for (int j : {0, 1, 2, 3, 4, 5})
    {
        for (int i : {0, 1, 2, 3})
            if ((board[i][j] == 'x' && board[i + 1][j] == 'x' && board[i + 2][j] == 'x' && board[i + 3][j] == 'x') ||
                (board[i][j] == 'o' && board[i + 1][j] == 'o' && board[i + 2][j] == 'o' && board[i + 3][j] == 'o'))
                return true;
    }
    for (int i : {0, 1, 2, 3})
    {
        for (int j : {0, 1, 2})
            if ((board[i][j] == 'x' && board[i + 1][j + 1] == 'x' && board[i + 2][j + 2] == 'x' && board[i + 3][j + 3] == 'x') ||
                (board[i][j] == 'o' && board[i + 1][j + 1] == 'o' && board[i + 2][j + 2] == 'o' && board[i + 3][j + 3] == 'o'))
                return true;
    }
    for (int i : {3, 4, 5, 6})
    {
        for (int j : {0, 1, 2})
            if ((board[i][j] == 'x' && board[i - 1][j + 1] == 'x' && board[i - 2][j + 2] == 'x' && board[i - 3][j + 3] == 'x') ||
                (board[i][j] == 'o' && board[i - 1][j + 1] == 'o' && board[i - 2][j + 2] == 'o' && board[i - 3][j + 3] == 'o'))
                return true;
    }
    return false;
}
bool Board42::update_board(int x, int y, char symbol)
{
    if (x < 0 || x >= n_rows || y < 0 || y >= n_cols || board[x][y] != 0 || (x < 6 && board[x + 1][y] == 0))
        return false;
    board[x][y] = symbol;
    return true;
}
bool Board42::is_draw() { return (n_moves == 28 && !is_winner()); }
bool Board42::game_is_over() { return n_moves >= 28; }
// Board42 class implementation starts here//////////////////////////

// Board25 class implementation starts here//////////////////////////
Board25::Board25()
{
    n_rows = n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
int Board25::wins(char symbol)
{
    int num_of_wins = 0;
    for (int i : {0, 1, 2, 3, 4}) // Vertical
    {
        string new_str = "";
        for (int j : {0, 1, 2, 3, 4})
            new_str += board[i][j];
        bool a = new_str.substr(0, 3) == string(3, symbol);
        bool b = new_str.substr(1, 3) == string(3, symbol);
        bool c = new_str.substr(2, 3) == string(3, symbol);
        num_of_wins += (a + b + c);
    }
    for (int j : {0, 1, 2, 3, 4}) // Vertical
    {
        string new_str = "";
        for (int i : {0, 1, 2, 3, 4})
            new_str += board[i][j];
        bool a = new_str.substr(0, 3) == string(3, symbol);
        bool b = new_str.substr(1, 3) == string(3, symbol);
        bool c = new_str.substr(2, 3) == string(3, symbol);
        num_of_wins += (a + b + c);
    }
    //  Left to right diagonal wins
    for (int i : {0, 1, 2})
    {
        for (int k : {0, 1, 2})
        {
            string new_str = "";
            for (int j : {0, 1, 2})
                for (int l : {0, 1, 2})
                    new_str += board[i + k][j + l];
            num_of_wins += (new_str == string(3, symbol));
        }
    }
    // Right to left diagonal wins
    for (int i : {4, 3, 2})
    {
        for (int k : {0, 1, 2})
        {
            string new_str = "";
            for (int j : {4, 3, 2})
                for (int l : {0, 1, 2})
                    new_str += board[i - k][j - l];
            num_of_wins += (new_str == string(3, symbol));
        }
    }
    return num_of_wins;
}
bool Board25::is_winner() { return true; }
bool Board25::is_draw() { return false; }
bool Board25::game_is_over() { return true; }
char Board25::winner(char c1, char c2) { return ((wins(c1) == wins(c2)) ? 'D' : ((wins(c1) > wins(c2)) ? c1 : c2)); }
// Board25 class implementation ends here//////////////////////////

// Player class implementation starts here//////////////////////////////
Player::Player(char symbol) : symbol(symbol) {}
string Player::to_string() { return "Player: " + name; }
char Player::get_symbol() { return symbol; }
Player::Player(int order, char symbol) : symbol(symbol)
{
    cout << "Welcome player " << order << "\nPlease enter your name: ";
    cin >> name;
}
void Player::get_move(int &x, int &y)
{
    cout << "\nPlease enter your move x and y separated by spaces(x y): ";
    cin >> x >> y;
}
// Player class implementation ends here//////////////////////////////

// RandomPlayer class implementation starts here//////////////////////////////
RandomPlayer::RandomPlayer(char symbol, int dd, int ee) : Player(symbol), d(dd), e(ee)
{
    name = "Random Computer Player";
    cout << "My names is " + name + '\n';
}
void RandomPlayer::get_move(int &x, int &y)
{
    x = (rand() / (RAND_MAX + 1.0) * d);
    y = (rand() / (RAND_MAX + 1.0) * e);
}
// RandomPlayer class implementation ends here//////////////////////////////

// GameManager class implementation starts here//////////////////////////////
GameManager::GameManager(Board *bPtr, Player *playerPtr[2])
{
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}
GameManager::GameManager(Board25 new_board, Player *playerPtr[2])
{
    five_by_five = new_board;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}
void GameManager::run()
{
    int x, y;
    boardPtr->display_board();
    while (!boardPtr->game_is_over())
    {
        for (int i : {0, 1})
        {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol()))
                players[i]->get_move(x, y);
            boardPtr->display_board();
            if (boardPtr->is_winner())
            {
                cout << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw())
            {
                cout << "Draw!\n";
                return;
            }
        }
    }
}
void GameManager::run25()
{
    cout << "Welcome to the 5x5 TicTacToe Game. :)\n\n";
    char c1 = players[0]->get_symbol(), c2 = players[1]->get_symbol();

    five_by_five.display_board();

    int x, y, moves_made = 0;
    while (moves_made < 24)
    {
        for (int i : {0, 1})
        {
            players[i]->get_move(x, y);
            while (!five_by_five.update_board(x, y, players[i]->get_symbol()))
                players[i]->get_move(x, y);
            five_by_five.display_board();
            moves_made++;
            cout << "\nMoves Made: " << moves_made << '\n';
        }
    }

    if (five_by_five.winner(c1, c2) == c1)
        cout << players[0]->to_string() + " wins!!\n\n";
    else if (five_by_five.winner(c1, c2) == c2)
        cout << players[1]->to_string() + " wins!!\n\n";
    else
        cout << "This is a draw.\n\n";
}
// GameManager class implementation ends here//////////////////////////////
