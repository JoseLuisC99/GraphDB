template<typename T> void Edge::addAttr(std::string key, T val) {
    attr[key] = val;
}

template<typename T> T Edge::getValue(std::string key) {
    return std::any_cast<T>(attr.at(key));
}