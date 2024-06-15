
#ifndef BIN_SERI_H
#define BIN_SERI_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>

namespace BinSerialization {

// 序列化函数模板
template<typename T>
void serialize(const T& obj, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        throw std::runtime_error("Cannot open file for writing");
    }
    ofs.write(reinterpret_cast<const char*>(&obj), sizeof(T));
}

// 反序列化函数模板
template<typename T>
void deserialize(T& obj, const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        throw std::runtime_error("Cannot open file for reading");
    }
    ifs.read(reinterpret_cast<char*>(&obj), sizeof(T));
}

// 为std::string类型特化的序列化函数
void serialize(const std::string& str, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        throw std::runtime_error("Cannot open file for writing");
    }
    size_t size = str.size();
    ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));
    ofs.write(str.data(), size);
}

// 为std::string类型特化的反序列化函数
void deserialize(std::string& str, const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        throw std::runtime_error("Cannot open file for reading");
    }
    size_t size;
    ifs.read(reinterpret_cast<char*>(&size), sizeof(size));
    str.resize(size);
    ifs.read(&str[0], size);
}

// 序列化 std::vector<T> 的通用版本
template<typename T>
void serialize(const std::vector<T>& obj, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        throw std::runtime_error("Cannot open file for writing");
    }
    size_t size = obj.size();
    ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (const T& element : obj) {
        ofs.write(reinterpret_cast<const char*>(&element), sizeof(T));
    }
}

// 反序列化 std::vector<T> 的通用版本
template<typename T>
void deserialize(std::vector<T>& obj, const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        throw std::runtime_error("Cannot open file for reading");
    }
    size_t size;
    ifs.read(reinterpret_cast<char*>(&size), sizeof(size));
    obj.resize(size);
    for (size_t i = 0; i < size; ++i) {
        T element;
        ifs.read(reinterpret_cast<char*>(&element), sizeof(T));
        obj[i] = element;
    }
}

template<typename T>
void serialize(const std::set<T>& obj, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        throw std::runtime_error("Cannot open file for writing");
    }
    size_t size = obj.size();
    ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (const T& element : obj) {
        ofs.write(reinterpret_cast<const char*>(&element), sizeof(T));
    }
}

// 反序列化 std::set<T> 的特化版本
template<typename T>
void deserialize(std::set<T>& obj, const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        throw std::runtime_error("Cannot open file for reading");
    }
    size_t size;
    ifs.read(reinterpret_cast<char*>(&size), sizeof(size));
    for (size_t i = 0; i < size; ++i) {
        T element;
        ifs.read(reinterpret_cast<char*>(&element), sizeof(T));
        obj.insert(element);
    }
}

// 序列化 std::list<T> 的特化版本
template<typename T>
void serialize(const std::list<T>& obj, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        throw std::runtime_error("Cannot open file for writing");
    }
    size_t size = obj.size();
    ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (const T& element : obj) {
        ofs.write(reinterpret_cast<const char*>(&element), sizeof(T));
    }
}

// 反序列化 std::list<T> 的特化版本
template<typename T>
void deserialize(std::list<T>& obj, const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        throw std::runtime_error("Cannot open file for reading");
    }
    size_t size;
    ifs.read(reinterpret_cast<char*>(&size), sizeof(size));
    for (size_t i = 0; i < size; ++i) {
        T element;
        ifs.read(reinterpret_cast<char*>(&element), sizeof(T));
        obj.push_back(element);
    }
}

// 序列化 std::pair<T1, T2> 的特化版本
template<typename T1, typename T2>
void serialize(const std::pair<T1, T2>& obj, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        throw std::runtime_error("Cannot open file for writing");
    }
    ofs.write(reinterpret_cast<const char*>(&obj.first), sizeof(T1));
    ofs.write(reinterpret_cast<const char*>(&obj.second), sizeof(T2));
}

// 反序列化 std::pair<T1, T2> 的特化版本
template<typename T1, typename T2>
void deserialize(std::pair<T1, T2>& obj, const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        throw std::runtime_error("Cannot open file for reading");
    }
    ifs.read(reinterpret_cast<char*>(&obj.first), sizeof(T1));
    ifs.read(reinterpret_cast<char*>(&obj.second), sizeof(T2));
}

// 序列化 std::map<Key, Value> 的特化版本
template<typename Key, typename Value>
void serialize(const std::map<Key, Value>& obj, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    if (!ofs) {
        throw std::runtime_error("Cannot open file for writing");
    }
    size_t size = obj.size();
    ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (const auto& pair : obj) {
        ofs.write(reinterpret_cast<const char*>(&pair.first), sizeof(Key));
        ofs.write(reinterpret_cast<const char*>(&pair.second), sizeof(Value));
    }
}

// 反序列化 std::map<Key, Value> 的特化版本
template<typename Key, typename Value>
void deserialize(std::map<Key, Value>& obj, const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) {
        throw std::runtime_error("Cannot open file for reading");
    }
    size_t size;
    ifs.read(reinterpret_cast<char*>(&size), sizeof(size));
    for (size_t i = 0; i < size; ++i) {
        Key key;
        Value value;
        ifs.read(reinterpret_cast<char*>(&key), sizeof(Key));
        ifs.read(reinterpret_cast<char*>(&value), sizeof(Value));
        obj.insert({key, value});
    }
}
}

#endif // BIN_SERI_H
