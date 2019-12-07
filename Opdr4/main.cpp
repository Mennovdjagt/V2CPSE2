#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

int main( int argc, char *argv[] ){

  std::string word;
  std::vector<char> tekst;

  std::ifstream myFile("tekst.txt");

  while(myFile >> word){
      for(unsigned int i = 0; i < word.length(); i++){
          tekst.push_back(word[i]);
      }
  }

  std::cout << "aantal characters: \t" << tekst.size() << std::endl;                                                  //reads the size using 

  std::ifstream lines("tekst.txt");                                                                                 //must be made, because otherwise it will return 0 lines (myFile is already used to read)

  std::cout << "aantal regels: \t\t" << std::count(std::istreambuf_iterator<char>(lines), 
                     std::istreambuf_iterator<char>(), '\n') + 1 << std::endl;                                      //counts all lines

  std::cout << "aantal letters: \t" << std::count_if(tekst.begin(), tekst.end(), [](char c){ return std::isalpha(c); }) << std::endl;       //counts the characters if they are alpha
  std::cout << "aantal cijfers: \t" << std::count_if(tekst.begin(), tekst.end(), [](char c){ return std::isdigit(c); }) << std::endl;

  for_each(tekst.begin(), tekst.end(), [](char&c){ if(std::isdigit(c)){ c = ((int)c + 49); } });

  for(unsigned int i = 0; i < tekst.size(); i++){
      std::cout << tekst.at(i);
  }

  std::cout << std::endl;

}