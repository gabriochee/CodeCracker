#include <iostream>
#include <string>

bool same(char* target, char* prototype, int target_length) {
    for (int i = 0; i < target_length; i++) {
        if (prototype[i] != target[i]) { return false; }
    }
    return true;
}

int main()
{
    char caracters[63] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char mdp[] = "1234";
    char test[26] = { 'a' };
    int pointer = 0;
    int index = 0;
    bool cycle_ended = false;
    while (!same(mdp,test,4)) {
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
            bool added = false;
            while (test[pointer] == '9') {
                test[pointer] = 'A';
                pointer--;
                length++;
                if (pointer < 0) {
                    pointer = length;
                    std::cout << length << '\n';
                    test[pointer] = 'A';
                    added = true;
                    break;
                }
            }
            if(!added) {
                int pos = 0;
                for (pos; pos <= 61; pos++) {
                    if (caracters[pos] == test[pointer]) { pos++; break; }
                }
                test[pointer] = caracters[pos];
                pointer++;
                while (test[pointer] == 'A' && test[pointer + 1] != 0) { pointer++; }
            }
            cycle_ended = false;
        }
        std::cout << test << '\n';
    }
    return 0;
}