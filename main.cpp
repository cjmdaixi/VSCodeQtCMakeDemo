#include <iostream>
#include <QApplication>
#include <QPushButton>

int main(int argc, char **argv)
{
    std::cout<<"Hello CMake";
    QApplication app(argc, argv);

    auto button = new QPushButton("Quit");
    button->setFixedSize(QSize(400, 200));
    button->setText("hello");
    QObject::connect(button, &QPushButton::clicked, &app, &QCoreApplication::quit);
    button->show();
    return app.exec();
}