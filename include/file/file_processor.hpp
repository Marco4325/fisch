#pragma once
#include <vector>
#include <filesystem>
#include <string>

class file_processor{
    private:
        std::vector<std::string> stop_words;
        
        bool check_if_punctuation( std::string word );
        bool check_if_stop_word( std::string word );
        std::string convert_to_lower_case( std::string _word );
        void load_stop_words( std::filesystem::path path_to_stop_words );

        public:
        file_processor( std::filesystem::path path_to_stop_words );
        std::vector<std::string> process_words_from_file( std::filesystem::path path_to_file );
        
};