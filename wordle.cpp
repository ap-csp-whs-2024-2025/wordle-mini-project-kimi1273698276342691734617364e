/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"

#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <iostream>  // std::cin, std::cout
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

std::vector<int> createSecret() 
{
    std::vector<int> secret_code(4);
    for (int i = 0; i < 4; i = i + 1)
    {
        int random_num = rand() % 10; 
    }

    return secret_code;
}

std::vector<std::string> getHint(std::vector<int> secret, std::vector<int> guess) 
{
    std::vector<std::string> hint(4);
    for (int i = 0; i < 4; i = i+1)
    {
        if (secret_code[i] == user_guess[i])
        {
            hint[i] = "O";
        }
        else
        {
            hint[i] = "X";
        }
    }

    return hint;
}

bool winGame(std::vector<int> secret, std::vector<int> guess) 
{
    for (int i = 0; i < 4; i = i+1)
    {
        if (secret_code[i] != user_guess[i])
        {
            return false;    
        }
    
        return true;
    }
}

int main()
{
    srand(time(0));
    
    std::vector<int> secret_code = createSecret();
    std::vector<int> user_guess = {};
    std::vector<std::string> hint = {};   

    int secret_code_length = 4;
    int num_guesses = 0;

    std::cout << "Welcome to Number Wordle!\n";
    
    while (!winGame(secret_code, user_guess))    // while you have not won the game yet
    {
        std::cout << "\nEnter your guess: ";
        hint = {};    // reset the hint for the next guess
        for (int i = 0; i < 4; i = i + 1)
        {
            int input;
            std::cin >> input;
            guess.push_back(input);    
        }

        hint = getHint(secret_code, user_guess);
        display(hint);
        num_guesses = num_guesses + 1;
    }

    std::cout << "Congrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    return 0;
}
