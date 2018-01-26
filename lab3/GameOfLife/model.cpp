#include "model.h"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <cstring>

Model::Model(QWidget *parent) :
    QWidget(parent),
    generations(-1),
    height(50),
    width(50),
    rule("Conway`s")
{
    universe = new bool[(height + 2) * (width + 2)];
    next = new bool[(height + 2) * (width + 2)];
    std::memset(universe, false, sizeof(bool) * (height + 2) * (width + 2));
    std::memset(next, false, sizeof(bool) * (height + 2) * (width + 2));
}

Model::~Model()
{
    delete [] universe;
    delete [] next;
}

void Model::setGenerations(const int number)
{
    generations = number;
}

void Model::clear()
{
    for(int k = 1; k <= height; k++) {
        for(int j = 1; j <= width; j++) {
            universe[k * width + j] = false;
        }
    }
}

std::string Model::gameRule()
{
    return rule;
}

void Model::setRule(const std::string &r)
{
    rule = r;
}

int Model::heightCellNumber()
{
    return height;
}

void Model::setHeightCellNumber(const int h)
{
    height = h;
    resetUniverse();
}

int Model::widthCellNumber()
{
    return width;
}

void Model::setWidthCellNumber(const int w)
{
    width = w;
    resetUniverse();
}

void Model::resetUniverse()
{
    delete [] universe;
    delete [] next;
    universe = new bool[(height + 2) * (width + 2)];
    next = new bool[(height + 2) * (width + 2)];
    std::memset(universe, false, sizeof(bool) * (height + 2) * (width + 2));
    std::memset(next, false, sizeof(bool) * (height + 2) * (width + 2));
}

std::string Model::dump()
{
    bool flag = true;
    char temp;
    int count = 0;
    std::string master = "";
    for (int k = 1; k <= height; k++) {
        for (int j = 1; j <= width; j++) {
            if ((universe[k * width + j] == true && !flag) || (universe[k * width + j] == false && flag)) {
                master += std::to_string(count);
                master += temp;
                count = 0;
            }
            if (universe[k * width + j] == true) {
                temp = 'o';
                flag = true;
                count++;

            }
            if (universe[k * width + j] == false) {
                temp = 'b';
                flag = false;
                count++;
            }
        }
        if (k != height){
            master += "$";
        } else {
            master += "!";
        }
    }
    return master;
}

void Model::setDump(const std::string &data)
{
    std::ifstream file(data);
    std::string article;
    std::string field;
    std::getline(file, article);
    std::getline(file, field);
    int current = 0;
    for(int k = 1; k <= height; k++) {
        for(int j = 1; j <= width; j++) {
            if (data[current] == 'o')
            {
                universe[k * width + j] = true;
            }
            else universe[k * width + j] = false;
            current++;
        }
        current++;
    }
}

bool Model::isAlive(int k, int j)
{
    int power = 0;
    power += universe[(k + 1) * width +  j];
    power += universe[(k - 1) * width + j];
    power += universe[k * width + (j + 1)];
    power += universe[k * width + (j - 1)];
    power += universe[(k + 1) * width + (j - 1)];
    power += universe[(k - 1) * width + (j + 1)];
    power += universe[(k - 1) * width + (j - 1)];
    power += universe[(k + 1) * width +  (j + 1)];
    if (rule == "Conway`s" && (((universe[k * width + j] == true) && (power == 2)) || (power == 3)))
    {
           return true;
    }
    if (rule == "HighLife" && (((universe[k * width + j] == true) && (power == 2)) || (power == 3) || (power == 6)))
    {
           return true;
    }
    if (rule == "Day & Night" && (((universe[k * width + j] == true) && (power == 4)) ||
       (power == 3) || (power == 6) || (power == 7) || (power == 8)))
    {
           return true;
    }
    if (rule == "Life without Death" && ((universe[k * width + j] == true) || power == 3))
    {
           return true;
    }
    if (rule == "Seeds" && power == 2)
    {
           return true;
    }
    if (rule == "Your rule")
    {

    }
    return false;
}

void Model::newGeneration()
{
    if (generations < 0)
        generations++;
    int notChanged = 0;
    for (int k = 1; k <= height; k++) {
        for (int j = 1; j <= width; j++) {
            next[k * width + j] = isAlive(k, j);
            if (next[k * width + j] == universe[k * width + j])
                notChanged++;
        }
    }
    if (notChanged == height * width) {
       emit(lostGame(true));
        return;
    }
    for (int k = 1; k <= height; k++) {
        for (int j = 1; j <= width; j++) {
            universe[k * height + j] = next[k * width + j];
        }
    }
    emit(needUpdate(true));
    generations--;
    if (generations == 0) {
        emit(finishGame(true));
    }
}