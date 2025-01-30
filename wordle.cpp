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
   std::vector<int> code = {};
   int i = 0;
   while (i < 4)
   {
    into val = rand() % 10;
    append(code, val);
    i = i + 1;
   }
   return code;
}


std::vector<std::string> getHint(std::vector<int> secret, std::vector<int> guess) 
{
    int i = 0;

    std::vector<int> guess = {};
    while (i < 4)
    {
        std::cout << "\nEnter your guess: ";
        std::cin >> guess;
        append(code, guess);
        i = i + 1;
    }

    std::vector<std::string> hint();
    for (i < 4)
    {
        if (code[i] == guess[i])
        {
            hint.push_back ("O");
            i = i + 1;
        }
        else
        {
            hint.push_back ("X");
            i = i + 1;
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
    }
    return true;
}


int main()
{
    srand(time(0));
    
    std::vector<int> secret_code = createSecret();
    std::vector<int> user_guess = {};
    std::vector<std::string> hint;   

    int secret_code_length = 4;
    int num_guesses = 0;

    std::cout << "Welcome to Number Wordle!\n";
    
    while (!winGame(secret_code, user_guess))    
    {
        hint.clear();
        user_guess.clear();

       
        for (int i = 0; i < 4; i = i + 1)
        {
            int input;
            std::cin >> input;
            user_guess.push_back(input);    
        }

        hint = getHint(secret_code, user_guess);
        display(hint);
        num_guesses = num_guesses + 1;
    }

    std::cout << "Congrats!  You guessed the code!  It took you " << num_guesses << " tries.\n";
    return 0;
}
