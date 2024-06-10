/*
�����ˣ���������
�������ڣ�2024-6-10
������
*/
#include "cscrollarea .h"
#include <QWheelEvent>
#include <QScrollBar>
namespace GameClient::Component { 
	CScrollArea::CScrollArea(QWidget* parent):QScrollArea(parent) {
		setAttribute(Qt::WA_AcceptTouchEvents);
		vScrollBar = verticalScrollBar();
	}

	void CScrollArea::wheelEvent(QWheelEvent* event) {
		if (event->angleDelta().y() > 0) { //���Ϲ���
			qDebug() << "Scrolling up";
			emit scrollingUp();
			vScrollBar->blockSignals(true);
			vScrollBar->setValue(vScrollBar->value() - vScrollBar->singleStep());
			vScrollBar->blockSignals(false);
		} else { //���¹���
			qDebug() << "Scrolling down";
			emit scrollingDown();
			vScrollBar->blockSignals(true);
			vScrollBar->setValue(vScrollBar->value() + vScrollBar->singleStep());
			vScrollBar->blockSignals(false);
		}
	}
}