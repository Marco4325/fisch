#pragma once
#include <unordered_map>
#include <forward_list>
#include <string>
#include <filesystem>
#include <vector>

struct deserialized_data {
    std::vector<std::filesystem::path> path_to_files;
    std::unordered_map<std::string, std::forward_list<u_int>> reverse_index;
};

class deserializer{
    private:
        

    public:
        static deserialized_data deserialize();
};