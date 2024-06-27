#ifndef GENERATEDGRAPH_H
#define GENERATEDGRAPH_H

#include "graph.h"

class GeneratedGraph : public Graph
{
    Q_OBJECT
public:
    GeneratedGraph(int Width, int Height, int x, int y);
    void paintEvent(QPaintEvent *event) override;
    void drawFromVector(QVector<int> wektor);
};

#endif // GENERATEDGRAPH_H
