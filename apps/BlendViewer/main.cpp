#include "../include/core/logging.h"
#include <QCoreApplication>
#include <QDebug>

int main(int argc, char* argv[])
{
	QCoreApplication app(argc, argv);

	qInfo() << "BlendViewer application started.";

	return app.exec();
}