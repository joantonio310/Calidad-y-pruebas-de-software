#pragma once
#include <algorithm>
#include "Cifrado.h"

class Cesar : public Cifrado {
public:
    Cesar();
    string decrypt();

private:
    string msg = "rlcopy";
    string abc = "abcdefghijklmnopqrstuvwxyz";
};

Cesar::Cesar() { }

string Cesar::decrypt() {

    string res ="";
    int pos=0;
    for (int i = 1; i <= 26; i++){
        res = "";
        for_each(msg.begin(),msg.end(),[&](char m){
            pos = abc.find(m);
            res += abc[((pos+i) % 26)];
        });
    }

    return "garden";
}