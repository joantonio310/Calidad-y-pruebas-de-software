#include <iostream>
#include <fstream>
using namespace std;
string rotate(string word);
bool searchFile(string word);

int main(int argc, char * argv[])
{

    string key = "RLCOPY";
    bool found = false;
    int count = 0;
    cout << "comparo..." << endl;
    while(count < 28)
    {

        if(searchFile(key))
        {
            found = true;
            break;
        }
        key = rotate(key);
        ++count;
    }
    if(found)
    {
        cout << "encontrado!" << endl;
        cout << "llave-> " << key << endl;
    }

    return 0;
}

bool searchFile(string word)
{
    fstream file;
    file.open("diccionario.txt", fstream::in);
    string line;
    while(getline(file, line))
    {
        if(word.compare(line) == 0)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

string rotate(string word)
{
    for(int i = 0; i < word.length(); ++i)
    {
        word[i] = (char)((((int)word[i] + 1 - 65) % 26) + 65);
    }
    return word;
}