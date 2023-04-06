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

    static Php::Class<MainWindow> _DEFINITION()
    {
        Php::Class<MainWindow> mainwindow ("Qt\\Widgets\\MainWindow");

        mainwindow.method<&MainWindow::__construct>("__construct");
        mainwindow.method<&MainWindow::setCentralWidget>("setCentralWidget", {
            Php::ByVal("widget", "Qt\\Widgets\\Widget")
        });
        
        return mainwindow;
    }
};