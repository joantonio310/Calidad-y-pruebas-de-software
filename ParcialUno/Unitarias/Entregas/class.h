#include <string>
#include <iostream>
#include <fstream>

class Base
{
public:
    virtual std::string decrypt(std::string _key) = 0;
    virtual ~Base() {}
};

class Cesar : public Base
{
public:
    std::string decrypt(std::string _key)
    {
        bool found = false;
        int count = 0;
        std::cout << "searching..." << std::endl;
        while(count < 28)
        {
            if(searchFile(_key))
            {
                found = true;
                break;
            }
            _key = rotate(_key);
            ++count;
        }
        if(found)
        {
            return _key;
        }
        else
        {
            return "no aparece...";
        }
    }

    bool searchFile(std::string word)
    {
        std::fstream file;
        file.open("diccionario.txt", std::fstream::in);
        std::string line;
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

    std::string rotate(std::string word)
    {
        for(int i = 0; i < word.length(); ++i)
        {
            word[i] = (char)((((int)word[i] + 1 - 65) % 26) + 65);
        }
        return word;
    }
};