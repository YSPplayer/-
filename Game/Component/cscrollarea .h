/*
�����ˣ���������
�������ڣ�2024-6-10
������
*/
#pragma once
#include <QScrollArea>
namespace GameClient::Component {
	class CScrollArea : public QScrollArea {
        Q_OBJECT

    public:
        CScrollArea(QWidget* parent = nullptr);
    private:
        QScrollBar *vScrollBar;
    protected:
        void wheelEvent(QWheelEvent* event) override;
    signals:
        void scrollingUp();
        void scrollingDown();
	};
}
