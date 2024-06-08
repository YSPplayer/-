/*
�����ˣ���������
�������ڣ�2024-6-5
������
*/
#pragma once
#include <QWidget>
#include <QCoreApplication>
namespace GameClient::Tool {
	class QUtil {
/// <summary>
/// ��õ�ǰ�������еĸ�Ŀ¼
/// </summary>
/// <returns></returns>
#define QUtilGetRootPath QCoreApplication::applicationDirPath
		public:
		/// <summary>
		/// ���õ�ǰ���ڵ�����
		/// </summary>
		/// <param name="pfont"></param>
		/// <param name="widget"></param>
		/// <param name="size"></param>
		static void SetWidgetFont(QFont* pfont,QWidget* widget, qint32 size) {
			pfont->setPointSize(size);
			widget->setFont(*pfont);
		};
		private:

	};

}