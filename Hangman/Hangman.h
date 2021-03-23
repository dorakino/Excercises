#ifndef HANGMAN_H
#define HANGMAN_H

class Hangman
{
private:
    std::vector<char> v;
    std::string myWord;
    std::map<char, bool> letters;
    std::map<char, bool>::iterator it;

    void generateWord();
    void setup();
    void figure(int a);

public:
    void play();
};


#endif
