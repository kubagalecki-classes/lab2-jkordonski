#pragma once

#include "Resource.hpp"

class ResourceManager
{
    Resource* p;

public:
    ResourceManager(Resource* ptr = NULL)
    {
        cout << "Resource acquired!" << endl;
        p = ptr;
    }

    ~ResourceManager()
    {
        cout << "Resource deleted!" << endl;
        delete (p);
    }
};
