#ifndef _NOTIFYINTERFACE_HPP_
#define _NOTIFYINTERFACE_HPP_


class NotifyInterface{
	public:
		virtual void notify(int type, void* obj) = 0;

};

#endif
