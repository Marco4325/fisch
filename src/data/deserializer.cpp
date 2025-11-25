#include "../../include/data/deserializer.hpp"
#include <fstream>

deserialized_data deserializer::deserialize(){
    
    deserialized_data data;

    std::unordered_map<std::string, std::forward_list<u_int>> reverse_index;
    std::fstream file("./index.dat", std::ios::binary | std::ios::in );

    uint32_t path_to_files_size = 0;
    file.read(reinterpret_cast<char*>(&path_to_files_size), sizeof(uint32_t));

    for(int i = 0; i < path_to_files_size; i++){
        
        uint32_t path_size = 0;
        file.read(reinterpret_cast<char*>(&path_size), sizeof(uint32_t));

        std::string path(path_size, '\0'); 
        file.read(&path[0], path_size);

        data.path_to_files.push_back(path);
    }

    uint32_t bucket_size = 0;
    file.read(reinterpret_cast<char*>(&bucket_size), sizeof(uint32_t));

    for (uint32_t i = 0; i < bucket_size; i++)
    {
        uint32_t word_size = 0;
        file.read(reinterpret_cast<char*>(&word_size), sizeof(uint32_t));

        std::string word(word_size, '\0'); 
        file.read(&word[0], word_size);

        uint32_t list_of_IDs_size = 0;
        file.read(reinterpret_cast<char*>(&list_of_IDs_size), sizeof(uint32_t));

        std::forward_list<u_int> list_of_temporary_IDs;

        for (uint32_t j = 0; j < list_of_IDs_size; j++)
        {
            uint32_t ID;
            file.read(reinterpret_cast<char*>(&ID), sizeof(uint32_t));
            list_of_temporary_IDs.push_front(ID); // push_front é mais eficiente
        }

        list_of_temporary_IDs.reverse();
        data.reverse_index.emplace(std::move(word), std::move(list_of_temporary_IDs));
    }

    return data;
}