#ifndef COMPANIES_H
#define COMPANIES_H

#include <iostream>
#include "contracts.h"

class company_player
{
	bool			m_Human;
	std::string		m_Name;			// Company 
	int				m_StartDate;
	int				m_Money;		// Money dosent include loan
	int				m_Loan;			// Current loan
	int				m_CValue;		// Company Value
	contract*		RootContract;	// Contract List
};

class industryPlayerRating
{
	industryPlayerRating*	NextPlayer;
	company_player*			Player;
	float	Rating;
};

#endif