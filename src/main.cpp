#include "../include/directory/directory_scanner.hpp"
#include "../include/file/file_processor.hpp"
#include "../include/data/reverse_index.hpp"
#include "../include/data/serializer.hpp"
#include "../include/data/deserializer.hpp"

#include <filesystem>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main(int argc, char* argv[]){
    reverse_index ri;
    
    if(std::string(argv[1]) == "construir" || std::string(argv[1]) == "build"){
        std::filesystem::path given_path = argv[2];
        ri.save_word_to_id_from_txt_files(directory_scanner::retrieve_path_to_txt_files(given_path));
        
        auto hash_table = ri.get_data();
        serializer::serialize(hash_table, directory_scanner::retrieve_path_to_txt_files(given_path));
    }
    
    if(std::string(argv[1]) == "buscar" || std::string(argv[1]) == "search"){
        auto deserialized_data = deserializer::deserialize();
        
        std::vector<std::filesystem::path> path_to_files = deserialized_data.path_to_files;

        auto hash_table = deserialized_data.reverse_index;

        std::vector<std::forward_list<u_int32_t>> files_id;
        for(int i = 2; i < argc; i++){
            files_id.push_back(hash_table[argv[i]]);
        }

        if(files_id.size() == 0){
            std::cout << "INFO: No file with word(s)!";
            return -1;
        }

        std::vector<uint32_t> final_files;
        if(files_id.size() == 1){
            for(u_int32_t id : files_id[0])
                final_files.push_back(id);
        }else{
            for(uint32_t id : files_id[0]){
                for(int i = 1; i < files_id.size(); i++){
                    auto f = files_id[i];
                    auto it = std::find(f.begin(), f.end(), id);
                    if(it != f.end()){
                        final_files.push_back(id);
                    }
                }
            }
        }

        for(uint32_t id : final_files){
            auto file = path_to_files[id - 1];
            std::cout << file << "\n";
        }

    }

return 0;}