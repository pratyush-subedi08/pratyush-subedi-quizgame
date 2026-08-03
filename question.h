#ifndef QUESTION_H
#define QUESTION_H

#include <QString>

class Question
{
private:
    QString questionText;
    QString optionA;
    QString optionB;
    QString optionC;
    QString optionD;
    QString correctAnswer;

public:
    Question();

    Question(QString q, QString a, QString b, QString c, QString d, QString ans);

    QString getQuestionText();
    QString getOptionA();
    QString getOptionB();
    QString getOptionC();
    QString getOptionD();
    QString getCorrectAnswer();
};

#endif // QUESTION_H