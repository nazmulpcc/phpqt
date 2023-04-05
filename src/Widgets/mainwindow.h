#include "../macros.h"
#include "widget.h"
#include<phpcpp.h>
#include <QtWidgets/QMainWindow>

class MainWindow : public Widget
{
private:
    QMainWindow *mainWindow;

public:
    void __construct();
    // void addToolBar(Php::Parameters &params);
    void setCentralWidget(Php::Parameters &params);
    void setWindowTitle(Php::Parameters &params);
    OVERRIDE_METHOD(show)
    OVERRIDE_METHOD_WITH_PARAMS(setGeometry)

    static Php::Class<MainWindow> _DEFINITION()
    {
        Php::Class<MainWindow> mainwindow ("Qt\\Widgets\\MainWindow");

        mainwindow.method<&MainWindow::__construct>("__construct");
        mainwindow.method<&MainWindow::setCentralWidget>("setCentralWidget", {
            Php::ByVal("widget", "Qt\\Widgets\\Widget")
        });
        mainwindow.method<&MainWindow::setGeometry>("setGeometry", {
            Php::ByVal("x", Php::Type::Numeric, true),
            Php::ByVal("y", Php::Type::Numeric, true),
            Php::ByVal("w", Php::Type::Numeric, true),
            Php::ByVal("h", Php::Type::Numeric, true),
        });
        mainwindow.method<&MainWindow::setWindowTitle>("setWindowTitle", {
            Php::ByVal("title", Php::Type::String, true)
        });
        mainwindow.method<&MainWindow::show>("show");

        return mainwindow;
    }
};