//
// Created by cabo_ on 11/9/2023.
//

#pragma once

#include "Allocator.h"

namespace corbeau {

    class Memory {
    public:
        explicit Memory(size_t pool_size) :
            data(pool_size),
            pool(&data),
            Allocator(&pool)
            {}
        ~Memory() = default;


        std::pmr::polymorphic_allocator<> Allocator;
    private:
        std::pmr::monotonic_buffer_resource data;
        std::pmr::unsynchronized_pool_resource pool;
    };

} // corbeau
