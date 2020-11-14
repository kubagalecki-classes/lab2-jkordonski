#pragma once

#include "Resource.hpp"

class ResourceManager
{
  
  Resource* p;

public:
    ResourceManager()
    { p = new Resource;}
    

    double get(){return p->get();}

    ResourceManager(const ResourceManager &other)
    {p= new Resource{*other.p};}

    ResourceManager operator =(const ResourceManager& other)
    {if (&other !=this)
      {delete p;
        p= new Resource{*other.p};}
        return *this}

    ResourceManager(ResourceManager&& other)
    {
      p = nullptr;
      p = other.p;
      other.p = nullptr;}

      ResourceManager operator=(ResourceManager&& other)
      {if (&other !=this)
        {
          delete p;
          p = other.p;
          other.p = nullptr;};
          return *this;}

    ~ResourceManager()
    {delete p;}
};
