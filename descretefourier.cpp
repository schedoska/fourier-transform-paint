#include "descretefourier.h"
#include <QDebug>

#define PI 3.1416

DescreteFourier::DescreteFourier()
{
    CalucaltedRank = -1;
}

void DescreteFourier::UpdateInputVector(QVector<int> InputVector)
{
    this->InputVector = InputVector;
    CalucaltedRank = -1;
}

QVector<std::complex<float>> DescreteFourier::CalulateKrank(int k)
{
    for(int q = CalucaltedRank; q < k; q++)
    {
        FourierValues[q+1] = CalculateFor_k(q+1);
    }
    QVector<std::complex<float>> Answer;
    for(int q = -1; q < k; q++)
    {
        Answer.push_back(FourierValues[q+1]);
    }
    CalucaltedRank = k;
    return Answer;
}

int DescreteFourier::getCalculatedRank()
{
    return CalucaltedRank;
}

QVector<int> DescreteFourier::CalculateInverseFourier(int k_rank, int SampleLength)
{
    QVector<int> Answer;

    if(k_rank > CalucaltedRank)
    {
        qDebug() << "Inverse fourier with higher demanded rank than calculated ERROR";
        return QVector<int>();
    }
    for(int q = 0; q < SampleLength; q++)
    {
        float ans = 0;
        for(int k = 0; k < k_rank + 1; k++)
        {
            ans = ans + (float)FourierValues[k].real() * cos((float)2 * PI * q * k / SampleLength)
                      + (float)FourierValues[k].imag() * sin((float)2 * PI * q * k / SampleLength);
        }
        Answer.push_front(ans);
    }
    return Answer;
}

void DescreteFourier::ReadComplecVector(QVector<std::complex<float> > vec)
{
    qDebug() << "DEBUG VECTOR READ OF COMPLEX";
    for(int q = 0; q < vec.size(); q++)
    {
        qDebug() << "RANK: " << q << " real: " << vec.at(q).real() << " imag: " << vec.at(q).imag();
    }
    qDebug() << "-----------------------------";
}

std::complex<float> DescreteFourier::CalculateFor_k(int k)
{
    //qDebug() << "Calculating for k = " << k;

    std::complex<float> Answer;
    std::complex<float> Temporary;
    float _2PIdivN = (2. * PI) / (float) InputVector.size();

    for(int n = 0; n < InputVector.size(); n++)
    {
        Temporary.real(InputVector.at(n) * cos(_2PIdivN*k*n));
        Temporary.imag(-InputVector.at(n) * sin(_2PIdivN*k*n));
        Answer += Temporary;
    }
    if(k > 0) Answer *= (float)2;  // Sztucznie dodane !!!! w razie co usunac
    return Answer / (float) InputVector.size();
}






















