#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "../include/Bin_Seri.h"
using namespace std;
int main() {
    //int test
    int i1 = 2024, i2;
    BinSerialization::serialize(i1,"binary_data/n.data");
    BinSerialization::deserialize(i2,"binary_data/n.data");
    if(i1==i2){
        cout << "int type test passed !" << endl;
    }
    else{
        throw logic_error("Test Failed!");
    }
    //float test
    float f1 = 2024.2023, f2;
    BinSerialization::serialize(f1,"binary_data/n.data");
    BinSerialization::deserialize(f2,"binary_data/n.data");
    if(f1==f2){
        cout << "float type test passed !" << endl;
    }
    else{
        throw logic_error("Test Failed!");
    }
    //bool test
    bool b1 = false, b2;
    BinSerialization::serialize(b1,"binary_data/n.data");
    BinSerialization::deserialize(b2,"binary_data/n.data");
    if(i1==i2){
        cout << "bool type test passed !" << endl;
    }
    else{
        throw logic_error("Test Failed!");
    }
    //char test
    char c1 = 'e', c2;
    BinSerialization::serialize(c1,"binary_data/n.data");
    BinSerialization::deserialize(c2,"binary_data/n.data");
    if(c1==c2){
        cout << "char type test passed !" << endl;
    }
    else{
        throw logic_error("Test Failed!");
    }
    cout << "All arthimetic tests passed(4/4)" << endl << endl;
    //vector test
    //int
    vector<int> v1_int = {1,2,3,4,5}, v2_int;
    BinSerialization::serialize(v1_int,"binary_data/n.data");
    BinSerialization::deserialize(v2_int,"binary_data/n.data");
    if(v1_int==v2_int){
        cout << "vector_int type test passed !" << endl;
    }
    else{
        throw logic_error("Test Failed!");
    }
    // float  
    vector<float> v1_float = {1.1, 2.2, 3.3, 4.4, 5.5}, v2_float;  
    BinSerialization::serialize(v1_float, "binary_data/n.data");  
    BinSerialization::deserialize(v2_float, "binary_data/n.data");  
    if (v1_float == v2_float) {  
        cout << "vector_float type test passed !" << endl;  
    }
    else{  
        throw logic_error("Test Failed!");  
    }  
    
    // char  
    vector<char> v1_char = {'a', 'b', 'c', 'd', 'e'}, v2_char;  
    BinSerialization::serialize(v1_char, "binary_data/n.data");  
    BinSerialization::deserialize(v2_char, "binary_data/n.data");  
    if (v1_char == v2_char) {  
        cout << "vector_char type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    
    // bool  
    vector<bool> v1_bool = {true, false, true, false, true}, v2_bool;  
    BinSerialization::serialize(v1_bool, "binary_data/n.data");  
    BinSerialization::deserialize(v2_bool, "binary_data/n.data");  
    if (v1_bool == v2_bool) {  
        cout << "vector_bool type test passed !" << endl;  
    }
    else {  
        throw logic_error("Test Failed!");  
    }
    cout << "All vector tests passed(4/4)" << endl << endl;
    //vector test end

    //set test
    // int  
    set<int> s1_int = {1, 2, 3, 4, 5}, s2_int;  
    BinSerialization::serialize(s1_int, "binary_data/n.data");  
    BinSerialization::deserialize(s2_int, "binary_data/n.data");  
    if (s1_int == s2_int) {  
        cout << "set_int type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    // float  
    set<float> s1_float = {1.1, 2.2, 3.3, 4.4, 5.5}, s2_float;  
    BinSerialization::serialize(s1_float, "binary_data/n.data");  
    BinSerialization::deserialize(s2_float, "binary_data/n.data");  
    if (s1_float == s2_float) {  
        cout << "set_float type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    
    // char  
    set<char> s1_char = {'a', 'b', 'c', 'd', 'e'}, s2_char;  
    BinSerialization::serialize(s1_char, "binary_data/n.data");  
    BinSerialization::deserialize(s2_char, "binary_data/n.data");  
    if (s1_char == s2_char) {  
        cout << "set_char type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    
    // bool  
    set<bool> s1_bool = {true, false, true, false, true}, s2_bool;  
    BinSerialization::serialize(s1_bool, "binary_data/n.data");  
    BinSerialization::deserialize(s2_bool, "binary_data/n.data");  
    if (s1_bool == s2_bool) {  
        cout << "set_bool type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    cout << "All set tests passed(4/4)" << endl << endl;
    //end set test

    //list test
    // int  
    list<int> l1_int = {1, 2, 3, 4, 5}, l2_int;  
    BinSerialization::serialize(l1_int, "binary_data/n.data");  
    BinSerialization::deserialize(l2_int, "binary_data/n.data");  
    if (l1_int == l2_int) {  
        cout << "list_int type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    
    // float  
    list<float> l1_float = {1.1, 2.2, 3.3, 4.4, 5.5}, l2_float;  
    BinSerialization::serialize(l1_float, "binary_data/n.data");  
    BinSerialization::deserialize(l2_float, "binary_data/n.data");  
    if (l1_float == l2_float) {  
        cout << "list_float type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    
    // char  
    list<char> l1_char = {'a', 'b', 'c', 'd', 'e'}, l2_char;  
    BinSerialization::serialize(l1_char, "binary_data/n.data");  
    BinSerialization::deserialize(l2_char, "binary_data/n.data");  
    if (l1_char == l2_char) {  
        cout << "list_char type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    
    // bool  
    list<bool> l1_bool = {true, false, true, false, true}, l2_bool;  
    BinSerialization::serialize(l1_bool, "binary_data/n.data");  
    BinSerialization::deserialize(l2_bool, "binary_data/n.data");  
    if (l1_bool == l2_bool) {  
        cout << "list_bool type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    cout << "All list tests passed(4/4)" << endl << endl;  
    //list test end

    //pair test
    // pair<int, int>  
    pair<int, int> p1_int_int = {5, 10}, p2_int_int;  
    BinSerialization::serialize(p1_int_int, "binary_data/n.data");  
    BinSerialization::deserialize(p2_int_int, "binary_data/n.data");  
    if (p1_int_int == p2_int_int) {  
        cout << "pair_int_int type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }    
    // pair<int, float>  
    pair<int, float> p1_int_float = {1, 3.14}, p2_int_float;  
    BinSerialization::serialize(p1_int_float, "binary_data/n.data");  
    BinSerialization::deserialize(p2_int_float, "binary_data/n.data");  
    if (p1_int_float == p2_int_float) {  
        cout << "pair_int_float type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    
    // pair<int, char>  
    pair<int, char> p1_int_char = {1, 'a'}, p2_int_char;  
    BinSerialization::serialize(p1_int_char, "binary_data/n.data");  
    BinSerialization::deserialize(p2_int_char, "binary_data/n.data");  
    if (p1_int_char == p2_int_char) {  
        cout << "pair_int_char type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    
    // pair<int, bool>  
    pair<int, bool> p1_int_bool = {1, true}, p2_int_bool;  
    BinSerialization::serialize(p1_int_bool, "binary_data/n.data");  
    BinSerialization::deserialize(p2_int_bool, "binary_data/n.data");  
    if (p1_int_bool == p2_int_bool) {  
        cout << "pair_int_bool type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    cout << "All pair tests passed(4/4)" << endl << endl; 

    //map test
    // map<int, int>  
    map<int, int> m1_int_int = {{1, 10}, {2, 20}, {3, 30}}, m2_int_int;  
    BinSerialization::serialize(m1_int_int, "binary_data/n.data");  
    BinSerialization::deserialize(m2_int_int, "binary_data/n.data");  
    if (m1_int_int == m2_int_int) {  
        cout << "map_int_int type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    
    // map<int, bool>  
    map<int, bool> m1_int_bool = {{1, true}, {2, false}, {3, true}}, m2_int_bool;  
    BinSerialization::serialize(m1_int_bool, "binary_data/n.data");  
    BinSerialization::deserialize(m2_int_bool, "binary_data/n.data");  
    if (m1_int_bool == m2_int_bool) {  
        cout << "map_int_bool type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    
    // map<int, char>  
    map<int, char> m1_int_char = {{1, 'a'}, {2, 'b'}, {3, 'c'}}, m2_int_char;  
    BinSerialization::serialize(m1_int_char, "binary_data/n.data");  
    BinSerialization::deserialize(m2_int_char, "binary_data/n.data");  
    if (m1_int_char == m2_int_char) {  
        cout << "map_int_char type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    
    // map<int, float>  
    map<int, float> m1_int_float = {{1, 1.1}, {2, 2.2}, {3, 3.3}}, m2_int_float;  
    BinSerialization::serialize(m1_int_float, "binary_data/n.data");  
    BinSerialization::deserialize(m2_int_float, "binary_data/n.data");  
    if (m1_int_float == m2_int_float) {  
        cout << "map_int_float type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    cout << "All map tests passed(4/4)" << endl << endl;   
    //map test END

    // string  
    string s1 = "Hello, world!", s2;  
    BinSerialization::serialize(s1, "binary_data/n.data");  
    BinSerialization::deserialize(s2, "binary_data/n.data");  
    if (s1 == s2) {  
        cout << "string type test passed !" << endl;  
    } else {  
        throw logic_error("Test Failed!");  
    }  
    cout << "All string tests passed(1/1)" << endl << endl;  

    cout << "All test passed(25/25)" << endl;
    cout << "BinaryTest Finish" << endl;
    system("pause");
    return 0;
}
