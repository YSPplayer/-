/*
创建人：神数不神
创建日期：2024-9-21
无修正
*/
#include "gamemenuwindow.h"
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
GameMenuWindow::GameMenuWindow(QWidget *parent)
	: QWidget(parent) {
	ui.setupUi(this);
    //// 使用 QVBoxLayout 来垂直排列按钮
    //QVBoxLayout* layout = new QVBoxLayout(this);

    //// 创建多个按钮并添加到布局中
    //for (int i = 1; i <= 10; ++i) {
    //    QPushButton* button = new QPushButton(QString("Button %1").arg(i));
    //    layout->addWidget(button);
    //}

    //// 设置布局
    //this->setLayout(layout);

    //// 创建 QScrollArea，并设置其内容为之前创建的 QWidget
    //QScrollArea* scrollArea = new QScrollArea;
    //scrollArea->setWidget(this);
    //scrollArea->setWidgetResizable(true);  // 允许滚动区域自适应内容大小
    //scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);  // 始终显示垂直滚动条

    //// 设置 QScrollArea 的窗口大小并显示
    //scrollArea->resize(200, 300);
    //scrollArea->show();
}

GameMenuWindow::~GameMenuWindow() {

}
