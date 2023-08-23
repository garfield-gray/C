#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "LocationManager.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    LocationManager locationmanager;

    engine.rootContext()->setContextProperty("LocationManagerModel", &locationmanager);


    const QUrl url(u"qrc:/frtask/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
