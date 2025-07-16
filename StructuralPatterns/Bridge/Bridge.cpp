/**
 * @file Bridge.cpp
 * @brief 
 *
 * Detailed description of the file
 *
 * @version 1.0
 * @date 2025-07-16 20:44:53
 * @author xiangxun
 */
#include <iostream>
using namespace std;

class Color;
class Shape {

public:
    virtual void ShowShape() = 0;
    virtual void SetColor(Color* color) = 0;
private:
    virtual void DrawShape() = 0;
    virtual void DrawColor() = 0;
protected:
    Color* _color;
};

class Color
{
public:
    Color(string color_name) : _color_name(color_name) {}
    virtual string getColor() = 0;
protected:
    string _color_name;
};

class Blue : public Color
{
public:
    Blue() : Color("蓝色") {}
    string getColor() override
    {
        return _color_name;
    }
};

class Rect : public Shape
{
public:
    void ShowShape() override
    {
        cout << "形状为矩形，填充色为：" << this->_color->getColor() << endl; 
    }
    void SetColor(Color* color) override
    {
        this->_color = color;
    }
private:
    void DrawShape() override
    {

    }
    void DrawColor() override
    {
        
    }
};




int main()
{
    Shape* rect = new Rect();
    rect->SetColor(new Blue);
    rect->ShowShape();



    return 0;
}