/**
 * @file Prototype.cpp
 * @brief sd
 *
 * Detailed description of the file
 *
 * @version 1.0
 * @date 2025-07-16 13:10:42
 * @author xiangxun
 */
#include <iostream>
#include <unordered_map>
using namespace std;

class Car
{
public:
    Car() = default;
    virtual ~Car() = default;
    virtual void run() = 0;
    virtual Car* clone() = 0;
};

class San : public Car
{
public:
    San() = default;
    San(int speed) : _speed(speed)
    {

    }
    San(const San& other)
    {
        this->_speed = other._speed;
    }
    void run() override
    {
        cout << "三轮车以" << _speed << "km/h的速度奔跑\n";
    }

    Car* clone() override
    {
        return new San(*this);
    }
private:
    int _speed;
};





int main() 
{
    Car* a = new San();
    a->run();
    Car* c = a->clone();
    c->run();
    
    return 0;
}