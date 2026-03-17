#include <cstring>

#include "mystring.hpp"

String::String() {
    this->str = new char[1];
    *this->str = '\0';
    this->len = 0;
}

String::String(const char *str) {
    size_t len = strlen(str);
    this->str = new char[len + 1];
    memcpy(this->str, str, len + 1);
    this->len = len;
}

size_t String::size() const { return this->len; }

String String::operator+(const String &other) const {
    String s;
    s.len = this->len + other.len;
    s.str = new char[s.len + 1];
    memcpy(s.str, this->str, this->len);
    memcpy(s.str + this->len, other.str, other.len + 1);

    return s;
}

String &String::operator+=(const String &other) {
    char *str = new char[this->len + other.len];
    memcpy(str, this->str, this->len);
    memcpy(str + this->len, other.str, other.len);

    delete[] this->str;
    this->str = str;
    this->len = this->len + other.len;

    return *this;
}

bool String::operator==(const String &other) const {
    return !strcmp(this->str, other.str);
}

std::ostream &operator<<(std::ostream &out, const String &str) {
    out << str.str;
    return out;
}

String::~String() { delete[] this->str; }
