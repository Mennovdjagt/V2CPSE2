#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <array>
#include <map>

int main( int argc, char *argv[] ){

  std::string word;                               //buffer to save a word temporary
  std::vector<char> tekst;                        //dynamic array to save all the characters out of the file in
  std::map<uint, uint> digits;    //to save the amount of digits that will be counted (on key)     

  std::ifstream myFile( "tekst.txt" );

  while( myFile >> word ){                                          //puts all the words in the file in a string (overwrites)
      for( unsigned int i = 0; i < word.length(); i++ ){            //loops through the length of the word and pushes every character into the vector
          tekst.push_back( word[i] );
      }
  }

  std::cout << "aantal characters: \t" << tekst.size() << std::endl;                                                  //reads the size using 

  std::ifstream lines( "tekst.txt" );                                                                                 //must be made, because otherwise it will return 0 lines (myFile is already used to read)

  std::cout << "aantal regels: \t\t" << std::count(std::istreambuf_iterator<char>(lines), 
                     std::istreambuf_iterator<char>(), '\n') + 1 << std::endl;                                        //counts all lines

  std::cout << "aantal letters: \t" << std::count_if(tekst.begin(), tekst.end(), [](char c){ return std::isalpha(c); }) << std::endl;               //counts the characters if they are alpha
  std::cout << "aantal cijfers: \t" << std::count_if(tekst.begin(), tekst.end(), [](char c){ return std::isdigit(c); }) << "\n" << std::endl;       //counts all the digits

  //for_each(tekst.begin(), tekst.end(), [](char&c){ if(std::isdigit(c)){ c = ((int)c + 49); } });                      //changes all the digits to characters

  for( uint i = 0; i < tekst.size(); i++ ){                                     //prints the newly changed vector (should be without the digits)
      std::cout << tekst.at(i);
  }

  std::cout << "\n\n";

  for(uint i = 0; i < 10; i++){                                                 //fills the map with 0's
      digits.insert(std::pair<char,int>( i, 0 ) );
  }            

  for( auto p : tekst ){                                                        //loops through all the characters looking for digits to count
      if( std::isdigit(p) ){         
          unsigned int x = digits.at((int)(p-'0'));                             // -'0' is because the char for 0-9 is a different number in the ASCII table
          digits.at((int)(p-'0')) = x+1;
      }
  }

  for(auto &p : digits){                                                        //print all the numbers with there corresponding amount (not sorted yet)
      std::cout << p.first << ":" << p.second << std::endl;
  }



  std::cout << std::endl;

}