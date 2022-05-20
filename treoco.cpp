#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
#include <ctime>
#include <fstream>
#include <conio.h>
using namespace std;

bool compare(string a, string b) {
    int cnt = 0;
    if (a.length() == b.length()) {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] == b[i])
                cnt++;
        } if (cnt == a.length()) {
            return true;
        }
    } return false;
}

string wordRan(int topic, int level) {
    string word;
    vector<string> Listofword;
    srand(time(NULL));

    ifstream randomWord;
    if (topic == 1) {
        randomWord.open("sport.txt");
    }
    else if (topic == 2) {
        randomWord.open("animal.txt");
    }
    else if (topic == 3) {
        randomWord.open("food.txt");
    }

    string tmp;
    while (randomWord >> tmp)
    {
        bool isValid = false;
        if (level == 1) {
            if (tmp.length() <= 5) {
                isValid = true;
            }
        }
        else {
            if (level == 2) {
                if (tmp.length() > 5) {
                    isValid = true;
                }
            }
        }

        if (isValid) {
            Listofword.push_back(tmp);
        }
    }

    int randomNum = rand() % Listofword.size();
    word = Listofword[randomNum];
    return word;
}

int main() {
    char again;

    do {
        cout << " CHOOSE MODE: \n";
        cout << "\t\t1> Press 1 to choose Player Mode \n";
        cout << "\t\t2> Press 2 to choose Computer Mode \n";

        int mode;
        cout << "\t\t Your Choice: ";
        cin >> mode;

        if (mode == 1) {
            do {
                vector<char> v;
                cout << "==~~ Welcome to HANGMAN ~~==" << endl;
                cout << "____________ " << endl;
                cout << "|     }      " << endl;
                cout << "|     0      " << endl;
                cout << "|     |      " << endl;
                cout << "|    /|\\    " << endl;
                cout << "|   / | \\   " << endl;
                cout << "|    / \\    " << endl;
                cout << "|   /   \\   " << endl;
                cout << "|            " << endl;
                cout << "|____________" << endl;
                cout << "Ten cua ban la: ";
                string PlayerName;
                getline(cin, PlayerName);

                cout << "\n\n CHOOSE TOPIC:" << endl;
                cout << "\t\t1> Press 1 to choose Sport topic" << endl;
                cout << "\t\t2> Press 2 to choose Animal topic" << endl;
                cout << "\t\t3> Press 3 to choose Food topic" << endl;

                int topic;
                cout << "\t\t Your Choice: ";
                cin >> topic;

                cout << "\n\n CHOOSE LEVEL:" << endl;
                cout << "\t\t1> Press 1 to choose Easy level" << endl;
                cout << "\t\t2> Press 2 to choose Hard level" << endl;

                int level;
                cout << "\t\t Your Choice: ";
                cin >> level;

                char batdau;
                cout << "\n\nPress any key and enter to Start the game: ";
                getch();

                string word = wordRan(topic, level);
                string mysteryWord = string(word.length(), '*');
                int len = mysteryWord.size();
                cout << mysteryWord << endl;

                int Try = 6;

                char Guess;
                string GuessfullWord;
                char choose;
                bool correctGuess;

                int x = 0;
                while (Try >= 0) {
                    correctGuess = false;

                    cout << "The word you have to guess has " << len << " characters" << endl;
                    cout << mysteryWord << endl;
                    cout << "You have " << Try << " turn to play" << endl;
                    cout << "Guess a letter: ";
                    cin >> Guess;

                    v.push_back(Guess);
                    cout << "Nhung chu da doan: ";
                    if (x >= 1) {
                        for (int i = 0;i <= x; i++) {
                            cout << v[i] << " ";
                        }
                    }
                    cout << endl;
                    x++;

                    for (int i = 0; i < mysteryWord.length(); i++) {
                        if (word[i] == Guess) {
                            mysteryWord[i] = Guess;
                            cout << "Congratulation!" << " " << Guess << " is one of the letters!" << endl;
                            correctGuess = true;
                        }
                    }

                    if (correctGuess == true) {
                        cout << "Do you want to guess the full word: (y/n)" << endl;
                        cout << "Your choice: ";
                        cin >> choose;
                        if (choose == 'y') {
                            cout << "Press full word: ";
                            cin >> GuessfullWord;
                            if (compare(word, GuessfullWord) == true)
                            {
                                cout << "Excellent! you have won this game!" << endl;
                                break;
                            }
                            else {
                                cout << "Wrong answer !!! Please try again" << endl;
                            }

                        }
                    }

                    if (word == mysteryWord)
                    {
                        cout << "Perfect!" << " " << word << " is a correct answer" << endl;
                        break;
                    }
                    if (correctGuess == false)
                    {
                        Try--;
                        cout << "Wrong" << " " << Guess << " is not a part of the word" << endl;
                    }
                    switch (Try)
                    {
                    case 6:
                        cout << "____________ " << endl;
                        cout << "|     |      " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|____________" << endl;
                        break;
                    case 5:
                        cout << "____________ " << endl;
                        cout << "|     |      " << endl;
                        cout << "|     0      " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|____________" << endl;
                        break;
                    case 4:
                        cout << "____________ " << endl;
                        cout << "|     |      " << endl;
                        cout << "|     0      " << endl;
                        cout << "|     |      " << endl;
                        cout << "|     |      " << endl;
                        cout << "|     |      " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|____________" << endl;
                        break;
                    case 3:
                        cout << "____________ " << endl;
                        cout << "|     |      " << endl;
                        cout << "|     0      " << endl;
                        cout << "|     |      " << endl;
                        cout << "|    /|      " << endl;
                        cout << "|   / |      " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|____________" << endl;
                        Try--;
                        break;
                    case 2:
                        cout << "____________ " << endl;
                        cout << "|     |      " << endl;
                        cout << "|     0      " << endl;
                        cout << "|     |      " << endl;
                        cout << "|    /|\\    " << endl;
                        cout << "|   / | \\   " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|            " << endl;
                        cout << "|____________" << endl;
                        break;
                    case 1:
                        cout << "____________ " << endl;
                        cout << "|     |      " << endl;
                        cout << "|     0      " << endl;
                        cout << "|     |      " << endl;
                        cout << "|    /|\\    " << endl;
                        cout << "|   / | \\   " << endl;
                        cout << "|    /       " << endl;
                        cout << "|   /        " << endl;
                        cout << "|            " << endl;
                        cout << "|____________" << endl;
                        break;
                    case 0:
                        cout << "____________ " << endl;
                        cout << "|     |      " << endl;
                        cout << "|     0      " << endl;
                        cout << "|     |      " << endl;
                        cout << "|    /|\\    " << endl;
                        cout << "|   / | \\   " << endl;
                        cout << "|    / \\    " << endl;
                        cout << "|   /   \\   " << endl;
                        cout << "|            " << endl;
                        cout << "|____________" << endl;
                        cout << "\n GAME OVER! You lost" << endl;
                        cout << "The correct word is: " << word << endl;
                        Try = -1;
                        break;
                    }
                }

                cout << "Do you want to play again? (y/n)";
                cin >> again;
            } while (again != 'n');
        }
        else {
            cout << "Working on it . . .!\n";
        }
        cout << "Do you want to play again? (y/n)";
        cin >> again;
    } while (again != 'n');

    cout << "\n\n ----------> Goodbye and see you again <----------" << endl;
    return 0;
}




