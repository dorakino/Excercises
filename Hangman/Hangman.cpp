#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "Hangman.h"


void Hangman::generateWord() {
    int coord;
    std::vector<std::string> words;
    std::string line;
    std::ifstream myfile("words.txt");

    if (myfile.is_open())
    {
        while (getline(myfile, line, '\n')) {
            words.push_back(line);
        }
        myfile.close();
    }
    /*
    else {
        std::cout << "unable to open." << std::endl;
    }
    */

    srand(time(NULL));
    coord = rand() % words.size();
    myWord = words[coord];
}

void Hangman::setup() {
    //collect letters appering in theoretical word
    for (int i = 0; i < myWord.length(); i++) {
        it = letters.find(myWord.at(i));
        if (it == letters.end()) {
            letters.insert(std::pair<char, int>(myWord.at(i), 0));
        }
    }
}


void Hangman::figure(int a) {
    switch (a) {
    case 1:
        for (int i = 0; i < 8; i++) {
            std::cout << std::endl;
        }
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        break;
    case 2:
        for (int i = 0; i < 8; i++) {
            std::cout << "|" << std::endl;
        }
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        break;
    case 3:
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        for (int i = 0; i < 7; i++) {
            std::cout << "|" << std::endl;
        }
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        break;
    case 4:
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        std::cout << "|/" << std::endl;
        for (int i = 0; i < 6; i++) {
            std::cout << "|" << std::endl;
        }
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        break;
    case 5:
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        std::cout << "|/  |" << std::endl;
        std::cout << "|   |" << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << "|" << std::endl;
        }
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        break;
    case 6:
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        std::cout << "|/  |" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "|   O" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << "|" << std::endl;
        }
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        break;
    case 7:
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        std::cout << "|/  |" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "|   O" << std::endl;
        std::cout << "|   T" << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << "|" << std::endl;
        }
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        break;
    case 8:
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        std::cout << "|/  |" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "|   O" << std::endl;
        std::cout << "|  vTv" << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << "|" << std::endl;
        }
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        break;
    case 9:
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        std::cout << "|/  |" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "|   O" << std::endl;
        std::cout << "|  vTv" << std::endl;
        std::cout << "|   Y" << std::endl;
        for (int i = 0; i < 2; i++) {
            std::cout << "|" << std::endl;
        }
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        break;
    case 10:
        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        std::cout << "|/  |" << std::endl;
        std::cout << "|   |" << std::endl;
        std::cout << "|   O" << std::endl;
        std::cout << "|  vTv" << std::endl;
        std::cout << "|   Y" << std::endl;
        std::cout << "|   =" << std::endl;
        std::cout << "|" << std::endl;

        for (int i = 0; i < 8; i++) {
            std::cout << "=";
        }
        std::cout << std::endl;
        break;
    default:
        std::cout << "a";
    }

}


void Hangman::play() {

    Hangman::generateWord();
    Hangman::setup();

    int count = 0;
    bool win = false;
    char c;
    bool found;
    std::string guess;

    std::cout << "You can guess a letter or the final word (for this type 0 and an enter, then guess the word)." << std::endl << std::endl;
    for (int i = 0; i < myWord.length(); i++) {
        std::cout << "_ ";
    }
    std::cout << std::endl;
    
    while (count < 10 && win == false) {
        win = true;
        if (count != 0) {
            std::cout << std::endl << "You have already guessed these: ";
            for (int i = 0; i < v.size(); i++) {
                std::cout << v[i] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "You have " << 10 - count << " attempts remained." << std::endl;
        std::cout << "Your guess:" << std::endl;
        std::cin >> c;
        if (c == '0') {
            std::cin >> guess;
            if (guess == myWord) {
                win = true;
                break;
            }
            else {
                win = false;
                break;
            }
        }

        found = false;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == c) {
                found = true;
            }
        }
        if (found) {
            std::cout << "You have already guessed letter " << c << std::endl;
            win = false;
            continue;
        }
        else {
            v.push_back(c);
        }
        it = letters.find(c);
        if (it == letters.end()) {
            count++;
            std::cout << "NO..." << std::endl;
            Hangman::figure(count);
        }
        else {
            std::cout << "Yes!!!" << std::endl;
            it->second = 1;
        }
        std::cout << std::endl;
        for (int i = 0; i < myWord.length(); i++) {
            it = letters.find(myWord.at(i));
            if (it->second == false) {
                std::cout << "_ ";
                win = false;
            }
            else {
                std::cout << myWord.at(i) << " ";
            }
        }
        std::cout << std::endl;
    }
    if (win) {
        std::cout << "Congratulations!" << std::endl;
    }
    else {
        std::cout << "The solution was: " << myWord << std::endl;
        std::cout << ":(" << std::endl;
    }
}

