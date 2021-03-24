#include <iostream>
#include <string>
#include <sstream>
 
int main() {
    std::stringstream ss;
 
    std::string str = "samurai engineer programmer";
 
    std::string output;
 
    ss << str;
 
    ss >> output;
 
    std::cout << "元の文字列：" << str << "\n";
    std::cout << "抽出：" << output << "\n";
 
    return 0;
}