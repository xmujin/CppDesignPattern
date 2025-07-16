/**
 * @file Adapter.cpp
 * @brief 适配器模式
 *
 * Detailed description of the file
 *
 * @version 1.0
 * @date 2025-07-16 19:23:08
 * @author xiangxun
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Target
{
public:
    virtual ~Target() = default;

    virtual std::string Request() const
    {
        return "哈哈，我是正常的字符串\n";
    }
};

class Adaptee
{
public:
    std::string SpecificRequest() const
    {
        return "!dlrow olleH";
    }
};

class Adapter : public Target
{
private:
    Adaptee *adaptee_;

public:
    Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
    std::string Request() const override
    {
        std::string to_reverse = this->adaptee_->SpecificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "适配器:" + to_reverse;
    }
};

int main()
{
    Target *target = new Target;
    target->Request();
    std::cout << "\n\n";
    Adaptee *adaptee = new Adaptee;
    std::cout << "客户端: 真他娘的操蛋，Adaptee类的内容我无法理解\n";
    std::cout << "Adaptee:我说的是：" << adaptee->SpecificRequest();
    std::cout << "\n\n";
    std::cout << "客户端: 嘻嘻，我能通过适配器理解。\n";
    Adapter *adapter = new Adapter(adaptee);
    std::cout << adapter->Request() << endl;

    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}