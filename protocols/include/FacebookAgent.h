#ifndef __FACEBOOK_AGENT_H__
#define __FACEBOOK_AGENT_H__

#include <string>
#include <map>
#include <vector>

namespace cocos2d{namespace plugin{

class AgentManager;

class FacebookAgent{

public:

	static FacebookAgent* getInstance();
	static void destroyInstance();

	enum HttpMethod{
		Get = 0,
		Post,
		Delete
	};

	typedef std::map<std::string, std::string> FBInfo;
	typedef std::function<void(int, std::string&, FBInfo&)> FBCallback;

	void login(FBCallback cb);
	void logout(FBCallback cb);
	void getLoignStatus(FBCallback cb);
	std::string getAccessToken();
	void share(FBInfo &info, FBCallback cb);
	void dialog(FBInfo &info, FBCallback cb);
	void request(std::string &path, int method, FBInfo &params, FBCallback cb);

	FBCallback getRequestCallback(int index);
private:
	FacebookAgent();
	~FacebookAgent();

	AgentManager* agentManager;
	std::vector<FBCallback> requestCallbacks;
};

}}
#endif
