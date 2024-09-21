/*
创建人：神数不神
创建日期：2024-9-21
无修正
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
