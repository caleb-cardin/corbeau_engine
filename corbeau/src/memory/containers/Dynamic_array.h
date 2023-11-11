//
// Created by cabo_ on 11/9/2023.
//
#pragma once

#include <memory_resource>
#include "memory/Allocator.h"

namespace corbeau {

    template<typename T>
    class Dynamic_array {
    public:
        Dynamic_array(size_t size, std::pmr::polymorphic_allocator<T> alloc) : m_Array(alloc)
        {
            m_Array.reserve(size);
        }

        ~Dynamic_array() = default;

        void add_element(T element);
//        void add_element(const T& element);
//        void add_element(T&& element);

        T* operator[](size_t pos);
    private:
        std::pmr::vector<T> m_Array;

    };

    template<typename T>
    void Dynamic_array<T>::add_element(T element)
    {
        m_Array.emplace_back(element);
    }

    template<typename T>
    T* Dynamic_array<T>::operator[](size_t pos)
    {
        return m_Array[pos];
    }


//    template<typename T>
//    void Dynamic_array<T>::add_element(const T& element)
//    {
//        m_Array.emplace_back(element);
//    }
//
//    template<typename T>
//    void Dynamic_array<T>::add_element(T&& element)
//    {
//        m_Array.emplace_back(element);
//    }


} // corbeau
