#include "../../include/directory/directory_scanner.hpp"
#include "../../include/file/file_verifier.hpp"
#include <iostream>
#include <stdexcept>

bool directory_scanner::path_exist( std::filesystem::path _path ){
bool is_valid = true;

    if( !(std::filesystem::exists( _path )) ){
        std::cout << "ERROR: Path doesn't exist!\n";
        is_valid = false;
    }

    if( !(std::filesystem::is_directory( _path )) ){
        std::cout << "ERROR: Path isn't a directory!\n";
        is_valid = false;
    }

    if(!is_valid) { std::cout << "\n"; return false;}

    return true;
}

std::vector<std::filesystem::path> directory_scanner::retrieve_path_to_txt_files( std::filesystem::path _path ){
    if(!path_exist(_path)){ throw std::runtime_error("ERROR: Path doesn't exist!"); }
    
    std::vector<std::filesystem::path> vector_of_paths;
    for( const auto &entry : std::filesystem::directory_iterator(_path) )
        if(file_verifier::verify_if_txt(entry.path()))
            vector_of_paths.push_back(entry.path());
    
    if(vector_of_paths.size() == 0){ std::cout << "INFO: There's no .txt file in the specified directory\n\n";}
    return vector_of_paths;
}