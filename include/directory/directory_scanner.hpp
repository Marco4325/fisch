#pragma once
#include <filesystem>
#include <string>

class directory_scanner{
    private:
        std::filesystem::path directory_path;

    public:
        directory_scanner( std::filesystem::path _path );
        bool scan_for_txt();

};