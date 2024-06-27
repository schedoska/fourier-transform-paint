#include "drawablegraph.h"
#include <QPainter>
#include <QDebug>

#define WIDENOFFSET 8

DrawableGraph::DrawableGraph(int Width, int Height, int x, int y)
    : Graph(Width, Height, x , y)
{
    Canvas = new QPixmap(Width, Height);
    Canvas->fill(Qt::transparent);

    WidenDrawableRect = getGridRect();
    WidenDrawableRect.adjust(-WIDENOFFSET, -WIDENOFFSET, WIDENOFFSET, WIDENOFFSET);
    //qDebug() << WidenDrawableRect;
}

void DrawableGraph::paintEvent(QPaintEvent *event)
{
    Graph::paintEvent(event);

    QPainter malarz2(this);
    malarz2.drawPixmap(0,0,*Canvas);

    //DEBUG_DRAW(&malarz2);
}

void DrawableGraph::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && WidenDrawableRect.contains(event->pos()))
    {
        isDrawing = true;
        lastPoint = normalize(event->pos());
        endPoint = normalize(event->pos());
        qDebug() << lastPoint;
    }
}

void DrawableGraph::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        isDrawing = false;
    }
}

void DrawableGraph::mouseMoveEvent(QMouseEvent *event)
{
    if(!isDrawing) return;

    endPoint = normalize(event->pos());
    drawLine();
    lastPoint = endPoint;
}

void DrawableGraph::drawLine()
{
    QPainter malarz(Canvas);
    QPen dlugopis(QColor(52,165,230));
    dlugopis.setWidth(6);
    dlugopis.setCapStyle(Qt::RoundCap);
    dlugopis.setJoinStyle(Qt::RoundJoin);
    malarz.setRenderHint(QPainter::Antialiasing);

    malarz.setPen(dlugopis);

    malarz.drawLine(lastPoint,endPoint);
    update();
}

void DrawableGraph::VectorizeFromCanvas()
{
    QImage image = Canvas->toImage();
    int ValuesCount = getValuesVector()->size();
    float SampleGap = (float) getGridRect().width() / ValuesCount;

    for(int i = 0; i < ValuesCount; i++)
    {
        int Value = readVertically(ValuesCount, &image, i * SampleGap + getGridRect().left());
        setValue(i, 100 - Value);
    }
    update();
}

QPoint DrawableGraph::normalize(QPoint MousePos)
{
    QPoint Normalized = MousePos;

    if(MousePos.x() > getGridRect().right())    Normalized.setX(getGridRect().right());
    if(MousePos.x() < getGridRect().left())     Normalized.setX(getGridRect().left());

    if(MousePos.y() > getGridRect().bottom())   Normalized.setY(getGridRect().bottom());
    if(MousePos.y() < getGridRect().top())      Normalized.setY(getGridRect().top());

    return Normalized;
}

int DrawableGraph::readVertically(int ValueCount, QImage *image, int Xrow)
{
    float SampleGap = (float) getGridRect().height() / ValueCount;

    for(int i = 0; i < ValueCount + 1; i++)
    {
        QColor Kolor = image->pixelColor(Xrow, i * SampleGap + getGridRect().top());

        if(Kolor != Qt::transparent)
        {
            return i;
        }
    }
    return 50;
}

void DrawableGraph::DEBUG_DRAW(QPainter *malarz)
{
    QVector<int> wartosci = *getValuesVector();

    for(int q = 0; q < wartosci.size(); q++)
    {
        malarz->setBrush(Qt::red);
        malarz->drawEllipse(q * 4.5 + getGridRect().left(), getGridRect().bottom()-wartosci.at(q) * 4.5, 3, 3);
    }
}

void DrawableGraph::ClearCanvas()
{
    Canvas->fill(Qt::transparent);
    update();
}












