/*
�����ˣ���������
�������ڣ�2024-9-21
������
*/
#pragma once
#include <QWidget>
#include "ui_menu.h"

class GameMenuWindow : public QWidget {
	Q_OBJECT

public:
	GameMenuWindow(QWidget *parent = nullptr);
	~GameMenuWindow();

private:
	Ui::menuClass ui;
};
