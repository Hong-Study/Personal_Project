#pragma once
class GameSession : public Session
{
public:
	GameSession() { }
	~GameSession()
	{
		cout << "~GameSession" << endl;
	}
	virtual void OnConnected() override;
	virtual int32 OnRecv(BYTE* buffer, int32 len) override;
	virtual void OnSend(int32 len) override;

private:
	void HANDLE_URL_MAKING(BYTE* buffer, int32 len);
	void HANDLE_URL_MAPPING(BYTE* buffer, int32 len);

private:
	PKT_Header* head;
};

