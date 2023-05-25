#ifndef FORM_H
#define FORM_H

#include <QWidget>

#ifdef __cplusplus
extern "C" {
#endif
#include "../smart_calc.h"
#ifdef __cplusplus
}
#endif

namespace Ui {
  class Form;
}

class Form : public QWidget
{
  Q_OBJECT

public:
  explicit Form(QWidget *parent = nullptr);
  ~Form();

private:
 Ui::Form *ui;
 double X, h;
 QVector<double> x, y;

public slots:
 void slot(double Xmin, double Xmax, double Ymin, double Ymax, char *str);
};

#endif // FORM_H
