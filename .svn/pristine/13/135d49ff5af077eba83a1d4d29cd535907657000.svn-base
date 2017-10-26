/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
    ifstream wordsFile(filename);
	string w;
	vector<string> words;
	if (wordsFile.is_open()) {
    /* Reads a line from `wordsFile` into `word` until the file ends. */
   		while (getline(wordsFile, w)) {
        	words.push_back(w);
    	}
	}
	for(auto & singleword: words){
		auto lookup = dict.find(singleword);
		if(lookup == dict.end()){
			vector<char> charVector;
			for(unsigned long i = 0; i < singleword.length(); i++)
				charVector.push_back(singleword[i]);
			std::sort(charVector.begin(), charVector.end());
			dict.insert(std::pair<string, vector<char>>(singleword, charVector));
		}
	}
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
    for(unsigned long i = 0; i < words.size(); i++){
    	auto lookup = dict.find(words[i]);
    	if(lookup == dict.end()){
    		vector<char> charVector;
    		for(unsigned long j = 0; j < words[i].length(); j++)
				charVector.push_back(words[i][j]);
			std::sort(charVector.begin(), charVector.end());
			dict.insert(std::pair<string, vector<char>>(words[i], charVector));
    	}
    }
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
    auto lookup = dict.find(word);
    if(lookup == dict.end())
    	return vector<string>();
    vector<string> anagram;
    int i = 0;
    for(auto & key_val: dict){
    	if(key_val.first == lookup->first)
    		continue;
    	if(key_val.second == lookup->second){
    		if(i == 0)
    			anagram.push_back(lookup->first);
    		anagram.push_back(key_val.first);
    		i++;
    	}
    }
    return anagram;
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
    vector<vector<string>> result;
    for(auto & key_val: dict){
    	vector<string> anagram = get_anagrams(key_val.first);
    	if(anagram.size() > 1)
    		result.push_back(anagram);
    }
    return result;
}
