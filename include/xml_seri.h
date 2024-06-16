// XMLSerializer.h
#ifndef XMLSERIALIZER_H
#define XMLSERIALIZER_H

#include "tinyxml2.h"
#include <utility>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#include <list>

namespace XMLSerializer {

// Serialize function
template<typename T1, typename T2>
void serialize_xml(const std::pair<T1, T2>& pair, const char* name, const char* filename) {
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement* root = doc.NewElement("serialization");
    doc.InsertFirstChild(root);
    tinyxml2::XMLElement* pairElement = doc.NewElement(name);
    root->InsertEndChild(pairElement);

    tinyxml2::XMLElement* firstElement = doc.NewElement("first");
    std::stringstream ssFirst;
    ssFirst << pair.first;
    firstElement->SetAttribute("val", ssFirst.str().c_str());
    pairElement->InsertEndChild(firstElement);

    tinyxml2::XMLElement* secondElement = doc.NewElement("second");
    std::stringstream ssSecond;
    ssSecond << pair.second;
    secondElement->SetAttribute("val", ssSecond.str().c_str());
    pairElement->InsertEndChild(secondElement);

    doc.SaveFile(filename);
}

// Deserialize function
template<typename T1, typename T2>
void deserialize_xml(std::pair<T1, T2>& pair, const char* name, const char* filename) {
    tinyxml2::XMLDocument doc;
    doc.LoadFile(filename);
    tinyxml2::XMLElement* root = doc.FirstChildElement("serialization");
    tinyxml2::XMLElement* pairElement = root->FirstChildElement(name);

    tinyxml2::XMLElement* firstElement = pairElement->FirstChildElement("first");
    std::stringstream ssFirst(firstElement->Attribute("val"));
    ssFirst >> pair.first;

    tinyxml2::XMLElement* secondElement = pairElement->FirstChildElement("second");
    std::stringstream ssSecond(secondElement->Attribute("val"));
    ssSecond >> pair.second;
}

template<typename T>
void serialize_xml(const T& value, const char* name, const char* filename) {
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement* root = doc.NewElement("serialization");
    doc.InsertFirstChild(root);
    tinyxml2::XMLElement* element = doc.NewElement(name);
    root->InsertEndChild(element);

    std::stringstream ss;
    ss << value;
    element->SetAttribute("val", ss.str().c_str());

    doc.SaveFile(filename);
}

// General deserialize function template
template<typename T>
void deserialize_xml(T& value, const char* name, const char* filename) {
    tinyxml2::XMLDocument doc;
    doc.LoadFile(filename);
    tinyxml2::XMLElement* root = doc.FirstChildElement("serialization");
    tinyxml2::XMLElement* element = root->FirstChildElement(name);

    std::stringstream ss(element->Attribute("val"));
    ss >> value;
}

// Specialization for std::map
template<typename K, typename V>
void serialize_xml(const std::map<K, V>& map, const char* name, const char* filename) {
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement* root = doc.NewElement("serialization");
    doc.InsertFirstChild(root);
    tinyxml2::XMLElement* mapElement = doc.NewElement(name);
    root->InsertEndChild(mapElement);

    for (const auto& pair : map) {
        tinyxml2::XMLElement* pairElement = doc.NewElement("pair");
        mapElement->InsertEndChild(pairElement);

        std::stringstream keyStream, valueStream;
        keyStream << pair.first;
        valueStream << pair.second;

        tinyxml2::XMLElement* keyElement = doc.NewElement("key");
        keyElement->SetAttribute("val", keyStream.str().c_str());
        pairElement->InsertEndChild(keyElement);

        tinyxml2::XMLElement* valueElement = doc.NewElement("value");
        valueElement->SetAttribute("val", valueStream.str().c_str());
        pairElement->InsertEndChild(valueElement);
    }

    doc.SaveFile(filename);
}

template<typename K, typename V>
void deserialize_xml(std::map<K, V>& map, const char* name, const char* filename) {
    tinyxml2::XMLDocument doc;
    doc.LoadFile(filename);
    tinyxml2::XMLElement* root = doc.FirstChildElement("serialization");
    tinyxml2::XMLElement* mapElement = root->FirstChildElement(name);

    for (tinyxml2::XMLElement* pairElement = mapElement->FirstChildElement("pair"); 
         pairElement != nullptr; 
         pairElement = pairElement->NextSiblingElement("pair")) {

        K key;
        V value;

        std::stringstream keyStream(pairElement->FirstChildElement("key")->Attribute("val"));
        std::stringstream valueStream(pairElement->FirstChildElement("value")->Attribute("val"));

        keyStream >> key;
        valueStream >> value;

        map[key] = value;
    }
}

// Specialization for std::vector
template<typename T>
void serialize_xml(const std::vector<T>& vec, const char* name, const char* filename) {
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement* root = doc.NewElement("serialization");
    doc.InsertFirstChild(root);
    tinyxml2::XMLElement* vectorElement = doc.NewElement(name);
    root->InsertEndChild(vectorElement);

    for (const auto& value : vec) {
        tinyxml2::XMLElement* element = doc.NewElement("element");
        vectorElement->InsertEndChild(element);

        std::stringstream ss;
        ss << value;
        element->SetAttribute("val", ss.str().c_str());
    }

    doc.SaveFile(filename);
}

template<typename T>
void deserialize_xml(std::vector<T>& vec, const char* name, const char* filename) {
    tinyxml2::XMLDocument doc;
    doc.LoadFile(filename);
    tinyxml2::XMLElement* root = doc.FirstChildElement("serialization");
    tinyxml2::XMLElement* vectorElement = root->FirstChildElement(name);

    for (tinyxml2::XMLElement* element = vectorElement->FirstChildElement("element"); 
         element != nullptr; 
         element = element->NextSiblingElement("element")) {

        T value;
        std::stringstream ss(element->Attribute("val"));
        ss >> value;
        vec.push_back(value);
    }
}

void serialize_xml(const std::string& str, const char* name, const char* filename) {
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement* root = doc.NewElement("serialization");
    doc.InsertFirstChild(root);
    tinyxml2::XMLElement* stringElement = doc.NewElement(name);
    root->InsertEndChild(stringElement);

    stringElement->SetAttribute("val", str.c_str());

    doc.SaveFile(filename);
}

void deserialize_xml(std::string& str, const char* name, const char* filename) {
    tinyxml2::XMLDocument doc;
    doc.LoadFile(filename);
    tinyxml2::XMLElement* root = doc.FirstChildElement("serialization");
    tinyxml2::XMLElement* stringElement = root->FirstChildElement(name);

    str = stringElement->Attribute("val");
}

// Specialization for std::list
template<typename T>
void serialize_xml(const std::list<T>& lst, const char* name, const char* filename) {
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement* root = doc.NewElement("serialization");
    doc.InsertFirstChild(root);
    tinyxml2::XMLElement* listElement = doc.NewElement(name);
    root->InsertEndChild(listElement);

    for (const auto& value : lst) {
        tinyxml2::XMLElement* element = doc.NewElement("element");
        listElement->InsertEndChild(element);

        std::stringstream ss;
        ss << value;
        element->SetAttribute("val", ss.str().c_str());
    }

    doc.SaveFile(filename);
}

template<typename T>
void deserialize_xml(std::list<T>& lst, const char* name, const char* filename) {
    tinyxml2::XMLDocument doc;
    doc.LoadFile(filename);
    tinyxml2::XMLElement* root = doc.FirstChildElement("serialization");
    tinyxml2::XMLElement* listElement = root->FirstChildElement(name);

    for (tinyxml2::XMLElement* element = listElement->FirstChildElement("element"); 
         element != nullptr; 
         element = element->NextSiblingElement("element")) {

        T value;
        std::stringstream ss(element->Attribute("val"));
        ss >> value;
        lst.push_back(value);
    }
}
// Specialization for std::set
template<typename T>
void serialize_xml(const std::set<T>& set, const char* name, const char* filename) {
    tinyxml2::XMLDocument doc;
    tinyxml2::XMLElement* root = doc.NewElement("serialization");
    doc.InsertFirstChild(root);
    tinyxml2::XMLElement* setElement = doc.NewElement(name);
    root->InsertEndChild(setElement);

    for (const auto& value : set) {
        tinyxml2::XMLElement* element = doc.NewElement("element");
        setElement->InsertEndChild(element);

        std::stringstream ss;
        ss << value;
        element->SetAttribute("val", ss.str().c_str());
    }

    doc.SaveFile(filename);
}

template<typename T>
void deserialize_xml(std::set<T>& set, const char* name, const char* filename) {
    tinyxml2::XMLDocument doc;
    doc.LoadFile(filename);
    tinyxml2::XMLElement* root = doc.FirstChildElement("serialization");
    tinyxml2::XMLElement* setElement = root->FirstChildElement(name);

    for (tinyxml2::XMLElement* element = setElement->FirstChildElement("element"); 
         element != nullptr; 
         element = element->NextSiblingElement("element")) {

        T value;
        std::stringstream ss(element->Attribute("val"));
        ss >> value;
        set.insert(value);
    }
}

} // namespace XMLSerializer

#endif // XMLSERIALIZER_H
