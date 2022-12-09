#include <QGuiApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    const QUrl test1("https://www.google.fr/");
    const QUrl test2("qrc:/temp/test.txt");
    const QUrl test3(":/temp/test.txt");
    const QUrl test4("qrc:///temp/test.txt");

    QQmlApplicationEngine engine;
    const QUrl url("qrc:/untitled/main.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
