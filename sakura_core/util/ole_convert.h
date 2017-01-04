/*!	@file
	@brief OLE�^�iVARIANT, BSTR�Ȃǁj�̕ϊ��֐�

*/
#ifndef SAKURA_OLE_CONVERT_208FE8C1_C742_4ED8_9C9C_25841915706BD_H_
#define SAKURA_OLE_CONVERT_208FE8C1_C742_4ED8_9C9C_25841915706BD_H_

#include <string>
#include "_os/OleTypes.h"

bool variant_to_wstr( VARIANT v, std::wstring& wstr );	// VARIANT�ϐ���BSTR�Ƃ݂Ȃ��Awstring�ɕϊ�����
bool variant_to_astr( VARIANT v, std::string& astr );	// VARIANT�ϐ���BSTR�Ƃ݂Ȃ��Astring�ɕϊ�����
bool variant_to_int( VARIANT v, int& n );	// VARIANT�ϐ��𐮐��Ƃ݂Ȃ��Aint�ɕϊ�����

inline bool variant_to_auto_str( VARIANT v, std::wstring& wstr )
{
	return variant_to_wstr( v, wstr );
}

inline bool variant_to_auto_str( VARIANT v, std::string& astr )
{
	return variant_to_astr( v, astr );
}

#endif /* SAKURA_OLE_CONVERT_208FE8C1_C742_4ED8_9C9C_25841915706BD_H_ */
/*[EOF]*/
