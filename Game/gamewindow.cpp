/*
�����ˣ���������
�������ڣ�2024-5-24
������
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
    /// ���ÿ���༭������ʽ
    /// </summary>
    void GameWindow::SetDeckWinodw() {
        QList<QWidget*> widgets = ui.widget_game_deck->findChildren<QWidget*>();
        for (auto widget : widgets) {
            if(!widget) continue;
            const WidgetInfo& info = GetWidgetInfo(widget);
            quint8 itype = info.type;
            qint32 fsize = 10;
            if(fType == FontType::YoungRound_CN) fsize = 14;
            if(itype != GAME_WIDGET_COMMON) SetWidgetFont(widget,fsize);
            if(itype == GAME_WIDGET_COMMON) {
                SetWidgetShadow(widget,QColor(62, 62, 62));
            } else if(itype == GAME_BUTTON_COMMON) {
                const QColor& cLightGrey = QColor(115, 115, 122);
                if(widget == ui.button_exit)  {
                    SetWidgetShadow(widget,cLightGrey);
                } else {
                    SetWidgetShadow(widget,cLightGrey,false,1);
                }
                widget->setStyleSheet(R"(QPushButton { color: rgb(199, 195, 195);
                                            background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #4B4B54, stop:1 #272727);
                                             border-radius:3px;                    
 })");
            } else if(itype == GAME_LABEL_COMMON) {
                widget->setStyleSheet("QLabel { color: rgb(199, 195, 195);}");
            } else if(itype == GAME_COMBOX_COMMON) {
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
            } else if(itype == GAME_LINEEDIT_COMMON) {
                SetWidgetShadow(widget,QColor(115, 115, 122),false,1);
                widget->setStyleSheet(R"(QLineEdit { color: rgb(199, 195, 195);
                                            background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #4B4B54, stop:1 #272727);
                                             border-radius:3px;})");
            }
        }
    }

    /// <summary>
    /// ����ӳ���UI
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

        widgetMap[ui.label_deck_class] = { GAME_LABEL_COMMON,  reinterpret_cast<QWidget**>(&ui.label_deck_class) };
        widgetMap[ui.label_deck_list] = { GAME_LABEL_COMMON, reinterpret_cast<QWidget**>(&ui.label_deck_list) };

        widgetMap[ui.comboBox_deck_class] = { GAME_COMBOX_COMMON, reinterpret_cast<QWidget**>(&ui.comboBox_deck_class) };
        widgetMap[ui.comboBox_deck_list] = { GAME_COMBOX_COMMON, reinterpret_cast<QWidget**>(&ui.comboBox_deck_list) };

        widgetMap[ui.lineEdit_saveas] = { GAME_LINEEDIT_COMMON, reinterpret_cast<QWidget**>(&ui.lineEdit_saveas) };
    }

    /// <summary>
    /// ���������Ӱ
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
    /// ���õ�ǰ���ڵ�����
    /// </summary>
    /// <param name="widget"></param>
    /// <param name="size"></param>
    void GameWindow::SetWidgetFont(QWidget* widget, qint32 size) {
        font.setPointSize(size);
        font.setBold(false);
        widget->setFont(font);
    }

    /// <summary>
    /// ��ȡcomboBox����ı����е�λ��
    /// </summary>
    /// <param name="comboBox"></param>
    /// <returns></returns>
    qint32 GameWindow::GetComboBoxTextCenterValue(QComboBox* comboBox) {
        qint32 pleft = 0;
        QFontMetrics metrics(comboBox->font());
        qint32 pixelWidth  = metrics.horizontalAdvance(comboBox->currentText());
        //30 ��ͼƬ�����ĺϼƴ�С
        return (comboBox->width() - 30 - pixelWidth) / 2;
    }

    /// <summary>
    /// ��ȡ��ǰui���
    /// </summary>
    /// <param name="widget"></param>
    /// <returns></returns>
    WidgetInfo GameWindow::GetWidgetInfo(QObject* widget) {
        if (widgetMap.contains(widget)) return widgetMap[widget];
        return { GAME_WIDGET_NONE, nullptr };
    }

    /// <summary>
    /// ��������
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