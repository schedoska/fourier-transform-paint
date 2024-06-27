#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include <QPainter>

class Graph : public QWidget
{
    Q_OBJECT
public:
    Graph(int Width, int Height, int x, int y);
    void paintEvent(QPaintEvent *event) override;
    void setAxisColor(QColor kolor);
    QRect getGridRect();

    QVector<int> *getValuesVector();
    void setValue(int index, int value);
    int getValue(int index);
    void fillVectorWithZeros();
    void initValuesVector();
    void setValuesVector(QVector<int> ValuesVector);

private:
    void drawGrid(QPainter *malarz);
    void drawAxis(QPainter *malarz);

    int numberOfVlines;
    int numberOfHlines;

    int Width;
    int Height;

    QRect GridRect;
    QColor AxisColor;

    QVector<int> ValuesVector;
};

#endif // GRAPH_H
