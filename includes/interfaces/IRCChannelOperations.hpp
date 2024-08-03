#ifndef IRC_IRCCHANNELOPERATIONS_HPP
#define IRC_IRCCHANNELOPERATIONS_HPP


class IRCChannelOperations {
public:
	virtual void addClient() = 0;
	virtual void removeClient() = 0;
	virtual void sendMessageToChannel() = 0;
	virtual void kickClient() = 0;
	virtual void inviteClient() = 0;
	virtual void setTopic() = 0;
	virtual void changeMode() = 0;
};


#endif //IRC_IRCCHANNELOPERATIONS_HPP
