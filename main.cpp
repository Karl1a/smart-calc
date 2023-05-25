#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  QApplication::setWindowIcon(QIcon(":icon.icns"));
  w.show();
  return a.exec();
}
