#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("compilerLT.txt");

    if (!fin.is_open()) {
        cout << "Cannot open file!" << endl;
        return 0;
    }

    string lineText;

    while (getline(fin, lineText)) {

        string token = "";

        for (int i = 0; i < lineText.size(); i++) {

            char current = lineText[i];

            if ((current >= 'a' && current <= 'z') ||
                (current >= 'A' && current <= 'Z') ||
                (current >= '0' && current <= '9') ||
                current == '_') {

                token = token + current;
            }
            else {

                if (token.length() > 0) {

                    if (token == "int" || token == "return") {
                        cout << "Keyword -> " << token << endl;
                    }
                    else if (token[0] >= '0' && token[0] <= '9') {
                        cout << "Number -> " << token << endl;
                    }
                    else {
                        cout << "Identifier -> " << token << endl;
                    }

                    token = "";
                }

                if (current == ' ')
                    continue;

                if (current == '"') {

                    string text = "\"";
                    i++;

                    while (i < lineText.size() && lineText[i] != '"') {
                        text = text + lineText[i];
                        i++;
                    }

                    text = text + "\"";
                    cout << "String -> " << text << endl;
                }
                else {
                    if (current == '=' || current == '<' || current == '>') {
                        cout << "Operator -> " << current << endl;
                    }
                    else {
                        cout << "Symbol -> " << current << endl;
                    }
                }
            }
        }

        if (token.length() > 0) {

            if (token == "int" || token == "return") {
                cout << "Keyword -> " << token << endl;
            }
            else if (token[0] >= '0' && token[0] <= '9') {
                cout << "Number -> " << token << endl;
            }
            else {
                cout << "Identifier -> " << token << endl;
            }
        }
    }

    fin.close();
    return 0;
}
