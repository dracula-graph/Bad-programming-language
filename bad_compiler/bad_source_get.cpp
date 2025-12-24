#include <iostream>
#include <fstream>
#include <vector>

#include "bad_source_get.h"

std::vector<std::string> get_source_data(std::string& file_path){
    std::fstream file;
    std::vector<std::string> file_data;
    file.open(file_path);
    if (file.is_open()) {
        std::string data_line;
        while (std::getline(file, data_line)) {
            file_data.push_back(data_line);
        }
    } else {
        std::cout << "file not found" << std::endl;
    }

    return file_data;
}
