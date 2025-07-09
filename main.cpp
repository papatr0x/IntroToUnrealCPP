#include <iostream>
#include <vector>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <algorithm>


const std::vector<std::string> options = {"rock", "paper", "scissors"};

// read player choice (rock, paper, scissors)
int readPlayerChoice()
{
    std::string choice;
    std::cin >> choice;

    while (true) {
        auto it = std::find(options.cbegin(), options.cend(), choice);
        if (it != options.cend()) {
            return options.cbegin() - it;
        }

        // if (choice == "rock")
        //     return 0;
        // else if (choice == "paper")
        //     return 1;
        // else if (choice == "scissors")
        //     return 2;

        std::cout << "Invalid choice" << std::endl;
    }

    return -1;
}

// returns tie=0, p1 wins=1, p2 wins=2
int checkResults(int p1Choice, int p2Choice)
{
    if (p1Choice == p2Choice)
    {
        return 0;
    }

    if ((p1Choice + 1) % 3 == p2Choice) {
        return 2;
    }

    return 1;
}

void initialize() {
    // Seed the random number generator once (typically in main())
    srand(static_cast<unsigned int>(time(nullptr)));
}

int get_computer_choice() {
    return rand() % options.size();
}

// rock, paper, scissors
int main()
{
    initialize();

    int p1Wins = 0;
    int p2Wins = 0;

    // repeat 3 times
    for (int i = 0; i < 3; i++)
    {
        // player 1 choose rock, paper, scissors
        std::cout << "Player 1, choose rock, paper, scissors" << std::endl;
        int p1Choice = readPlayerChoice();

        // player 2 chooses rock, paper, scissors
        // std::cout << "Player 2, choose rock, paper, scissors" << std::endl;
        // int p2Choice = readPlayerChoice();

        // computer choice
        int p2Choice = get_computer_choice();
        std::cout << "Computer chooses " << options[p2Choice] << std::endl;

        // check results
        const int winner = checkResults(p1Choice, p2Choice);

        // record result
        if (winner == 1) {
            p1Wins++;
        }
        else if (winner == 2) {
            p2Wins++;
        }
    }

    // the player with more points win
    if (p1Wins == p2Wins) {
        std::cout << "Tie" << std::endl;
    }
    else if (p1Wins > p2Wins) {
        std::cout << "Player 1 wins" << std::endl;
    }
    else {
        //std::cout << "Player 2 wins" << std::endl;
        std::cout << "Computer wins" << std::endl;
    }
}