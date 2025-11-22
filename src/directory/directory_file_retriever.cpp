#include "../../include/directory/directory_file_retriever.hpp"
#include <iostream>

directory_file_retriever::directory_file_retriever( std::filesystem::path _path ){
    bool is_valid = true;

    if( !(std::filesystem::exists( _path )) ){
        std::cout << "ERROR: Path doesn't exist!\n";
        is_valid = false;
    }

    if( !(std::filesystem::is_directory( _path )) ){
        std::cout << "ERROR: Path isn't a directory!\n";
        is_valid = false;
    }

    if(!is_valid) { std::cout << "\n"; return;}

    this->directory_path = _path;
}

std::vector<std::filesystem::path> directory_file_retriever::retrieve_path_to_txt_files(){
    std::vector<std::filesystem::path> vector_of_paths;
    for( const auto &entry : std::filesystem::directory_iterator(this->directory_path) )
        if(entry.path().extension().string() == ".txt")
            vector_of_paths.push_back(entry.path());
    
    return vector_of_paths;
}