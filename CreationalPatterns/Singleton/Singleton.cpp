/**
 * @file Singleton.cpp
 * @brief Brief description of the file
 *
 * Detailed description of the file
 *
 * @version 1.0
 * @date 2025-07-16 17:57:58
 * @author xiangxun
 */
#include <iostream>
using namespace std;

class Sky
{
protected:
    string _color;
    Sky(string color) : _color(color) {}
    static Sky* _singleton;
public:
    Sky(const Sky& other) = delete;
    Sky* operator=(const Sky& other) = delete;
    void print()
    {
        cout << "天空是" << _color << endl;
    }
    static Sky* GetInstance(const std::string& color)
    {
        if(_singleton == nullptr)
        {
            _singleton = new Sky(color);
        }
        return _singleton;
    }
};


Sky* Sky::_singleton= nullptr;


int main()
{
    Sky* a = Sky::GetInstance("蔚蓝色");
    a->print();
    return 0;
}