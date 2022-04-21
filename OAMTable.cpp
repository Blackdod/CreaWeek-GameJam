#include "pch.h"
#include "OAMTable.h"
#include "OAMEntry.h"

OAMTable::OAMTable()
	:m_MaxEntries{40}	
{
}

OAMTable::~OAMTable()
{
	
}

bool OAMTable::AddEntry(const OAMEntry& entry)
{
	if (m_Entries.size() < m_MaxEntries)
	{
		m_Entries.push_back(entry);
		return true;
	}
	return false;
}

OAMEntry& OAMTable::GetEntry(int idx)
{
	return m_Entries[idx];
}

OAMEntry OAMTable::RemoveEntry(int idx)
{
	OAMEntry entry = m_Entries[idx];
	m_Entries[idx] = m_Entries.back();
	return entry;
}


