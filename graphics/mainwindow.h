#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void drawImage(QImage*image);
    void paintEvent(QPaintEvent *event);
private:
    Ui::MainWindow *ui;
    QImage*image;
};

#endif // MAINWINDOW_H
