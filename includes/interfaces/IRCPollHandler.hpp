#ifndef IRC_IRCPOLLHANDLER_HPP
#define IRC_IRCPOLLHANDLER_HPP


class IRCPollHandler {
public:
	virtual int onRead() = 0;
	virtual int onWrite() = 0;
	virtual bool onError() = 0;
};


#endif //IRC_IRCPOLLHANDLER_HPP
