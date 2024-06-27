#include "fouriertransformapp.h"
#include <QScreen>
#include <QDebug>
#include "functiongenerator.h"
#include <complex>

#define MAX_RANK 150
#define MIN_RANK 0

FourierTransformApp::FourierTransformApp()
{
    setGeometry(300,200,1300,700);
    setFixedSize(1150,650);

    UiPositionSetup();
    UiRankSelectorSetup();

    FouriterTransformRank = 0;
}

void FourierTransformApp::UiPositionSetup()
{
    graf = new DrawableGraph(500,500, 50, 50);
    graf->setParent(this);

    graf2 = new GeneratedGraph(500, 500, 580, 50);
    graf2->setParent(this);

    CanvasCelarBtn = new QPushButton("Clear", this);
    CanvasCelarBtn->setGeometry(50,560,500,60);
    connect(CanvasCelarBtn, &QPushButton::clicked, graf, &DrawableGraph::ClearCanvas);

    VectorizeBtn = new QPushButton("Update Function", this);
    VectorizeBtn->setGeometry(580,560,235,60);
    connect(VectorizeBtn, &QPushButton::clicked, this, &FourierTransformApp::Transform);
}

void FourierTransformApp::UiRankSelectorSetup()
{
    const int Separator = 5;
    const int OffsetToRight = 30;
    const int UpdateBtnRight = VectorizeBtn->pos().x() + VectorizeBtn->rect().right();

    Rank = new QLabel("0",this);
    Rank->setFrameStyle(QFrame::Box | QFrame::Sunken);
    Rank->setLineWidth(0);
    Rank->setMidLineWidth(2);
    Rank->setAlignment(Qt::AlignCenter);
    Rank->setFont(QFont("Calibri Light",15));

    RankMINUS_5 = new QPushButton("<<",this);
    RankMINUS_5->setGeometry(UpdateBtnRight + OffsetToRight, 560, 40, 60);
    connect(RankMINUS_5, &QPushButton::clicked, this, &FourierTransformApp::Sub5ToRank);

    RankMINUS_1 = new QPushButton("<",this);
    RankMINUS_1->setGeometry(RankMINUS_5->geometry().right() + Separator, 560, 40 , 60);
    connect(RankMINUS_1, &QPushButton::clicked, this, &FourierTransformApp::Sub1ToRank);

    Rank->setGeometry(RankMINUS_1->geometry().right() + Separator,560,60,60);

    RankPLUS_1 = new QPushButton(">",this);
    RankPLUS_1->setGeometry(Rank->geometry().right() + Separator, 560, 40 , 60);
    connect(RankPLUS_1, &QPushButton::clicked, this, &FourierTransformApp::Add1ToRank);

    RankPLUS_5 = new QPushButton(">>",this);
    RankPLUS_5->setGeometry(RankPLUS_1->geometry().right() + Separator, 560, 40 , 60);
    connect(RankPLUS_5, &QPushButton::clicked, this, &FourierTransformApp::Add5ToRank);
}

void FourierTransformApp::UpdateFourierTransform()
{
    const int SampleLenght = 100;
    QVector<std::complex<float>> odp = Furier.CalulateKrank(FouriterTransformRank);
    //DescreteFourier::ReadComplecVector(odp);
    QVector<int> odpGRAPH = Furier.CalculateInverseFourier(FouriterTransformRank, SampleLenght);
    //qDebug() << odpakacz;
    graf2->drawFromVector(odpGRAPH);
}

void FourierTransformApp::Transform()
{
    graf->VectorizeFromCanvas();
    Furier.UpdateInputVector(*graf->getValuesVector());

    FouriterTransformRank = 0;
    Rank->setText(QString::number(FouriterTransformRank));

    UpdateFourierTransform();
}

void FourierTransformApp::Add1ToRank()
{
    if(FouriterTransformRank + 1 > MAX_RANK) return;
    FouriterTransformRank ++;
    Rank->setText(QString::number(FouriterTransformRank));
    UpdateFourierTransform();
}

void FourierTransformApp::Add5ToRank()
{
    if(FouriterTransformRank + 5 > MAX_RANK) return;
    FouriterTransformRank += 5;
    Rank->setText(QString::number(FouriterTransformRank));
    UpdateFourierTransform();
}

void FourierTransformApp::Sub1ToRank()
{
    if(FouriterTransformRank - 1 < MIN_RANK) return;
    FouriterTransformRank --;
    Rank->setText(QString::number(FouriterTransformRank));
    UpdateFourierTransform();
}

void FourierTransformApp::Sub5ToRank()
{
    if(FouriterTransformRank - 5 < MIN_RANK) return;
    FouriterTransformRank -= 5;
    Rank->setText(QString::number(FouriterTransformRank));
    UpdateFourierTransform();
}

















