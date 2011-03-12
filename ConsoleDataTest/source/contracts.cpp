#include "contracts.h"

contract::contract()
{
	m_Sending = NULL;
	m_Recieving = NULL;
	m_Rate = 0;
	m_Remaining = -1;
	m_Expires = 0;
	m_Renew = false;
}

	//person(std::string N, int A) : name(N), age(A) {}
contract::contract(industry* sending,industry* recieving, int rate, int remaining, int expires, bool renew)
{
	m_Sending = sending;
	m_Recieving = recieving;
	m_Rate = rate;
	m_Remaining = remaining;
	m_Expires = expires;
	m_Renew = renew;
}
