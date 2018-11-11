#include "fixed_size_map.h"
#include <algorithm>

std::string FixedSizeMap1::find(const std::string& key)
{
    const auto iter = m_map.find(key);
    if (iter == m_map.cend())
    {
        return "";
    }
    m_lru.erase(iter->second.second);
    m_lru.push_front(key);
    return iter->second.first;
}

bool FixedSizeMap1::erase(const std::string& key)
{
    const auto iter = m_map.find(key);
    if (iter == m_map.cend())
    {
        return false;
    }
    m_lru.erase(iter->second.second);
    m_map.erase(iter);
    return true;
}

void FixedSizeMap1::insert(const std::string& key, const std::string& value)
{
    if (m_map.size() == m_capacity)
    {
        m_map.erase(m_lru.back());
        m_lru.pop_back();
    }
    m_lru.push_front(key);
    m_map.emplace(key, std::make_pair(value, m_lru.cbegin()));
}

std::string FixedSizeMap2::find(const std::string& key)
{
    const auto iter = m_map.find(key);
    if (iter == m_map.cend())
    {
        return "";
    }
    // O(n)
    auto lru_iter = std::find(m_lru.cbegin(), m_lru.cend(), key);
    m_lru.erase(lru_iter);
    // O(1)
    m_lru.push_back(key);
    return iter->second;
}

bool FixedSizeMap2::erase(const std::string& key)
{
    const auto iter = m_map.find(key);
    if (iter == m_map.cend())
    {
        return false;
    }
    auto lru_iter = std::find(m_lru.cbegin(), m_lru.cend(), key);
    // O(n)
    m_lru.erase(lru_iter);
    m_map.erase(iter);
    return true;
}

void FixedSizeMap2::insert(const std::string& key, const std::string& value)
{
    if (m_map.size() == m_capacity)
    {
        // O(n)
        m_map.erase(m_lru.front());
        m_lru.erase(m_lru.cbegin());
    }
    m_lru.push_back(key);
    m_map.emplace(key, value);
}
