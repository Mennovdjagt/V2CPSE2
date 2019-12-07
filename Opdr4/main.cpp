#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

int main( int argc, char *argv[] ){

  std::string word;
  std::vector<char*> tekst;

  std::ifstream myFile("tekst.txt");

  while(myFile >> word){
      for(unsigned int i = 0; i < word.length(); i++){
          tekst.push_back(&word[i]);
      }
  }

  std::cout << "aantal characters: " << tekst.size() << std::endl;

  std::ifstream lines("tekst.txt");

  std::cout << "aantal regels: " << std::count(std::istreambuf_iterator<char>(lines), 
                     std::istreambuf_iterator<char>(), '\n') + 1 << std::endl;

}