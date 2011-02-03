
#include <iostream>
#include "industries.h"

class contract
{
	contract*	m_NextContract;	// Link List
	industry*	m_Sending;	// Sending industry
	industry*	m_Recieving;	// Recieving industry
	int			m_Rate;		// Resorces needed per month
	int			m_Remaining;	// Quantity remaining (not recieved)
	int			m_Expires;	// Expirey date in game time
	bool		m_Renew;		// Wether the contract can be renewed

	contract()
	{
		m_Sending = NULL;
		m_Recieving = NULL;
		m_Rate = 0;
		m_Remaining = -1;
		m_Expires = 0;
		m_Renew = false;
	}

	//person(std::string N, int A) : name(N), age(A) {}
	contract(industry* sending,industry* recieving, int rate, int remaining, int expires, bool renew)
	{
		m_Sending = sending;
		m_Recieving = recieving;
		m_Rate = rate;
		m_Remaining = remaining;
		m_Expires = expires;
		m_Renew = renew;
	}

	void SetRate(int rate) { m_Rate = rate; }
	void SetRemaining(int remaining) { m_Remaining = remaining; }
	void SetExpires(int expires ) { m_Expires = expires; }
	void SetRenewable(bool renew) { m_Renew = renew; }

	industry*	GetSending(void)	{ return m_Sending; }
	industry*	GetRecieving(void)	{ return m_Recieving; }
	int			GetRate(void)		{ return m_Rate; }
	int			GetRemaining(void)	{ return m_Remaining; }
	int			GetExpires(void)	{ return m_Expires; }
	bool		GetRenew(void)		{ return m_Renew; }
};

class AvailableContracts
{
	contract*		RootContract;	// Contract List
};

