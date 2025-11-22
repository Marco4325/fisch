#pragma once
#include <filesystem>
#include <string>
#include <vector>

class directory_file_retriever{
    private:
        std::filesystem::path directory_path;
    public:
        directory_file_retriever( std::filesystem::path _path );
        std::vector<std::filesystem::path> retrieve_path_to_txt_files();

};