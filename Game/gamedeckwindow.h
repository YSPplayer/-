/*
�����ˣ���������
�������ڣ�2024-5-24
������
*/
#pragma once
#include <QtWidgets/QWidget>
#include <QFont>
#include <QMap>
#include "ui_game.h"
#include "Enum/enumtype.h"
#include "Component/deckeditcontainer.h"
#include "Component/cardsearchscrollarea.h"

namespace GameClient { 
    using namespace GameClient::GameEnum;
    using namespace GameClient::Component;
    struct WidgetInfo {
        quint32 type;
        QWidget** pwidgetPtr;
    };
    class GameDeckWindow : public QWidget {
        Q_OBJECT

    public:
        GameDeckWindow(QWidget *parent = nullptr);
        ~GameDeckWindow();

    private:
        QMap<QObject*, WidgetInfo> widgetMap;
        Ui::GameClass ui;
        void SetDeckWinodw();
        void SetWidgetState(quint8 wtype,quint8 stype,QWidget* widget, qint32 size = 2);
        void SetWidgetMap();
        void SetWidgetShadow(QWidget* widget, const QColor& color, bool inverted = false, qint32 size = 2);
        qint32 GetComboBoxTextCenterValue(QComboBox* comboBox);
        WidgetInfo GetWidgetInfo(QObject* widget);
        QFont LoadFont(LanguageType ltype,FontType fType);
        QString rootPath;//�����Ŀ¼
        FontType fType;//��������
        LanguageType lType;//��������
        QFont font;//��ǰ����ʹ�õ�����
        DeckEditContainer mainDeckEditContainer;
        DeckEditContainer extraDeckEditContainer;
        DeckEditContainer secondDeckEditContainer;
    protected:
        CardSearchScrollArea cardSearchScrollArea;
    };
}