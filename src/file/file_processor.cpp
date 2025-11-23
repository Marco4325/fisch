#include "../../include/file/file_processor.hpp"
#include <fstream>
#include <cctype>

file_processor::file_processor( std::filesystem::path path_to_stop_words ){
    load_stop_words(path_to_stop_words);
}



void file_processor::load_stop_words( std::filesystem::path path_to_stop_words ){
    std::ifstream file(path_to_stop_words);
    std::string word;

    while(file >> word)
        this->stop_words.push_back(convert_to_lower_case(word));
}



std::vector<std::string> file_processor::process_words_from_file( std::filesystem::path path_to_file ){
    std::ifstream file(path_to_file);
    std::vector<std::string> words_from_file;
    std::string word;

    while(file >> word){
        std::string lowered_word = convert_to_lower_case(word);
        if(!check_if_punctuation(lowered_word) && !check_if_stop_word(lowered_word))
            words_from_file.push_back(convert_to_lower_case(lowered_word));
    }

    return words_from_file;
}



bool file_processor::check_if_punctuation( std::string _word ){
    
    for(auto ch : _word)
        if(ch >= 0x61 && ch <= 0x7A || ch >= 0x41 && ch <= 0x5A)
            return false;
    
    return true;
}



bool file_processor::check_if_stop_word( std::string _word ){
    
    for(std::string word : this->stop_words)
        if(word == _word)
            return true;
    
    return false;
}



std::string file_processor::convert_to_lower_case( std::string _word ){
    std::string lowered_word;

    for(auto ch : _word){
        if(ch >= 0x41 && ch <= 0x5A)
            ch += 32;
        lowered_word.push_back(ch);
    }

    return lowered_word;
}