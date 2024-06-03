/*
创建人：神数不神
创建日期：2024-5-24
无修正
*/
#include "gamewindow.h"
#include <QGraphicsDropShadowEffect>
#include <QFontDatabase>
#include <QBuffer>
#include "Tag/dfwindow.h"
#include "Component/cdelegate.h"
namespace GameClient { 
    using namespace GameClient::Tag;
    using namespace GameClient::Component;
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
            qint32 fsize = 10;
            if(fType == FontType::YoungRound_CN) fsize = 14;
            if(itype != GAME_COMPONENT_WIDGET) SetWidgetFont(widget,fsize);
            if(itype == GAME_COMPONENT_WIDGET) {
                SetWidgetShadow(widget,QColor(62, 62, 62));
            } else if(itype == GAME_COMPONENT_BUTTON) {
                widget->setAttribute(Qt::WA_Hover, true);
                widget->setCursor(Qt::PointingHandCursor);
                qint32 size = widget == ui.button_exit ? 2 : 1;
                SetWidgetState(itype,COMPONENT_STATE_COMMON,widget,size);
                connect(reinterpret_cast<QPushButton*>(widget),&QPushButton::pressed,this,[this,itype,widget,size] {SetWidgetState(itype,COMPONENT_STATE_ACTIVATE,widget,size);});
                connect(reinterpret_cast<QPushButton*>(widget),&QPushButton::released,this,[this,itype,widget,size] {SetWidgetState(itype,COMPONENT_STATE_COMMON,widget,size);});
            } else if(itype == GAME_COMPONENT_LABEL) {
                widget->setStyleSheet("QLabel { color: rgb(199, 195, 195); border: none; }");
            } else if(itype == GAME_COMPONENT_COMBOX) {
                widget->setCursor(Qt::PointingHandCursor);
                QComboBox* comboBox = qobject_cast<QComboBox*>(widget);
                if (!comboBox) continue;
                SetWidgetShadow(comboBox,QColor(115, 115, 122),false,1);
                comboBox->setStyleSheet(QString(R"(QComboBox { border-radius: 5px;background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #4B4B54, stop:1 #272727); padding-left:%1px; color:rgb(199, 195, 195);}
                QComboBox::drop-down {width: 40px; border-top-right-radius: 5px; border-bottom-right-radius: 5px;}
                QComboBox::down-arrow { image: url(%2); background-position: center;background-repeat: no-repeat;}
                QComboBox QAbstractItemView { border:none; color:rgb(199, 195, 195); background-color: #4B4B54;}
                )").arg(QString::number(GetComboBoxTextCenterValue(comboBox))).arg(rootPath + "/Resources/UI/arrowDown.png"));
                auto delegate = new ComboBoxDelegate();
                delegate->SetFont(&font, 13);
                delegate->SetSelectColor(QColor(240, 126, 51));
                delegate->SetItemHeight(30);
                comboBox->setItemDelegate(delegate);
            } else if(itype == GAME_COMPONENT_LINEEDIT) {
                SetWidgetShadow(widget,QColor(115, 115, 122),false,1);
                widget->setStyleSheet(R"(QLineEdit { color: rgb(199, 195, 195);
                                            background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #4B4B54, stop:1 #272727);
                                             border-radius:3px;})");
            }
        }
    }

    /// <summary>
    /// 设置组件多种状态下的样式状态
    /// </summary>
    void GameWindow::SetWidgetState(quint8 wtype,quint8 stype,QWidget* widget, qint32 size) {
        bool enable = stype == COMPONENT_STATE_COMMON;
        stype == COMPONENT_STATE_DISABLE ? widget->setEnabled(false) : widget->setEnabled(true);
        QColor color = QColor();
        if(enable) {
            if(wtype != GAME_COMPONENT_LINEEDIT) widget->setCursor(Qt::PointingHandCursor);
            if(wtype == GAME_COMPONENT_BUTTON) {
                widget->setStyleSheet(R"(QPushButton { color: rgb(199, 195, 195);
                                            background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #4B4B54, stop:1 #272727);
                                             border-radius:3px; } 
                                         QPushButton:hover {  color: rgb(223, 221, 221); 
                                            background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #737381, stop:1 #333232); 
                                             border-radius:3px;})");
                color = QColor(115, 115, 122);
            }
        } else {
            widget->unsetCursor();
            if(wtype == GAME_COMPONENT_BUTTON) {
                widget->setStyleSheet(R"(QPushButton { color: rgb(199,195, 195); 
                                       padding-left:2px;padding-top:5px;background-color:#313234; border-radius:3px; })");
                color = QColor(70, 71, 73);
            }
        }
  
        SetWidgetShadow(widget,color,!enable,size); 
    }

    /// <summary>
    /// 设置映射的UI
    /// </summary>
    void GameWindow::SetWidgetMap() {
        widgetMap[ui.widget_card_des] = { GAME_COMPONENT_WIDGET, &ui.widget_card_des };
        widgetMap[ui.widget_deck_manage] = { GAME_COMPONENT_WIDGET, &ui.widget_deck_manage };
        widgetMap[ui.widget_card_properties] = { GAME_COMPONENT_WIDGET, &ui.widget_card_properties };

        widgetMap[ui.button_exit] = { GAME_COMPONENT_BUTTON,  reinterpret_cast<QWidget**>(&ui.button_exit) };
        widgetMap[ui.button_manage] = { GAME_COMPONENT_BUTTON, reinterpret_cast<QWidget**>(&ui.button_manage) };
        widgetMap[ui.button_save] = { GAME_COMPONENT_BUTTON,reinterpret_cast<QWidget**>(&ui.button_save) };
        widgetMap[ui.button_saveas] = { GAME_COMPONENT_BUTTON,  reinterpret_cast<QWidget**>(&ui.button_saveas) };
        widgetMap[ui.button_delete] = { GAME_COMPONENT_BUTTON, reinterpret_cast<QWidget**>(&ui.button_delete) };
        widgetMap[ui.button_disruption] = { GAME_COMPONENT_BUTTON,reinterpret_cast<QWidget**>(&ui.button_disruption) };
        widgetMap[ui.button_sort] = { GAME_COMPONENT_BUTTON,  reinterpret_cast<QWidget**>(&ui.button_sort) };
        widgetMap[ui.button_empty] = { GAME_COMPONENT_BUTTON, reinterpret_cast<QWidget**>(&ui.button_empty) };
        widgetMap[ui.button_reset] = { GAME_COMPONENT_BUTTON,  reinterpret_cast<QWidget**>(&ui.button_reset) };
        widgetMap[ui.button_search] = { GAME_COMPONENT_BUTTON, reinterpret_cast<QWidget**>(&ui.button_search) };

        widgetMap[ui.label_deck_class] = { GAME_COMPONENT_LABEL,  reinterpret_cast<QWidget**>(&ui.label_deck_class) };
        widgetMap[ui.label_deck_list] = { GAME_COMPONENT_LABEL, reinterpret_cast<QWidget**>(&ui.label_deck_list) };
        widgetMap[ui.label_deck_type] = { GAME_COMPONENT_LABEL,  reinterpret_cast<QWidget**>(&ui.label_deck_type) };
        widgetMap[ui.label_deck_attribute] = { GAME_COMPONENT_LABEL, reinterpret_cast<QWidget**>(&ui.label_deck_attribute) };
        widgetMap[ui.label_deck_race] = { GAME_COMPONENT_LABEL, reinterpret_cast<QWidget**>(&ui.label_deck_race) };
        widgetMap[ui.label_deck_star] = { GAME_COMPONENT_LABEL, reinterpret_cast<QWidget**>(&ui.label_deck_star) };
        widgetMap[ui.label_deck_forbid] = { GAME_COMPONENT_LABEL, reinterpret_cast<QWidget**>(&ui.label_deck_forbid) };
        widgetMap[ui.label_deck_ad] = { GAME_COMPONENT_LABEL, reinterpret_cast<QWidget**>(&ui.label_deck_ad) };
        widgetMap[ui.label_deck_keyword] = { GAME_COMPONENT_LABEL, reinterpret_cast<QWidget**>(&ui.label_deck_keyword) };
        widgetMap[ui.label_main_deck_text] = { GAME_COMPONENT_LABEL, reinterpret_cast<QWidget**>(&ui.label_main_deck_text) };
        widgetMap[ui.label_extra_deck_text] = { GAME_COMPONENT_LABEL, reinterpret_cast<QWidget**>(&ui.label_extra_deck_text) };
        widgetMap[ui.label_second_deck_text] = { GAME_COMPONENT_LABEL, reinterpret_cast<QWidget**>(&ui.label_second_deck_text) };
        widgetMap[ui.label_search_text] = { GAME_COMPONENT_LABEL, reinterpret_cast<QWidget**>(&ui.label_search_text) };

        widgetMap[ui.comboBox_deck_class] = { GAME_COMPONENT_COMBOX, reinterpret_cast<QWidget**>(&ui.comboBox_deck_class) };
        widgetMap[ui.comboBox_deck_list] = { GAME_COMPONENT_COMBOX, reinterpret_cast<QWidget**>(&ui.comboBox_deck_list) };
        widgetMap[ui.comboBox_deck_type_all] = { GAME_COMPONENT_COMBOX, reinterpret_cast<QWidget**>(&ui.comboBox_deck_type_all) };
        widgetMap[ui.comboBox_deck_type_detail] = { GAME_COMPONENT_COMBOX, reinterpret_cast<QWidget**>(&ui.comboBox_deck_type_detail) };
        widgetMap[ui.comboBox_deck_attribute] = { GAME_COMPONENT_COMBOX, reinterpret_cast<QWidget**>(&ui.comboBox_deck_attribute) };
        widgetMap[ui.comboBox_deck_race] = { GAME_COMPONENT_COMBOX, reinterpret_cast<QWidget**>(&ui.comboBox_deck_race) };
        widgetMap[ui.comboBox_deck_star] = { GAME_COMPONENT_COMBOX, reinterpret_cast<QWidget**>(&ui.comboBox_deck_star) };
        widgetMap[ui.comboBox_deck_forbid] = { GAME_COMPONENT_COMBOX, reinterpret_cast<QWidget**>(&ui.comboBox_deck_forbid) };
        widgetMap[ui.comboBox_deck_search_sort] = { GAME_COMPONENT_COMBOX, reinterpret_cast<QWidget**>(&ui.comboBox_deck_search_sort) };

        widgetMap[ui.lineEdit_saveas] = { GAME_COMPONENT_LINEEDIT, reinterpret_cast<QWidget**>(&ui.lineEdit_saveas) };
        widgetMap[ui.lineEdit_keyword] = { GAME_COMPONENT_LINEEDIT, reinterpret_cast<QWidget**>(&ui.lineEdit_keyword) };
        widgetMap[ui.lineEdit_deck_attack] = { GAME_COMPONENT_LINEEDIT, reinterpret_cast<QWidget**>(&ui.lineEdit_deck_attack) };
        widgetMap[ui.lineEdit_deck_defense] = { GAME_COMPONENT_LINEEDIT, reinterpret_cast<QWidget**>(&ui.lineEdit_deck_defense) };
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
    /// 获取comboBox组件文本居中的位置
    /// </summary>
    /// <param name="comboBox"></param>
    /// <returns></returns>
    qint32 GameWindow::GetComboBoxTextCenterValue(QComboBox* comboBox) {
        qint32 pleft = 0;
        QFontMetrics metrics(comboBox->font());
        qint32 pixelWidth  = metrics.horizontalAdvance(comboBox->currentText());
        //30 是图片与间隔的合计大小
        return (comboBox->width() - 30 - pixelWidth) / 2;
    }

    /// <summary>
    /// 获取当前ui类别
    /// </summary>
    /// <param name="widget"></param>
    /// <returns></returns>
    WidgetInfo GameWindow::GetWidgetInfo(QObject* widget) {
        if (widgetMap.contains(widget)) return widgetMap[widget];
        return { GAME_COMPONENT_NONE, nullptr };
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