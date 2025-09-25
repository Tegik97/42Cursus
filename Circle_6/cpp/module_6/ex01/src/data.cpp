#include "data.hpp"

Data::Data() : id(0), name("default"), value(42.42) {}

Data::Data(int i, const std::string& n, double v) : id(i), name(n), value(v) {}