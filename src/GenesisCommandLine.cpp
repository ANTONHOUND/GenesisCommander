#include "GenesisCommandLine.h"
#include <stdio.h>
#include <stdlib.h>
#include <Rect.h>
#include <Beep.h>

#include <Entry.h>
#include <Roster.h>

#include <unistd.h>


////////////////////////////////////////////////////////////////////////
CommandLine::CommandLine(BRect rect, char *name, BMessage* msg)
	   	   : BTextControl( rect, name , "", "", msg, B_FOLLOW_BOTTOM|B_FOLLOW_LEFT , B_WILL_DRAW )
////////////////////////////////////////////////////////////////////////
{
	SetPath("/");
}

////////////////////////////////////////////////////////////////////////
CommandLine::~CommandLine()
////////////////////////////////////////////////////////////////////////
{

}

////////////////////////////////////////////////////////////////////////
void CommandLine::Execute(void)
////////////////////////////////////////////////////////////////////////
{
	BString execute;
	execute.SetTo(Text());

	if (execute.Length()==0)
		return;

	entry_ref ref;
	BEntry entry(execute.String());
	if (entry.GetRef(&ref) == B_OK)
		be_roster->Launch(&ref);

	SetText("");
}

////////////////////////////////////////////////////////////////////////
void CommandLine::SetPath(const char *path)
////////////////////////////////////////////////////////////////////////
{
	BFont font;
	BString chdirpath;

	// Set new text...
	m_Path.SetTo(path);
	SetLabel(m_Path.String());

	// Set path...
	chdirpath.SetTo("""");
	chdirpath+=m_Path.String();
	chdirpath+="""";
	chdir(chdirpath.String());

	// Set divider...
	GetFont(&font);
	SetDivider(font.StringWidth(m_Path.String())+4);
}
