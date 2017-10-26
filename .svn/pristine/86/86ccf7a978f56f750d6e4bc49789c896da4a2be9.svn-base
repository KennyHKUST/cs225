/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of "StringTriples" (a typedef'd std::tuple, see top of
 * cartalk_puzzle.h). Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<StringTriple> cartalk_puzzle(PronounceDict d,
                                    const string& word_list_fname)
{
    /* Your code goes here! */
    vector<StringTriple> result;

    ifstream wordsFile(word_list_fname);
	string word;
	if (wordsFile.is_open()) {
    /* Reads a line from `wordsFile` into `word` until the file ends. */
    	while (getline(wordsFile, word)) {
    		if(word.length() != 5)
    			continue;
        	string word1 = word;
        	word.erase(0, 1);
        	if(d.homophones(word1, word)){
        		string word2;
        		word2.append(word1.begin(), word1.begin() + 1);
        		word2.append(word.begin() + 1, word.end());
        		if(d.homophones(word1, word2)){
        			//add into tuples and vector
        			StringTriple answer;
        			std::get<0>(answer) = word1; 
					std::get<1>(answer) = word;
					std::get<2>(answer) = word2;
        			result.push_back(answer);
        		}
        	}
    	}
	}

    return result;
}
