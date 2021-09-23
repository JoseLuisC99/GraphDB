template<typename T>
void Vertex::addAttr(std::string key, T val) {
    attr[key] = val;
}

template<typename T>
T Vertex::getValue(std::string key) {
    return std::any_cast<T>(attr.at(key));
}