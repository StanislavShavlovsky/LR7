#include <iostream>

void read(char*& s) {
    while (true) {
        int i = 0;
        while (true) {
            s[i] = (char)getchar(); // O(1)
            if (s[i] == '\n') {
                s[i] = '\0';
                return;
            }
            i++; // O(n)
        }
    }
}

void read(int& n) {
    n = 0;
    while (true) {
        char c = (char)getchar(); // O(1)
        if (c == '\n') {
            return;
        }
        n = n * 10 + c - '0'; // O(n)
    }
}

void write(char*& s) {
    for (int i = 0; s[i] != '\0'; i++) { // O(n)
        std::cout << s[i]; // O(1)
    }
    std::cout << '\n';
}
