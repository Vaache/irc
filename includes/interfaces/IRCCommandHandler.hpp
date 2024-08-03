#ifndef IRC_IRCCOMMANDHANDLER_HPP
#define IRC_IRCCOMMANDHANDLER_HPP


class IRCCommandHandler {
public:
	virtual void processCommand() = 0;
	virtual void handleKick() = 0;
	virtual void handleInvite() = 0;
	virtual void handleTopic() = 0;
	virtual void handleMode() = 0;
};


#endif //IRC_IRCCOMMANDHANDLER_HPP
