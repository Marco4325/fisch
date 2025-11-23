#pragma once
#include <filesystem>

class file_verifier{
    public:
        static bool verify_if_txt( std::filesystem::path file_path );
};