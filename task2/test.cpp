#include <iostream>

#include "mystring.hpp"

int main() {
    String s1("abo");
    String s2("ba");
    String s3("aboba");
    std::cout << s3 << ' ' << (s3 == s1 + s2) << std::endl;
    return 0;
}
