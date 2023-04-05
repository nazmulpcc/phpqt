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

    static Php::Class<MainWindow> _DEFINITION()
    {
        Php::Class<MainWindow> mainwindow ("Qt\\Widgets\\MainWindow");

        mainwindow.method<&MainWindow::__construct>("__construct");
        mainwindow.method<&MainWindow::setCentralWidget>("setCentralWidget", {
            Php::ByVal("widget", "Qt\\Widgets\\Widget")
        });

        mainwindow.method<&MainWindow::setWindowTitle>("setWindowTitle", {
            Php::ByVal("title", Php::Type::String, true)
        });

        return mainwindow;
    }
};