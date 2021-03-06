#ifndef _GENESISCOMMANDLINE_H_
#define _GENESISCOMMANDLINE_H_

#include <TextControl.h>
#include <View.h>
#include <String.h>

const uint32 COMMANDLINE_ESC		= 'CESC';

class CommandLine : public BTextControl
{
	public:
		CommandLine(BRect rect, char *name, BMessage* msg);
		~CommandLine();

		BString m_Path;
		
		void Execute(void);		
		void SetPath(const char *path);
};

#endif