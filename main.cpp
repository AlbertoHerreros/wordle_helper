/* 
 * File:   main.cpp
 * Author: Alberto Herreros Magaña
 *
 * Created on 24 de diciembre de 2022, 12:50
 */
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

void seeList(std::vector<std::string> words);
std::vector<std::string> lengthFilter(std::vector<std::string> words, int length);
std::vector<std::string> letterPositionFilter(std::vector<std::string> words, int position, char c);
std::vector<std::string> letterNotExistsFilter(std::vector<std::string> words, char c);
std::vector<std::string> letterExistsFilter(std::vector<std::string> words, char c);

int main(int argc, char** argv) {

    std::string fileName = "diccionario.txt";
    std::ifstream file( fileName.c_str() );
    std::string line;
    
    std::vector<std::string> words;
    std::vector<std::string> filteredWords;
    
    //Read the entire input
    while(getline(file,line))
        words.push_back(line);
    
    int option = 1;
    int length;
    int position;
    char c;
    
    while(option != 0){
        std::cout << "---------------------------------------------------------" << std::endl;
        std::cout << "Option 1: see possible words that could be the final word." << std::endl;
        std::cout << "Option 2: filter by word's length." << std::endl;
        std::cout << "Option 3: position and character guessed." << std::endl;
        std::cout << "Option 4: doesn't contain character." << std::endl;
        std::cout << "Option 5: contains character." << std::endl;
        std::cout << "---------------------------------------------------------" << std::endl;
        std::cin >> option;
        switch(option){
            case 1:
                seeList(words);
                break;
            case 2:
                std::cout << "Specify word's length:" << std::endl;
                std::cin >> length;
                words = lengthFilter(words,length);
                break;  
            case 3:
                std::cout << "Specify character position:" << std::endl;
                std::cin >> position;
                std::cout << "Specify character:" << std::endl;
                std::cin >> c;
                words = letterPositionFilter(words,position,c);
                break;
            case 4:
                std::cout << "Specify character that doesn't exists:" << std::endl;
                std::cin >> c;
                words = letterNotExistsFilter(words,c);
                break;
            case 5:
                std::cout << "Specify character that exists (you don't know it's position):" << std::endl;
                std::cin >> c;
                words = letterExistsFilter(words,c);
                break;
        }
    }    
    return 0;
}

void seeList(std::vector<std::string> words){
    for (auto& it : words) 
        std::cout << it << std::endl;
}

std::vector<std::string> lengthFilter(std::vector<std::string> words, int length){
    std::vector<std::string> filteredWords;
    for( int i = 0; i < words.size(); i++ )
        if( words[i].length() == length )
            filteredWords.push_back(words[i]);
    return filteredWords;
}

std::vector<std::string> letterPositionFilter(std::vector<std::string> words, int position, char c){
    std::vector<std::string> filteredWords;
    for( int i = 0; i < words.size(); i++ )
        if( words[i][position-1] == c )
            filteredWords.push_back(words[i]);
    return filteredWords;
}

std::vector<std::string> letterNotExistsFilter(std::vector<std::string> words, char c){
    std::vector<std::string> filteredWords;
    bool valid;
    for( int i = 0; i < words.size(); i++ ){
        valid = true;
        for( int j = 0; j < words[i].length(); j++ )
            if( words[i][j] == c )
                valid = false;
        if( valid )
            filteredWords.push_back(words[i]);
    }
    return filteredWords;
}

std::vector<std::string> letterExistsFilter(std::vector<std::string> words, char c){
    std::vector<std::string> filteredWords;
    bool valid;
    for( int i = 0; i < words.size(); i++ ){
        valid = false;
        for( int j = 0; j < words[i].length(); j++ )
            if( words[i][j] == c )
                valid = true;
        if( valid )
            filteredWords.push_back(words[i]);
    }
    return filteredWords;
}