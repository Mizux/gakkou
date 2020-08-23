//! @file
#include <QApplication>
#include <QTabWidget>

#include "SumWidget.hpp"
#include "MultiplyWidget.hpp"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  app.setOrganizationName("Mizux");
  app.setOrganizationDomain("mizux.net");
  app.setApplicationName("SumApp");

  QTabWidget tab;

  SumWidget* sum = new SumWidget();
  tab.addTab(sum, "Sum");
  MultiplyWidget* mult = new MultiplyWidget();
  tab.addTab(mult, "Multiply");

  tab.show();
  return app.exec();
}
