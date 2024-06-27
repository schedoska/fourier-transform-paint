#include "functiongenerator.h"
#include <qmath.h>
#include <QDebug>

#define PI 3.14

FunctionGenerator::FunctionGenerator()
{

}

QVector<int> FunctionGenerator::SineFunction(int SampleSize, float Freq, float Amplitude)
{
    QVector<int> Answer;

    for(int q = 0; q < SampleSize; q++)
    {
        //Answer.push_back(Amplitude * cos(2 * PI * Freq * (float) q) + Amplitude * cos(2 * PI * Freq/2. * (float) q));
        Answer.push_back(pow(q/10,2) - 50);
    }
    return Normalize(&Answer);
}

QVector<int> FunctionGenerator::Normalize(QVector<int> *Values)
{
    QVector<int> Normalized;

    for(int q = 0; q < Values->size(); q++)
    {
        Normalized.push_back(Values->at(q) + 50);
    }

    return Normalized;
}
