#pragma once

#include <ostream>

class String {
  private:
    char *str;
    size_t len;

  public:
    String();
    String(const char *str);
    ~String();

    size_t size() const;

    String operator+(const String &other) const;
    bool operator==(const String &other) const;
    String &operator+=(const String &other);

    friend std::ostream &operator<<(std::ostream &out, const String &str);
};
