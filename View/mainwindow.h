#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"

extern "C"
{
#include "../smart_calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString temp;

private:
    Ui::MainWindow *ui;
    Form *graph;
    double xBegin, xEnd, X;

    QVector<double> x, y;

signals:
    void signal(double Xmin, double Xmax, double Ymin, double Ymax, char *str);

private slots:
    void digit_numbers();
    void on_pushButton_42_clicked();
    void arithmetic_operations();
    void result();
    void on_button_delete_all_clicked();
    void trigonometry_operations();
    void on_button_x_clicked();
    void on_button_pow_clicked();
    void on_button_graph_clicked();


};

#endif // MAINWINDOW_H
