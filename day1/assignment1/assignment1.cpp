#include <iostream>
#include <string>

using namespace std;

int main(){

    int user_input;
    int number_array [8][9][11];

    cout << "Input a positive number:" << endl;
    cin >> user_input;

    if(user_input > 0 && user_input <= 65335) //check value range
    {
        for(int a = 0; a < 8; a++)
        {   
            for (int aa = 0; aa < 9; aa++)
            {
                for(int aaa = 0; aaa < 11; aaa++)
                {
                    number_array[a][aa][aaa] = rand() % user_input;
                }
            }
        }

        for(int b = 0; b < 8; b++)
        {
            cout << endl << "Array : " << "{" << b << "}" << endl;

            for(int bb = 0; bb < 9; bb++)
            {   
                cout << "{";
                for(int bbb = 0; bbb < 11;  bbb++)
                {
                    cout << "[" << number_array[b][bb][bbb] << "]";    
                }
                cout << "}, " << endl;
            }

        }
        
    }
    else
    {
        cout << "Number out of range (0-65335): " << user_input << endl;    
    }
    
    return 1;
}