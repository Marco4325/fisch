#include "../../include/file/file_verifier.hpp"

bool file_verifier::verify_if_txt( std::filesystem::path file_path ){
    if( file_path.extension().string() == ".txt" )
        return true;
    return false;
}