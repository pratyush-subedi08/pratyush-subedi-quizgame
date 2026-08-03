#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);



    currentQuestionIndex = 0;
    score=0;

    loadQuestions();

    ui->scorelabel->setText(
        "Score: 0 / " + QString::number(questions.size())
        );

    showQuestion();
}

MainWindow::~MainWindow()
{


    delete ui;
}
void MainWindow::loadQuestions()
{
    questions.clear();

    questions.append(
        Question(
            "What is the capital of Nepal?",
            "Kathmandu",
            "Pokhara",
            "Lalitpur",
            "Bhaktapur",
            "A"
            )
        );

    questions.append(
        Question(
            "Which language is used for Qt?",
            "Java",
            "Python",
            "C++",
            "JavaScript",
            "C"
            )
        );

    questions.append(
        Question(
            "How many days are there in a week?",
            "5",
            "6",
            "7",
            "8",
            "C"
            )
        );
}


void MainWindow::showQuestion()
{


    Question q = questions[currentQuestionIndex];

    ui->questionlabel->setText(q.getQuestionText());

    ui->optionAButton->setText(q.getOptionA());
    ui->optionBButton->setText(q.getOptionB());
    ui->optionCButton->setText(q.getOptionC());
    ui->optionDButton->setText(q.getOptionD());

    ui->optionAButton->setChecked(false);
    ui->optionBButton->setChecked(false);
    ui->optionCButton->setChecked(false);
    ui->optionDButton->setChecked(false);
}

void MainWindow::checkAnswer(QString selectedAnswer)
{
    if (selectedAnswer == questions[currentQuestionIndex].getCorrectAnswer())
    {
        score++;
    }

    ui->scorelabel->setText(
        "Score: " + QString::number(score) +
        " / " + QString::number(questions.size())
        );
}
void MainWindow::on_nextButton_clicked()
{
    QString selectedAnswer;

    if (ui->optionAButton->isChecked())
        selectedAnswer = "A";
    else if (ui->optionBButton->isChecked())
        selectedAnswer = "B";
    else if (ui->optionCButton->isChecked())
        selectedAnswer = "C";
    else if (ui->optionDButton->isChecked())
        selectedAnswer = "D";
    else
    {
        QMessageBox::warning(
            this,
            "No Answer Selected",
            "Please select an answer before clicking Next."
            );
        return;
    }

    checkAnswer(selectedAnswer);

    currentQuestionIndex++;

    if (currentQuestionIndex < questions.size())
    {
        showQuestion();
    }
    else
    {
        ui->questionlabel->setText(
            "Quiz Finished!\nYour Score: " +
            QString::number(score) + " / " +
            QString::number(questions.size())
            );

        QFile file("result.txt");

        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);

            out << "Quiz Result\n";
            out << "-----------\n";
            out << "Score: " << score << " / " << questions.size() << "\n";

            file.close();
        }

        ui->optionAButton->hide();
        ui->optionBButton->hide();
        ui->optionCButton->hide();
        ui->optionDButton->hide();

       ui->nextButton->hide();
    }
}
