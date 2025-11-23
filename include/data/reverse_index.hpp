#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <filesystem>

class reverse_index{
    private:
        std::unordered_map<std::string, std::unordered_set<u_int>> data_storage;

    public:
        void save_word_to_id_from_txt_files( std::vector<std::filesystem::path> path_to_files );
        std::unordered_map<std::string, std::unordered_set<u_int>> get_data();
};