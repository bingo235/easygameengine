#ifndef MOLE2D_MESSAGE_IN_H
#define MOLE2D_MESSAGE_IN_H

/**
 * Mole2D 游戏引擎
 *
 * 这个文件属于整个引擎的一部分
 *
 * 作者：akinggw
 * 建立时间： 2008.6.24
 */

#include <string>

#include "Mole2dCommon.h"

//namespace mole2d
//{
//namespace graphics
//{

#include <iosfwd>

/**
* 用于处理输入信息
*/
class MOLEXPORT CMolMessageIn
{
public:
	/// 初始的构造函数
	CMolMessageIn(void);
	/// 构造函数
	CMolMessageIn(const char *data, int length);

	/// 得到消息ID
	int getId() const { return mId; }
	/// 得到消息的总长度
	int getLength() const { return mLength; }
	/// 读取一个BYTE数据
	int readByte();
	/// 读取一个short数据
	int readShort();
	/// 读取一个long数据
	unsigned long readLong();
	/// 读取一个float数据
	float readFloat();
	/// 读取一个doubel数据
	double readDouble();
	/// 读取一个字符串，如果长度为-1的话，长度就存储在字符串开始的第一个short中
	std::string readString(int length = -1);
	/// 返回没有读取的数据的长度
	int getUnreadLength() const { return mLength - mPos; }

private:
	const char *mData;         /**< 数据包数据 */
	unsigned short mLength;    /**< 数据包的总长度 */
	unsigned short mId;        /**< 数据包的ID */

	unsigned short mPos;       /**< 数据实际读取的位置 */
};

//}
//}

#endif
