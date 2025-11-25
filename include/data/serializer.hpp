#pragma once
#include <unordered_map>
#include <forward_list>
#include <string>
#include <filesystem>
#include <vector>

class serializer{
    public:
        static void serialize( std::unordered_map<std::string, std::forward_list<u_int>> reverse_index, std::vector<std::filesystem::path> path_to_files );
};