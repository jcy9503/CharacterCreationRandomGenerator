/* Contributer: Lucas Jeong */
/* Clipboard Function Code from: Arian8j2 */

#include <iostream>
#include <random>
#include <string>
#include <cmath>
#include "Clipboard.h"

using namespace std;

int main(int argc, char* argv[])
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int>two(0, 99);
    uniform_int_distribution<int>color(0, 255);
    uniform_real_distribution<float>minus(-1.0f, 1.0f);
    uniform_real_distribution<float>plus(0.0f, 1.0f);
    
    bool flag = true;
    
    while(flag)
    {
        clipboardxx::clipboard clipboard;
        string copyText;
        
        cout << "1: (00), 2: (0.00)~(1.00), 3: (-1.00)~(1.00)\n"
                "4: (0, 0, 0), 3: (0, 0, 0, 0)" << endl;
        
        int num;
        cin >> num;
        
        switch(num)
        {
            
        case 1:
            copyText = to_string(two(gen));
            break;
        case 2:
            copyText = to_string(round(plus(gen)*100)/100);
            break;
        case 3:
            copyText = to_string(round(minus(gen)*100)/100);
            break;
        case 4:
            copyText = "(" + to_string(color(gen)) + "," + to_string(color(gen)) +
                "," + to_string(color(gen)) + ")";
            break;
        case 5:
            copyText = "(" + to_string(color(gen)) + "," + to_string(color(gen)) +
                "," + to_string(color(gen)) + "," + to_string(color(gen)) + ")";
            
            break;
        default:
            flag = false;
            break;
        }
        
        cout << copyText << endl << endl;
        clipboard << copyText;
    }
    
    return 0;
}
