#include "generatedgraph.h"
#include <QDebug>

GeneratedGraph::GeneratedGraph(int Width, int Height, int x, int y)
    : Graph(Width, Height, x , y)
{

}

void GeneratedGraph::paintEvent(QPaintEvent *event)
{
    Graph::paintEvent(event);

    float Vspace = (float) getGridRect().width() / getValuesVector()->size();
    float VTransform = (float) getGridRect().height() / getValuesVector()->size();
    //qDebug() << getValuesVector()->size();

    QPen dlugopis(QColor(209, 60, 44));
    dlugopis.setWidth(4);
    dlugopis.setCapStyle(Qt::RoundCap);
    dlugopis.setJoinStyle(Qt::RoundJoin);

    QPainter malarz(this);
    malarz.setPen(dlugopis);
    malarz.setRenderHint(QPainter::Antialiasing);

    for(int q = 0; q < getValuesVector()->size() - 1; q++)
    {
        malarz.drawLine(q * Vspace + getGridRect().left(),
                        getGridRect().bottom() - getValuesVector()->at(q) * VTransform,
                        (q+1) * Vspace + getGridRect().left(),
                        getGridRect().bottom() - getValuesVector()->at(q+1) * VTransform);
    }
}

void GeneratedGraph::drawFromVector(QVector<int> wektor)
{
    setValuesVector(wektor);
    update();
}
