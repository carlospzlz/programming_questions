/*
 Your task is to write a C++ container that acts as a *map* (a.k.a. dictionary)
 with a *fixed capacity*. If the caller tries to insert a new entry when the
 container is full, an existing entry needs to be removed to make room.

 Requirements
 ------------
 - Keys and values in the map should be strings.
 - The size is set at construction time.
 - It should support find(), erase(), insert().
 - Don't use any third-party libraries - standard library (STL) classes only.
*/

#include <list>
#include <string>
#include <unordered_map>
#include <vector>

class FixedSizeMap1
{
public:
    FixedSizeMap1(size_t capacity) : m_capacity(capacity) { }
    std::string find(const std::string& key);

    // Erase the pair identified by the given key.
    // Returns true if the pair is removed false otherwise.
    bool erase(const std::string& key);

    // Inserts given pair.
    void insert(const std::string& key, const std::string& value);

private:
    size_t m_capacity;
    std::unordered_map<std::string,
        std::pair<std::string, std::list<std::string>::const_iterator>> m_map;
    std::list<std::string> m_lru;

};

class FixedSizeMap2
{
public:
    FixedSizeMap2(size_t capacity) : m_capacity(capacity) { }
    std::string find(const std::string& key);

    // Erase the pair identified by the given key.
    // Returns true if the pair is removed false otherwise.
    bool erase(const std::string& key);

    // Inserts given pair.
    void insert(const std::string& key, const std::string& value);

private:
    size_t m_capacity;
    std::unordered_map<std::string, std::string> m_map;
    std::vector<std::string> m_lru;

};
