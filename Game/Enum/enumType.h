/*
�����ˣ���������
�������ڣ�2024-5-31
������
*/
#pragma once
namespace GameClient::GameEnum {
	enum class FontType:quint8  {
		YoungRound_CN,//������Բ����
	};
	enum class LanguageType:quint8  {
		zh_CN,
		en_US
	};

	enum class ValueType:quint8 {
		Common,
		Undefined,
		Infinity,
	};
}