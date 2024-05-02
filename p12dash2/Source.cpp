#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool isLetter(char c);
void pressEnterToContinue();

int main() {
    string file_path;
    cout << "input file: ";
    getline(cin, file_path);

    ifstream file(file_path);
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    std::string word;
    int word_count = 0, char_count = 0;

    while (file >> word) {
        bool has_letter = false;
        for (char c : word) {
            if (isLetter(c)) {
                char_count++;
                has_letter = true;
            }
        }
        if (has_letter) {
            word_count++;
        }
    }

    file.close();

    cout << "Words:      " << word_count << endl;
    cout << "Characters: " << char_count << endl;

    pressEnterToContinue();
}

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void pressEnterToContinue() {
    cout << "\nPress enter to continue... \n";
    cin.clear();
    while (cin.get() != '\n') continue;
}
