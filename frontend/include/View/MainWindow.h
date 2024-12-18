#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ViewModel/MainViewModel.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // This also creates the view model.
    MainWindow(QWidget *parent = nullptr);
    // This also destroys the view model.
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // The view model behind the window.
    // This refers to the same object throughout the entire existence of the window;
    // mode changes are achieved by changing the HsCalcStateWrapper instance under the view model.
    MainViewModel *viewModel;
};
#endif // MAINWINDOW_H
