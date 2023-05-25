#include "form.h"
#include "ui_form.h"
#include "iostream"

Form::Form(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Form)
{
  ui->setupUi(this);
}
void Form::slot(double Xmin, double Xmax, double Ymin, double Ymax,
			char *str) {
   h = 0.1;
   std::cout << str << std::endl;
   ui->widget->clearGraphs();
   ui->widget->xAxis->setRange(Xmin, Xmax);
   ui->widget->yAxis->setRange(Ymin, Ymax);
   if (input_validation(str) == 0) {
     for (X = Xmin; X <= Xmax; X += h) {
//      std::cout << "dfghiop" << std::endl;
       double Y = algorithm(str, X);
//       printf("Y IS %f", Y);
       if (Y <= Ymin * 2 || Y >= Ymax * 2) {
	 Y = qQNaN();
       }
       x.push_back(X);
       y.push_back(Y);
     }
   }
   ui->widget->addGraph();
   QPen pen;
   pen.setWidth(2);
   pen.setColor(QColor(250, 110, 255));
   ui->widget->graph(0)->setPen(pen);
   ui->widget->graph(0)->addData(x, y);
   ui->widget->replot();
   x.clear();
   y.clear();
 }

Form::~Form()
{
  delete ui;
}


