#pragma once
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Product
{
public:
    void Add(const string &part) {parts.push_back(part);};
    void show() 
    {
        cout << "\n产品创建 ----" << endl;
        for (auto part : parts) 
        {
            cout << part << endl;
        }
    }
private:
    list<string> parts;
};

class Builder
{
public:
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual Product* GetResult() = 0;
};

class ConcreteBuilder1 : public Builder
{
public:
    void BuildPartA() override {product->Add("部件A");};
    void BuildPartB() override {product->Add("部件B");};
    Product* GetResult() override {return product;};
private:
    Product *product = new Product();
};

class ConcreteBuilder2 : public Builder
{
public:
    void BuildPartA() override {product->Add("部件X");};
    void BuildPartB() override {product->Add("部件Y");};
    Product* GetResult() override {return product;};
private:
    Product *product = new Product();
};

class Director
{
public:
    void Construct(Builder *builder) {
        builder->BuildPartA();
        builder->BuildPartB();
    }
};