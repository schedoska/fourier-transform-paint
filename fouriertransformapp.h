#ifndef FOURIERTRANSFORMAPP_H
#define FOURIERTRANSFORMAPP_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "drawablegraph.h"
#include "generatedgraph.h"
#include "descretefourier.h"

class FourierTransformApp : public QMainWindow
{
    Q_OBJECT
public:
    FourierTransformApp();
    DrawableGraph *graf;
    GeneratedGraph *graf2;

    QPushButton *CanvasCelarBtn;
    QPushButton *VectorizeBtn;

    QPushButton *RankPLUS_1;
    QPushButton *RankPLUS_5;
    QPushButton *RankMINUS_1;
    QPushButton *RankMINUS_5;

    QLabel *Rank;

private:
    void UiPositionSetup();
    void UiRankSelectorSetup();
    void UpdateFourierTransform();

    DescreteFourier Furier;
    int FouriterTransformRank;

public slots:
    void Transform();
    void Add1ToRank();
    void Add5ToRank();
    void Sub1ToRank();
    void Sub5ToRank();
};

#endif // FOURIERTRANSFORMAPP_H
