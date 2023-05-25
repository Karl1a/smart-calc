#include "mainwindow.h"
#include "../smart_calc.h"
#include "ui_mainwindow.h"
#include "iostream"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

  graph = new Form;
  connect(this, &MainWindow::signal, graph, &Form::slot);
    ui->setupUi(this);
      connect(ui->button_0, SIGNAL(clicked()), this, SLOT(digit_numbers()));
      connect(ui->button_1, SIGNAL(clicked()), this, SLOT(digit_numbers()));
      connect(ui->button_2, SIGNAL(clicked()), this, SLOT(digit_numbers()));
      connect(ui->button_3, SIGNAL(clicked()), this, SLOT(digit_numbers()));
      connect(ui->button_4, SIGNAL(clicked()), this, SLOT(digit_numbers()));
      connect(ui->button_5, SIGNAL(clicked()), this, SLOT(digit_numbers()));
      connect(ui->button_6, SIGNAL(clicked()), this, SLOT(digit_numbers()));
      connect(ui->button_7, SIGNAL(clicked()), this, SLOT(digit_numbers()));
      connect(ui->button_8, SIGNAL(clicked()), this, SLOT(digit_numbers()));
      connect(ui->button_9, SIGNAL(clicked()), this, SLOT(digit_numbers()));
      connect(ui->button_add, SIGNAL(clicked()), this, SLOT(arithmetic_operations()));
      connect(ui->button_minus, SIGNAL(clicked()), this, SLOT(arithmetic_operations()));
      connect(ui->button_multiply, SIGNAL(clicked()), this, SLOT(arithmetic_operations()));
      connect(ui->button_divide, SIGNAL(clicked()), this, SLOT(arithmetic_operations()));
      connect(ui->button_equal, SIGNAL(clicked()), this, SLOT(result()));
      connect(ui->button_delete_all, SIGNAL(clicked()), this, SLOT(on_button_delete_all_clicked()));
      connect(ui->open_parent, SIGNAL(clicked()), this, SLOT(arithmetic_operations()));
      connect(ui->close_parent, SIGNAL(clicked()), this, SLOT(arithmetic_operations()));
      connect(ui->button_modulo, SIGNAL(clicked()), this, SLOT(arithmetic_operations()));
      connect(ui->button_sin, SIGNAL(clicked()), this, SLOT(trigonometry_operations()));
      connect(ui->button_cos, SIGNAL(clicked()), this, SLOT(trigonometry_operations()));
      connect(ui->button_tan, SIGNAL(clicked()), this, SLOT(trigonometry_operations()));
      connect(ui->button_asin, SIGNAL(clicked()), this, SLOT(trigonometry_operations()));
      connect(ui->button_acos, SIGNAL(clicked()), this, SLOT(trigonometry_operations()));
      connect(ui->button_atan, SIGNAL(clicked()), this, SLOT(trigonometry_operations()));
      connect(ui->button_sqrt, SIGNAL(clicked()), this, SLOT(trigonometry_operations()));
      connect(ui->button_log, SIGNAL(clicked()), this, SLOT(trigonometry_operations()));
      connect(ui->button_ln, SIGNAL(clicked()), this, SLOT(trigonometry_operations()));
      connect(ui->button_graph, SIGNAL(clicked()), this, SLOT(on_button_graph_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_numbers()
{
    QPushButton *button = (QPushButton *)sender();
    QString new_label = ui->label->text() + button->text();
    ui->label->setText(new_label);
}


void MainWindow::on_pushButton_42_clicked()
{
    if(!(ui->label->text().contains('.'))) {
	ui->label->setText(ui->label->text() + ".");
    }
}

void MainWindow::arithmetic_operations() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  new_label = ui->label->text();
  if (button->text() == "/" && !(ui->label->text().endsWith("/"))) {
    new_label += "/";
  } else if (button->text() == "*" &&
	     !(ui->label->text().endsWith("*"))) {
    new_label += "*";
  } else if (button->text() == "+" &&
	     !(ui->label->text().endsWith("+"))) {
    new_label += "+";
  } else if (button->text() == "-" &&
	     !(ui->label->text().endsWith("-"))) {
    new_label += "-";
  } else if (button->text() == "(") {
      new_label += "(";
    } else if (button->text() == ")")
    {new_label += ")";
    } else if (button->text() == "%" && !(ui->label->text().endsWith("%")))
      new_label += "%";

  ui->label->setText(new_label);
}

void MainWindow::trigonometry_operations() {
  QPushButton *button = (QPushButton *)sender();
  QString new_label;
  new_label = ui->label->text();

  if(button->text() == "sin" && !(ui->label->text().endsWith("sin(")))  {
    new_label += "sin(";
    } else if(button->text() == "cos" && !(ui->label->text().endsWith("cos(")))  {
    new_label += "cos(";
    } else if(button->text() == "tan" && !(ui->label->text().endsWith("tan(")))  {
    new_label += "tan(";
    } else if(button->text() == "asin" && !(ui->label->text().endsWith("asin(")))  {
    new_label += "asin(";
    } else if(button->text() == "acos" && !(ui->label->text().endsWith("acos(")))  {
    new_label += "acos(";
    } else if(button->text() == "log" && !(ui->label->text().endsWith("log("))) {
    new_label += "log(";
    } else if (button->text() == "ln" && !(ui->label->text().endsWith("ln(")))  {
      new_label += "ln(";
    } else if (button->text() == "sqrt" && !(ui->label->text().endsWith("sqrt(")))  {
      new_label += "sqrt(";
    }

  ui->label->setText(new_label);
}

void MainWindow::result() {
  std::string str = ui->label->text().toStdString();
  char *expression = &str[0];

  std::string str_1 = ui->get_x->text().toStdString();
  char *res_x = &str_1[0];

  double x = atof(res_x);
  double res = 0.0;
  res = algorithm(expression, x);
  QString num1 = QString::number(res, 'f', 6);
  ui->label->setText(num1);
}


void MainWindow::on_button_delete_all_clicked()
{
    ui->label->setText("");
}

void MainWindow::on_button_x_clicked()
{
  QString new_label;
  new_label = ui->label->text();
  new_label += "x";
  ui->label->setText(new_label);
}


void MainWindow::on_button_pow_clicked()
{

    QString new_label;
    new_label = ui->label->text();
    new_label += "^";
    ui->label->setText(new_label);
}

void MainWindow::on_button_graph_clicked()
{
  graph->show();
  double Xmin = ui->x_min->text().toDouble();
  double Xmax = ui->x_max->text().toDouble();
  double Ymin = ui->y_min->text().toDouble();
  double Ymax = ui->y_max->text().toDouble();
  QString display_value = ui->label->text();
  QByteArray ds = display_value.toLocal8Bit();
  char *str = ds.data();
  emit signal(Xmin, Xmax, Ymin, Ymax, str);
}

