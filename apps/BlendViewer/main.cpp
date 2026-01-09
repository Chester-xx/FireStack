#include "../include/core/logging.h"
#include <QCoreApplication>

int main(int argc, char* argv[])
{
	QCoreApplication app(argc, argv);

	logging::print("Application Output Test");

	return app.exec();
}