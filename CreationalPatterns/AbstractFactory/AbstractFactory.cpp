#include <iostream>



class Chair
{
public:
    virtual ~Chair() = default;
    virtual void sit() = 0;
};


class StoneChair : public Chair
{
    void sit() override 
    {
        std::cout << "我坐上了石头板凳\n";
    }
};

class WoodChair : public Chair
{
    void sit() override 
    {
        std::cout << "我坐上了木头板凳\n";
    }
};

class FurnitureFactory
{
public:
    virtual ~FurnitureFactory() = default;
    virtual Chair* createChair() = 0;
};

class WoodFurnitureFactory : public FurnitureFactory
{
public:
    Chair* createChair() override
    {
        return new WoodChair();
    }
};


class StoneFurnitureFactory : public FurnitureFactory
{
public:
    Chair* createChair() override
    {
        return new StoneChair();
    }
};








int main() 
{
    FurnitureFactory* woodFactory = new WoodFurnitureFactory();
    Chair* woodChair = woodFactory->createChair();
    woodChair->sit();
    FurnitureFactory* stoneFactory = new StoneFurnitureFactory();
    Chair* stoneChair = stoneFactory->createChair();
    stoneChair->sit();
    delete woodFactory;
    delete woodChair;
    delete stoneFactory;
    delete stoneChair;
    

  return 0;
}