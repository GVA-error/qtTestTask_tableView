#include "mainwindow.h"

#include "./Logic/Utilities/loger.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Logger::init();
    initData();
    initUI();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initData()
{
    mData = QSharedPointer<DataTable>(new DataTable);
    mData->init();//10, 10, DataTable::DataType::Random);
}

void MainWindow::initUI()
{
    defaultTableView  = new QTableView(this);
    defaultTableModel = new DefaultTableModel(mData, defaultTableView);
    testTableDelegate = new TestTableDelegate(defaultTableView);

    defaultTableView->setModel(defaultTableModel);
    defaultTableView->setItemDelegate(testTableDelegate);

    setCentralWidget(defaultTableView);
}
