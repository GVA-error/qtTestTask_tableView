#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSharedPointer>
#include <QScrollArea>
#include <QTableView>
#include "./Logic/Data/datatable.h"
#include "./Gui/QtModels/defaulttablemodel.h"
#include "Gui/QtViews/testtabledelegate.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // Data
    QSharedPointer<DataTable> mData;

    // UI elements
    QTableView* defaultTableView;
    DefaultTableModel* defaultTableModel;
    TestTableDelegate* testTableDelegate;

    // init methods
    void initData();
    void initUI();
};
#endif // MAINWINDOW_H
