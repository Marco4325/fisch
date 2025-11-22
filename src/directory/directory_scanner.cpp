#include "../../include/directory/directory_scanner.hpp"
#include <iostream>

directory_scanner::directory_scanner( std::filesystem::path _path ){
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

bool directory_scanner::scan_for_txt(){
    
    for(const auto &entry : std::filesystem::directory_iterator(this->directory_path)){
        if( entry.path().extension().string() == ".txt" )
            return true;
    }

    return false;
}