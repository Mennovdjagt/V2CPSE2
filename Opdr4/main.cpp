#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <unordered_set>

int main( int argc, char *argv[] ){

  std::string word;                               //buffer to save a word temporary
  std::vector<char> tekst;                        //dynamic array to save all the characters out of the file in
  std::vector< std::pair<int,char> > vect;        //holds how many times an alphabetical character is counted in the tekst   

  std::ifstream myFile( "tekst.txt" );

  while( myFile >> word ){                                          //puts all the words in the file in a string (overwrites)   
      for( unsigned int i = 0; i < word.length(); i++ ){            //loops through the length of the word and pushes every character into the vector
          tekst.push_back( word[i] );
      }
      tekst.push_back(' ');
  }

  std::cout << "aantal characters: \t" << tekst.size() << std::endl;                                                  //reads the size using 

  std::ifstream lines( "tekst.txt" );                                                                                 //must be made, because otherwise it will return 0 lines (myFile is already used to read)

  std::cout << "aantal regels: \t\t" << std::count(std::istreambuf_iterator<char>(lines), 
                     std::istreambuf_iterator<char>(), '\n') + 1 << std::endl;                                                                        //counts all lines

  std::cout << "aantal letters: \t"       << std::count_if(tekst.begin(), tekst.end(), [](char c){ return std::isalpha(c); }) << '\n';                //counts the characters if they are alpha
  std::cout << "aantal hoofdletters: \t"  << std::count_if(tekst.begin(), tekst.end(), [](char c){ return std::isupper(c); }) << '\n';                //counts the characters if they are uppercase
  std::cout << "aantal cijfers: \t"       << std::count_if(tekst.begin(), tekst.end(), [](char c){ return std::isdigit(c); }) << "\n\n";              //counts all the digits

  for_each(tekst.begin(), tekst.end(), [](char&c){ if(std::isdigit(c)){ c = ((int)c + 49); } });                                                      //changes all the digits to characters

  for_each(tekst.begin(), tekst.end(), [](char&c){ if(std::isupper(c)){ c = std::tolower(c); } }); 

  for( uint i = 0; i < tekst.size(); i++ ){                                     //prints the newly changed vector (should be without the digits)
      std::cout << tekst.at(i);
  }

  std::cout << "\n\n";   

  std::string alphabet = "abcdefghijklmnopqrstuvwxyz";                          //string with all the alphabetical letters, as check for the occurance check

  for( auto p : alphabet ){                                                     //loops through every letter in the alphabet
      int count = std::count( tekst.begin(), tekst.end(), p );                  //counts the occurance of a alphabetically char
      vect.push_back(std::make_pair(count, p));                                 //puts the occurance and the letter in a pair and that in a vector
  }

  for( auto p : vect ){                                                         //prints it on alphabetical order
      std::cout << p.second << " : " << p.first << '\n';
  }

  std::cout << '\n';

  std::sort(vect.begin(), vect.end());                                          //sorts the vector on occurance(less first, biggest last)

  for( auto p : vect ){                                                         //prints the newly ordered vector
      std::cout << p.second << " : " << p.first << '\n';
  }


  std::vector<std::string> words;                                   //holds all the words that are in the tekst after changing uppercase to lower and digit to alpha
  std::unordered_set<std::string> uniqueSet;                        //a list that can only hold unique values (saves the word)  
  std::string buf = "";                                             //a buffer string that holds multiple char objects, that create a word

  //makes from a vector of char's a new vector with words
  for_each(tekst.begin(), tekst.end(), [&buf, &words](char c){ if(c==' '||c=='\0'){ words.push_back(buf); buf = ""; }else{ buf+=c; } }); 
  for_each(words.begin(), words.end(), [&uniqueSet](std::string s){ uniqueSet.insert(s); });

  for( auto p : words ){
      std::cout << p << '\n';
  }


  std::cout << std::endl;

  std::map<std::string, int> occurance;

  for_each(uniqueSet.begin(), uniqueSet.end(), [&words, &occurance](std::string s){ occurance[s] = std::count(words.begin(), words.end(), s); });


  for( auto p : occurance ){
      std::cout << p.first << " " << p.second << '\n';
  }


}