/*
�����ˣ���������
�������ڣ�2024-9-21
������
*/
#include "gamemenuwindow.h"
#include <QScrollArea>
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
GameMenuWindow::GameMenuWindow(QWidget *parent)
	: QWidget(parent) {
	ui.setupUi(this);
    //// ʹ�� QVBoxLayout ����ֱ���а�ť
    //QVBoxLayout* layout = new QVBoxLayout(this);

    //// ���������ť����ӵ�������
    //for (int i = 1; i <= 10; ++i) {
    //    QPushButton* button = new QPushButton(QString("Button %1").arg(i));
    //    layout->addWidget(button);
    //}

    //// ���ò���
    //this->setLayout(layout);

    //// ���� QScrollArea��������������Ϊ֮ǰ������ QWidget
    //QScrollArea* scrollArea = new QScrollArea;
    //scrollArea->setWidget(this);
    //scrollArea->setWidgetResizable(true);  // ���������������Ӧ���ݴ�С
    //scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);  // ʼ����ʾ��ֱ������

    //// ���� QScrollArea �Ĵ��ڴ�С����ʾ
    //scrollArea->resize(200, 300);
    //scrollArea->show();
}

GameMenuWindow::~GameMenuWindow() {

}
