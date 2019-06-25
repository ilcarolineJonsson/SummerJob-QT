#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QtQml>
#include <QQmlComponent>
#include <QQmlEngine>
#include <QQuickWindow>
#include <QSurfaceFormat>
#include "udp.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

//    qmlRegisterType<UDP>("com.UDP", 1, 0, "UDP");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    QQmlContext* context =engine.rootContext();
    UDP dt;
    context->setContextProperty("udp",&dt);
    engine.load(url);

    return app.exec();

}
