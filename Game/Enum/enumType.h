/*
创建人：神数不神
创建日期：2024-5-31
无修正
*/
#pragma once
namespace GameClient::GameEnum {
	enum class FontType:quint8  {
		YoungRound_CN,//中文幼圆字体
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