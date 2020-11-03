#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <tictactoe.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Lib::ticTacToe::TicTacToe>("TTT", 1,0, "TicTacToe");
    Lib::ticTacToe::TicTacToe ticTacToe;
    QQmlApplicationEngine engine;
    engine.rootContext() -> setContextProperty("ticTacToe",&ticTacToe);
    const QUrl url(QStringLiteral("qrc:/Views/MasterView.qml"));
    engine.addImportPath("qrc:/");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
