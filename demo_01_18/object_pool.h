#ifndef __OBJECT_POOL__
#define __OBJECT_POOL__


#include <iostream>
#include <list>

using namespace std;

template <typename T>
class ObjectPool
{
public:
    ObjectPool(){}

    ~ObjectPool()
    {
        free_count = total_count = 0;
        for (T* object : _objects)
        {
            if (!object)
                continue;

            delete(object);
        }
    }

    T* createObject()
    {
        while (true)
        {
            if (free_count > 0)
            {
                T* _obj = static_cast<T*>(*_objects.begin());
                _objects.pop_front();
                --free_count;

                return _obj;
            }

            allocCapacity();
        }
    }

    // kbe中我比较费解的一种写法
    // 写出来跑跑看
    template <typename T1>
    T* createObject()
    {
        while (true)
        {
            if (free_count > 0)
            {
                T* _obj = static_cast<T1*>(*_objects.begin());
                _objects.pop_front();
                --free_count;

                return _obj;
            }

            allocCapacity();
        }
    }

    void allocCapacity(int size=2)
    {
        std::cout << "ready to alloc capacity: " << size << endl;
        for (int index = 0; index < size; ++index)
        {
            T* obj = new T();
            ++free_count;
            ++total_count;
            _objects.push_back(obj);
        }
    }
    

private:
    std::list<T* > _objects;     // 对象池所有对象列表
    int free_count = 0;         // 空闲计数
    int total_count = 0;        // 对象池对象总数

};


# endif
