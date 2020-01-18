#include "object_pool.h"


class PoolObjectBase
{
public:
    PoolObjectBase(){}
    
    int base_value = 0;
};


struct Fill
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    int g = 0;
};

class PoolObjectDrived : public PoolObjectBase
{
public:
    PoolObjectDrived(): PoolObjectBase() {}


    Fill f1;
    Fill f2;
    int a = 0;
    int drived_value = 0;
};

int main()
{
    ObjectPool<PoolObjectBase> object_pool;

    PoolObjectBase* obj1 = object_pool.createObject<PoolObjectDrived>();
    obj1->base_value = 1;
    PoolObjectDrived* real_obj1 = static_cast<PoolObjectDrived*>(obj1);
    real_obj1->drived_value = 2;

    PoolObjectBase* obj2 = object_pool.createObject();
    obj2->base_value = 3;

    cout << "obj1.base_value = " << real_obj1->base_value << "  " << "drived_value = " << real_obj1->drived_value << endl;
    cout << "obj2.base_value = " << obj2->base_value << endl;

    cout << "obj1.base_value's address: " << &real_obj1->base_value << " drived_value's address: " << &real_obj1->drived_value << endl;
    cout << "obj2.base_value's address: " << &obj2->base_value << endl;

    return 0;
}
