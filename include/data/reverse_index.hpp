#pragma once

#include <unordered_map>
#include <forward_list>
#include <string>
#include <vector>
#include <filesystem>

class reverse_index{
    private:
        std::unordered_map<std::string, std::forward_list<u_int32_t>> data_storage;

        std::forward_list<u_int32_t> read_IDs_from_word( std::string word );

    public:
        void save_word_to_id_from_txt_files( std::vector<std::filesystem::path> path_to_files );
        std::unordered_map<std::string, std::forward_list<u_int32_t>> get_data();
        void save_data( std::unordered_map<std::string, std::forward_list<u_int32_t>> _data );
        std::vector<std::string> retrieve_file_names_by_word( std::string _word, std::vector<std::filesystem::path> path_to_files );
};