/*************************************************************************
	> File Name: DecoratorPhone.h
	> Author: SAIRRE
	> Mail:496389633@qq.com 
	> Created Time: Tue 16 Jun 2015 09:46:40 AM CST
 ************************************************************************/

#include "Phone.h"
namespace Ch
{
class DecoratorPhone:public Phone
{
public:
	DecoratorPhone();
	~DecoratorPhone();
	virtual ShowDecoreate();

}
}
