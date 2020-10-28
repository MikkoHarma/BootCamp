//ASCII 0x41-0x5A A-Z
#include <iostream>
#include <string>

using namespace std;

int main (){

    int cipher_key;
    string cipher_text, decoded_text;
    char encoded = 0;

    cout << "Input cipher key (0-26):" << endl;
    cin >> cipher_key;

    if(cipher_key < 0 || cipher_key > 26)
        return 0;

    cout << "Input cipher text (A-Z):" << endl;
    cin >> cipher_text;

    cout << "Data: " << cipher_text << " : Key: " << cipher_key << endl; 

    for(int x = 0; x < cipher_text.size(); x++) 
    {
        encoded = cipher_text.at(x);
        if(encoded < 0x41 || encoded > 0x5A) // if outside of range print ?
        {
            encoded = 0x3F;
        }
        else if(encoded - cipher_key >= 0x41) // if no wrap
        {
            encoded = encoded - cipher_key;
        }
        else
        {
            encoded  = 0x5B - (0x41 - (encoded - cipher_key)); //wrap
        }
        decoded_text.replace(x, 1, &encoded);    // add decoded char to string
    }
    cout << "Decoded text: " << decoded_text << endl;
}