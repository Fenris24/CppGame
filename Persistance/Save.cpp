//
// Created by francisc on 8/28/24.
//

#include "Save.hpp"
#include <fstream>
#include <iostream>
#include <cstdio>

void Save::createSave(const std::string& fileName, Data &data) {
    std::ofstream saveFile(fileName, std::ios::binary);
    if (saveFile.is_open()) {
        saveFile.write((char*)&data, sizeof(Data));
        saveFile.close();
        std::cout << "Data saved successfully.\n";
    } else {
        std::cout << "Could not open file for writing.\n";
    }
}

void Save::loadSave(const std::string& fileName, Data &data) {
    std::ifstream saveFile(fileName, std::ios::binary);
    if (saveFile.is_open()) {
        saveFile.read((char*)&data, sizeof(Data));
        if(saveFile) {
            std::cout << "Data loaded successfully.\n";
        } else {
            std::cout << "Failed to load data. File may be corrupted or incomplete.\n";
        }
        saveFile.close();
    } else {
        std::cout << "Could not open file for reading.\n";
    }
}

void Save::updateSave(const std::string& fileName, Data &data) {
    std::ofstream saveFile(fileName, std::ios::binary);
    if (saveFile.is_open()) {
        saveFile.write((char*)&data, sizeof(Data));
        saveFile.close();
        std::cout << "Data updated successfully.\n";
    } else {
        std::cout << "Could not open file for writing.\n";
    }
}

void Save::deleteSave(const std::string& fileName) {
    if (remove(fileName.c_str()) == 0) {
        std::cout << "File deleted successfully." << std::endl;
    } else {
        std::perror("Error deleting file");
    }
}

