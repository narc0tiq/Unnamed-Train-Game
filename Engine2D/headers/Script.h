/*
	Script.h - Provides simple wrapper for Lua
*/

#ifndef _SCRIPT_H
#define _SCRIPT_H

#include "Engine2D.h"

namespace Engine2D {

	class Script
	{
		private:
			lua_State *luaState;
	
		public:
			Script();
			Script(std::string scriptfile);
			virtual ~Script();
			
			bool loadScript(std::string scriptfile);
	
			std::string getGlobalString(std::string name);
			void setGlobalString(std::string name, std::string value);
			
			double getGlobalNumber(std::string name);
			void setGlobalNumber(std::string name, double value);
			
			bool getGlobalBoolean(std::string name);
			void setGlobalBoolean(std::string name, bool value);
			
			void runFunction(std::string name);
	};
	
};

#endif