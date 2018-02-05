#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include <QWidget>

class Model : public QWidget
{
Q_OBJECT

signals:
    void finishGame(bool ok);
    void lostGame(bool ok);
    void needUpdate(bool ok);
    void myRule(bool ok);
    void notMyRule(bool ok);

public:
    explicit Model(QWidget *parent = 0);
    ~Model();
    void setGenerations(const int number);
    void clear();
    std::string gameRule();
    void setRule(const std::string &r);
    int heightCellNumber();
    void setHeightCellNumber(const int h);
    int widthCellNumber();
    void setWidthCellNumber(const int w);
    std::string dump();
    void setDump(const std::string &data);
    void newGeneration();
    std::vector<bool> &getNext();
    std::vector<bool> &getUniverse();
    void setUniverse(std::vector<bool> &u);
    void setNext(std::vector<bool> &n);
    void setBirth(const std::vector<bool> b);
    void setLife(const std::vector<bool> l);

private:
    int generations;
    std::vector<bool> universe;
    std::vector<bool> next;
    std::vector<bool> birth;
    std::vector<bool> life;
    int height;
    int width;
    std::string rule;
    bool isAlive(int k, int j);
    void resetUniverse();
};

#endif // MODEL_H
