//! @file
#include "SumWidget.hpp"
#include <QApplication>

int
main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	app.setOrganizationName("Mizux");
	app.setOrganizationDomain("mizux.net");
	app.setApplicationName("SumApp");

	SumWidget main;
	main.show();

	return app.exec();
}
