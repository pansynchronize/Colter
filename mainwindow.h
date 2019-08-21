#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAbout_triggered();

    void on_actionExit_triggered();

    void on_actionHSV_triggered();

    void on_actionHSL_triggered();

    void on_actionBGR_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
