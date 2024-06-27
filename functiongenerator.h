#ifndef FUNCTIONGENERATOR_H
#define FUNCTIONGENERATOR_H

#include <QVector>

class FunctionGenerator
{
public:
    FunctionGenerator();
    QVector<int> SineFunction(int SampleSize, float Freq, float Amplitude);
    QVector<int> Normalize(QVector<int> *Values);
};

#endif // FUNCTIONGENERATOR_H
