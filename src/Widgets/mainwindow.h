#include<phpcpp.h>
#include <QtWidgets/QMainWindow>

class MainWindow : public Php::Base
{
private:
    QMainWindow* native;
    
public:
    void __construct();
    // void addToolBar(Php::Parameters &params);
    void setCentralWidget(Php::Parameters &params);
    void show();

    QMainWindow* getNative();
    void setNative(QMainWindow *n);

    static Php::Class<MainWindow> _DEFINITION()
    {
        Php::Class<MainWindow> mainwindow ("Qt\\Widgets\\MainWindow");

        mainwindow.method<&MainWindow::__construct>("__construct");
        // mainwindow.method("addToolBar", {
        //     Php::ByVal("title", Php::Type::String)
        // });
        mainwindow.method<&MainWindow::setCentralWidget>("setCentralWidget", {
            Php::ByVal("title", "Qt\\Widgets\\Widget")
        });
        mainwindow.method<&MainWindow::show>("show");

        return mainwindow;
    }
};