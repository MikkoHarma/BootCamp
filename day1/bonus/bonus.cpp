#include <iostream>
#include <string>

using namespace std;

int main (){

    int ask_number = 0;
    int thinking_of_number = 0;

    srand(time(NULL)); // random seed
    thinking_of_number = rand() % 128 + 1;

    for (int x=0; x < 7; x++) // 7 tries
    {
        cout << "Guess a number I'm thinking of (1-128). Guess: " << x + 1 << endl;
        cin >> ask_number;

        if(ask_number < 1 || ask_number > 128)
        {
           cout << "Invalid number, guess again. Guess: " << x+1 << endl;
        }
        else
        {
            if(ask_number == thinking_of_number)
            {
                cout << "You guessed the number: " << thinking_of_number << endl;
                return 1;
            }
            else if (ask_number < thinking_of_number)
            {
                cout << "Number is higher than: " << ask_number << endl;
            }
            else
            {
                cout << "Number is lower than: " << ask_number << endl;
            }
        }
    }
    cout << "Too bad you failed. Number I was thinking of: " << thinking_of_number << endl;
    return 1;
}