#ifndef DESCRETEFOURIER_H
#define DESCRETEFOURIER_H

#include <complex>
#include <QVector>
#include <qmath.h>

#define MAX_FOU_RANK 200

class DescreteFourier
{
public:
    DescreteFourier();
    void UpdateInputVector(QVector<int> InputVector);
    QVector<std::complex<float>> CalulateKrank(int k);
    int getCalculatedRank();
    QVector<int> CalculateInverseFourier(int k_rank, int SampleLength);

    static void ReadComplecVector( QVector<std::complex<float>> vec);

private:
    std::complex<float> CalculateFor_k(int k);
    QVector<int> InputVector;
    std::complex<float> FourierValues[MAX_FOU_RANK];
    int CalucaltedRank;
};

#endif // DESCRETEFOURIER_H
