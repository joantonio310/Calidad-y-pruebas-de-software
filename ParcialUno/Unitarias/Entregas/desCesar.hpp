#include <iostream>
#include <string>
#include <vector>

class desCesar {
public:
  std::string descypher(std::string w,std::vector<std::string> d);

};

std::string desCesar::descypher(std::string w, std::vector<std::string> d)
{
  std::string word = w;
  std::string desWord;
  char c;
  int x = 0;
  for (int i=1; i<27;i++)
  {
    desWord ="";
    for(int j=0; j<word.size(); j++)
    {
      x = word[j]+i;
      if (x>90)
      {
        x -= 26;
      }
      c = x;
      desWord += c;
    }
    std::cout << desWord << std::endl;
    for(int j=0;j<d.size();j++)
    {
      if(desWord == d[j])
      {
        return desWord;
      }
    }
  }
  return "";
}