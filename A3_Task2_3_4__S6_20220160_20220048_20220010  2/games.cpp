// File name: games.cpp
// Purpose: Game Arcade - Application File
// Author(s): Ahmad Ismail Ali
// ID(s): 20220010, 20220048, 20220160
// Section: S6
// Date: 17-12-2023
#include "full_implementation.cpp"

int main()
{
    int choice;
    Player *players[2];
    players[0] = new Player(1, 'x');

    cout << "Welcome to FCAI Arcade. :)\n";
    cout << "Press 1 if you want to play with a computer: ";
    cin >> choice;

    cout << "Choose the game you want to play (1-4): \n";
    cout << "(1)-Regular TicTacToe.\n";
    cout << "(2)-Pyramid Board TicTacToe.\n";
    cout << "(3)-Connect-4 TicTacToe.\n";
    cout << "(4)-5x5 TicTacToe.\n";
    int x;
    cin >> x;

    bool validInput = false;
    while (!validInput)
    {
        if (x == 1)
        {
            validInput = true;
            players[1] = ((choice != 1) ? new Player(2, 'o') : new RandomPlayer('o', 3, 3));
            GameManager x_o_game(new X_O_Board(), players);
            x_o_game.run();
        }
        else if (x == 2)
        {
            validInput = true;
            players[1] = ((choice != 1) ? new Player(2, 'o') : new RandomPlayer('o', 3, 3));
            GameManager pyramid_xo(new PyramBoard(), players);
            pyramid_xo.run();
        }
        else if (x == 3)
        {
            validInput = true;
            players[1] = ((choice != 1) ? new Player(2, 'o') : new RandomPlayer('o', 7, 6));
            GameManager connect4_xo(new Board42(), players);
            connect4_xo.run();
        }
        else if (x == 4)
        {
            validInput = true;
            players[1] = ((choice != 1) ? new Player(2, 'o') : new RandomPlayer('o', 5, 5));
            Board25 new_board;
            GameManager twentyfive(new_board, players);
            twentyfive.run25();
        }
        else
        {
            cout << "Option unavailable.\n";
            cout << "Please re-enter your choice.\n";
        }
    }
    cout << "Thank you for playing.\n";
}
