/*
创建人：神数不神
创建日期：2024-6-10
无修正
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
		if (event->angleDelta().y() > 0) { //向上滚动
			qDebug() << "Scrolling up";
			emit scrollingUp();
			vScrollBar->blockSignals(true);
			vScrollBar->setValue(vScrollBar->value() - vScrollBar->singleStep());
			vScrollBar->blockSignals(false);
		} else { //向下滚动
			qDebug() << "Scrolling down";
			emit scrollingDown();
			vScrollBar->blockSignals(true);
			vScrollBar->setValue(vScrollBar->value() + vScrollBar->singleStep());
			vScrollBar->blockSignals(false);
		}
	}
}