#include "question.h"

Question::Question()
{
}

Question::Question(QString q, QString a, QString b, QString c, QString d, QString ans)
{
    questionText = q;
    optionA = a;
    optionB = b;
    optionC = c;
    optionD = d;
    correctAnswer = ans;
}

QString Question::getQuestionText()
{
    return questionText;
}

QString Question::getOptionA()
{
    return optionA;
}

QString Question::getOptionB()
{
    return optionB;
}

QString Question::getOptionC()
{
    return optionC;
}

QString Question::getOptionD()
{
    return optionD;
}

QString Question::getCorrectAnswer()
{
    return correctAnswer;
}