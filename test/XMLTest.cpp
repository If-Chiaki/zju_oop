#include <iostream>
#include <utility>
#include "../include/xml_seri.h"
#include <bits/stdc++.h>
// Include the serialize_xml and deserialize_xml function definitions here
using namespace std;
int main() {
    //int test
    int i1 = 2024, i2;
    XMLSerializer::serialize_xml(i1,"int_value","xml_data/int.xml");
    XMLSerializer::deserialize_xml(i2,"int_value","xml_data/int.xml");
    if(i1 == i2){
        cout << "int test passed!" << endl;
    }
    else{
        throw logic_error("Test failed.");
    }
    // float test
    float f1 = 3.14f, f2;
    XMLSerializer::serialize_xml(f1, "float_value", "xml_data/float.xml");
    XMLSerializer::deserialize_xml(f2, "float_value", "xml_data/float.xml");
    if(f1 == f2) {
        cout << "float test passed!" << endl;
    }
    else {
        throw logic_error("Float test failed.");
    }

    // char test
    char c1 = 'A', c2;
    XMLSerializer::serialize_xml(c1, "char_value", "xml_data/char.xml");
    XMLSerializer::deserialize_xml(c2, "char_value", "xml_data/char.xml");
    if(c1 == c2) {
        cout << "char test passed!" << endl;
    }
    else {
        throw logic_error("Char test failed.");
    }

    // bool test
    bool b1 = true, b2;
    XMLSerializer::serialize_xml(b1, "bool_value", "xml_data/bool.xml");
    XMLSerializer::deserialize_xml(b2, "bool_value", "xml_data/bool.xml");
    if(b1 == b2) {
        cout << "bool test passed!" << endl;
    }
    else {
        throw logic_error("Bool test failed.");
    }
    cout << "All arthimetic test passed!" << endl << endl;
    // map test
    map<int, float> m1 = {{1, 1.1f}, {2, 2.2f}, {3, 3.3f}}, m2;
    XMLSerializer::serialize_xml(m1, "int_float_map", "xml_data/map.xml");
    XMLSerializer::deserialize_xml(m2, "int_float_map", "xml_data/map.xml");
    if(m1 == m2) {
        cout << "map test passed!" << endl;
    }
    else {
        throw logic_error("Map test failed.");
    }

    // list test
    list<char> l1 = {'a', 'b', 'c'}, l2;
    XMLSerializer::serialize_xml(l1, "char_list", "xml_data/list.xml");
    XMLSerializer::deserialize_xml(l2, "char_list", "xml_data/list.xml");
    if(l1 == l2) {
        cout << "list test passed!" << endl;
    }
    else {
        throw logic_error("List test failed.");
    }

    // vector test
    vector<bool> v1 = {true, false, true}, v2;
    XMLSerializer::serialize_xml(v1, "bool_vector", "xml_data/vector.xml");
    XMLSerializer::deserialize_xml(v2, "bool_vector", "xml_data/vector.xml");
    if(v1 == v2) {
        cout << "vector test passed!" << endl;
    }
    else {
        throw logic_error("Vector test failed.");
    }

    // pair test
    pair<float, bool> p1 = {4.4f, true}, p2;
    XMLSerializer::serialize_xml(p1, "float_bool_pair", "xml_data/pair.xml");
    XMLSerializer::deserialize_xml(p2, "float_bool_pair", "xml_data/pair.xml");
    if(p1 == p2) {
        cout << "pair test passed!" << endl;
    }
    else {
        throw logic_error("Pair test failed.");
    }

    // set test
    set<float> s1 = {5.5f, 6.6f, 7.7f}, s2;
    XMLSerializer::serialize_xml(s1, "float_set", "xml_data/set.xml");
    XMLSerializer::deserialize_xml(s2, "float_set", "xml_data/set.xml");
    if(s1 == s2) {
        cout << "set test passed!" << endl;
    }
    else {
        throw logic_error("Set test failed.");
    }

    // string test
    std::string str1 = "I love ooooooooooooooooooooooooooop!", str2;
    XMLSerializer::serialize_xml(str1, "string_value", "xml_data/string.xml");
    XMLSerializer::deserialize_xml(str2, "string_value", "xml_data/string.xml");
    if(str1 == str2) {
        std::cout << "string test passed!" << std::endl;
    }
    else {
        throw std::logic_error("String test failed.");
    }
    cout << "All STL container tests passed!" << endl;
    cout << "All XMLTest Passed!" << endl;
    system("pause");
    return 0;
}
