#include <iostream>
using namespace std;


class Product
{
public:
    virtual ~Product() = default;
    virtual std::string print() const = 0;
};


class ProductA : public Product
{
public:
    std::string print() const override
    {
        return "我是产品A";
    }
};


class ProductB : public Product
{
public:
    std::string print() const override
    {
        return "我是产品B";
    }
};


class Creator
{
public:
    virtual ~Creator() = default;
    virtual Product* createProduct() const = 0;
};

class ProductACreator : public Creator
{
public:
    Product* createProduct() const override 
    {
        return new ProductA();
    }
};

class ProductBCreator : public Creator
{
public:
    Product* createProduct() const override 
    {
        return new ProductB();
    }
};


int main()
{
    Creator* c1 = new ProductACreator();
    Product* sb = c1->createProduct();
    cout << "创建产品A: " << sb->print() << endl;
    Creator* c11 = new ProductBCreator();
    Product* sb1 = c11->createProduct();
    cout << "创建产品A: " << sb->print() << endl;
    delete c1;
    delete sb;
    delete c11;
    delete sb1;
    return 0;
}





























































