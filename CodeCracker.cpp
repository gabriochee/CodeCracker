#include <iostream>
#include <string>

int main()
{
    char caracters[63] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    //for (int i = int('A'); i <= int('Z'); i++) {
    //    caracters[i - int('A')] = char(i);
    //}
    //for (int i = int('a'); i <= int('z'); i++) {
    //    caracters[26 + i - int('a')] = char(i);
    //}
    //for (int i = int('0'); i <= int('9'); i++) {
    //    caracters[52 + i - int('0')] = char(i);
    //}
    char mdp[] = {'a','l','a'};
    char test[26] = { 'a' };
    int pointer = 0;
    int index = 0;
    bool cycle_ended = false;
    while (test[0] != test[1] != test[2] != 'z') {
        if (!cycle_ended) {
            test[pointer] = caracters[index];
            if (index >= 61) {
                cycle_ended = true;
                index = 0;
            }
            else {
                index++;
            }
        }
        else {
            int length = 0;
            bool new_letter = false;
            while (test[pointer] == '9') {
                test[pointer] = 'A';
                pointer--;
                if (pointer < 0) {
                    pointer = length+1;
                    test[pointer] = 'A';
                    new_letter = true;
                    break;
                }
                length++;
            }
            if (!new_letter) {
                int pos = 0;
                for (pos; pos < 62; pos++) {
                    if (caracters[pos] == test[pointer]) { break; }
                }
                test[pointer] = (pos < 61) ? caracters[pos + 1] : 'A';
                pointer++;
            }
            cycle_ended = false;
        }
        std::cout << test << '\n';
    }
    return 0;
}