#include "../../include/data/reverse_index.hpp"
#include "../../include/file/file_processor.hpp"
#include <string>
#include <iostream>

void reverse_index::save_word_to_id_from_txt_files( std::vector<std::filesystem::path> path_to_files ){
    file_processor fp("/workspaces/fisch/stop_words.txt");

    for(int i = 0; i < path_to_files.size(); i++){
        std::vector<std::string> words = fp.process_words_from_file( path_to_files[i] );
        
        for(std::string word : words){
            auto value_returned = this->data_storage.find(word);
            
            if(value_returned == this->data_storage.end()) { // VALOR NÃO EXISTE
                this->data_storage[word].insert(i);
            }else{
                this->data_storage.at(word).insert(i);
            }
            
        }
    }

}

std::unordered_map<std::string, std::unordered_set<u_int>> reverse_index::get_data(){
    return this->data_storage;
}