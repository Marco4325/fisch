#include "../../include/data/serializer.hpp"
#include <fstream>

void serializer::serialize( std::unordered_map<std::string, std::forward_list<u_int>> reverse_index, std::vector<std::filesystem::path> path_to_files ){
    std::fstream file("./index.dat", std::ios::binary | std::ios::trunc | std::ios::out );

    u_int32_t path_to_files_size = path_to_files.size();
    file.write(reinterpret_cast<const char*>(&path_to_files_size), sizeof(u_int32_t));

    for( std::string path : path_to_files ){
        uint32_t path_size = path.size();

        file.write(reinterpret_cast<const char*>(&path_size), sizeof(uint32_t));
        file.write(path.data(), path_size);
    }

    u_int32_t bucket_size = reverse_index.size();
    file.write(reinterpret_cast<const char*>(&bucket_size), sizeof(u_int32_t));

    for( const auto& pair : reverse_index ){

        u_int32_t word_size = pair.first.size();
        file.write(reinterpret_cast<const char*>(&word_size), sizeof(u_int32_t));
        for( char ch : pair.first){
            file.write(reinterpret_cast<const char*>(&ch), sizeof(char));
        }

        u_int32_t list_of_IDs_size = std::distance(pair.second.begin(), pair.second.end());
        file.write(reinterpret_cast<const char*>(&list_of_IDs_size), sizeof(u_int32_t));        
        for( const auto& IDs : pair.second ){
            file.write(reinterpret_cast<const char*>(&IDs), sizeof(u_int32_t));
        }
    }
}