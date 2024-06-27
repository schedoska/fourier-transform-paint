#ifndef DRAWABLEGRAPH_H
#define DRAWABLEGRAPH_H

#include "graph.h"
#include <QMouseEvent>
#include <QObject>

class DrawableGraph : public Graph
{
    Q_OBJECT
public:
    DrawableGraph(int Width, int Height, int x, int y);

private:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void drawLine();

    QPoint normalize(QPoint MousePos);

    QPixmap *Canvas;
    QRect WidenDrawableRect;
    bool isDrawing;

    QPoint lastPoint;
    QPoint endPoint;

    int readVertically(int ValueCount, QImage *image, int Xrow);
    void DEBUG_DRAW(QPainter *malarz);

public slots:
    void ClearCanvas();
    void VectorizeFromCanvas();
};

#endif // DRAWABLEGRAPH_H
