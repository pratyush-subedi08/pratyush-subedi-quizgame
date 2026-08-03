#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "question.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_nextButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<Question> questions;
    int currentQuestionIndex;
    int score;

    void loadQuestions();
    void showQuestion();
    void checkAnswer(QString selectedAnswer);
};
#endif // MAINWINDOW_H
