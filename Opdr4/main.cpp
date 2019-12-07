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
          std::cout << word[i] << std::endl;
      }
  }

  std::cout << std::endl;

  std::cout << "aantal characters: " << tekst.size() << std::endl;

  std::ifstream lines("tekst.txt");

  std::cout << "aantal regels: " << std::count(std::istreambuf_iterator<char>(lines), 
                     std::istreambuf_iterator<char>(), '\n') + 1 << std::endl;

  std::cout << std::count_if(tekst.begin(), tekst.end(), [](char c){ return std::isalpha(c); }) << std::endl;
  std::cout << std::count_if(tekst.begin(), tekst.end(), [](char c){ return std::isdigit(c); }) << std::endl;

}