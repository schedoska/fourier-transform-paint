#include "graph.h"
#include <qdebug.h>

#define GRID_OFFSET 25
#define LINES_NUMBER 8
#define GRID_BRIGHTNESS 180
#define AXIS_BRIGHTNESS 120

#define VALUES_COUNT 100

Graph::Graph(int t_Width, int t_Height, int x, int y)
{
    numberOfHlines = LINES_NUMBER;
    numberOfVlines = LINES_NUMBER;

    Width = t_Width;
    Height = t_Height;

    setGeometry(x, y, Width, Height);
    GridRect.setRect(GRID_OFFSET, GRID_OFFSET, Width - 2 * GRID_OFFSET, Height - 2 * GRID_OFFSET);

    AxisColor = QColor(AXIS_BRIGHTNESS,AXIS_BRIGHTNESS,AXIS_BRIGHTNESS);

    initValuesVector();
}

void Graph::paintEvent(QPaintEvent *event)
{
    QPainter malarz(this);
    malarz.fillRect(rect(), QBrush(Qt::white));

    drawGrid(&malarz);
    drawAxis(&malarz);
}

void Graph::setAxisColor(QColor kolor)
{
    AxisColor = kolor;
    update();
}

QRect Graph::getGridRect()
{
    return GridRect;
}

QVector<int> *Graph::getValuesVector()
{
    return &ValuesVector;
}

void Graph::setValue(int index, int value)
{
    ValuesVector.replace(index, value);
}

int Graph::getValue(int index)
{
    return ValuesVector.at(index);
}

void Graph::fillVectorWithZeros()
{
    ValuesVector.fill(0);
}

void Graph::initValuesVector()
{
    for(int i = 0; i < VALUES_COUNT; i++)
    {
        ValuesVector.append(0);
    }
}

void Graph::setValuesVector(QVector<int> ValuesVector)
{
    this->ValuesVector = ValuesVector;
}

void Graph::drawGrid(QPainter *malarz)
{
    QPen dlugosz = QPen(QColor(GRID_BRIGHTNESS,GRID_BRIGHTNESS,GRID_BRIGHTNESS));
    malarz->setPen(dlugosz);

    float Hspace = (float) GridRect.height() / numberOfHlines;
    float Vspace = (float) GridRect.width() / numberOfVlines;

    for(int i = 0; i < numberOfHlines + 1; i++)
    {
        malarz->drawLine(GridRect.left() ,i * Hspace + GridRect.top(),
                         GridRect.right(), i * Hspace  + GridRect.top());
    }
    for(int i = 0; i < numberOfVlines + 1; i++)
    {
        malarz->drawLine(i * Vspace + GridRect.left(), GridRect.top(),
                         i * Vspace + GridRect.left(), GridRect.bottom());
    }
}

void Graph::drawAxis(QPainter *malarz)
{
    QPen dlugosz = QPen(AxisColor);
    dlugosz.setWidth(3);
    malarz->setPen(dlugosz);

    malarz->drawLine(GridRect.left(), GridRect.center().y(),
                     GridRect.right(), GridRect.center().y());

    malarz->drawLine(GridRect.topLeft(),GridRect.bottomLeft());
}
















