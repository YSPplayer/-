#include "gamewindow.h"
#include <QGraphicsDropShadowEffect>
/*
400 x 580
*/
namespace GameClient { 
    GameWindow::GameWindow(QWidget *parent)
        : QWidget(parent) {
        ui.setupUi(this);
        SetDeckWinodw();
    }

    GameWindow::~GameWindow() {

    }

    void GameWindow::SetDeckWinodw() {
        SetWidgetShadow(ui.widget_card_des,QColor(62, 62, 62));
        SetWidgetShadow(ui.button_exit,QColor(115, 115, 122));
        SetWidgetShadow(ui.widget_deck_manage,QColor(62, 62, 62));
        SetWidgetShadow(ui.widget_card_properties,QColor(62, 62, 62));
    }

    /// <summary>
    /// 设置组件阴影
    /// </summary>
    /// <param name="widget"></param>
    /// <param name="color"></param>
    /// <param name="inverted"></param>
    /// <param name="size"></param>
    void GameWindow::SetWidgetShadow(QWidget* widget, const QColor& color, bool inverted, qint32 size) {
        QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(widget);
        inverted ? effect->setOffset(0, size) : effect->setOffset(0, -size);
        effect->setBlurRadius(size);
        effect->setColor(color);
        widget->setGraphicsEffect(effect);
        
    }
}