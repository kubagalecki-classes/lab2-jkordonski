#pragma once

#include "Resource.hpp"

class ResourceManager
{
    Resource* p;

public:
    ResourceManager(Resource* ptr = NULL) { p = ptr; }

    ~ResourceManager() { delete (p); }
};
