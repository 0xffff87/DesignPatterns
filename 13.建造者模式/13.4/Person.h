#pragma once

#include <iostream>

using namespace std;

class PersonBuilder
{
public:
    PersonBuilder() {/*不需要背景版和画笔*/};
    ~PersonBuilder();
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildArmLeft() = 0;
    virtual void buildArmRight() = 0;
    virtual void buildLegLeft() = 0;
    virtual void buildLegRight() = 0;
};

class PersonThinBuilder : public PersonBuilder
{
public:
    PersonThinBuilder() {/*不需要背景版和画笔*/};
    ~PersonThinBuilder();
    void buildHead() override {cout << "瘦人头部" << endl;};
    void buildBody() override {cout << "瘦人身体" << endl;};
    void buildArmLeft() override {cout << "瘦人左手" << endl;};
    void buildArmRight() override {cout << "瘦人右手" << endl;};
    void buildLegLeft() override {cout << "瘦人左腿" << endl;};
    void buildLegRight() override {cout << "瘦人右腿" << endl;};
};

class PersonFatBuilder : public PersonBuilder
{
public:
    PersonFatBuilder() {/*不需要背景版和画笔*/};
    ~PersonFatBuilder();
    void buildHead() override {cout << "胖人头部" << endl;};
    void buildBody() override {cout << "胖人身体" << endl;};
    void buildArmLeft() override {cout << "胖人左手" << endl;};
    void buildArmRight() override {cout << "胖人右手" << endl;};
    void buildLegLeft() override {cout << "胖人左腿" << endl;};
    void buildLegRight() override {cout << "胖人右腿" << endl;};
};

class PersonDirector
{
public:
    PersonDirector(PersonBuilder *pb) : m_pb(pb) {};
    ~PersonDirector() {delete m_pb;};
    void createPerson() {
        m_pb->buildHead();
        m_pb->buildBody();
        m_pb->buildArmLeft();
        m_pb->buildArmRight();
        m_pb->buildLegLeft();
        m_pb->buildLegRight();
    };

private:
    PersonBuilder *m_pb = nullptr;
};