#pragma once
#include <filesystem>
#include <vector>

class directory_scanner{
    private:
        static bool path_exist( std::filesystem::path _path );

    public:
        static std::vector<std::filesystem::path> retrieve_path_to_txt_files( std::filesystem::path _path );

};