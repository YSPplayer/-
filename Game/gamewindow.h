#pragma once
#include <QtWidgets/QWidget>
#include "ui_game.h"

namespace GameClient { 
    class GameWindow : public QWidget {
        Q_OBJECT

    public:
        GameWindow(QWidget *parent = nullptr);
        ~GameWindow();

    private:
        Ui::GameClass ui;
        void SetDeckWinodw();
        void SetWidgetShadow(QWidget* widget, const QColor& color, bool inverted = false, qint32 size = 2);
    };
}