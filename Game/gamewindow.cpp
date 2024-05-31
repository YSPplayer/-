/*
创建人：神数不神
创建日期：2024-5-24
无修正
*/
#include "gamewindow.h"
#include <QGraphicsDropShadowEffect>
#include <QFontDatabase>
#include "Tag/dfwindow.h"
namespace GameClient { 
    using namespace GameClient::Tag;
    GameWindow::GameWindow(QWidget *parent)
        : QWidget(parent) {
        rootPath = QCoreApplication::applicationDirPath();
        ui.setupUi(this);
        fType = FontType::YoungRound_CN;
        lType = LanguageType::zh_CN;
        font = LoadFont(lType,fType);
        SetWidgetMap();
        SetDeckWinodw();
    }

    GameWindow::~GameWindow() {

    }

    /// <summary>
    /// 设置卡组编辑界面样式
    /// </summary>
    void GameWindow::SetDeckWinodw() {
        QList<QWidget*> widgets = ui.widget_game_deck->findChildren<QWidget*>();
        for (auto widget : widgets) {
            if(!widget) continue;
            const WidgetInfo& info = GetWidgetInfo(widget);
            quint8 itype = info.type;
            if(itype == GAME_WIDGET_COMMON) {
                SetWidgetShadow(widget,QColor(62, 62, 62));
            } else if(itype == GAME_BUTTON_COMMON) {
                const QColor& cLightGrey = QColor(115, 115, 122);
                if(widget == ui.button_exit)  {
                    SetWidgetShadow(widget,cLightGrey);
                } else {
                    SetWidgetShadow(widget,cLightGrey,false,1);
                }
                qint32 fsize = 10;
                if(fType == FontType::YoungRound_CN) fsize = 14;
                SetWidgetFont(widget,fsize);
                widget->setStyleSheet(R"(QPushButton { color: rgb(199, 195, 195);
                                            background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #4B4B54, stop:1 #272727);
                                             border-radius:3px;                    
 })");
            }
        }
    }

    /// <summary>
    /// 设置映射的UI
    /// </summary>
    void GameWindow::SetWidgetMap() {
        widgetMap[ui.widget_card_des] = { GAME_WIDGET_COMMON, &ui.widget_card_des };
        widgetMap[ui.widget_deck_manage] = { GAME_WIDGET_COMMON, &ui.widget_deck_manage };
        widgetMap[ui.widget_card_properties] = { GAME_WIDGET_COMMON, &ui.widget_card_properties };

        widgetMap[ui.button_exit] = { GAME_BUTTON_COMMON,  reinterpret_cast<QWidget**>(&ui.button_exit) };
        widgetMap[ui.button_manage] = { GAME_BUTTON_COMMON, reinterpret_cast<QWidget**>(&ui.button_manage) };
        widgetMap[ui.button_save] = { GAME_BUTTON_COMMON,reinterpret_cast<QWidget**>(&ui.button_save) };
        widgetMap[ui.button_saveas] = { GAME_BUTTON_COMMON,  reinterpret_cast<QWidget**>(&ui.button_saveas) };
        widgetMap[ui.button_delete] = { GAME_BUTTON_COMMON, reinterpret_cast<QWidget**>(&ui.button_delete) };
        widgetMap[ui.button_disruption] = { GAME_BUTTON_COMMON,reinterpret_cast<QWidget**>(&ui.button_disruption) };
        widgetMap[ui.button_sort] = { GAME_BUTTON_COMMON,  reinterpret_cast<QWidget**>(&ui.button_sort) };
        widgetMap[ui.button_empty] = { GAME_BUTTON_COMMON, reinterpret_cast<QWidget**>(&ui.button_empty) };
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

    /// <summary>
    /// 设置当前窗口的字体
    /// </summary>
    /// <param name="widget"></param>
    /// <param name="size"></param>
    void GameWindow::SetWidgetFont(QWidget* widget, qint32 size) {
        font.setPointSize(size);
        font.setBold(false);
        widget->setFont(font);
    }

    /// <summary>
    /// 获取当前ui类别
    /// </summary>
    /// <param name="widget"></param>
    /// <returns></returns>
    WidgetInfo GameWindow::GetWidgetInfo(QObject* widget) {
        if (widgetMap.contains(widget)) return widgetMap[widget];
        return { GAME_WIDGET_NONE, nullptr };
    }

    /// <summary>
    /// 加载字体
    /// </summary>
    /// <param name="ltype"></param>
    /// <param name="fType"></param>
    /// <returns></returns>
    QFont GameWindow::LoadFont(LanguageType ltype,FontType fType) {
        QString fpath = rootPath + "/Resources/Font/";
        if (ltype == LanguageType::zh_CN) {
            if (fType == FontType::YoungRound_CN) fpath += "YoungRound_CN.TTF";
        }
        qint32 fontId = QFontDatabase::addApplicationFont(fpath);
        QStringList fontFamilyList = QFontDatabase::applicationFontFamilies(fontId);
        if (fontId != -1 && !fontFamilyList.isEmpty()) {
            QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
            return QFont(fontFamily);
        }
        else {
            return QApplication::font();
        }
    }
}